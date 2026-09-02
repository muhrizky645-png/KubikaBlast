using UnityEngine;
using KubikaBlast;

/// <summary>
/// SUSUNAN PAPAN AWAL - MOZAIK BERATURAN YANG DIUNDI TIAP RONDE.
///
/// SEJARAH SINGKAT (supaya tidak berputar balik lagi):
///   V1 - StartingFill() bawaan: acak murni per sel. Terlihat seperti derau.
///   V2 - Fondasi corong (baris penuh berlubang 1/2/4). Kaku, jelas "disusun mesin".
///   V3 - Taburan organik (noise sinus, berat di dasar). SALAH ARAH: itu meniru
///        endapan/gravitasi, padahal TABUNG INI TIDAK PUNYA ATAS DAN BAWAH -
///        dia cuma papan datar yang digulung. Jadi siluet "berat di bawah" tidak
///        punya arti apa-apa di sini. Dan yang diminta memang bukan acak organik.
///   V4 (INI) - MOZAIK: motif geometris yang benar-benar beraturan, dipilih acak
///        dari perpustakaan 7 motif tiap kali permainan dimulai.
///
/// PRINSIP DESAINNYA:
///   1. TERATUR, BUKAN ACAK. Setiap sel ditentukan rumus periodik, bukan undian.
///      Mata langsung membaca polanya - itu yang bikin terasa "indah", bukan
///      ketidakteraturan.
///   2. ACAKNYA DI TINGKAT GAYA, BUKAN DI TINGKAT SEL. Yang diundi tiap ronde:
///      motif mana (7 pilihan), putaran mengelilingi tabung, arah miring, cermin,
///      balik vertikal, fase gelombang, dan palet warnanya. Jadi tiap PLAY selalu
///      beda, tapi selalu rapi.
///   3. PAPAN DATAR, BUKAN TUMPUKAN. Mozaik ditaruh sebagai PITA yang melingkari
///      tengah tabung (BAND_ROWS), dengan ruang kosong di atas DAN di bawahnya.
///      Tidak ada lagi kepadatan yang meluruh ke atas.
///   4. MULUS DI SAMBUNGAN. Periode motif selalu dipilih dari pembagi jumlah
///      kolom, jadi kolom terakhir menyambung mulus ke kolom 0 - tidak ada
///      jahitan yang kelihatan saat tabung diputar.
///   5. PALET TERBATAS. Tiap ronde hanya memakai PALETTE_SIZE warna (default 3),
///      diundi dari palet penuh, dan warna diberikan PER MOTIF - bukan per sel.
///      Ini pembeda terbesar dari versi lama yang terlihat seperti confetti.
///
/// LEBIH MUDAH:
///   - Pita cuma setinggi BAND_ROWS baris, sisanya lapang.
///   - Kepadatan motif berkisar 30-55%, bukan 80%.
///   - Ada "jendela" yang sengaja dilubangi, berpasangan di sisi seberang tabung
///     supaya tetap terlihat disengaja, bukan rusak.
///   - Tray pembuka dibias kuat ke potongan yang bisa langsung meng-clear.
///   - Kalau ternyata tetap tidak ada clear yang mungkin, PAPANNYA yang mengalah
///     (AdaptToTray) - sisa satu cincin diisi memakai warna motif yang sama, jadi
///     tambalannya menyatu dengan mozaik.
///
/// PERPUSTAKAAN MOTIF:
///   0 RIBBON  - pita diagonal (garis miring lebar 2)
///   1 CHECKER - papan catur blok 2x2
///   2 LATTICE - kisi motif plus/wajik
///   3 CHEVRON - zigzag
///   4 GROUT   - kisi garis nat (paling padat, sering bikin cincin nyaris penuh)
///   5 WAVE    - pita gelombang mengalir mengelilingi tabung
///   6 BRICK   - susunan bata berselang-seling
///
/// KENAPA FILE TERPISAH (BUKAN MENGEDIT BlastGame.cs):
///   BlastGame.cs 33 KB - di atas batas aman push. Semua yang dibutuhkan sudah
///   publik: Core.Grid, Core.Wrap, Core.CanPlace, Core.RegenerateTray,
///   Core.CanPlaceAnywhere, Core.ClearBias, RenderGrid(). StartingFill() bawaan
///   dibiarkan jalan, hasilnya kita timpa dari luar. NOL perubahan di file besar.
///
/// KENAPA POLLING, BUKAN EVENT OnRebuilt:
///   Bootstrap AfterSceneLoad bisa jalan SETELAH Rebuild() pertama, jadi event
///   papan pertama bisa terlewat. Kita pantau IDENTITAS BlastCore: core baru =
///   ronde baru. Menangkap papan pertama maupun tiap PLAY AGAIN, dan mustahil
///   jalan dua kali untuk ronde yang sama.
///
/// HUBUNGAN DENGAN KubikaIntro:
///   RenderGrid() membuat blok dalam keadaan AKTIF, dan itu aman karena
///   IntroRoutine() mematikan SEMUA blok sekaligus sebelum tiruan pertama
///   diluncurkan - tabung tetap mulai KOSONG.
/// </summary>
public class KubikaStartLayout : MonoBehaviour
{
    // ================= TOMBOL PENYETEL =================

    /// <summary>Tinggi pita mozaik dalam baris. Kecilkan = makin mudah &amp; makin lapang.</summary>
    const int BAND_ROWS = 5;

    /// <summary>Geser pita naik (+) atau turun (-) dari tengah tabung.</summary>
    const int BAND_SHIFT = 0;

    /// <summary>Berapa warna yang dipakai satu ronde. 2 = paling tenang, 3 = seimbang.</summary>
    const int PALETTE_SIZE = 3;

    /// <summary>Berapa pasang "jendela" yang dilubangi (tiap pasang = 2 lubang berseberangan).</summary>
    const int WINDOW_PAIRS = 1;
    const int WINDOW_W = 3;
    const int WINDOW_H = 2;

    /// <summary>
    /// Seberapa kuat tray PEMBUKA dibias agar memuat potongan yang bisa meng-clear
    /// (0 = acak murni, 1 = selalu diusahakan). Hanya dipakai sekali saat papan
    /// dibuat; sesudahnya nilai dari scene dipulihkan.
    /// </summary>
    const float OPENING_CLEAR_BIAS = 0.9f;

    /// <summary>
    /// Maksimum sel yang boleh DITAMBAHKAN demi menjamin clear di langkah pertama.
    /// Kecilkan kalau tambalannya mulai terlihat; besarkan kalau clear pembuka
    /// terlalu jarang terjadi.
    /// </summary>
    const int ADAPT_MAX_FILL = 6;

    const int PATTERN_COUNT = 7;

    BlastGame _game;
    BlastCore _lastCore;

    // Gaya ronde ini - semuanya diundi ulang tiap papan baru.
    int _pattern = -1;
    int _spin, _dir, _mirror, _flip;
    float _phase;
    int _bandRows, _rowStart;
    readonly int[] _pal = new int[PALETTE_SIZE];

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void Bootstrap()
    {
        if (FindFirstObjectByType<KubikaStartLayout>() != null) return;
        var go = new GameObject("KubikaStartLayout (auto)");
        go.AddComponent<KubikaStartLayout>();
    }

    void Update()
    {
        // Papan bisa dibangun ulang kapan saja, jadi rujukannya dicari terus.
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_game == null) return;

        var core = _game.Core;
        if (core == null) return;

        // Core BARU = ronde baru. Ini pemancing kita, sekali per ronde.
        if (ReferenceEquals(core, _lastCore)) return;
        _lastCore = core;

        Apply(core);
    }

    void Apply(BlastCore core)
    {
        if (_game == null || core == null) return;

        // Hormati setelan scene.
        if (!_game.startWithBlocks || _game.demoFill) return;
        if (core.GameOver) return;

        int cols = _game.columns;
        int h = _game.height;
        int colors = Mathf.Max(1, _game.numColors);
        if (cols <= 2 || h <= 3) return;

        // Pita diletakkan di TENGAH papan: tabung tidak punya atas/bawah, jadi
        // tidak ada alasan menumpuk di dasar. Ruang kosong di kedua sisi juga
        // yang bikin langkah pertama gampang.
        _bandRows = Mathf.Clamp(BAND_ROWS, 1, h - 2);
        _rowStart = Mathf.Clamp((h - _bandRows) / 2 + BAND_SHIFT, 0, h - _bandRows);

        RollStyle(cols, colors);

        // ===== 1. Kosongkan papan (buang hasil acak StartingFill) =====
        for (int c = 0; c < cols; c++)
            for (int r = 0; r < h; r++)
                core.Grid[c, r] = -1;

        // ===== 2. Cetak mozaik =====
        for (int r = _rowStart; r < _rowStart + _bandRows; r++)
            for (int c = 0; c < cols; c++)
            {
                int m = Motif(c, r, cols);
                if (m >= 0) core.Grid[c, r] = _pal[Mod(m, PALETTE_SIZE)];
            }

        // ===== 3. Jendela yang disengaja =====
        CarveWindows(core, cols);

        // ===== 4. Anti auto-clear =====
        // Motif seperti GROUT bisa menghasilkan cincin penuh. Satu sel dilubangi,
        // dan justru itu yang menyisakan cincin nyaris penuh - enak buat pembuka.
        BreakFullLines(core, cols, h);

        // ===== 5. Tray pembuka =====
        // WAJIB: tray lama dipahat dari papan yang baru saja kita buang.
        core.ClearBias = Mathf.Clamp01(OPENING_CLEAR_BIAS);
        core.RegenerateTray();
        core.ClearBias = Mathf.Clamp01(_game.clearBias);

        // ===== 6. Cocokkan papan ke potongan yang benar-benar dipegang pemain =====
        if (!HasImmediateClear(core, cols, h))
            AdaptToTray(core, cols, h);

        // ===== 7. Anti mati-instan =====
        int guard = 0;
        int maxSteps = cols * _bandRows + 1;
        while (!AnyTrayFits(core) && guard++ < maxSteps)
            core.Grid[Random.Range(0, cols), Random.Range(_rowStart, _rowStart + _bandRows)] = -1;

        // ===== 8. Gambar ulang =====
        _game.RenderGrid();
    }

    // ================= GAYA RONDE =================

    /// <summary>
    /// Semua keacakan permainan ini ada DI SINI, dan berhenti di sini. Setelah
    /// gaya terundi, pencetakan mozaik sepenuhnya deterministik - itulah kenapa
    /// hasilnya selalu rapi walaupun selalu berbeda.
    /// </summary>
    void RollStyle(int cols, int colors)
    {
        int p = Random.Range(0, PATTERN_COUNT);
        // Jangan mengulang motif ronde sebelumnya - pengulangan langsung itu yang
        // paling terasa "kok gitu-gitu aja".
        if (p == _pattern) p = (p + 1 + Random.Range(0, PATTERN_COUNT - 1)) % PATTERN_COUNT;
        _pattern = p;

        _spin = Random.Range(0, cols);
        _dir = Random.value < 0.5f ? -1 : 1;
        _mirror = Random.value < 0.5f ? 1 : 0;
        _flip = Random.value < 0.5f ? 1 : 0;
        _phase = Random.Range(0f, Mathf.PI * 2f);

        PickPalette(colors);
    }

    /// <summary>Ambil PALETTE_SIZE warna berbeda dari palet penuh, acak tiap ronde.</summary>
    void PickPalette(int colors)
    {
        var all = new int[colors];
        for (int i = 0; i < colors; i++) all[i] = i;
        for (int i = colors - 1; i > 0; i--)
        {
            int j = Random.Range(0, i + 1);
            int t = all[i]; all[i] = all[j]; all[j] = t;
        }

        int n = Mathf.Max(1, Mathf.Min(PALETTE_SIZE, colors));
        for (int i = 0; i < _pal.Length; i++) _pal[i] = all[i % n];
    }

    // ================= PERPUSTAKAAN MOTIF =================

    /// <summary>
    /// Mengembalikan nomor motif untuk sel (c,r), atau -1 kalau sel itu kosong.
    /// Nomor motif dipetakan ke warna lewat _pal, jadi satu bentuk = satu warna.
    /// </summary>
    int Motif(int c, int r, int cols)
    {
        int y = r - _rowStart;
        if (y < 0 || y >= _bandRows) return -1;

        // Cermin, putaran, dan balik vertikal - variasi gratis tanpa merusak pola.
        int x = (_mirror == 1) ? (cols - 1 - c) : c;
        x = Mod(x + _spin, cols);
        int v = (_flip == 1) ? (_bandRows - 1 - y) : y;

        switch (_pattern)
        {
            case 0: return Ribbon(x, v, cols);
            case 1: return Checker(x, v, cols);
            case 2: return Lattice(x, v, cols);
            case 3: return Chevron(x, v, cols);
            case 4: return Grout(x, v, cols);
            case 5: return Wave(x, v, cols);
            default: return Brick(x, v, cols);
        }
    }

    /// <summary>Pita diagonal lebar 2. Miringnya ikut _dir.</summary>
    int Ribbon(int x, int y, int cols)
    {
        int p = Period(cols, 4);
        int s = Mod(x + _dir * y, cols);
        return (s % p) < (p / 2) ? (s / p) : -1;
    }

    /// <summary>Papan catur dengan blok 2x2.</summary>
    int Checker(int x, int y, int cols)
    {
        // Ukuran blok harus membuat jumlah blok per keliling GENAP, kalau tidak
        // sambungan kolom terakhir ke kolom 0 akan kelihatan.
        int b = (cols % 4 == 0) ? 2 : 1;
        int bx = x / b, by = y / b;
        return ((bx + by) % 2 == 0) ? (bx + by * 2) : -1;
    }

    /// <summary>Kisi motif plus/wajik kecil - paling longgar, paling mudah.</summary>
    int Lattice(int x, int y, int cols)
    {
        int p = Period(cols, 4);
        int u = Mod(x, p), w = Mod(y, p);
        int cu = p / 2;
        return (Mathf.Abs(u - cu) + Mathf.Abs(w - cu) <= 1) ? (x / p + (y / p) * 2) : -1;
    }

    /// <summary>Zigzag: pita vertikal yang digeser bolak-balik tiap baris.</summary>
    int Chevron(int x, int y, int cols)
    {
        int p = Period(cols, 6);
        int amp = Mathf.Max(1, p / 2);
        int t = Mod(y, amp * 2);
        int off = (t <= amp) ? t : (amp * 2 - t);
        int s = Mod(x - off * _dir, cols);
        return (s % p) < (p / 2) ? (s / p) : -1;
    }

    /// <summary>Kisi garis nat. Motif terpadat - sering menyisakan cincin nyaris penuh.</summary>
    int Grout(int x, int y, int cols)
    {
        int p = Period(cols, 3);
        return (Mod(x, p) == 0 || Mod(y, p) == 0) ? (x / p + y / p) : -1;
    }

    /// <summary>Pita gelombang setebal 2 yang mengalir mengelilingi tabung.</summary>
    int Wave(int x, int y, int cols)
    {
        float a = (x / (float)cols) * Mathf.PI * 4f + _phase; // 2 puncak per keliling -> mulus
        float mid = (_bandRows - 1) * 0.5f;
        float amp = (_bandRows - 1) * 0.5f;
        int cy = Mathf.RoundToInt(mid + amp * Mathf.Sin(a));
        if (y != cy && y != cy - 1) return -1;
        return Mathf.FloorToInt((x / (float)cols) * (PALETTE_SIZE * 2f));
    }

    /// <summary>Susunan bata: potongan lebar 2, berselang-seling tiap baris.</summary>
    int Brick(int x, int y, int cols)
    {
        int p = Period(cols, 4);
        int off = (Mod(y, 2) == 0) ? 0 : (p / 2);
        int s = Mod(x + off, cols);
        return (s % p) < (p / 2) ? (s / p + y) : -1;
    }

    /// <summary>
    /// Periode motif WAJIB membagi habis jumlah kolom, kalau tidak akan ada
    /// jahitan di tempat tabung menyambung. Dicari pembagi terdekat dari nilai
    /// yang diinginkan.
    /// </summary>
    static int Period(int cols, int want)
    {
        for (int p = want; p >= 2; p--) if (cols % p == 0) return p;
        for (int p = want + 1; p <= cols; p++) if (cols % p == 0) return p;
        return Mathf.Max(2, cols);
    }

    static int Mod(int a, int b) => ((a % b) + b) % b;

    // ================= JENDELA =================

    /// <summary>
    /// Lubang persegi yang disengaja. Selalu dibuat BERPASANGAN di sisi seberang
    /// tabung supaya terbaca sebagai bagian desain, bukan pola yang rusak.
    /// </summary>
    void CarveWindows(BlastCore core, int cols)
    {
        for (int i = 0; i < WINDOW_PAIRS; i++)
        {
            int span = Mathf.Max(1, _bandRows - WINDOW_H + 1);
            int c0 = Random.Range(0, cols);
            int r0 = _rowStart + Random.Range(0, span);
            Carve(core, cols, c0, r0);
            Carve(core, cols, c0 + cols / 2, r0);
        }
    }

    void Carve(BlastCore core, int cols, int c0, int r0)
    {
        for (int dx = 0; dx < WINDOW_W; dx++)
            for (int dy = 0; dy < WINDOW_H; dy++)
            {
                int r = r0 + dy;
                if (r < _rowStart || r >= _rowStart + _bandRows) continue;
                core.Grid[Mod(c0 + dx, cols), r] = -1;
            }
    }

    // ================= PENYESUAIAN KE TRAY =================

    /// <summary>Warna motif untuk sel tertentu; dipakai saat menambal supaya menyatu.</summary>
    int ColorAt(int c, int r, int cols)
    {
        int m = Motif(c, r, cols);
        if (m < 0) m = c + r * 2;
        return _pal[Mod(m, PALETTE_SIZE)];
    }

    /// <summary>Adakah SATU penempatan sah dari tray yang langsung melengkapi cincin/kolom?</summary>
    static bool HasImmediateClear(BlastCore core, int cols, int h)
    {
        if (core.Tray == null) return false;

        foreach (var p in core.Tray)
        {
            if (p == null || p.Used) continue;
            for (int r = 0; r < h; r++)
                for (int c = 0; c < cols; c++)
                {
                    if (!core.CanPlace(p, c, r)) continue;
                    if (CompletesLine(core, p, c, r, cols, h)) return true;
                }
        }
        return false;
    }

    /// <summary>
    /// Simulasi di grid SALINAN: kalau potongan ini ditaruh di (col,row), apakah
    /// ada cincin atau kolom yang jadi penuh? Grid asli tidak pernah disentuh.
    /// </summary>
    static bool CompletesLine(BlastCore core, BlastCore.Piece p, int col, int row, int cols, int h)
    {
        var g = (int[,])core.Grid.Clone();

        foreach (var cell in p.Cells)
        {
            int r = row + cell.y;
            if (r < 0 || r >= h) return false;
            g[core.Wrap(col + cell.x), r] = p.Color;
        }

        foreach (var cell in p.Cells)
        {
            int r = row + cell.y;
            int c = core.Wrap(col + cell.x);

            bool full = true;
            for (int cc = 0; cc < cols; cc++) if (g[cc, r] < 0) { full = false; break; }
            if (full) return true;

            full = true;
            for (int rr = 0; rr < h; rr++) if (g[c, rr] < 0) { full = false; break; }
            if (full) return true;
        }
        return false;
    }

    /// <summary>
    /// Papan yang mengalah ke tray. Dicari pasangan (potongan, penempatan, cincin)
    /// yang paling MURAH - cincin yang tinggal kurang beberapa sel - lalu sisanya
    /// diisi dengan WARNA MOTIF supaya tambalannya menyatu dengan mozaik.
    /// </summary>
    void AdaptToTray(BlastCore core, int cols, int h)
    {
        if (core.Tray == null) return;

        int bestScore = int.MaxValue;
        BlastCore.Piece bestPiece = null;
        int bestCol = 0, bestRow = 0, bestRing = -1;

        int rLo = Mathf.Max(0, _rowStart - 1);
        int rHi = Mathf.Min(h, _rowStart + _bandRows + 1);
        int mid = _rowStart + _bandRows / 2;

        foreach (var p in core.Tray)
        {
            if (p == null || p.Used) continue;

            for (int r0 = 0; r0 < h; r0++)
                for (int c0 = 0; c0 < cols; c0++)
                {
                    if (!core.CanPlace(p, c0, r0)) continue;

                    foreach (var cell in p.Cells)
                    {
                        int ring = r0 + cell.y;
                        if (ring < rLo || ring >= rHi) continue;

                        int cost = 0;
                        for (int c = 0; c < cols; c++)
                        {
                            if (core.Grid[c, ring] >= 0) continue;
                            if (Covers(core, p, c0, r0, c, ring)) continue;
                            cost++;
                        }
                        if (cost > ADAPT_MAX_FILL) continue;

                        // cost yang menentukan; kedekatan ke tengah pita jadi pemecah seri.
                        int score = cost * 100 + Mathf.Abs(ring - mid);
                        if (score < bestScore)
                        {
                            bestScore = score;
                            bestPiece = p;
                            bestCol = c0; bestRow = r0; bestRing = ring;
                        }
                    }
                }
        }

        // Tidak ada kandidat cukup murah: biarkan. Tray sudah dibias 0.9, dan
        // memaksa isi banyak sel justru merusak mozaiknya.
        if (bestPiece == null || bestRing < 0) return;

        for (int c = 0; c < cols; c++)
        {
            if (core.Grid[c, bestRing] >= 0) continue;
            if (Covers(core, bestPiece, bestCol, bestRow, c, bestRing)) continue;
            core.Grid[c, bestRing] = ColorAt(c, bestRing, cols);
        }

        // Mengisi cincin bisa tidak sengaja melengkapi sebuah KOLOM. Kalau terjadi,
        // lubangi kolomnya di baris SELAIN bestRing supaya jaminan tadi tetap utuh.
        for (int c = 0; c < cols; c++)
        {
            bool full = true;
            for (int r = 0; r < h; r++) if (core.Grid[c, r] < 0) { full = false; break; }
            if (!full) continue;

            for (int r = h - 1; r >= 0; r--)
                if (r != bestRing) { core.Grid[c, r] = -1; break; }
        }
    }

    /// <summary>Apakah potongan p di jangkar (col,row) menutupi sel (c,r)?</summary>
    static bool Covers(BlastCore core, BlastCore.Piece p, int col, int row, int c, int r)
    {
        foreach (var cell in p.Cells)
            if (row + cell.y == r && core.Wrap(col + cell.x) == c) return true;
        return false;
    }

    // ================= JARING PENGAMAN =================

    static void BreakFullLines(BlastCore core, int cols, int h)
    {
        for (int r = 0; r < h; r++)
        {
            bool full = true;
            for (int c = 0; c < cols; c++) if (core.Grid[c, r] < 0) { full = false; break; }
            if (full) core.Grid[Random.Range(0, cols), r] = -1;
        }
        for (int c = 0; c < cols; c++)
        {
            bool full = true;
            for (int r = 0; r < h; r++) if (core.Grid[c, r] < 0) { full = false; break; }
            if (full) core.Grid[c, Random.Range(0, h)] = -1;
        }
    }

    static bool AnyTrayFits(BlastCore core)
    {
        if (core == null || core.Tray == null) return true;
        foreach (var p in core.Tray)
            if (p != null && !p.Used && core.CanPlaceAnywhere(p)) return true;
        return false;
    }
}
