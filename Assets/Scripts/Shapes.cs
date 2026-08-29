using System;
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
    /// </summary>
    public static class Shapes
    {
        // ============ BENTUK DASAR (orientasi kanonik) ============
        // Tiap bentuk dasar nanti diperluas menjadi SEMUA rotasi uniknya.

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
            new (int x, int y)[] { (0,0),(1,0),(1,1),(1,2),(2,1) },     // Zigzag-S (12586)
            new (int x, int y)[] { (0,0),(1,0),(0,1),(0,2),(1,2) },     // U-kecil (78412)
            new (int x, int y)[] { (0,0),(0,1),(1,1),(1,2),(2,2) },     // W / Tangga (89451)
            new (int x, int y)[] { (0,0),(0,1),(1,1),(2,1),(2,2) },     // Petir Z-5 (94561)
        };

        // ---- Tier 3: bentuk besar (6-9 sel) yang muat 3x3 ----
        static readonly (int x, int y)[][] Base3 = new (int x, int y)[][]
        {
            new (int x, int y)[] { (0,0),(1,0),(0,1),(1,1),(0,2),(1,2) },                       // Persegi 2x3
            new (int x, int y)[] { (0,0),(1,0),(2,0),(0,1),(2,1),(0,2),(1,2),(2,2) },           // Gawang O (ring 3x3)
            new (int x, int y)[] { (0,0),(1,0),(2,0),(0,1),(1,1),(2,1),(0,2),(1,2),(2,2) },     // Kotak besar 3x3
            new (int x, int y)[] { (1,0),(0,1),(1,1),(2,1),(1,2),(2,2) },           // Panah (425896)
            new (int x, int y)[] { (0,0),(1,0),(0,1),(1,1),(2,1),(1,2),(2,2) },     // Kristal (8965412)
            new (int x, int y)[] { (0,0),(1,0),(2,0),(1,1),(0,2),(1,2),(2,2) },     // I-beam / Tulang (7895123)
            new (int x, int y)[] { (0,0),(2,0),(0,1),(1,1),(2,1),(1,2) },           // Robot (845613)
            new (int x, int y)[] { (0,0),(1,0),(2,0),(0,1),(0,2),(1,2),(2,2) },     // Kurung-C (7894123)
        };

        // ============ POOL HASIL PERLUASAN ROTASI (dibangun sekali) ============
        public static readonly (int x, int y)[][] Tier0 = ExpandAll(Base0);
        public static readonly (int x, int y)[][] Tier1 = ExpandAll(Base1);
        public static readonly (int x, int y)[][] Tier2 = ExpandAll(Base2);
        public static readonly (int x, int y)[][] Tier3 = ExpandAll(Base3);

        // Semua bentuk digabung (kompatibilitas mundur).
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

        // ============ ROTASI OTOMATIS ============

        // Perluas kumpulan bentuk dasar menjadi semua rotasi uniknya (dedupe global).
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

        // Hasilkan hingga 4 rotasi (0/90/180/270), sudah dinormalkan, tanpa kembar.
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

        // Putar 90 derajat: (x,y) -> (y,-x), lalu dinormalkan ke (0,0).
        static (int x, int y)[] Rotate90((int x, int y)[] shape)
        {
            var res = new (int x, int y)[shape.Length];
            for (int i = 0; i < shape.Length; i++)
                res[i] = (shape[i].y, -shape[i].x);
            return res;
        }

        // Geser supaya min x = 0 dan min y = 0.
        static (int x, int y)[] Normalize((int x, int y)[] shape)
        {
            int minX = int.MaxValue, minY = int.MaxValue;
            foreach (var (x, y) in shape) { if (x < minX) minX = x; if (y < minY) minY = y; }
            var res = new (int x, int y)[shape.Length];
            for (int i = 0; i < shape.Length; i++)
                res[i] = (shape[i].x - minX, shape[i].y - minY);
            return res;
        }

        // Kunci kanonik untuk dedupe (sel diurutkan stabil).
        static string Key((int x, int y)[] shape)
        {
            var pts = new List<(int x, int y)>(shape);
            pts.Sort((a, b) => a.y != b.y ? a.y - b.y : a.x - b.x);
            var sb = new StringBuilder();
            foreach (var (x, y) in pts) { sb.Append(x); sb.Append(','); sb.Append(y); sb.Append(';'); }
            return sb.ToString();
        }

        // ============ KOLAM BENTUK PER LEVEL ============
        /// <summary>
        /// Kolam bentuk sesuai level. Semua bentuk (dan seluruh rotasinya) tersedia;
        /// makin tinggi level, makin banyak bentuk besar yang ikut muncul.
        /// </summary>
        public static (int x, int y)[][] PoolForLevel(int level)
        {
            var pool = new List<(int x, int y)[]>();
            pool.AddRange(Tier0);
            pool.AddRange(Tier1);
            if (level >= 3) pool.AddRange(Tier2);
            if (level >= 5) pool.AddRange(Tier3);
            return pool.ToArray();
        }
    }
}
