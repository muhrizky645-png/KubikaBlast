// Dukung DUA backend input Unity: Input Manager (lama) & Input System (baru).
// Kalau project cuma pakai Input System baru (default Unity 6 URP), branch
// USE_NEW_INPUT yang dipakai. Kalau ada Input Manager lama (atau "Both"),
// pakai API lama. Jadi script ini jalan tanpa perlu ubah Player Settings.
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

using System.Collections.Generic;
using UnityEngine;
#if USE_NEW_INPUT
using UnityEngine.InputSystem;
#endif
using KubikaBlast;

/// <summary>
/// TAHAP 3 + 4 — Input, drag-drop, & preview-clear ala Block Blast.
/// Tempel komponen ini ke GameObject "Game" yang SAMA dengan BlastGame.
///
/// PENTING: DefaultExecutionOrder > 0 supaya BlastGame.Start() (Rebuild yang
/// menghapus semua anak Game) jalan LEBIH DULU daripada BlastInput.Start().
/// Ghost & preview root juga dibuat ulang otomatis kalau hilang (setelah Rebuild).
///
/// MODEL MURNI SERET (HP):
///  1. Pilih potongan tray (tap slot UI / tombol 1-2-3 / TAB).
///  2. TEKAN & SERET jari di tabung. Ghost muncul HANYA setelah jari BERGERAK
///     melewati dragThreshold. Tap/pencet diam TIDAK menaruh apa pun.
///  3. Kalau posisi seret membuat cincin/kolom PENUH -> sel-sel yang akan hancur
///     ikut MENYALA (preview clear ala Block Blast).
///  4. LEPAS jari di sel valid -> potongan ditaruh. Seret keluar tabung = batal.
///
/// Putar TABUNG: drag KLIK-KANAN / Q-E / panah / DUA JARI.
/// </summary>
[RequireComponent(typeof(BlastGame))]
[DefaultExecutionOrder(1000)]
public class BlastInput : MonoBehaviour
{
    [Header("Kecepatan putar tabung")]
    public float keyRotateSpeed = 90f;    // derajat / detik (Q/E, panah kiri-kanan)
    public float dragRotateSpeed = 0.3f;  // derajat / pixel (drag klik-kanan atau 2 jari)

    [Header("Perilaku ghost / drag")]
    // true (HP): ghost hanya muncul saat MENYERET. false (mouse): preview saat hover.
    public bool ghostOnlyWhileDragging = true;
    // Jarak minimal (pixel) jari harus bergerak agar dihitung MENYERET, bukan tap.
    public float dragThreshold = 12f;

    [Header("Warna ghost preview (alpha diabaikan, pakai ghostAlpha)")]
    public Color validColor = new Color(0.35f, 0.90f, 0.40f, 1f);
    public Color invalidColor = new Color(0.95f, 0.30f, 0.30f, 1f);
    // Transparansi ghost. Dibuat KECIL supaya jelas beda dari blok terpasang (yang solid).
    [Range(0.05f, 1f)] public float ghostAlpha = 0.25f;

    [Header("Preview CLEAR ala Block Blast")]
    public bool enableClearPreview = true;
    // Warna nyala untuk sel yang AKAN hancur (baris/kolom penuh).
    public Color clearPreviewColor = new Color(1f, 0.95f, 0.35f, 0.55f);

    BlastGame _game;
    Camera _cam;

    int _current = -1;                 // index potongan tray yang sedang dipilih
    Material _matValid, _matInvalid, _matPreview;
    Transform _ghostRoot, _previewRoot;
    readonly List<GameObject> _ghosts = new List<GameObject>();
    readonly List<GameObject> _previews = new List<GameObject>();

    // status drag-putar (klik-kanan)
    bool _rotating;
    float _lastPointerX;

    // deteksi seret: posisi saat mulai menekan + apakah sudah dihitung menyeret
    Vector2 _pressStartPos;
    bool _isDragging;

    // target terakhir saat menyeret -> dipakai untuk menaruh saat jari dilepas
    int _lastCol, _lastRow;
    bool _lastCanPlace, _hasLast;

    // ===== API publik untuk BlastUI (Tahap 4) =====
    public int CurrentIndex => _current;                 // slot tray yang dipilih (-1 = tak ada)
    public void SelectTray(int i) => TrySelect(i);       // dipanggil saat tap slot tray di UI
    public void ResetSelection() => SelectFirstUnused(); // dipanggil saat Restart

    void Awake()
    {
        _game = GetComponent<BlastGame>();
    }

    void Start()
    {
        _cam = Camera.main;
        // Alpha ghost dipaksa = ghostAlpha (abaikan alpha pada validColor/invalidColor).
        Color v = validColor; v.a = ghostAlpha;
        Color iv = invalidColor; iv.a = ghostAlpha;
        _matValid = MakeGhostMaterial(v, false);
        _matInvalid = MakeGhostMaterial(iv, false);
        _matPreview = MakeGhostMaterial(clearPreviewColor, true); // pakai emission -> menyala
        EnsureGhostRoot();
        EnsurePreviewRoot();
        SelectFirstUnused();
    }

    void Update()
    {
        if (_cam == null) _cam = Camera.main;
        var core = _game.Core;
        if (core == null) return;

        EnsureGhostRoot();   // buat ulang bila hilang (mis. setelah Rebuild tabung)
        EnsurePreviewRoot();

        HandleRotation();
        HandleSelection();

        // pastikan potongan terpilih masih valid (mis. setelah refill tray)
        var piece = CurrentPiece();
        if (piece == null) { SelectFirstUnused(); piece = CurrentPiece(); }

        bool multi = MultiTouchActive();   // 2 jari = gestur putar, bukan menaruh
        bool held = PointerHeld();         // jari/klik-kiri sedang menekan?

        // ---- deteksi SERET sungguhan (bukan tap) ----
        if (PointerPressedThisFrame())
        {
            _pressStartPos = PointerPosition();
            _isDragging = false;
        }
        if (held && !_isDragging &&
            (PointerPosition() - _pressStartPos).sqrMagnitude >= dragThreshold * dragThreshold)
        {
            _isDragging = true; // jari sudah bergerak cukup jauh -> ini menyeret
        }

        // Mode HP: harus MENYERET. Mode desktop (hover): selalu preview.
        bool dragging = ghostOnlyWhileDragging ? (held && _isDragging) : true;
        bool active = piece != null && !core.GameOver && !_rotating && !multi && dragging;

        int col = 0, row = 0;
        bool haveCell = false;
        bool canPlace = false;

        if (active && PointerToCell(out col, out row))
        {
            haveCell = true;
            canPlace = core.CanPlace(piece, col, row);
            _lastCol = col; _lastRow = row; _lastCanPlace = canPlace; _hasLast = true;
        }
        else if (held)
        {
            _hasLast = false; // menekan tapi belum menyeret / di luar sel -> tak ada target
        }

        SetGhost(haveCell, piece, col, row, canPlace);

        // ---- preview CLEAR: sel yang akan hancur menyala ----
        HashSet<(int, int)> clearSet =
            (enableClearPreview && haveCell && canPlace) ? PredictClears(piece, col, row) : null;
        SetClearPreview(clearSet);

        // LEPAS jari/klik -> taruh di sel valid terakhir (HANYA jika benar-benar menyeret).
        if (PointerReleased() && !_rotating && !multi)
        {
            bool draggedEnough = !ghostOnlyWhileDragging || _isDragging;
            if (draggedEnough && _hasLast && _lastCanPlace && piece != null
                && !BlastUI.PointerBlocksPlacement(PointerPosition()))
            {
                if (_game.TryPlace(_current, _lastCol, _lastRow))
                {
                    Debug.Log($"[KubikaBlast] Taruh potongan #{_current} di (c={_lastCol}, r={_lastRow}). " +
                              $"Skor={core.Score}  Combo={core.Combo}  Lines={core.LinesCleared}");
                    SelectFirstUnused();
                    if (core.GameOver)
                        Debug.Log("[KubikaBlast] GAME OVER - tidak ada potongan tray yang muat lagi.");
                }
            }
            _hasLast = false;
            _isDragging = false; // reset untuk gestur berikutnya
            SetClearPreview(null);
        }
    }

    // ================= PREDIKSI CLEAR (untuk preview) =================
    // Cari sel-sel yang AKAN hancur seandainya potongan ditaruh di (col,row),
    // TANPA mengubah grid asli. Aturan sama dengan BlastCore.ResolveClears:
    // cincin (baris) penuh ATAU kolom penuh.
    HashSet<(int, int)> PredictClears(BlastCore.Piece piece, int col, int row)
    {
        var core = _game.Core;
        int C = core.Columns, H = core.Height;

        var pieceCells = new HashSet<(int, int)>();
        foreach (var (dx, dy) in piece.Cells)
        {
            int r = row + dy;
            if (r < 0 || r >= H) continue;
            pieceCells.Add((core.Wrap(col + dx), r));
        }

        // sel terisi = sudah ada blok ATAU akan ditutupi potongan ini
        bool Occ(int c, int r) => core.Grid[c, r] != -1 || pieceCells.Contains((c, r));

        var result = new HashSet<(int, int)>();

        for (int r = 0; r < H; r++) // cincin/baris penuh
        {
            bool full = true;
            for (int c = 0; c < C; c++) if (!Occ(c, r)) { full = false; break; }
            if (full) for (int c = 0; c < C; c++) result.Add((c, r));
        }
        for (int c = 0; c < C; c++) // kolom penuh
        {
            bool full = true;
            for (int r = 0; r < H; r++) if (!Occ(c, r)) { full = false; break; }
            if (full) for (int r = 0; r < H; r++) result.Add((c, r));
        }
        return result;
    }

    void SetClearPreview(HashSet<(int, int)> cells)
    {
        EnsurePreviewRoot();
        if (cells == null || cells.Count == 0)
        {
            for (int i = 0; i < _previews.Count; i++)
                if (_previews[i] != null) _previews[i].SetActive(false);
            return;
        }

        EnsurePreviews(cells.Count);
        int used = 0;
        foreach (var (c, r) in cells)
        {
            var g = _previews[used++];
            g.SetActive(true);
            g.transform.localPosition = _game.CellToWorld(c, r);
            g.transform.localRotation = _game.CellRotation(c);
            // sedikit lebih besar dari blok supaya "membungkus" -> efek menyala.
            g.transform.localScale = new Vector3(_game.cellWidth * _game.gap * 1.06f,
                                                 _game.cellHeight * _game.gap * 1.06f,
                                                 _game.blockDepth * 1.14f);
            g.GetComponent<MeshRenderer>().sharedMaterial = _matPreview;
        }
        for (int i = used; i < _previews.Count; i++)
            if (_previews[i] != null) _previews[i].SetActive(false);
    }

    void EnsurePreviews(int n)
    {
        while (_previews.Count < n)
        {
            var go = new GameObject("ClearCube");
            go.transform.SetParent(_previewRoot, false);
            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _game.CellMesh;
            go.AddComponent<MeshRenderer>();
            go.SetActive(false);
            _previews.Add(go);
        }
    }

    void EnsurePreviewRoot()
    {
        if (_previewRoot != null) return;
        var pr = new GameObject("ClearPreview").transform;
        pr.SetParent(_game.transform, false); // anak Game -> ikut transform tabung
        _previewRoot = pr;
        _previews.Clear();
    }

    // ================= ROTASI TABUNG =================
    void HandleRotation()
    {
        float deltaDeg = 0f;

        float k = 0f;
        if (RotLeftHeld()) k += 1f;
        if (RotRightHeld()) k -= 1f;
        deltaDeg += k * keyRotateSpeed * Time.deltaTime;

        if (RightDown()) { _rotating = true; _lastPointerX = PointerPosition().x; }
        if (RightUp()) _rotating = false;
        if (_rotating && RightHeld())
        {
            float px = PointerPosition().x;
            float dx = px - _lastPointerX;
            _lastPointerX = px;
            deltaDeg += -dx * dragRotateSpeed;
        }

        float twoFingerX = TwoFingerAvgDeltaX();
        if (Mathf.Abs(twoFingerX) > 0f) deltaDeg += -twoFingerX * dragRotateSpeed;

        if (Mathf.Abs(deltaDeg) > 0.0001f)
            _game.transform.Rotate(0f, deltaDeg, 0f, Space.World);
    }

    // ================= PILIH POTONGAN TRAY =================
    void HandleSelection()
    {
        if (Digit1Down()) TrySelect(0);
        if (Digit2Down()) TrySelect(1);
        if (Digit3Down()) TrySelect(2);
        if (TabDown()) SelectNextUnused();
    }

    BlastCore.Piece CurrentPiece()
    {
        var tray = _game.Core.Tray;
        if (_current < 0 || _current >= tray.Length) return null;
        var p = tray[_current];
        return (p != null && !p.Used) ? p : null;
    }

    void TrySelect(int i)
    {
        var tray = _game.Core.Tray;
        if (i >= 0 && i < tray.Length && tray[i] != null && !tray[i].Used) _current = i;
    }

    void SelectFirstUnused()
    {
        var tray = _game.Core.Tray;
        for (int i = 0; i < tray.Length; i++)
            if (tray[i] != null && !tray[i].Used) { _current = i; return; }
        _current = -1;
    }

    void SelectNextUnused()
    {
        var tray = _game.Core.Tray;
        int startFrom = _current < 0 ? -1 : _current;
        for (int step = 1; step <= tray.Length; step++)
        {
            int i = (startFrom + step) % tray.Length;
            if (i < 0) i += tray.Length;
            if (tray[i] != null && !tray[i].Used) { _current = i; return; }
        }
        SelectFirstUnused();
    }

    // ================= RAYCAST -> SEL GRID =================
    bool PointerToCell(out int col, out int row)
    {
        col = 0; row = 0;
        if (_cam == null) return false;

        float R = _game.Radius;
        if (R <= 0f) return false;

        Ray ray = _cam.ScreenPointToRay(PointerPosition());

        Vector3 o = _game.transform.InverseTransformPoint(ray.origin);
        Vector3 d = _game.transform.InverseTransformDirection(ray.direction);
        d.Normalize();

        float a = d.x * d.x + d.z * d.z;
        if (a < 1e-6f) return false;
        float b = 2f * (o.x * d.x + o.z * d.z);
        float c = o.x * o.x + o.z * o.z - R * R;
        float disc = b * b - 4f * a * c;
        if (disc < 0f) return false;

        float sq = Mathf.Sqrt(disc);
        float t0 = (-b - sq) / (2f * a);
        float t1 = (-b + sq) / (2f * a);
        float t = t0 >= 0f ? t0 : t1;
        if (t < 0f) return false;

        Vector3 hit = o + d * t;

        float ang = Mathf.Atan2(hit.z, hit.x);
        int cc = Mathf.RoundToInt(ang / (2f * Mathf.PI) * _game.columns);
        col = _game.Core.Wrap(cc);

        int rr = Mathf.RoundToInt(hit.y / _game.cellHeight - 0.5f);
        if (rr < 0 || rr >= _game.height) return false;
        row = rr;
        return true;
    }

    // ================= GHOST PREVIEW =================
    void EnsureGhostRoot()
    {
        if (_ghostRoot != null) return;
        var gr = new GameObject("Ghost").transform;
        gr.SetParent(_game.transform, false);
        _ghostRoot = gr;
        _ghosts.Clear();
    }

    void SetGhost(bool show, BlastCore.Piece piece, int col, int row, bool canPlace)
    {
        if (!show || piece == null)
        {
            for (int i = 0; i < _ghosts.Count; i++)
                if (_ghosts[i] != null) _ghosts[i].SetActive(false);
            return;
        }

        var mat = canPlace ? _matValid : _matInvalid;
        EnsureGhosts(piece.Cells.Length);

        int used = 0;
        foreach (var (dx, dy) in piece.Cells)
        {
            int r = row + dy;
            if (r < 0 || r >= _game.height) continue;
            int c = _game.Core.Wrap(col + dx);

            var g = _ghosts[used++];
            g.SetActive(true);
            g.transform.localPosition = _game.CellToWorld(c, r);
            g.transform.localRotation = _game.CellRotation(c);
            g.transform.localScale = new Vector3(_game.cellWidth * _game.gap,
                                                 _game.cellHeight * _game.gap,
                                                 _game.blockDepth);
            g.GetComponent<MeshRenderer>().sharedMaterial = mat;
        }
        for (int i = used; i < _ghosts.Count; i++)
            if (_ghosts[i] != null) _ghosts[i].SetActive(false);
    }

    void EnsureGhosts(int n)
    {
        while (_ghosts.Count < n)
        {
            var go = new GameObject("GhostCube");
            go.transform.SetParent(_ghostRoot, false);
            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _game.CellMesh;
            go.AddComponent<MeshRenderer>();
            go.SetActive(false);
            _ghosts.Add(go);
        }
    }

    // Material semi-transparan (URP Lit; fallback Standard). withEmission -> menyala.
    Material MakeGhostMaterial(Color col, bool withEmission)
    {
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);

        if (m.HasProperty("_Surface")) m.SetFloat("_Surface", 1f); // transparan
        m.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
        m.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
        m.SetInt("_ZWrite", 0);
        m.DisableKeyword("_SURFACE_TYPE_OPAQUE");
        m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
        m.EnableKeyword("_ALPHABLEND_ON");
        m.renderQueue = (int)UnityEngine.Rendering.RenderQueue.Transparent;

        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", col);
        m.color = col;

        if (withEmission && m.HasProperty("_EmissionColor"))
        {
            m.EnableKeyword("_EMISSION");
            m.SetColor("_EmissionColor", new Color(col.r, col.g, col.b) * 0.9f);
        }
        return m;
    }

    // ==================================================================
    // ============ ABSTRAKSI INPUT (lama vs baru) ======================
    // ==================================================================
    Vector2 PointerPosition()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null) return m.position.ReadValue();
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null) return ts.primaryTouch.position.ReadValue();
        return Vector2.zero;
#else
        return Input.mousePosition;
#endif
    }

    bool PointerPressedThisFrame()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null && m.leftButton.wasPressedThisFrame) return true;
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null && ts.primaryTouch.press.wasPressedThisFrame) return true;
        return false;
#else
        return Input.GetMouseButtonDown(0);
#endif
    }

    bool PointerHeld()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null && m.leftButton.isPressed) return true;
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null && ts.primaryTouch.press.isPressed) return true;
        return false;
#else
        return Input.GetMouseButton(0);
#endif
    }

    bool PointerReleased()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null && m.leftButton.wasReleasedThisFrame) return true;
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null && ts.primaryTouch.press.wasReleasedThisFrame) return true;
        return false;
#else
        return Input.GetMouseButtonUp(0);
#endif
    }

    bool MultiTouchActive()
    {
#if USE_NEW_INPUT
        var ts = Touchscreen.current;
        if (ts == null) return false;
        int n = 0;
        foreach (var t in ts.touches) if (t.isInProgress) n++;
        return n >= 2;
#else
        return Input.touchCount >= 2;
#endif
    }

    bool RightDown()
    {
#if USE_NEW_INPUT
        return Mouse.current != null && Mouse.current.rightButton.wasPressedThisFrame;
#else
        return Input.GetMouseButtonDown(1);
#endif
    }

    bool RightUp()
    {
#if USE_NEW_INPUT
        return Mouse.current != null && Mouse.current.rightButton.wasReleasedThisFrame;
#else
        return Input.GetMouseButtonUp(1);
#endif
    }

    bool RightHeld()
    {
#if USE_NEW_INPUT
        return Mouse.current != null && Mouse.current.rightButton.isPressed;
#else
        return Input.GetMouseButton(1);
#endif
    }

    bool RotLeftHeld()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current;
        return k != null && (k.qKey.isPressed || k.leftArrowKey.isPressed);
#else
        return Input.GetKey(KeyCode.Q) || Input.GetKey(KeyCode.LeftArrow);
#endif
    }

    bool RotRightHeld()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current;
        return k != null && (k.eKey.isPressed || k.rightArrowKey.isPressed);
#else
        return Input.GetKey(KeyCode.E) || Input.GetKey(KeyCode.RightArrow);
#endif
    }

    bool Digit1Down()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current; return k != null && k.digit1Key.wasPressedThisFrame;
#else
        return Input.GetKeyDown(KeyCode.Alpha1);
#endif
    }

    bool Digit2Down()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current; return k != null && k.digit2Key.wasPressedThisFrame;
#else
        return Input.GetKeyDown(KeyCode.Alpha2);
#endif
    }

    bool Digit3Down()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current; return k != null && k.digit3Key.wasPressedThisFrame;
#else
        return Input.GetKeyDown(KeyCode.Alpha3);
#endif
    }

    bool TabDown()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current; return k != null && k.tabKey.wasPressedThisFrame;
#else
        return Input.GetKeyDown(KeyCode.Tab);
#endif
    }

    float TwoFingerAvgDeltaX()
    {
#if USE_NEW_INPUT
        var ts = Touchscreen.current;
        if (ts == null) return 0f;
        int n = 0; float sum = 0f;
        foreach (var t in ts.touches)
        {
            if (t.isInProgress) { sum += t.delta.ReadValue().x; n++; }
        }
        return n == 2 ? sum * 0.5f : 0f;
#else
        if (Input.touchCount == 2)
            return (Input.GetTouch(0).deltaPosition.x + Input.GetTouch(1).deltaPosition.x) * 0.5f;
        return 0f;
#endif
    }
}
