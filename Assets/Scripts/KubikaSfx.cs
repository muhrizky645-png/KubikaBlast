using UnityEngine;

/// <summary>
/// Procedural sound effects untuk Kubika Blast.
/// Semua SFX di-generate lewat kode (TANPA file audio).
///
/// >>> LANGSUNG JALAN TANPA SETTING UNITY <<<
/// Cukup taruh file ini di dalam folder "Assets" project Unity-mu
/// (mis. Assets/Scripts/KubikaSfx.cs). Unity otomatis compile,
/// dan [RuntimeInitializeOnLoadMethod] otomatis membuat GameObject SFX
/// saat game Play -- tidak perlu drag component atau setting apa pun.
///
/// Panggil dari mana saja lewat:
///   KubikaSfx.Instance.PlayPlace();
///   KubikaSfx.Instance.PlayClear();
///   KubikaSfx.Instance.PlayCombo(comboCount);
///   KubikaSfx.Instance.PlayLevelUp();
///   KubikaSfx.Instance.PlayGameOver();
///   KubikaSfx.Instance.PlayClick();
///   KubikaSfx.Instance.PlayInvalid();
/// </summary>
public class KubikaSfx : MonoBehaviour
{
    public static KubikaSfx Instance { get; private set; }

    [Range(0f, 1f)] public float masterVolume = 0.7f;

    const int SampleRate = 44100;

    AudioSource _src;
    AudioClip _place, _clear, _combo, _levelUp, _gameOver, _click, _invalid;

    // Auto-buat GameObject SFX saat game mulai (tanpa perlu setting scene).
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    static void AutoBootstrap()
    {
        if (Instance != null) return;
        var go = new GameObject("KubikaSfx (auto)");
        go.AddComponent<KubikaSfx>();
    }

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);

        _src = gameObject.GetComponent<AudioSource>();
        if (_src == null) _src = gameObject.AddComponent<AudioSource>();
        _src.playOnAwake = false;
        _src.spatialBlend = 0f; // 2D

        BuildClips();
    }

    void BuildClips()
    {
        // Taruh blok: "tock" pendek (tri rendah + klik noise)
        _place = MakeClip("sfx_place", 0.12f, t =>
        {
            float env = Mathf.Exp(-t * 35f);
            float body = Tri(220f, t) * 0.6f;
            float click = (Random.value * 2f - 1f) * Mathf.Exp(-t * 130f) * 0.35f;
            return (body + click) * env;
        });

        // Baris hancur: chime naik yang cerah
        _clear = MakeClip("sfx_clear", 0.35f, t =>
        {
            float f = Mathf.Lerp(500f, 1000f, t / 0.35f);
            float env = Mathf.Exp(-t * 7f);
            return (Sine(f, t) * 0.55f + Sine(f * 2f, t) * 0.2f + Sine(f * 3f, t) * 0.1f) * env;
        });

        // Combo: dua blip cepat menaik
        _combo = MakeClip("sfx_combo", 0.22f, t =>
        {
            float[] f = { 660f, 990f };
            return Seq(t, f, 0.11f, (freq, lt) => Sine(freq, lt) * Mathf.Exp(-lt * 18f)) * 0.6f;
        });

        // Naik level: arpeggio 4 nada (C-E-G-C oktaf)
        _levelUp = MakeClip("sfx_levelup", 0.40f, t =>
        {
            float[] f = { 523f, 659f, 784f, 1047f };
            return Seq(t, f, 0.09f, (freq, lt) =>
                (Sine(freq, lt) * 0.6f + Tri(freq * 2f, lt) * 0.15f) * Mathf.Exp(-lt * 12f)) * 0.7f;
        });

        // Game over: turun sedih 4 nada (tri + sedikit square)
        _gameOver = MakeClip("sfx_gameover", 0.85f, t =>
        {
            float[] f = { 440f, 392f, 330f, 262f };
            return Seq(t, f, 0.20f, (freq, lt) =>
                (Tri(freq, lt) * 0.5f + Square(freq, lt) * 0.12f) * Mathf.Exp(-lt * 6f)) * 0.6f;
        });

        // Klik UI: blip tinggi sangat pendek
        _click = MakeClip("sfx_click", 0.06f, t =>
        {
            float env = Mathf.Exp(-t * 60f);
            return Sine(1200f, t) * env * 0.5f;
        });

        // Gerakan tak valid: buzz rendah bergetar
        _invalid = MakeClip("sfx_invalid", 0.16f, t =>
        {
            float env = Mathf.Exp(-t * 22f);
            float gate = (Mathf.Floor(t * 80f) % 2f == 0f) ? 1f : 0.3f;
            return Square(150f, t) * env * gate * 0.5f;
        });
    }

    // ---------- Public API ----------
    public void PlayPlace()          => Play(_place, 0.9f);
    public void PlayClear()          => Play(_clear, 1f);
    public void PlayCombo(int combo) => Play(_combo, 1f, Mathf.Pow(1.05946f, Mathf.Clamp(combo, 0, 12)));
    public void PlayLevelUp()        => Play(_levelUp, 1f);
    public void PlayGameOver()       => Play(_gameOver, 1f);
    public void PlayClick()          => Play(_click, 0.7f);
    public void PlayInvalid()        => Play(_invalid, 0.8f);

    void Play(AudioClip clip, float vol, float pitch = 1f)
    {
        if (clip == null || _src == null) return;
        _src.pitch = pitch;
        _src.PlayOneShot(clip, vol * masterVolume);
    }

    // ---------- Synth core ----------
    AudioClip MakeClip(string name, float duration, System.Func<float, float> gen)
    {
        int count = Mathf.CeilToInt(duration * SampleRate);
        var data = new float[count];
        for (int i = 0; i < count; i++)
        {
            float t = (float)i / SampleRate;
            // fade-out ~3 ms di ujung supaya tidak ada "klik"
            float tail = Mathf.Min(1f, (count - i) / (0.003f * SampleRate));
            data[i] = Mathf.Clamp(gen(t) * tail, -1f, 1f);
        }
        var clip = AudioClip.Create(name, count, 1, SampleRate, false);
        clip.SetData(data, 0);
        return clip;
    }

    // Urutkan beberapa nada dalam satu clip.
    static float Seq(float t, float[] freqs, float noteDur, System.Func<float, float, float> voice)
    {
        int idx = Mathf.FloorToInt(t / noteDur);
        if (idx < 0 || idx >= freqs.Length) return 0f;
        float localT = t - idx * noteDur;
        return voice(freqs[idx], localT);
    }

    // Oscillator dasar
    static float Sine(float f, float t)   => Mathf.Sin(2f * Mathf.PI * f * t);
    static float Square(float f, float t) => Mathf.Sign(Sine(f, t));
    static float Tri(float f, float t)    => 2f * Mathf.Abs(2f * (t * f - Mathf.Floor(t * f + 0.5f))) - 1f;
    static float Saw(float f, float t)    { float p = t * f; return 2f * (p - Mathf.Floor(p + 0.5f)); }
}
