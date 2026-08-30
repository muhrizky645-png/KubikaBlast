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
///   - Kalau kamu menaruh file suara di Assets/Resources/Voice/ (good.wav,
///     awesome.wav, amazing.wav, fantastic.wav, incredible.wav, unstoppable.wav,
///     legendary.wav) -> otomatis dipakai suara ASLI itu.
///   - Kalau file tidak ada -> otomatis pakai sting musik yang naik tiap combo.
/// </summary>
public class KubikaSfx : MonoBehaviour
{
    public static KubikaSfx Instance { get; private set; }

    [Header("Volume")]
    [Range(0f, 1f)] public float sfxVolume = 0.8f;
    [Range(0f, 1f)] public float musicVolume = 0.32f;
    public bool musicEnabled = true;

    const int SampleRate = 44100;
    const int SPARK_STEPS = 31;

    AudioSource _sfx, _sparkSrc, _melodic, _voiceSrc, _music;

    AudioClip _place, _levelUp, _gameOver, _click, _invalid, _praise, _music_clip;
    AudioClip[] _sparks;

    BlastGame _game;
    BlastCore _lastCore;
    int _pScore, _pLines, _pLevel;
    bool _pGameOver;

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
            Prime(core);
            return;
        }

        if (core.Score > _pScore)
        {
            PlayPlace();

            if (core.LinesCleared > _pLines)
            {
                int cells = (core.LastClear.Cells != null) ? core.LastClear.Cells.Count : 0;
                if (cells <= 0) cells = (core.LinesCleared - _pLines) * Mathf.Max(1, core.Columns);
                StartCoroutine(ClearCascade(cells, core.Combo));
                PlayPraise(core.Combo);
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

    // ====== Suara pujian: Good / Awesome / Amazing ... ======
    public void PlayPraise(int combo)
    {
        int i = Mathf.Clamp(combo - 1, 0, VoiceKeys.Length - 1);
        var voice = Resources.Load<AudioClip>("Voice/" + VoiceKeys[i]);
        if (voice != null)
        {
            _voiceSrc.pitch = 1f;
            _voiceSrc.PlayOneShot(voice, 0.95f * sfxVolume);
            return;
        }
        // fallback: sting musik naik makin tinggi per combo
        float pitch = Mathf.Pow(1.05946f, Mathf.Clamp((combo - 1) * 2, 0, 18));
        _voiceSrc.pitch = pitch;
        _voiceSrc.PlayOneShot(_praise, 0.8f * sfxVolume);
    }

    // ====== KASKADE HANCUR: nada naik sinkron block pecah 1-per-1 ======
    IEnumerator ClearCascade(int cellCount, int combo)
    {
        int n = Mathf.Clamp(cellCount, 1, 28);
        float delay = 0.06f;
        if (_game != null && _game.clearStepDelay > 0f) delay = _game.clearStepDelay;
        int comboLift = Mathf.Clamp(combo - 1, 0, 5) * 2;
        int[] penta = { 0, 2, 4, 7, 9 };
        var wait = new WaitForSeconds(delay);

        for (int i = 0; i < n; i++)
        {
            int oct = i / penta.Length;
            int semi = Mathf.Clamp(oct * 12 + penta[i % penta.Length] + comboLift, 0, SPARK_STEPS - 1);
            float vol = Mathf.Lerp(0.9f, 0.5f, (float)i / n);
            _sparkSrc.PlayOneShot(_sparks[semi], vol * sfxVolume);
            yield return wait;
        }

        int topIndex = Mathf.Clamp(((n - 1) / penta.Length) * 12 + comboLift + 12, 0, SPARK_STEPS - 1);
        _sparkSrc.PlayOneShot(_sparks[topIndex], 0.55f * sfxVolume);
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

        // Sting pujian (fallback bila tak ada file suara): arpeggio mayor ceria.
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

        _music_clip = BuildMusic();
    }

    public void PlayPlace()   => PlayOn(_sfx, _place, 0.9f);
    public void PlayClick()   => PlayOn(_sfx, _click, 0.7f);
    public void PlayInvalid() => PlayOn(_sfx, _invalid, 0.8f);
    public void PlayLevelUp() => PlayOn(_melodic, _levelUp, 1f);
    public void PlayGameOver()=> PlayOn(_melodic, _gameOver, 1f);

    void PlayOn(AudioSource src, AudioClip clip, float vol, float pitch = 1f)
    {
        if (clip == null || src == null) return;
        src.pitch = pitch;
        src.PlayOneShot(clip, vol * sfxVolume);
    }

    // ====== BACKGROUND MUSIC (loop) ======
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

    // ====== Synth core ======
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
