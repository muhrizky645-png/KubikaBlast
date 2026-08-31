using System.Collections;
using UnityEngine;
using KubikaBlast; // untuk membaca status BlastCore

/// <summary>
/// Procedural AUDIO untuk Kubika Blast: SFX gaya Block Blast + background music
/// + suara pujian (Good/Awesome/Amazing...). Semua di-generate lewat kode.
///
/// >>> LANGSUNG BUNYI, TANPA EDIT KODE GAME & TANPA SETTING UNITY <<<
/// Taruh file ini di folder "Assets" lalu tekan Play.
///
/// SUARA PUJIAN:
///   - Kalau kamu menaruh file suara di Assets/Resources/Voice/ (good, awesome,
///     amazing, fantastic, incredible, unstoppable, legendary; .mp3/.wav/.ogg)
///     -> otomatis dipakai suara ASLI itu.
///   - Kalau tidak ada -> otomatis pakai sting musik yang naik tiap combo.
///
/// STREAK: tingkat pujian pakai penghitung streak berbasis WAKTU (praiseWindow),
/// bukan Combo bawaan game yang cepat reset. Selama clear berikutnya masih dalam
/// praiseWindow detik, tingkatnya terus naik.
/// </summary>
public class KubikaSfx : MonoBehaviour
{
    public static KubikaSfx Instance { get; private set; }

    [Header("Volume")]
    [Range(0f, 1f)] public float sfxVolume = 0.8f;
    [Range(0f, 1f)] public float musicVolume = 0.32f;
    public bool musicEnabled = true;

    [Header("Pujian (announcer)")]
    [Tooltip("Berapa detik jeda maksimum antar-clear agar streak pujian terus naik.")]
    [Range(1f, 30f)] public float praiseWindow = 15f;

    const int SampleRate = 44100;
    const int SPARK_STEPS = 31;

    AudioSource _sfx, _sparkSrc, _melodic, _voiceSrc, _music;

    AudioClip _place, _levelUp, _gameOver, _click, _invalid, _praise, _music_clip;
    AudioClip _hammer, _bomb, _hammerTick, _gem;
    AudioClip[] _sparks;

    BlastGame _game;
    BlastCore _lastCore;
    int _pScore, _pLines, _pLevel;
    bool _pGameOver;

    int _streak;
    float _lastClearTime = -999f;

    static readonly string[] VoiceKeys =
        { "good", "awesome", "amazing", "fantastic", "incredible", "unstoppable", "legendary" };

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

        _sfx = NewSource();
        _sparkSrc = NewSource();
        _melodic = NewSource();
        _voiceSrc = NewSource();
        _music = NewSource();
        _music.loop = true;

        BuildClips();

        _music.clip = _music_clip;
        _music.volume = musicVolume;
        if (musicEnabled) _music.Play();
    }

    AudioSource NewSource()
    {
        var s = gameObject.AddComponent<AudioSource>();
        s.playOnAwake = false;
        s.spatialBlend = 0f;
        return s;
    }

    void Update()
    {
        if (_music != null)
        {
            _music.volume = musicVolume;
            if (musicEnabled && !_music.isPlaying) _music.Play();
            else if (!musicEnabled && _music.isPlaying) _music.Pause();
        }

        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_game == null) return;

        var core = _game.Core;
        if (core == null) return;

        if (!ReferenceEquals(core, _lastCore))
        {
            _lastCore = core;
            _streak = 0;
            _lastClearTime = -999f;
            Prime(core);
            return;
        }

        if (core.Score > _pScore)
        {
            PlayPlace();

            if (core.LinesCleared > _pLines)
            {
                // Streak berbasis waktu: lanjut naik bila masih dalam praiseWindow.
                if (Time.time - _lastClearTime <= praiseWindow) _streak++;
                else _streak = 1;
                _lastClearTime = Time.time;

                int cells = (core.LastClear.Cells != null) ? core.LastClear.Cells.Count : 0;
                if (cells <= 0) cells = (core.LinesCleared - _pLines) * Mathf.Max(1, core.Columns);
                StartCoroutine(ClearCascade(cells, _streak));
                // Pujian (teks + suara) kini disetir tunggal oleh KubikaHud agar SINKRON.
                // (dulu suara di sini pakai window/streak terpisah -> bisa beda dgn teks)
            }

            if (core.Level > _pLevel)
                PlayLevelUp();
        }

        if (core.GameOver && !_pGameOver)
            PlayGameOver();

        Prime(core);
    }

    void Prime(BlastCore core)
    {
        _pScore = core.Score;
        _pLines = core.LinesCleared;
        _pLevel = core.Level;
        _pGameOver = core.GameOver;
    }

    public void PlayPraise(int tier)
    {
        int i = Mathf.Clamp(tier - 1, 0, VoiceKeys.Length - 1);
        var voice = Resources.Load<AudioClip>("Voice/" + VoiceKeys[i]);
        if (voice != null)
        {
            _voiceSrc.pitch = 1f;
            _voiceSrc.PlayOneShot(voice, 0.95f * sfxVolume);
            return;
        }
        float pitch = Mathf.Pow(1.05946f, Mathf.Clamp((tier - 1) * 2, 0, 18));
        _voiceSrc.pitch = pitch;
        _voiceSrc.PlayOneShot(_praise, 0.8f * sfxVolume);
    }

    IEnumerator ClearCascade(int cellCount, int tier)
    {
        int n = Mathf.Clamp(cellCount, 1, 24);
        float delay = 0.06f;
        if (_game != null && _game.clearStepDelay > 0f) delay = _game.clearStepDelay;

        // BATAS nada: cegah suara terlalu melengking saat 2-3 baris hancur sekaligus.
        // Dulu nada memanjat oktaf terus (bisa ~4 kHz). Sekarang diplafon.
        const int MAX_STEP = 16;                    // plafon nada (~1.3 oktaf dari dasar)
        int lift = Mathf.Clamp(tier - 1, 0, 3) * 2; // kenaikan per-tier dibatasi
        int[] penta = { 0, 2, 4, 7, 9 };
        var wait = new WaitForSeconds(delay);

        for (int i = 0; i < n; i++)
        {
            // Oktaf hanya berselang 0/1 (tidak memanjat tanpa henti) lalu diplafon.
            int octave = (i / penta.Length) % 2;
            int semi = Mathf.Clamp(octave * 12 + penta[i % penta.Length] + lift, 0, MAX_STEP);
            float vol = Mathf.Lerp(0.85f, 0.45f, (float)i / n);
            _sparkSrc.PlayOneShot(_sparks[semi], vol * sfxVolume);
            yield return wait;
        }

        // Sparkle penutup juga diplafon supaya tidak menusuk.
        int topIndex = Mathf.Clamp(penta[penta.Length - 1] + lift + 4, 0, MAX_STEP);
        _sparkSrc.PlayOneShot(_sparks[topIndex], 0.5f * sfxVolume);
    }

    // ==================================================================
    void BuildClips()
    {
        _place = MakeClip("sfx_place", 0.11f, t =>
        {
            float env = Mathf.Exp(-t * 42f) * (1f - Mathf.Exp(-t * 600f));
            float f = Mathf.Lerp(920f, 430f, Mathf.Clamp01(t / 0.06f));
            float body = Sine(f, t) * 0.7f + Tri(f * 0.5f, t) * 0.15f;
            float click = (Random.value * 2f - 1f) * Mathf.Exp(-t * 300f) * 0.22f;
            return (body + click) * env;
        });

        _sparks = new AudioClip[SPARK_STEPS];
        for (int s = 0; s < SPARK_STEPS; s++)
        {
            float mul = Mathf.Pow(2f, s / 12f);
            float bF = 740f * mul;
            _sparks[s] = MakeClip("sfx_spark_" + s, 0.22f, t =>
            {
                float env = Mathf.Exp(-t * 12f) * (1f - Mathf.Exp(-t * 800f));
                float body = Sine(bF, t) * 0.5f + Sine(bF * 2f, t) * 0.24f
                           + Sine(bF * 3f, t) * 0.10f + Tri(bF, t) * 0.08f;
                float vib = Mathf.Sin(2f * Mathf.PI * 16f * t) * 18f;
                float shimmer = Sine(bF * 4f + vib, t) * 0.07f * Mathf.Exp(-t * 10f);
                return (body + shimmer) * env;
            });
        }

        _praise = MakeClip("sfx_praise", 0.42f, t =>
        {
            float[] f = { 523f, 659f, 784f };
            float arp = Seq(t, f, 0.06f, (freq, lt) =>
                (Sine(freq, lt) * 0.5f + Sine(freq * 2f, lt) * 0.2f) * Mathf.Exp(-lt * 12f));
            float top = Sine(1046f, t) * 0.16f * Mathf.Exp(-t * 6f);
            return arp + top;
        });

        _levelUp = MakeClip("sfx_levelup", 0.55f, t =>
        {
            float[] f = { 523f, 659f, 784f, 1047f };
            return Seq(t, f, 0.11f, (freq, lt) =>
                (Sine(freq, lt) * 0.55f + Sine(freq * 2f, lt) * 0.18f + Tri(freq, lt) * 0.12f)
                * Mathf.Exp(-lt * 9f) * (1f - Mathf.Exp(-lt * 400f))) * 0.75f;
        });

        _gameOver = MakeClip("sfx_gameover", 0.9f, t =>
        {
            float[] f = { 523f, 440f, 349f, 262f };
            return Seq(t, f, 0.22f, (freq, lt) =>
                (Tri(freq, lt) * 0.5f + Sine(freq, lt) * 0.3f + Square(freq, lt) * 0.08f)
                * Mathf.Exp(-lt * 5.5f)) * 0.6f;
        });

        _click = MakeClip("sfx_click", 0.06f, t => Sine(1300f, t) * Mathf.Exp(-t * 60f) * 0.5f);

        _invalid = MakeClip("sfx_invalid", 0.16f, t =>
        {
            float env = Mathf.Exp(-t * 22f);
            float gate = (Mathf.Floor(t * 80f) % 2f == 0f) ? 1f : 0.3f;
            return Square(150f, t) * env * gate * 0.5f;
        });

        // PALU: whoosh -> THUD sub-bass + dentang metalik + kresek pecahan kaca.
        _hammer = MakeClip("sfx_hammer", 0.32f, t =>
        {
            float whoEnv = Mathf.Exp(-t * 26f) * Mathf.Clamp01(t / 0.012f);
            float whoosh = (Random.value * 2f - 1f) * whoEnv * 0.22f;

            float ti = Mathf.Max(0f, t - 0.03f);            // benturan mulai ~0.03s
            float hit = 1f - Mathf.Exp(-ti * 700f);

            float thud = Sine(Mathf.Lerp(240f, 70f, Mathf.Clamp01(ti / 0.06f)), ti) * Mathf.Exp(-ti * 24f) * 0.95f;
            float sub  = Sine(48f, ti) * Mathf.Exp(-ti * 16f) * 0.5f;
            float clank = (Sine(1750f, ti) * 0.35f + Square(2550f, ti) * 0.12f + Sine(3400f, ti) * 0.15f) * Mathf.Exp(-ti * 46f);
            float grain = (Mathf.Floor(ti * 5200f) % 2f == 0f) ? 1f : 0.4f;
            float crackle = (Random.value * 2f - 1f) * Mathf.Exp(-ti * 12f) * 0.3f * grain;

            float mix = whoosh + (thud + sub + clank + crackle) * hit;
            return (float)System.Math.Tanh(mix * 1.1f);        // soft-clip biar tebal, tak harsh
        });

        // PALU (tik per-block): pukulan pendek & tajam untuk hancur satu-per-satu.
        _hammerTick = MakeClip("sfx_hammer_tick", 0.13f, t =>
        {
            float hit = 1f - Mathf.Exp(-t * 900f);
            float tick = (Sine(2600f, t) * 0.5f + Square(3600f, t) * 0.2f) * Mathf.Exp(-t * 70f);
            float thud = Sine(Mathf.Lerp(300f, 120f, Mathf.Clamp01(t / 0.03f)), t) * Mathf.Exp(-t * 38f) * 0.6f;
            float chip = (Random.value * 2f - 1f) * Mathf.Exp(-t * 55f) * 0.28f;
            float mix = (tick + thud + chip) * hit;
            return (float)System.Math.Tanh(mix * 1.15f);
        });

        // BOM: dentuman sub-bass + body ledakan + crackle transien + debris bergema.
        _bomb = MakeClip("sfx_bomb", 0.75f, t =>
        {
            float hit = 1f - Mathf.Exp(-t * 500f);

            float boom = Sine(Mathf.Lerp(150f, 38f, Mathf.Clamp01(t / 0.22f)), t) * Mathf.Exp(-t * 5.5f) * 0.85f;
            float sub  = Sine(30f, t) * Mathf.Exp(-t * 4f) * 0.5f;
            float body = (Random.value * 2f - 1f) * Mathf.Exp(-t * 7f) * 0.55f;
            float crack = (Random.value * 2f - 1f) * Mathf.Exp(-t * 42f) * 0.5f;
            float grain = (Mathf.Floor(t * 3300f) % 2f == 0f) ? 1f : 0.35f;
            float debris = (Random.value * 2f - 1f) * Mathf.Exp(-t * 3.2f) * 0.2f * grain;

            float mix = (boom + sub + body + crack + debris) * hit;
            return (float)System.Math.Tanh(mix * 1.2f);        // soft-clip -> ledakan fat & hangat
        });

        _gem = MakeClip("sfx_gem", 0.34f, t =>
        {
            float[] f = { 784f, 1047f, 1319f };
            float arp = Seq(t, f, 0.07f, (freq, lt) =>
                (Sine(freq, lt) * 0.5f + Sine(freq * 2f, lt) * 0.22f) * Mathf.Exp(-lt * 11f));
            float shimmer = Sine(2093f, t) * 0.12f * Mathf.Exp(-t * 8f);
            return arp + shimmer;
        });

        _music_clip = BuildMusic();
    }

    public void PlayPlace()   => PlayOn(_sfx, _place, 0.9f);
    public void PlayClick()   => PlayOn(_sfx, _click, 0.7f);
    public void PlayInvalid() => PlayOn(_sfx, _invalid, 0.8f);
    public void PlayLevelUp() => PlayOn(_melodic, _levelUp, 1f);
    public void PlayGameOver()=> PlayOn(_melodic, _gameOver, 1f);
    public void PlayHammer()  => PlayOn(_sfx, _hammer, 1f, Random.Range(0.96f, 1.05f));
    public void PlayHammerTick(int step) => PlayOn(_sparkSrc, _hammerTick, 0.9f, Mathf.Min(1.75f, 1f + step * 0.05f) * Random.Range(0.98f, 1.02f));
    public void PlayBomb()    => PlayOn(_sfx, _bomb, 1f, Random.Range(0.9f, 1.0f));
    public void PlayGem()     => PlayOn(_sparkSrc, _gem, 0.9f);

    void PlayOn(AudioSource src, AudioClip clip, float vol, float pitch = 1f)
    {
        if (clip == null || src == null) return;
        src.pitch = pitch;
        src.PlayOneShot(clip, vol * sfxVolume);
    }

    AudioClip BuildMusic()
    {
        float bpm = 96f;
        float beat = 60f / bpm;
        int beatsPerBar = 4, bars = 4;
        int totalBeats = bars * beatsPerBar;
        int count = Mathf.CeilToInt(totalBeats * beat * SampleRate);
        var buf = new float[count];

        int[] barRoot = { 60, 55, 57, 53 };
        bool[] barMinor = { false, false, true, false };

        for (int bar = 0; bar < bars; bar++)
        {
            int root = barRoot[bar];
            int[] triad = barMinor[bar] ? new[] { 0, 3, 7 } : new[] { 0, 4, 7 };
            for (int b = 0; b < beatsPerBar; b++)
            {
                int beatIndex = bar * beatsPerBar + b;
                float tStart = beatIndex * beat;
                if (b == 0 || b == 2)
                    AddNote(buf, tStart, beat * 0.95f, Midi(root - 12), 0.18f, VoiceBass);
                foreach (var d in triad)
                    AddNote(buf, tStart, beat, Midi(root + d), 0.045f, VoicePad);
                for (int e = 0; e < 2; e++)
                {
                    int step = beatIndex * 2 + e;
                    int deg = triad[step % 3];
                    AddNote(buf, tStart + e * beat * 0.5f, beat * 0.5f * 0.95f, Midi(root + 12 + deg), 0.11f, VoicePluck);
                }
            }
        }

        float peak = 0f;
        for (int i = 0; i < count; i++) peak = Mathf.Max(peak, Mathf.Abs(buf[i]));
        if (peak > 0.9f) { float k = 0.9f / peak; for (int i = 0; i < count; i++) buf[i] *= k; }

        var clip = AudioClip.Create("bgm_loop", count, 1, SampleRate, false);
        clip.SetData(buf, 0);
        return clip;
    }

    void AddNote(float[] buf, float startSec, float durSec, float freq, float amp,
                 System.Func<float, float, float, float> voice)
    {
        int start = Mathf.RoundToInt(startSec * SampleRate);
        int len = Mathf.RoundToInt(durSec * SampleRate);
        for (int i = 0; i < len; i++)
        {
            int idx = start + i;
            if (idx < 0 || idx >= buf.Length) continue;
            buf[idx] += voice(freq, (float)i / SampleRate, durSec) * amp;
        }
    }

    static float VoicePluck(float f, float lt, float dur)
    {
        float env = Mathf.Exp(-lt * 7f) * (1f - Mathf.Exp(-lt * 400f));
        return (Sine(f, lt) * 0.7f + Sine(2f * f, lt) * 0.18f + Tri(f, lt) * 0.12f) * env;
    }
    static float VoiceBass(float f, float lt, float dur)
    {
        float env = Mathf.Exp(-lt * 3.2f) * (1f - Mathf.Exp(-lt * 250f));
        return (Sine(f, lt) * 0.8f + Tri(f, lt) * 0.2f) * env;
    }
    static float VoicePad(float f, float lt, float dur)
    {
        float atk = Mathf.Clamp01(lt / 0.12f);
        float rel = Mathf.Clamp01((dur - lt) / 0.18f);
        return (Sine(f, lt) * 0.6f + Sine(2f * f, lt) * 0.15f) * atk * rel;
    }

    AudioClip MakeClip(string name, float duration, System.Func<float, float> gen)
    {
        int count = Mathf.CeilToInt(duration * SampleRate);
        var data = new float[count];
        for (int i = 0; i < count; i++)
        {
            float t = (float)i / SampleRate;
            float tail = Mathf.Min(1f, (count - i) / (0.003f * SampleRate));
            data[i] = Mathf.Clamp(gen(t) * tail, -1f, 1f);
        }
        var clip = AudioClip.Create(name, count, 1, SampleRate, false);
        clip.SetData(data, 0);
        return clip;
    }

    static float Seq(float t, float[] freqs, float noteDur, System.Func<float, float, float> voice)
    {
        int idx = Mathf.FloorToInt(t / noteDur);
        if (idx < 0 || idx >= freqs.Length) return 0f;
        return voice(freqs[idx], t - idx * noteDur);
    }

    static float Midi(int m) => 440f * Mathf.Pow(2f, (m - 69) / 12f);
    static float Sine(float f, float t)   => Mathf.Sin(2f * Mathf.PI * f * t);
    static float Square(float f, float t) => Mathf.Sign(Sine(f, t));
    static float Tri(float f, float t)    => 2f * Mathf.Abs(2f * (t * f - Mathf.Floor(t * f + 0.5f))) - 1f;
}
