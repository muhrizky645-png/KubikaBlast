using System.Collections.Generic;

namespace KubikaBlast
{
    /// <summary>
    /// Kumpulan bentuk potongan KUBIKA BLAST — bentuk ORIGINAL (poligon buatan sendiri,
    /// BUKAN tetromino Tetris murni), disusun per-tier kesulitan.
    /// Koordinat (x = kolom mengelilingi tabung, y = tinggi). Potongan TIDAK diputar.
    /// Anchor selalu mulai dari (0,0).
    /// </summary>
    public static class Shapes
    {
        // ---- Tier 0: santai (level awal) ----
        public static readonly (int x, int y)[][] Tier0 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (0,0) },                                   // Titik
            new (int x, int y)[] { (0,0),(1,0) },                             // Duo mendatar
            new (int x, int y)[] { (0,0),(0,1) },                             // Duo menegak
            new (int x, int y)[] { (0,0),(1,0),(0,1) },                       // Sudut kecil
            new (int x, int y)[] { (0,0),(1,0),(2,0) },                       // Trio mendatar
            new (int x, int y)[] { (0,0),(1,0),(0,1),(1,1) },                 // Kotak 2x2
        };

        // ---- Tier 1: sedang ----
        public static readonly (int x, int y)[][] Tier1 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (0,0),(0,1),(0,2) },                       // Trio menegak
            new (int x, int y)[] { (0,0),(0,1),(0,2),(1,0) },                 // Kait bawah
            new (int x, int y)[] { (0,0),(0,1),(0,2),(1,2) },                 // Kait atas
            new (int x, int y)[] { (0,0),(1,0),(2,0),(1,1) },                 // Mahkota
            new (int x, int y)[] { (0,0),(1,0),(1,1),(2,1) },                 // Tangga naik
            new (int x, int y)[] { (1,0),(2,0),(0,1),(1,1) },                 // Tangga turun
            new (int x, int y)[] { (0,0),(1,0),(2,0),(3,0) },                 // Kuartet mendatar
        };

        // ---- Tier 2: sulit ----
        public static readonly (int x, int y)[][] Tier2 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (1,0),(0,1),(1,1),(2,1),(1,2) },           // Bintang plus
            new (int x, int y)[] { (0,0),(1,0),(2,0),(0,1),(1,1),(2,1) },     // Bata 3x2
            new (int x, int y)[] { (0,0),(2,0),(0,1),(1,1),(2,1) },           // Gawang U
            new (int x, int y)[] { (0,0),(1,0),(1,1),(2,1),(2,2) },           // Zigzag panjang
            new (int x, int y)[] { (0,0),(0,1),(0,2),(1,2),(2,2) },           // Siku besar
            new (int x, int y)[] { (0,0),(1,0),(2,0),(3,0),(4,0) },           // Kuintet mendatar
        };

        // ---- Tier 3: aneh & menantang (level tinggi) ----
        public static readonly (int x, int y)[][] Tier3 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (0,0),(1,1),(2,2),(3,3) },                 // Anak tangga diagonal
            new (int x, int y)[] { (0,0),(1,0),(2,0),(3,0),(1,1),(2,1) },     // Meja lebar
            new (int x, int y)[] { (0,0),(0,1),(1,1),(1,2),(2,2),(2,3) },     // Ular menanjak
            new (int x, int y)[] { (0,0),(0,1),(0,2),(1,1),(2,0),(2,1),(2,2) },// Huruf H
            new (int x, int y)[] { (0,0),(0,1),(1,1),(1,2),(2,2) },           // Angin (W)
            new (int x, int y)[] { (1,0),(0,1),(1,1),(2,1),(1,2),(1,3) },     // Salib panjang
        };

        // Semua bentuk digabung (kompatibilitas mundur untuk kode/tes lama).
        public static readonly (int x, int y)[][] All = BuildAll();

        static (int x, int y)[][] BuildAll()
        {
            var list = new List<(int x, int y)[]>();
            list.AddRange(Tier0);
            list.AddRange(Tier1);
            list.AddRange(Tier2);
            list.AddRange(Tier3);
            return list.ToArray();
        }

        /// <summary>
        /// Kolam bentuk sesuai level. Makin tinggi level, makin besar & aneh bentuknya,
        /// tapi tetap menyertakan sebagian bentuk mudah agar nyaman dimainkan.
        /// </summary>
        public static (int x, int y)[][] PoolForLevel(int level)
        {
            var pool = new List<(int x, int y)[]>();
            if (level <= 2)
            {
                pool.AddRange(Tier0);
            }
            else if (level <= 4)
            {
                pool.AddRange(Tier0);
                pool.AddRange(Tier1);
            }
            else if (level <= 6)
            {
                pool.AddRange(Tier1);
                pool.AddRange(Tier2);
            }
            else
            {
                pool.AddRange(Tier2);
                pool.AddRange(Tier3);
                // sedikit bentuk sedang biar tetap ada napas
                pool.Add(Tier1[0]);
                pool.Add(Tier1[3]);
            }
            return pool.ToArray();
        }
    }
}
