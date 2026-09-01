// Dukung DUA backend input Unity (Input Manager lama & Input System baru).
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
#if USE_NEW_INPUT
using UnityEngine.InputSystem;
#endif
using KubikaBlast;

/// <summary>
/// SISTEM ITEM / POWER-UP + PERMATA untuk Kubika Blast (ADD-ON).
///
/// Item: HAMMER (baris+kolom), BOMB (4x4), UNDO (batalkan langkah).
/// Didapat dari bubble + iklan (simulasi), atau dibeli di TOKO pakai permata.
///
/// EKONOMI PERMATA: kelas ini MENDENGARKAN BlastGame.OnCleared dan menyimpan
/// info.Gems. Clear dari alat datang bertanda FromTool dan TIDAK dibayar,
/// supaya membeli palu tak pernah bisa menghasilkan permata melebihi harganya.
///
/// Execution order default (0) -> jalan SEBELUM BlastInput (1000), jadi bisa
/// mengambil snapshot papan sebelum langkah pemain untuk fitur UNDO.
/// </summary>
public class KubikaItems : MonoBehaviour
{
    public static KubikaItems Instance { get; private set; }
    public static bool TargetingActive => Instance != null && Instance._mode != Mode.None;
    public static float LastBuffUseTime = -999f;

    enum Item { Hammer = 0, Bomb = 1, Undo = 2 }
    enum Mode { None, Hammer, Bomb }
    Mode _mode = Mode.None;

    const string GEM_KEY = "kubika_gems";
    static readonly string[] ITEM_KEY = { "kubika_item_hammer", "kubika_item_bomb", "kubika_item_undo" };

    // Diturunkan dari { 200, 600, 400 }. Dengan rumus permata BlastCore (3 untuk
    // satu baris polos), harga lama membuat sebuah bom setara ~200 baris.
    static readonly int[] PRICE = { 120, 260, 180 };
    static readonly string[] NAME = { "HAMMER", "BOMB", "UNDO" };
    static readonly Color[] ICOL =
    {
        new Color(1.00f, 0.72f, 0.30f),
        new Color(1.00f, 0.36f, 0.48f),
        new Color(0.31f, 0.76f, 0.97f),
    };

    const int MAX_GEM_SPRITES = 20;
    const float BUBBLE_STOP_Y = -360f;
    static readonly Vector2 C = new Vector2(0.5f, 0.5f);

    BlastGame _game, _hookedGame;
    BlastInput _input;
    BlastCore _core;
    Camera _cam;
    bool _built;

    Canvas _play, _modal, _backCanvas, _fxCanvas;
    Image _flash;
    Font _font;
    Sprite _round, _bubbleSprite;
    Sprite _spHammer, _spBomb, _spUndo, _spGem, _spCrown;

    GameObject _itemBar;
    RectTransform[] _itemBtn = new RectTransform[3];
    Text[] _itemCount = new Text[3];
    Text _gemLabel;
    RectTransform _gemPill;

    // Angka permata yang DITAMPILKAN, sengaja tertinggal dari nilai asli supaya
    // bisa merangkak naik saat tiap permata mendarat.
    int _gemShown = -1;
    int _gemsInFlight;
    Vector2 _burstOrigin = new Vector2(0f, 180f);

    GameObject _hint;
    Text _hintText;
    RectTransform _btnCancel;

    Text _toast;
    Coroutine _toastCo;

    GameObject _bubble;
    RectTransform _bubbleRT;
    Text _bubbleLabel;
    Image _bubbleIcon;
    Item _bubbleItem;
    float _nextBubble;
    bool _bubbleLanded;
    float _bubbleHoverUntil;

    GameObject _confirm;
    Text _confirmText;
    RectTransform _btnYes, _btnNo;
    Item _pending;

    GameObject _adPanel;
    Text _adText;
    float _adTimer;
    int _adPhase;
    Item _adItem;

    GameObject _shop;
    Text _shopGems, _shopStatus;
    Text[] _shopOwned = new Text[3];
    RectTransform[] _shopBuy = new RectTransform[3];
    RectTransform _shopClose;
    RectTransform _tokoBtn;

    int[,] _snapGrid, _undoGrid;
    int _snapScore, _snapCombo, _snapLines, _undoScore, _undoCombo, _undoLines;
    bool _snapGO, _undoGO;
    BlastCore.Piece[] _snapTray, _undoTray;
    bool _hasSnap, _hasUndo, _selfModified;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void Boot()
    {
        if (Instance != null) return;
        var go = new GameObject("KubikaItems (auto)");
        go.AddComponent<KubikaItems>();
    }

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void OnDestroy()
    {
        UnhookGame();
        if (Instance == this) Instance = null;
    }

    void Update()
    {
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_input == null) _input = FindFirstObjectByType<BlastInput>();
        if (_cam == null) _cam = Camera.main;
        if (_game == null) return;
        _core = _game.Core;
        if (_core == null) return;

        if (!_built) BuildUI();
        HookGame();

        HandleUndoSnapshot();

        bool playing = Time.timeScale > 0f && !_core.GameOver;
        bool anyModal = _confirm.activeSelf || _adPanel.activeSelf || _shop.activeSelf;
        _itemBar.SetActive(playing && _mode == Mode.None && !anyModal);
        _hint.SetActive(playing && _mode != Mode.None && !anyModal);
        UpdateItemCounts();

        string menu = KubikaMenu.CurrentScreenName;
        bool showToko = !anyModal && (menu == "Home" || menu == "Paused");
        _tokoBtn.gameObject.SetActive(showToko);

        HandleBubble(playing && _mode == Mode.None && !anyModal);

        if (_adPanel.activeSelf) HandleAdTimer();

        HandleTaps();

        _selfModified = false;
    }

    // ============================================================
    //  HOOK KE BLASTGAME
    // ============================================================
    void HookGame()
    {
        if (_game == null || ReferenceEquals(_game, _hookedGame)) return;
        UnhookGame();
        _hookedGame = _game;
        _game.OnCleared += HandleCleared;
        _game.OnRebuilt += HandleRebuilt;
    }

    void UnhookGame()
    {
        if (_hookedGame == null) return;
        _hookedGame.OnCleared -= HandleCleared;
        _hookedGame.OnRebuilt -= HandleRebuilt;
        _hookedGame = null;
    }

    void HandleCleared(BlastCore.ClearInfo info)
    {
        // Clear dari alat tidak membayar: kalau membayar, membeli palu bisa
        // menghasilkan permata lebih banyak daripada harganya.
        if (info.FromTool) return;

        int gems = Mathf.Max(1, info.Gems);
        AddGems(gems);
        _burstOrigin = BurstOrigin(info);
        StartCoroutine(GemBurst(gems, info.Combo));
    }

    void HandleRebuilt()
    {
        _hasSnap = false;
        _hasUndo = false;
        _gemShown = -1;
        _gemsInFlight = 0;
        _mode = Mode.None;
    }

    /// <summary>Titik tengah sel yang benar-benar hancur, dalam koordinat canvas.</summary>
    Vector2 BurstOrigin(BlastCore.ClearInfo info)
    {
        if (_cam == null) _cam = Camera.main;
        if (_cam == null || _game == null || _play == null ||
            info.Cells == null || info.Cells.Count == 0)
            return new Vector2(0f, 180f);

        Vector3 sum = Vector3.zero;
        foreach (var cell in info.Cells) sum += _game.CellToWorld(cell.c, cell.r);
        Vector3 world = _game.transform.TransformPoint(sum / info.Cells.Count);
        Vector2 sp = _cam.WorldToScreenPoint(world);

        RectTransformUtility.ScreenPointToLocalPointInRectangle(
            (RectTransform)_play.transform, sp, null, out Vector2 local);
        return local;
    }

    /// <summary>
    /// Ke mana permata terbang. Dulu konstanta piksel (-456, 962) yang hanya
    /// benar di satu rasio layar; kini dibaca dari rect pil permata sendiri.
    /// </summary>
    Vector2 GemTarget()
    {
        if (_gemPill == null || _play == null) return new Vector2(-354f, 958f);
        Vector3 world = _gemPill.TransformPoint(_gemPill.rect.center);
        Vector2 sp = RectTransformUtility.WorldToScreenPoint(null, world);
        RectTransformUtility.ScreenPointToLocalPointInRectangle(
            (RectTransform)_play.transform, sp, null, out Vector2 local);
        return local;
    }

    // ============================================================
    //  UNDO SNAPSHOT
    // ============================================================
    void HandleUndoSnapshot()
    {
        if (!_hasSnap || _core.LinesCleared < _snapLines || (_snapGrid != null &&
            (_snapGrid.GetLength(0) != _core.Columns || _snapGrid.GetLength(1) != _core.Height)))
        {
            TakeSnapshot();
            _hasUndo = false;
            return;
        }

        if (!_selfModified && (_core.Score != _snapScore || !GridEquals(_core.Grid, _snapGrid)))
        {
            _undoGrid = CloneGrid(_snapGrid);
            _undoScore = _snapScore; _undoCombo = _snapCombo; _undoLines = _snapLines; _undoGO = _snapGO;
            _undoTray = DeepCopyTray(_snapTray);
            _hasUndo = true;
        }

        TakeSnapshot();
    }

    void TakeSnapshot()
    {
        _snapGrid = CloneGrid(_core.Grid);
        _snapScore = _core.Score; _snapCombo = _core.Combo; _snapLines = _core.LinesCleared; _snapGO = _core.GameOver;
        _snapTray = DeepCopyTray(_core.Tray);
        _hasSnap = true;
    }

    void DoUndo()
    {
        if (!_hasUndo || _undoGrid == null) return;
        for (int c = 0; c < _core.Columns; c++)
            for (int r = 0; r < _core.Height; r++)
                _core.Grid[c, r] = _undoGrid[c, r];
        _core.Score = _undoScore; _core.Combo = _undoCombo; _core.LinesCleared = _undoLines; _core.GameOver = _undoGO;

        var t = DeepCopyTray(_undoTray);
        for (int i = 0; i < _core.Tray.Length && i < t.Length; i++) _core.Tray[i] = t[i];

        // Papan berubah -> status game over harus dihitung ulang, jangan diwarisi.
        _core.RecheckGameOver();

        _game.RenderGrid();
        if (_input != null) _input.ResetSelection();

        AddItem(Item.Undo, -1);
        _hasUndo = false;
        _selfModified = true;
        TakeSnapshot();
        FlashHint("Move undone");
    }

    int[,] CloneGrid(int[,] g)
    {
        if (g == null) return null;
        int w = g.GetLength(0), h = g.GetLength(1);
        var n = new int[w, h];
        System.Array.Copy(g, n, g.Length);
        return n;
    }

    bool GridEquals(int[,] a, int[,] b)
    {
        if (a == null || b == null) return false;
        if (a.GetLength(0) != b.GetLength(0) || a.GetLength(1) != b.GetLength(1)) return false;
        int w = a.GetLength(0), h = a.GetLength(1);
        for (int c = 0; c < w; c++)
            for (int r = 0; r < h; r++)
                if (a[c, r] != b[c, r]) return false;
        return true;
    }

    BlastCore.Piece[] DeepCopyTray(BlastCore.Piece[] src)
    {
        if (src == null) return null;
        var dst = new BlastCore.Piece[src.Length];
        for (int i = 0; i < src.Length; i++)
        {
            var p = src[i];
            if (p == null) { dst[i] = null; continue; }
            var cells = new (int x, int y)[p.Cells != null ? p.Cells.Length : 0];
            if (p.Cells != null) System.Array.Copy(p.Cells, cells, p.Cells.Length);
            dst[i] = new BlastCore.Piece { Cells = cells, Color = p.Color, Used = p.Used };
        }
        return dst;
    }

    // ============================================================
    //  BUBBLE ITEM JATUH
    // ============================================================
    void HandleBubble(bool canRun)
    {
        if (!canRun)
        {
            if (_bubble != null && _bubble.activeSelf) _bubble.SetActive(false);
            return;
        }

        if ((_bubble == null || !_bubble.activeSelf) && Time.unscaledTime >= _nextBubble)
            SpawnBubble();

        if (_bubble == null || !_bubble.activeSelf) return;

        var p = _bubbleRT.anchoredPosition;
        if (!_bubbleLanded)
        {
            p.y -= 320f * Time.deltaTime;
            if (p.y <= BUBBLE_STOP_Y)
            {
                p.y = BUBBLE_STOP_Y;
                _bubbleLanded = true;
                _bubbleHoverUntil = Time.unscaledTime + 6.5f;
            }
            _bubbleRT.anchoredPosition = p;
        }
        else
        {
            p.y = BUBBLE_STOP_Y + Mathf.Sin(Time.unscaledTime * 2.2f) * 16f;
            _bubbleRT.anchoredPosition = p;
            if (Time.unscaledTime >= _bubbleHoverUntil) { _bubble.SetActive(false); ScheduleNextBubble(); }
        }
        _bubbleRT.localRotation = Quaternion.Euler(0f, 0f, Mathf.Sin(Time.unscaledTime * 1.6f) * 8f);
    }

    void ScheduleNextBubble() { _nextBubble = Time.unscaledTime + Random.Range(9f, 17f); }

    void SpawnBubble()
    {
        _bubbleItem = (Item)Random.Range(0, 3);
        float lane = (Random.value < 0.5f) ? -430f : 430f;
        _bubbleRT.anchoredPosition = new Vector2(lane, 1300f);
        _bubbleRT.localRotation = Quaternion.identity;
        _bubbleLanded = false;
        var img = _bubble.GetComponent<Image>();
        var bSp = (_bubbleItem == Item.Hammer) ? _spHammer : (_bubbleItem == Item.Bomb) ? _spBomb : _spUndo;
        if (bSp != null)
        {
            _bubbleIcon.sprite = bSp;
            _bubbleIcon.gameObject.SetActive(true);
            _bubbleLabel.text = "";
            img.color = new Color(0.70f, 0.88f, 1f, 0.55f);
        }
        else
        {
            _bubbleIcon.gameObject.SetActive(false);
            _bubbleLabel.text = NAME[(int)_bubbleItem];
            var ic = ICOL[(int)_bubbleItem]; img.color = new Color(ic.r, ic.g, ic.b, 0.7f);
        }
        _bubble.SetActive(true);
    }

    // ============================================================
    //  IKLAN (SIMULASI)
    // ============================================================
    void OpenConfirm(Item it)
    {
        _pending = it;
        _confirmText.text = "Watch an ad to get\n\"" + NAME[(int)it] + "\"?";
        _confirm.SetActive(true);
    }

    void StartAd()
    {
        _confirm.SetActive(false);
        _adItem = _pending;
        _adPhase = 0;
        _adTimer = 2.5f;
        _adText.text = "Showing ad...\n(simulated)";
        _adPanel.SetActive(true);
    }

    void HandleAdTimer()
    {
        _adTimer -= Time.unscaledDeltaTime;
        if (_adTimer > 0f)
        {
            if (_adPhase == 0)
                _adText.text = "Showing ad...\n(simulated)  " + Mathf.CeilToInt(_adTimer);
            return;
        }
        if (_adPhase == 0)
        {
            AddItem(_adItem, +1);
            _adPhase = 1;
            _adTimer = 1.3f;
            _adText.text = "+1 " + NAME[(int)_adItem] + "\nadded to your items!";
        }
        else _adPanel.SetActive(false);
    }

    // ============================================================
    //  PAKAI ITEM
    // ============================================================
    void OnItemButton(Item it)
    {
        if (GetItem(it) <= 0) { OpenShop(); return; }
        switch (it)
        {
            case Item.Undo:
                if (_hasUndo) DoUndo();
                else FlashHint("No move to undo yet");
                break;
            case Item.Hammer: EnterTargeting(Mode.Hammer); break;
            case Item.Bomb: EnterTargeting(Mode.Bomb); break;
        }
    }

    void EnterTargeting(Mode m)
    {
        _mode = m;
        _hintText.text = (m == Mode.Hammer)
            ? "HAMMER: tap a block to clear its row and column"
            : "BOMB: tap a block to blow up a 4x4 area";
    }

    void CancelTarget() { _mode = Mode.None; }

    void TryTargetTap(Vector2 sp)
    {
        if (_cam == null) _cam = Camera.main;
        if (_cam == null) return;
        if (!RaycastCell(sp, out int c, out int r)) return;

        var cells = new List<(int c, int r)>();
        if (_mode == Mode.Hammer)
        {
            for (int rr = 0; rr < _core.Height; rr++) cells.Add((c, rr));
            for (int cc = 0; cc < _core.Columns; cc++) if (cc != c) cells.Add((cc, r));
        }
        else if (_mode == Mode.Bomb)
        {
            for (int dc = -1; dc <= 2; dc++)
                for (int dr = -1; dr <= 2; dr++)
                {
                    int cc = _core.Wrap(c + dc);
                    int rr = r + dr;
                    if (rr >= 0 && rr < _core.Height) cells.Add((cc, rr));
                }
        }
        else return;

        // Rekam warna + posisi SEBELUM grid dibersihkan, untuk efek.
        var caps = new List<(int color, Vector3 pos, Quaternion rot)>();
        var seen = new HashSet<int>();
        foreach (var (cc, rr) in cells)
        {
            int key = cc * 1000 + rr;
            if (!seen.Add(key)) continue;
            if (rr < 0 || rr >= _core.Height) continue;
            int col = _core.Grid[cc, rr];
            if (col < 0) continue;
            caps.Add((col, _game.CellToWorld(cc, rr), _game.CellRotation(cc)));
        }

        bool bomb = _mode == Mode.Bomb;
        Vector3 center = _game.CellToWorld(c, r);

        // Lewat BlastCore.BlastCells, BUKAN menulis Grid[c,r] = -1 sendiri.
        // Menulis langsung melewatkan penghitungan ulang game over, sehingga
        // sebuah alat bisa membebaskan papan tapi game tetap merasa buntu.
        _core.BlastCells(cells);

        AddItem(bomb ? Item.Bomb : Item.Hammer, -1);

        _game.RenderGrid();
        _selfModified = true;
        _hasUndo = false;
        TakeSnapshot();
        _mode = Mode.None;

        StartCoroutine(BlockFx(caps, bomb, center));
    }

    bool RaycastCell(Vector2 sp, out int col, out int row)
    {
        col = 0; row = 0;
        var blocks = _game.transform.Find("Blocks");
        if (blocks == null) return false;
        for (int i = 0; i < blocks.childCount; i++)
        {
            var ch = blocks.GetChild(i);
            if (ch.GetComponent<Collider>() == null) ch.gameObject.AddComponent<BoxCollider>();
        }
        Ray ray = _cam.ScreenPointToRay(sp);
        if (Physics.Raycast(ray, out RaycastHit hit, 500f))
        {
            var n = hit.collider.gameObject.name; // "Block_c_r"
            var parts = n.Split('_');
            if (parts.Length == 3 && int.TryParse(parts[1], out col) && int.TryParse(parts[2], out row))
                return true;
        }
        return false;
    }

    // ============================================================
    //  TOKO
    // ============================================================
    public static void OpenShop() { if (Instance != null) Instance.OpenShopInternal(); }
    void OpenShopInternal() { _shopStatus.text = ""; RefreshShop(); _shop.SetActive(true); }
    void CloseShop() { _shop.SetActive(false); }

    void Buy(Item it)
    {
        int price = PRICE[(int)it];
        if (GetGems() < price) { _shopStatus.text = "Not enough gems"; return; }
        AddGems(-price);
        _gemShown = GetGems();
        AddItem(it, +1);
        _shopStatus.text = "Bought 1 " + NAME[(int)it] + "!";
        RefreshShop();
    }

    void RefreshShop()
    {
        _shopGems.text = "Gems: " + GetGems();
        for (int i = 0; i < 3; i++) _shopOwned[i].text = "Owned: " + GetItem((Item)i);
    }

    // ============================================================
    //  INVENTORY / GEM STORAGE
    // ============================================================
    int GetGems() => PlayerPrefs.GetInt(GEM_KEY, 0);
    void AddGems(int d) { PlayerPrefs.SetInt(GEM_KEY, Mathf.Max(0, GetGems() + d)); PlayerPrefs.Save(); }
    int GetItem(Item it) => PlayerPrefs.GetInt(ITEM_KEY[(int)it], 0);
    void AddItem(Item it, int d) { PlayerPrefs.SetInt(ITEM_KEY[(int)it], Mathf.Max(0, GetItem(it) + d)); PlayerPrefs.Save(); }

    void UpdateItemCounts()
    {
        for (int i = 0; i < 3; i++) if (_itemCount[i] != null) _itemCount[i].text = "x" + GetItem((Item)i);

        if (_gemLabel == null) return;
        int real = GetGems();
        if (_gemShown < 0) _gemShown = real;
        // Tidak ada permata terbang -> angka tampilan harus sama dengan aslinya.
        if (_gemsInFlight <= 0 && _gemShown != real) _gemShown = real;
        _gemLabel.text = _gemShown.ToString();
    }

    // ============================================================
    //  TOAST
    //  Dulu pesan seperti "belum ada langkah untuk di-undo" ditulis ke
    //  _shopStatus, yang hidup DI DALAM panel toko - jadi hanya terlihat kalau
    //  toko kebetulan terbuka.
    // ============================================================
    void FlashHint(string msg)
    {
        if (_toast == null) return;
        if (_toastCo != null) StopCoroutine(_toastCo);
        _toastCo = StartCoroutine(ToastRoutine(msg));
    }

    IEnumerator ToastRoutine(string msg)
    {
        _toast.text = msg;
        var col = _toast.color; col.a = 1f; _toast.color = col;
        var rt = _toast.rectTransform;

        float t = 0f;
        while (t < 0.16f)
        {
            t += Time.unscaledDeltaTime;
            rt.localScale = Vector3.one * Mathf.Lerp(0.7f, 1f, t / 0.16f);
            yield return null;
        }
        rt.localScale = Vector3.one;

        yield return new WaitForSecondsRealtime(1.1f);

        t = 0f;
        while (t < 0.35f)
        {
            t += Time.unscaledDeltaTime;
            col.a = 1f - (t / 0.35f);
            _toast.color = col;
            yield return null;
        }
        _toast.text = "";
        col.a = 1f; _toast.color = col;
        _toastCo = null;
    }

    // ============================================================
    //  INPUT
    // ============================================================
    void HandleTaps()
    {
        bool down = PDown();
        Vector2 p = PPos();

        if (_adPanel.activeSelf) return;
        if (_confirm.activeSelf)
        {
            if (down)
            {
                if (Hit(_btnYes, p)) StartAd();
                else if (Hit(_btnNo, p)) _confirm.SetActive(false);
            }
            return;
        }
        if (_shop.activeSelf)
        {
            if (down)
            {
                if (Hit(_shopClose, p)) CloseShop();
                else for (int i = 0; i < 3; i++) if (Hit(_shopBuy[i], p)) { Buy((Item)i); break; }
            }
            return;
        }
        if (!down) return;

        if (_tokoBtn.gameObject.activeSelf && Hit(_tokoBtn, p)) { OpenShop(); return; }

        if (_mode != Mode.None)
        {
            LastBuffUseTime = Time.unscaledTime;
            if (Hit(_btnCancel, p)) CancelTarget();
            else TryTargetTap(p);
            return;
        }

        if (Time.timeScale > 0f && !_core.GameOver)
        {
            if (_bubble != null && _bubble.activeSelf && Hit(_bubbleRT, p))
            {
                _bubble.SetActive(false);
                ScheduleNextBubble();
                OpenConfirm(_bubbleItem);
                return;
            }
            for (int i = 0; i < 3; i++)
                if (Hit(_itemBtn[i], p)) { OnItemButton((Item)i); return; }
        }
    }

    // ============================================================
    //  BUILD UI
    // ============================================================
    void BuildUI()
    {
        _built = true;
        LoadIcons();
        _backCanvas = MakeCanvas("KubikaItemsBack", 5);
        _play = MakeCanvas("KubikaItemsCanvas", 150);
        _modal = MakeCanvas("KubikaItemsModal", 330);
        _fxCanvas = MakeCanvas("KubikaItemsFx", 400);

        BuildFxOverlay();
        BuildItemBar();
        BuildGemHud();
        BuildToast();
        BuildHint();
        BuildBubble();
        BuildConfirm();
        BuildAd();
        BuildShop();
        BuildTokoButton();

        ScheduleNextBubble();
    }

    Canvas MakeCanvas(string name, int order)
    {
        var go = new GameObject(name, typeof(Canvas), typeof(CanvasScaler));
        go.transform.SetParent(transform, false);
        var cv = go.GetComponent<Canvas>();
        cv.renderMode = RenderMode.ScreenSpaceOverlay;
        cv.sortingOrder = order;
        var sc = go.GetComponent<CanvasScaler>();
        sc.uiScaleMode = CanvasScaler.ScaleMode.ScaleWithScreenSize;
        sc.referenceResolution = new Vector2(1080, 2400);
        sc.screenMatchMode = CanvasScaler.ScreenMatchMode.MatchWidthOrHeight;
        sc.matchWidthOrHeight = 0.5f;
        return cv;
    }

    void BuildItemBar()
    {
        var barGO = new GameObject("ItemBar", typeof(RectTransform));
        barGO.transform.SetParent(_play.transform, false);
        _itemBar = barGO;
        var brt = barGO.GetComponent<RectTransform>();
        brt.anchorMin = brt.anchorMax = new Vector2(0.5f, 0f);
        brt.pivot = new Vector2(0.5f, 0f);
        brt.anchoredPosition = Vector2.zero;
        brt.sizeDelta = new Vector2(1080, 700);

        float[] xs = { -240f, 0f, 240f };
        for (int i = 0; i < 3; i++)
        {
            var btn = MakeSprite("item" + i, barGO.transform, ICOL[i]);
            var rt = btn.rectTransform;
            Place(rt, new Vector2(0.5f, 0f), new Vector2(xs[i], 400f), new Vector2(210, 150));
            _itemBtn[i] = rt;

            var itSp = (i == 0) ? _spHammer : (i == 1) ? _spBomb : _spUndo;
            if (itSp != null)
            {
                // Item cukup lewat ikon saja - TANPA tulisan nama.
                var icon = MakeImage("icon" + i, rt, Color.white);
                icon.sprite = itSp;
                icon.preserveAspect = true;
                Place(icon.rectTransform, C, new Vector2(0, 4), new Vector2(132, 132));
                btn.color = new Color(ICOL[i].r, ICOL[i].g, ICOL[i].b, 0.30f);
            }
            else
            {
                // Fallback: kalau ikon belum ada, baru tampilkan nama supaya tombol tak kosong.
                var lbl = MakeText("lbl" + i, rt, 44, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
                lbl.text = NAME[i];
                Place(lbl.rectTransform, C, new Vector2(0, 10), new Vector2(210, 90));
            }

            var badge = MakeSprite("badge" + i, rt, new Color(0f, 0f, 0f, 0.55f));
            Place(badge.rectTransform, new Vector2(1f, 1f), new Vector2(-6, -6), new Vector2(84, 60));
            var cnt = MakeText("cnt" + i, badge.rectTransform, 40, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.9f, 0.4f));
            cnt.text = "x0";
            Place(cnt.rectTransform, C, Vector2.zero, new Vector2(84, 60));
            _itemCount[i] = cnt;
        }
    }

    void BuildGemHud()
    {
        var pill = MakeSprite("gemPill", _play.transform, new Color(0.10f, 0.12f, 0.20f, 0.72f));
        Place(pill.rectTransform, new Vector2(0f, 1f), new Vector2(36f, -196f), new Vector2(300f, 92f));
        _gemPill = pill.rectTransform;

        if (_spGem != null)
        {
            var gi = MakeImage("gemIcon", _play.transform, Color.white);
            gi.sprite = _spGem;
            gi.preserveAspect = true;
            Place(gi.rectTransform, new Vector2(0f, 1f), new Vector2(52f, -206f), new Vector2(64f, 64f));
        }

        _gemLabel = MakeText("gem", _play.transform, 46, TextAnchor.MiddleLeft, FontStyle.Bold, new Color(0.72f, 0.95f, 1f));
        _gemLabel.text = "0";
        Place(_gemLabel.rectTransform, new Vector2(0f, 1f), new Vector2(128f, -206f), new Vector2(180f, 72f));
    }

    void BuildToast()
    {
        _toast = MakeText("toast", _play.transform, 46, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.86f, 0.45f));
        _toast.text = "";
        Place(_toast.rectTransform, C, new Vector2(0f, -140f), new Vector2(960f, 100f));
    }

    void BuildHint()
    {
        var go = new GameObject("Hint", typeof(RectTransform));
        go.transform.SetParent(_play.transform, false);
        _hint = go;
        var rt = go.GetComponent<RectTransform>();
        rt.anchorMin = rt.anchorMax = new Vector2(0.5f, 0f);
        rt.pivot = new Vector2(0.5f, 0f);
        rt.anchoredPosition = Vector2.zero;
        rt.sizeDelta = new Vector2(1080, 700);

        var card = MakeSprite("hintCard", go.transform, new Color(0.10f, 0.12f, 0.20f, 0.92f));
        Place(card.rectTransform, new Vector2(0.5f, 0f), new Vector2(0, 470), new Vector2(940, 150));
        _hintText = MakeText("hintTxt", card.rectTransform, 42, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        Place(_hintText.rectTransform, C, new Vector2(0, 24), new Vector2(900, 70));

        _btnCancel = MakeButton(card.rectTransform, "CANCEL", new Vector2(0, -44), new Vector2(300, 74),
            new Color(0.55f, 0.35f, 0.35f), 40);
        _hint.SetActive(false);
    }

    void BuildBubble()
    {
        var img = MakeImage("Bubble", _backCanvas.transform, new Color(0.70f, 0.88f, 1f, 0.55f));
        img.sprite = BubbleSprite();
        img.type = Image.Type.Simple;
        img.preserveAspect = true;
        _bubble = img.gameObject;
        _bubbleRT = img.rectTransform;
        _bubbleRT.anchorMin = _bubbleRT.anchorMax = _bubbleRT.pivot = C;
        _bubbleRT.sizeDelta = new Vector2(190, 190);
        _bubbleRT.anchoredPosition = new Vector2(430, 1300);
        _bubbleLabel = MakeText("bubTxt", _bubbleRT, 40, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        _bubbleLabel.text = NAME[0];
        Place(_bubbleLabel.rectTransform, C, Vector2.zero, new Vector2(170, 170));
        _bubbleIcon = MakeImage("bubIcon", _bubbleRT, Color.white);
        _bubbleIcon.preserveAspect = true;
        Place(_bubbleIcon.rectTransform, C, Vector2.zero, new Vector2(128, 128));
        _bubbleIcon.gameObject.SetActive(false);
        _bubble.SetActive(false);
    }

    void BuildConfirm()
    {
        _confirm = MakeFullPanel(_modal.transform, "Confirm", new Color(0f, 0f, 0f, 0.6f));
        var card = MakeCard(_confirm.transform, new Vector2(0, 40), new Vector2(820, 700), new Color(0.12f, 0.13f, 0.24f, 0.97f));
        _confirmText = MakeText("cTxt", card, 52, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        Place(_confirmText.rectTransform, C, new Vector2(0, 190), new Vector2(760, 240));
        _btnYes = MakeButton(card, "WATCH AD", new Vector2(0, -30), new Vector2(560, 150), new Color(0.30f, 0.75f, 0.40f), 60);
        _btnNo = MakeButton(card, "NO THANKS", new Vector2(0, -210), new Vector2(560, 130), new Color(0.5f, 0.5f, 0.58f), 54);
        _confirm.SetActive(false);
    }

    void BuildAd()
    {
        _adPanel = MakeFullPanel(_modal.transform, "Ad", new Color(0f, 0f, 0f, 0.9f));
        var card = MakeCard(_adPanel.transform, new Vector2(0, 60), new Vector2(860, 520), new Color(0.08f, 0.09f, 0.16f, 0.98f));
        MakeDecoRow(card, new Vector2(0, 150));
        _adText = MakeText("adTxt", card, 58, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        Place(_adText.rectTransform, C, new Vector2(0, -20), new Vector2(800, 300));
        _adPanel.SetActive(false);
    }

    void BuildShop()
    {
        _shop = MakeFullPanel(_modal.transform, "Shop", new Color(0f, 0f, 0f, 0.75f));
        var card = MakeCard(_shop.transform, new Vector2(0, 40), new Vector2(940, 1600), new Color(0.10f, 0.12f, 0.20f, 0.96f));
        MakeDecoRow(card, new Vector2(0, 700));
        var title = MakeText("sTitle", card, 84, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.85f, 0.3f));
        title.text = "GEM SHOP";
        Place(title.rectTransform, C, new Vector2(0, 590), new Vector2(880, 130));
        if (_spCrown != null)
        {
            var cr = MakeImage("shopCrown", card, Color.white);
            cr.sprite = _spCrown;
            cr.preserveAspect = true;
            Place(cr.rectTransform, C, new Vector2(-370, 720), new Vector2(84, 84));
        }

        _shopGems = MakeText("sGems", card, 54, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(0.55f, 0.95f, 1f));
        Place(_shopGems.rectTransform, C, new Vector2(0, 470), new Vector2(880, 80));

        float[] ys = { 280f, 60f, -160f };
        for (int i = 0; i < 3; i++)
        {
            var row = MakeCard(card, new Vector2(0, ys[i]), new Vector2(840, 190), new Color(0f, 0f, 0f, 0.30f));
            var nm = MakeText("n" + i, row, 52, TextAnchor.MiddleLeft, FontStyle.Bold, ICOL[i]);
            nm.text = NAME[i];
            Place(nm.rectTransform, C, new Vector2(-320, 40), new Vector2(360, 70));
            _shopOwned[i] = MakeText("o" + i, row, 36, TextAnchor.MiddleLeft, FontStyle.Normal, new Color(0.8f, 0.85f, 0.95f));
            Place(_shopOwned[i].rectTransform, C, new Vector2(-320, -40), new Vector2(360, 60));
            var rowSp = (i == 0) ? _spHammer : (i == 1) ? _spBomb : _spUndo;
            if (rowSp != null)
            {
                var ri = MakeImage("ri" + i, row, Color.white);
                ri.sprite = rowSp;
                ri.preserveAspect = true;
                Place(ri.rectTransform, C, new Vector2(-370, 0), new Vector2(110, 110));
                Place(nm.rectTransform, C, new Vector2(-190, 40), new Vector2(320, 70));
                Place(_shopOwned[i].rectTransform, C, new Vector2(-190, -40), new Vector2(320, 60));
            }
            var price = MakeText("p" + i, row, 42, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.9f, 0.4f));
            price.text = PRICE[i] + " gems";
            Place(price.rectTransform, C, new Vector2(70, 0), new Vector2(320, 70));
            _shopBuy[i] = MakeButton(row, "BUY", new Vector2(310, 0), new Vector2(190, 120), new Color(0.30f, 0.70f, 0.42f), 46);
        }

        _shopStatus = MakeText("sStat", card, 40, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.7f, 0.4f));
        Place(_shopStatus.rectTransform, C, new Vector2(0, -370), new Vector2(880, 70));

        _shopClose = MakeButton(card, "CLOSE", new Vector2(0, -560), new Vector2(520, 150), new Color(0.45f, 0.47f, 0.55f), 60);
        _shop.SetActive(false);
    }

    void BuildTokoButton()
    {
        _tokoBtn = MakeButton(_modal.transform, "SHOP", new Vector2(0, -975), new Vector2(360, 150),
            new Color(1f, 0.72f, 0.25f), 64);
        _tokoBtn.gameObject.SetActive(false);
    }

    // ---- Helpers UI ----
    GameObject MakeFullPanel(Transform parent, string name, Color col)
    {
        var img = MakeImage(name, parent, col);
        var rt = img.rectTransform;
        rt.anchorMin = Vector2.zero; rt.anchorMax = Vector2.one; rt.pivot = C;
        rt.offsetMin = Vector2.zero; rt.offsetMax = Vector2.zero;
        return img.gameObject;
    }

    RectTransform MakeCard(Transform parent, Vector2 pos, Vector2 size, Color col)
    {
        var img = MakeSprite("Card", parent, col);
        Place(img.rectTransform, C, pos, size);
        return img.rectTransform;
    }

    void MakeDecoRow(Transform parent, Vector2 pos)
    {
        Color[] pal = { new Color(1f,0.36f,0.48f), new Color(1f,0.72f,0.30f), new Color(1f,0.84f,0.31f),
                        new Color(0.40f,0.73f,0.42f), new Color(0.31f,0.76f,0.97f) };
        for (int i = 0; i < pal.Length; i++)
        {
            var b = MakeSprite("deco" + i, parent, pal[i]);
            Place(b.rectTransform, C, new Vector2(pos.x + (i - 2) * 120f, pos.y), new Vector2(76, 76));
        }
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
        tex.wrapMode = TextureWrapMode.Clamp; tex.filterMode = FilterMode.Bilinear;
        var px = new Color32[size * size];
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
            {
                float a = RoundedAlpha(x, y, size, size, radius);
                px[y * size + x] = new Color32(255, 255, 255, (byte)Mathf.RoundToInt(a * 255f));
            }
        tex.SetPixels32(px); tex.Apply();
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

    // ============================================================
    //  IKON & SPRITE PROSEDURAL
    // ============================================================
    void LoadIcons()
    {
        _spHammer = LoadIcon("Hammer_A");
        _spBomb   = LoadIcon("Boom_A");
        _spUndo   = LoadIcon("Undo_A");
        _spGem    = LoadIcon("Gem_A");
        _spCrown  = LoadIcon("Crown_A");
    }

    Sprite LoadIcon(string name)
    {
        var tex = Resources.Load<Texture2D>("KubikaIcons/" + name);
        if (tex == null) return null;
        return Sprite.Create(tex, new Rect(0, 0, tex.width, tex.height), C, 100f);
    }

    Sprite BubbleSprite()
    {
        if (_bubbleSprite != null) return _bubbleSprite;
        int s = 128; var tex = new Texture2D(s, s, TextureFormat.RGBA32, false);
        tex.wrapMode = TextureWrapMode.Clamp; tex.filterMode = FilterMode.Bilinear;
        var px = new Color32[s * s];
        float cx = s * 0.5f, cy = s * 0.5f, R = s * 0.5f - 1f;
        float hx = s * 0.36f, hy = s * 0.66f;
        for (int y = 0; y < s; y++)
            for (int x = 0; x < s; x++)
            {
                float dx = x + 0.5f - cx, dy = y + 0.5f - cy;
                float d = Mathf.Sqrt(dx * dx + dy * dy);
                float cover = Mathf.Clamp01(R - d + 0.5f);
                float rim = Mathf.Clamp01((d - R * 0.55f) / (R * 0.45f));
                float a = cover * Mathf.Lerp(0.14f, 0.62f, rim * rim);
                float hd = Mathf.Sqrt((x + 0.5f - hx) * (x + 0.5f - hx) + (y + 0.5f - hy) * (y + 0.5f - hy));
                float hi = Mathf.Clamp01(1f - hd / (s * 0.14f)) * 0.85f * cover;
                float alpha = Mathf.Clamp01(Mathf.Max(a, hi));
                px[y * s + x] = new Color32(255, 255, 255, (byte)Mathf.RoundToInt(alpha * 255f));
            }
        tex.SetPixels32(px); tex.Apply();
        _bubbleSprite = Sprite.Create(tex, new Rect(0, 0, s, s), C, 100f);
        return _bubbleSprite;
    }

    Material FxMat(Color col, float emis)
    {
        var sh = Shader.Find("Universal Render Pipeline/Lit");
        if (sh == null) sh = Shader.Find("Standard");
        var m = new Material(sh);
        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", col);
        m.color = col;
        if (m.HasProperty("_EmissionColor")) { m.EnableKeyword("_EMISSION"); m.SetColor("_EmissionColor", col * emis); }
        return m;
    }

    // ============================================================
    //  JUICE
    //  Getar kamera & hit-stop TIDAK lagi dikerjakan sendiri di sini. Dulu file
    //  ini menulis Camera.main.localPosition langsung lalu memulihkan posisi
    //  yang KEBETULAN dilihatnya; kini BlastGame juga menggetarkan kamera, jadi
    //  keduanya saling menimpa dan bisa meninggalkan kamera melenceng. Hit-stop
    //  pun dulu menyetel Time.timeScale sendiri, padahal jaring pengaman
    //  KubikaMenu hanya tahu harus mengalah untuk BlastGame.HitStopActive.
    // ============================================================
    void BuildFxOverlay()
    {
        _flash = MakeImage("Flash", _fxCanvas.transform, new Color(1f, 1f, 1f, 0f));
        var rt = _flash.rectTransform;
        rt.anchorMin = Vector2.zero; rt.anchorMax = Vector2.one;
        rt.offsetMin = Vector2.zero; rt.offsetMax = Vector2.zero;
        _flash.raycastTarget = false;
    }

    void Shake(float amount) { if (_game != null) _game.Shake(amount); }
    void HitStop(float seconds, float scale) { if (_game != null) _game.HitStop(seconds, scale); }

    IEnumerator FlashScreen(Color col, float peak, float dur)
    {
        if (_flash == null) yield break;
        float t = 0f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / dur);
            float a = (k < 0.25f) ? Mathf.Lerp(0f, peak, k / 0.25f)
                                  : Mathf.Lerp(peak, 0f, (k - 0.25f) / 0.75f);
            var c = col; c.a = a; _flash.color = c;
            yield return null;
        }
        var c2 = col; c2.a = 0f; _flash.color = c2;
    }

    IEnumerator ShockRing(Vector2 screenPos, Color col, float maxScale, float dur)
    {
        if (_play == null) yield break;
        var img = MakeImage("shock", _play.transform, col);
        img.sprite = RoundSprite();
        var rt = img.rectTransform;
        rt.anchorMin = rt.anchorMax = rt.pivot = C;
        RectTransformUtility.ScreenPointToLocalPointInRectangle(
            (RectTransform)_play.transform, screenPos, null, out Vector2 local);
        rt.anchoredPosition = local;
        rt.sizeDelta = new Vector2(120, 120);
        float baseA = col.a;
        float t = 0f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / dur);
            rt.localScale = Vector3.one * Mathf.Lerp(0.4f, maxScale, k);
            var c = col; c.a = Mathf.Lerp(baseA, 0f, k); img.color = c;
            yield return null;
        }
        Destroy(img.gameObject);
    }

    // ---- Efek HAMMER / BOMB pada blok 3D ----
    IEnumerator BlockFx(List<(int color, Vector3 pos, Quaternion rot)> caps, bool bomb, Vector3 center)
    {
        if (_game == null || caps == null || caps.Count == 0) yield break;
        Mesh mesh = _game.CellMesh;
        Vector3 bs = new Vector3(_game.cellWidth * _game.gap, _game.cellHeight * _game.gap, _game.blockDepth);

        if (_cam == null) _cam = Camera.main;
        Vector3 worldCenter = _game.transform.TransformPoint(center);
        Vector2 screenCenter = _cam != null
            ? (Vector2)_cam.WorldToScreenPoint(worldCenter)
            : new Vector2(Screen.width * 0.5f, Screen.height * 0.5f);

        if (!bomb)
        {
            yield return StartCoroutine(HammerCascade(caps, center, screenCenter, mesh, bs));
            yield break;
        }

        caps.Sort((a, b) => (a.pos - center).sqrMagnitude.CompareTo((b.pos - center).sqrMagnitude));
        float maxd = 0.01f;
        for (int i = 0; i < caps.Count; i++) maxd = Mathf.Max(maxd, (caps[i].pos - center).magnitude);

        var flashes = new List<GameObject>(caps.Count);
        var cols = new List<Color>(caps.Count);
        var startAt = new float[caps.Count];
        const float igniteSpread = 0.30f;

        for (int i = 0; i < caps.Count; i++)
        {
            var cap = caps[i];
            Color bc = (_game.palette != null && cap.color >= 0 && cap.color < _game.palette.Length)
                ? _game.palette[cap.color] : new Color(0.7f, 0.7f, 0.7f);
            cols.Add(bc);
            startAt[i] = (cap.pos - center).magnitude / maxd * igniteSpread;

            var go = new GameObject("KItemFx");
            go.transform.SetParent(_game.transform, false);
            go.transform.localPosition = cap.pos;
            go.transform.localRotation = cap.rot;
            go.transform.localScale = bs;
            var mf = go.AddComponent<MeshFilter>(); mf.sharedMesh = mesh;
            var mr = go.AddComponent<MeshRenderer>();
            mr.material = FxMat(bc, 0.2f);
            mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            mr.receiveShadows = false;
            flashes.Add(go);
        }

        float ramp = 0.16f;
        float total = igniteSpread + ramp + 0.05f;
        float t = 0f;
        while (t < total)
        {
            t += Time.deltaTime;
            for (int i = 0; i < flashes.Count; i++)
            {
                var go = flashes[i]; if (go == null) continue;
                float lt = Mathf.Clamp01((t - startAt[i]) / ramp);
                go.transform.localScale = bs * Mathf.Lerp(1f, 1.14f, lt);
                var m = go.GetComponent<MeshRenderer>().sharedMaterial;
                Color cc = Color.Lerp(cols[i], Color.white, lt);
                if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", cc);
                m.color = cc;
                if (m.HasProperty("_EmissionColor")) m.SetColor("_EmissionColor", cc * Mathf.Lerp(0.2f, 1.7f, lt));
            }
            yield return null;
        }

        // Klimaks ledakan.
        if (KubikaSfx.Instance != null) KubikaSfx.Instance.PlayBomb();
        StartCoroutine(FlashScreen(new Color(1f, 0.85f, 0.55f), 0.6f, 0.26f));
        Shake(1.0f);
        StartCoroutine(ShockRing(screenCenter, new Color(1f, 0.7f, 0.3f, 0.65f), 6.5f, 0.4f));
        StartCoroutine(ShockRing(screenCenter, new Color(1f, 0.95f, 0.6f, 0.5f), 4.0f, 0.3f));
        HitStop(0.07f, 0.06f);

        for (int i = 0; i < flashes.Count; i++)
        {
            if (flashes[i] != null) Destroy(flashes[i]);
            SpawnDebris(caps[i].pos, cols[i], mesh, bs);
        }
    }

    IEnumerator HammerCascade(List<(int color, Vector3 pos, Quaternion rot)> caps, Vector3 center, Vector2 screenCenter, Mesh mesh, Vector3 bs)
    {
        StartCoroutine(FlashScreen(Color.white, 0.34f, 0.12f));
        Shake(0.45f);
        StartCoroutine(ShockRing(screenCenter, new Color(1f, 0.96f, 0.75f, 0.6f), 3.6f, 0.3f));
        HitStop(0.045f, 0.06f);

        caps.Sort((a, b) => (a.pos - center).sqrMagnitude.CompareTo((b.pos - center).sqrMagnitude));

        for (int i = 0; i < caps.Count; i++)
        {
            var cap = caps[i];
            Color bc = (_game.palette != null && cap.color >= 0 && cap.color < _game.palette.Length)
                ? _game.palette[cap.color] : new Color(0.7f, 0.7f, 0.7f);

            if (KubikaSfx.Instance != null)
            {
                if (i == 0) KubikaSfx.Instance.PlayHammer();
                else KubikaSfx.Instance.PlayHammerTick(i);
            }

            StartCoroutine(HammerHitOne(cap.pos, cap.rot, bc, mesh, bs));

            if (i > 0 && (i % 2 == 0)) Shake(0.16f);

            yield return new WaitForSecondsRealtime(0.07f);
        }
    }

    IEnumerator HammerHitOne(Vector3 localPos, Quaternion rot, Color col, Mesh mesh, Vector3 bs)
    {
        var go = new GameObject("KItemHit");
        go.transform.SetParent(_game.transform, false);
        go.transform.localPosition = localPos;
        go.transform.localRotation = rot;
        go.transform.localScale = bs;
        var mf = go.AddComponent<MeshFilter>(); mf.sharedMesh = mesh;
        var mr = go.AddComponent<MeshRenderer>();
        mr.material = FxMat(col, 0.2f);
        mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        mr.receiveShadows = false;

        float dur = 0.12f, t = 0f;
        while (t < dur)
        {
            t += Time.deltaTime;
            float lt = Mathf.Clamp01(t / dur);
            go.transform.localScale = bs * Mathf.Lerp(1f, 1.22f, lt);
            var m = mr.sharedMaterial;
            Color cc = Color.Lerp(col, Color.white, lt);
            if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", cc);
            m.color = cc;
            if (m.HasProperty("_EmissionColor")) m.SetColor("_EmissionColor", cc * Mathf.Lerp(0.2f, 2f, lt));
            yield return null;
        }
        Destroy(go);
        SpawnDebris(localPos, col, mesh, bs);
    }

    void SpawnDebris(Vector3 localPos, Color col, Mesh mesh, Vector3 bs)
    {
        int n = Random.Range(8, 12);
        for (int i = 0; i < n; i++)
        {
            var go = new GameObject("KItemDebris");
            go.transform.SetParent(_game.transform, false);
            go.transform.localPosition = localPos + Random.insideUnitSphere * 0.14f;
            go.transform.localRotation = Random.rotation;
            float sz = Random.Range(0.12f, 0.4f);
            Vector3 s0 = new Vector3(bs.x * sz, bs.y * sz, bs.z * sz);
            go.transform.localScale = s0;
            var mf = go.AddComponent<MeshFilter>(); mf.sharedMesh = mesh;
            var mr = go.AddComponent<MeshRenderer>();
            mr.material = FxMat(col, 0.4f);
            mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
            mr.receiveShadows = false;
            Vector3 dir = (go.transform.localPosition - localPos);
            if (dir.sqrMagnitude < 0.0001f) dir = Random.onUnitSphere;
            Vector3 vel = dir.normalized * Random.Range(1.7f, 4.3f) + Vector3.up * Random.Range(0.7f, 2.6f);
            StartCoroutine(DebrisFx(go, vel, s0));
        }
    }

    IEnumerator DebrisFx(GameObject go, Vector3 vel, Vector3 s0)
    {
        float t = 0f, dur = Random.Range(0.5f, 0.78f);
        while (t < dur)
        {
            if (go == null) yield break;
            float dt = Time.deltaTime; t += dt;
            vel += Vector3.down * 7f * dt;
            go.transform.localPosition += vel * dt;
            go.transform.Rotate(240f * dt, 170f * dt, 90f * dt);
            go.transform.localScale = Vector3.Lerp(s0, s0 * 0.15f, t / dur);
            yield return null;
        }
        if (go != null) Destroy(go);
    }

    // ============================================================
    //  PERMATA
    //  Dulu: maksimal 8 sprite berapa pun permata yang didapat, dan angka HUD
    //  melompat ke nilai akhir saat itu juga - sebelum satu pun permata sampai,
    //  jadi permata yang terbang tidak berarti apa-apa. Sekarang jumlahnya nyata
    //  (sampai 20, masing-masing membawa jatahnya), melengkung ke HUD sambil
    //  meninggalkan jejak, dan angkanya merangkak naik seiring pendaratan.
    // ============================================================
    IEnumerator GemBurst(int gems, int combo)
    {
        if (_play == null || _gemLabel == null) yield break;

        Vector2 origin = _burstOrigin;
        Vector2 target = GemTarget();

        int n = Mathf.Clamp(gems, 1, MAX_GEM_SPRITES);
        int per = Mathf.Max(1, Mathf.CeilToInt((float)gems / n));
        _gemsInFlight += n;

        StartCoroutine(GemRing(origin, combo));
        StartCoroutine(GemGainPopup(gems, target + new Vector2(150f, -34f)));

        int given = 0;
        for (int i = 0; i < n; i++)
        {
            int worth = Mathf.Max(1, Mathf.Min(per, gems - given));
            given += worth;
            StartCoroutine(GemFly(i, origin, target, worth));
            yield return new WaitForSecondsRealtime(0.035f);
        }
    }

    IEnumerator GemFly(int index, Vector2 origin, Vector2 target, int worth)
    {
        var img = MakeImage("gemfx", _play.transform, Color.white);
        if (_spGem != null) { img.sprite = _spGem; img.preserveAspect = true; }
        else { img.sprite = RoundSprite(); img.color = new Color(0.62f, 0.35f, 1f); }
        var rt = img.rectTransform;
        rt.anchorMin = rt.anchorMax = rt.pivot = C;
        rt.sizeDelta = new Vector2(92, 92);

        Vector2 pos = origin + new Vector2(Random.Range(-70f, 70f), Random.Range(-40f, 40f));
        rt.anchoredPosition = pos;
        rt.localScale = Vector3.zero;

        // 1) Lahir: pop dengan sedikit overshoot.
        float t = 0f, birth = 0.16f;
        while (t < birth)
        {
            t += Time.unscaledDeltaTime;
            float k = t / birth;
            float s = (k < 0.7f) ? Mathf.Lerp(0.15f, 1.2f, k / 0.7f)
                                 : Mathf.Lerp(1.2f, 1f, (k - 0.7f) / 0.3f);
            rt.localScale = Vector3.one * s;
            yield return null;
        }

        // 2) Terlempar keluar sebentar.
        Vector2 vel = new Vector2(Random.Range(-260f, 260f), Random.Range(180f, 420f));
        t = 0f;
        float scatter = Random.Range(0.22f, 0.34f);
        while (t < scatter)
        {
            float dt = Time.unscaledDeltaTime; t += dt;
            vel.y -= 1500f * dt;
            pos += vel * dt;
            rt.anchoredPosition = pos;
            rt.localRotation = Quaternion.Euler(0f, 0f, rt.localEulerAngles.z + 320f * dt);
            yield return null;
        }

        // 3) Terbang MELENGKUNG ke HUD sambil meninggalkan jejak.
        Vector2 from = pos;
        Vector2 mid = (from + target) * 0.5f
                    + new Vector2(Random.Range(-120f, 120f), Random.Range(160f, 300f));
        Color trailCol = new Color(0.72f, 0.95f, 1f, 0.5f);
        float fly = 0.5f + index * 0.012f;
        float trailAt = 0f;
        t = 0f;
        while (t < fly)
        {
            float dt = Time.unscaledDeltaTime; t += dt;
            float k = Mathf.Clamp01(t / fly);
            float e = k * k * (3f - 2f * k);
            Vector2 a = Vector2.Lerp(from, mid, e);
            Vector2 b = Vector2.Lerp(mid, target, e);
            pos = Vector2.Lerp(a, b, e);
            rt.anchoredPosition = pos;
            rt.localScale = Vector3.one * Mathf.Lerp(1f, 0.42f, e);
            rt.localRotation = Quaternion.Euler(0f, 0f, rt.localEulerAngles.z + 220f * dt);

            trailAt -= dt;
            if (trailAt <= 0f)
            {
                trailAt = 0.028f;
                StartCoroutine(TrailDot(pos, 34f * (1f - e * 0.5f), trailCol));
            }
            yield return null;
        }

        Destroy(img.gameObject);

        // 4) Mendarat: kilau kecil, angka HUD naik, tik nada meninggi.
        StartCoroutine(LandFlash(target));
        if (_gemLabel != null) StartCoroutine(PunchLabel(_gemLabel.rectTransform));
        _gemShown = Mathf.Min(GetGems(), Mathf.Max(0, _gemShown) + worth);
        if (KubikaSfx.Instance != null) KubikaSfx.Instance.PlayGemTick(index);
        _gemsInFlight = Mathf.Max(0, _gemsInFlight - 1);
    }

    IEnumerator TrailDot(Vector2 pos, float size, Color col)
    {
        var img = MakeImage("gemTrail", _play.transform, col);
        img.sprite = RoundSprite();
        var rt = img.rectTransform;
        rt.anchorMin = rt.anchorMax = rt.pivot = C;
        rt.anchoredPosition = pos;
        rt.sizeDelta = new Vector2(size, size);
        float t = 0f, dur = 0.26f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float k = t / dur;
            rt.localScale = Vector3.one * Mathf.Lerp(1f, 0.2f, k);
            var c = col; c.a = Mathf.Lerp(col.a, 0f, k); img.color = c;
            yield return null;
        }
        Destroy(img.gameObject);
    }

    IEnumerator LandFlash(Vector2 at)
    {
        var img = MakeImage("gemLand", _play.transform, new Color(0.8f, 0.96f, 1f, 0.75f));
        img.sprite = RoundSprite();
        var rt = img.rectTransform;
        rt.anchorMin = rt.anchorMax = rt.pivot = C;
        rt.anchoredPosition = at;
        rt.sizeDelta = new Vector2(70, 70);
        float t = 0f, dur = 0.22f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float k = t / dur;
            rt.localScale = Vector3.one * Mathf.Lerp(0.4f, 2.2f, k);
            var c = img.color; c.a = Mathf.Lerp(0.75f, 0f, k); img.color = c;
            yield return