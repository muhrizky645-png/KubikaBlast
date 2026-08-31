using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using KubikaBlast;

/// <summary>
/// Render TABUNG 3D gaya gulungan kabel + kubus dari BlastCore.
///
/// PERBAIKAN PENTING (blok hantu):
///   Dulu kubus efek ("Fx") di-parent ke `transform`, sementara RenderGrid() hanya
///   membersihkan anak-anak `_blocksRoot`. Jadi selama ~1.1 detik setelah clear ada
///   kubus sekarat yang MASIH TERLIHAT di papan padahal Grid sudah kosong — persis
///   seperti "muncul blok baru entah dari mana". Sekarang semua efek hidup di root
///   terpisah `_fxRoot` ("ClearFx") yang bisa dibersihkan kapan saja, dan durasinya
///   dipangkas jadi ~0.5 detik total.
///
/// JAM COMBO:
///   BlastCore murni C# dan tidak tahu waktu Unity, jadi jendela combo 10 detik
///   digerakkan dari sini lewat Update() -> _core.TickCombo(Time.time).
/// </summary>
public class BlastGame : MonoBehaviour
{
    [Header("Ukuran papan")]
    public int columns = 12;
    public int height = 10;
    public int numColors = 5;

    [Header("Dimensi sel/kubus")]
    public float cellWidth = 1f;
    public float cellHeight = 1f;
    public float blockDepth = 0.6f;
    public float gap = 0.92f;

    [Header("Flange (gulungan kabel)")]
    public float flangeMargin = 0.4f;
    public float flangeThickness = 0.3f;
    public float drumGap = 0.08f;
    public bool showAxle = true;

    [Header("Kamera (auto-fit, di-frame SEKALI saja)")]
    public bool autoCamera = true;
    public float cameraFov = 35f;
    public float cameraZoomOut = 1.25f;
    public float cameraTilt = 6f;
    public float cameraAimHeight = 0.45f;

    [Header("Efek clear")]
    public bool enableClearFx = true;
    // Dipangkas dari 0.4 -> 0.3 dan 0.06 -> 0.02. Dulu 24 sel x 0.06 = 1.44 detik
    // rentetan, jadi kubus sekarat menumpuk di papan dan suaranya saling tabrakan.
    public float clearFxDuration = 0.3f;
    public float clearStepDelay = 0.02f;

    [Header("Efek hadiah (menghargai pemain)")]
    public bool enableShockwave = true;
    public bool enableCameraShake = true;
    [Range(0f, 1f)] public float shakeStrength = 0.5f;
    [Range(0f, 0.5f)] public float blockEmission = 0.14f;

    [Header("Debug")]
    public bool demoFill = false;

    [Header("Bayangan (shadow)")]
    public bool disableShadows = true;
    public bool disableSceneLightShadows = true;

    [Header("Kecerdasan potongan (smart drop)")]
    [Range(0f, 1f)] public float clearBias = 0.35f;

    [Header("Blok default saat mulai (starting fill)")]
    public bool startWithBlocks = true;
    [Range(0f, 1f)] public float startFillChance = 0.45f;
    public bool startRandomColors = true;
    public int startSeed = 0;

    public Color[] palette;

    float _radius;
    BlastCore _core;
    Transform _blocksRoot;
    Transform _fxRoot;
    Mesh _mesh;
    Material[] _mats;
    bool _cameraFramed;

    // Semua material yang KAMI buat, supaya bisa dihancurkan saat Rebuild.
    // Dulu tiap Rebuild membocorkan satu set penuh (palet + drum + 2 flange + axle).
    readonly List<Material> _ownedMats = new List<Material>();

    // Getaran kamera.
    float _shake;
    Vector3 _camBase;
    bool _camBaseSet;

    /// <summary>
    /// True selagi jeda dramatis (hit-stop) berlangsung. KubikaMenu memeriksa ini
    /// sebelum memaksa Time.timeScale kembali ke 1.
    /// </summary>
    public static bool HitStopActive { get; private set; }

    // ===== Hook publik untuk BlastInput =====
    public BlastCore Core => _core;
    public float Radius => _radius;
    public Mesh CellMesh => _mesh;

    // ===== Event (menggantikan tebak-tebakan lewat selisih skor) =====
    /// <summary>Potongan berhasil ditaruh. Argumen = jumlah sel potongan.</summary>
    public event System.Action<int> OnPlaced;
    /// <summary>Ada sel yang hancur (dari penempatan ATAU dari alat).</summary>
    public event System.Action<BlastCore.ClearInfo> OnCleared;
    /// <summary>Level naik. Argumen = level baru.</summary>
    public event System.Action<int> OnLevelUp;
    /// <summary>Papan buntu. Dipanggil TEPAT SEKALI per ronde.</summary>
    public event System.Action OnGameOver;
    /// <summary>Papan dibangun ulang (ronde baru).</summary>
    public event System.Action OnRebuilt;

    bool _gameOverFired;

    void Start()
    {
        Rebuild();
    }

    void Update()
    {
        if (_core == null) return;

        // Jendela combo 10 detik. SENGAJA memakai Time.time (TERSKALA), bukan
        // Time.unscaledTime: KubikaMenu menyetel timeScale = 0 saat jeda, sehingga
        // Time.time ikut berhenti dan membuka menu jeda TIDAK menghanguskan rantai
        // combo yang sedang berjalan. Hit-stop cuma 0.06x selama <=0.25 detik, jadi
        // pengaruhnya di sini bisa diabaikan.
        _core.TickCombo(Time.time);
    }

    void OnDestroy()
    {
        HitStopActive = false;
        CleanupOwnedMaterials();
    }

    [ContextMenu("Rebuild Tabung")]
    public void Rebuild()
    {
        // Hentikan SEMUA animasi ronde sebelumnya sebelum apa pun dihancurkan.
        StopAllCoroutines();
        HitStopActive = false;
        _shake = 0f;
        _gameOverFired = false;

        CleanupOwnedMaterials();

        for (int i = transform.childCount - 1; i >= 0; i--)
            Kill(transform.GetChild(i).gameObject);

        _radius = columns * cellWidth / (2f * Mathf.PI);
        _mesh = RoundedCube.Shared();

        // Palet dibangun DULU supaya numColors bisa dijepit ke jumlah warna nyata.
        // Dulu numColors bisa melebihi panjang palette dan meminta warna yang tak ada.
        BuildPalette();
        numColors = Mathf.Clamp(numColors, 1, Mathf.Max(1, palette.Length));

        _core = new BlastCore(columns, height, numColors);
        _core.ClearBias = clearBias;

        // Samakan jam combo dengan waktu sekarang supaya ronde baru tidak memulai
        // hidup dengan jendela combo yang sudah kedaluwarsa.
        _core.TickCombo(Time.time);

        BuildReel();

        if (autoCamera && !_cameraFramed) { SetupCamera(); _cameraFramed = true; }

        if (disableShadows) DisableLightShadows();

        if (demoFill) DemoFill();
        else if (startWithBlocks) StartingFill();

        // SMART DROP: setelah papan terisi, carve ulang tray dari CELAH NYATA di papan
        // supaya tiap potongan dijamin punya slot pas (solusi tersembunyi).
        _core.RegenerateTray();
        RenderGrid();

        OnRebuilt?.Invoke();
    }

    void Kill(Object o)
    {
        if (o == null) return;
        if (Application.isPlaying) Destroy(o);
        else DestroyImmediate(o);
    }

    void CleanupOwnedMaterials()
    {
        for (int i = 0; i < _ownedMats.Count; i++) Kill(_ownedMats[i]);
        _ownedMats.Clear();
        _mats = null;
    }

    [ContextMenu("Frame Camera (auto-fit sekali)")]
    public void FrameCameraNow()
    {
        SetupCamera();
        _cameraFramed = true;
    }

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

    void BuildReel()
    {
        float totalH = height * cellHeight;
        var reel = new GameObject("Reel").transform;
        reel.SetParent(transform, false);

        float blockInner = _radius - blockDepth * 0.5f;
        float drumR = Mathf.Max(0.05f, blockInner - drumGap);
        var drum = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        drum.name = "Drum";
        drum.transform.SetParent(reel, false);
        drum.transform.localScale = new Vector3(drumR * 2f, totalH / 2f, drumR * 2f);
        drum.transform.localPosition = new Vector3(0, totalH / 2f, 0);
        Paint(drum, new Color(0.25f, 0.27f, 0.32f));

        float flangeR = _radius + flangeMargin;
        CreateDisc("FlangeBawah", reel, -flangeThickness * 0.5f, flangeR);
        CreateDisc("FlangeAtas", reel, totalH + flangeThickness * 0.5f, flangeR);

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

        // Root TERPISAH untuk efek. Ini yang mencegah kubus sekarat disangka blok asli.
        var fx = new GameObject("ClearFx").transform;
        fx.SetParent(transform, false);
        _fxRoot = fx;
    }

    void CreateDisc(string name, Transform parent, float y, float discRadius)
    {
        var disc = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        disc.name = name;
        disc.transform.SetParent(parent, false);
        disc.transform.localScale = new Vector3(discRadius * 2f, flangeThickness / 2f, discRadius * 2f);
        disc.transform.localPosition = new Vector3(0, y, 0);
        Paint(disc, new Color(0.30f, 0.22f, 0.15f));
    }

    public void RenderGrid()
    {
        if (_blocksRoot == null || _core == null) return;

        for (int i = _blocksRoot.childCount - 1; i >= 0; i--)
            Kill(_blocksRoot.GetChild(i).gameObject);

        for (int r = 0; r < height; r++)
            for (int c = 0; c < columns; c++)
            {
                int col = _core.Grid[c, r];
                if (col < 0) continue;
                SpawnBlock(c, r, col);
            }
    }

    /// <summary>Buang semua efek yang sedang berjalan (dipakai saat game over / restart).</summary>
    public void ClearFx()
    {
        StopAllCoroutines();
        if (_fxRoot == null) return;
        for (int i = _fxRoot.childCount - 1; i >= 0; i--)
            Kill(_fxRoot.GetChild(i).gameObject);
    }

    public bool TryPlace(int trayIndex, int col, int row)
    {
        if (_core == null || _core.GameOver) return false;

        int levelBefore = _core.Level;
        var piece = (trayIndex >= 0 && trayIndex < _core.Tray.Length) ? _core.Tray[trayIndex] : null;
        int pieceCells = (piece != null && piece.Cells != null) ? piece.Cells.Length : 0;

        // Pastikan jam combo mutakhir SEBELUM clear diselesaikan, supaya keputusan
        // sambung-atau-putus memakai waktu penempatan ini, bukan frame sebelumnya.
        _core.TickCombo(Time.time);

        bool ok = _core.PlacePiece(trayIndex, col, row);
        if (!ok) return false;

        RenderGrid();
        OnPlaced?.Invoke(pieceCells);

        var clear = _core.LastClear;
        int clearedCells = (clear.Cells != null) ? clear.Cells.Count : 0;
        if (clearedCells > 0)
        {
            if (enableClearFx) SpawnClearEffect(clear);
            ApplyImpact(clear);
            OnCleared?.Invoke(clear);
        }

        if (_core.Level > levelBefore && !_core.GameOver) OnLevelUp?.Invoke(_core.Level);

        if (_core.GameOver && !_gameOverFired)
        {
            _gameOverFired = true;
            OnGameOver?.Invoke();
        }
        return true;
    }

    /// <summary>
    /// Hancurkan sel dari alat (Palu / Bom) LEWAT BlastCore, bukan dengan menulis
    /// Grid langsung. Dengan begitu alat ikut memberi skor, memunculkan efek, dan
    /// memeriksa ulang game over kalau ruang yang dibuka menyelamatkan pemain.
    /// </summary>
    public BlastCore.ClearInfo BlastCells(IEnumerable<(int c, int r)> cells)
    {
        if (_core == null) return default;

        var info = _core.BlastCells(cells);
        if (info.Cells != null && info.Cells.Count > 0)
        {
            if (enableClearFx) SpawnClearEffect(info);
            ApplyImpact(info);
        }
        RenderGrid();

        if (info.Cells != null && info.Cells.Count > 0) OnCleared?.Invoke(info);

        if (_core.GameOver && !_gameOverFired)
        {
            _gameOverFired = true;
            OnGameOver?.Invoke();
        }
        else if (!_core.GameOver)
        {
            _gameOverFired = false; // alat menyelamatkan papan
        }
        return info;
    }

    void SpawnBlock(int c, int r, int color)
    {
        var go = new GameObject($"Block_{c}_{r}");
        go.transform.SetParent(_blocksRoot, false);
        go.transform.localPosition = CellToWorld(c, r);
        go.transform.localRotation = CellRotation(c);
        go.transform.localScale = new Vector3(cellWidth * gap, cellHeight * gap, blockDepth);

        var mf = go.AddComponent<MeshFilter>();
        mf.sharedMesh = _mesh;
        var mr = go.AddComponent<MeshRenderer>();
        mr.sharedMaterial = _mats[color % _mats.Length];
        if (disableShadows) DisableShadows(mr);
    }

    // ==================================================================
    // ============ EFEK CLEAR ==========================================
    // ==================================================================

    void ApplyImpact(BlastCore.ClearInfo clear)
    {
        int lines = 0;
        if (clear.Rings != null) lines += clear.Rings.Count;
        if (clear.Cols != null) lines += clear.Cols.Count;

        if (enableShockwave && lines > 0) SpawnShockwaves(clear);

        if (enableCameraShake)
        {
            int cells = (clear.Cells != null) ? clear.Cells.Count : 0;
            float mag = Mathf.Clamp01(cells / 40f) * 0.6f + Mathf.Clamp01(lines / 4f) * 0.4f;
            float comboBoost = 1f + Mathf.Clamp01((clear.Combo - 1) / 6f) * 0.8f;
            Shake(mag * comboBoost * shakeStrength);
        }
    }

    /// <summary>Tambah getaran kamera. Selalu mengambil nilai TERBESAR, tidak menumpuk.</summary>
    public void Shake(float amount)
    {
        if (amount > _shake) _shake = Mathf.Min(1.2f, amount);
    }

    void LateUpdate()
    {
        if (!enableCameraShake) return;
        var cam = Camera.main;
        if (cam == null) return;

        if (!_camBaseSet) { _camBase = cam.transform.position; _camBaseSet = true; }

        if (_shake > 0.0005f)
        {
            _shake = Mathf.MoveTowards(_shake, 0f, Time.unscaledDeltaTime * 2.6f);
            Vector3 off = Random.insideUnitSphere * (_shake * 0.22f);
            off.z *= 0.35f;
            cam.transform.position = _camBase + off;
        }
        else if (cam.transform.position != _camBase)
        {
            cam.transform.position = _camBase;
        }
    }

    void SpawnShockwaves(BlastCore.ClearInfo clear)
    {
        if (!Application.isPlaying || _fxRoot == null) return;

        Color glow = new Color(1f, 0.94f, 0.65f);
        if (clear.Combo >= 5) glow = new Color(1f, 0.72f, 0.35f);
        if (clear.Combo >= 7) glow = new Color(1f, 0.55f, 0.75f);

        if (clear.Rings != null)
            foreach (int r in clear.Rings) SpawnRingShock(r, glow);

        // Kolom vertikal: satu kilatan tinggi di posisi kolom itu.
        if (clear.Cols != null)
            foreach (int c in clear.Cols) SpawnColumnShock(c, glow);
    }

    void SpawnRingShock(int row, Color glow)
    {
        var go = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        go.name = "ShockRing";
        var col = go.GetComponent<Collider>();
        if (col != null) Kill(col);
        go.transform.SetParent(_fxRoot, false);
        go.transform.localPosition = new Vector3(0f, row * cellHeight + cellHeight * 0.5f, 0f);

        var mr = go.GetComponent<MeshRenderer>();
        var mat = MakeGlowMaterial(glow);
        mr.material = mat;
        DisableShadows(mr);

        StartCoroutine(AnimateShock(go, mat, _radius * 1.02f, _radius * 2.1f, cellHeight * 0.16f));
    }

    void SpawnColumnShock(int c, Color glow)
    {
        var go = GameObject.CreatePrimitive(PrimitiveType.Cylinder);
        go.name = "ShockCol";
        var col = go.GetComponent<Collider>();
        if (col != null) Kill(col);
        go.transform.SetParent(_fxRoot, false);

        float totalH = height * cellHeight;
        Vector3 dir = CellToWorld(c, 0).normalized;
        go.transform.localPosition = dir * (_radius * 1.15f) + new Vector3(0f, totalH * 0.5f, 0f);
        go.transform.localScale = new Vector3(cellWidth * 0.5f, totalH * 0.5f, cellWidth * 0.5f);

        var mr = go.GetComponent<MeshRenderer>();
        var mat = MakeGlowMaterial(glow);
        mr.material = mat;
        DisableShadows(mr);

        StartCoroutine(AnimateColumnShock(go, mat));
    }

    IEnumerator AnimateShock(GameObject go, Material mat, float r0, float r1, float thickness)
    {
        const float dur = 0.42f;
        float t = 0f;
        while (t < dur)
        {
            if (go == null) { Kill(mat); yield break; }
            float k = t / dur;
            float ease = 1f - (1f - k) * (1f - k);         // ease-out
            float rad = Mathf.Lerp(r0, r1, ease);
            go.transform.localScale = new Vector3(rad * 2f, thickness, rad * 2f);
            SetGlowAlpha(mat, Mathf.Lerp(0.55f, 0f, k));
            t += Time.unscaledDeltaTime;
            yield return null;
        }
        Kill(go);
        Kill(mat);
    }

    IEnumerator AnimateColumnShock(GameObject go, Material mat)
    {
        const float dur = 0.38f;
        float t = 0f;
        Vector3 s0 = go.transform.localScale;
        while (t < dur)
        {
            if (go == null) { Kill(mat); yield break; }
            float k = t / dur;
            float w = Mathf.Lerp(1f, 2.6f, k);
            go.transform.localScale = new Vector3(s0.x * w, s0.y, s0.z * w);
            SetGlowAlpha(mat, Mathf.Lerp(0.5f, 0f, k));
            t += Time.unscaledDeltaTime;
            yield return null;
        }
        Kill(go);
        Kill(mat);
    }

    void SpawnClearEffect(BlastCore.ClearInfo clear)
    {
        if (!Application.isPlaying) return;
        if (_fxRoot == null) return;
        if (clear.Cells == null || clear.Cells.Count == 0) return;

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

        var order = new List<int>(n);
        for (int i = 0; i < n; i++) order.Add(i);
        order.Sort((x, y) => rr[x] != rr[y] ? rr[x].CompareTo(rr[y]) : cc[x].CompareTo(cc[y]));

        var gos = new List<GameObject>(n);
        var mats = new List<Material>(n);
        for (int k = 0; k < order.Count; k++)
        {
            int i = order[k];
            var go = new GameObject("Fx");
            // >>> root TERPISAH: tidak akan pernah tertukar dengan blok asli. <<<
            go.transform.SetParent(_fxRoot, false);
            go.transform.localPosition = CellToWorld(cc[i], rr[i]);
            go.transform.localRotation = CellRotation(cc[i]);
            go.transform.localScale = new Vector3(cellWidth * gap, cellHeight * gap, blockDepth);

            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _mesh;
            var mr = go.AddComponent<MeshRenderer>();
            Color baseC = (palette != null && colr[i] >= 0 && colr[i] < palette.Length)
                          ? palette[colr[i]] : Color.white;
            var mat = MakeFxMaterial(baseC);
            mr.material = mat;
            if (disableShadows) DisableShadows(mr);

            gos.Add(go); mats.Add(mat);
        }

        StartCoroutine(ClearSequence(gos, mats));
    }

    IEnumerator ClearSequence(List<GameObject> gos, List<Material> mats)
    {
        float delay = Mathf.Max(0f, clearStepDelay);
        for (int k = 0; k < gos.Count; k++)
        {
            if (gos[k] != null) StartCoroutine(AnimateFx(gos[k], mats[k]));
            if (delay > 0f) yield return new WaitForSecondsRealtime(delay);
        }
    }

    IEnumerator AnimateFx(GameObject go, Material mat)
    {
        float dur = Mathf.Max(0.05f, clearFxDuration);
        float t = 0f;
        Vector3 s0 = go.transform.localScale;
        Vector3 s1 = s0 * 1.85f;
        Vector3 startPos = go.transform.localPosition;
        Vector3 outward = go.transform.localRotation * Vector3.forward;
        Vector3 spin = new Vector3(Random.Range(-160f, 160f), Random.Range(-160f, 160f), Random.Range(-160f, 160f));
        Color c0 = mat.HasProperty("_BaseColor") ? mat.GetColor("_BaseColor") : mat.color;

        while (t < dur)
        {
            if (go == null) { Kill(mat); yield break; }
            float k = t / dur;

            // Sedikit "pop" dulu sebelum mengembang & memudar — terasa pecah, bukan meleleh.
            float pop = k < 0.14f ? Mathf.Lerp(1f, 1.22f, k / 0.14f) : 1f;
            go.transform.localScale = Vector3.Lerp(s0, s1, k) * pop;
            go.transform.localPosition = startPos + outward * (k * 0.75f) + Vector3.up * (k * k * 0.35f);
            go.transform.Rotate(spin * Time.unscaledDeltaTime, Space.Self);

            Color cc = c0;
            cc.a = Mathf.Lerp(0.95f, 0f, k * k);
            if (mat.HasProperty("_BaseColor")) mat.SetColor("_BaseColor", cc);
            if (mat.HasProperty("_EmissionColor"))
                mat.SetColor("_EmissionColor", c0 * Mathf.Lerp(2.2f, 0f, k));
            mat.color = cc;

            t += Time.unscaledDeltaTime;
            yield return null;
        }
        Kill(go);
        Kill(mat);
    }

    Material MakeFxMaterial(Color col)
    {
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);

        if (m.HasProperty("_Surface")) m.SetFloat("_Surface", 1f);
        m.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
        m.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
        m.SetInt("_ZWrite", 0);
        m.DisableKeyword("_SURFACE_TYPE_OPAQUE");
        m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
        m.EnableKeyword("_ALPHABLEND_ON");
        m.renderQueue = (int)UnityEngine.Rendering.RenderQueue.Transparent;

        Color c = col; c.a = 0.95f;
        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", c);
        if (m.HasProperty("_EmissionColor")) { m.EnableKeyword("_EMISSION"); m.SetColor("_EmissionColor", col * 2.2f); }
        m.color = c;
        return m;
    }

    // Material aditif untuk gelombang kejut. TIDAK didaftarkan ke _ownedMats karena
    // umurnya pendek dan dihancurkan sendiri di akhir koroutin.
    Material MakeGlowMaterial(Color col)
    {
        var shader = Shader.Find("Universal Render Pipeline/Unlit");
        if (shader == null) shader = Shader.Find("Unlit/Color");
        if (shader == null) shader = Shader.Find("Sprites/Default");
        var m = new Material(shader);

        if (m.HasProperty("_Surface")) m.SetFloat("_Surface", 1f);
        m.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
        m.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.One); // aditif
        m.SetInt("_ZWrite", 0);
        m.DisableKeyword("_SURFACE_TYPE_OPAQUE");
        m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
        m.renderQueue = (int)UnityEngine.Rendering.RenderQueue.Transparent + 10;

        Color c = col; c.a = 0.55f;
        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", c);
        m.color = c;
        return m;
    }

    static void SetGlowAlpha(Material m, float a)
    {
        if (m == null) return;
        if (m.HasProperty("_BaseColor"))
        {
            var c = m.GetColor("_BaseColor"); c.a = a; m.SetColor("_BaseColor", c);
        }
        var mc = m.color; mc.a = a; m.color = mc;
    }

    // ==================================================================
    // ============ HIT-STOP ============================================
    // ==================================================================

    /// <summary>Jeda dramatis singkat. Aman dipanggil berkali-kali.</summary>
    public void HitStop(float seconds, float scale = 0.08f)
    {
        if (!Application.isPlaying) return;
        if (HitStopActive) return;
        StartCoroutine(HitStopRoutine(Mathf.Clamp(seconds, 0.01f, 0.25f), Mathf.Clamp01(scale)));
    }

    IEnumerator HitStopRoutine(float seconds, float scale)
    {
        HitStopActive = true;
        float prev = Time.timeScale;
        Time.timeScale = scale;
        yield return new WaitForSecondsRealtime(seconds);
        // Jangan timpa kalau sementara itu ada menu yang sengaja mem-pause game.
        if (Mathf.Approximately(Time.timeScale, scale)) Time.timeScale = Mathf.Approximately(prev, 0f) ? 1f : prev;
        HitStopActive = false;
    }

    // ==================================================================
    // ============ KAMERA & MATERIAL ===================================
    // ==================================================================

    void SetupCamera()
    {
        var cam = Camera.main;
        if (cam == null) return;

        cam.fieldOfView = Mathf.Clamp(cameraFov, 5f, 120f);

        float totalH = height * cellHeight;
        Vector3 basePos = transform.position;
        float aimY = totalH * Mathf.Clamp01(cameraAimHeight);
        Vector3 target = new Vector3(basePos.x, basePos.y + aimY, basePos.z);

        float halfH = totalH / 2f + flangeThickness;
        float halfW = _radius + flangeMargin;

        float tanV = Mathf.Tan(cam.fieldOfView * 0.5f * Mathf.Deg2Rad);
        float aspect = Mathf.Max(0.0001f, cam.aspect);
        float tanH = tanV * aspect;

        float distForHeight = halfH / Mathf.Max(0.0001f, tanV);
        float distForWidth = halfW / Mathf.Max(0.0001f, tanH);
        float dist = Mathf.Max(distForHeight, distForWidth) * Mathf.Max(0.1f, cameraZoomOut);

        float rad = cameraTilt * Mathf.Deg2Rad;
        Vector3 offset = new Vector3(0f, Mathf.Sin(rad) * dist, -Mathf.Cos(rad) * dist);
        cam.transform.position = target + offset;
        cam.transform.LookAt(target);

        // Titik acuan getaran harus ikut diperbarui.
        _camBase = cam.transform.position;
        _camBaseSet = true;
    }

    void BuildPalette()
    {
        if (palette == null || palette.Length == 0)
            palette = new Color[]
            {
                new Color(0.95f, 0.30f, 0.30f),
                new Color(0.30f, 0.65f, 0.95f),
                new Color(0.40f, 0.85f, 0.45f),
                new Color(0.98f, 0.80f, 0.25f),
                new Color(0.70f, 0.45f, 0.90f),
            };

        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");

        _mats = new Material[palette.Length];
        for (int i = 0; i < palette.Length; i++)
        {
            var m = new Material(shader);
            if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", palette[i]);
            m.color = palette[i];

            // Sedikit emisi supaya papan tidak terasa datar. Dulu HANYA kubus SEKARAT
            // yang punya emisi, jadi blok hidup justru terlihat lebih kusam.
            if (blockEmission > 0f && m.HasProperty("_EmissionColor"))
            {
                m.EnableKeyword("_EMISSION");
                m.SetColor("_EmissionColor", palette[i] * blockEmission);
            }
            if (m.HasProperty("_Smoothness")) m.SetFloat("_Smoothness", 0.42f);

            _mats[i] = m;
            _ownedMats.Add(m);
        }
    }

    void Paint(GameObject go, Color col)
    {
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);
        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", col);
        m.color = col;
        _ownedMats.Add(m);

        var rend = go.GetComponent<MeshRenderer>();
        rend.sharedMaterial = m;
        if (disableShadows) DisableShadows(rend);
        var cc = go.GetComponent<Collider>();
        if (cc != null) Kill(cc);
    }

    // ===== BAYANGAN (SHADOW) =====
    void DisableShadows(Renderer r)
    {
        if (r == null) return;
        r.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        r.receiveShadows = false;
    }

    void DisableLightShadows()
    {
        if (!disableSceneLightShadows) return;
#if UNITY_2022_2_OR_NEWER
        var lights = FindObjectsByType<Light>(FindObjectsSortMode.None);
#else
        var lights = FindObjectsOfType<Light>();
#endif
        foreach (var l in lights) if (l != null) l.shadows = LightShadows.None;
    }

    // ==================================================================
    // ============ ISI PAPAN AWAL ======================================
    // ==================================================================

    void DemoFill()
    {
        for (int c = 0; c < columns; c++) _core.Grid[c, 0] = c % numColors;
        for (int c = 0; c < columns; c += 2) _core.Grid[c, 1] = (c + 1) % numColors;
        for (int r = 0; r < 4; r++) _core.Grid[3, r] = 2;
    }

    void StartingFill()
    {
        if (numColors <= 0) return;

        var rng = startSeed != 0 ? new System.Random(startSeed) : new System.Random();

        for (int c = 0; c < columns; c++)
            for (int r = 0; r < height; r++)
                _core.Grid[c, r] = -1;

        int pattern = rng.Next(7);
        float chance = Mathf.Clamp01(startFillChance);

        for (int c = 0; c < columns; c++)
        {
            for (int r = 0; r < height; r++)
            {
                bool fill = false;
                switch (pattern)
                {
                    case 0:
                        fill = rng.NextDouble() <= chance;
                        break;
                    case 1:
                        fill = (c % 2 == 0) && rng.NextDouble() <= 0.85;
                        break;
                    case 2:
                        fill = (r % 2 == 0) && rng.NextDouble() <= 0.85;
                        break;
                    case 3:
                        fill = false;
                        break;
                    case 4:
                        fill = ((c + r) % 3 == 0);
                        break;
                    case 5:
                    {
                        float wave = (Mathf.Sin((float)c / columns * Mathf.PI * 4f) * 0.5f + 0.5f) * (height - 1);
                        fill = Mathf.Abs(r - wave) <= 1.2f;
                        break;
                    }
                    default:
                        fill = false;
                        break;
                }
                if (fill)
                    _core.Grid[c, r] = startRandomColors ? rng.Next(numColors) : (c % numColors);
            }
        }

        if (pattern == 6) FillClusters(rng);
        else if (pattern == 3) FillDiagonalPairs(rng);

        // Anti auto-clear: jangan pernah mulai dengan baris/kolom yang sudah penuh.
        for (int r = 0; r < height; r++)
        {
            bool full = true;
            for (int c = 0; c < columns; c++) if (_core.Grid[c, r] == -1) { full = false; break; }
            if (full) _core.Grid[rng.Next(columns), r] = -1;
        }
        for (int c = 0; c < columns; c++)
        {
            bool full = true;
            for (int r = 0; r < height; r++) if (_core.Grid[c, r] == -1) { full = false; break; }
            if (full) _core.Grid[c, rng.Next(height)] = -1;
        }

        // Anti mati-instan: buka sel sampai ada potongan tray yang muat.
        int guard = 0;
        int maxSteps = columns * height + 1;
        while (!AnyTrayFits() && guard++ < maxSteps)
        {
            _core.Grid[rng.Next(columns), rng.Next(height)] = -1;
        }
    }

    void FillDiagonalPairs(System.Random rng)
    {
        float chance = Mathf.Clamp01(startFillChance);
        for (int c = 0; c < columns; c++)
        {
            for (int r = 0; r < height - 1; r++)
            {
                if (_core.Grid[c, r] != -1) continue;
                if (rng.NextDouble() > chance * 0.6) continue;
                int c2 = _core.Wrap(c + 1);
                if (_core.Grid[c2, r + 1] != -1) continue;
                int color = startRandomColors ? rng.Next(numColors) : (c % numColors);
                _core.Grid[c, r] = color;
                _core.Grid[c2, r + 1] = color;
            }
        }
    }

    void FillClusters(System.Random rng)
    {
        int blobs = Mathf.Max(3, (columns * height) / 20);
        for (int b = 0; b < blobs; b++)
        {
            int cc = rng.Next(columns);
            int rr = rng.Next(height);
            int color = startRandomColors ? rng.Next(numColors) : (cc % numColors);
            int size = 3 + rng.Next(5);
            for (int s = 0; s < size; s++)
            {
                int c = _core.Wrap(cc + rng.Next(3) - 1);
                int r = Mathf.Clamp(rr + rng.Next(3) - 1, 0, height - 1);
                _core.Grid[c, r] = color;
            }
        }
    }

    bool AnyTrayFits()
    {
        if (_core == null || _core.Tray == null) return true;
        foreach (var p in _core.Tray)
            if (p != null && !p.Used && _core.CanPlaceAnywhere(p)) return true;
        return false;
    }
}
