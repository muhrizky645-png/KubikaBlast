using UnityEngine;
using KubikaBlast;

/// <summary>
/// Tes logika BlastCore tanpa visual.
///
/// TIDAK lagi jalan otomatis. Dulu Start() memanggil RunTests() tanpa syarat,
/// jadi SETIAP sesi main — termasuk build — membanjiri Console dengan hasil tes
/// dan membuat satu BlastCore sekali pakai. Sekarang:
///   - centang "runOnStart" di Inspector kalau mau otomatis (editor saja), atau
///   - klik kanan komponennya -> "Run Logic Tests" kapan saja.
/// </summary>
public class BlastTest : MonoBehaviour
{
    [Tooltip("Jalankan tes saat Play. Hanya berlaku di Editor; build selalu melewatinya.")]
    public bool runOnStart = false;

    int _pass, _fail;

    void Start()
    {
#if UNITY_EDITOR
        if (runOnStart) RunTests();
#endif
    }

    [ContextMenu("Run Logic Tests")]
    public void RunTests()
    {
        _pass = 0; _fail = 0;
        Debug.Log("=== KUBIKA BLAST — TES LOGIKA ===");

        TestWrap();
        TestRingClear();
        TestBlockedCell();
        TestWrapPiece();
        TestScoringRules();
        TestToolBlast();
        TestShapePools();

        Debug.Log($"=== SELESAI: {_pass} lulus, {_fail} gagal ===");
    }

    // --- Tes 1: Wrap kolom (silinder) ---
    void TestWrap()
    {
        var core = new BlastCore(columns: 6, height: 6, numColors: 4, seed: 42);
        Check("Wrap(-1) == Columns-1", core.Wrap(-1) == core.Columns - 1);
        Check("Wrap(Columns) == 0", core.Wrap(core.Columns) == 0);
    }

    // --- Tes 2: isi satu cincin (baris 0) penuh -> harus ke-clear ---
    void TestRingClear()
    {
        var core = new BlastCore(columns: 6, height: 6, numColors: 4, seed: 42);

        for (int c = 0; c < core.Columns; c++) core.Grid[c, 0] = 1;
        core.Grid[0, 0] = -1; // sisakan 1 lubang di kolom 0

        var single = new BlastCore.Piece
        {
            Cells = new (int, int)[] { (0, 0) },
            Color = 2,
            Used = false
        };
        core.Tray[0] = single;

        bool placed = core.PlacePiece(0, 0, 0); // tutup lubang di (0,0)
        Check("PlacePiece menutup lubang berhasil", placed);

        bool row0Empty = true;
        for (int c = 0; c < core.Columns; c++)
            if (core.Grid[c, 0] != -1) { row0Empty = false; break; }
        Check("Cincin/baris 0 ke-clear setelah penuh", row0Empty);
        Check("LastClear mencatat 1 cincin", core.LastClear.Rings.Count == 1);
        Check("LastClear BUKAN dari tool", core.LastClear.FromTool == false);
        Check("Clear menghasilkan permata", core.LastClear.Gems > 0);
    }

    // --- Tes 3: tidak bisa menaruh di sel terisi ---
    void TestBlockedCell()
    {
        var core = new BlastCore(columns: 6, height: 6, numColors: 4, seed: 42);
        core.Grid[2, 2] = 0;
        var s2 = new BlastCore.Piece { Cells = new (int, int)[] { (0, 0) }, Color = 1, Used = false };
        Check("CanPlace di sel terisi = false", core.CanPlace(s2, 2, 2) == false);
    }

    // --- Tes 4: potongan menyeberang wrap (kolom terakhir -> 0) ---
    void TestWrapPiece()
    {
        var core = new BlastCore(columns: 6, height: 6, numColors: 4, seed: 42);
        var domino = new BlastCore.Piece
        {
            Cells = new (int, int)[] { (0, 0), (1, 0) },
            Color = 3,
            Used = false
        };
        Check("Domino menyeberang wrap valid", core.CanPlace(domino, core.Columns - 1, 5));
    }

    // --- Tes 5: aturan skor & permata yang baru ---
    void TestScoringRules()
    {
        Check("Combo 1 = pengali 1.0x",
            Mathf.Abs(BlastCore.MultiplierFor(1) - 1f) < 0.0001f);

        float atCap = 1f + BlastCore.COMBO_STEP * (BlastCore.COMBO_CAP - 1);
        Check("Combo di cap = pengali yang diharapkan",
            Mathf.Abs(BlastCore.MultiplierFor(BlastCore.COMBO_CAP) - atCap) < 0.0001f);
        Check("Pengali BERHENTI di cap (tidak tumbuh selamanya)",
            Mathf.Abs(BlastCore.MultiplierFor(999) - atCap) < 0.0001f);
        Check("Pengali naik seiring combo",
            BlastCore.MultiplierFor(3) > BlastCore.MultiplierFor(2));

        Check("Permata naik seiring jumlah baris",
            BlastCore.GemsFor(2, 1) > BlastCore.GemsFor(1, 1));
        Check("Permata naik seiring combo",
            BlastCore.GemsFor(1, 4) > BlastCore.GemsFor(1, 1));
        Check("Satu baris selalu memberi permata",
            BlastCore.GemsFor(1, 1) > 0);

        var core = new BlastCore(columns: 6, height: 6, numColors: 4, seed: 42);
        Check("Papan baru mulai di level 1", core.Level == 1);
        Check("LinesIntoLevel mulai dari 0", core.LinesIntoLevel == 0);
        Check("LINES_PER_LEVEL masuk akal", BlastCore.LINES_PER_LEVEL > 0);
    }

    // --- Tes 6: Palu/Bom lewat BlastCells ---
    void TestToolBlast()
    {
        var core = new BlastCore(columns: 6, height: 6, numColors: 4, seed: 7);
        core.Grid[1, 1] = 0;
        core.Grid[2, 1] = 1;
        int comboBefore = core.Combo;

        var info = core.BlastCells(new[] { (1, 1), (2, 1) });

        Check("BlastCells mengosongkan sel sasaran",
            core.Grid[1, 1] == -1 && core.Grid[2, 1] == -1);
        Check("BlastCells ditandai FromTool", info.FromTool);
        Check("BlastCells TIDAK menaikkan combo", core.Combo == comboBefore);
    }

    // --- Tes 7: bentuk 3x3 berat tidak pernah masuk pool ---
    void TestShapePools()
    {
        bool heavyFound = false;
        int worstLevel = -1;
        for (int level = 1; level <= 30 && !heavyFound; level++)
        {
            foreach (var shape in Shapes.PoolForLevel(level))
            {
                if (shape != null && shape.Length >= 8) { heavyFound = true; worstLevel = level; break; }
            }
        }
        Check("3x3 berat (8-9 sel) tidak pernah muncul di pool level manapun" +
              (heavyFound ? $" [bocor di level {worstLevel}]" : ""), !heavyFound);

        Check("TIER2_LEVEL sebelum TIER3_LEVEL", Shapes.TIER2_LEVEL < Shapes.TIER3_LEVEL);
    }

    void Check(string label, bool ok)
    {
        if (ok) { _pass++; Debug.Log("PASS  " + label); }
        else { _fail++; Debug.LogError("FAIL  " + label); }
    }
}
