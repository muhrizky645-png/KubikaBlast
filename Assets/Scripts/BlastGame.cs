using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using KubikaBlast;

/// <summary>
/// Render TABUNG 3D gaya gulungan kabel + kubus dari BlastCore.
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
    public float clearFxDuration = 0.4f;
    public float clearStepDelay = 0.06f;

    [Header("Debug")]
    public bool demoFill = false;

    [Header("Bayangan (shadow)")]
    // Matikan cast & receive shadow di semua blok/drum/flange/axle.
    public bool disableShadows = true;
    // Matikan juga shadow di semua Light pada scene (mis. Directional Light).
    public bool disableSceneLightShadows = true;

    [Header("Kecerdasan potongan (smart drop)")]
    // 0 = potongan benar-benar ACAK (asal muat di papan).
    // Makin tinggi = makin sering sengaja memberi potongan yang bisa langsung meng-clear.
    // Turunkan (mis. 0.15) kalau mau terasa lebih acak; naikkan kalau mau lebih sering clear.
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
    Mesh _mesh;
    Material[] _mats;
    bool _cameraFramed;

    // ===== Hook publik untuk BlastInput =====
    public BlastCore Core => _core;
    public float Radius => _radius;
    public Mesh CellMesh => _mesh;

    void Start()
    {
        Rebuild();
    }

    [ContextMenu("Rebuild Tabung")]
    public void Rebuild()
    {
        for (int i = transform.childCount - 1; i >= 0; i--)
        {
            var ch = transform.GetChild(i).gameObject;
            if (Application.isPlaying) Destroy(ch);
            else DestroyImmediate(ch);
        }

        _radius = columns * cellWidth / (2f * Mathf.PI);
        _core = new BlastCore(columns, height, numColors);
        _core.ClearBias = clearBias;
        _mesh = RoundedCube.Shared();

        BuildPalette();
        BuildReel();

        if (autoCamera && !_cameraFramed) { SetupCamera(); _cameraFramed = true; }

        if (disableShadows) DisableLightShadows();

        if (demoFill) DemoFill();
        else if (startWithBlocks) StartingFill();
        // SMART DROP: setelah papan terisi, carve ulang tray dari CELAH NYATA di papan
        // supaya tiap potongan dijamin punya slot pas (solusi tersembunyi).
        _core.RegenerateTray();
        RenderGrid();
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

    public bool TryPlace(int trayIndex, int col, int row)
    {
        if (_core == null) return false;
        bool ok = _core.PlacePiece(trayIndex, col, row);
        if (ok)
        {
            if (enableClearFx) SpawnClearEffect(_core.LastClear);
            RenderGrid();
        }
        return ok;
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

    void SpawnClearEffect(BlastCore.ClearInfo clear)
    {
        if (!Application.isPlaying) return;
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
        var mrs = new List<MeshRenderer>(n);
        var mats = new List<Material>(n);
        for (int k = 0; k < order.Count; k++)
        {
            int i = order[k];
            var go = new GameObject("Fx");
            go.transform.SetParent(transform, false);
            go.transform.localPosition = CellToWorld(cc[i], rr[i]);
            go.transform.localRotation = CellRotation(cc[i]);
            go.transform.localScale = new Vector3(cellWidth * gap, cellHeight * gap, blockDepth);

            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _mesh;
            var mr = go.AddComponent<MeshRenderer>();
            Color baseC = (palette != null && colr[i] >= 0 && colr[i] < palette.Length)
                          ? palette[colr[i]] : Color.white;
            mr.material = MakeFxMaterial(baseC);
            if (disableShadows) DisableShadows(mr);

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
        Vector3 outward = go.transform.localRotation * Vector3.forward;
        Color c0 = mat.HasProperty("_BaseColor") ? mat.GetColor("_BaseColor") : mat.color;

        while (t < dur)
        {
            if (go == null) yield break;
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
        if (m.HasProperty("_EmissionColor")) { m.EnableKeyword("_EMISSION"); m.SetColor("_EmissionColor", col * 0.6f); }
        m.color = c;
        return m;
    }

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
        var rend = go.GetComponent<MeshRenderer>();
        rend.sharedMaterial = m;
        if (disableShadows) DisableShadows(rend);
        var cc = go.GetComponent<Collider>();
        if (cc != null)
        {
            if (Application.isPlaying) Destroy(cc);
            else DestroyImmediate(cc);
        }
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
