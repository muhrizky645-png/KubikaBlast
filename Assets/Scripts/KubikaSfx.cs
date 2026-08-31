using System.Collections;
using UnityEngine;
using KubikaBlast;

/// <summary>
/// Procedural AUDIO untuk Kubika Blast: SFX gaya Block Blast + background music
/// + suara pujian (Good/Awesome/Amazing...). Semua di-generate lewat kode.
///
/// >>> LANGSUNG BUNYI, TANPA EDIT KODE GAME & TANPA SETTING UNITY <<<
/// Taruh file ini di folder "Assets" lalu tekan Play.
///
/// =====================================================================
/// KENAPA DULU SUARANYA "NABRAK" — dan apa yang diperbaiki
/// =====================================================================
///
/// (1) SATU clear memicu EMPAT hal di frame yang sama: PlayPlace, rentetan
///     cascade, chime permata, dan suara pujian.
///
/// (2) Cascade-nya 24 nada x 0.06 detik = 1.44 DETIK, padahal tiap klip spark
///     panjangnya 0.22 detik. Artinya sekitar 4 nada selalu berbunyi bersamaan
///     sepanjang rentetan. Lebih parah: tidak ada pegangan koroutin, jadi clear
///     kedua dalam 1.44 detik itu menumpuk cascade BARU di atas yang lama.
///     Sekarang: maksimal 10 nada, total dikunci ~0.26 detik, dan cascade lama
///     SELALU dihentikan sebelum yang baru dimulai.
///
/// (3) BIANG KERUSAKAN: PlayOn() menulis `src.pitch` sebelum tiap PlayOneShot,
///     sementara cascade, chime permata, DAN tik palu semuanya berbagi satu
///     AudioSource (_sparkSrc). Di Unity, mengubah AudioSource.pitch akan
///     MENGGESER NADA SEMUA PlayOneShot yang masih berbunyi di source itu.
///     Jadi chime permata (muncul tiap clear) atau tik palu (pitch sampai 1.75)
///     membengkokkan nada cascade yang sedang jalan di tengah jalan. Itulah
///     bunyi "nabrak"/sumbang, bukan sekadar ramai.
///     Sekarang: SATU AudioSource per peran, dan _cascadeSrc pitch-nya TIDAK
///     PERNAH disentuh siapa pun.
///
/// (4) Tidak ada kompensasi gain. Nada bertumpuk menjumlah lewat 1.0 lalu
///     ter-clip keras di mixer (bunyi kresek). Sekarang tiap nada diredam
///     1/sqrt(jumlah nada).
///
/// (5) Objek ini DontDestroyOnLoad tapi tidak pernah StopAllCoroutines, jadi
///     cascade ronde sebelumnya bisa terus berbunyi di layar Home.
///
/// GAME OVER: semua source di-fade 120ms lalu dihentikan, baru sting game over
/// diputar SENDIRIAN. Dulu langkah terakhir yang meng-clear sekaligus mematikan
/// papan menghasilkan place + cascade 1.44 detik + jingle naik level + jingle
/// game over + suara pujian, semuanya barengan.
///
/// SUARA PUJIAN:
///   - Taruh file di Assets/Resources/Voice/ (good, awesome, amazing, fantastic,
///     incredible, unstoppable, legendary; .mp3/.wav/.ogg) -> dipakai otomatis.
///   - Kalau tidak ada -> pakai sting musik yang naik tiap tingkat combo.
/// </summary>
public class KubikaSfx : MonoBehaviour
{
    public static KubikaSfx Instance { get; private set; }

    [Header("Volume")]
    [Range(0f, 1f)] public float sfxVolume = 0.8f;
    [Range(0f, 1f)] public float musicVolume = 0.32f;
    public bool musicEnabled = true;

    [Header("Pujian (announcer)")]
    [Tooltip("Tidak lagi dipakai: tingkat pujian kini mengikuti BlastCore.Combo. Disimpan demi kompatibilitas scene lama.")]
    [Range(1f, 30f)] public float praiseWindow = 15f;

    const int SampleRate = 44100;
    const int SPARK_STEPS = 31;

    /// <summary>Nada cascade maksimum. Dulu 24 — jauh lebih panjang dari klipnya sendiri.</summary>
    const int MAX_CASCADE_NOTES = 10;

    /// <summary>Total durasi rentetan, berapa pun jumlah sel yang hancur.</summary>
    const float CASCADE_TOTAL = 0.26f;

    // ---- SATU AudioSource PER PERAN ----
    // Ini kuncinya. Karena `pitch` bersifat per-source dan mempengaruhi suara yang
    // MASIH berbunyi, peran yang mengubah pitch tidak boleh berbagi source dengan
    // peran yang bunyinya panjang.
    AudioSource _sfx;        // place / click / invalid / palu / bom (pitch boleh berubah)
    AudioSource _cascadeSrc; // HANYA rentetan clear. pitch selalu 1. jangan disentuh.
    AudioSource _gemSrc;     // HANYA chime permata (pitch naik per butir)
    AudioSource _toolSrc;    // HANYA tik palu (pitch naik per blok)
    AudioSource _melodic;    // naik level / game over
    AudioSource _voiceSrc;   // suara pujian
    AudioSource _music;

    AudioClip _place, _levelUp, _gameOver, _click, _invalid, _praise, _music_clip;
    AudioClip _hammer, _bomb, _hammerTick, _gem;
    AudioClip[] _sparks;

    BlastGame _game;
    BlastGame _hookedGame;
    BlastCore _lastCore;

    Coroutine _cascade;
    bool _muted;               // true sejak game over sampai ronde berikutnya
    float _lastGemTime = -99f;

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

        _sfx        = NewSource();
        _cascadeSrc = NewSource();
        _gemSrc     = NewSource();
        _toolSrc    = NewSource();
        _melodic    = NewSource();
        _voiceSrc   = NewSource();
        _music      = NewSource();
        _music.loop = true;

        BuildClips();

        _music.clip = _music_clip;
        _music.volume = musicVolume;
        if (musicEnabled) _music.Play();
    }

    void OnDestroy()
    {
        Unhook();
        if (Instance == this) Instance = null;
    }

    AudioSource NewSource()
    {
        var s = gameObject.AddComponent<AudioSource>();
        s.playOnAwake = false;
        s.spatialBlend = 0f;
        s.volume = 1f;
        return s;
    }

    // ==================================================================
    // ============ HOOK KE GAME (event, bukan tebak skor) ==============
    // ==================================================================

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

        if (!ReferenceEquals(_game, _hookedGame)) Hook(_game);

        // Core baru = ronde baru. Bersihkan sisa suara ronde lama.
        var core = _game.Core;
        if (core != null && !ReferenceEquals(core, _lastCore))
        {
            _lastCore = core;
            ResetForNewRound();
        }
    }

    void Hook(BlastGame g)
    {
        Unhook();
        _hookedGame = g;
        g.OnPlaced   += HandlePlaced;
        g.OnCleared  += HandleCleared;
        g.OnLevelUp  += HandleLevelUp;
        g.OnGameOver += HandleGameOver;
        g.OnRebuilt  += ResetForNewRound;
    }

    void Unhook()
    {
        if (_hookedGame == null) return;
        _hookedGame.OnPlaced   -= HandlePlaced;
        _hookedGame.OnCleared  -= HandleCleared;
        _hookedGame.OnLevelUp  -= HandleLevelUp;
        _hookedGame.OnGameOver -= HandleGameOver;
        _hookedGame.OnRebuilt  -= ResetForNewRound;
        _hookedGame = null;
    }

    void ResetForNewRound()
    {
        _muted = false;
        StopCascade();
        StopAllCoroutines();   // (5) sisa ronde lama tidak boleh ikut ke Home / ronde baru
        HushNow();
    }

    void HandlePlaced(int cells)
    {
        if (_muted) return;
        PlayPlace();
    }

    void HandleCleared(BlastCore.ClearInfo info)
    {
        if (_muted) return;

        int cells = (info.Cells != null) ? info.Cells.Count : 0;
        if (cells <= 0) return;

        // Alat (palu/bom) punya suaranya sendiri; jangan tumpuk rentetan di atasnya.
        if (info.FromTool) return;

        StopCascade();
        _cascade = StartCoroutine(ClearCascade(cells, Mathf.Max(1, info.Combo)));
    }

    void HandleLevelUp(int level)
    {
        if (_muted) return;
        // Diberi jeda kecil supaya tidak menabrak awal rentetan clear.
        StartCoroutine(DelayedLevelUp());
    }

    IEnumerator DelayedLevelUp()
    {
        yield return new WaitForSecondsRealtime(CASCADE_TOTAL + 0.06f);
        if (_muted) yield break;
        PlayLevelUp();
    }

    void HandleGameOver()
    {
        // Diam DULU, baru sting. Inilah perbaikan "suara pujian tetap muncul
        // padahal sudah game over".
        _muted = true;
        StopCascade();
        StartCoroutine(GameOverRoutine());
    }

    IEnumerator GameOverRoutine()
    {
        yield return StartCoroutine(FadeOutAll(0.12f));
        yield return new WaitForSecondsRealtime(0.16f);   // satu tarikan napas
        _melodic.volume = 1f;
        _melodic.pitch = 1f;
        _melodic.PlayOneShot(_gameOver, 1f * sfxVolume);
    }

    void StopCascade()
    {
        if (_cascade != null) { StopCoroutine(_cascade); _cascade = null; }
    }

    /// <summary>Redam semua SFX dengan halus, lalu hentikan. Musik tidak diganggu.</summary>
    IEnumerator FadeOutAll(float dur)
    {
        AudioSource[] all = { _sfx, _cascadeSrc, _gemSrc, _toolSrc, _melodic, _voiceSrc };
        float t = 0f;
        while (t < dur)
        {
            float k = 1f - (t / dur);
            foreach (var s in all) if (s != null) s.volume = k;
            t += Time.unscaledDeltaTime;
            yield return null;
        }
        foreach (var s in all)
        {
            if (s == null) continue;
            s.Stop();
            s.volume = 1f;
            s.pitch = 1f;
        }
    }

    void HushNow()
    {
        AudioSource[] all = { _sfx, _cascadeSrc, _gemSrc, _toolSrc, _melodic, _voiceSrc };
        foreach (var s in all)
        {
            if (s == null) continue;
            s.Stop();
            s.volume = 1f;
            s.pitch = 1f;
        }
    }

    // ==================================================================
    // ============ RENTETAN CLEAR ======================================
    // ==================================================================

    IEnumerator ClearCascade(int cellCount, int tier)
    {
        int n = Mathf.Clamp(cellCount, 1, MAX_CASCADE_NOTES);

        // Total durasi DIKUNCI. Dulu durasinya ikut jumlah sel, jadi clear besar
        // berbunyi 1.44 detik dan pasti bertabrakan dengan aksi berikutnya.
        float delay = Mathf.Clamp(CASCADE_TOTAL / n, 0.018f, 0.05f);

        const int MAX_STEP = 16;
        int lift = Mathf.Clamp(tier - 1, 0, 4) * 2;
        int[] penta = { 0, 2, 4, 7, 9 };

        // (4) Kompensasi polifoni: makin banyak nada bersamaan, makin pelan
        //     masing-masing, supaya jumlahnya tidak melewati 1.0 dan clipping.
        float poly = 1f / Mathf.Sqrt(n);

        var wait = new WaitForSecondsRealtime(delay);

        for (int i = 0; i < n; i++)
        {
            if (_muted) { _cascade = null; yield break; }

            int octave = (i / penta.Length) % 2;
            int semi = Mathf.Clamp(octave * 12 + penta[i % penta.Length] + lift, 0, MAX_STEP);
            float vol = Mathf.Lerp(0.90f, 0.50f, (float)i / Mathf.Max(1, n - 1)) * poly;

            // pitch TIDAK disentuh di sini, dan tidak ada peran lain yang memakai
            // source ini, jadi nada tak mungkin dibengkokkan di tengah jalan.
            _cascadeSrc.PlayOneShot(_sparks[semi], vol * sfxVolume);
            yield return wait;
        }

        if (!_muted)
        {
            int topIndex = Mathf.Clamp(penta[penta.Length - 1] + lift + 4, 0, MAX_STEP);
            _cascadeSrc.PlayOneShot(_sparks[topIndex], (0.42f * poly + 0.14f) * sfxVolume);
        }
        _cascade = null;
    }

    // ==================================================================
    // ============ API PUBLIK ==========================================
    // ==================================================================

    public void PlayPraise(int tier)
    {
        if (_muted) return;   // jangan pernah memuji papan yang sudah mati

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

    public void PlayPlace()    => PlayOn(_sfx, _place, 0.9f);
    public void PlayClick()    => PlayOn(_sfx, _click, 0.7f);
    public void PlayInvalid()  => PlayOn(_sfx, _invalid, 0.8f);
    public void PlayLevelUp()  => PlayOn(_melodic, _levelUp, 1f);
    public void PlayGameOver() => PlayOn(_melodic, _gameOver, 1f);
    public void PlayHammer()   => PlayOn(_sfx, _hammer, 1f, Random.Range(0.96f, 1.05f));
    public void PlayBomb()     => PlayOn(_sfx, _bomb, 1f, Random.Range(0.9f, 1.0f));

    /// <summary>Tik palu. Source SENDIRI: pitch-nya naik terus, dulu ini yang
    /// membengkokkan rentetan clear karena berbagi _sparkSrc.</summary>
    public void PlayHammerTick(int step)
        => PlayOn(_toolSrc, _hammerTick, 0.85f, Mathf.Min(1.6f, 1f + step * 0.05f) * Random.Range(0.98f, 1.02f));

    /// <summary>Chime permata tunggal.</summary>
    public void PlayGem() => PlayGemTick(0);

    /// <summary>
    /// Chime permata ke-<paramref name="index"/> dalam satu semburan; nadanya naik
    /// sedikit tiap butir sehingga terdengar seperti koin yang dikumpulkan.
    /// Dibatasi laju supaya tidak menumpuk jadi bunyi kresek.
    /// </summary>
    public void PlayGemTick(int index)
    {
        if (_muted) return;
        float now = Time.unscaledTime;
        if (now - _lastGemTime < 0.035f) return;
        _lastGemTime = now;

        float pitch = Mathf.Min(1.9f, 1f + index * 0.055f);
        float vol = Mathf.Lerp(0.75f, 0.42f, Mathf.Clamp01(index / 12f));
        PlayOn(_gemSrc, _gem, vol, pitch);
    }

    void PlayOn(AudioSource src, AudioClip clip, float vol, float pitch = 1f)
    {
        if (clip == null || src == null) return;
        if (_muted && src != _melodic) return;
        src.pitch = pitch;
        src.PlayOneShot(clip, vol * sfxVolume);
    }

    // ==================================================================
    // ============ PEMBUATAN KLIP (procedural) =========================
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

        // Klip spark dipendekkan 0.22 -> 0.16 detik. Dengan jarak nada ~0.026 detik,
        // tumpang-tindihnya jauh lebih pendek dan terdengar sebagai satu rentetan
        // utuh, bukan empat nada yang saling menimpa.
        _sparks = new AudioClip[SPARK_STEPS];
        for (int s = 0; s < SPARK_STEPS; s++)
        {
            float mul = Mathf.Pow(2f, s / 12f);
            float bF = 740f * mul;
            _sparks[s] = MakeClip("sfx_spark_" + s, 0.16f, t =>
            {
                float env = Mathf.Exp(-t * 17f) * (1f - Mathf.Exp(-t * 900f));
                float body = Sine(bF, t) * 0.5f + Sine(bF * 2f, t) * 0.22f
                           + Sine(bF * 3f, t) * 0.09f + Tri(bF, t) * 0.07f;
                float vib = Mathf.Sin(2f * Mathf.PI * 16f * t) * 18f;
                float shimmer = Sine(bF * 4f + vib, t) * 0.06f * Mathf.Exp(-t * 12f);
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

        // Game over dibuat lebih hangat & panjang: bukan hukuman, tapi penutup yang
        // menghormati usaha pemain. Turun lembut lalu berhenti di akor mayor.
        _gameOver = MakeClip("sfx_gameover", 1.35f, t =>
        {
            float[] f = { 659f, 523f, 440f, 349f };
            float fall = Seq(t, f, 0.19f, (freq, lt) =>
                (Sine(freq, lt) * 0.5f + Tri(freq, lt) * 0.22f + Sine(freq * 2f, lt) * 0.1f)
                * Mathf.Exp(-lt * 4.2f));

            // Akor penutup C mayor yang menenangkan, mulai ~0.76 detik.
            float ct = Mathf.Max(0f, t - 0.76f);
            float chord = 0f;
            if (t > 0.76f)
            {
                float env = Mathf.Exp(-ct * 2.2f) * (1f - Mathf.Exp(-ct * 60f));
                chord = (Sine(262f, ct) * 0.34f + Sine(330f, ct) * 0.26f
                       + Sine(392f, ct) * 0.22f + Sine(523f, ct) * 0.16f) * env;
            }
            return (fall * 0.55f + chord * 0.75f);
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

            float ti = Mathf.Max(0f, t - 0.03f);
            float hit = 1f - Mathf.Exp(-ti * 700f);

            float thud = Sine(Mathf.Lerp(240f, 70f, Mathf.Clamp01(ti / 0.06f)), ti) * Mathf.Exp(-ti * 24f) * 0.95f;
            float sub  = Sine(48f, ti) * Mathf.Exp(-ti * 16f) * 0.5f;
            float clank = (Sine(1750f, ti) * 0.35f + Square(2550f, ti) * 0.12f + Sine(3400f, ti) * 0.15f) * Mathf.Exp(-ti * 46f);
            float grain = (Mathf.Floor(ti * 5200f) % 2f == 0f) ? 1f : 0.4f;
            float crackle = (Random.value * 2f - 1f) * Mathf.Exp(-ti * 12f) * 0.3f * grain;

            float mix = whoosh + (thud + sub + clank + crackle) * hit;
            return (float)System.Math.Tanh(mix * 1.1f);
        });

        _hammerTick = MakeClip("sfx_hammer_tick", 0.13f, t =>
        {
            float hit = 1f - Mathf.Exp(-t * 900f);
            float tick = (Sine(2600f, t) * 0.5f + Square(3600f, t) * 0.2f) * Mathf.Exp(-t * 70f);
            float thud = Sine(Mathf.Lerp(300f, 120f, Mathf.Clamp01(t / 0.03f)), t) * Mathf.Exp(-t * 38f) * 0.6f;
            float chip = (Random.value * 2f - 1f) * Mathf.Exp(-t * 55f) * 0.28f;
            float mix = (tick + thud + chip) * hit;
            return (float)System.Math.Tanh(mix * 1.15f);
        });

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
            return (float)System.Math.Tanh(mix * 1.2f);
        });

        // Chime permata dibuat lebih pendek & bening supaya enak diulang per butir.
        _gem = MakeClip("sfx_gem", 0.24f, t =>
        {
            float[] f = { 1047f, 1319f };
            float arp = Seq(t, f, 0.055f, (freq, lt) =>
                (Sine(freq, lt) * 0.5f + Sine(freq * 2f, lt) * 0.18f) * Mathf.Exp(-lt * 16f));
            float shimmer = Sine(2093f, t) * 0.10f * Mathf.Exp(-t * 12f);
            return arp + shimmer;
        });

        _music_clip = BuildMusic();
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
