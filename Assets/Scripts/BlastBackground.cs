using UnityEngine;
using KubikaBlast;

/// <summary>
/// Background dinamis KUBIKA BLAST: gradient warna + gelembung mengambang.
/// Warna berganti HALUS tiap NAIK LEVEL. Bootstrap OTOMATIS (tak perlu ditempel
/// manual ke GameObject) lewat RuntimeInitializeOnLoadMethod, jadi cukup ada file
/// ini di project. Berjalan di belakang tabung 3D.
///
/// TEMA "CERAH TAPI KALEM" — aturan yang dipegang:
///  1. TIDAK ADA channel warna yang menyentuh 0.90+. Percobaan sebelumnya pakai
///     0.99/1.00 dan hasilnya silau, terutama bagian bawah layar yang jadi
///     genangan cahaya tepat di area tray (paling sering dilihat pemain).
///  2. Saturasi ditahan rendah-sedang (pastel berdebu), bukan warna jenuh.
///     Warna jenuh + luminance tinggi = mata cepat lelah.
///  3. Jarak terang atas vs bawah dipersempit. Gradient dengan kontras besar
///     memaksa mata terus beradaptasi.
///  4. Bagian ATAS tetap lebih pekat daripada bawah, karena teks HUD (LEVEL,
///     skor) duduk di atas tanpa kartu di belakangnya — kalau atasnya pucat,
///     teks putihnya hilang.
///  Level 1 sengaja disamakan nuansanya dengan background menu supaya
///  perpindahan menu -> gameplay terasa menyambung.
/// </summary>
public class BlastBackground : MonoBehaviour
{
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void Bootstrap()
    {
        if (FindFirstObjectByType<BlastBackground>() != null) return;
        var go = new GameObject("BlastBackground");
        go.AddComponent<BlastBackground>();
    }

    [Header("Reaksi ke permainan")]
    public bool enableBubbles = true;
    public bool reactToClears = true;
    [Range(0f, 1f)] public float bloomStrength = 0.55f;

    // Pasangan warna gradient (atas & bawah) per level; berputar kalau level melebihi jumlah.
    // Atas: pastel sedang (0.50-0.84). Bawah: netral hangat lembut (0.74-0.88).
    static readonly Color[] TopColors =
    {
        new Color(0.52f, 0.68f, 0.80f),   // 1. biru kabut
        new Color(0.64f, 0.62f, 0.80f),   // 2. lilac lembut
        new Color(0.50f, 0.72f, 0.70f),   // 3. sage teal
        new Color(0.84f, 0.68f, 0.58f),   // 4. terracotta lembut
        new Color(0.58f, 0.74f, 0.60f),   // 5. hijau daun muda
        new Color(0.84f, 0.66f, 0.68f),   // 6. rose berdebu
    };
    static readonly Color[] BottomColors =
    {
        new Color(0.86f, 0.84f, 0.76f),   // 1. pasir lembut
        new Color(0.86f, 0.82f, 0.85f),   // 2. blush kelabu
        new Color(0.82f, 0.86f, 0.78f),   // 3. sage pucat
        new Color(0.87f, 0.83f, 0.74f),   // 4. linen hangat
        new Color(0.80f, 0.86f, 0.80f),   // 5. mint kelabu
        new Color(0.84f, 0.82f, 0.88f),   // 6. lavender kelabu
    };

    // Gelembung: di atas background terang, putih tidak terlihat. Dipakai tint
    // biru-kelabu supaya gelembungnya terbaca sebagai bayangan lembut, bukan
    // titik terang yang menarik perhatian.
    static readonly Color BubbleTint = new Color(0.28f, 0.34f, 0.48f);
    const float BUBBLE_ALPHA = 0.20f;

    BlastGame _game;
    BlastGame _hooked;
    Camera _cam;
    Material _mat;
    Texture2D _grad;
    Texture2D _dot;
    ParticleSystem _ps;
    float _baseEmission = 9f;

    int _lastLevel = int.MinValue;
    Color _curTop, _curBot, _tgtTop, _tgtBot;
    float _bloom;          // kilau sesaat setelah clear
    bool _ready;

    void Start()
    {
        _game = FindFirstObjectByType<BlastGame>();
        _curTop = _tgtTop = TopColors[0];
        _curBot = _tgtBot = BottomColors[0];
        EnsureRig();
        ApplyNow();
    }

    void OnDestroy() { Unhook(); }

    void Update()
    {
        if (!_ready) { EnsureRig(); if (!_ready) return; }
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_game != null && !ReferenceEquals(_game, _hooked)) Hook(_game);

        var core = (_game != null) ? _game.Core : null;
        int level = (core != null) ? core.Level : 1;
        if (level != _lastLevel)
        {
            _lastLevel = level;
            int idx = ((level - 1) % TopColors.Length + TopColors.Length) % TopColors.Length;
            _tgtTop = TopColors[idx];
            _tgtBot = BottomColors[idx];
        }

        bool dirty = false;

        if (Far(_curTop, _tgtTop) || Far(_curBot, _tgtBot))
        {
            float k = Time.deltaTime * 2f;
            _curTop = Color.Lerp(_curTop, _tgtTop, k);
            _curBot = Color.Lerp(_curBot, _tgtBot, k);
            dirty = true;
        }

        if (_bloom > 0.001f)
        {
            _bloom = Mathf.MoveTowards(_bloom, 0f, Time.unscaledDeltaTime * 1.7f);
            dirty = true;
        }

        if (dirty) ApplyNow();

        // Gelembung memancar lebih cepat selama combo — papan terasa "hidup".
        if (_ps != null && core != null)
        {
            var em = _ps.emission;
            float boost = 1f + Mathf.Clamp01((core.Combo - 1) / 6f) * 1.6f;
            em.rateOverTime = _baseEmission * boost;
        }
    }

    void Hook(BlastGame g)
    {
        Unhook();
        _hooked = g;
        g.OnCleared += HandleCleared;
    }

    void Unhook()
    {
        if (_hooked == null) return;
        _hooked.OnCleared -= HandleCleared;
        _hooked = null;
    }

    void HandleCleared(BlastCore.ClearInfo info)
    {
        if (!reactToClears) return;
        float combo = Mathf.Clamp01((info.Combo - 1) / 7f);
        _bloom = Mathf.Min(1f, _bloom + 0.45f + combo * 0.55f);

        if (_ps != null)
        {
            int burst = Mathf.Clamp((info.Cells != null ? info.Cells.Count : 0) / 3, 2, 14);
            _ps.Emit(burst);
        }
    }

    static bool Far(Color a, Color b)
    {
        return Mathf.Abs(a.r - b.r) + Mathf.Abs(a.g - b.g) + Mathf.Abs(a.b - b.b) > 0.006f;
    }

    void EnsureRig()
    {
        _cam = Camera.main;
        if (_cam == null) return;
        _cam.clearFlags = CameraClearFlags.SolidColor;

        float far = Mathf.Max(50f, _cam.farClipPlane);
        float gdist = Mathf.Clamp(far * 0.5f, 20f, 500f);

        // ---- Quad gradient (anak kamera, jauh di belakang, menghadap kamera) ----
        if (_mat == null)
        {
            _grad = new Texture2D(4, 128, TextureFormat.RGBA32, false);
            _grad.wrapMode = TextureWrapMode.Clamp;
            _grad.filterMode = FilterMode.Bilinear;

            var shader = Shader.Find("Universal Render Pipeline/Unlit");
            if (shader == null) shader = Shader.Find("Unlit/Texture");
            if (shader == null) shader = Shader.Find("Sprites/Default");
            _mat = new Material(shader);

            var q = GameObject.CreatePrimitive(PrimitiveType.Quad);
            q.name = "BgGradient";
            var qcol = q.GetComponent<Collider>();
            if (qcol != null) Destroy(qcol);
            var qt = q.transform;
            qt.SetParent(_cam.transform, false);

            float gh = 2f * gdist * Mathf.Tan(_cam.fieldOfView * 0.5f * Mathf.Deg2Rad) * 1.2f;
            float gw = gh * Mathf.Max(1f, _cam.aspect) * 1.2f;
            qt.localPosition = new Vector3(0f, 0f, gdist);
            qt.localRotation = Quaternion.identity;
            qt.localScale = new Vector3(gw, gh, 1f);

            var mr = q.GetComponent<MeshRenderer>();
            mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            mr.receiveShadows = false;
            mr.sharedMaterial = _mat;
        }

        // ---- Gelembung mengambang: DIHIDUPKAN lagi ----
        // Dulu terkunci di balik `if (false)`. Komentar aslinya menjelaskan cara
        // menghidupkannya dengan aman: ganti gerbangnya DAN tambahkan vel.z.
        // Tanpa vel.z, velocityOverLifetime punya kurva X & Y tapi Z-nya belum
        // di-set, dan itulah kenapa sistem ini dulu dimatikan.
        if (enableBubbles && _ps == null)
        {
            float pdist = gdist * 0.82f;
            float ph = 2f * pdist * Mathf.Tan(_cam.fieldOfView * 0.5f * Mathf.Deg2Rad);
            float pw = ph * Mathf.Max(1f, _cam.aspect);

            var pgo = new GameObject("BgBubbles");
            pgo.transform.SetParent(_cam.transform, false);
            pgo.transform.localPosition = new Vector3(0f, -ph * 0.5f, pdist);
            pgo.transform.localRotation = Quaternion.identity;

            _ps = pgo.AddComponent<ParticleSystem>();
            _ps.Stop();

            var main = _ps.main;
            main.loop = true;
            main.startLifetime = 8f;
            main.startSpeed = 0f;
            main.startSize = new ParticleSystem.MinMaxCurve(ph * 0.02f, ph * 0.06f);
            main.maxParticles = 120;
            main.simulationSpace = ParticleSystemSimulationSpace.Local;
            main.startColor = new Color(BubbleTint.r, BubbleTint.g, BubbleTint.b, BUBBLE_ALPHA);

            var emission = _ps.emission;
            emission.rateOverTime = _baseEmission;

            var shape = _ps.shape;
            shape.shapeType = ParticleSystemShapeType.Box;
            shape.scale = new Vector3(pw, 0.1f, 0.1f);

            var vel = _ps.velocityOverLifetime;
            vel.enabled = true;
            vel.space = ParticleSystemSimulationSpace.Local;
            vel.y = new ParticleSystem.MinMaxCurve(ph * 0.06f, ph * 0.12f);
            vel.x = new ParticleSystem.MinMaxCurve(-ph * 0.01f, ph * 0.01f);
            vel.z = new ParticleSystem.MinMaxCurve(0f, 0f);   // <- baris yang dulu hilang

            var colOverLife = _ps.colorOverLifetime;
            colOverLife.enabled = true;
            var grad = new Gradient();
            grad.SetKeys(
                new[] { new GradientColorKey(Color.white, 0f), new GradientColorKey(Color.white, 1f) },
                new[]
                {
                    new GradientAlphaKey(0f, 0f),
                    new GradientAlphaKey(0.5f, 0.25f),
                    new GradientAlphaKey(0.5f, 0.75f),
                    new GradientAlphaKey(0f, 1f),
                });
            colOverLife.color = grad;

            var psr = pgo.GetComponent<ParticleSystemRenderer>();
            var pshader = Shader.Find("Sprites/Default");
            if (pshader == null) pshader = Shader.Find("Universal Render Pipeline/Particles/Unlit");
            var pmat = new Material(pshader);
            pmat.mainTexture = SoftDot();
            psr.material = pmat;
            psr.sortingOrder = -10;

            _ps.Play();
        }

        _ready = _mat != null;
    }

    void ApplyNow()
    {
        // Kilau setelah clear. Targetnya BUKAN putih murni — kilatan ke putih di
        // atas background terang terasa seperti lampu blitz. Cukup ditarik sedikit
        // ke krem pucat, dan bobotnya dikecilkan supaya terasa sebagai "denyut",
        // bukan silau.
        float b = _bloom * Mathf.Clamp01(bloomStrength);
        Color top = Color.Lerp(_curTop, new Color(0.92f, 0.91f, 0.86f), b * 0.30f);
        Color bot = Color.Lerp(_curBot, new Color(0.92f, 0.91f, 0.88f), b * 0.16f);
        Apply(top, bot);
    }

    void Apply(Color top, Color bot)
    {
        if (_grad != null)
        {
            int h = _grad.height, w = _grad.width;
            var px = new Color[w * h];
            for (int y = 0; y < h; y++)
            {
                float t = (float)y / (h - 1);
                Color c = Color.Lerp(bot, top, t);
                for (int x = 0; x < w; x++) px[y * w + x] = c;
            }
            _grad.SetPixels(px);
            _grad.Apply();
            if (_mat != null)
            {
                if (_mat.HasProperty("_BaseMap")) _mat.SetTexture("_BaseMap", _grad);
                _mat.mainTexture = _grad;
            }
        }
        if (_cam != null) _cam.backgroundColor = bot;
        if (_ps != null)
        {
            var main = _ps.main;
            Color pc = Color.Lerp(top, BubbleTint, 0.55f);
            pc.a = BUBBLE_ALPHA;
            main.startColor = pc;
        }
    }

    Texture2D SoftDot()
    {
        if (_dot != null) return _dot;
        int s = 64;
        _dot = new Texture2D(s, s, TextureFormat.RGBA32, false);
        _dot.wrapMode = TextureWrapMode.Clamp;
        float c = (s - 1) * 0.5f;
        var px = new Color32[s * s];
        for (int y = 0; y < s; y++)
            for (int x = 0; x < s; x++)
            {
                float d = Mathf.Sqrt((x - c) * (x - c) + (y - c) * (y - c)) / c;
                float a = Mathf.Clamp01(1f - d);
                a = a * a;
                px[y * s + x] = new Color32(255, 255, 255, (byte)(a * 255f));
            }
        _dot.SetPixels32(px);
        _dot.Apply();
        return _dot;
    }
}
