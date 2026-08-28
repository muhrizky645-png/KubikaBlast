using UnityEngine;
using KubikaBlast;

/// <summary>
/// Render TABUNG 3D gaya gulungan kabel + kubus dari BlastCore.
/// Tahap 2: statis (isi grid contoh, tampilkan). Belum ada input.
/// Tempel ke GameObject kosong, tekan Play.
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

    [Header("Kamera")]
    public bool autoCamera = true;          // UNCHECK untuk pakai kamera manualmu
    public float camDistanceFactor = 3.2f;
    public float camHeightFactor = 0.8f;

    public Color[] palette;

    float _radius;
    BlastCore _core;
    Transform _blocksRoot;
    Mesh _mesh;
    Material[] _mats;

    void Start()
    {
        Rebuild();
    }

    /// <summary>
    /// Bangun ulang seluruh tabung + isi.
    /// Bisa dipanggil MANUAL: klik kanan komponen "Blast Game" di Inspector
    /// lalu pilih "Rebuild Tabung". Jadi kamu bisa ubah nilai di Inspector
    /// dan langsung lihat hasilnya TANPA harus tekan Play.
    /// </summary>
    [ContextMenu("Rebuild Tabung")]
    public void Rebuild()
    {
        // hapus anak lama (Reel + Blocks) supaya tidak dobel
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

        DemoFill();     // isi contoh biar kelihatan (hapus nanti di Tahap 3)
        RenderGrid();
    }

    // ===== Pemetaan sel -> dunia 3D (bagian 9.1 konsep) =====
    public Vector3 CellToWorld(int c, int r)
    {
        float ang = (float)c / columns * Mathf.PI * 2f;
        float x = Mathf.Cos(ang) * _radius;
        float z = Mathf.Sin(ang) * _radius;
        float y = r * cellHeight + cellHeight * 0.5f;
        return new Vector3(x, y, z);
    }

    Quaternion CellRotation(int c)
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

        // Drum (spool dalam) — dibuat lebih KECIL dari cincin blok, supaya blok
        // tidak menempel di drum melainkan duduk di TEPI tutup (flange).
        float drumR = _radius * drumRadiusFactor;
        var drum = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        drum.name = "Drum";
        drum.transform.SetParent(reel, false);
        drum.transform.localScale = new Vector3(drumR * 2f, totalH / 2f, drumR * 2f);
        drum.transform.position = new Vector3(0, totalH / 2f, 0);
        Paint(drum, new Color(0.25f, 0.27f, 0.32f));

        // Flange atas & bawah (piringan) — radius sedikit di luar cincin blok,
        // jadi blok tampak berada di TEPI tutup.
        float flangeR = _radius + flangeMargin;
        CreateDisc("FlangeBawah", reel, 0f, flangeR, totalH);
        CreateDisc("FlangeAtas", reel, totalH, flangeR, totalH);

        // Poros/as opsional (menghubungkan kedua flange lewat tengah)
        if (showAxle)
        {
            var axle = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
            axle.name = "Axle";
            axle.transform.SetParent(reel, false);
            float axleH = totalH + flangeThickness * 4f;
            axle.transform.localScale = new Vector3(drumR * 0.5f, axleH / 2f, drumR * 0.5f);
            axle.transform.position = new Vector3(0, totalH / 2f, 0);
            Paint(axle, new Color(0.18f, 0.19f, 0.22f));
        }

        var root = new GameObject("Blocks").transform;
        root.SetParent(transform, false);
        _blocksRoot = root;
    }

    void CreateDisc(string name, Transform parent, float y, float discRadius, float totalH)
    {
        var disc = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        disc.name = name;
        disc.transform.SetParent(parent, false);
        disc.transform.localScale = new Vector3(discRadius * 2f, flangeThickness / 2f, discRadius * 2f);
        disc.transform.position = new Vector3(0, y, 0);
        Paint(disc, new Color(0.30f, 0.22f, 0.15f)); // warna kayu
    }

    // ===== Render isi grid jadi kubus =====
    public void RenderGrid()
    {
        for (int i = _blocksRoot.childCount - 1; i >= 0; i--)
            Destroy(_blocksRoot.GetChild(i).gameObject);

        for (int r = 0; r < height; r++)
            for (int c = 0; c < columns; c++)
            {
                int col = _core.Grid[c, r];
                if (col < 0) continue;
                SpawnBlock(c, r, col);
            }
    }

    void SpawnBlock(int c, int r, int color)
    {
        var go = new GameObject($"Block_{c}_{r}");
        go.transform.SetParent(_blocksRoot, false);
        go.transform.position = CellToWorld(c, r);
        go.transform.rotation = CellRotation(c);
        go.transform.localScale = new Vector3(cellWidth * gap, cellHeight * gap, blockDepth);

        var mf = go.AddComponent<MeshFilter>();
        mf.sharedMesh = _mesh;
        var mr = go.AddComponent<MeshRenderer>();
        mr.sharedMaterial = _mats[color % _mats.Length];
    }

    // ===== Kamera membidik titik tengah tabung (bagian 9.2) =====
    void SetupCamera()
    {
        if (!autoCamera) return; // biarkan posisi/rotasi kamera manual apa adanya
        var cam = Camera.main;
        if (cam == null) return;
        float centerY = height * cellHeight / 2f;
        Vector3 target = new Vector3(0, centerY, 0);
        float dist = _radius * camDistanceFactor;
        cam.transform.position = new Vector3(0, centerY + _radius * camHeightFactor, -dist);
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
        // buang collider default cylinder (belum perlu di Tahap 2)
        var cc = go.GetComponent<Collider>();
        if (cc != null) Destroy(cc);
    }

    // ===== Isi contoh untuk lihat hasil (hapus di Tahap 3) =====
    void DemoFill()
    {
        // baris paling bawah penuh 1 cincin
        for (int c = 0; c < columns; c++) _core.Grid[c, 0] = c % numColors;
        // beberapa kubus acak-teratur di atasnya
        for (int c = 0; c < columns; c += 2) _core.Grid[c, 1] = (c + 1) % numColors;
        for (int r = 0; r < 4; r++) _core.Grid[3, r] = 2; // satu kolom naik
    }
}