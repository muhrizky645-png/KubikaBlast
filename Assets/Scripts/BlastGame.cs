using UnityEngine;
using KubikaBlast;

/// <summary>
/// Render TABUNG 3D gaya gulungan kabel + kubus dari BlastCore.
/// Tahap 2: render statis. Tahap 3: menyediakan hook untuk BlastInput
/// (Core, Radius, CellMesh, CellRotation, TryPlace) + dukungan PUTAR TABUNG.
///
/// Tempel ke GameObject kosong (mis. "Game"), lalu tambahkan juga komponen
/// BlastInput di GameObject yang sama agar bisa dimainkan.
/// </summary>
public class BlastGame : MonoBehaviour
{
    [Header("Ukuran papan")]
    public int columns = 12;
    public int height = 10;
    public int numColors = 5;

    [Header("Dimensi sel/kubus")]
    public float cellWidth = 1f;    // lebar sel di keliling tabung
    public float cellHeight = 1f;   // tinggi sel
    public float blockDepth = 0.6f; // ketebalan kubus (arah radial)
    public float gap = 0.92f;       // <1 supaya ada celah antar kubus

    [Header("Flange (gulungan kabel)")]
    public float flangeMargin = 0.4f;       // seberapa flange melebihi cincin blok
    public float flangeThickness = 0.3f;
    public float drumRadiusFactor = 0.55f;  // drum dibuat lebih kecil (spool dalam)
    public bool showAxle = true;

    [Header("Kamera (auto-fit, view fixed)")]
    public bool autoCamera = true;          // UNCHECK untuk pakai kamera manualmu
    public float cameraFitPadding = 1.1f;   // >1 = kamera agak mundur biar tabung tak mepet tepi
    public float cameraTilt = 12f;          // derajat kamera menunduk (0 = lurus dari samping)
    public float cameraAimHeight = 0.45f;   // 0=dasar tabung, 1=puncak; titik yang dibidik kamera

    [Header("Debug")]
    public bool demoFill = false;           // isi grid contoh (dulu Tahap 2). Default OFF.

    public Color[] palette;

    float _radius;
    BlastCore _core;
    Transform _blocksRoot;
    Mesh _mesh;
    Material[] _mats;

    // ===== Hook publik untuk BlastInput (Tahap 3) =====
    public BlastCore Core => _core;   // logika inti (grid, tray, skor)
    public float Radius => _radius;   // radius cincin blok (dipakai raycast)
    public Mesh CellMesh => _mesh;    // mesh kubus membulat (dipakai ghost)

    void Start()
    {
        Rebuild();
    }

    /// <summary>
    /// Bangun ulang seluruh tabung + isi.
    /// Bisa dipanggil MANUAL: klik kanan komponen "Blast Game" di Inspector
    /// lalu pilih "Rebuild Tabung" untuk lihat perubahan TANPA Play.
    /// </summary>
    [ContextMenu("Rebuild Tabung")]
    public void Rebuild()
    {
        // hapus anak lama (Reel + Blocks + Ghost) supaya tidak dobel
        for (int i = transform.childCount - 1; i >= 0; i--)
        {
            var ch = transform.GetChild(i).gameObject;
            if (Application.isPlaying) Destroy(ch);
            else DestroyImmediate(ch);
        }

        // radius cincin blok dihitung supaya keliling = columns * cellWidth
        _radius = columns * cellWidth / (2f * Mathf.PI);
        _core = new BlastCore(columns, height, numColors);
        _mesh = RoundedCube.Shared();

        BuildPalette();
        BuildReel();
        SetupCamera();

        if (demoFill) DemoFill();   // hanya untuk debug; default OFF di Tahap 3
        RenderGrid();
    }

    // ===== Pemetaan sel -> ruang LOKAL tabung (bagian 9.1 konsep) =====
    // NB: mengembalikan koordinat LOKAL (relatif ke transform BlastGame) supaya
    // blok & ghost ikut berputar saat tabung diputar.
    public Vector3 CellToWorld(int c, int r)
    {
        float ang = (float)c / columns * Mathf.PI * 2f;
        float x = Mathf.Cos(ang) * _radius;
        float z = Mathf.Sin(ang) * _radius;
        float y = r * cellHeight + cellHeight * 0.5f;
        return new Vector3(x, y, z);
    }

    public Quaternion CellRotation(int c)
    {
        float ang = (float)c / columns * Mathf.PI * 2f;
        Vector3 outward = new Vector3(Mathf.Cos(ang), 0f, Mathf.Sin(ang));
        return Quaternion.LookRotation(outward, Vector3.up);
    }

    // ===== Bangun tabung gaya gulungan kabel =====
    void BuildReel()
    {
        float totalH = height * cellHeight;
        var reel = new GameObject("Reel").transform;
        reel.SetParent(transform, false);

        // Drum (spool dalam) - lebih KECIL dari cincin blok, supaya blok duduk
        // di TEPI tutup (flange), bukan menempel drum.
        float drumR = _radius * drumRadiusFactor;
        var drum = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        drum.name = "Drum";
        drum.transform.SetParent(reel, false);
        drum.transform.localScale = new Vector3(drumR * 2f, totalH / 2f, drumR * 2f);
        drum.transform.localPosition = new Vector3(0, totalH / 2f, 0);
        Paint(drum, new Color(0.25f, 0.27f, 0.32f));

        // Flange atas & bawah (piringan)
        float flangeR = _radius + flangeMargin;
        CreateDisc("FlangeBawah", reel, 0f, flangeR);
        CreateDisc("FlangeAtas", reel, totalH, flangeR);

        // Poros/as opsional
        if (showAxle)
        {
            var axle = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
            axle.name = "Axle";
            axle.transform.SetParent(reel, false);
            float axleH = totalH + flangeThickness * 4f;
            axle.transform.localScale = new Vector3(drumR * 0.5f, axleH / 2f, drumR * 0.5f);
            axle.transform.localPosition = new Vector3(0, totalH / 2f, 0);
            Paint(axle, new Color(0.18f, 0.19f, 0.22f));
        }

        var root = new GameObject("Blocks").transform;
        root.SetParent(transform, false);
        _blocksRoot = root;
    }

    void CreateDisc(string name, Transform parent, float y, float discRadius)
    {
        var disc = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        disc.name = name;
        disc.transform.SetParent(parent, false);
        disc.transform.localScale = new Vector3(discRadius * 2f, flangeThickness / 2f, discRadius * 2f);
        disc.transform.localPosition = new Vector3(0, y, 0);
        Paint(disc, new Color(0.30f, 0.22f, 0.15f)); // warna kayu
    }

    // ===== Render isi grid jadi kubus =====
    public void RenderGrid()
    {
        for (int i = _blocksRoot.childCount - 1; i >= 0; i--)
        {
            var ch = _blocksRoot.GetChild(i).gameObject;
            if (Application.isPlaying) Destroy(ch);
            else DestroyImmediate(ch);
        }

        for (int r = 0; r < height; r++)
            for (int c = 0; c < columns; c++)
            {
                int col = _core.Grid[c, r];
                if (col < 0) continue;
                SpawnBlock(c, r, col);
            }
    }

    /// <summary>Dipanggil BlastInput: taruh potongan tray lalu render ulang.</summary>
    public bool TryPlace(int trayIndex, int col, int row)
    {
        if (_core == null) return false;
        bool ok = _core.PlacePiece(trayIndex, col, row);
        if (ok) RenderGrid();
        return ok;
    }

    void SpawnBlock(int c, int r, int color)
    {
        var go = new GameObject($"Block_{c}_{r}");
        go.transform.SetParent(_blocksRoot, false);
        // LOKAL supaya ikut berputar bersama tabung
        go.transform.localPosition = CellToWorld(c, r);
        go.transform.localRotation = CellRotation(c);
        go.transform.localScale = new Vector3(cellWidth * gap, cellHeight * gap, blockDepth);

        var mf = go.AddComponent<MeshFilter>();
        mf.sharedMesh = _mesh;
        var mr = go.AddComponent<MeshRenderer>();
        mr.sharedMaterial = _mats[color % _mats.Length];
    }

    // ===== Kamera AUTO-FIT + view fixed (menunduk dari depan-atas) =====
    // Memperhitungkan FOV kamera + rasio layar (penting untuk layar HP portrait),
    // lalu tempatkan kamera pada sudut tetap yang enak dilihat.
    void SetupCamera()
    {
        if (!autoCamera) return; // biarkan kamera manual apa adanya
        var cam = Camera.main;
        if (cam == null) return;

        float totalH = height * cellHeight;
        float aimY = totalH * Mathf.Clamp01(cameraAimHeight); // titik yang dibidik
        Vector3 target = new Vector3(0f, aimY, 0f);

        // setengah-ukuran tabung yang harus muat di layar
        float halfH = totalH / 2f + flangeThickness;   // arah tinggi
        float halfW = _radius + flangeMargin;          // arah lebar (radius luar)

        float tanV = Mathf.Tan(cam.fieldOfView * 0.5f * Mathf.Deg2Rad);
        float aspect = Mathf.Max(0.0001f, cam.aspect); // lebar / tinggi
        float tanH = tanV * aspect;

        float distForHeight = halfH / Mathf.Max(0.0001f, tanV);
        float distForWidth = halfW / Mathf.Max(0.0001f, tanH);
        float dist = Mathf.Max(distForHeight, distForWidth) * cameraFitPadding;

        // posisi kamera: mundur di -Z lalu naik sesuai sudut tunduk (tilt)
        float rad = cameraTilt * Mathf.Deg2Rad;
        Vector3 offset = new Vector3(0f, Mathf.Sin(rad) * dist, -Mathf.Cos(rad) * dist);
        cam.transform.position = target + offset;
        cam.transform.LookAt(target);
    }

    // ===== Util warna & material =====
    void BuildPalette()
    {
        if (palette == null || palette.Length == 0)
            palette = new Color[]
            {
                new Color(0.95f, 0.30f, 0.30f), // merah
                new Color(0.30f, 0.65f, 0.95f), // biru
                new Color(0.40f, 0.85f, 0.45f), // hijau
                new Color(0.98f, 0.80f, 0.25f), // kuning
                new Color(0.70f, 0.45f, 0.90f), // ungu
            };

        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");

        _mats = new Material[palette.Length];
        for (int i = 0; i < palette.Length; i++)
        {
            var m = new Material(shader);
            if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", palette[i]);
            m.color = palette[i];
            _mats[i] = m;
        }
    }

    void Paint(GameObject go, Color col)
    {
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);
        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", col);
        m.color = col;
        go.GetComponent<MeshRenderer>().sharedMaterial = m;
        // buang collider default cylinder (raycast tabung dihitung matematis, tak perlu collider)
        var cc = go.GetComponent<Collider>();
        if (cc != null)
        {
            if (Application.isPlaying) Destroy(cc);
            else DestroyImmediate(cc);
        }
    }

    // ===== Isi contoh untuk debug (dulu Tahap 2). Aktifkan lewat toggle demoFill. =====
    void DemoFill()
    {
        for (int c = 0; c < columns; c++) _core.Grid[c, 0] = c % numColors;
        for (int c = 0; c < columns; c += 2) _core.Grid[c, 1] = (c + 1) % numColors;
        for (int r = 0; r < 4; r++) _core.Grid[3, r] = 2;
    }
}
