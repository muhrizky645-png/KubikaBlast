using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using KubikaBlast;

/// <summary>
/// Render TABUNG 3D gaya gulungan kabel + kubus dari BlastCore.
/// Tahap 2: render statis. Tahap 3: hook untuk BlastInput. Tahap 4: efek clear
/// + Restart (Rebuild) dipakai oleh BlastUI. Tahap 5: clear BERURUTAN satu-per-satu.
///
/// Tempel ke GameObject kosong (mis. "Game"), lalu tambahkan juga komponen
/// BlastInput (kontrol) dan BlastUI (antarmuka) agar game utuh.
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
    // Drum dibuat mepet ke SISI DALAM blok, disisakan celah drumGap biar tak nyentuh.
    // Makin kecil drumGap -> drum makin mepet ke blok. 0 = menyentuh (hindari).
    public float drumGap = 0.08f;
    public bool showAxle = true;

    [Header("Kamera (auto-fit, di-frame SEKALI saja)")]
    public bool autoCamera = true;          // UNCHECK untuk pakai kamera manualmu (tak akan disentuh)
    // FOV vertikal kamera. Kecil (mis. 30-35) = perspektif lebih FLAT/seragam (ala Block Blast),
    // auto-fit otomatis memundurkan kamera biar tabung tetap muat. Besar = lebih "lebar"/melengkung.
    public float cameraFov = 35f;
    public float cameraZoomOut = 1.25f;     // >1 = kamera mundur (zoom-out). Naikkan kalau mau lebih jauh.
    public float cameraTilt = 6f;           // derajat kamera menunduk (0 = lurus dari samping)
    public float cameraAimHeight = 0.45f;   // 0=dasar tabung, 1=puncak; titik yang dibidik kamera

    [Header("Efek clear (Tahap 4 + 5)")]
    public bool enableClearFx = true;       // percikan kubus saat baris/kolom hancur
    public float clearFxDuration = 0.4f;
    // Jeda antar sel saat hancur BERURUTAN satu-per-satu (gaya Tetris3D).
    // 0 = serempak (semua sekaligus). ~0.05-0.08 = gelombang halus.
    public float clearStepDelay = 0.06f;

    [Header("Debug")]
    public bool demoFill = false;           // isi grid contoh (dulu Tahap 2). Default OFF.

    public Color[] palette;

    float _radius;
    BlastCore _core;
    Transform _blocksRoot;
    Mesh _mesh;
    Material[] _mats;
    bool _cameraFramed;   // supaya kamera hanya diatur SEKALI (tidak reset tiap Rebuild)

    // ===== Hook publik untuk BlastInput (Tahap 3) =====
    public BlastCore Core => _core;   // logika inti (grid, tray, skor)
    public float Radius => _radius;   // radius cincin blok (dipakai raycast)
    public Mesh CellMesh => _mesh;    // mesh kubus membulat (dipakai ghost)

    void Start()
    {
        Rebuild();
    }

    /// <summary>
    /// Bangun ulang seluruh tabung + isi (juga dipakai sebagai RESTART oleh BlastUI).
    /// Bisa dipanggil MANUAL: klik kanan komponen "Blast Game" di Inspector
    /// lalu pilih "Rebuild Tabung" untuk lihat perubahan TANPA Play.
    /// Kamera TIDAK ikut di-reset saat Rebuild (lihat _cameraFramed).
    /// </summary>
    [ContextMenu("Rebuild Tabung")]
    public void Rebuild()
    {
        // hapus anak lama (Reel + Blocks + Ghost + Fx) supaya tidak dobel
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

        // Kamera diatur SEKALI saja (frame pertama), supaya tak reset tiap Rebuild.
        if (autoCamera && !_cameraFramed) { SetupCamera(); _cameraFramed = true; }

        if (demoFill) DemoFill();   // hanya untuk debug; default OFF di Tahap 3
        RenderGrid();
    }

    /// <summary>Paksa atur ulang kamera auto-fit (mis. setelah ganti ukuran papan / posisi tabung).</summary>
    [ContextMenu("Frame Camera (auto-fit sekali)")]
    public void FrameCameraNow()
    {
        SetupCamera();
        _cameraFramed = true;
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

        // Drum (spool dalam). Dibuat MEPET ke sisi dalam blok:
        //   sisi dalam blok = _radius - blockDepth/2
        //   radius drum     = sisi dalam blok - drumGap  (celah kecil biar tak nyentuh)
        float blockInner = _radius - blockDepth * 0.5f;
        float drumR = Mathf.Max(0.05f, blockInner - drumGap);
        var drum = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        drum.name = "Drum";
        drum.transform.SetParent(reel, false);
        drum.transform.localScale = new Vector3(drumR * 2f, totalH / 2f, drumR * 2f);
        drum.transform.localPosition = new Vector3(0, totalH / 2f, 0);
        Paint(drum, new Color(0.25f, 0.27f, 0.32f));

        // Flange atas & bawah (piringan). Digeser KELUAR setengah tebalnya supaya
        // permukaan DALAM flange pas di ujung tumpukan blok (y=0 & y=totalH),
        // sehingga TIDAK memotong blok baris paling bawah/atas.
        float flangeR = _radius + flangeMargin;
        CreateDisc("FlangeBawah", reel, -flangeThickness * 0.5f, flangeR);
        CreateDisc("FlangeAtas", reel, totalH + flangeThickness * 0.5f, flangeR);

        // Poros/as opsional (di tengah drum)
        if (showAxle)
        {
            var axle = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
            axle.name = "Axle";
            axle.transform.SetParent(reel, false);
            float axleH = totalH + flangeThickness * 4f;
            float axleR = Mathf.Min(drumR * 0.35f, 0.35f);
            axle.transform.localScale = new Vector3(axleR * 2f, axleH / 2f, axleR * 2f);
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

    /// <summary>Dipanggil BlastInput: taruh potongan tray lalu render ulang + efek clear.</summary>
    public bool TryPlace(int trayIndex, int col, int row)
    {
        if (_core == null) return false;
        bool ok = _core.PlacePiece(trayIndex, col, row);
        if (ok)
        {
            // Ambil laporan clear SEBELUM RenderGrid (grid sudah dikosongkan oleh core,
            // tapi LastClear.Cells menyimpan warna aslinya untuk efek).
            if (enableClearFx) SpawnClearEffect(_core.LastClear);
            RenderGrid();
        }
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

    // ===== Efek "blast" saat baris/kolom hancur (Tahap 4 + 5) =====
    // Tahap 5: hancur BERURUTAN satu-per-satu. Semua kubus Fx dibuat DULU
    // (menggantikan blok yang baru hilang supaya papan tak langsung kosong),
    // lalu animasi hancurnya dimulai SATU PER SATU dengan jeda clearStepDelay.
    // Urutan: baris bawah->atas, dalam satu baris kiri->kanan (keliling).
    void SpawnClearEffect(BlastCore.ClearInfo clear)
    {
        if (!Application.isPlaying) return;
        if (clear.Cells == null || clear.Cells.Count == 0) return;

        // Snapshot data (c,r,color) supaya aman walau LastClear berubah nanti.
        int n = clear.Cells.Count;
        var cc = new int[n];
        var rr = new int[n];
        var colr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cc[i] = clear.Cells[i].c;
            rr[i] = clear.Cells[i].r;
            colr[i] = clear.Cells[i].color;
        }

        // urutan hancur: baris bawah->atas, dalam baris kiri->kanan (keliling).
        var order = new List<int>(n);
        for (int i = 0; i < n; i++) order.Add(i);
        order.Sort((x, y) => rr[x] != rr[y] ? rr[x].CompareTo(rr[y]) : cc[x].CompareTo(cc[y]));

        // Spawn SEMUA kubus Fx sekarang (statis dulu), lalu animasikan berurutan.
        var gos = new List<GameObject>(n);
        var mrs = new List<MeshRenderer>(n);
        var mats = new List<Material>(n);
        for (int k = 0; k < order.Count; k++)
        {
            int i = order[k];
            var go = new GameObject("Fx");
            go.transform.SetParent(transform, false);        // anak Game -> ikut rotasi tabung
            go.transform.localPosition = CellToWorld(cc[i], rr[i]);
            go.transform.localRotation = CellRotation(cc[i]);
            go.transform.localScale = new Vector3(cellWidth * gap, cellHeight * gap, blockDepth);

            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _mesh;
            var mr = go.AddComponent<MeshRenderer>();
            Color baseC = (palette != null && colr[i] >= 0 && colr[i] < palette.Length)
                          ? palette[colr[i]] : Color.white;
            mr.material = MakeFxMaterial(baseC);

            gos.Add(go); mrs.Add(mr); mats.Add(mr.material);
        }

        StartCoroutine(ClearSequence(gos, mrs, mats));
    }

    IEnumerator ClearSequence(List<GameObject> gos, List<MeshRenderer> mrs, List<Material> mats)
    {
        float delay = Mathf.Max(0f, clearStepDelay);
        for (int k = 0; k < gos.Count; k++)
        {
            if (gos[k] != null) StartCoroutine(AnimateFx(gos[k], mrs[k], mats[k]));
            if (delay > 0f) yield return new WaitForSeconds(delay);
        }
    }

    IEnumerator AnimateFx(GameObject go, MeshRenderer mr, Material mat)
    {
        float dur = Mathf.Max(0.05f, clearFxDuration);
        float t = 0f;
        Vector3 s0 = go.transform.localScale;
        Vector3 s1 = s0 * 1.7f;
        Vector3 startPos = go.transform.localPosition;
        Vector3 outward = go.transform.localRotation * Vector3.forward; // radial keluar
        Color c0 = mat.HasProperty("_BaseColor") ? mat.GetColor("_BaseColor") : mat.color;

        while (t < dur)
        {
            if (go == null) yield break; // ke-destroy oleh Rebuild/restart
            float k = t / dur;
            go.transform.localScale = Vector3.Lerp(s0, s1, k);
            go.transform.localPosition = startPos + outward * (k * 0.6f);
            Color cc = c0; cc.a = Mathf.Lerp(0.95f, 0f, k);
            if (mat.HasProperty("_BaseColor")) mat.SetColor("_BaseColor", cc);
            mat.color = cc;
            t += Time.deltaTime;
            yield return null;
        }
        if (go != null) Destroy(go);
    }

    Material MakeFxMaterial(Color col)
    {
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);

        if (m.HasProperty("_Surface")) m.SetFloat("_Surface", 1f); // transparan
        m.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
        m.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
        m.SetInt("_ZWrite", 0);
        m.DisableKeyword("_SURFACE_TYPE_OPAQUE");
        m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
        m.EnableKeyword("_ALPHABLEND_ON");
        m.renderQueue = (int)UnityEngine.Rendering.RenderQueue.Transparent;

        Color c = col; c.a = 0.95f;
        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", c);
        if (m.HasProperty("_EmissionColor")) { m.EnableKeyword("_EMISSION"); m.SetColor("_EmissionColor", col * 0.6f); }
        m.color = c;
        return m;
    }

    // ===== Kamera AUTO-FIT + view fixed (menunduk dari depan-atas) =====
    // Membidik POSISI TABUNG SEBENARNYA (transform.position), bukan titik nol dunia,
    // supaya selalu center walau GameObject Game tidak di (0,0,0).
    // Memperhitungkan FOV + rasio layar. Dipanggil SEKALI.
    void SetupCamera()
    {
        var cam = Camera.main;
        if (cam == null) return;

        // Pakai FOV yang kita tentukan -> perspektif konsisten & bisa dibikin flat.
        cam.fieldOfView = Mathf.Clamp(cameraFov, 5f, 120f);

        float totalH = height * cellHeight;
        Vector3 basePos = transform.position; // posisi dunia tabung (dasar tabung)
        float aimY = totalH * Mathf.Clamp01(cameraAimHeight);
        Vector3 target = new Vector3(basePos.x, basePos.y + aimY, basePos.z); // titik yang dibidik

        // setengah-ukuran tabung yang harus muat di layar
        float halfH = totalH / 2f + flangeThickness;   // arah tinggi
        float halfW = _radius + flangeMargin;          // arah lebar (radius luar)

        float tanV = Mathf.Tan(cam.fieldOfView * 0.5f * Mathf.Deg2Rad);
        float aspect = Mathf.Max(0.0001f, cam.aspect); // lebar / tinggi
        float tanH = tanV * aspect;

        float distForHeight = halfH / Mathf.Max(0.0001f, tanV);
        float distForWidth = halfW / Mathf.Max(0.0001f, tanH);
        float dist = Mathf.Max(distForHeight, distForWidth) * Mathf.Max(0.1f, cameraZoomOut);

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
