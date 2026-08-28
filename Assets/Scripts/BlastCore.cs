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
    /// SMART DROP: potongan tray tidak lagi acak murni. Tiap potongan di-carve dari
    /// CELAH NYATA pada papan (solusi tersembunyi) sehingga DIJAMIN punya slot yang pas,
    /// dan cenderung memicu clear. LEVEL naik tiap LEVEL_STEP skor; makin tinggi level,
    /// makin besar & aneh bentuk yang muncul.
    /// </summary>
    public class BlastCore
    {
        // ---- konfigurasi skor ----
        const int CELL_POINTS = 10;    // poin per sel saat menaruh potongan
        const int CLEAR_POINTS = 100;  // poin per baris/kolom yang di-clear
        const int TRAY_SIZE = 3;       // jumlah potongan aktif
        const int LEVEL_STEP = 1000;   // skor yang dibutuhkan untuk naik satu level

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

        // Level naik tiap LEVEL_STEP skor. Mulai dari 1.
        public int Level => Math.Max(1, Score / LEVEL_STEP + 1);

        // ---- laporan clear terakhir (dibaca renderer untuk efek visual) ----
        public struct ClearInfo
        {
            public List<int> Rings;                       // baris yang di-clear
            public List<int> Cols;                        // kolom yang di-clear
            public List<(int c, int r, int color)> Cells; // sel yang hancur
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
            GameOver = false;
            RefillTray();
        }

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
            for (int i = 0; i < TRAY_SIZE; i++)
                Tray[i] = GenerateSmartPiece(scratch);
        }

        Piece GenerateSmartPiece(int[,] scratch)
        {
            var pool = Shapes.PoolForLevel(Level);

            // Acak urutan bentuk biar variatif.
            int[] order = new int[pool.Length];
            for (int i = 0; i < pool.Length; i++) order[i] = i;
            for (int i = order.Length - 1; i > 0; i--)
            {
                int j = _rng.Next(i + 1);
                int tmp = order[i]; order[i] = order[j]; order[j] = tmp;
            }

            (int x, int y)[] bestShape = null;
            int bestCol = 0, bestRow = 0;
            double bestScore = double.NegativeInfinity;

            foreach (int oi in order)
            {
                var shape = pool[oi];
                for (int row = 0; row < Height; row++)
                {
                    for (int col = 0; col < Columns; col++)
                    {
                        if (!FitsOn(scratch, shape, col, row)) continue;
                        double s = ScorePlacement(scratch, shape, col, row) + _rng.NextDouble() * 0.5;
                        if (s > bestScore)
                        {
                            bestScore = s;
                            bestShape = shape;
                            bestCol = col;
                            bestRow = row;
                        }
                    }
                }
            }

            if (bestShape == null)
            {
                // Papan hampir penuh: cari sel kosong apa pun untuk potongan Titik.
                for (int row = 0; row < Height && bestShape == null; row++)
                    for (int col = 0; col < Columns && bestShape == null; col++)
                        if (scratch[col, row] == -1)
                        {
                            bestShape = new (int x, int y)[] { (0, 0) };
                            bestCol = col; bestRow = row;
                        }
            }
            if (bestShape == null)
            {
                // Benar-benar penuh: kembalikan Titik apa adanya (memicu game over nanti).
                bestShape = new (int x, int y)[] { (0, 0) };
                bestCol = 0; bestRow = 0;
            }

            // Pesan slot di scratch supaya potongan berikutnya tidak menimpa (tanpa clear,
            // agar setiap slot terpilih tetap kosong di papan ASLI => dijamin muat).
            int color = _rng.Next(_numColors);
            foreach (var (dx, dy) in bestShape)
            {
                int r = bestRow + dy;
                int c = Wrap(bestCol + dx);
                if (r >= 0 && r < Height) scratch[c, r] = color;
            }

            var cells = new (int x, int y)[bestShape.Length];
            Array.Copy(bestShape, cells, bestShape.Length);
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

        // Nilai kelayakan penempatan: utamakan yang menyelesaikan cincin/kolom, lalu yang
        // menempel rapat ke sel terisi/tepi (kompak). Memakai penanda sementara -2.
        double ScorePlacement(int[,] grid, (int x, int y)[] shape, int col, int row)
        {
            var placed = new List<(int c, int r)>();
            foreach (var (dx, dy) in shape)
            {
                int r = row + dy;
                int c = Wrap(col + dx);
                grid[c, r] = -2; // penanda sementara (dianggap terisi)
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
                    if (nr < 0 || nr >= Height) { adjacency++; continue; } // tepi atas/bawah
                    int v = grid[nc, nr];
                    if (v != -1 && v != -2) adjacency++; // menempel ke sel terisi asli
                }
            }

            // Bersihkan penanda sementara.
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

        // col, row = posisi jangkar (0,0) potongan pada grid.
        public bool CanPlace(Piece piece, int col, int row)
        {
            if (piece == null || piece.Used) return false;
            foreach (var (dx, dy) in piece.Cells)
            {
                int r = row + dy;
                int c = Wrap(col + dx);
                if (r < 0 || r >= Height) return false; // di luar tinggi tabung
                if (Grid[c, r] != -1) return false;     // sel sudah terisi
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
            Score += piece.Cells.Length * CELL_POINTS;

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

            // Cincin/baris penuh
            for (int r = 0; r < Height; r++)
            {
                bool full = true;
                for (int c = 0; c < Columns; c++)
                    if (Grid[c, r] == -1) { full = false; break; }
                if (full) rings.Add(r);
            }
            // Kolom penuh
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
                LastClear = new ClearInfo { Rings = rings, Cols = cols, Cells = clearedCells };
                return;
            }

            // Kumpulkan sel unik (hindari double-count di persilangan cincin x kolom).
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
            Combo++;

            // Skor: (base per line + bonus multi-clear) x combo.
            int baseScore = lines * CLEAR_POINTS;
            int multiBonus = lines > 1 ? (lines - 1) * (CLEAR_POINTS / 2) : 0;
            Score += (baseScore + multiBonus) * Math.Max(1, Combo);

            LastClear = new ClearInfo { Rings = rings, Cols = cols, Cells = clearedCells };
            // Tanpa gravity: sel lain tetap di tempat (khas Block Blast).
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
