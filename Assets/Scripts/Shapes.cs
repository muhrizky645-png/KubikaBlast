namespace KubikaBlast
{
    /// <summary>
    /// Daftar bentuk potongan Kubika Blast.
    /// x = kolom (keliling tabung), y = baris (tinggi).
    /// Potongan TIDAK diputar — ditaruh apa adanya.
    /// </summary>
    public static class Shapes
    {
        public static readonly (int x, int y)[][] All =
        {
            new (int, int)[]{ (0,0) },                                   // 0  Single
            new (int, int)[]{ (0,0),(1,0) },                             // 1  Domino H
            new (int, int)[]{ (0,0),(0,1) },                             // 2  Domino V
            new (int, int)[]{ (0,0),(1,0),(2,0) },                       // 3  Garis-3 H
            new (int, int)[]{ (0,0),(0,1),(0,2) },                       // 4  Garis-3 V
            new (int, int)[]{ (0,0),(1,0),(0,1) },                       // 5  L kecil
            new (int, int)[]{ (0,0),(1,0),(1,1) },                       // 6  L kecil cermin
            new (int, int)[]{ (0,0),(1,0),(0,1),(1,1) },                 // 7  Kotak 2x2
            new (int, int)[]{ (0,0),(1,0),(2,0),(3,0) },                 // 8  Garis-4 H
            new (int, int)[]{ (0,0),(0,1),(0,2),(0,3) },                 // 9  Garis-4 V
            new (int, int)[]{ (0,0),(1,0),(2,0),(1,1) },                 // 10 T
            new (int, int)[]{ (0,0),(1,0),(2,0),(0,1),(1,1),(2,1) },     // 11 Kotak 3x2
        };
    }
}