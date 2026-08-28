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
/// TAHAP 3 + 4b — Input & drag-drop untuk Kubika Blast.
/// Tempel komponen ini ke GameObject "Game" yang SAMA dengan BlastGame.
///
/// PENTING: DefaultExecutionOrder dibuat > 0 supaya BlastGame.Start() (yang
/// memanggil Rebuild dan menghapus semua anak Game) jalan LEBIH DULU daripada
/// BlastInput.Start(). Selain itu ghost root juga dibuat ulang otomatis kalau
/// hilang (mis. setelah Rebuild), lihat EnsureGhostRoot().
///
/// MODEL SERET (cocok untuk HP):
///  1. Pilih potongan tray (tap slot di UI, atau tombol 1/2/3, atau TAB).
///  2. TEKAN & SERET jari di permukaan tabung -> ghost preview muncul MENGIKUTI jari
///     (hijau = boleh, merah = tidak boleh). Ghost HANYA tampil selama jari menekan.
///  3. LEPAS jari di sel valid -> potongan ditaruh. Seret keluar tabung lalu lepas = BATAL.
///  - Tap cepat tetap berfungsi (dianggap seret sangat singkat).
///  - Uncheck "Ghost Only While Dragging" kalau mau preview hover pakai mouse (desktop).
///
/// Putar TABUNG: drag KLIK-KANAN, atau Q/E, atau panah Kiri/Kanan, atau DUA JARI.
/// (Potongan sendiri TIDAK diputar - khas Block Blast.)
/// </summary>
[RequireComponent(typeof(BlastGame))]
[DefaultExecutionOrder(1000)]
public class BlastInput : MonoBehaviour
{
    [Header("Kecepatan putar tabung")]
    public float keyRotateSpeed = 90f;    // derajat / detik (Q/E, panah kiri-kanan)
    public float dragRotateSpeed = 0.3f;  // derajat / pixel (drag klik-kanan atau 2 jari)

    [Header("Perilaku ghost / drag")]
    // true (HP): ghost hanya muncul saat jari menekan/seret.
    // false (mouse desktop): ghost tampil saat pointer hover walau tak menekan.
    public bool ghostOnlyWhileDragging = true;

    [Header("Warna ghost preview (alpha = transparansi)")]
    public Color validColor = new Color(0.35f, 0.90f, 0.40f, 0.50f);
    public Color invalidColor = new Color(0.95f, 0.30f, 0.30f, 0.50f);

    BlastGame _game;
    Camera _cam;

    int _current = -1;                 // index potongan tray yang sedang dipilih
    Material _matValid, _matInvalid;
    Transform _ghostRoot;
    readonly List<GameObject> _ghosts = new List<GameObject>();

    // status drag-putar (klik-kanan)
    bool _rotating;
    float _lastPointerX;

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
        _matValid = MakeGhostMaterial(validColor);
        _matInvalid = MakeGhostMaterial(invalidColor);
        EnsureGhostRoot();
        SelectFirstUnused();
    }

    void Update()
    {
        if (_cam == null) _cam = Camera.main;
        var core = _game.Core;
        if (core == null) return;

        EnsureGhostRoot(); // buat ulang bila hilang (mis. setelah Rebuild tabung)

        HandleRotation();
        HandleSelection();

        // pastikan potongan terpilih masih valid (mis. setelah refill tray)
        var piece = CurrentPiece();
        if (piece == null) { SelectFirstUnused(); piece = CurrentPiece(); }

        bool multi = MultiTouchActive();   // 2 jari = gestur putar, bukan menaruh
        bool held = PointerHeld();         // jari/klik-kiri sedang menekan?

        // Ghost aktif hanya saat menyeret (mode HP). Saat putar / 2 jari / game over -> nonaktif.
        bool active = piece != null && !core.GameOver && !_rotating && !multi
                      && (!ghostOnlyWhileDragging || held);

        int col = 0, row = 0;
        bool haveCell = false;
        bool canPlace = false;

        if (active && PointerToCell(out col, out row))
        {
            haveCell = true;
            canPlace = core.CanPlace(piece, col, row);
            // ingat sel target terakhir supaya bisa ditaruh saat jari dilepas
            _lastCol = col; _lastRow = row; _lastCanPlace = canPlace; _hasLast = true;
        }
        else if (held)
        {
            // menekan tapi tidak di atas sel tabung -> seret keluar = batalkan target
            _hasLast = false;
        }

        SetGhost(haveCell, piece, col, row, canPlace);

        // LEPAS jari/klik -> taruh di sel valid terakhir (drag-and-drop khas HP).
        if (PointerReleased() && !_rotating && !multi)
        {
            if (_hasLast && _lastCanPlace && piece != null
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
            _hasLast = false; // reset setiap kali jari dilepas
        }
    }

    // ================= ROTASI TABUNG =================
    void HandleRotation()
    {
        float deltaDeg = 0f;

        // keyboard: Q/panah-kiri putar satu arah, E/panah-kanan arah sebaliknya
        float k = 0f;
        if (RotLeftHeld()) k += 1f;
        if (RotRightHeld()) k -= 1f;
        deltaDeg += k * keyRotateSpeed * Time.deltaTime;

        // drag klik-kanan (desktop)
        if (RightDown()) { _rotating = true; _lastPointerX = PointerPosition().x; }
        if (RightUp()) _rotating = false;
        if (_rotating && RightHeld())
        {
            float px = PointerPosition().x;
            float dx = px - _lastPointerX;
            _lastPointerX = px;
            deltaDeg += -dx * dragRotateSpeed;
        }

        // dua jari (touch)
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

    // ================= RAYCAST -> SEL GRID (kebalikan CellToWorld) =================
    // Silinder blok: x^2 + z^2 = R^2 (di ruang LOKAL BlastGame). Kita cari titik
    // permukaan terdekat ke kamera, lalu ubah jadi (col,row).
    bool PointerToCell(out int col, out int row)
    {
        col = 0; row = 0;
        if (_cam == null) return false;

        float R = _game.Radius;
        if (R <= 0f) return false;

        Ray ray = _cam.ScreenPointToRay(PointerPosition());

        // ubah ray ke ruang lokal BlastGame supaya rotasi tabung ikut diperhitungkan
        Vector3 o = _game.transform.InverseTransformPoint(ray.origin);
        Vector3 d = _game.transform.InverseTransformDirection(ray.direction);
        d.Normalize();

        float a = d.x * d.x + d.z * d.z;
        if (a < 1e-6f) return false; // ray hampir sejajar sumbu tabung
        float b = 2f * (o.x * d.x + o.z * d.z);
        float c = o.x * o.x + o.z * o.z - R * R;
        float disc = b * b - 4f * a * c;
        if (disc < 0f) return false; // tidak kena silinder

        float sq = Mathf.Sqrt(disc);
        float t0 = (-b - sq) / (2f * a); // permukaan depan (dekat kamera)
        float t1 = (-b + sq) / (2f * a); // permukaan belakang
        float t = t0 >= 0f ? t0 : t1;
        if (t < 0f) return false;

        Vector3 hit = o + d * t;

        float ang = Mathf.Atan2(hit.z, hit.x);      // sama seperti sudut di CellToWorld
        int cc = Mathf.RoundToInt(ang / (2f * Mathf.PI) * _game.columns);
        col = _game.Core.Wrap(cc);

        int rr = Mathf.RoundToInt(hit.y / _game.cellHeight - 0.5f);
        if (rr < 0 || rr >= _game.height) return false;
        row = rr;
        return true;
    }

    // ================= GHOST PREVIEW =================
    // Pastikan ghost root ADA dan menjadi anak Game (ikut posisi + rotasi tabung).
    // Unity meng-overload operator== sehingga objek yang sudah di-Destroy terbaca
    // sebagai null -> aman dipakai untuk mendeteksi ghost yang terhapus Rebuild.
    void EnsureGhostRoot()
    {
        if (_ghostRoot != null) return;
        var gr = new GameObject("Ghost").transform;
        gr.SetParent(_game.transform, false); // anak Game -> ikut transform tabung
        _ghostRoot = gr;
        _ghosts.Clear(); // ghost cube lama sudah ikut terhapus bersama root lama
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
            if (r < 0 || r >= _game.height) continue; // di luar tinggi tabung -> tak digambar
            int c = _game.Core.Wrap(col + dx);

            var g = _ghosts[used++];
            g.SetActive(true);
            // localPosition RELATIF ke ghost root (anak Game) = ruang lokal tabung,
            // sama persis dengan blok terpasang -> posisi selalu sinkron.
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

    // Material semi-transparan untuk ghost (URP Lit; fallback Standard).
    Material MakeGhostMaterial(Color col)
    {
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);

        if (m.HasProperty("_Surface")) m.SetFloat("_Surface", 1f); // 0=opaque, 1=transparent
        m.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
        m.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
        m.SetInt("_ZWrite", 0);
        m.DisableKeyword("_SURFACE_TYPE_OPAQUE");
        m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
        m.EnableKeyword("_ALPHABLEND_ON"); // untuk fallback Standard
        m.renderQueue = (int)UnityEngine.Rendering.RenderQueue.Transparent;

        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", col);
        m.color = col;
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

    bool PointerHeld() // klik kiri / jari sedang menekan
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

    bool PointerReleased() // klik kiri dilepas / tap selesai
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

    bool MultiTouchActive() // >= 2 jari menyentuh layar (gestur putar)
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
