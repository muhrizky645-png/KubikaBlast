// Dukung DUA backend input Unity: Input Manager (lama) & Input System (baru).
// Kalau project cuma pakai Input System baru (default Unity 6 URP), branch
// USE_NEW_INPUT yang dipakai. Kalau ada Input Manager lama (atau "Both"),
// pakai API lama. Jadi script ini jalan tanpa perlu ubah Player Settings.
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

// BAGIAN 1 dari 2 (logika input, penempatan, rotasi).
// Bagian visual (ghost / preview clear / blok melayang) + abstraksi tombol ada
// di BlastInputVisuals.cs. Dipecah jadi partial class supaya tiap file kecil
// dan aman saat di-push.

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
/// Ghost &amp; preview root juga dibuat ulang otomatis kalau hilang (setelah Rebuild).
///
/// MODEL MURNI SERET-DARI-TRAY (HP) ala Block Blast:
///  1. TEKAN jari TEPAT di potongan tray yang diinginkan (BUKAN di tabung).
///  2. Tanpa melepas, SERET jari ke tabung. Selama menyeret, potongan tampak
///     "MELAYANG" DI ATAS JARI (lihat "TITIK INCAR" di bawah).
///  3. Kalau posisi seret membuat cincin/kolom PENUH -&gt; sel yang akan hancur
///     ikut MENYALA (preview clear ala Block Blast).
///  4. LEPAS jari -&gt; potongan ditaruh di sel tujuan. Lepas di luar tabung = batal.
///  * Menekan/menyeret LANGSUNG di tabung TIDAK menaruh apa pun. Menaruh HANYA
///    sah lewat gestur seret yang DIMULAI dari slot tray.
///
/// TITIK INCAR DIANGKAT DI ATAS JARI (perbaikan main di HP):
///  Dulu sel tujuan dihitung TEPAT di titik jari, jadi blok selalu ketutup jari
///  dan susah dilihat. Sekarang raycast pakai PointerAimPosition() = titik jari
///  + offset ke ATAS sebesar aimOffsetCells (satuan SEL, jadi ikut skala zoom).
///  Hasilnya: jari tetap di bawah, blok &amp; indikator sel tujuan ada di atas jari
///  sehingga jelas kelihatan. Atur lewat Inspector: liftAimAboveFinger,
///  aimOffsetCells, maxAimOffsetFraction.
///
/// POLESAN UX PENEMPATAN:
///  - Toleransi snap: kalau titik incar tak pas, cari sel valid TERDEKAT.
///  - Auto-putar tabung saat jari dekat tepi layar (jangkau sisi tersembunyi).
///
/// Putar TABUNG: SATU JARI (seret di area tabung) / DUA JARI / drag KLIK-KANAN / Q-E / panah.
/// </summary>
[RequireComponent(typeof(BlastGame))]
[DefaultExecutionOrder(1000)]
public partial class BlastInput : MonoBehaviour
{
    [Header("Kecepatan putar tabung")]
    public float keyRotateSpeed = 90f;    // derajat / detik (Q/E, panah kiri-kanan)
    public float dragRotateSpeed = 0.3f;  // derajat / pixel (drag klik-kanan atau 2 jari)

    // Putar tabung pakai 1 JARI: seret 1 jari di area tabung (BUKAN slot tray/UI).
    public bool oneFingerRotate = true;
    public float fingerRotateSpeed = 0.3f; // derajat / pixel saat putar 1 jari

    [Header("Perilaku ghost / drag")]
    // true (HP): menaruh HANYA lewat seret DARI slot tray. false (mouse): preview saat hover.
    public bool ghostOnlyWhileDragging = true;
    // Jarak minimal (pixel) jari harus bergerak agar dihitung MENYERET, bukan tap.
    public float dragThreshold = 12f;

    [Header("Titik incar di ATAS jari (anti ketutup jempol)")]
    // Inti perbaikan main di HP: sel tujuan TIDAK lagi dihitung tepat di titik
    // jari, tapi di titik yang lebih TINGGI. Jadi jari boleh tetap di bawah,
    // sementara blok & indikator sel tujuan kelihatan jelas di atas jari.
    public bool liftAimAboveFinger = true;
    // Besar jarak angkat dalam satuan SEL (bukan pixel), supaya konsisten di
    // semua ukuran layar & tingkat zoom kamera. 1.8 = sekitar dua blok di atas jari.
    public float aimOffsetCells = 1.8f;
    // Batas aman: offset tidak boleh lebih dari sekian bagian tinggi layar,
    // supaya di layar pendek titik incar tidak kebablasan keluar layar.
    public float maxAimOffsetFraction = 0.22f;

    [Header("Indikator sel tujuan (gaya Block Blast)")]
    // Highlight di sel tempat potongan akan mendarat. Alpha dinaikkan biar lebih TEGAS
    // (gampang kelihatan sel tujuannya). Dipakai HANYA saat posisi PAS.
    public Color ghostHighlightColor = new Color(1f, 1f, 1f, 0.35f);

    [Header("Preview CLEAR ala Block Blast")]
    public bool enableClearPreview = true;
    // Warna nyala untuk sel yang AKAN hancur (baris/kolom penuh).
    public Color clearPreviewColor = new Color(1f, 0.95f, 0.35f, 0.55f);

    [Header("Blok melayang saat diseret")]
    // Blok melayang: MELENGKUNG di tabung saat terkunci ke ghost, atau OVERLAY layar
    // rata (fallback) saat belum ada sel tujuan valid.
    public bool enableHeldPiece = true;
    // LEGACY: offset ke atas (pixel) untuk mode fallback overlay. Sekarang HANYA
    // dipakai kalau liftAimAboveFinger = false. Kalau true, offset diambil dari
    // aimOffsetCells supaya mode melengkung & mode overlay tidak lompat-lompat.
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
    // Seberapa tinggi (dalam satuan SEL) blok terangkat RADIAL dari permukaan tabung,
    // supaya terlihat melayang di atas bayangannya. 0 = pas di ghost.
    public float heldGhostLiftCells = 0.35f;

    [Header("Toleransi snap (magnet ke sel valid terdekat)")]
    // Kalau titik incar tak pas di sel valid, cari sel valid TERDEKAT dalam radius ini.
    public bool snapToNearestValid = true;
    public int snapSearchRadius = 2;      // berapa sel ke segala arah yang dicari

    [Header("Auto-putar tabung saat seret dekat tepi layar")]
    public bool autoRotateWhileDragging = true;
    public float edgeRotatePx = 90f;      // lebar zona tepi kiri/kanan (pixel)
    public float edgeRotateSpeed = 120f;  // derajat / detik saat jari di zona tepi

    BlastGame _game;
    Camera _cam;

    int _current = -1;                 // index potongan tray yang sedang dipilih
    Material _matGhost, _matPreview;
    Transform _ghostRoot, _previewRoot;
    readonly List<GameObject> _ghosts = new List<GameObject>();
    readonly List<GameObject> _previews = new List<GameObject>();

    // blok melayang: TIDAK di-parent ke tabung supaya tak ikut berputar.
    Transform _heldRoot;
    readonly List<GameObject> _held = new List<GameObject>();
    readonly Dictionary<int, Material> _solidMats = new Dictionary<int, Material>();

    // status drag-putar (klik-kanan)
    bool _rotating;
    float _lastPointerX;

    // status putar 1 jari (seret di area tabung)
    bool _fingerRotating;
    float _lastFingerX;

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
        // Catatan: pakai PointerPosition() MENTAH (bukan aim) karena ini soal
        // jari benar-benar menyentuh slot tray yang mana.
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
            // Pusatkan potongan tepat di titik incar supaya indikator tujuan
            // TIDAK geser. Anchor = sel titik incar - centroid potongan.
            PieceCentroidOffset(piece, out int offX, out int offY);
            int baseCol = core.Wrap(col - offX);
            int baseRow = row - offY;

            haveCell = true;

            // Toleransi snap: kalau anchor pas tak muat, cari sel valid TERDEKAT.
            // Bikin penempatan jauh lebih forgiving.
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
        // Blok melayang mengikuti titik incar selama menyeret dari tray.
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
            // PENTING: cek "terhalang UI" pakai TITIK INCAR, bukan titik jari.
            // Karena titik incar diangkat ke atas, jari sering masih berada di
            // area tray/tombol saat menaruh baris bawah. Yang menentukan sah/tidak
            // adalah tempat BLOK-nya, bukan tempat jarinya.
            if (draggedEnough && trayOk && _hasLast && _lastCanPlace && piece != null
                && !BlastUI.PointerBlocksPlacement(PointerAimPosition()))
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

    // ================= TITIK INCAR (AIM) =================
    // Konversi: 1 unit dunia di permukaan DEPAN tabung = berapa pixel di layar.
    // Dipakai untuk menghitung offset aim & ukuran blok melayang mode overlay.
    float PixelsPerWorldUnitAtTube()
    {
        if (_cam == null || _game == null) return 0f;
        Vector3 tubeCenter = _game.transform.position
                             + Vector3.up * (_game.height * _game.cellHeight * 0.5f);
        float dTube = Mathf.Max(0.1f,
            Vector3.Distance(_cam.transform.position, tubeCenter) - _game.Radius);
        float tanV = Mathf.Tan(_cam.fieldOfView * 0.5f * Mathf.Deg2Rad);
        float wpp = (2f * dTube * tanV) / Mathf.Max(1, Screen.height);
        return wpp > 1e-6f ? 1f / wpp : 0f;
    }

    // Berapa PIXEL titik incar diangkat di atas jari.
    // Dihitung dari aimOffsetCells (satuan sel) supaya konsisten di semua zoom,
    // lalu dibatasi maxAimOffsetFraction supaya tidak kebablasan di layar pendek.
    float AimYOffsetPixels()
    {
        if (!liftAimAboveFinger || _game == null) return 0f;
        float px = _game.cellHeight * Mathf.Max(0f, aimOffsetCells) * PixelsPerWorldUnitAtTube();
        float maxPx = Screen.height * Mathf.Clamp01(maxAimOffsetFraction);
        return Mathf.Clamp(px, 0f, maxPx);
    }

    // Titik yang dipakai untuk MENGINCAR sel tujuan = titik jari + offset ke atas.
    // Inilah kunci supaya blok tidak lagi ketutup jari.
    Vector2 PointerAimPosition()
    {
        Vector2 p = PointerPosition();
        p.y += AimYOffsetPixels();
        // jangan sampai keluar batas atas layar
        p.y = Mathf.Min(p.y, Screen.height - 1f);
        return p;
    }

    // Centroid (dibulatkan) offset sel potongan -> dipakai memusatkan di titik incar.
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
    // Skor = jarak^2 dari anchor titik incar; posisi terdekat diutamakan.
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

                float score = dc * dc + dr * dr; // makin dekat titik incar makin diutamakan

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

        // ---- Putar tabung pakai 1 JARI: seret di area tabung (bukan slot tray/UI) ----
        // Pakai titik jari MENTAH: ini soal jari menyentuh apa, bukan soal aim.
        if (oneFingerRotate)
        {
            if (PointerPressedThisFrame() && !MultiTouchActive())
            {
                Vector2 p = PointerPosition();
                bool onTray = BlastUI.TraySlotAtPointer(p) >= 0;
                bool onUI = BlastUI.PointerBlocksPlacement(p);
                if (!onTray && !onUI) { _fingerRotating = true; _lastFingerX = p.x; }
            }
            if (_fingerRotating && PointerHeld() && !MultiTouchActive())
            {
                float px = PointerPosition().x;
                float dx = px - _lastFingerX;
                _lastFingerX = px;
                deltaDeg += -dx * fingerRotateSpeed;
            }
            if (PointerReleased() || MultiTouchActive()) _fingerRotating = false;
        }

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
    // Raycast dari TITIK INCAR (di atas jari), bukan dari titik jari langsung.
    bool PointerToCell(out int col, out int row)
    {
        col = 0; row = 0;
        if (_cam == null) return false;

        float R = _game.Radius;
        if (R <= 0f) return false;

        Ray ray = _cam.ScreenPointToRay(PointerAimPosition());

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
}
