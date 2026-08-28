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
/// TAHAP 3 + 4 + 5 — Input, drag-drop, blok melayang, & preview-clear ala Block Blast.
/// Tempel komponen ini ke GameObject "Game" yang SAMA dengan BlastGame.
///
/// PENTING: DefaultExecutionOrder > 0 supaya BlastGame.Start() (Rebuild yang
/// menghapus semua anak Game) jalan LEBIH DULU daripada BlastInput.Start().
/// Ghost & preview root juga dibuat ulang otomatis kalau hilang (setelah Rebuild).
///
/// MODEL MURNI SERET-DARI-TRAY (HP) ala Block Blast:
///  1. TEKAN jari TEPAT di potongan tray yang diinginkan (BUKAN di tabung).
///  2. Tanpa melepas, SERET jari ke tabung. Selama menyeret, potongan tampak
///     "MELAYANG". Saat sudah menemukan sel tujuan valid, blok melayang digambar
///     MELENGKUNG di permukaan tabung (sinkron dgn bayangan) & terangkat sedikit.
///     Saat belum ada sel tujuan valid, blok jadi OVERLAY rata mengikuti jari.
///     Di tabung TIDAK ada balok berwarna kembar; yang muncul cuma INDIKATOR SEL
///     TUJUAN yang halus (highlight tipis) dan HANYA saat posisi PAS.
///  3. Kalau posisi seret membuat cincin/kolom PENUH -> sel yang akan hancur
///     ikut MENYALA (preview clear ala Block Blast).
///  4. LEPAS jari di sel valid -> potongan ditaruh. Lepas di luar tabung = batal.
///  * Menekan/menyeret LANGSUNG di tabung TIDAK menaruh apa pun. Menaruh HANYA
///    sah lewat gestur seret yang DIMULAI dari slot tray.
///
/// POLESAN UX PENEMPATAN (baru):
///  - Toleransi snap: kalau titik jari tak pas, cari sel valid TERDEKAT.
///  - Magnet ke clear: utamakan posisi yang memicu ring/kolom penuh.
///  - Auto-putar tabung saat jari dekat tepi layar (jangkau sisi tersembunyi).
///  - Feedback merah saat blok belum ketemu sel valid.
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
    // true (HP): menaruh HANYA lewat seret DARI slot tray. false (mouse): preview saat hover.
    public bool ghostOnlyWhileDragging = true;
    // Jarak minimal (pixel) jari harus bergerak agar dihitung MENYERET, bukan tap.
    public float dragThreshold = 12f;

    [Header("Indikator sel tujuan (gaya Block Blast)")]
    // Highlight di sel tempat potongan akan mendarat. Alpha dinaikkan biar lebih TEGAS
    // (gampang kelihatan sel tujuannya). Dipakai HANYA saat posisi PAS.
    public Color ghostHighlightColor = new Color(1f, 1f, 1f, 0.35f);

    [Header("Preview CLEAR ala Block Blast")]
    public bool enableClearPreview = true;
    // Warna nyala untuk sel yang AKAN hancur (baris/kolom penuh).
    public Color clearPreviewColor = new Color(1f, 0.95f, 0.35f, 0.55f);

    [Header("Blok melayang saat diseret (poin 1)")]
    // Blok melayang: MELENGKUNG di tabung saat terkunci ke ghost, atau OVERLAY layar
    // rata (fallback) saat belum ada sel tujuan valid.
    public bool enableHeldPiece = true;
    // Offset ke ATAS (pixel) supaya blok melayang di atas jari, tak ketutup jari.
    // Dipakai HANYA saat FALLBACK overlay (jari belum di sel valid).
    public float heldScreenYOffset = 90f;
    // Samakan ukuran blok melayang dengan blok ASLI di tabung (seperti "bayangan" blok).
    // Dipakai HANYA pada mode fallback overlay.
    public bool matchBlockSize = true;
    // Pengali halus ukuran blok melayang (1 = pas sama blok asli). Mode fallback overlay.
    public float heldSizeMultiplier = 1f;
    // Ukuran satu sel blok melayang di LAYAR (pixel). Dipakai HANYA bila matchBlockSize = false.
    public float heldPixelSize = 90f;
    // Jarak overlay dari kamera (unit dunia). Kecil = terasa menempel di layar. Mode fallback.
    public float heldDepth = 2f;
    // OPSI #3: kunci blok melayang ke posisi ghost (sel tujuan). Nilai = seberapa
    // tinggi (dalam satuan SEL) blok terangkat di atas sel tujuan agar tak ketutup jari.
    // Diturunkan (0.6 -> 0.35) supaya posisi jatuhnya terasa lebih pas/intuitif.
    // 0 = pas di ghost.
    public float heldGhostLiftCells = 0.35f;

    [Header("Toleransi snap (magnet ke sel valid terdekat)")]
    // Kalau titik jari tak pas di sel valid, cari sel valid TERDEKAT dalam radius ini.
    public bool snapToNearestValid = true;
    public int snapSearchRadius = 2;      // berapa sel ke segala arah yang dicari
    // Utamakan posisi yang MEMICU CLEAR (magnet ke ring/kolom yang hampir penuh).
    public bool magnetToClears = true;
    public float magnetClearBonus = 3f;   // pengurang "skor jarak" bila memicu clear

    [Header("Auto-putar tabung saat seret dekat tepi layar")]
    public bool autoRotateWhileDragging = true;
    public float edgeRotatePx = 90f;      // lebar zona tepi kiri/kanan (pixel)
    public float edgeRotateSpeed = 120f;  // derajat / detik saat jari di zona tepi

    [Header("Feedback saat tak muat")]
    // Warnai MERAH blok melayang saat belum menemukan sel tujuan valid.
    public bool tintInvalidHeld = true;
    public Color invalidHeldColor = new Color(1f, 0.28f, 0.28f, 0.8f);

    BlastGame _game;
    Camera _cam;

    int _current = -1;                 // index potongan tray yang sedang dipilih
    Material _matGhost, _matPreview, _matInvalidHeld;
    Transform _ghostRoot, _previewRoot;
    readonly List<GameObject> _ghosts = new List<GameObject>();
    readonly List<GameObject> _previews = new List<GameObject>();

    // blok melayang (poin 1): TIDAK di-parent ke tabung supaya tak ikut berputar.
    Transform _heldRoot;
    readonly List<GameObject> _held = new List<GameObject>();
    readonly Dictionary<int, Material> _solidMats = new Dictionary<int, Material>();

    // status drag-putar (klik-kanan)
    bool _rotating;
    float _lastPointerX;

    // deteksi seret: posisi saat mulai menekan + apakah sudah dihitung menyeret
    Vector2 _pressStartPos;
    bool _isDragging;
    // true HANYA jika gestur menekan ini DIMULAI tepat di atas slot tray.
    // Inilah gerbang "seret-dari-tray": menekan tabung -> false -> tak bisa menaruh.
    bool _dragFromTray;

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
        // Indikator sel tujuan: highlight tipis (pakai emission -> glow lembut).
        _matGhost = MakeGhostMaterial(ghostHighlightColor, true);
        _matPreview = MakeGhostMaterial(clearPreviewColor, true); // pakai emission -> menyala
        _matInvalidHeld = MakeGhostMaterial(invalidHeldColor, false); // merah translusen (tak muat)
        EnsureGhostRoot();
        EnsurePreviewRoot();
        EnsureHeldRoot();
        SelectFirstUnused();
    }

    void Update()
    {
        if (_cam == null) _cam = Camera.main;
        var core = _game.Core;
        if (core == null) return;

        EnsureGhostRoot();   // buat ulang bila hilang (mis. setelah Rebuild tabung)
        EnsurePreviewRoot();
        EnsureHeldRoot();

        HandleRotation();
        HandleSelection();

        // pastikan potongan terpilih masih valid (mis. setelah refill tray)
        var piece = CurrentPiece();
        if (piece == null) { SelectFirstUnused(); piece = CurrentPiece(); }

        bool multi = MultiTouchActive();   // 2 jari = gestur putar, bukan menaruh
        bool held = PointerHeld();         // jari/klik-kiri sedang menekan?

        // ---- MULAI gestur: hanya sah kalau DIMULAI di slot tray ----
        if (PointerPressedThisFrame())
        {
            _pressStartPos = PointerPosition();
            _isDragging = false;
            int slot = BlastUI.TraySlotAtPointer(_pressStartPos);
            if (slot >= 0) { TrySelect(slot); _dragFromTray = true; }  // "angkat" potongan dari tray
            else _dragFromTray = false;                                 // tekan tabung/lainnya -> tak bisa menaruh
        }
        // deteksi seret sungguhan (bukan tap): jari sudah bergerak cukup jauh?
        if (held && !_isDragging &&
            (PointerPosition() - _pressStartPos).sqrMagnitude >= dragThreshold * dragThreshold)
        {
            _isDragging = true;
        }

        // Mode HP: WAJIB menyeret DARI tray. Mode desktop (hover): selalu preview.
        bool requireTrayDrag = ghostOnlyWhileDragging;
        bool dragging = ghostOnlyWhileDragging ? (held && _isDragging) : true;
        bool active = piece != null && !core.GameOver && !_rotating && !multi
                      && dragging && (!requireTrayDrag || _dragFromTray);

        // Auto-putar tabung saat menyeret potongan & jari dekat tepi layar, biar
        // sel di sisi yang belum kelihatan bisa dijangkau tanpa lepas jari.
        if (active) HandleEdgeAutoRotate();

        int col = 0, row = 0;
        bool haveCell = false;
        bool canPlace = false;

        if (active && PointerToCell(out col, out row))
        {
            // Pusatkan potongan tepat di bawah jari (gaya Block Blast) supaya
            // indikator tujuan TIDAK geser ke kanan. Anchor = sel jari - centroid.
            PieceCentroidOffset(piece, out int offX, out int offY);
            int baseCol = core.Wrap(col - offX);
            int baseRow = row - offY;

            haveCell = true;

            // Toleransi snap: kalau anchor pas tak muat, cari sel valid TERDEKAT
            // (dan utamakan yang memicu clear). Bikin penempatan jauh lebih forgiving.
            if (TryFindPlacement(piece, baseCol, baseRow, out int snapCol, out int snapRow))
            {
                col = snapCol; row = snapRow; canPlace = true;
            }
            else
            {
                col = baseCol; row = baseRow; canPlace = false;
            }

            _lastCol = col; _lastRow = row; _lastCanPlace = canPlace; _hasLast = true;
        }
        else if (held)
        {
            _hasLast = false; // menekan tapi belum menyeret / di luar sel -> tak ada target
        }

        // Indikator sel tujuan (highlight halus) HANYA saat posisi PAS.
        SetGhost(haveCell && canPlace, piece, col, row);
        // Poin 1: blok melayang mengikuti jari selama menyeret dari tray.
        SetHeldPiece(enableHeldPiece && active, piece);

        // ---- preview CLEAR: sel yang akan hancur menyala ----
        HashSet<(int, int)> clearSet =
            (enableClearPreview && haveCell && canPlace) ? PredictClears(piece, col, row) : null;
        SetClearPreview(clearSet);

        // LEPAS jari/klik -> taruh di sel valid terakhir.
        // Syarat: gestur DIMULAI di tray (_dragFromTray) DAN benar-benar menyeret.
        if (PointerReleased() && !_rotating && !multi)
        {
            bool draggedEnough = !ghostOnlyWhileDragging || _isDragging;
            bool trayOk = !requireTrayDrag || _dragFromTray;
            if (draggedEnough && trayOk && _hasLast && _lastCanPlace && piece != null
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
            _isDragging = false;   // reset untuk gestur berikutnya
            _dragFromTray = false; // gerbang tray ditutup lagi
            SetClearPreview(null);
            SetHeldPiece(false, null); // sembunyikan blok melayang setelah dilepas
        }
    }

    // Centroid (dibulatkan) offset sel potongan -> dipakai memusatkan di jari.
    void PieceCentroidOffset(BlastCore.Piece piece, out int offX, out int offY)
    {
        float ax = 0f, ay = 0f;
        int n = piece.Cells.Length;
        foreach (var (dx, dy) in piece.Cells) { ax += dx; ay += dy; }
        if (n > 0) { ax /= n; ay /= n; }
        offX = Mathf.RoundToInt(ax);
        offY = Mathf.RoundToInt(ay);
    }

    // ================= TOLERANSI SNAP =================
    // Cari anchor VALID terdekat dari (baseCol,baseRow) dalam radius snapSearchRadius.
    // Skor = jarak^2 dari anchor jari; dikurangi magnetClearBonus bila posisi itu
    // memicu clear (magnet ke ring/kolom hampir penuh). Return posisi terbaik.
    bool TryFindPlacement(BlastCore.Piece piece, int baseCol, int baseRow,
                          out int bestCol, out int bestRow)
    {
        var core = _game.Core;
        bestCol = baseCol; bestRow = baseRow;

        // Tanpa toleransi: cek anchor apa adanya (perilaku lama).
        if (!snapToNearestValid)
            return core.CanPlace(piece, baseCol, baseRow);

        int radius = Mathf.Max(0, snapSearchRadius);
        float best = float.MaxValue;
        bool found = false;

        for (int dr = -radius; dr <= radius; dr++)
        {
            for (int dc = -radius; dc <= radius; dc++)
            {
                int cc = core.Wrap(baseCol + dc);
                int rr = baseRow + dr;
                if (!core.CanPlace(piece, cc, rr)) continue;

                float score = dc * dc + dr * dr; // makin dekat jari makin diutamakan
                if (magnetToClears)
                {
                    var clears = PredictClears(piece, cc, rr);
                    if (clears.Count > 0) score -= magnetClearBonus;
                }

                if (score < best) { best = score; bestCol = cc; bestRow = rr; found = true; }
            }
        }
        return found;
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

    // Saat menyeret potongan & jari dekat tepi KIRI/KANAN layar, putar tabung
    // perlahan supaya sel di sisi yang belum kelihatan bisa dijangkau.
    void HandleEdgeAutoRotate()
    {
        if (!autoRotateWhileDragging) return;
        float x = PointerPosition().x;
        float w = Screen.width;
        float edge = Mathf.Max(1f, edgeRotatePx);
        float dir = 0f;
        if (x < edge) dir = 1f;               // dekat tepi KIRI
        else if (x > w - edge) dir = -1f;     // dekat tepi KANAN
        if (Mathf.Abs(dir) < 0.5f) return;
        float deg = dir * edgeRotateSpeed * Time.deltaTime;
        _game.transform.Rotate(0f, deg, 0f, Space.World);
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

    // ================= INDIKATOR SEL TUJUAN (highlight halus) =================
    void EnsureGhostRoot()
    {
        if (_ghostRoot != null) return;
        var gr = new GameObject("Ghost").transform;
        gr.SetParent(_game.transform, false);
        _ghostRoot = gr;
        _ghosts.Clear();
    }

    void SetGhost(bool show, BlastCore.Piece piece, int col, int row)
    {
        if (!show || piece == null)
        {
            for (int i = 0; i < _ghosts.Count; i++)
                if (_ghosts[i] != null) _ghosts[i].SetActive(false);
            return;
        }

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
            // highlight "membungkus" sel tujuan (sedikit lebih besar dari blok).
            // Dibikin lebih tebal biar indikatornya lebih tegas.
            g.transform.localScale = new Vector3(_game.cellWidth * _game.gap * 1.08f,
                                                 _game.cellHeight * _game.gap * 1.08f,
                                                 _game.blockDepth * 1.12f);
            g.GetComponent<MeshRenderer>().sharedMaterial = _matGhost;
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

    // ================= BLOK MELAYANG (poin 1) =================
    void EnsureHeldRoot()
    {
        if (_heldRoot != null) return;
        var hr = new GameObject("HeldPiece").transform;
        // sengaja TANPA parent tabung supaya tidak ikut berputar bersama tabung.
        _heldRoot = hr;
        _held.Clear();
    }

    // Blok melayang punya DUA mode:
    //  (A) MELENGKUNG di tabung (saat terkunci ke ghost) -> tiap kubus dipetakan ke
    //      permukaan silinder pakai CellToWorld + CellRotation (persis seperti ghost),
    //      lalu diangkat RADIAL keluar sejauh heldGhostLiftCells. Hasilnya lengkungnya
    //      SINKRON dengan bayangan, apa pun angle/zoom kamera.
    //  (B) OVERLAY LAYAR rata (fallback saat belum ada sel tujuan valid) -> mengikuti
    //      jari, menghadap kamera, seukuran blok asli. Diwarnai MERAH bila tak muat.
    void SetHeldPiece(bool show, BlastCore.Piece piece)
    {
        EnsureHeldRoot();
        if (!show || piece == null || _cam == null)
        {
            for (int i = 0; i < _held.Count; i++)
                if (_held[i] != null) _held[i].SetActive(false);
            return;
        }

        EnsureHeld(piece.Cells.Length);

        bool lockedToGhost = _hasLast && _lastCanPlace;
        if (lockedToGhost) RenderHeldCurved(piece);   // (A) melengkung di tabung
        else RenderHeldFlatOverlay(piece);            // (B) overlay layar mengikuti jari
    }

    // (A) Blok melayang MELENGKUNG: dipetakan ke permukaan tabung seperti ghost,
    // lalu diangkat radial keluar biar "melayang" di atas bayangan & tak ketutup jari.
    void RenderHeldCurved(BlastCore.Piece piece)
    {
        float lift = _game.cellHeight * Mathf.Max(0f, heldGhostLiftCells);

        int used = 0;
        foreach (var (dx, dy) in piece.Cells)
        {
            int r = _lastRow + dy;
            if (r < 0 || r >= _game.height) continue;
            int c = _game.Core.Wrap(_lastCol + dx);

            Vector3 localPos = _game.CellToWorld(c, r);
            Quaternion localRot = _game.CellRotation(c);
            Vector3 outward = localRot * Vector3.forward; // arah radial keluar (ruang lokal tabung)
            localPos += outward * lift;                   // angkat menjauh dari permukaan

            var g = _held[used++];
            g.SetActive(true);
            // pakai transform tabung -> ikut posisi & rotasi tabung (sinkron dgn ghost).
            g.transform.position = _game.transform.TransformPoint(localPos);
            g.transform.rotation = _game.transform.rotation * localRot;
            g.transform.localScale = new Vector3(_game.cellWidth * _game.gap,
                                                 _game.cellHeight * _game.gap,
                                                 _game.blockDepth);
            g.GetComponent<MeshRenderer>().sharedMaterial = SolidMat(piece.Color);
        }
        for (int i = used; i < _held.Count; i++)
            if (_held[i] != null) _held[i].SetActive(false);
    }

    // (B) Fallback OVERLAY LAYAR rata: dipakai saat belum ada sel tujuan valid.
    // Tata letak sel dihitung dalam PIXEL layar (relatif titik acuan = jari + offset),
    // diproyeksikan dekat kamera (heldDepth) & selalu menghadap kamera -> tampak rata.
    // Diwarnai MERAH (invalidHeldColor) sebagai feedback "belum ketemu sel valid".
    void RenderHeldFlatOverlay(BlastCore.Piece piece)
    {
        int len = piece.Cells.Length;
        float avgX = 0f, avgY = 0f;
        foreach (var (dx, dy) in piece.Cells) { avgX += dx; avgY += dy; }
        if (len > 0) { avgX /= len; avgY /= len; }

        float d = Mathf.Max(0.05f, heldDepth);
        float tanV = Mathf.Tan(_cam.fieldOfView * 0.5f * Mathf.Deg2Rad);
        float invH = 1f / Mathf.Max(1, Screen.height);

        // Ukuran sel blok melayang (pixel). Kalau matchBlockSize: hitung supaya
        // apparent size-nya SAMA dengan blok asli di permukaan DEPAN tabung.
        float effPx = heldPixelSize;
        if (matchBlockSize)
        {
            Vector3 tubeCenter = _game.transform.position
                                 + Vector3.up * (_game.height * _game.cellHeight * 0.5f);
            float dTube = Mathf.Max(0.1f,
                Vector3.Distance(_cam.transform.position, tubeCenter) - _game.Radius);
            float wppTube = (2f * dTube * tanV) * invH;
            if (wppTube > 1e-6f) effPx = (_game.cellWidth * _game.gap) / wppTube;
        }
        effPx *= Mathf.Max(0.05f, heldSizeMultiplier);

        Vector2 anchor = PointerPosition();
        anchor.y += heldScreenYOffset;

        float worldPerPixel = (2f * d * tanV) * invH;
        float cube = effPx * worldPerPixel; // sisi kubus di dunia (~effPx px di layar)

        Quaternion rot = _cam.transform.rotation; // menghadap kamera -> tampak rata di layar

        // Material: merah kalau tak muat (feedback), selain itu warna asli potongan.
        Material mat = (tintInvalidHeld && _matInvalidHeld != null)
                       ? _matInvalidHeld : SolidMat(piece.Color);

        int used = 0;
        foreach (var (dx, dy) in piece.Cells)
        {
            // posisi sel di LAYAR (pixel), lalu proyeksikan ke dunia di depan kamera.
            Vector2 sp = anchor + new Vector2((dx - avgX) * effPx,
                                              (dy - avgY) * effPx);
            Vector3 world = _cam.ScreenToWorldPoint(new Vector3(sp.x, sp.y, d));

            var g = _held[used++];
            g.SetActive(true);
            g.transform.position = world;
            g.transform.rotation = rot;
            g.transform.localScale = new Vector3(cube * _game.gap, cube * _game.gap, cube * 0.6f);
            g.GetComponent<MeshRenderer>().sharedMaterial = mat;
        }
        for (int i = used; i < _held.Count; i++)
            if (_held[i] != null) _held[i].SetActive(false);
    }

    void EnsureHeld(int n)
    {
        while (_held.Count < n)
        {
            var go = new GameObject("HeldCube");
            go.transform.SetParent(_heldRoot, false);
            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _game.CellMesh;
            go.AddComponent<MeshRenderer>();
            go.SetActive(false);
            _held.Add(go);
        }
    }

    // Material SOLID (opaque) berwarna asli potongan, dipakai untuk blok melayang.
    Material SolidMat(int color)
    {
        if (_solidMats.TryGetValue(color, out var found) && found != null) return found;
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);
        Color c = (_game.palette != null && color >= 0 && color < _game.palette.Length)
                  ? _game.palette[color] : Color.white;
        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", c);
        m.color = c;
        _solidMats[color] = m;
        return m;
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
            // Emission dinaikkan (0.9 -> 1.7) biar indikator lebih tegas/nyala.
            m.SetColor("_EmissionColor", new Color(col.r, col.g, col.b) * 1.7f);
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
