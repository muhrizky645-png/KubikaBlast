// BAGIAN 2 dari 2 (pembangun UI). Logika/state ada di KubikaMenu.cs.

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public partial class KubikaMenu
{
    static readonly Vector2 C = new Vector2(0.5f, 0.5f);

    // ===================== PALET TOMBOL (MATTE) =====================
    // Warna sengaja diturunkan saturasi & kecerahannya supaya tidak terlihat
    // "mengkilap" seperti plastik. Tiap warna dipakai konsisten di semua layar.
    static readonly Color BTN_GREEN = new Color(0.26f, 0.62f, 0.38f);   // aksi utama (PLAY / RESUME)
    static readonly Color BTN_BLUE  = new Color(0.27f, 0.45f, 0.74f);   // aksi kedua (SETTINGS)
    static readonly Color BTN_SLATE = new Color(0.33f, 0.35f, 0.45f);   // netral (MAIN MENU)
    static readonly Color BTN_GRAY  = new Color(0.38f, 0.40f, 0.49f);   // netral terang (BACK)

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
            var img = MakeSprite("bgb" + i, go.transform, PaletteA(Random.Range(0, Palette.Length), Random.Range(0.28f, 0.5f)));
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

    // Denyut tombol PLAY dibuat jauh lebih halus supaya tidak terlihat berkilau.
    void AnimatePlay()
    {
        if (_screen != UIScreen.Home || _btnMain == null) return;
        float t = Time.unscaledTime;
        float wave = Mathf.Sin(t * 2.6f);
        _btnMain.localScale = Vector3.one * (1f + wave * 0.016f);
        if (_playHalo != null)
            _playHalo.localScale = Vector3.one * (1f + wave * 0.05f);
        if (_playHaloImg != null)
        {
            var c = _playHaloImg.color;
            c.a = 0.06f + (wave * 0.5f + 0.5f) * 0.09f;
            _playHaloImg.color = c;
        }
    }

    // ---- HOME ----
    void BuildHome()
    {
        _homePanel = MakePanel("HomePanel", new Color(0f, 0f, 0f, 0f));
        var root = _homePanel.transform;

        var title = MakeText("Title", root, 122, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.85f, 0.25f));
        title.text = "KUBIKA\nBLAST";
        Place(title.rectTransform, C, new Vector2(0, 780), new Vector2(1000, 360));
        MakeDecoRow(root, new Vector2(0, 560));

        // Halo emas lembut di belakang kartu skor.
        var cardHalo = MakeGlow(root, new Color(1f, 0.84f, 0.31f, 0.13f));
        Place(cardHalo.rectTransform, C, new Vector2(0, 140), new Vector2(1040, 920));

        var card = MakeCard(root, new Vector2(0, 140), new Vector2(820, 700), new Color(0.10f, 0.12f, 0.20f, 0.90f));

        // Mahkota di puncak kartu (menyembul sedikit di atas tepi kartu).
        var crown = CrownSprite();
        if (crown != null)
        {
            var cimg = MakeImage("Crown", card, Color.white);
            cimg.sprite = crown;
            cimg.type = Image.Type.Simple;
            cimg.preserveAspect = true;
            Place(cimg.rectTransform, C, new Vector2(0, 320), new Vector2(120, 120));
        }

        var top5Title = MakeText("Top5Title", card, 60, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.84f, 0.31f));
        top5Title.text = "TOP 5";
        Place(top5Title.rectTransform, C, new Vector2(0, 220), new Vector2(620, 72));

        // Wadah baris peringkat (diisi ulang tiap kali Home dibuka, lihat RefreshHome).
        var listGO = new GameObject("Top5Root", typeof(RectTransform));
        listGO.transform.SetParent(card, false);
        _top5Root = listGO.GetComponent<RectTransform>();
        Place(_top5Root, C, new Vector2(0, -60), new Vector2(720, 480));

        // Halo hijau berdenyut di belakang tombol PLAY (sangat tipis).
        _playHaloImg = MakeGlow(root, new Color(0.30f, 0.78f, 0.45f, 0f));
        _playHalo = _playHaloImg.rectTransform;
        Place(_playHalo, C, new Vector2(0, -560), new Vector2(940, 420));

        _btnMain = MakeButton(root, "PLAY", new Vector2(0, -560), new Vector2(620, 180), BTN_GREEN, 84);

        // Tombol SETTING = ikon gerigi kecil di pojok kanan atas (bukan tombol teks lagi).
        var gearImg = MakeSprite("SettingsGear", root, new Color(0f, 0f, 0f, 0.4f));
        _btnSettingsHome = gearImg.rectTransform;
        _btnSettingsHome.anchorMin = _btnSettingsHome.anchorMax = new Vector2(1f, 1f);
        _btnSettingsHome.pivot = new Vector2(1f, 1f);
        _btnSettingsHome.anchoredPosition = new Vector2(-36, -46);
        _btnSettingsHome.sizeDelta = new Vector2(128, 128);
        var gearSp = IconSprite("Gear_A", ref _gear);
        if (gearSp != null)
        {
            var gi = MakeImage("GearIcon", _btnSettingsHome, Color.white);
            gi.sprite = gearSp;
            gi.preserveAspect = true;
            Place(gi.rectTransform, C, Vector2.zero, new Vector2(96, 96));
        }
        else
        {
            var gt = MakeText("GearTxt", _btnSettingsHome, 60, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
            gt.text = "\u2699";
            Place(gt.rectTransform, C, Vector2.zero, new Vector2(128, 128));
        }
    }

    void RefreshHome()
    {
        if (_top5Root == null) return;

        for (int i = _top5Root.childCount - 1; i >= 0; i--)
            Destroy(_top5Root.GetChild(i).gameObject);

        var list = LoadScores();
        if (list.Count == 0)
        {
            var empty = MakeText("EmptyMsg", _top5Root, 46, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(0.80f, 0.85f, 0.95f));
            empty.text = "No scores yet.\nPlay your first round!";
            Place(empty.rectTransform, C, Vector2.zero, new Vector2(700, 220));
            return;
        }

        Color gold = new Color(1f, 0.84f, 0.31f);
        Color silver = new Color(0.82f, 0.85f, 0.90f);
        Color bronze = new Color(0.88f, 0.58f, 0.36f);

        int n = Mathf.Min(5, list.Count);
        float rowH = 80f, gap = 12f;
        float totalH = n * rowH + (n - 1) * gap;
        float startY = totalH * 0.5f - rowH * 0.5f;

        for (int i = 0; i < n; i++)
        {
            Color medal = (i == 0) ? gold : (i == 1) ? silver : (i == 2) ? bronze : new Color(0.45f, 0.50f, 0.62f);
            float y = startY - i * (rowH + gap);

            var row = MakeSprite("row" + i, _top5Root, new Color(medal.r, medal.g, medal.b, i < 3 ? 0.22f : 0.12f));
            Place(row.rectTransform, C, new Vector2(0, y), new Vector2(700, rowH));

            var rank = MakeText("rank" + i, row.transform, 48, TextAnchor.MiddleLeft, FontStyle.Bold, i < 3 ? medal : Color.white);
            rank.text = "#" + (i + 1);
            Place(rank.rectTransform, C, new Vector2(-230, 0), new Vector2(200, rowH));

            var sc = MakeText("sc" + i, row.transform, 52, TextAnchor.MiddleRight, FontStyle.Bold, Color.white);
            sc.text = list[i].ToString();
            Place(sc.rectTransform, C, new Vector2(180, 0), new Vector2(300, rowH));
        }
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

        _btnResume = MakeButton(card, "RESUME", new Vector2(0, 20), new Vector2(600, 160), BTN_GREEN, 76);
        _btnSettingsPause = MakeButton(card, "SETTINGS", new Vector2(0, -170), new Vector2(600, 140), BTN_BLUE, 56);
        _btnHome = MakeButton(card, "MAIN MENU", new Vector2(0, -340), new Vector2(600, 140), BTN_SLATE, 56);
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

        BuildSlider(card, "MUSIC", 300, new Color(0.28f, 0.70f, 0.42f),
            out _musicBar, out _musicFill, out _musicPct);
        BuildSlider(card, "SFX", 90, new Color(0.90f, 0.64f, 0.30f),
            out _sfxBar, out _sfxFill, out _sfxPct);
        BuildSlider(card, "SMOOTHNESS", -120, new Color(0.31f, 0.66f, 0.86f),
            out _fpsBar, out _fpsFill, out _fpsPct);

        var hint = MakeText("Hint", card, 36, TextAnchor.MiddleCenter, FontStyle.Normal, new Color(0.72f, 0.77f, 0.88f));
        hint.text = "Higher FPS is smoother. Lower it if your phone gets hot or laggy.";
        Place(hint.rectTransform, C, new Vector2(0, -250), new Vector2(840, 80));

        _btnBackSettings = MakeButton(card, "BACK", new Vector2(0, -560), new Vector2(520, 150), BTN_GRAY, 62);
    }

    void BuildSlider(Transform root, string label, float y, Color fillColor,
        out RectTransform bar, out RectTransform fill, out Text pct)
    {
        // Label kiri & persen kanan diposisikan agar muat penuh di dalam kartu.
        var lbl = MakeText(label + "Lbl", root, 52, TextAnchor.MiddleLeft, FontStyle.Bold, Color.white);
        lbl.text = label;
        Place(lbl.rectTransform, C, new Vector2(-180, y + 70), new Vector2(520, 70));

        pct = MakeText(label + "Pct", root, 50, TextAnchor.MiddleRight, FontStyle.Bold, new Color(1f, 0.85f, 0.3f));
        Place(pct.rectTransform, C, new Vector2(220, y + 70), new Vector2(400, 70));

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

    // ---- GAME OVER ----
    void BuildGameOver()
    {
        _goPanel = MakePanel("GameOverPanel", new Color(0f, 0f, 0f, 0f));
        var root = _goPanel.transform;

        var card = MakeCard(root, new Vector2(0, 40), new Vector2(900, 1480), new Color(0.12f, 0.10f, 0.22f, 0.95f));
        MakeDecoRow(card, new Vector2(0, 660));

        _goTitle = MakeText("GO", card, 108, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.36f, 0.48f));
        _goTitle.text = "GAME OVER";
        Place(_goTitle.rectTransform, C, new Vector2(0, 520), new Vector2(840, 170));
        _goTitleRT = _goTitle.rectTransform;
        _cgTitle = _goTitle.gameObject.AddComponent<CanvasGroup>();

        _goMotivation = MakeText("Motivation", card, 42, TextAnchor.MiddleCenter, FontStyle.Normal, new Color(0.86f, 0.90f, 1f));
        _goMotivation.horizontalOverflow = HorizontalWrapMode.Wrap;
        _goMotivation.text = "";
        Place(_goMotivation.rectTransform, C, new Vector2(0, 370), new Vector2(780, 130));
        _cgMotivation = _goMotivation.gameObject.AddComponent<CanvasGroup>();

        var scoreWrap = MakeText("ScoreWrap", card, 44, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(0.75f, 0.8f, 0.9f));
        scoreWrap.text = "FINAL SCORE";
        Place(scoreWrap.rectTransform, C, new Vector2(0, 240), new Vector2(700, 70));
        _cgScore = scoreWrap.gameObject.AddComponent<CanvasGroup>();

        _goScore = MakeText("Score", scoreWrap.transform, 132, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.84f, 0.31f));
        _goScore.text = "0";
        Place(_goScore.rectTransform, C, new Vector2(0, -110), new Vector2(760, 170));
        _goScoreRT = _goScore.rectTransform;

        _goRecord = MakeText("Record", card, 76, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.84f, 0.31f));
        _goRecord.text = "";
        Place(_goRecord.rectTransform, C, new Vector2(0, -20), new Vector2(800, 110));
        _goRecordRT = _goRecord.rectTransform;
        _cgRecord = _goRecord.gameObject.AddComponent<CanvasGroup>();

        _goBest = _goRecord;

        _goStats = MakeText("Stats", card, 40, TextAnchor.UpperCenter, FontStyle.Bold, new Color(0.80f, 0.85f, 0.95f));
        _goStats.text = "";
        Place(_goStats.rectTransform, C, new Vector2(0, -190), new Vector2(760, 240));
        _cgStats = _goStats.gameObject.AddComponent<CanvasGroup>();

        var btnWrap = new GameObject("Buttons", typeof(RectTransform));
        btnWrap.transform.SetParent(card, false);
        _goButtonsRoot = btnWrap.GetComponent<RectTransform>();
        Place(_goButtonsRoot, C, new Vector2(0, -480), new Vector2(860, 400));
        _cgButtons = btnWrap.AddComponent<CanvasGroup>();

        _goRestart = MakeButton(btnWrap.transform, "PLAY AGAIN", new Vector2(0, 80), new Vector2(600, 170), BTN_GREEN, 76);
        // MAIN MENU dibuat sama dengan yang di layar PAUSED supaya konsisten.
        _goHome = MakeButton(btnWrap.transform, "MAIN MENU", new Vector2(0, -110), new Vector2(600, 140), BTN_SLATE, 56);
    }

    void BuildPauseButton()
    {
        var img = MakeSprite("PauseBtn", _canvas.transform, new Color(0f, 0f, 0f, 0.4f));
        _pauseBtn = img.rectTransform;
        _pauseBtn.anchorMin = _pauseBtn.anchorMax = new Vector2(1f, 1f);
        _pauseBtn.pivot = new Vector2(1f, 1f);
        _pauseBtn.anchoredPosition = new Vector2(-36, -46);
        _pauseBtn.sizeDelta = new Vector2(128, 128);

        var pauseSp = IconSprite("Pause_A", ref _pauseIcon);
        if (pauseSp != null)
        {
            var pi = MakeImage("PauseIcon", img.transform, Color.white);
            pi.sprite = pauseSp;
            pi.preserveAspect = true;
            Place(pi.rectTransform, C, Vector2.zero, new Vector2(80, 80));
        }
        else
        {
            var t = MakeText("Txt", img.transform, 56, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
            t.text = "| |";
            Place(t.rectTransform, C, Vector2.zero, new Vector2(128, 128));
        }
        _pauseBtn.gameObject.SetActive(false);
    }

    // ===================== HELPER UI =====================
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
            var b = MakeSprite("deco" + i, parent, PaletteA(i, 0.92f));
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

    // Tombol gaya MATTE:
    // - TIDAK ada lapisan kilau (gloss) putih di muka tombol.
    // - Ketebalan tetap terasa dari sisi bawah yang lebih gelap + bayangan lembut.
    // - Cuma ada garis rim sangat tipis di tepi atas supaya bentuknya tetap terbaca.
    RectTransform MakeButton(Transform parent, string label, Vector2 pos, Vector2 size, Color bg, int fontSize)
    {
        var containerGO = new GameObject(label + "Btn", typeof(RectTransform));
        containerGO.transform.SetParent(parent, false);
        var container = containerGO.GetComponent<RectTransform>();
        Place(container, C, pos, size);

        float depth = Mathf.Clamp(size.y * 0.12f, 8f, 18f);

        var shadow = MakeSprite(label + "Sh", container, new Color(0f, 0f, 0f, 0.20f));
        Place(shadow.rectTransform, C, new Vector2(0f, -depth * 0.85f), size);

        var baseImg = MakeSprite(label + "Base", container, Darken(bg, 0.64f));
        Place(baseImg.rectTransform, C, new Vector2(0f, -depth), size);

        var face = MakeSprite(label + "Face", container, bg);
        Place(face.rectTransform, C, Vector2.zero, size);

        var rim = MakeSprite(label + "Rim", face.transform, new Color(1f, 1f, 1f, 0.045f));
        Place(rim.rectTransform, C, new Vector2(0f, size.y * 0.5f - 6f), new Vector2(size.x - 28f, 6f));

        var t = MakeText(label + "Txt", face.transform, fontSize, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(0.97f, 0.98f, 1f));
        t.text = label;
        Place(t.rectTransform, C, Vector2.zero, size);

        return container;
    }

    static Color Darken(Color c, float f) => new Color(c.r * f, c.g * f, c.b * f, c.a);

    Image MakeGlow(Transform parent, Color col)
    {
        var img = MakeImage("Glow", parent, col);
        img.sprite = GlowSprite();
        img.type = Image.Type.Simple;
        img.raycastTarget = false;
        return img;
    }

    Sprite GlowSprite()
    {
        if (_glow != null) return _glow;
        int size = 64;
        var tex = new Texture2D(size, size, TextureFormat.RGBA32, false);
        tex.wrapMode = TextureWrapMode.Clamp;
        tex.filterMode = FilterMode.Bilinear;
        var px = new Color32[size * size];
        Vector2 ctr = new Vector2(size * 0.5f, size * 0.5f);
        float maxd = size * 0.5f;
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
            {
                float d = Vector2.Distance(new Vector2(x + 0.5f, y + 0.5f), ctr) / maxd;
                float a = Mathf.Clamp01(1f - d);
                a = a * a;
                px[y * size + x] = new Color32(255, 255, 255, (byte)Mathf.RoundToInt(a * 255f));
            }
        tex.SetPixels32(px);
        tex.Apply();
        _glow = Sprite.Create(tex, new Rect(0, 0, size, size), new Vector2(0.5f, 0.5f), 100f);
        return _glow;
    }

    Sprite CrownSprite()
    {
        if (_crown != null) return _crown;
        var tex = Resources.Load<Texture2D>("KubikaIcons/Crown_A");
        if (tex != null)
            _crown = Sprite.Create(tex, new Rect(0, 0, tex.width, tex.height), new Vector2(0.5f, 0.5f), 100f);
        return _crown;
    }

    // Ikon umum dari Resources/KubikaIcons (null-safe kalau belum ada).
    Sprite IconSprite(string name, ref Sprite cache)
    {
        if (cache != null) return cache;
        var tex = Resources.Load<Texture2D>("KubikaIcons/" + name);
        if (tex != null)
            cache = Sprite.Create(tex, new Rect(0, 0, tex.width, tex.height), new Vector2(0.5f, 0.5f), 100f);
        return cache;
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
        // Bayangan teks dibuat lebih lembut supaya tidak menambah kesan mengkilap.
        var sh = go.AddComponent<Shadow>();
        sh.effectColor = new Color(0f, 0f, 0f, 0.40f);
        sh.effectDistance = new Vector2(2f, -2f);
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
}
