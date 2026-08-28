using UnityEngine;
using KubikaBlast;

/// <summary>
/// Script tes logika BlastCore tanpa visual.
/// Tempel ke GameObject kosong di scene, tekan Play, lihat Console.
/// </summary>
public class BlastTest : MonoBehaviour
{
    void Start()
    {
        RunTests();
    }

    void RunTests()
    {
        Debug.Log("=== KUBIKA BLAST — TES LOGIKA ===");

        // Papan kecil biar gampang diamati: 6 kolom x 6 baris, seed tetap.
        var core = new BlastCore(columns: 6, height: 6, numColors: 4, seed: 42);

        // --- Tes 1: Wrap kolom (silinder) ---
        // Wrap(-1) harus jadi kolom terakhir; Wrap(Columns) harus jadi 0.
        Check("Wrap(-1) == Columns-1", core.Wrap(-1) == core.Columns - 1);
        Check("Wrap(Columns) == 0", core.Wrap(core.Columns) == 0);

        // --- Tes 2: isi satu cincin (baris 0) penuh secara manual → harus ke-clear ---
        // Kita pakai grid langsung untuk kontrol penuh.
        for (int c = 0; c < core.Columns; c++) core.Grid[c, 0] = 1;
        core.Grid[0, 0] = -1; // sisakan 1 lubang di kolom 0

        // Buat potongan Single buatan sendiri untuk menutup lubang.
        var single = new BlastCore.Piece {
            Cells = new (int, int)[] { (0, 0) }, Color = 2, Used = false
        };
        core.Tray[0] = single;

        bool placed = core.PlacePiece(0, 0, 0); // tutup lubang di (0,0)
        Check("PlacePiece menutup lubang berhasil", placed);

        // Setelah lubang tertutup, baris 0 harus penuh lalu di-clear (jadi kosong lagi).
        bool row0Empty = true;
        for (int c = 0; c < core.Columns; c++)
            if (core.Grid[c, 0] != -1) { row0Empty = false; break; }
        Check("Cincin/baris 0 ke-clear setelah penuh", row0Empty);
        Check("LastClear mencatat 1 cincin", core.LastClear.Rings.Count == 1);

        // --- Tes 3: tidak bisa menaruh di sel terisi ---
        core.Grid[2, 2] = 0;
        var s2 = new BlastCore.Piece { Cells = new (int, int)[] { (0, 0) }, Color = 1, Used = false };
        Check("CanPlace di sel terisi = false", core.CanPlace(s2, 2, 2) == false);

        // --- Tes 4: potongan menyeberang wrap (kolom terakhir → 0) ---
        var domino = new BlastCore.Piece {
            Cells = new (int, int)[] { (0, 0), (1, 0) }, Color = 3, Used = false
        };
        // Jangkar di kolom terakhir; sel kedua harus wrap ke kolom 0.
        bool canWrap = core.CanPlace(domino, core.Columns - 1, 5);
        Check("Domino menyeberang wrap valid", canWrap);

        Debug.Log("Grid akhir:\n" + core.ToText());
        Debug.Log("=== SELESAI ===");
    }

    void Check(string label, bool ok)
    {
        if (ok) Debug.Log($"✅ {label}");
        else Debug.LogError($"❌ {label}");
    }
}