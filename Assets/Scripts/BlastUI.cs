// Antarmuka (UI) untuk Kubika Blast.
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
#if USE_NEW_INPUT
using UnityEngine.InputSystem;
#endif
using KubikaBlast;

/// <summary>
/// Membangun UI game SEPENUHNYA lewat kode: skor/combo/baris/LEVEL + tray 3D.
/// Teks memakai outline + shadow + ukuran besar, dan potongan tray digambar
/// bergaya 3D (bevel/gloss/shadow).
///
/// CATATAN: layar GAME OVER TIDAK lagi dibangun di sini.
///   Dulu ada DUA layar game over yang bertumpuk: panel milik file ini di
///   sortingOrder 100, dan kartu KubikaMenu di sortingOrder 300. Yang lama
///   tertutup rapat oleh yang baru, tapi tetap berjalan tiap frame, tetap
///   menulis ulang teks "Skor Akhir", dan tetap memiliki tombol "MAIN LAGI"
///   yang kotak sentuhnya duduk PERSIS di bawah tombol yang terlihat.
///   IsOverInteractiveUI() bahkan masih menanyai tombol mati itu saat menentukan
///   apakah sebuah tap boleh menaruh potongan. Semuanya sudah dibuang; kini
///   KubikaMenu adalah satu-satunya pemilik layar game over.
/// </summary>
public class BlastUI : MonoBehaviour
{
    public static BlastUI Instance { get; private set; }

    [Header("Referensi (auto kalau kosong)")]
    public BlastGame game;
    public BlastInput input;

    [Header("Warna UI")]
    public Color slotColor = new Color(1f, 1f, 1f, 0.10f);
    public Color slotSelected = new Color(1f, 0.85f, 0.25f, 0.35f);
    public Color slotUsed = new Color(1f, 1f, 1f, 0.03f);

    Canvas _canvas;
    Text _scoreText, _comboText, _linesText, _levelText;
    readonly RectTransform[] _slot = new RectTransform[3];
    readonly Image[] _slotBg = new Image[3];
    readonly RectTransform[] _cellHolder = new RectTransform[3];
    readonly List<GameObject>[] _cellImgs = new List<GameObject>[3];
    readonly object[] _lastPiece = new object[3];
    readonly bool[] _lastUsed = new bool[3];

    Font _font;
    Sprite _roundSprite;

    void Awake()
    {
        Instance = this;
        if (game == null) game = FindFirstObjectByType<BlastGame>();
        if (input == null) input = FindFirstObjectByType<BlastInput>();
        for (int i = 0; i < 3; i++) _cellImgs[i] = new List<GameObject>();
    }

    void OnDestroy() { if (Instance == this) Instance = null; }

    void Start() { BuildUI(); }

    // ==================================================================
    // ============ BANGUN UI ===========================================
    // ==================================================================
    void BuildUI()
    {
        var canvasGO = new GameObject("BlastCanvas", typeof(Canvas), typeof(CanvasScaler));
        canvasGO.transform.SetParent(transform, false);
        _canvas = canvasGO.GetComponent<Canvas>();
        _canvas.renderMode = RenderMode.ScreenSpaceOverlay;
        _canvas.sortingOrder = 100;
        var scaler = canvasGO.GetComponent<CanvasScaler>();
        scaler.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        scaler.referenceResolution = new Vector2(1080, 2400);
        scaler.screenMatchMode = CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
        scaler.matchWidthOrHeight = 0.5f;

        Transform root = canvasGO.transform;

        // ---- teks status (atas) ----
        // KubikaHud mengkloning & menyembunyikan teks-teks ini lewat refleksi
        // (nama field _scoreText/_levelText/_comboText/_linesText). Jangan ganti
        // nama field-nya tanpa memperbarui KubikaHud.FindText().
        _scoreText = MakeText("Score", root, 88, TextAnchor.UpperCenter, FontStyle.Bold);
        Place(_scoreText.rectTransform, new Vector2(0.5f, 1f), new Vector2(0, -40), new Vector2(1000, 120));

        _comboText = MakeText("Combo", root, 60, TextAnchor.UpperCenter, FontStyle.Bold);
        _comboText.color = new Color(1f, 0.85f, 0.25f);
        Place(_comboText.rectTransform, new Vector2(0.5f, 1f), new Vector2(0, -168), new Vector2(1000, 80));

        _linesText = MakeText("Lines", root, 40, TextAnchor.UpperCenter);
        _linesText.color = new Color(1f, 1f, 1f, 0.75f);
        Place(_linesText.rectTransform, new Vector2(0.5f, 1f), new Vector2(0, -244), new Vector2(1000, 56));

        _levelText = MakeText("Level", root, 60, TextAnchor.UpperLeft, FontStyle.Bold);
        _levelText.color = new Color(0.45f, 0.95f, 0.85f);
        Place(_levelText.rectTransform, new Vector2(0f, 1f), new Vector2(40, -44), new Vector2(520, 90));

        // ---- tray (bawah) ----
        float slotW = 300f, slotH = 340f, gap = 30f;
        for (int i = 0; i < 3; i++)
        {
            float x = (i - 1) * (slotW + gap);
            var bg = MakeImage("Slot" + i, root, slotColor);
            _slotBg[i] = bg;
            _slot[i] = bg.rectTransform;
            Place(_slot[i], new Vector2(0.5f, 0f), new Vector2(x, 40), new Vector2(slotW, slotH));

            var lbl = MakeText("Lbl" + i, _slot[i], 40, TextAnchor.UpperCenter, FontStyle.Bold);
            lbl.text = (i + 1).ToString();
            lbl.color = new Color(1f, 1f, 1f, 0.6f);
            Place(lbl.rectTransform, new Vector2(0.5f, 1f), new Vector2(0, -6), new Vector2(slotW, 50));

            var holderGO = new GameObject("Cells" + i, typeof(RectTransform));
            holderGO.transform.SetParent(_slot[i], false);
            var hrt = holderGO.GetComponent<RectTransform>();
            Place(hrt, new Vector2(0.5f, 0f), new Vector2(0, 20), new Vector2(slotW - 40, slotH - 80));
            _cellHolder[i] = hrt;
        }
    }

    // ==================================================================
    // ============ UPDATE / REFRESH ====================================
    // ==================================================================
    void Update()
    {
        if (game == null) { game = FindFirstObjectByType<BlastGame>(); if (game == null) return; }
        if (input == null) input = FindFirstObjectByType<BlastInput>();
        var core = game.Core;
        if (core == null) return;

        _scoreText.text = "Score  " + core.Score;
        _comboText.text = core.Combo > 1 ? ("COMBO x" + core.Combo) : "";
        _linesText.text = "Lines cleared: " + core.LinesCleared;
        _levelText.text = "LEVEL " + core.Level;

        RefreshTray(core);
        HandleTaps(core);
    }

    void RefreshTray(BlastCore core)
    {
        int sel = input != null ? input.CurrentIndex : -1;
        var pal = game.palette;
        for (int i = 0; i < 3; i++)
        {
            var pc = core.Tray[i];
            bool used = pc == null || pc.Used;

            _slotBg[i].color = used ? slotUsed : (i == sel ? slotSelected : slotColor);

            if (!ReferenceEquals(_lastPiece[i], pc) || _lastUsed[i] != used)
            {
                _lastPiece[i] = pc;
                _lastUsed[i] = used;
                RedrawSlotCells(i, pc, used, pal);
            }
        }
    }

    void RedrawSlotCells(int i, BlastCore.Piece pc, bool used, Color[] pal)
    {
        var list = _cellImgs[i];
        foreach (var g in list) if (g != null) Destroy(g);
        list.Clear();
        if (pc == null || used || pc.Cells == null || pc.Cells.Length == 0) return;

        int minX = int.MaxValue, maxX = int.MinValue, minY = int.MaxValue, maxY = int.MinValue;
        foreach (var (dx, dy) in pc.Cells)
        {
            if (dx < minX) minX = dx; if (dx > maxX) maxX = dx;
            if (dy < minY) minY = dy; if (dy > maxY) maxY = dy;
        }
        int w = maxX - minX + 1, h = maxY - minY + 1;
        Vector2 area = _cellHolder[i].sizeDelta;
        float cell = Mathf.Min(area.x / Mathf.Max(1, w), area.y / Mathf.Max(1, h)) * 0.9f;
        float cx = (minX + maxX) * 0.5f, cy = (minY + maxY) * 0.5f;
        Color col = (pal != null && pc.Color >= 0 && pc.Color < pal.Length) ? pal[pc.Color] : Color.white;
        col.a = 1f;

        foreach (var (dx, dy) in pc.Cells)
        {
            var g = MakeCell3D(_cellHolder[i], col,
                               new Vector2((dx - cx) * cell, (dy - cy) * cell),
                               cell * 0.96f);
            list.Add(g);
        }
    }

    // Potongan tray bergaya 3D: bayangan + badan (ber-outline) + gradasi bawah + kilap atas.
    GameObject MakeCell3D(Transform parent, Color color, Vector2 pos, float size)
    {
        var contGO = new GameObject("cell", typeof(RectTransform));
        contGO.transform.SetParent(parent, false);
        var crt = contGO.GetComponent<RectTransform>();
        Place(crt, new Vector2(0.5f, 0.5f), pos, new Vector2(size, size));

        float inset = size * 0.94f;

        var sh = MakeSpriteImage("sh", crt, new Color(0f, 0f, 0f, 0.35f));
        Place(sh.rectTransform, new Vector2(0.5f, 0.5f), new Vector2(0f, -size * 0.06f), new Vector2(inset, inset));

        var body = MakeSpriteImage("body", crt, color);
        Place(body.rectTransform, new Vector2(0.5f, 0.5f), Vector2.zero, new Vector2(inset, inset));
        var outline = body.gameObject.AddComponent<Outline>();
        outline.effectColor = new Color(0f, 0f, 0f, 0.45f);
        outline.effectDistance = new Vector2(3f, -3f);

        var shade = MakeSpriteImage("shade", crt, new Color(0f, 0f, 0f, 0.18f));
        Place(shade.rectTransform, new Vector2(0.5f, 0f), new Vector2(0f, size * 0.03f), new Vector2(inset * 0.98f, inset * 0.5f));

        var gloss = MakeSpriteImage("gloss", crt, new Color(1f, 1f, 1f, 0.32f));
        Place(gloss.rectTransform, new Vector2(0.5f, 1f), new Vector2(0f, -size * 0.07f), new Vector2(inset * 0.82f, inset * 0.4f));

        return contGO;
    }

    // ==================================================================
    // ============ INTERAKSI (tap) =====================================
    // ==================================================================
    void HandleTaps(BlastCore core)
    {
        // Saat game over, KubikaMenu yang pegang kendali penuh.
        if (core.GameOver) return;
        if (!PointerPressedThisFrame()) return;
        Vector2 p = PointerPos();

        for (int i = 0; i < 3; i++)
        {
            var pc = core.Tray[i];
            if (pc != null && !pc.Used && Contains(_slot[i], p))
            {
                if (input != null) input.SelectTray(i);
                return;
            }
        }
    }

    bool Contains(RectTransform rt, Vector2 screenPos)
        => rt != null && RectTransformUtility.RectangleContainsScreenPoint(rt, screenPos, null);

    /// <summary>Bangun ulang papan. Disediakan untuk pemanggil luar; layar game
    /// over sendiri kini ditangani KubikaMenu.</summary>
    public void DoRestart()
    {
        if (game == null) return;
        game.Rebuild();
        if (input != null) input.ResetSelection();
        for (int i = 0; i < 3; i++) { _lastPiece[i] = null; _lastUsed[i] = true; }
    }

    public bool IsOverInteractiveUI(Vector2 screenPos)
    {
        if (game == null) return false;
        var core = game.Core;
        if (core == null) return false;
        if (core.GameOver) return false;   // dulu di sini menanyai tombol restart yang sudah mati
        for (int i = 0; i < 3; i++)
        {
            var pc = core.Tray[i];
            if (pc != null && !pc.Used && Contains(_slot[i], screenPos)) return true;
        }
        return false;
    }

    public static bool PointerBlocksPlacement(Vector2 screenPos)
        => Instance != null && Instance.IsOverInteractiveUI(screenPos);

    public int TraySlotAt(Vector2 screenPos)
    {
        if (game == null) return -1;
        var core = game.Core;
        if (core == null || core.GameOver) return -1;
        for (int i = 0; i < 3; i++)
        {
            var pc = core.Tray[i];
            if (pc != null && !pc.Used && Contains(_slot[i], screenPos)) return i;
        }
        return -1;
    }

    public static int TraySlotAtPointer(Vector2 screenPos)
        => Instance != null ? Instance.TraySlotAt(screenPos) : -1;

    // ==================================================================
    // ============ HELPER UI ===========================================
    // ==================================================================
    Text MakeText(string name, Transform parent, int size, TextAnchor anchor, FontStyle style = FontStyle.Normal)
    {
        var goT = new GameObject(name, typeof(RectTransform));
        goT.transform.SetParent(parent, false);
        var t = goT.AddComponent<Text>();
        t.font = UIFont();
        t.fontSize = size;
        t.alignment = anchor;
        t.fontStyle = style;
        t.color = Color.white;
        t.raycastTarget = false;
        t.horizontalOverflow = HorizontalWrapMode.Overflow;
        t.verticalOverflow = VerticalWrapMode.Overflow;

        var shadow = goT.AddComponent<Shadow>();
        shadow.effectColor = new Color(0f, 0f, 0f, 0.55f);
        shadow.effectDistance = new Vector2(3f, -3f);
        var ol = goT.AddComponent<Outline>();
        ol.effectColor = new Color(0f, 0f, 0f, 0.6f);
        ol.effectDistance = new Vector2(2f, 2f);
        return t;
    }

    Image MakeImage(string name, Transform parent, Color col)
    {
        var goI = new GameObject(name, typeof(RectTransform));
        goI.transform.SetParent(parent, false);
        var img = goI.AddComponent<Image>();
        img.color = col;
        img.raycastTarget = false;
        return img;
    }

    Image MakeSpriteImage(string name, Transform parent, Color col)
    {
        var img = MakeImage(name, parent, col);
        img.sprite = RoundSprite();
        img.type = Image.Type.Sliced;
        return img;
    }

    Sprite RoundSprite()
    {
        if (_roundSprite != null) return _roundSprite;
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
        _roundSprite = Sprite.Create(tex, new Rect(0, 0, size, size), new Vector2(0.5f, 0.5f), 100f, 0,
                                     SpriteMeshType.FullRect, new Vector4(b, b, b, b));
        return _roundSprite;
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
        rt.anchorMin = anchor;
        rt.anchorMax = anchor;
        rt.pivot = anchor;
        rt.anchoredPosition = pos;
        rt.sizeDelta = size;
    }

    Font UIFont()
    {
        if (_font != null) return _font;
        _font = Resources.GetBuiltinResource<Font>("LegacyRuntime.ttf");
        if (_font == null) _font = Resources.GetBuiltinResource<Font>("Arial.ttf");
        if (_font == null) _font = Font.CreateDynamicFontFromOSFont("Arial", 16);
        return _font;
    }

    // ==================================================================
    // ============ ABSTRAKSI INPUT (lama vs baru) ======================
    // ==================================================================
    Vector2 PointerPos()
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

    bool PointerPressedThisFrame()
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
}
