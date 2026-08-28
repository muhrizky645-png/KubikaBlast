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
    /// </summary>
    public class BlastCore
    {
        // ---- konfigurasi skor ----
        const int CELL_POINTS = 10;    // poin per sel saat menaruh potongan
        const int CLEAR_POINTS = 100;  // poin per baris/kolom yang di-clear
        const int TRAY_SIZE = 3;       // jumlah potongan aktif

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

        // ================= TRAY =================

        void RefillTray()
        {
            for (int i = 0; i < TRAY_SIZE; i++)
                Tray[i] = NewPiece();
        }

        Piece NewPiece()
        {
            var shape = Shapes.All[_rng.Next(Shapes.All.Length)];
            var cells = new (int x, int y)[shape.Length];
            Array.Copy(shape, cells, shape.Length);
            return new Piece { Cells = cells, Color = _rng.Next(_numColors), Used = false };
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
                Combo = 0; // tidak ada clear → combo putus
                LastClear = new ClearInfo { Rings = rings, Cols = cols, Cells = clearedCells };
                return;
            }

            // Kumpulkan sel unik (hindari double-count di persilangan cincin×kolom).
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

            // Skor: (base per line + bonus multi-clear) × combo.
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