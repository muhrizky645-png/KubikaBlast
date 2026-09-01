// BAGIAN 2 dari 3 (pembangun UI umum).
// Logika/state -> KubikaMenu.cs
// Tema visual (background terang + layar GAME OVER) -> KubikaMenuTheme.cs

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

    // Kotak hias layar JEDA: x, y, ukuran, rotasi.
    // Posisinya TETAP (bukan acak) dan sengaja dijauhkan dari area kartu jeda
    // (kartu ada di tengah, 760x980 -> y -450..530) supaya tidak pernah menabrak
    // teks atau tombol.
    static readonly float[,] PAUSE_DECO =
    {
        { -420f,  880f, 150f,  18f },
        {  405f,  985f, 190f, -12f },
        { -300f,  625f, 100f,  32f },
        {  470f,  600f, 120f,  24f },
        { -475f, -560f, 170f, -20f },
        {  430f, -605f, 140f,  14f },
        { -350f, -865f, 110f,  28f },
        {  360f, -900f, 180f, -26f },
    };

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

        var card = MakeCard(root, new Vector2(0, 140), new Vector2(820, 700), CARD_DEEP);

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
    // Dulu layar jeda cuma satu lapisan HITAM (alpha 0.72) di atas board yang
    // membeku. Hasilnya kartu jeda terasa "mengapung" / nyempil, karena dia satu-
    // satunya benda di layar dan tidak punya latar yang jadi pijakannya.
    // Sekarang layar jeda punya latar sendiri, memakai gradient yang SAMA dengan
    // background menu supaya satu bahasa visual dengan Home/Settings/GameOver.
    //
    // TATA LETAK: kartu 760x980 (dulu 840). Dengan tinggi 840, tombol MAIN MENU di
    // y -340 dengan tinggi 140 punya tepi bawah di -410, sementara dasar kartu cuma
    // di -380 -- jadi tombolnya BOCOR 30px keluar kartu, plus lapisan bayangan 3D
    // dari MakeButton (~17px) di bawahnya lagi. Sekarang isi kartu digeser naik dan
    // kartunya ditinggikan, menyisakan ~43px jarak aman di bawah MAIN MENU.
    void BuildPause()
    {
        _pausePanel = MakePanel("PausePanel", new Color(0f, 0f, 0f, 0f));
        var root = _pausePanel.transform;

        // GradientSprite() di-cache, jadi ini otomatis sprite yang sama dengan
        // background menu — bukan tekstur baru, dan warnanya dijamin cocok.
        // Alpha sengaja TIDAK 1: board yang membeku masih terlihat samar di
        // belakang, jadi pemain tetap sadar permainannya cuma dijeda.
        var grad = MakeImage("PauseBg", root, new Color(1f, 1f, 1f, 0.88f));
        grad.sprite = GradientSprite(BG_TOP, BG_BOTTOM);
        grad.type = Image.Type.Simple;
        Stretch(grad.rectTransform);

        // Kotak pastel STATIS (tidak dianimasikan — layar jeda memang seharusnya
        // terasa berhenti, bukan bergerak seperti Home).
        for (int i = 0; i < PAUSE_DECO.GetLength(0); i++)
        {
            var d = MakeSprite("pdeco" + i, root, PaletteA(i, 0.55f));
            float s = PAUSE_DECO[i, 2];
            Place(d.rectTransform, C, new Vector2(PAUSE_DECO[i, 0], PAUSE_DECO[i, 1]), new Vector2(s, s));
            d.rectTransform.localRotation = Quaternion.Euler(0f, 0f, PAUSE_DECO[i, 3]);
        }

        // Halo emas lembut di belakang kartu — trik yang sama dipakai di Home.
        // Ini yang membuat kartu terasa DUDUK di latarnya, bukan ditempel di atasnya.
        var cardHalo = MakeGlow(root, new Color(1f, 0.84f, 0.31f, 0.13f));
        Place(cardHalo.rectTransform, C, new Vector2(0, 40), new Vector2(1020, 1220));

        var card = MakeCard(root, new Vector2(0, 40), new Vector2(760, 980), CARD_DEEP);
        MakeDecoRow(card, new Vector2(0, 370));
        var title = MakeText("Title", card, 100, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        title.text = "PAUSED";
        Place(title.rectTransform, C, new Vector2(0, 240), new Vector2(700, 160));

        _btnResume = MakeButton(card, "RESUME", new Vector2(0, 60), new Vector2(600, 160), BTN_GREEN, 76);
        _btnSettingsPause = MakeButton(card, "SETTINGS", new Vector2(0, -140), new Vector2(600, 140), BTN_BLUE, 56);
        _btnHome = MakeButton(card, "MAIN MENU", new Vector2(0, -320), new Vector2(600, 140), BTN_SLATE, 56);
    }

    // ---- SETTINGS ----
    void BuildSettings()
    {
        _settingsPanel = MakePanel("SettingsPanel", new Color(0f, 0f, 0f, 0f));
        var root = _settingsPanel.transform;

        var card = MakeCard(root, new Vector2(0, 40), new Vector2(920, 1560), CARD_DEEP);
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
