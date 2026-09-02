using UnityEngine;
using KubikaBlast;

/// <summary>
/// SUSUNAN PAPAN AWAL (rintangan pembuka) gaya Block Blast.
///
/// MASALAHNYA DULU:
///   BlastGame.StartingFill() mengisi papan secara ACAK (pattern = rng.Next(7),
///   kepadatan startFillChance = 0.45). Hasilnya dua hal yang mengganggu:
///     1. Terlihat berantakan -- tidak ada bentuk yang bisa dibaca mata.
///     2. TIDAK ada jaminan pemain bisa menghancurkan sesuatu di langkah awal,
///        padahal justru di situ kepuasan Block Blast berasal.
///
/// YANG DILAKUKAN SCRIPT INI:
///   Menimpa susunan acak itu dengan FONDASI RAPI berbentuk corong:
///     baris 0 : penuh, KECUALI 1 lubang        -> satu potongan = ring hancur
///     baris 1 : penuh, KECUALI 2 lubang
///     baris 2 : penuh, KECUALI 4 lubang
///   Semua lubang dipusatkan di kolom yang sama, jadi bentuknya corong yang
///   melebar ke atas -- simetris, enak dilihat, dan langsung "mengundang"
///   pemain menjatuhkan potongan ke dalamnya.
///
///   Tiap baris diberi SATU warna (pita warna bertumpuk) supaya terasa disusun
///   sengaja, bukan ditabur. Titik corong dan pergeseran warna diacak tiap ronde
///   supaya tetap ada variasi.
///
/// KENAPA FILE TERPISAH (BUKAN MENGEDIT BlastGame.cs):
///   BlastGame.cs sudah 33 KB -- jauh di atas batas aman push kita dan satu-satunya
///   file yang pernah terpotong diam-diam. Ternyata semua yang kita butuh SUDAH
///   publik: Core.Grid, Core.Wrap, Core.RegenerateTray, Core.CanPlaceAnywhere,
///   Core.ClearBias, dan RenderGrid(). Jadi StartingFill() bawaan dibiarkan jalan
///   apa adanya, lalu hasilnya kita timpa dari luar. NOL perubahan di file besar.
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
///   sebelum tiruan pertama diluncurkan -- jadi tabung tetap mulai KOSONG.
/// </summary>
public class KubikaStartLayout : MonoBehaviour
{
    // ================= TOMBOL PENYETEL =================

    /// <summary>
    /// Jumlah LUBANG di tiap baris fondasi, dari bawah ke atas.
    /// Panjang array = tinggi fondasi. Angka pertama sengaja 1 supaya langkah
    /// pertama bisa langsung menghancurkan satu ring penuh.
    /// Mau papan lebih lega? Pendekkan jadi { 1, 3 }.
    /// Mau lebih menantang? { 1, 2, 3, 5 }.
    /// </summary>
    static readonly int[] GAPS_PER_ROW = { 1, 2, 4 };

    /// <summary>
    /// Seberapa kuat tray PEMBUKA dibias agar memuat potongan yang menutup lubang
    /// (0 = acak murni, 1 = selalu diusahakan bisa menghancurkan). Hanya dipakai
    /// sekali saat papan dibuat; sesudahnya nilai dari scene dipulihkan.
    /// </summary>
    const float OPENING_CLEAR_BIAS = 0.9f;

    BlastGame _game;
    BlastCore _lastCore;

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
        if (cols <= 2 || h <= 2) return;

        // ===== 1. Kosongkan papan (buang hasil acak StartingFill) =====
        for (int c = 0; c < cols; c++)
            for (int r = 0; r < h; r++)
                core.Grid[c, r] = -1;

        // ===== 2. Fondasi rapi berbentuk corong =====
        int mouth = Random.Range(0, cols);      // titik corong, acak tiap ronde
        int tint = Random.Range(0, colors);     // pergeseran warna, biar tiap ronde beda
        int rows = Mathf.Clamp(GAPS_PER_ROW.Length, 1, h - 1);

        for (int r = 0; r < rows; r++)
        {
            // Selalu sisakan minimal 1 lubang: baris penuh akan hancur sendiri
            // sebelum pemain menyentuh apa pun.
            int gaps = Mathf.Clamp(GAPS_PER_ROW[r], 1, cols - 1);
            int color = (r + tint) % colors;

            // Isi penuh dulu, lalu lubangi. Lebih mudah dibaca daripada menghitung
            // sel mana saja yang boleh diisi.
            for (int c = 0; c < cols; c++) core.Grid[c, r] = color;

            // Lubang dipusatkan di sekitar 'mouth' supaya corongnya simetris.
            int from = -(gaps - 1) / 2;
            for (int k = 0; k < gaps; k++)
                core.Grid[core.Wrap(mouth + from + k), r] = -1;
        }

        // ===== 3. Jaring pengaman anti auto-clear =====
        // Sesuai konstruksi di atas ini mustahil terjadi, tapi kalau nanti
        // GAPS_PER_ROW diubah sembarangan, papan tidak boleh hancur sendiri.
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

        // ===== 4. Tray pembuka =====
        // WAJIB: tray lama dicetak dari papan acak yang baru saja kita buang, jadi
        // potongannya bisa tidak muat sama sekali (mati instan). Sekalian kita bias
        // kuat supaya ada potongan yang pas menutup lubang -> hancur di langkah 1.
        core.ClearBias = Mathf.Clamp01(OPENING_CLEAR_BIAS);
        core.RegenerateTray();
        // Pulihkan ke nilai scene. Dibaca dari _game.clearBias (bukan dari core)
        // supaya tidak bergantung pada ada-tidaknya getter di BlastCore.
        core.ClearBias = Mathf.Clamp01(_game.clearBias);

        // ===== 5. Anti mati-instan =====
        int guard = 0;
        int maxSteps = cols * rows + 1;
        while (!AnyTrayFits(core) && guard++ < maxSteps)
            core.Grid[Random.Range(0, cols), Random.Range(0, rows)] = -1;

        // ===== 6. Gambar ulang =====
        _game.RenderGrid();
    }

    static bool AnyTrayFits(BlastCore core)
    {
        if (core == null || core.Tray == null) return true;
        foreach (var p in core.Tray)
            if (p != null && !p.Used && core.CanPlaceAnywhere(p)) return true;
        return false;
    }
}
