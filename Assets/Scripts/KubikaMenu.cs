// Dukung DUA backend input Unity (Input Manager lama & Input System baru),
// sama seperti BlastInput/BlastUI, supaya tombol menu jalan tanpa ubah Player Settings.
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

using System.Collections;
using System.Collections.Generic;
using System.Text;
using UnityEngine;
using UnityEngine.UI;
#if USE_NEW_INPUT
using UnityEngine.InputSystem;
#endif
using KubikaBlast;

/// <summary>
/// MENU / UI SISTEM untuk Kubika Blast (ADD-ON, tanpa edit kode game).
///
/// >>> TANPA SETTING UNITY <<< Taruh file ini di folder "Assets", tekan Play.
///
/// Tema: ceria & warna-warni, dengan BACKGROUND ANIMASI (kotak-kotak warni
/// melayang) di semua layar menu.
///
/// LAYAR GAME OVER (dirombak):
///   Dulu kartunya menumpahkan semuanya dalam satu frame — skor, skor terbaik,
///   dua tombol, selesai. Tidak ada yang menghargai usaha pemain.
///   Sekarang muncul BERTAHAP di waktu unscaled (layar ini jalan di timeScale 0):
///   judul -> kalimat motivasi -> skor berhitung naik -> NEW RECORD / skor
///   terbaik -> statistik ronde -> tombol. Ronde yang berakhir cepat pun tetap
///   punya sesuatu untuk ditunjukkan.
///
/// Semua tap dideteksi manual (tanpa EventSystem). Saat menu/jeda terbuka:
/// Time.timeScale = 0 dan BlastInput dimatikan. Animasi background pakai
/// unscaledDeltaTime agar tetap bergerak walau game di-pause.
/// </summary>
public class KubikaMenu : MonoBehaviour
{
    public static KubikaMenu Instance { get; private set; }

    // =================================================================
    // KALIMAT MOTIVASI GAME OVER
    // Silakan ganti/tambah sesukamu. Dipilih acak dari kolam yang sesuai
    // dengan hasil ronde. Satu baris = satu kalimat.
    // =================================================================

    /// <summary>Dipakai saat pemain memecahkan rekor pribadinya.</summary>
    static readonly string[] MotivationRecord =
    {
        "A brand new record. That was your best run yet.",
        "You just beat yourself, and that is the hardest opponent there is.",
        "New personal best. Everything clicked this time.",
        "Record broken. All that practice finally showed up.",
    };

    /// <summary>Ronde kuat: mendekati rekor, atau banyak baris hancur.</summary>
    static readonly string[] MotivationStrong =
    {
        "So close to your best. One more run and it is yours.",
        "That was a strong run. You read the board well.",
        "You kept that board alive far longer than it wanted to stay.",
        "You are getting sharper every single round.",
    };

    /// <summary>Ronde biasa yang sehat.</summary>
    static readonly string[] MotivationSolid =
    {
        "Good run. Every board teaches you something new.",
        "Nice work out there. The next one will go further.",
        "Solid effort. The momentum is building.",
        "You held it together under pressure. That counts.",
    };

    /// <summary>Ronde pendek / papan yang memang jahat.</summary>
    static readonly string[] MotivationShort =
    {
        "Rough board. That one was stacked against you.",
        "Shake it off. The next board is a clean slate.",
        "Every expert lost this board a hundred times first.",
        "Short run, no problem. Go again.",
    };

    enum UIScreen { Home, Playing, Paused, Settings, GameOver }
    UIScreen _screen = UIScreen.Home;
    UIScreen _settingsReturn = UIScreen.Home;
    // Dibaca KubikaItems untuk tahu kapan menampilkan tombol TOKO (Home/Jeda).
    public static string CurrentScreenName = "Home";

    const string LB_KEY = "kubika_leaderboard";
    const string MUSIC_KEY = "kubika_music_vol";
    const string SFX_KEY = "kubika_sfx_vol";
    const string FPS_KEY = "kubika_fps";

    static readonly int[] FPS_OPTS = { 30, 60, 90, 120 };

    // Palet ceria dipakai untuk dekorasi & background.
    static readonly Color[] Palette =
    {
        new Color(1.00f, 0.36f, 0.48f), // pink
        new Color(1.00f, 0.72f, 0.30f), // orange
        new Color(1.00f, 0.84f, 0.31f), // yellow
        new Color(0.40f, 0.73f, 0.42f), // green
        new Color(0.31f, 0.76f, 0.97f), // blue
        new Color(0.73f, 0.41f, 0.78f), // purple
        new Color(0.30f, 0.82f, 0.88f), // teal
    };

    BlastGame _game;
    BlastInput _input;
    bool _init;
    bool _prevGameOver;

    Canvas _canvas;
    Font _font;
    Sprite _round, _gradient;

    GameObject _homePanel, _pausePanel, _settingsPanel, _goPanel;
    RectTransform _pauseBtn;
    RectTransform _btnMain, _btnSettingsHome;
    RectTransform _btnResume, _btnSettingsPause, _btnHome;
    RectTransform _btnBackSettings;
    RectTransform _goRestart, _goHome;
    RectTransform _musicBar, _sfxBar, _fpsBar, _musicFill, _sfxFill, _fpsFill;
    Text _musicPct, _sfxPct, _fpsPct, _homeTop5, _goScore, _goBest;

    // Game over: elemen baru + grup untuk fade bertahap.
    Text _goTitle, _goMotivation, _goRecord, _goStats;
    RectTransform _goTitleRT, _goScoreRT, _goRecordRT;
    CanvasGroup _cgTitle, _cgMotivation, _cgScore, _cgRecord, _cgStats, _cgButtons;
    RectTransform _goButtonsRoot;
    Coroutine _reveal;

    float _sliderWidth = 640f;
    float _musicVal = 0.32f, _sfxVal = 0.8f, _fpsVal = 1f / 3f;
    bool _dragMusic, _dragSfx, _dragFps;

    // Background animasi.
    GameObject _bgRoot;
    RectTransform[] _bgBlocks;
    float[] _bgSpeed, _bgRot, _bgSwayFreq, _bgPhase, _bgBaseX, _bgAmp;
    float _bgTime;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void AutoBootstrap()
    {
        if (Instance != null) return;
        var go = new GameObject("KubikaMenu (auto)");
        go.AddComponent<KubikaMenu>();
    }

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void Update()
    {
        if (!_init) Init();
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_input == null) _input = FindFirstObjectByType<BlastInput>();
        var core = _game != null ? _game.Core : null;

        // Jaring pengaman: saat status BERMAIN, pastikan waktu berjalan & input game
        // aktif, supaya game tidak pernah "stuck tak bisa dipencet".
        //
        // DULU baris ini menyetel Time.timeScale = 1 SETIAP FRAME tanpa syarat, jadi
        // hit-stop (jeda dramatis 60-80 ms saat clear besar) selalu dibatalkan dalam
        // satu frame — efeknya tidak pernah benar-benar terasa. Sekarang jaring ini
        // mengalah selama hit-stop berjalan, tapi tetap memulihkan papan sesudahnya.
        if (_screen == UIScreen.Playing && (core == null || !core.GameOver))
        {
            if (!BlastGame.HitStopActive && Time.timeScale != 1f) Time.timeScale = 1f;
            if (_input != null && !_input.enabled) _input.enabled = true;
        }

        var sfx = KubikaSfx.Instance;
        if (sfx != null)
        {
            sfx.musicVolume = _musicVal;
            sfx.musicEnabled = _musicVal > 0.01f;
            sfx.sfxVolume = _sfxVal;
        }

        if (_pauseBtn != null)
        {
            bool showPause = _screen == UIScreen.Playing && (core == null || !core.GameOver);
            if (_pauseBtn.gameObject.activeSelf != showPause) _pauseBtn.gameObject.SetActive(showPause);
        }

        // Deteksi GAME OVER -> catat skor & tampilkan layar custom.
        if (core != null)
        {
            if (core.GameOver && !_prevGameOver && _screen == UIScreen.Playing)
            {
                // Ambil rekor SEBELUM skor ini dicatat, supaya "NEW RECORD" akurat.
                var before = LoadScores();
                int bestBefore = (before.Count > 0) ? before[0] : 0;
                RecordScore(core.Score);
                ShowGameOver(core, bestBefore);
            }
            _prevGameOver = core.GameOver;
        }

        AnimateBackground();
        UpdateSliderFills();
        if (_screen == UIScreen.Settings) HandleSliders();

        if (PDown())
        {
            Vector2 p = PPos();
            switch (_screen)
            {
                case UIScreen.Home:
                    if (Hit(_btnMain, p)) StartGame();
                    else if (Hit(_btnSettingsHome, p)) ShowSettings(UIScreen.Home);
                    break;
                case UIScreen.Playing:
                    if (_pauseBtn.gameObject.activeSelf && Hit(_pauseBtn, p)) Pause();
                    break;
                case UIScreen.Paused:
                    if (Hit(_btnResume, p)) Resume();
                    else if (Hit(_btnSettingsPause, p)) ShowSettings(UIScreen.Paused);
                    else if (Hit(_btnHome, p)) GoHome();
                    break;
                case UIScreen.Settings:
                    if (Hit(_btnBackSettings, p)) BackFromSettings();
                    break;
                case UIScreen.GameOver:
                    // Tap di mana saja mempercepat animasi — jangan paksa pemain menunggu.
                    if (_reveal != null && !Hit(_goRestart, p) && !Hit(_goHome, p)) { SkipReveal(); break; }
                    if (Hit(_goRestart, p)) StartGame();
                    else if (Hit(_goHome, p)) GoHome();
                    break;
            }
        }
    }

    // ===================== STATE =====================
    void SetState(UIScreen s)
    {
        _screen = s;
        CurrentScreenName = s.ToString();
        if (_homePanel != null) _homePanel.SetActive(s == UIScreen.Home);
        if (_pausePanel != null) _pausePanel.SetActive(s == UIScreen.Paused);
        if (_settingsPanel != null) _settingsPanel.SetActive(s == UIScreen.Settings);
        if (_goPanel != null) _goPanel.SetActive(s == UIScreen.GameOver);
        if (_pauseBtn != null) _pauseBtn.gameObject.SetActive(s == UIScreen.Playing);

        bool menuBg = (s == UIScreen.Home || s == UIScreen.Settings || s == UIScreen.GameOver);
        if (_bgRoot != null) _bgRoot.SetActive(menuBg);

        if (s == UIScreen.Home) RefreshHome();

        if (s != UIScreen.GameOver) StopReveal();

        Time.timeScale = (s == UIScreen.Playing) ? 1f : 0f;
        if (_input != null) _input.enabled = (s == UIScreen.Playing);
    }

    bool _everStarted;
    void StartGame()
    {
        StopReveal();
        SetState(UIScreen.Playing);
        // Papan sudah dibangun FRESH oleh BlastGame.Start() saat boot. Kalau MAIN
        // pertama Rebuild lagi, Core baru dibuat & balapan dgn gambar tray 2D
        // (kadang cuma tabung yang muncul). Jadi Rebuild HANYA saat main ulang.
        if (_everStarted && _game != null) _game.Rebuild();
        _everStarted = true;
        _prevGameOver = false;
    }

    void Pause() { if (_screen == UIScreen.Playing) SetState(UIScreen.Paused); }
    void Resume() { SetState(UIScreen.Playing); }
    void GoHome() { SetState(UIScreen.Home); }
    void ShowSettings(UIScreen ret) { _settingsReturn = ret; SetState(UIScreen.Settings); }
    void BackFromSettings() { SetState(_settingsReturn); }

    // ===================== GAME OVER =====================

    void ShowGameOver(BlastCore core, int bestBefore)
    {
        int score = core.Score;
        int best = Mathf.Max(bestBefore, score);
        bool isRecord = score > 0 && score > bestBefore;

        if (_goScore != null) _goScore.text = "0";
        if (_goBest != null) _goBest.text = "Best  " + best;

        if (_goStats != null)
        {
            var sb = new StringBuilder();
            sb.Append("Lines cleared").Append("        ").Append(core.LinesCleared).Append('\n');
            sb.Append("Gems earned").Append("         ").Append(core.GemsEarned).Append('\n');
            sb.Append("Best combo").Append("           x").Append(Mathf.Max(1, core.BestCombo)).Append('\n');
            sb.Append("Pieces placed").Append("       ").Append(core.PiecesPlaced);
            _goStats.text = sb.ToString();
        }

        if (_goMotivation != null)
            _goMotivation.text = PickMotivation(core, bestBefore, isRecord);

        if (_goRecord != null)
        {
            _goRecord.text = isRecord ? "NEW RECORD!" : ("Best  " + best);
            _goRecord.color = isRecord ? new Color(1f, 0.84f, 0.31f) : Color.white;
            _goRecord.fontSize = isRecord ? 76 : 48;
        }

        SetState(UIScreen.GameOver);

        StopReveal();
        _reveal = StartCoroutine(RevealRoutine(score, isRecord));
    }

    string PickMotivation(BlastCore core, int bestBefore, bool isRecord)
    {
        if (isRecord) return Pick(MotivationRecord);

        int lines = core.LinesCleared;
        float ratio = (bestBefore > 0) ? (float)core.Score / bestBefore : 1f;

        if (ratio >= 0.75f || lines >= 30) return Pick(MotivationStrong);
        if (ratio >= 0.35f || lines >= 12) return Pick(MotivationSolid);
        return Pick(MotivationShort);
    }

    static string Pick(string[] pool)
    {
        if (pool == null || pool.Length == 0) return "";
        return pool[Random.Range(0, pool.Length)];
    }

    void StopReveal()
    {
        if (_reveal != null) { StopCoroutine(_reveal); _reveal = null; }
    }

    /// <summary>Tampilkan semuanya seketika (pemain menge-tap untuk melewati).</summary>
    void SkipReveal()
    {
        StopReveal();
        SetCG(_cgTitle, 1f); SetCG(_cgMotivation, 1f); SetCG(_cgScore, 1f);
        SetCG(_cgRecord, 1f); SetCG(_cgStats, 1f); SetCG(_cgButtons, 1f);
        if (_goScore != null && _game != null && _game.Core != null)
            _goScore.text = _game.Core.Score.ToString();
        if (_goTitleRT != null) _goTitleRT.localScale = Vector3.one;
        if (_goScoreRT != null) _goScoreRT.localScale = Vector3.one;
        if (_goRecordRT != null) _goRecordRT.localScale = Vector3.one;
    }

    IEnumerator RevealRoutine(int score, bool isRecord)
    {
        // Semua tersembunyi dulu.
        SetCG(_cgTitle, 0f); SetCG(_cgMotivation, 0f); SetCG(_cgScore, 0f);
        SetCG(_cgRecord, 0f); SetCG(_cgStats, 0f); SetCG(_cgButtons, 0f);
        if (_goTitleRT != null) _goTitleRT.localScale = Vector3.one * 0.8f;
        if (_goRecordRT != null) _goRecordRT.localScale = Vector3.one * 0.6f;
        if (_goScoreRT != null) _goScoreRT.localScale = Vector3.one;

        yield return Wait(0.18f);

        // 1) Judul: pop masuk.
        yield return Pop(_cgTitle, _goTitleRT, 0.28f, 0.8f, 1f);

        // 2) Kalimat motivasi.
        yield return Fade(_cgMotivation, 0.30f);
        yield return Wait(0.14f);

        // 3) Skor berhitung naik.
        SetCG(_cgScore, 1f);
        yield return CountUp(score, 0.85f);
        yield return Punch(_goScoreRT, 0.22f, 1.14f);

        // 4) NEW RECORD / skor terbaik.
        yield return Wait(0.08f);
        if (isRecord)
        {
            if (KubikaSfx.Instance != null) KubikaSfx.Instance.PlayLevelUp();
            yield return Pop(_cgRecord, _goRecordRT, 0.34f, 0.6f, 1f);
        }
        else
        {
            if (_goRecordRT != null) _goRecordRT.localScale = Vector3.one;
            yield return Fade(_cgRecord, 0.26f);
        }

        // 5) Statistik ronde.
        yield return Wait(0.06f);
        yield return Fade(_cgStats, 0.30f);

        // 6) Tombol.
        yield return Wait(0.06f);
        yield return Fade(_cgButtons, 0.26f);

        _reveal = null;
    }

    // --- Primitif animasi (semuanya unscaled: layar ini jalan di timeScale 0) ---

    static IEnumerator Wait(float s)
    {
        float t = 0f;
        while (t < s) { t += Time.unscaledDeltaTime; yield return null; }
    }

    IEnumerator Fade(CanvasGroup cg, float dur)
    {
        if (cg == null) yield break;
        float t = 0f;
        while (t < dur)
        {
            cg.alpha = Mathf.Clamp01(t / dur);
            t += Time.unscaledDeltaTime;
            yield return null;
        }
        cg.alpha = 1f;
    }

    IEnumerator Pop(CanvasGroup cg, RectTransform rt, float dur, float from, float to)
    {
        float t = 0f;
        while (t < dur)
        {
            float k = t / dur;
            if (cg != null) cg.alpha = Mathf.Clamp01(k * 2.2f);
            if (rt != null)
            {
                // overshoot kecil supaya terasa "hidup"
                float s = k < 0.65f ? Mathf.Lerp(from, to * 1.12f, k / 0.65f)
                                    : Mathf.Lerp(to * 1.12f, to, (k - 0.65f) / 0.35f);
                rt.localScale = Vector3.one * s;
            }
            t += Time.unscaledDeltaTime;
            yield return null;
        }
        if (cg != null) cg.alpha = 1f;
        if (rt != null) rt.localScale = Vector3.one * to;
    }

    IEnumerator Punch(RectTransform rt, float dur, float peak)
    {
        if (rt == null) yield break;
        float t = 0f;
        while (t < dur)
        {
            float k = t / dur;
            float s = k < 0.4f ? Mathf.Lerp(1f, peak, k / 0.4f)
                               : Mathf.Lerp(peak, 1f, (k - 0.4f) / 0.6f);
            rt.localScale = Vector3.one * s;
            t += Time.unscaledDeltaTime;
            yield return null;
        }
        rt.localScale = Vector3.one;
    }

    IEnumerator CountUp(int target, float dur)
    {
        if (_goScore == null) yield break;
        if (target <= 0) { _goScore.text = "0"; yield break; }

        float t = 0f;
        while (t < dur)
        {
            float k = t / dur;
            float ease = 1f - Mathf.Pow(1f - k, 3f);   // cepat di awal, melambat di akhir
            _goScore.text = Mathf.RoundToInt(target * ease).ToString();
            t += Time.unscaledDeltaTime;
            yield return null;
        }
        _goScore.text = target.ToString();
    }

    static void SetCG(CanvasGroup cg, float a) { if (cg != null) cg.alpha = a; }

    // ===================== FPS / SMOOTHNESS =====================
    int FpsFromFrac(float f)
    {
        int i = Mathf.Clamp(Mathf.RoundToInt(f * (FPS_OPTS.Length - 1)), 0, FPS_OPTS.Length - 1);
        return FPS_OPTS[i];
    }

    float FracFromFps(int fps)
    {
        for (int i = 0; i < FPS_OPTS.Length; i++)
            if (FPS_OPTS[i] == fps) return (float)i / (FPS_OPTS.Length - 1);
        return 1f / 3f;
    }

    void ApplyFps(int fps)
    {
        QualitySettings.vSyncCount = 0;
        Application.targetFrameRate = fps;
        Screen.sleepTimeout = SleepTimeout.NeverSleep;
        PlayerPrefs.SetInt(FPS_KEY, fps);
    }

    // ===================== SLIDER =====================
    void HandleSliders()
    {
        if (!PHeld()) { _dragMusic = false; _dragSfx = false; _dragFps = false; return; }
        Vector2 p = PPos();
        if (PDown())
        {
            if (Hit(_musicBar, p)) _dragMusic = true;
            else if (Hit(_sfxBar, p)) _dragSfx = true;
            else if (Hit(_fpsBar, p)) _dragFps = true;
        }
        if (_dragMusic) { _musicVal = FracOf(_musicBar, p); PlayerPrefs.SetFloat(MUSIC_KEY, _musicVal); }
        if (_dragSfx) { _sfxVal = FracOf(_sfxBar, p); PlayerPrefs.SetFloat(SFX_KEY, _sfxVal); }
        if (_dragFps)
        {
            int fps = FpsFromFrac(FracOf(_fpsBar, p));
            _fpsVal = FracFromFps(fps);
            ApplyFps(fps);
        }
    }

    void UpdateSliderFills()
    {
        if (_musicFill != null)
        {
            var sd = _musicFill.sizeDelta; sd.x = _sliderWidth * _musicVal; _musicFill.sizeDelta = sd;
            if (_musicPct != null) _musicPct.text = Mathf.RoundToInt(_musicVal * 100f) + "%";
        }
        if (_sfxFill != null)
        {
            var sd = _sfxFill.sizeDelta; sd.x = _sliderWidth * _sfxVal; _sfxFill.sizeDelta = sd;
            if (_sfxPct != null) _sfxPct.text = Mathf.RoundToInt(_sfxVal * 100f) + "%";
        }
        if (_fpsFill != null)
        {
            var sd = _fpsFill.sizeDelta; sd.x = _sliderWidth * _fpsVal; _fpsFill.sizeDelta = sd;
            if (_fpsPct != null) _fpsPct.text = FpsFromFrac(_fpsVal) + " FPS";
        }
    }

    float FracOf(RectTransform rt, Vector2 sp)
    {
        Vector2 local;
        RectTransformUtility.ScreenPointToLocalPointInRectangle(rt, sp, null, out local);
        float w = rt.rect.width;
        if (w <= 0f) return 0f;
        return Mathf.Clamp01((local.x + w * 0.5f) / w);
    }

    // ===================== LEADERBOARD DATA =====================
    List<int> LoadScores()
    {
        var list = new List<int>();
        string raw = PlayerPrefs.GetString(LB_KEY, "");
        if (!string.IsNullOrEmpty(raw))
            foreach (var part in raw.Split(','))
                if (int.TryParse(part, out int v)) list.Add(v);
        return list;
    }

    void RecordScore(int score)
    {
        if (score <= 0) return;
        var list = LoadScores();
        list.Add(score);
        list.Sort((a, b) => b.CompareTo(a));
        if (list.Count > 10) list = list.GetRange(0, 10);
        var sb = new StringBuilder();
        for (int i = 0; i < list.Count; i++) { if (i > 0) sb.Append(','); sb.Append(list[i]); }
        PlayerPrefs.SetString(LB_KEY, sb.ToString());
        PlayerPrefs.Save();
    }

    void RefreshHome()
    {
        if (_homeTop5 == null) return;
        var list = LoadScores();
        if (list.Count == 0) { _homeTop5.text = "No scores yet.\nPlay your first round!"; return; }
        int n = Mathf.Min(5, list.Count);
        var sb = new StringBuilder();
        for (int i = 0; i < n; i++)
        {
            sb.Append(i + 1).Append(".   ").Append(list[i]);
            if (i < n - 1) sb.Append('\n');
        }
        _homeTop5.text = sb.ToString();
    }

    // ===================== BUILD UI =====================
    void Init()
    {
        _init = true;
        _game = FindFirstObjectByType<BlastGame>();
        _input = FindFirstObjectByType<BlastInput>();

        _musicVal = PlayerPrefs.GetFloat(MUSIC_KEY, 0.32f);
        _sfxVal = PlayerPrefs.GetFloat(SFX_KEY, 0.8f);
        int savedFps = PlayerPrefs.GetInt(FPS_KEY, 60);
        _fpsVal = FracFromFps(savedFps);
        ApplyFps(savedFps);

        BuildCanvas();
        BuildBackground();
        BuildHome();
        BuildPause();
        BuildSettings();
        BuildGameOver();
        BuildPauseButton();

        SetState(UIScreen.Home);
    }

    void BuildCanvas()
    {
        var go = new GameObject("KubikaMenuCanvas", typeof(Canvas), typeof(CanvasScaler));
        go.transform.SetParent(transform, false);
        _canvas = go.GetComponent<Canvas>();
        _canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        _canvas.sortingOrder = 300;
        var scaler = go.GetComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080, 2400);
        scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
        scaler.matchWidthOrHeight = 0.5f;
    }

    // ---- Background animasi (kotak warni melayang) ----
    void BuildBackground()
    {
        var go = new GameObject("AnimatedBg", typeof(RectTransform));
        go.transform.SetParent(_canvas.transform, false);
        _bgRoot = go;
        var rt = go.GetComponent<RectTransform>();
        Stretch(rt);

        var baseImg = MakeImage("BgBase", go.transform, Color.white);
        baseImg.sprite = GradientSprite(new Color(0.07f, 0.08f, 0.16f), new Color(0.13f, 0.09f, 0.22f));
        baseImg.type = Image.Type.Simple;
        Stretch(baseImg.rectTransform);

        int n = 16;
        _bgBlocks = new RectTransform[n];
        _bgSpeed = new float[n];
        _bgRot = new float[n];
        _bgSwayFreq = new float[n];
        _bgPhase = new float[n];
        _bgBaseX = new float[n];
        _bgAmp = new float[n];

        for (int i = 0; i < n; i++)
        {
            var img = MakeSprite("bgb" + i, go.transform, PaletteA(Random.Range(0, Palette.Length), Random.Range(0.32f, 0.6f)));
            var b = img.rectTransform;
            b.anchorMin = b.anchorMax = b.pivot = new Vector2(0.5f, 0.5f);
            float size = Random.Range(90f, 230f);
            b.sizeDelta = new Vector2(size, size);
            float x = Random.Range(-620f, 620f);
            float y = Random.Range(-1350f, 1350f);
            b.anchoredPosition = new Vector2(x, y);
            b.localRotation = Quaternion.Euler(0f, 0f, Random.Range(0f, 360f));

            _bgBlocks[i] = b;
            _bgBaseX[i] = x;
            _bgSpeed[i] = Random.Range(55f, 150f);
            _bgRot[i] = Random.Range(-22f, 22f);
            _bgSwayFreq[i] = Random.Range(0.3f, 0.9f);
            _bgPhase[i] = Random.Range(0f, 6.28f);
            _bgAmp[i] = Random.Range(30f, 90f);
        }
    }

    void AnimateBackground()
    {
        if (_bgRoot == null || !_bgRoot.activeSelf || _bgBlocks == null) return;
        float dt = Time.unscaledDeltaTime;
        _bgTime += dt;
        for (int i = 0; i < _bgBlocks.Length; i++)
        {
            var b = _bgBlocks[i];
            if (b == null) continue;
            var p = b.anchoredPosition;
            p.y += _bgSpeed[i] * dt;
            if (p.y > 1380f) { p.y = -1380f; _bgBaseX[i] = Random.Range(-620f, 620f); }
            p.x = _bgBaseX[i] + Mathf.Sin(_bgTime * _bgSwayFreq[i] + _bgPhase[i]) * _bgAmp[i];
            b.anchoredPosition = p;
            b.Rotate(0f, 0f, _bgRot[i] * dt);
        }
    }

    // ---- HOME ----
    void BuildHome()
    {
        _homePanel = MakePanel("HomePanel", new Color(0f, 0f, 0f, 0f)); // transparan, background animasi yang tampil
        var root = _homePanel.transform;

        var title = MakeText("Title", root, 122, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.85f, 0.25f));
        title.text = "KUBIKA\nBLAST";
        Place(title.rectTransform, C, new Vector2(0, 780), new Vector2(1000, 360));
        MakeDecoRow(root, new Vector2(0, 560));

        var card = MakeCard(root, new Vector2(0, 150), new Vector2(800, 660), new Color(0.10f, 0.12f, 0.20f, 0.90f));
        var top5Title = MakeText("Top5Title", card, 62, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.84f, 0.31f));
        top5Title.text = "TOP 5";
        Place(top5Title.rectTransform, C, new Vector2(0, 250), new Vector2(700, 90));
        _homeTop5 = MakeText("Top5List", card, 58, TextAnchor.UpperCenter, FontStyle.Bold, Color.white);
        Place(_homeTop5.rectTransform, C, new Vector2(0, 150), new Vector2(700, 420));

        _btnMain = MakeButton(root, "PLAY", new Vector2(0, -560), new Vector2(620, 180),
            new Color(0.30f, 0.75f, 0.40f), 84);
        _btnSettingsHome = MakeButton(root, "SETTINGS", new Vector2(0, -790), new Vector2(620, 150),
            new Color(0.45f, 0.47f, 0.55f), 58);
    }

    // ---- PAUSE ----
    void BuildPause()
    {
        _pausePanel = MakePanel("PausePanel", new Color(0f, 0f, 0f, 0.72f));
        var root = _pausePanel.transform;

        var card = MakeCard(root, new Vector2(0, 40), new Vector2(760, 840), new Color(0.11f, 0.12f, 0.22f, 0.96f));
        MakeDecoRow(card, new Vector2(0, 300));
        var title = MakeText("Title", card, 100, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        title.text = "PAUSED";
        Place(title.rectTransform, C, new Vector2(0, 180), new Vector2(700, 160));

        _btnResume = MakeButton(card, "RESUME", new Vector2(0, 20), new Vector2(600, 160),
            new Color(0.30f, 0.75f, 0.40f), 76);
        _btnSettingsPause = MakeButton(card, "SETTINGS", new Vector2(0, -170), new Vector2(600, 140),
            new Color(0.30f, 0.55f, 0.95f), 56);
        _btnHome = MakeButton(card, "MAIN MENU", new Vector2(0, -340), new Vector2(600, 140),
            new Color(0.55f, 0.35f, 0.35f), 56);
    }

    // ---- SETTINGS ----
    void BuildSettings()
    {
        _settingsPanel = MakePanel("SettingsPanel", new Color(0f, 0f, 0f, 0f));
        var root = _settingsPanel.transform;

        var card = MakeCard(root, new Vector2(0, 40), new Vector2(920, 1560), new Color(0.10f, 0.12f, 0.20f, 0.94f));
        MakeDecoRow(card, new Vector2(0, 640));
        var title = MakeText("Title", card, 84, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        title.text = "SETTINGS";
        Place(title.rectTransform, C, new Vector2(0, 520), new Vector2(860, 140));

        BuildSlider(card, "MUSIC", 300, new Color(0.30f, 0.80f, 0.45f),
            out _musicBar, out _musicFill, out _musicPct);
        BuildSlider(card, "SFX", 90, new Color(1.00f, 0.72f, 0.30f),
            out _sfxBar, out _sfxFill, out _sfxPct);
        BuildSlider(card, "SMOOTHNESS", -120, new Color(0.31f, 0.76f, 0.97f),
            out _fpsBar, out _fpsFill, out _fpsPct);

        var hint = MakeText("Hint", card, 36, TextAnchor.MiddleCenter, FontStyle.Normal, new Color(0.72f, 0.77f, 0.88f));
        hint.text = "Higher FPS is smoother. Lower it if your phone gets hot or laggy.";
        Place(hint.rectTransform, C, new Vector2(0, -250), new Vector2(860, 80));

        _btnBackSettings = MakeButton(card, "BACK", new Vector2(0, -560), new Vector2(520, 150),
            new Color(0.45f, 0.47f, 0.55f), 62);
    }

    void BuildSlider(Transform root, string label, float y, Color fillColor,
        out RectTransform bar, out RectTransform fill, out Text pct)
    {
        var lbl = MakeText(label + "Lbl", root, 54, TextAnchor.MiddleLeft, FontStyle.Bold, Color.white);
        lbl.text = label;
        Place(lbl.rectTransform, C, new Vector2(-330, y + 70), new Vector2(560, 70));

        pct = MakeText(label + "Pct", root, 50, TextAnchor.MiddleRight, FontStyle.Bold, new Color(1f, 0.85f, 0.3f));
        Place(pct.rectTransform, C, new Vector2(360, y + 70), new Vector2(360, 70));

        var bgImg = MakeSprite("bar" + label, root, new Color(0f, 0f, 0f, 0.45f));
        bar = bgImg.rectTransform;
        Place(bar, C, new Vector2(0, y), new Vector2(_sliderWidth, 40));

        var fillImg = MakeSprite("fill" + label, bgImg.transform, fillColor);
        fill = fillImg.rectTransform;
        fill.anchorMin = new Vector2(0f, 0f);
        fill.anchorMax = new Vector2(0f, 1f);
        fill.pivot = new Vector2(0f, 0.5f);
        fill.anchoredPosition = Vector2.zero;
        fill.sizeDelta = new Vector2(_sliderWidth * 0.5f, 0f);
    }

    // ---- GAME OVER (custom, muncul bertahap) ----
    void BuildGameOver()
    {
        _goPanel = MakePanel("GameOverPanel", new Color(0f, 0f, 0f, 0f));
        var root = _goPanel.transform;

        var card = MakeCard(root, new Vector2(0, 40), new Vector2(900, 1480), new Color(0.12f, 0.10f, 0.22f, 0.95f));
        MakeDecoRow(card, new Vector2(0, 660));

        // --- Judul ---
        _goTitle = MakeText("GO", card, 108, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.36f, 0.48f));
        _goTitle.text = "GAME OVER";
        Place(_goTitle.rectTransform, C, new Vector2(0, 520), new Vector2(840, 170));
        _goTitleRT = _goTitle.rectTransform;
        _cgTitle = _goTitle.gameObject.AddComponent<CanvasGroup>();

        // --- Kalimat motivasi ---
        _goMotivation = MakeText("Motivation", card, 42, TextAnchor.MiddleCenter, FontStyle.Normal, new Color(0.86f, 0.90f, 1f));
        _goMotivation.horizontalOverflow = HorizontalWrapMode.Wrap;
        _goMotivation.text = "";
        Place(_goMotivation.rectTransform, C, new Vector2(0, 370), new Vector2(780, 130));
        _cgMotivation = _goMotivation.gameObject.AddComponent<CanvasGroup>();

        // --- Skor ---
        var scoreWrap = MakeText("ScoreWrap", card, 44, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(0.75f, 0.8f, 0.9f));
        scoreWrap.text = "FINAL SCORE";
        Place(scoreWrap.rectTransform, C, new Vector2(0, 240), new Vector2(700, 70));
        _cgScore = scoreWrap.gameObject.AddComponent<CanvasGroup>();

        _goScore = MakeText("Score", scoreWrap.transform, 132, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.84f, 0.31f));
        _goScore.text = "0";
        Place(_goScore.rectTransform, C, new Vector2(0, -110), new Vector2(760, 170));
        _goScoreRT = _goScore.rectTransform;

        // --- NEW RECORD / skor terbaik ---
        _goRecord = MakeText("Record", card, 76, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.84f, 0.31f));
        _goRecord.text = "";
        Place(_goRecord.rectTransform, C, new Vector2(0, -20), new Vector2(800, 110));
        _goRecordRT = _goRecord.rectTransform;
        _cgRecord = _goRecord.gameObject.AddComponent<CanvasGroup>();

        // Disimpan demi kompatibilitas: teks best lama sekarang menyatu ke _goRecord.
        _goBest = _goRecord;

        // --- Statistik ronde ---
        _goStats = MakeText("Stats", card, 40, TextAnchor.UpperCenter, FontStyle.Bold, new Color(0.80f, 0.85f, 0.95f));
        _goStats.text = "";
        Place(_goStats.rectTransform, C, new Vector2(0, -190), new Vector2(760, 240));
        _cgStats = _goStats.gameObject.AddComponent<CanvasGroup>();

        // --- Tombol (dibungkus supaya bisa di-fade sekaligus) ---
        var btnWrap = new GameObject("Buttons", typeof(RectTransform));
        btnWrap.transform.SetParent(card, false);
        _goButtonsRoot = btnWrap.GetComponent<RectTransform>();
        Place(_goButtonsRoot, C, new Vector2(0, -480), new Vector2(860, 400));
        _cgButtons = btnWrap.AddComponent<CanvasGroup>();

        _goRestart = MakeButton(btnWrap.transform, "PLAY AGAIN", new Vector2(0, 80), new Vector2(600, 170),
            new Color(0.30f, 0.75f, 0.40f), 76);
        _goHome = MakeButton(btnWrap.transform, "MAIN MENU", new Vector2(0, -110), new Vector2(600, 140),
            new Color(0.30f, 0.55f, 0.95f), 56);
    }

    void BuildPauseButton()
    {
        var img = MakeSprite("PauseBtn", _canvas.transform, new Color(0f, 0f, 0f, 0.4f));
        _pauseBtn = img.rectTransform;
        _pauseBtn.anchorMin = _pauseBtn.anchorMax = new Vector2(1f, 1f);
        _pauseBtn.pivot = new Vector2(1f, 1f);
        _pauseBtn.anchoredPosition = new Vector2(-30, -40);
        _pauseBtn.sizeDelta = new Vector2(150, 92);

        var t = MakeText("Txt", img.transform, 56, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        t.text = "| |";
        Place(t.rectTransform, new Vector2(0.5f, 0.5f), Vector2.zero, new Vector2(150, 92));
        _pauseBtn.gameObject.SetActive(false);
    }

    // ===================== HELPER UI =====================
    static readonly Vector2 C = new Vector2(0.5f, 0.5f);

    Color PaletteA(int i, float a)
    {
        var c = Palette[((i % Palette.Length) + Palette.Length) % Palette.Length];
        c.a = a;
        return c;
    }

    void MakeDecoRow(Transform parent, Vector2 pos)
    {
        const int n = 5;
        const float step = 120f;
        for (int i = 0; i < n; i++)
        {
            var b = MakeSprite("deco" + i, parent, PaletteA(i, 1f));
            Place(b.rectTransform, C, new Vector2(pos.x + (i - (n - 1) / 2f) * step, pos.y), new Vector2(76, 76));
        }
    }

    RectTransform MakeCard(Transform parent, Vector2 pos, Vector2 size, Color col)
    {
        var img = MakeSprite("Card", parent, col);
        Place(img.rectTransform, C, pos, size);
        return img.rectTransform;
    }

    GameObject MakePanel(string name, Color col)
    {
        var img = MakeImage(name, _canvas.transform, col);
        Stretch(img.rectTransform);
        return img.gameObject;
    }

    void Stretch(RectTransform rt)
    {
        rt.anchorMin = Vector2.zero; rt.anchorMax = Vector2.one; rt.pivot = C;
        rt.offsetMin = Vector2.zero; rt.offsetMax = Vector2.zero;
    }

    RectTransform MakeButton(Transform parent, string label, Vector2 pos, Vector2 size, Color bg, int fontSize)
    {
        var img = MakeSprite(label + "Btn", parent, bg);
        Place(img.rectTransform, C, pos, size);
        var t = MakeText(label + "Txt", img.transform, fontSize, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        t.text = label;
        Place(t.rectTransform, C, Vector2.zero, size);
        return img.rectTransform;
    }

    Text MakeText(string name, Transform parent, int size, TextAnchor anchor, FontStyle style, Color col)
    {
        var go = new GameObject(name, typeof(RectTransform));
        go.transform.SetParent(parent, false);
        var t = go.AddComponent<Text>();
        t.font = UIFont();
        t.fontSize = size;
        t.alignment = anchor;
        t.fontStyle = style;
        t.color = col;
        t.raycastTarget = false;
        t.horizontalOverflow = HorizontalWrapMode.Overflow;
        t.verticalOverflow = VerticalWrapMode.Overflow;
        var sh = go.AddComponent<Shadow>();
        sh.effectColor = new Color(0f, 0f, 0f, 0.55f);
        sh.effectDistance = new Vector2(3f, -3f);
        return t;
    }

    Image MakeImage(string name, Transform parent, Color col)
    {
        var go = new GameObject(name, typeof(RectTransform));
        go.transform.SetParent(parent, false);
        var img = go.AddComponent<Image>();
        img.color = col;
        img.raycastTarget = false;
        return img;
    }

    Image MakeSprite(string name, Transform parent, Color col)
    {
        var img = MakeImage(name, parent, col);
        img.sprite = RoundSprite();
        img.type = Image.Type.Sliced;
        return img;
    }

    Sprite RoundSprite()
    {
        if (_round != null) return _round;
        int size = 48, radius = 14;
        var tex = new Texture2D(size, size, TextureFormat.RGBA32, false);
        tex.wrapMode = TextureWrapMode.Clamp;
        tex.filterMode = FilterMode.Bilinear;
        var px = new Color32[size * size];
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
            {
                float a = RoundedAlpha(x, y, size, size, radius);
                px[y * size + x] = new Color32(255, 255, 255, (byte)Mathf.RoundToInt(a * 255f));
            }
        tex.SetPixels32(px);
        tex.Apply();
        float b = radius;
        _round = Sprite.Create(tex, new Rect(0, 0, size, size), new Vector2(0.5f, 0.5f), 100f, 0,
            SpriteMeshType.FullRect, new Vector4(b, b, b, b));
        return _round;
    }

    Sprite GradientSprite(Color top, Color bottom)
    {
        if (_gradient != null) return _gradient;
        int h = 64;
        var tex = new Texture2D(1, h, TextureFormat.RGBA32, false);
        tex.wrapMode = TextureWrapMode.Clamp;
        tex.filterMode = FilterMode.Bilinear;
        for (int y = 0; y < h; y++)
        {
            float f = (float)y / (h - 1);
            tex.SetPixel(0, y, Color.Lerp(bottom, top, f));
        }
        tex.Apply();
        _gradient = Sprite.Create(tex, new Rect(0, 0, 1, h), new Vector2(0.5f, 0.5f), 100f);
        return _gradient;
    }

    static float RoundedAlpha(int x, int y, int w, int h, float radius)
    {
        float px = x + 0.5f, py = y + 0.5f;
        float dx = Mathf.Max(Mathf.Max(radius - px, px - (w - radius)), 0f);
        float dy = Mathf.Max(Mathf.Max(radius - py, py - (h - radius)), 0f);
        float dist = Mathf.Sqrt(dx * dx + dy * dy);
        return Mathf.Clamp01(radius - dist + 0.5f);
    }

    void Place(RectTransform rt, Vector2 anchor, Vector2 pos, Vector2 size)
    {
        rt.anchorMin = anchor; rt.anchorMax = anchor; rt.pivot = anchor;
        rt.anchoredPosition = pos; rt.sizeDelta = size;
    }

    Font UIFont()
    {
        if (_font != null) return _font;
        _font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        if (_font == null) _font = Resources.GetBuiltinResource<Font>("Arial.ttf");
        if (_font == null) _font = Font.CreateDynamicFontFromOSFont("Arial", 16);
        return _font;
    }

    bool Hit(RectTransform rt, Vector2 sp)
        => rt != null && rt.gameObject.activeInHierarchy
           && RectTransformUtility.RectangleContainsScreenPoint(rt, sp, null);

    // ===================== INPUT ABSTRAKSI =====================
    Vector2 PPos()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null) return m.position.ReadValue();
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null) return ts.primaryTouch.position.ReadValue();
        return Vector2.zero;
#else
        return Input.mousePosition;
#endif
    }

    bool PDown()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null && m.leftButton.wasPressedThisFrame) return true;
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null && ts.primaryTouch.press.wasPressedThisFrame) return true;
        return false;
#else
        return Input.GetMouseButtonDown(0);
#endif
    }

    bool PHeld()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null && m.leftButton.isPressed) return true;
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null && ts.primaryTouch.press.isPressed) return true;
        return false;
#else
        return Input.GetMouseButton(0);
#endif
    }
}
