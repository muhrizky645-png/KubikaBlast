// TAHAP 4 — Antarmuka (UI) untuk Kubika Blast.
// Mendukung dua backend input (lama & baru) sama seperti BlastInput.
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
/// Membangun UI game SEPENUHNYA lewat kode (tanpa perlu menyusun Canvas manual):
///  - Panel skor, combo, dan jumlah baris hancur (atas layar).
///  - Tampilan TRAY 3 potongan (bentuknya digambar dari Piece.Cells). Tap slot
///    untuk memilih potongan aktif.
///  - Layar GAME OVER + tombol \"MAIN LAGI\" (memanggil BlastGame.Rebuild()).
///
/// Cara pakai: buat GameObject kosong (mis. \"UI\") lalu tambahkan komponen ini.
/// Referensi BlastGame & BlastInput dicari otomatis. Interaksi (tap) ditangani
/// manual pakai abstraksi input, jadi TIDAK butuh EventSystem.
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
    Text _scoreText, _comboText, _linesText;
    readonly RectTransform[] _slot = new RectTransform[3];
    readonly Image[] _slotBg = new Image[3];
    readonly RectTransform[] _cellHolder = new RectTransform[3];
    readonly List<GameObject>[] _cellImgs = new List<GameObject>[3];
    readonly object[] _lastPiece = new object[3];
    readonly bool[] _lastUsed = new bool[3];

    GameObject _gameOverPanel;
    Text _gameOverFinal;
    RectTransform _restartRect;

    Font _font;

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
        _scoreText = MakeText("Score", root, 64, TextAnchor.UpperCenter, FontStyle.Bold);
        Place(_scoreText.rectTransform, new Vector2(0.5f, 1f), new Vector2(0, -40), new Vector2(1000, 90));

        _comboText = MakeText("Combo", root, 46, TextAnchor.UpperCenter, FontStyle.Bold);
        _comboText.color = new Color(1f, 0.85f, 0.25f);
        Place(_comboText.rectTransform, new Vector2(0.5f, 1f), new Vector2(0, -135), new Vector2(1000, 70));

        _linesText = MakeText("Lines", root, 34, TextAnchor.UpperCenter);
        _linesText.color = new Color(1f, 1f, 1f, 0.7f);
        Place(_linesText.rectTransform, new Vector2(0.5f, 1f), new Vector2(0, -205), new Vector2(1000, 50));

        // ---- tray (bawah) ----
        float slotW = 300f, slotH = 340f, gap = 30f;
        for (int i = 0; i < 3; i++)
        {
            float x = (i - 1) * (slotW + gap);
            var bg = MakeImage("Slot" + i, root, slotColor);
            _slotBg[i] = bg;
            _slot[i] = bg.rectTransform;
            Place(_slot[i], new Vector2(0.5f, 0f), new Vector2(x, 40), new Vector2(slotW, slotH));

            var lbl = MakeText("Lbl" + i, _slot[i], 34, TextAnchor.UpperCenter, FontStyle.Bold);
            lbl.text = (i + 1).ToString();
            lbl.color = new Color(1f, 1f, 1f, 0.6f);
            Place(lbl.rectTransform, new Vector2(0.5f, 1f), new Vector2(0, -6), new Vector2(slotW, 44));

            var holderGO = new GameObject("Cells" + i, typeof(RectTransform));
            holderGO.transform.SetParent(_slot[i], false);
            var hrt = holderGO.GetComponent<RectTransform>();
            Place(hrt, new Vector2(0.5f, 0f), new Vector2(0, 20), new Vector2(slotW - 40, slotH - 80));
            _cellHolder[i] = hrt;
        }

        BuildGameOver(root);
    }

    void BuildGameOver(Transform root)
    {
        var panelImg = MakeImage("GameOver", root, new Color(0f, 0f, 0f, 0.75f));
        _gameOverPanel = panelImg.gameObject;
        var prt = panelImg.rectTransform;
        prt.anchorMin = Vector2.zero; prt.anchorMax = Vector2.one; prt.pivot = new Vector2(0.5f, 0.5f);
        prt.offsetMin = Vector2.zero; prt.offsetMax = Vector2.zero;

        var title = MakeText("GO_Title", _gameOverPanel.transform, 92, TextAnchor.MiddleCenter, FontStyle.Bold);
        title.text = "GAME OVER";
        title.color = new Color(1f, 0.4f, 0.4f);
        Place(title.rectTransform, new Vector2(0.5f, 0.5f), new Vector2(0, 240), new Vector2(1000, 150));

        _gameOverFinal = MakeText("GO_Final", _gameOverPanel.transform, 52, TextAnchor.MiddleCenter);
        Place(_gameOverFinal.rectTransform, new Vector2(0.5f, 0.5f), new Vector2(0, 60), new Vector2(1000, 200));

        var btn = MakeImage("Restart", _gameOverPanel.transform, new Color(0.30f, 0.65f, 0.95f, 1f));
        _restartRect = btn.rectTransform;
        Place(_restartRect, new Vector2(0.5f, 0.5f), new Vector2(0, -160), new Vector2(480, 150));

        var btnText = MakeText("RestartTxt", btn.transform, 54, TextAnchor.MiddleCenter, FontStyle.Bold);
        btnText.text = "MAIN LAGI";
        Place(btnText.rectTransform, new Vector2(0.5f, 0.5f), new Vector2(0, 0), new Vector2(480, 150));

        _gameOverPanel.SetActive(false);
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

        _scoreText.text = "Skor  " + core.Score;
        _comboText.text = core.Combo > 1 ? ("COMBO x" + core.Combo) : "";
        _linesText.text = "Baris hancur: " + core.LinesCleared;

        RefreshTray(core);

        bool go = core.GameOver;
        if (_gameOverPanel.activeSelf != go) _gameOverPanel.SetActive(go);
        if (go) _gameOverFinal.text = "Skor Akhir\n" + core.Score;

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
            var img = MakeImage("c", _cellHolder[i], col);
            Place(img.rectTransform, new Vector2(0.5f, 0.5f),
                  new Vector2((dx - cx) * cell, (dy - cy) * cell),
                  new Vector2(cell * 0.92f, cell * 0.92f));
            list.Add(img.gameObject);
        }
    }

    // ==================================================================
    // ============ INTERAKSI (tap) =====================================
    // ==================================================================
    void HandleTaps(BlastCore core)
    {
        if (!PointerPressedThisFrame()) return;
        Vector2 p = PointerPos();

        if (core.GameOver)
        {
            if (Contains(_restartRect, p)) DoRestart();
            return;
        }

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

    void DoRestart()
    {
        if (game == null) return;
        game.Rebuild();
        if (input != null) input.ResetSelection();
        for (int i = 0; i < 3; i++) { _lastPiece[i] = null; _lastUsed[i] = true; } // paksa gambar ulang tray
    }

    // Dipakai BlastInput supaya balok tidak jatuh saat menekan area UI.
    public bool IsOverInteractiveUI(Vector2 screenPos)
    {
        if (game == null) return false;
        var core = game.Core;
        if (core == null) return false;
        if (core.GameOver) return Contains(_restartRect, screenPos);
        for (int i = 0; i < 3; i++)
        {
            var pc = core.Tray[i];
            if (pc != null && !pc.Used && Contains(_slot[i], screenPos)) return true;
        }
        return false;
    }

    public static bool PointerBlocksPlacement(Vector2 screenPos)
        => Instance != null && Instance.IsOverInteractiveUI(screenPos);

    // Slot tray (0-2) berisi potongan BELUM terpakai pada posisi layar ini,
    // atau -1 kalau tidak ada. Dipakai BlastInput untuk model "seret DARI tray":
    // menaruh hanya sah bila gestur seret DIMULAI di salah satu slot ini.
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
        return t;
    }

    Image MakeImage(string name, Transform parent, Color col)
    {
        var goI = new GameObject(name, typeof(RectTransform));
        goI.transform.SetParent(parent, false);
        var img = goI.AddComponent<Image>();
        img.color = col;
        img.raycastTarget = false; // hit-test manual, tak butuh raycaster
        return img;
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
