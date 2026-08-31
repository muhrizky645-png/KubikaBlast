using System;
using System.Collections.Generic;
using System.Text;

namespace KubikaBlast
{
    /// <summary>
    /// Logika inti KUBIKA BLAST — MURNI C# (tanpa dependensi Unity).
    /// Papan SILINDER: kolom membungkus (kolom terakhir nyambung ke kolom 0).
    /// Gaya Block Blast: TIDAK ada gravity, potongan TIDAK diputar.
    /// Clear terjadi saat cincin (baris) penuh ATAU kolom vertikal penuh.
    ///
    /// SUMBER KEBENARAN TUNGGAL:
    ///   Dulu ada TIGA penghitung combo yang berbeda-beda (BlastCore.Combo untuk skor,
    ///   KubikaHud._streak berbasis timer 10 detik untuk teks pujian, dan
    ///   KubikaSfx._streak berbasis timer 15 detik untuk nada). Angka yang dilihat
    ///   pemain tidak pernah sama dengan angka yang membayar. Sekarang HANYA Combo di
    ///   sini yang dipakai semua sistem (skor, permata, teks, suara).
    ///
    /// EKONOMI:
    ///   - Pengali combo DIBATASI (dulu Score += base * Combo tanpa batas, jadi combo
    ///     15 = pengali 15x dan skor meledak).
    ///   - Level dihitung dari LinesCleared, BUKAN dari Score. Dulu Level = Score/1000
    ///     sehingga satu combo besar melompatkan beberapa level sekaligus dan langsung
    ///     memunculkan bentuk raksasa => game over mendadak.
    ///   - Permata dihitung DI SINI (LastClearGems) supaya kurvanya masuk akal dan
    ///     tidak lagi "1 permata per combo" yang bikin awal game mustahil menabung.
    /// </summary>
    public class BlastCore
    {
        // ---- konfigurasi skor ----
        const int CELL_POINTS = 10;    // poin per sel saat menaruh potongan
        const int CLEAR_POINTS = 100;  // poin per baris/kolom yang di-clear
        const int TRAY_SIZE = 3;       // jumlah potongan aktif

        /// <summary>Berapa baris/kolom hancur untuk naik satu level.</summary>
        public const int LINES_PER_LEVEL = 12;

        /// <summary>Combo tertinggi yang masih menambah pengali skor.</summary>
        public const int COMBO_CAP = 8;

        /// <summary>Tambahan pengali per tingkat combo (combo 8 => 1 + 7*0.35 = 3.45x).</summary>
        public const float COMBO_STEP = 0.35f;

        public int Columns { get; private set; }
        public int Height { get; private set; }

        // Grid[c, r]: -1 = kosong; selain itu = indeks warna.
        public int[,] Grid;

        // ---- potongan di tray ----
        public class Piece
        {
            public (int x, int y)[] Cells;
            public int Color;
            public bool Used;
        }
        public Piece[] Tray = new Piece[TRAY_SIZE];

        // ---- status ----
        public bool GameOver;
        public int Score;
        public int LinesCleared;
        public int Combo;

        // ---- statistik untuk layar Game Over & HUD ----
        public int BestCombo;
        public int PiecesPlaced;
        public int CellsCleared;
        public int GemsEarned;

        // ---- hasil aksi terakhir (dibaca HUD / SFX / efek permata) ----
        public int LastClearScore;
        public int LastClearGems;
        public int LastPlaceScore;

        // 0 = potongan sepenuhnya ACAK (asal muat di papan); makin tinggi makin sering
        // sengaja memberi potongan yang bisa langsung meng-clear. Diatur dari BlastGame.
        public double ClearBias = 0.35;

        /// <summary>Level naik tiap LINES_PER_LEVEL baris/kolom hancur. Mulai dari 1.</summary>
        public int Level => Math.Max(1, LinesCleared / LINES_PER_LEVEL + 1);

        /// <summary>Berapa baris lagi menuju level berikutnya (0..LINES_PER_LEVEL).</summary>
        public int LinesIntoLevel => LinesCleared % LINES_PER_LEVEL;

        /// <summary>Pengali skor dari combo saat ini. Sudah dibatasi COMBO_CAP.</summary>
        public float ComboMultiplier => MultiplierFor(Combo);

        public static float MultiplierFor(int combo)
        {
            if (combo <= 1) return 1f;
            int steps = Math.Min(combo, COMBO_CAP) - 1;
            return 1f + COMBO_STEP * steps;
        }

        // ---- laporan clear terakhir (dibaca renderer untuk efek visual) ----
        public struct ClearInfo
        {
            public List<int> Rings;                       // baris yang di-clear
            public List<int> Cols;                        // kolom yang di-clear
            public List<(int c, int r, int color)> Cells; // sel yang hancur
            public int Combo;                             // combo saat clear ini terjadi
            public int Score;                             // skor yang diberikan clear ini
            public int Gems;                              // permata yang diberikan clear ini
            public bool FromTool;                         // true kalau dari Palu/Bom
        }
        public ClearInfo LastClear;

        readonly Random _rng;
        readonly int _numColors;

        public BlastCore(int columns, int height, int numColors = 5, int? seed = null)
        {
            _rng = seed.HasValue ? new Random(seed.Value) : new Random();
            _numColors = Math.Max(1, numColors);
            Reset(columns, height);
        }

        public void Reset(int columns, int height)
        {
            Columns = Math.Max(3, columns);
            Height = Math.Max(3, height);
            Grid = new int[Columns, Height];
            for (int c = 0; c < Columns; c++)
                for (int r = 0; r < Height; r++)
                    Grid[c, r] = -1;

            Score = 0; LinesCleared = 0; Combo = 0;
            BestCombo = 0; PiecesPlaced = 0; CellsCleared = 0; GemsEarned = 0;
            LastClearScore = 0; LastClearGems = 0; LastPlaceScore = 0;
            LastClear = EmptyClear(false);
            GameOver = false;
            RefillTray();
        }

        static ClearInfo EmptyClear(bool fromTool) => new ClearInfo
        {
            Rings = new List<int>(),
            Cols = new List<int>(),
            Cells = new List<(int c, int r, int color)>(),
            Combo = 0,
            Score = 0,
            Gems = 0,
            FromTool = fromTool,
        };

        // Kolom membungkus (silinder).
        public int Wrap(int c) { c %= Columns; if (c < 0) c += Columns; return c; }

        // ================= TRAY (SMART DROP) =================

        /// <summary>
        /// Bangun ulang seluruh tray dari kondisi papan SAAT INI. Dipanggil oleh renderer
        /// setelah starting-fill supaya potongan di-carve dari papan yang sudah terisi.
        /// </summary>
        public void RegenerateTray() { RefillTray(); }

        // "Solusi tersembunyi": tiap potongan di-carve dari celah NYATA di papan, lalu
        // slotnya DIPESAN di grid bayangan (scratch) supaya ketiga potongan dijamin muat
        // sekaligus di papan asli. Slot ini tidak ditampilkan ke pemain.
        void RefillTray()
        {
            var scratch = (int[,])Grid.Clone();
            var usedSigs = new HashSet<string>();
            for (int i = 0; i < TRAY_SIZE; i++)
                Tray[i] = GenerateSmartPiece(scratch, usedSigs);
        }

        // Tanda tangan kanonik sebuah bentuk (buat cegah bentuk kembar dalam satu tray).
        static string ShapeSig((int x, int y)[] shape)
        {
            var pts = new List<(int x, int y)>(shape);
            pts.Sort((a, b) => a.y != b.y ? a.y - b.y : a.x - b.x);
            var sb = new StringBuilder();
            foreach (var (x, y) in pts) { sb.Append(x); sb.Append(','); sb.Append(y); sb.Append(';'); }
            return sb.ToString();
        }

        // Pilih potongan: TETAP dijamin muat (di-carve dari celah nyata di papan), tapi
        // bentuknya dipilih ACAK di antara semua yang muat.
        Piece GenerateSmartPiece(int[,] scratch, HashSet<string> usedSigs)
        {
            var pool = Shapes.PoolForLevel(Level);

            var fits = new List<(int idx, int col, int row, bool clears, string sig)>();
            for (int oi = 0; oi < pool.Length; oi++)
            {
                var shape = pool[oi];
                double best = double.NegativeInfinity;
                int bcol = 0, brow = 0; bool any = false;
                for (int row = 0; row < Height; row++)
                    for (int col = 0; col < Columns; col++)
                    {
                        if (!FitsOn(scratch, shape, col, row)) continue;
                        any = true;
                        double s = ScorePlacement(scratch, shape, col, row);
                        if (s > best) { best = s; bcol = col; brow = row; }
                    }
                if (any) fits.Add((oi, bcol, brow, best >= 100.0, ShapeSig(shape)));
            }

            (int x, int y)[] chosenShape = null;
            int chosenCol = 0, chosenRow = 0;

            if (fits.Count > 0)
            {
                var bag = fits.FindAll(f => !usedSigs.Contains(f.sig));
                if (bag.Count == 0) bag = fits;

                var clearers = bag.FindAll(f => f.clears);
                var pick = (clearers.Count > 0 && _rng.NextDouble() < ClearBias)
                    ? clearers[_rng.Next(clearers.Count)]
                    : bag[_rng.Next(bag.Count)];

                chosenShape = pool[pick.idx];
                chosenCol = pick.col; chosenRow = pick.row;
                usedSigs.Add(pick.sig);
            }

            if (chosenShape == null)
            {
                for (int row = 0; row < Height && chosenShape == null; row++)
                    for (int col = 0; col < Columns && chosenShape == null; col++)
                        if (scratch[col, row] == -1)
                        {
                            chosenShape = new (int x, int y)[] { (0, 0) };
                            chosenCol = col; chosenRow = row;
                        }
            }
            if (chosenShape == null)
            {
                chosenShape = new (int x, int y)[] { (0, 0) };
                chosenCol = 0; chosenRow = 0;
            }

            int color = _rng.Next(_numColors);
            foreach (var (dx, dy) in chosenShape)
            {
                int r = chosenRow + dy;
                int c = Wrap(chosenCol + dx);
                if (r >= 0 && r < Height) scratch[c, r] = color;
            }

            var cells = new (int x, int y)[chosenShape.Length];
            Array.Copy(chosenShape, cells, chosenShape.Length);
            return new Piece { Cells = cells, Color = color, Used = false };
        }

        bool FitsOn(int[,] grid, (int x, int y)[] shape, int col, int row)
        {
            foreach (var (dx, dy) in shape)
            {
                int r = row + dy;
                int c = Wrap(col + dx);
                if (r < 0 || r >= Height) return false;
                if (grid[c, r] != -1) return false;
            }
            return true;
        }

        // Nilai kelayakan penempatan. Memakai penanda sementara -2.
        // CATATAN: pemanggil WAJIB sudah memastikan FitsOn(...) == true, karena fungsi
        // ini memulihkan sel ke -1 tanpa syarat.
        double ScorePlacement(int[,] grid, (int x, int y)[] shape, int col, int row)
        {
            var placed = new List<(int c, int r)>();
            foreach (var (dx, dy) in shape)
            {
                int r = row + dy;
                int c = Wrap(col + dx);
                if (r < 0 || r >= Height) continue;   // penjaga batas (dulu tidak ada)
                grid[c, r] = -2;
                placed.Add((c, r));
            }

            var rowsTouched = new HashSet<int>();
            var colsTouched = new HashSet<int>();
            foreach (var (c, r) in placed) { rowsTouched.Add(r); colsTouched.Add(c); }

            int completedRings = 0;
            foreach (int r in rowsTouched)
            {
                bool full = true;
                for (int c = 0; c < Columns; c++)
                    if (grid[c, r] == -1) { full = false; break; }
                if (full) completedRings++;
            }
            int completedCols = 0;
            foreach (int c in colsTouched)
            {
                bool full = true;
                for (int r = 0; r < Height; r++)
                    if (grid[c, r] == -1) { full = false; break; }
                if (full) completedCols++;
            }

            int adjacency = 0;
            int[] dc = { 1, -1, 0, 0 };
            int[] dr = { 0, 0, 1, -1 };
            foreach (var (c, r) in placed)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nc = Wrap(c + dc[k]);
                    int nr = r + dr[k];
                    if (nr < 0 || nr >= Height) { adjacency++; continue; }
                    int v = grid[nc, nr];
                    if (v != -1 && v != -2) adjacency++;
                }
            }

            foreach (var (c, r) in placed) grid[c, r] = -1;

            return (completedRings + completedCols) * 100.0 + adjacency * 2.0;
        }

        bool TrayEmpty()
        {
            foreach (var p in Tray)
                if (p != null && !p.Used) return false;
            return true;
        }

        // ================= PENEMPATAN =================

        public bool CanPlace(Piece piece, int col, int row)
        {
            if (piece == null || piece.Used) return false;
            foreach (var (dx, dy) in piece.Cells)
            {
                int r = row + dy;
                int c = Wrap(col + dx);
                if (r < 0 || r >= Height) return false;
                if (Grid[c, r] != -1) return false;
            }
            return true;
        }

        public bool CanPlaceAnywhere(Piece piece)
        {
            if (piece == null || piece.Used) return false;
            for (int r = 0; r < Height; r++)
                for (int c = 0; c < Columns; c++)
                    if (CanPlace(piece, c, r)) return true;
            return false;
        }

        /// <summary>Taruh potongan tray[trayIndex] di jangkar (col,row). Return true kalau berhasil.</summary>
        public bool PlacePiece(int trayIndex, int col, int row)
        {
            if (GameOver) return false;
            if (trayIndex < 0 || trayIndex >= TRAY_SIZE) return false;

            var piece = Tray[trayIndex];
            if (!CanPlace(piece, col, row)) return false;

            foreach (var (dx, dy) in piece.Cells)
            {
                int r = row + dy;
                int c = Wrap(col + dx);
                Grid[c, r] = piece.Color;
            }
            piece.Used = true;
            PiecesPlaced++;

            LastPlaceScore = piece.Cells.Length * CELL_POINTS;
            Score += LastPlaceScore;

            ResolveClears();

            if (TrayEmpty()) RefillTray();

            CheckGameOver();
            return true;
        }

        // ================= CLEAR (cincin & kolom) =================

        void ResolveClears()
        {
            var rings = new List<int>();
            var cols = new List<int>();

            for (int r = 0; r < Height; r++)
            {
                bool full = true;
                for (int c = 0; c < Columns; c++)
                    if (Grid[c, r] == -1) { full = false; break; }
                if (full) rings.Add(r);
            }
            for (int c = 0; c < Columns; c++)
            {
                bool full = true;
                for (int r = 0; r < Height; r++)
                    if (Grid[c, r] == -1) { full = false; break; }
                if (full) cols.Add(c);
            }

            var clearedCells = new List<(int c, int r, int color)>();

            if (rings.Count == 0 && cols.Count == 0)
            {
                Combo = 0; // tidak ada clear -> combo putus
                LastClearScore = 0;
                LastClearGems = 0;
                LastClear = new ClearInfo
                {
                    Rings = rings, Cols = cols, Cells = clearedCells,
                    Combo = 0, Score = 0, Gems = 0, FromTool = false,
                };
                return;
            }

            var toClear = new HashSet<(int, int)>();
            foreach (int r in rings)
                for (int c = 0; c < Columns; c++) toClear.Add((c, r));
            foreach (int c in cols)
                for (int r = 0; r < Height; r++) toClear.Add((c, r));

            foreach (var (c, r) in toClear)
                clearedCells.Add((c, r, Grid[c, r]));
            foreach (var (c, r) in toClear)
                Grid[c, r] = -1;

            int lines = rings.Count + cols.Count;
            LinesCleared += lines;
            CellsCleared += clearedCells.Count;
            Combo++;
            if (Combo > BestCombo) BestCombo = Combo;

            // Skor: (base per line + bonus multi-clear) x pengali combo YANG DIBATASI.
            int baseScore = lines * CLEAR_POINTS;
            int multiBonus = lines > 1 ? (lines - 1) * (CLEAR_POINTS / 2) : 0;
            int gained = (int)Math.Round((baseScore + multiBonus) * MultiplierFor(Combo));
            Score += gained;
            LastClearScore = gained;

            LastClearGems = GemsFor(lines, Combo);
            GemsEarned += LastClearGems;

            LastClear = new ClearInfo
            {
                Rings = rings, Cols = cols, Cells = clearedCells,
                Combo = Combo, Score = gained, Gems = LastClearGems, FromTool = false,
            };
            // Tanpa gravity: sel lain tetap di tempat (khas Block Blast).
        }

        /// <summary>
        /// Kurva permata. Dulu cuma `Mathf.Max(1, Combo)` sehingga awal game butuh ~100
        /// clear untuk satu Palu, sementara akhir game jadi kaya tanpa usaha.
        /// Sekarang: hadiah dasar yang layak + bonus baris + bonus combo bertingkat.
        /// </summary>
        public static int GemsFor(int lines, int combo)
        {
            int gems = 3;                                  // dasar tiap clear
            gems += Math.Max(0, lines - 1) * 3;            // multi-line lebih berharga
            gems += Math.Min(Math.Max(0, combo - 1), 7);   // bonus combo, dibatasi
            return gems;
        }

        // ================= ALAT (PALU / BOM) =================

        /// <summary>
        /// Hancurkan sel tertentu dari sumber luar (Palu / Bom).
        ///
        /// Dulu KubikaItems menulis `_core.Grid[cc,rr] = -1` LANGSUNG, sehingga alat
        /// tidak memberi skor, tidak memberi permata, tidak memicu clear beruntun, dan
        /// tidak pernah memeriksa ulang game over. Sekarang semua lewat sini.
        /// </summary>
        public ClearInfo BlastCells(IEnumerable<(int c, int r)> cells)
        {
            var removed = new List<(int c, int r, int color)>();
            if (cells != null)
            {
                var seen = new HashSet<(int, int)>();
                foreach (var (c0, r0) in cells)
                {
                    int c = Wrap(c0);
                    int r = r0;
                    if (r < 0 || r >= Height) continue;
                    if (Grid[c, r] < 0) continue;
                    if (!seen.Add((c, r))) continue;
                    removed.Add((c, r, Grid[c, r]));
                }
            }
            foreach (var (c, r, _) in removed) Grid[c, r] = -1;

            // Alat memberi skor SETENGAH nilai sel biasa: tetap dihargai, tapi tidak
            // mengalahkan bermain dengan rapi. Alat tidak menaikkan combo.
            int gained = removed.Count * (CELL_POINTS / 2);
            Score += gained;
            CellsCleared += removed.Count;
            LastClearScore = gained;
            LastClearGems = 0;

            LastClear = new ClearInfo
            {
                Rings = new List<int>(), Cols = new List<int>(), Cells = removed,
                Combo = Combo, Score = gained, Gems = 0, FromTool = true,
            };

            // Membuka ruang bisa MENGHIDUPKAN kembali papan yang tadinya buntu.
            RecheckGameOver();
            return LastClear;
        }

        /// <summary>
        /// Hitung ulang status game over dari nol. Dipakai setelah alat membuka ruang
        /// atau setelah undo mengembalikan papan.
        /// </summary>
        public void RecheckGameOver()
        {
            GameOver = false;
            CheckGameOver();
        }

        // ================= GAME OVER =================

        void CheckGameOver()
        {
            foreach (var p in Tray)
                if (p != null && !p.Used && CanPlaceAnywhere(p)) return;
            GameOver = true;
        }

        // ================= DEBUG =================

        /// <summary>Render grid jadi teks buat tes di console (baris atas dulu).</summary>
        public string ToText()
        {
            var sb = new StringBuilder();
            for (int r = Height - 1; r >= 0; r--)
            {
                for (int c = 0; c < Columns; c++)
                    sb.Append(Grid[c, r] == -1 ? '.' : (char)('0' + Grid[c, r]));
                sb.Append('\n');
            }
            return sb.ToString();
        }
    }
}
