// Dukung DUA backend input Unity (Input Manager lama & Input System baru),
// sama seperti BlastInput/BlastUI, supaya tombol menu jalan tanpa ubah Player Settings.
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

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
///  - HOME: judul + dekorasi + kartu TOP 5 (langsung tampil, tanpa tombol
///    leaderboard) + tombol MAIN & PENGATURAN.
///  - PENGATURAN: kartu berisi slider MUSIK, SFX, KELANCARAN (FPS).
///  - GAME OVER: layar custom (menutupi panel bawaan) dengan skor & skor
///    terbaik + MAIN LAGI & MENU UTAMA.
///  - Tombol JEDA saat main -> panel jeda.
///
/// Semua tap dideteksi manual (tanpa EventSystem). Saat menu/jeda terbuka:
/// Time.timeScale = 0 dan BlastInput dimatikan. Animasi background pakai
/// unscaledDeltaTime agar tetap bergerak walau game di-pause.
/// </summary>
public class KubikaMenu : MonoBehaviour
{
    public static KubikaMenu Instance { get; private set; }

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
        // aktif. Mencegah game "stuck tak bisa dipencet" bila ada yang mematikannya.
        if (_screen == UIScreen.Playing && (core == null || !core.GameOver))
        {
            if (Time.timeScale != 1f) Time.timeScale = 1f;
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
                RecordScore(core.Score);
                ShowGameOver(core.Score);
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

        Time.timeScale = (s == UIScreen.Playing) ? 1f : 0f;
        if (_input != null) _input.enabled = (s == UIScreen.Playing);
    }

    bool _everStarted;
    void StartGame()
    {
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

    void ShowGameOver(int score)
    {
        if (_goScore != null) _goScore.text = score.ToString();
        var list = LoadScores();
        int best = (list.Count > 0) ? list[0] : score;
        if (_goBest != null) _goBest.text = "Skor terbaik: " + best;
        SetState(UIScreen.GameOver);
    }

    // ===================== FPS / KELANCARAN =====================
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
        if (list.Count == 0) { _homeTop5.text = "Belum ada skor.\nAyo main dulu!"; return; }
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

        _btnMain = MakeButton(root, "MAIN", new Vector2(0, -560), new Vector2(620, 180),
            new Color(0.30f, 0.75f, 0.40f), 84);
        _btnSettingsHome = MakeButton(root, "PENGATURAN", new Vector2(0, -790), new Vector2(620, 150),
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
        title.text = "JEDA";
        Place(title.rectTransform, C, new Vector2(0, 180), new Vector2(700, 160));

        _btnResume = MakeButton(card, "LANJUT", new Vector2(0, 20), new Vector2(600, 160),
            new Color(0.30f, 0.75f, 0.40f), 76);
        _btnSettingsPause = MakeButton(card, "PENGATURAN", new Vector2(0, -170), new Vector2(600, 140),
            new Color(0.30f, 0.55f, 0.95f), 56);
        _btnHome = MakeButton(card, "MENU UTAMA", new Vector2(0, -340), new Vector2(600, 140),
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
        title.text = "PENGATURAN";
        Place(title.rectTransform, C, new Vector2(0, 520), new Vector2(860, 140));

        BuildSlider(card, "MUSIK", 300, new Color(0.30f, 0.80f, 0.45f),
            out _musicBar, out _musicFill, out _musicPct);
        BuildSlider(card, "SFX", 90, new Color(1.00f, 0.72f, 0.30f),
            out _sfxBar, out _sfxFill, out _sfxPct);
        BuildSlider(card, "KELANCARAN", -120, new Color(0.31f, 0.76f, 0.97f),
            out _fpsBar, out _fpsFill, out _fpsPct);

        var hint = MakeText("Hint", card, 36, TextAnchor.MiddleCenter, FontStyle.Normal, new Color(0.72f, 0.77f, 0.88f));
        hint.text = "FPS lebih tinggi = lebih mulus (kurangi bila HP panas/lag)";
        Place(hint.rectTransform, C, new Vector2(0, -250), new Vector2(860, 80));

        _btnBackSettings = MakeButton(card, "KEMBALI", new Vector2(0, -560), new Vector2(520, 150),
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

    // ---- GAME OVER (custom) ----
    void BuildGameOver()
    {
        _goPanel = MakePanel("GameOverPanel", new Color(0f, 0f, 0f, 0f));
        var root = _goPanel.transform;

        var card = MakeCard(root, new Vector2(0, 60), new Vector2(880, 1160), new Color(0.12f, 0.10f, 0.22f, 0.95f));
        MakeDecoRow(card, new Vector2(0, 440));

        var t = MakeText("GO", card, 112, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.36f, 0.48f));
        t.text = "GAME OVER";
        Place(t.rectTransform, C, new Vector2(0, 300), new Vector2(840, 180));

        var lbl = MakeText("ScoreLbl", card, 48, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(0.75f, 0.8f, 0.9f));
        lbl.text = "SKOR AKHIR";
        Place(lbl.rectTransform, C, new Vector2(0, 130), new Vector2(700, 70));

        _goScore = MakeText("Score", card, 134, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.84f, 0.31f));
        _goScore.text = "0";
        Place(_goScore.rectTransform, C, new Vector2(0, 20), new Vector2(760, 170));

        _goBest = MakeText("Best", card, 46, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        _goBest.text = "Skor terbaik: 0";
        Place(_goBest.rectTransform, C, new Vector2(0, -130), new Vector2(760, 70));

        _goRestart = MakeButton(card, "MAIN LAGI", new Vector2(0, -320), new Vector2(600, 170),
            new Color(0.30f, 0.75f, 0.40f), 76);
        _goHome = MakeButton(card, "MENU UTAMA", new Vector2(0, -510), new Vector2(600, 140),
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
