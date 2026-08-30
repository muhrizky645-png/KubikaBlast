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
    [Range(1f, 30f)] public float praiseWindow = 10f;

    const int SampleRate = 44100;
    const int SPARK_STEPS = 31;

    AudioSource _sfx, _sparkSrc, _melodic, _voiceSrc, _music;

    AudioClip _place, _levelUp, _gameOver, _click, _invalid, _praise, _music_clip;
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
                PlayPraise(_streak);
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

    // ==================================================================
    // API publik (dipakai KubikaMenu untuk klik tombol, dsb.)
    // ==================================================================
    public void PlayPlace() { _sfx.pitch = 1f; _sfx.PlayOneShot(_place, 0.6f * sfxVolume); }
    public void PlayLevelUp() { _melodic.pitch = 1f; _melodic.PlayOneShot(_levelUp, 0.85f * sfxVolume); }
    public void PlayGameOver() { _melodic.pitch = 1f; _melodic.PlayOneShot(_gameOver, 0.9f * sfxVolume); }
    public void PlayClick() { _sfx.pitch = 1f; _sfx.PlayOneShot(_click, 0.55f * sfxVolume); }
    public void PlayInvalid() { _sfx.pitch = 1f; _sfx.PlayOneShot(_invalid, 0.6f * sfxVolume); }

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
                (Sine(freq, lt) * 0.5f + Tri(freq, lt) * 0.2f)
                * Mathf.Exp(-lt * 6f) * (1f - Mathf.Exp(-lt * 200f))) * 0.8f;
        });

        _click = MakeClip("sfx_click", 0.07f, t =>
        {
            float env = Mathf.Exp(-t * 55f) * (1f - Mathf.Exp(-t * 900f));
            return (Sine(660f, t) * 0.5f + Sine(990f, t) * 0.2f) * env;
        });

        _invalid = MakeClip("sfx_invalid", 0.18f, t =>
        {
            float env = Mathf.Exp(-t * 18f);
            float f = Mathf.Lerp(220f, 150f, Mathf.Clamp01(t / 0.12f));
            float body = Sine(f, t) * 0.5f + Tri(f, t) * 0.18f;
            float grit = (Random.value * 2f - 1f) * 0.12f * Mathf.Exp(-t * 30f);
            return (body + grit) * env;
        });

        BuildMusic();
    }

    void BuildMusic()
    {
        // Loop 9.6 detik = 16 ketuk @100 BPM. Progresi akor Am - F - C - G.
        const float loopDur = 9.6f;
        const float beat = 0.6f;
        float[] roots = { 220.00f, 174.61f, 261.63f, 196.00f };

        _music_clip = MakeClip("music_loop", loopDur, t =>
        {
            int beatIdx = (int)(t / beat);
            int bar = (beatIdx / 4) % roots.Length;
            float root = roots[bar];
            float inBeat = t - beatIdx * beat;

            // Bass: pulsa root tiap ketuk.
            float bassEnv = Mathf.Exp(-inBeat * 3.5f) * (1f - Mathf.Exp(-inBeat * 120f));
            float bass = (Sine(root * 0.5f, t) * 0.6f + Tri(root * 0.5f, t) * 0.2f) * bassEnv * 0.35f;

            // Pad akor lembut (root + kuint).
            float pad = Sine(root, t) * 0.05f + Sine(root * 1.5f, t) * 0.04f;

            // Arpeggio ringan tiap 1/2 ketuk.
            float arpStep = beat * 0.5f;
            int arpIdx = (int)(t / arpStep);
            float inArp = t - arpIdx * arpStep;
            float[] mult = { 1f, 1.25f, 1.5f, 2f };
            float arpFreq = root * mult[arpIdx % mult.Length];
            float arp = Sine(arpFreq * 2f, t) * 0.055f * Mathf.Exp(-inArp * 8f);

            float mix = bass + pad + arp;

            // Fade tipis di ujung loop supaya sambungan mulus (tanpa "klik").
            float fade = 1f;
            if (t < 0.04f) fade = t / 0.04f;
            else if (t > loopDur - 0.04f) fade = (loopDur - t) / 0.04f;

            return mix * fade * 0.9f;
        });
    }

    // ==================================================================
    // DSP helpers
    // ==================================================================
    AudioClip MakeClip(string name, float dur, System.Func<float, float> fn)
    {
        int count = Mathf.Max(1, Mathf.CeilToInt(SampleRate * dur));
        var data = new float[count];
        for (int i = 0; i < count; i++)
        {
            float t = (float)i / SampleRate;
            data[i] = Mathf.Clamp(fn(t), -1f, 1f);
        }
        var clip = AudioClip.Create(name, count, 1, SampleRate, false);
        clip.SetData(data, 0);
        return clip;
    }

    static float Sine(float freq, float t) => Mathf.Sin(2f * Mathf.PI * freq * t);

    static float Tri(float freq, float t)
    {
        float p = (t * freq) % 1f;
        if (p < 0f) p += 1f;
        return 4f * Mathf.Abs(p - 0.5f) - 1f;
    }

    // Memainkan urutan frekuensi, tiap langkah selebar 'step' detik.
    float Seq(float t, float[] freqs, float step, System.Func<float, float, float> voice)
    {
        if (freqs == null || freqs.Length == 0) return 0f;
        int idx = Mathf.Clamp((int)(t / step), 0, freqs.Length - 1);
        float lt = t - idx * step;
        return voice(freqs[idx], lt);
    }
}
