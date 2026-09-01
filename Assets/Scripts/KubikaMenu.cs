// Dukung DUA backend input Unity (Input Manager lama & Input System baru).
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

// BAGIAN 1 dari 2 (logika/state). Pembangun UI ada di KubikaMenuUI.cs.
// Dipecah jadi partial class supaya tiap file tetap kecil dan aman di-push.

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
/// </summary>
public partial class KubikaMenu : MonoBehaviour
{
    public static KubikaMenu Instance { get; private set; }

    // Kalimat pujian saat game over (dipilih acak sesuai hasil ronde).
    static readonly string[] MotivationRecord =
    {
        "A brand new record. That was your best run yet.",
        "You just beat yourself, and that is the hardest opponent there is.",
        "New personal best. Everything clicked this time.",
        "Record broken. All that practice finally showed up.",
    };

    static readonly string[] MotivationStrong =
    {
        "So close to your best. One more run and it is yours.",
        "That was a strong run. You read the board well.",
        "You kept that board alive far longer than it wanted to stay.",
        "You are getting sharper every single round.",
    };

    static readonly string[] MotivationSolid =
    {
        "Good run. Every board teaches you something new.",
        "Nice work out there. The next one will go further.",
        "Solid effort. The momentum is building.",
        "You held it together under pressure. That counts.",
    };

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
    public static string CurrentScreenName = "Home";

    const string LB_KEY = "kubika_leaderboard";
    const string MUSIC_KEY = "kubika_music_vol";
    const string SFX_KEY = "kubika_sfx_vol";
    const string FPS_KEY = "kubika_fps";

    static readonly int[] FPS_OPTS = { 30, 60, 90, 120 };

    static readonly Color[] Palette =
    {
        new Color(1.00f, 0.36f, 0.48f),
        new Color(1.00f, 0.72f, 0.30f),
        new Color(1.00f, 0.84f, 0.31f),
        new Color(0.40f, 0.73f, 0.42f),
        new Color(0.31f, 0.76f, 0.97f),
        new Color(0.73f, 0.41f, 0.78f),
        new Color(0.30f, 0.82f, 0.88f),
    };

    BlastGame _game;
    BlastInput _input;
    bool _init;
    bool _prevGameOver;
    bool _everStarted;

    Canvas _canvas;
    Font _font;
    Sprite _round, _gradient, _crown, _glow, _gear, _pauseIcon;

    GameObject _homePanel, _pausePanel, _settingsPanel, _goPanel;
    RectTransform _pauseBtn;
    RectTransform _btnMain, _btnSettingsHome;
    RectTransform _btnResume, _btnSettingsPause, _btnHome;
    RectTransform _btnBackSettings;
    RectTransform _goRestart, _goHome;
    RectTransform _musicBar, _sfxBar, _fpsBar, _musicFill, _sfxFill, _fpsFill;
    Text _musicPct, _sfxPct, _fpsPct, _goScore, _goBest;

    RectTransform _top5Root;
    RectTransform _playHalo;
    Image _playHaloImg;

    Text _goTitle, _goMotivation, _goRecord, _goStats;
    RectTransform _goTitleRT, _goScoreRT, _goRecordRT;
    CanvasGroup _cgTitle, _cgMotivation, _cgScore, _cgRecord, _cgStats, _cgButtons;
    RectTransform _goButtonsRoot;
    Coroutine _reveal;

    float _sliderWidth = 640f;
    float _musicVal = 0.32f, _sfxVal = 0.8f, _fpsVal = 1f / 3f;
    bool _dragMusic, _dragSfx, _dragFps;

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

        if (core != null)
        {
            if (core.GameOver && !_prevGameOver && _screen == UIScreen.Playing)
            {
                var before = LoadScores();
                int bestBefore = (before.Count > 0) ? before[0] : 0;
                RecordScore(core.Score);
                ShowGameOver(core, bestBefore);
            }
            _prevGameOver = core.GameOver;
        }

        AnimateBackground();
        AnimatePlay();
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

    void StartGame()
    {
        StopReveal();
        SetState(UIScreen.Playing);
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
        SetCG(_cgTitle, 0f); SetCG(_cgMotivation, 0f); SetCG(_cgScore, 0f);
        SetCG(_cgRecord, 0f); SetCG(_cgStats, 0f); SetCG(_cgButtons, 0f);
        if (_goTitleRT != null) _goTitleRT.localScale = Vector3.one * 0.8f;
        if (_goRecordRT != null) _goRecordRT.localScale = Vector3.one * 0.6f;
        if (_goScoreRT != null) _goScoreRT.localScale = Vector3.one;

        yield return Wait(0.18f);
        yield return Pop(_cgTitle, _goTitleRT, 0.28f, 0.8f, 1f);
        yield return Fade(_cgMotivation, 0.30f);
        yield return Wait(0.14f);
        SetCG(_cgScore, 1f);
        yield return CountUp(score, 0.85f);
        yield return Punch(_goScoreRT, 0.22f, 1.14f);
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
        yield return Wait(0.06f);
        yield return Fade(_cgStats, 0.30f);
        yield return Wait(0.06f);
        yield return Fade(_cgButtons, 0.26f);

        _reveal = null;
    }

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
            float ease = 1f - Mathf.Pow(1f - k, 3f);
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
