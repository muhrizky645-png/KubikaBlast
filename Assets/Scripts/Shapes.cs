using System.Collections.Generic;
using System.Text;

namespace KubikaBlast
{
    /// <summary>
    /// Kumpulan bentuk potongan KUBIKA BLAST — gaya BLOCK BLAST.
    /// Semua bentuk DASAR muat dalam kotak 3x3 (plus satu garis panjang 4 kotak).
    /// Saat dibuat, tiap bentuk dasar OTOMATIS diputar (0/90/180/270 derajat) dan
    /// varian yang kembar dibuang — jadi orientasi TIDAK lagi fix (auto-rotate).
    /// Koordinat (x = kolom mengelilingi tabung, y = tinggi). Anchor dinormalkan ke (0,0).
    ///
    /// KURVA KESULITAN (diperbaiki):
    ///   Dulu Tier2 masuk di level 3 dan Tier3 di level 5, sementara Level dihitung
    ///   dari SKOR (Score/1000). Satu combo bagus bisa melompatkan level beberapa
    ///   tingkat sekaligus, lalu tiba-tiba muncul kotak PADAT 3x3 (9 sel) di papan
    ///   12x10 yang sudah setengah penuh => game over instan.
    ///   Sekarang:
    ///     - Level dihitung dari LinesCleared (lihat BlastCore), bukan skor.
    ///     - Tier2 baru muncul di level 4, Tier3 di level 8.
    ///     - Kotak PADAT 3x3 dan ring 3x3 dipindah ke Tier3Heavy dan TIDAK PERNAH
    ///       ikut ke kolam normal. Dua bentuk itu praktis mustahil ditempatkan.
    /// </summary>
    public static class Shapes
    {
        // ============ BENTUK DASAR (orientasi kanonik) ============

        // ---- Tier 0: kecil & santai ----
        static readonly (int x, int y)[][] Base0 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (0,0) },                              // Titik (1x1)
            new (int x, int y)[] { (0,0),(1,0) },                        // Duo (auto H/V)
            new (int x, int y)[] { (0,0),(1,0),(2,0) },                  // Trio garis
            new (int x, int y)[] { (0,0),(1,0),(0,1) },                  // Sudut kecil (L-3)
            new (int x, int y)[] { (0,0),(1,0),(0,1),(1,1) },            // Kotak 2x2
        };

        // ---- Tier 1: tetromino ala Block Blast + garis 4 ----
        static readonly (int x, int y)[][] Base1 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (0,0),(1,0),(2,0),(3,0) },           // Garis 4 (I) - auto H/V
            new (int x, int y)[] { (0,0),(0,1),(0,2),(1,0) },           // L
            new (int x, int y)[] { (0,0),(0,1),(0,2),(1,2) },           // J (kiralitas beda)
            new (int x, int y)[] { (0,0),(1,0),(2,0),(1,1) },           // T
            new (int x, int y)[] { (0,0),(1,0),(1,1),(2,1) },           // S
            new (int x, int y)[] { (1,0),(2,0),(0,1),(1,1) },           // Z
        };

        // ---- Tier 2: pentomino yang muat 3x3 ----
        static readonly (int x, int y)[][] Base2 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (1,0),(0,1),(1,1),(2,1),(1,2) },     // Plus (+)
            new (int x, int y)[] { (0,0),(1,0),(2,0),(0,1),(0,2) },     // Siku besar (V / L-5)
            new (int x, int y)[] { (0,0),(1,0),(2,0),(1,1),(1,2) },     // T besar (T-5)
            new (int x, int y)[] { (0,0),(1,0),(0,1),(1,1),(0,2) },     // P (gemuk-5)
            new (int x, int y)[] { (0,0),(1,0),(1,1),(1,2),(2,1) },     // Zigzag-S
            new (int x, int y)[] { (0,0),(1,0),(0,1),(0,2),(1,2) },     // U-kecil
            new (int x, int y)[] { (0,0),(0,1),(1,1),(1,2),(2,2) },     // W / Tangga
            new (int x, int y)[] { (0,0),(0,1),(1,1),(2,1),(2,2) },     // Petir Z-5
        };

        // ---- Tier 3: bentuk besar (6-7 sel) yang masih WAJAR di papan 12x10 ----
        static readonly (int x, int y)[][] Base3 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (0,0),(1,0),(0,1),(1,1),(0,2),(1,2) },           // Persegi 2x3
            new (int x, int y)[] { (1,0),(0,1),(1,1),(2,1),(1,2),(2,2) },           // Panah
            new (int x, int y)[] { (0,0),(1,0),(0,1),(1,1),(2,1),(1,2),(2,2) },     // Kristal
            new (int x, int y)[] { (0,0),(1,0),(2,0),(1,1),(0,2),(1,2),(2,2) },     // I-beam / Tulang
            new (int x, int y)[] { (0,0),(2,0),(0,1),(1,1),(2,1),(1,2) },           // Robot
            new (int x, int y)[] { (0,0),(1,0),(2,0),(0,1),(0,2),(1,2),(2,2) },     // Kurung-C
        };

        // ---- Tier 3 BERAT: 8-9 sel. TIDAK dipakai di kolam normal. ----
        // Kotak padat 3x3 butuh 9 sel kosong bersebelahan; ring 3x3 butuh 8 sel
        // dengan lubang tepat di tengah. Di papan 12x10 yang sudah terisi, dua
        // bentuk ini hampir selalu berarti game over instan. Disimpan hanya untuk
        // kompatibilitas / mode tantangan di masa depan.
        static readonly (int x, int y)[][] Base3Heavy = new (int x, int y)[][]
        {
            new (int x, int y)[] { (0,0),(1,0),(2,0),(0,1),(2,1),(0,2),(1,2),(2,2) },       // Ring 3x3 (8)
            new (int x, int y)[] { (0,0),(1,0),(2,0),(0,1),(1,1),(2,1),(0,2),(1,2),(2,2) }, // Kotak padat 3x3 (9)
        };

        // ============ POOL HASIL PERLUASAN ROTASI (dibangun sekali) ============
        public static readonly (int x, int y)[][] Tier0 = ExpandAll(Base0);
        public static readonly (int x, int y)[][] Tier1 = ExpandAll(Base1);
        public static readonly (int x, int y)[][] Tier2 = ExpandAll(Base2);
        public static readonly (int x, int y)[][] Tier3 = ExpandAll(Base3);
        public static readonly (int x, int y)[][] Tier3Heavy = ExpandAll(Base3Heavy);

        // Semua bentuk digabung (kompatibilitas mundur).
        public static readonly (int x, int y)[][] All = BuildAll();

        static (int x, int y)[][] BuildAll()
        {
            var list = new List<(int x, int y)[]>();
            list.AddRange(Tier0);
            list.AddRange(Tier1);
            list.AddRange(Tier2);
            list.AddRange(Tier3);
            list.AddRange(Tier3Heavy);
            return list.ToArray();
        }

        // ============ ROTASI OTOMATIS ============

        static (int x, int y)[][] ExpandAll((int x, int y)[][] bases)
        {
            var result = new List<(int x, int y)[]>();
            var seen = new HashSet<string>();
            foreach (var shape in bases)
                foreach (var rot in Rotations(shape))
                    if (seen.Add(Key(rot)))
                        result.Add(rot);
            return result.ToArray();
        }

        static List<(int x, int y)[]> Rotations((int x, int y)[] shape)
        {
            var outp = new List<(int x, int y)[]>();
            var seen = new HashSet<string>();
            var cur = Normalize(shape);
            for (int i = 0; i < 4; i++)
            {
                string k = Key(cur);
                if (seen.Add(k)) outp.Add(cur);
                cur = Normalize(Rotate90(cur));
            }
            return outp;
        }

        static (int x, int y)[] Rotate90((int x, int y)[] shape)
        {
            var res = new (int x, int y)[shape.Length];
            for (int i = 0; i < shape.Length; i++)
                res[i] = (shape[i].y, -shape[i].x);
            return res;
        }

        static (int x, int y)[] Normalize((int x, int y)[] shape)
        {
            int minX = int.MaxValue, minY = int.MaxValue;
            foreach (var (x, y) in shape) { if (x < minX) minX = x; if (y < minY) minY = y; }
            var res = new (int x, int y)[shape.Length];
            for (int i = 0; i < shape.Length; i++)
                res[i] = (shape[i].x - minX, shape[i].y - minY);
            return res;
        }

        static string Key((int x, int y)[] shape)
        {
            var pts = new List<(int x, int y)>(shape);
            pts.Sort((a, b) => a.y != b.y ? a.y - b.y : a.x - b.x);
            var sb = new StringBuilder();
            foreach (var (x, y) in pts) { sb.Append(x); sb.Append(','); sb.Append(y); sb.Append(';'); }
            return sb.ToString();
        }

        // ============ KOLAM BENTUK PER LEVEL ============

        /// <summary>Level pertama yang memunculkan pentomino (5 sel).</summary>
        public const int TIER2_LEVEL = 4;
        /// <summary>Level pertama yang memunculkan bentuk besar (6-7 sel).</summary>
        public const int TIER3_LEVEL = 8;

        /// <summary>
        /// Kolam bentuk sesuai level. Makin tinggi level, makin banyak bentuk besar
        /// yang ikut muncul — tapi bentuk BERAT (8-9 sel) tidak pernah masuk.
        /// </summary>
        public static (int x, int y)[][] PoolForLevel(int level)
        {
            var pool = new List<(int x, int y)[]>();
            pool.AddRange(Tier0);
            pool.AddRange(Tier1);
            if (level >= TIER2_LEVEL) pool.AddRange(Tier2);
            if (level >= TIER3_LEVEL) pool.AddRange(Tier3);
            return pool.ToArray();
        }
    }
}
