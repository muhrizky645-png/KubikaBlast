using UnityEngine;
using KubikaBlast;

/// <summary>
/// SUSUNAN PAPAN AWAL (rintangan pembuka) gaya Block Blast.
///
/// SEJARAH SINGKAT (biar tidak berputar balik):
///   Versi 1 - BlastGame.StartingFill() menabur acak murni. Terlihat seperti
///             derau: tidak ada bentuk yang bisa dibaca mata, dan tidak ada
///             jaminan pemain bisa menghancurkan apa pun di langkah awal.
///   Versi 2 - diganti FONDASI CORONG yang rapi (baris penuh berlubang 1/2/4,
///             satu warna per baris). Jaminannya dapat, tapi terlalu kaku:
///             kelihatan jelas "disusun mesin", bukan papan permainan.
///   Versi 3 (INI) - kembali ke TABURAN ACAK, tapi acak yang TERTATA, lalu
///             papannya DICOCOKKAN ke potongan yang benar-benar ada di tray.
///
/// TIGA HAL YANG BIKIN TABURAN INI ENAK DILIHAT:
///   1. GUMPALAN, BUKAN DERAU. Sel diisi lewat ambang kebisingan halus yang
///      periodik mengelilingi tabung (jumlah beberapa gelombang sinus), bukan
///      lewat undian per sel. Hasilnya massa yang menyambung dengan tepian
///      bergelombang - mata membacanya sebagai bentuk, bukan bintik.
///   2. BERAT DI BAWAH. Ambang kepadatan turun makin ke atas (BASE_DENSITY ->
///      TOP_DENSITY), jadi terbentuk siluet seperti endapan: padat di dasar,
///      makin renggang ke atas, dan puncak tabung tetap lapang buat bermain.
///   3. WARNA BERBERCAK. Warna TIDAK diundi per sel (itu yang bikin papan lama
///      terlihat seperti confetti). Warna diambil dari medan halus kedua, jadi
///      sel bertetangga cenderung sewarna dan terbentuk bercak-bercak yang
///      berpilin mengelilingi tabung. Ini penyumbang "indah" yang paling besar.
///   Di atasnya ditambah sedikit ketidakteraturan yang disengaja: goyangan tepi,
///   beberapa kantong kosong di dalam massa, dan beberapa butiran melayang di
///   atasnya - supaya tetap terasa DITABUR, bukan digambar.
///
/// "DISESUAIKAN DENGAN PILIHAN BLOK" - INI BAGIAN PENTINGNYA:
///   Urutannya sengaja dibalik dari cara biasa.
///     a. Papan ditabur lebih dulu.
///     b. Tray dicetak ulang DARI papan itu (RegenerateTray), dengan bias clear
///        tinggi. Smart-drop bawaan memahat tiap potongan dari celah NYATA, jadi
///        ketiganya dijamin muat.
///     c. Lalu dicek dengan geometri sungguhan: adakah SATU penempatan sah yang
///        langsung melengkapi cincin atau kolom? Kalau ADA, papan dibiarkan.
///        Kalau TIDAK ADA, papan yang mengalah: dipilih pasangan potongan +
///        penempatan yang paling murah, lalu sisa cincin itu diisi supaya
///        potongan tersebut menutupnya PERSIS.
///   Jadi bukan pemain yang disuruh mencari celah bikinan - papannya yang
///   dibentuk mengikuti potongan yang memang dia pegang. Batas ADAPT_MAX_FILL
///   menjaga penyesuaian ini tetap beberapa sel saja, supaya tidak kelihatan
///   seperti baris yang ditanam.
///
/// KENAPA FILE TERPISAH (BUKAN MENGEDIT BlastGame.cs):
///   BlastGame.cs sudah 33 KB - jauh di atas batas aman push kita dan satu-satunya
///   file yang pernah terpotong diam-diam. Ternyata semua yang kita butuh SUDAH
///   publik: Core.Grid, Core.Wrap, Core.CanPlace, Core.RegenerateTray,
///   Core.CanPlaceAnywhere, Core.ClearBias, dan RenderGrid(). Jadi StartingFill()
///   bawaan dibiarkan jalan apa adanya, lalu hasilnya kita timpa dari luar.
///   NOL perubahan di file besar.
///
/// KENAPA TIDAK PAKAI EVENT OnRebuilt:
///   Bootstrap AfterSceneLoad bisa jalan SETELAH BlastGame.Start() memanggil
///   Rebuild(), jadi OnRebuilt papan PERTAMA bisa terlewat. Karena itu kita pantau
///   IDENTITAS BlastCore: core baru = ronde baru. Cara ini menangkap papan pertama
///   maupun setiap PLAY AGAIN, dan mustahil jalan dua kali untuk ronde yang sama.
///
/// HUBUNGAN DENGAN KubikaIntro:
///   RenderGrid() di sini membuat blok baru dalam keadaan AKTIF. Itu aman, karena
///   IntroRoutine() punya jaring pengaman yang mematikan SEMUA blok sekaligus
///   sebelum tiruan pertama diluncurkan - jadi tabung tetap mulai KOSONG.
/// </summary>
public class KubikaStartLayout : MonoBehaviour
{
    // ================= TOMBOL PENYETEL =================

    /// <summary>Tinggi maksimum taburan, dihitung dari dasar tabung.</summary>
    const int FOUNDATION_ROWS = 4;

    /// <summary>Ambang kepadatan di baris PALING BAWAH (0..1). Makin besar makin padat.</summary>
    const float BASE_DENSITY = 0.80f;

    /// <summary>Ambang kepadatan di baris fondasi PALING ATAS. Jaga tetap kecil.</summary>
    const float TOP_DENSITY = 0.16f;

    /// <summary>Goyangan acak pada tepi massa. 0 = tepi mulus, 0.2 = compang-camping.</summary>
    const float EDGE_JITTER = 0.10f;

    /// <summary>Berapa kantong kosong yang dilubangi di dalam massa.</summary>
    const int POCKET_MIN = 2;
    const int POCKET_MAX = 4;

    /// <summary>Berapa butiran melayang yang ditaruh di atas massa utama.</summary>
    const int SPRINKLE_MIN = 2;
    const int SPRINKLE_MAX = 4;

    /// <summary>Peluang satu sel memakai warna acak, sebagai bumbu di antara bercak.</summary>
    const float SPECK_CHANCE = 0.08f;

    /// <summary>
    /// Seberapa kuat tray PEMBUKA dibias agar memuat potongan yang bisa meng-clear
    /// (0 = acak murni, 1 = selalu diusahakan). Hanya dipakai sekali saat papan
    /// dibuat; sesudahnya nilai dari scene dipulihkan.
    /// </summary>
    const float OPENING_CLEAR_BIAS = 0.9f;

    /// <summary>
    /// Maksimum sel yang boleh DITAMBAHKAN demi menjamin clear di langkah pertama.
    /// Kecilkan kalau papan mulai terasa "ditanam"; besarkan kalau clear pembuka
    /// terlalu jarang terjadi.
    /// </summary>
    const int ADAPT_MAX_FILL = 5;

    BlastGame _game;
    BlastCore _lastCore;

    // Fase gelombang, diundi ulang tiap ronde supaya bentuk & bercak warna
    // selalu berbeda walau rumusnya sama.
    readonly float[] _ph = new float[5];

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

        // Hormati setelan scene: kalau pemilik scene memang mau papan kosong atau
        // sedang memakai demoFill, jangan ikut campur.
        if (!_game.startWithBlocks || _game.demoFill) return;
        if (core.GameOver) return;

        int cols = _game.columns;
        int h = _game.height;
        int colors = Mathf.Max(1, _game.numColors);
        if (cols <= 2 || h <= 3) return;

        int rows = Mathf.Clamp(FOUNDATION_ROWS, 1, h - 2);

        for (int i = 0; i < _ph.Length; i++) _ph[i] = Random.Range(0f, Mathf.PI * 2f);

        // ===== 1. Kosongkan papan (buang hasil acak StartingFill) =====
        for (int c = 0; c < cols; c++)
            for (int r = 0; r < h; r++)
                core.Grid[c, r] = -1;

        // ===== 2. Taburan organik =====
        Scatter(core, cols, h, rows, colors);

        // ===== 3. Jaring pengaman anti auto-clear =====
        // Papan tidak boleh punya cincin/kolom penuh sebelum disentuh pemain.
        BreakFullLines(core, cols, h);

        // ===== 4. Tray pembuka =====
        // WAJIB: tray lama dipahat dari papan acak yang baru saja kita buang, jadi
        // potongannya bisa tidak muat sama sekali (mati instan). Sekalian dibias
        // kuat supaya cenderung memuat potongan yang bisa langsung meng-clear.
        core.ClearBias = Mathf.Clamp01(OPENING_CLEAR_BIAS);
        core.RegenerateTray();
        // Pulihkan ke nilai scene. Dibaca dari _game.clearBias (bukan dari core)
        // supaya tidak bergantung pada ada-tidaknya getter di BlastCore.
        core.ClearBias = Mathf.Clamp01(_game.clearBias);

        // ===== 5. Cocokkan papan ke potongan yang benar-benar dipegang pemain =====
        if (!HasImmediateClear(core, cols, h))
            AdaptToTray(core, cols, h, rows, colors);

        // ===== 6. Anti mati-instan =====
        int guard = 0;
        int maxSteps = cols * rows + 1;
        while (!AnyTrayFits(core) && guard++ < maxSteps)
            core.Grid[Random.Range(0, cols), Random.Range(0, rows)] = -1;

        // ===== 7. Gambar ulang =====
        _game.RenderGrid();
    }

    // ================= TABURAN =================

    void Scatter(BlastCore core, int cols, int h, int rows, int colors)
    {
        // 2a. Massa utama: ambang kepadatan turun makin ke atas, jadi terbentuk
        //     siluet berombak yang berat di dasar.
        for (int r = 0; r < rows; r++)
        {
            float t = (rows <= 1) ? 0f : r / (float)(rows - 1);
            float density = Mathf.Lerp(BASE_DENSITY, TOP_DENSITY, t);

            for (int c = 0; c < cols; c++)
            {
                float n = Ridge(c, cols, r) + Random.Range(-EDGE_JITTER, EDGE_JITTER);
                if (n < density) core.Grid[c, r] = Tint(c, cols, r, colors);
            }
        }

        // 2b. Kantong kosong di dalam massa - bikin papan bernapas dan sekaligus
        //     memastikan baris dasar tidak pernah rapat total.
        int pockets = Random.Range(POCKET_MIN, POCKET_MAX + 1);
        for (int i = 0; i < pockets; i++)
            core.Grid[Random.Range(0, cols), Random.Range(0, rows)] = -1;

        // 2c. Butiran melayang di atas massa. Tanpa gravity ini sah, dan justru
        //     yang bikin papan terasa DITABUR bukan digambar.
        int sprinkle = Random.Range(SPRINKLE_MIN, SPRINKLE_MAX + 1);
        int top = Mathf.Min(rows + 2, h);
        for (int i = 0; i < sprinkle; i++)
        {
            int c = Random.Range(0, cols);
            int r = Random.Range(rows, top);
            if (r >= 0 && r < h && core.Grid[c, r] < 0)
                core.Grid[c, r] = Tint(c, cols, r, colors);
        }
    }

    /// <summary>
    /// Medan kebisingan halus yang PERIODIK mengelilingi tabung (kolom terakhir
    /// nyambung ke kolom 0, jadi tidak ada jahitan yang kelihatan). Jumlah tiga
    /// gelombang sinus dengan frekuensi berbeda - murah, dan cukup untuk membuat
    /// gumpalan yang menyambung alih-alih bintik acak.
    /// </summary>
    float Ridge(int c, int cols, int r)
    {
        float a = (c / (float)cols) * Mathf.PI * 2f;
        float n = 0.5f;
        n += 0.26f * Mathf.Sin(a + _ph[0] + r * 0.42f);
        n += 0.16f * Mathf.Sin(a * 2f + _ph[1] - r * 0.31f);
        n += 0.09f * Mathf.Sin(a * 3f + _ph[2] + r * 0.67f);
        return n;
    }

    /// <summary>
    /// Warna diambil dari medan halus KEDUA, bukan diundi per sel. Sel bertetangga
    /// jadi cenderung sewarna sehingga terbentuk bercak yang berpilin mengelilingi
    /// tabung. SPECK_CHANCE menyisipkan sedikit warna nyasar sebagai bumbu.
    /// </summary>
    int Tint(int c, int cols, int r, int colors)
    {
        if (colors <= 1) return 0;
        if (Random.value < SPECK_CHANCE) return Random.Range(0, colors);

        float a = (c / (float)cols) * Mathf.PI * 2f;
        float v = 0.5f
                + 0.34f * Mathf.Sin(a + _ph[3] + r * 0.30f)
                + 0.16f * Mathf.Sin(a * 2f + _ph[4] - r * 0.55f);

        int idx = Mathf.FloorToInt(Mathf.Clamp01(v) * colors);
        return Mathf.Clamp(idx, 0, colors - 1);
    }

    // ================= PENYESUAIAN KE TRAY =================

    /// <summary>
    /// Adakah SATU penempatan sah dari tray yang langsung melengkapi cincin/kolom?
    /// </summary>
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
    /// Simulasi di grid salinan: kalau potongan ini ditaruh di (col,row), apakah
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
    /// yang paling MURAH - artinya cincin itu tinggal kurang beberapa sel saja -
    /// lalu sisanya diisi supaya potongan tersebut menutupnya persis. Cincin yang
    /// lebih rendah dimenangkan saat seri, karena clear di dasar paling terasa.
    /// </summary>
    void AdaptToTray(BlastCore core, int cols, int h, int rows, int colors)
    {
        if (core.Tray == null) return;

        int bestScore = int.MaxValue;
        BlastCore.Piece bestPiece = null;
        int bestCol = 0, bestRow = 0, bestRing = -1;

        int rMax = Mathf.Min(rows + 1, h);

        foreach (var p in core.Tray)
        {
            if (p == null || p.Used) continue;

            for (int r0 = 0; r0 < rMax; r0++)
                for (int c0 = 0; c0 < cols; c0++)
                {
                    if (!core.CanPlace(p, c0, r0)) continue;

                    foreach (var cell in p.Cells)
                    {
                        int ring = r0 + cell.y;
                        if (ring < 0 || ring >= h) continue;

                        int cost = 0;
                        for (int c = 0; c < cols; c++)
                        {
                            if (core.Grid[c, ring] >= 0) continue;
                            if (Covers(core, p, c0, r0, c, ring)) continue;
                            cost++;
                        }
                        if (cost > ADAPT_MAX_FILL) continue;

                        // cost yang menentukan; ring dipakai sebagai pemecah seri.
                        int score = cost * 100 + ring;
                        if (score < bestScore)
                        {
                            bestScore = score;
                            bestPiece = p;
                            bestCol = c0; bestRow = r0; bestRing = ring;
                        }
                    }
                }
        }

        // Tidak ada kandidat yang cukup murah: biarkan saja. Tray sudah dibias 0.9,
        // memaksa isi banyak sel justru akan merusak tampilan taburannya.
        if (bestPiece == null || bestRing < 0) return;

        for (int c = 0; c < cols; c++)
        {
            if (core.Grid[c, bestRing] >= 0) continue;
            if (Covers(core, bestPiece, bestCol, bestRow, c, bestRing)) continue;
            core.Grid[c, bestRing] = Tint(c, cols, bestRing, colors);
        }

        // Secara teori mengisi cincin bisa melengkapi sebuah KOLOM. Kalau itu
        // terjadi, lubangi kolomnya di baris SELAIN bestRing supaya jaminan tadi
        // tidak ikut rusak.
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
