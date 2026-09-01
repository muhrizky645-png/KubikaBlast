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

public class KubikaItems : MonoBehaviour
{
    public static KubikaItems Instance { get; private set; }
    public static bool TargetingActive => Instance != null && Instance._mode != Mode.None;
    public static float LastBuffUseTime = -999f;

    // Enum & urutan KEY simpanan sengaja TIDAK diubah supaya jumlah item yang sudah
    // dimiliki pemain tidak rusak. Yang diubah hanya URUTAN TAMPIL (lihat *_ORDER).
    enum Item { Hammer = 0, Bomb = 1, Undo = 2 }
    enum Mode { None, Hammer, Bomb }
    Mode _mode = Mode.None;

    const string GEM_KEY = "kubika_gems";
    static readonly string[] ITEM_KEY = { "kubika_item_hammer", "kubika_item_bomb", "kubika_item_undo" };

    // Harga: Bom termahal, Undo termurah.
    static readonly int[] PRICE = { 180, 260, 120 };
    static readonly string[] NAME = { "HAMMER", "BOMB", "UNDO" };
    static readonly Color[] ICOL =
    {
        new Color(1.00f, 0.72f, 0.30f),
        new Color(1.00f, 0.36f, 0.48f),
        new Color(0.31f, 0.76f, 0.97f),
    };

    // Urutan tampil di shop (atas -> bawah): Bom, Palu, Undo.
    static readonly Item[] SHOP_ORDER = { Item.Bomb, Item.Hammer, Item.Undo };
    // Urutan tampil di item bar (kiri -> kanan): Undo, Palu, Bom => Bom paling kanan.
    static readonly Item[] BAR_ORDER = { Item.Undo, Item.Hammer, Item.Bomb };

    // Paket permata (SIMULASI pembayaran). Patokan: $1 ~ 3.000 permata.
    static readonly string[] PACK_NAME = { "POUCH", "CHEST", "VAULT" };
    static readonly int[] PACK_GEMS = { 3000, 16500, 35000 };
    static readonly string[] PACK_PRICE = { "$0.99", "$4.99", "$9.99" };
    static readonly string[] PACK_SUB = { "Starter pack", "+10% bonus", "+17% bonus" };
    static readonly string[] PACK_TAG = { "", "POPULAR", "BEST VALUE" };

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
    Item _adItem;

    GameObject _shop;
    Text _shopGems, _shopStatus;
    Text[] _shopOwned = new Text[3];
    Text[] _shopPrice = new Text[3];
    RectTransform[] _shopBuy = new RectTransform[3];
    RectTransform[] _shopCard = new RectTransform[3];
    RectTransform[] _packBuy = new RectTransform[3];
    RectTransform _shopGemPill;
    RectTransform _shopClose;
    RectTransform _tokoBtn;
    int _shopGemAnim = -1;

    GameObject _pay;
    Text _payText;
    float _payTimer;
    int _payPack;

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
        bool anyModal = _confirm.activeSelf || _adPanel.activeSelf || _shop.activeSelf || _pay.activeSelf;
        _itemBar.SetActive(playing && _mode == Mode.None && !anyModal);
        _hint.SetActive(playing && _mode != Mode.None && !anyModal);
        UpdateItemCounts();

        string menu = KubikaMenu.CurrentScreenName;
        bool showToko = !anyModal && (menu == "Home" || menu == "Paused");
        _tokoBtn.gameObject.SetActive(showToko);

        HandleBubble(playing && _mode == Mode.None && !anyModal);

        if (_adPanel.activeSelf) HandleAdTimer();
        if (_pay.activeSelf) HandlePayTimer();

        HandleTaps();

        _selfModified = false;
    }

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

    Vector2 BurstOrigin(BlastCore.ClearInfo info)
    {
        if (_cam == null) _cam = Camera.main;
        if (_cam == null || _game == null || _play == null ||
            info.Cells == null || info.Cells.Count == 0)
            return new Vector2(0f, 180f);

        Vector3 sum = Vector3.zero;
        foreach (var cell in info.Cells) sum += _game.CellToWorld(cell.c, cell.r);
        return WorldToPlay(sum / info.Cells.Count);
    }

    // Ubah posisi lokal sel papan jadi koordinat lokal canvas HUD.
    Vector2 WorldToPlay(Vector3 localCell)
    {
        if (_cam == null) _cam = Camera.main;
        if (_cam == null || _game == null || _play == null) return new Vector2(0f, 180f);
        Vector3 world = _game.transform.TransformPoint(localCell);
        Vector2 sp = _cam.WorldToScreenPoint(world);
        RectTransformUtility.ScreenPointToLocalPointInRectangle(
            (RectTransform)_play.transform, sp, null, out Vector2 local);
        return local;
    }

    // Posisi tengah sebuah RectTransform dalam koordinat lokal canvas tertentu.
    Vector2 CanvasPos(RectTransform rt, Canvas cv)
    {
        if (rt == null || cv == null) return Vector2.zero;
        Vector3 world = rt.TransformPoint(rt.rect.center);
        Vector2 sp = RectTransformUtility.WorldToScreenPoint(null, world);
        RectTransformUtility.ScreenPointToLocalPointInRectangle(
            (RectTransform)cv.transform, sp, null, out Vector2 local);
        return local;
    }

    Vector2 GemTarget()
    {
        if (_gemPill == null || _play == null) return new Vector2(-354f, 958f);
        return CanvasPos(_gemPill, _play);
    }

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
        var bSp = IconOf(_bubbleItem);
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
        _adTimer = 2.5f;
        _adText.text = "Showing ad...\n(simulated)";
        _adPanel.SetActive(true);
    }

    void HandleAdTimer()
    {
        _adTimer -= Time.unscaledDeltaTime;
        if (_adTimer > 0f)
        {
            _adText.text = "Showing ad...\n(simulated)  " + Mathf.CeilToInt(_adTimer);
            return;
        }
        // Hadiah langsung diberikan, panel ditutup, lalu ikonnya terbang ke HUD.
        AddItem(_adItem, +1);
        _adPanel.SetActive(false);
        StartCoroutine(RewardToHudFx(_adItem));
    }

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

        // BlastCells sudah memberi skor SETENGAH nilai sel biasa. Di sini kita cuma
        // memunculkan popup "+N" supaya kenaikan skornya KELIHATAN oleh pemain.
        var res = _core.BlastCells(cells);

        AddItem(bomb ? Item.Bomb : Item.Hammer, -1);

        _game.RenderGrid();
        _selfModified = true;
        _hasUndo = false;
        TakeSnapshot();
        _mode = Mode.None;

        StartCoroutine(BlockFx(caps, bomb, center));

        if (res.Score > 0)
            StartCoroutine(ScorePopup(res.Score, WorldToPlay(center), bomb ? 0.45f : 0.06f));
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
            var n = hit.collider.gameObject.name;
            var parts = n.Split('_');
            if (parts.Length == 3 && int.TryParse(parts[1], out col) && int.TryParse(parts[2], out row))
                return true;
        }
        return false;
    }

    public static void OpenShop() { if (Instance != null) Instance.OpenShopInternal(); }
    void OpenShopInternal() { _shopStatus.text = ""; _shopGemAnim = -1; RefreshShop(); _shop.SetActive(true); }
    void CloseShop() { _shop.SetActive(false); }

    void Buy(Item it)
    {
        int price = PRICE[(int)it];
        if (GetGems() < price)
        {
            _shopStatus.text = "Not enough gems";
            if (_shopGems != null) StartCoroutine(PunchLabel(_shopGems.rectTransform));
            return;
        }
        AddGems(-price);
        _gemShown = GetGems();
        AddItem(it, +1);
        _shopStatus.text = "Bought 1 " + NAME[(int)it] + "!";
        RefreshShop();

        // Efek: ikon item nge-pop keluar dari kartunya, lalu turun sambil mengecil.
        Vector2 at = (_shopCard[(int)it] != null)
            ? CanvasPos(_shopCard[(int)it], _fxCanvas)
            : Vector2.zero;
        StartCoroutine(BuyPopFx(it, at));
    }

    void BuyPack(int i)
    {
        _payPack = Mathf.Clamp(i, 0, 2);
        _payTimer = 1.8f;
        _payText.text = "Processing payment...\n(simulated)";
        _pay.SetActive(true);
    }

    void HandlePayTimer()
    {
        _payTimer -= Time.unscaledDeltaTime;
        if (_payTimer > 0f) return;

        int gems = PACK_GEMS[_payPack];
        _shopGemAnim = GetGems();   // counter mulai dari nilai lama, lalu naik pelan.
        AddGems(gems);
        _pay.SetActive(false);
        _shopStatus.text = PACK_NAME[_payPack] + " purchased!  +" + gems.ToString("N0") + " gems";
        RefreshShop();
        StartCoroutine(PackGemFx(gems));
    }

    void RefreshShop()
    {
        int gems = GetGems();
        int shown = (_shopGemAnim >= 0) ? _shopGemAnim : gems;
        if (_shopGems != null) _shopGems.text = shown.ToString("N0");

        for (int i = 0; i < 3; i++)
        {
            if (_shopOwned[i] != null) _shopOwned[i].text = "Owned: " + GetItem((Item)i);

            bool can = gems >= PRICE[i];
            if (_shopBuy[i] != null)
            {
                var img = _shopBuy[i].GetComponent<Image>();
                if (img != null)
                    img.color = can ? new Color(0.24f, 0.72f, 0.42f) : new Color(0.33f, 0.35f, 0.42f);
            }
            if (_shopPrice[i] != null)
                _shopPrice[i].color = can ? new Color(1f, 0.88f, 0.38f) : new Color(1f, 0.48f, 0.48f);
        }
    }

    int GetGems() => PlayerPrefs.GetInt(GEM_KEY, 0);
    void AddGems(int d) { PlayerPrefs.SetInt(GEM_KEY, Mathf.Max(0, GetGems() + d)); PlayerPrefs.Save(); }
    int GetItem(Item it) => PlayerPrefs.GetInt(ITEM_KEY[(int)it], 0);
    void AddItem(Item it, int d) { PlayerPrefs.SetInt(ITEM_KEY[(int)it], Mathf.Max(0, GetItem(it) + d)); PlayerPrefs.Save(); }

    Sprite IconOf(Item it) => (it == Item.Hammer) ? _spHammer : (it == Item.Bomb) ? _spBomb : _spUndo;

    void UpdateItemCounts()
    {
        for (int i = 0; i < 3; i++) if (_itemCount[i] != null) _itemCount[i].text = "x" + GetItem((Item)i);

        if (_gemLabel == null) return;
        int real = GetGems();
        if (_gemShown < 0) _gemShown = real;
        if (_gemsInFlight <= 0 && _gemShown != real) _gemShown = real;
        _gemLabel.text = _gemShown.ToString();
    }

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

    void HandleTaps()
    {
        bool down = PDown();
        Vector2 p = PPos();

        if (_pay.activeSelf) return;
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
                if (Hit(_shopClose, p)) { CloseShop(); return; }
                for (int i = 0; i < 3; i++) if (Hit(_shopBuy[i], p)) { Buy((Item)i); return; }
                for (int i = 0; i < 3; i++) if (Hit(_packBuy[i], p)) { BuyPack(i); return; }
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
        BuildPay();
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

        // Kiri -> kanan: Undo, Palu, Bom (Bom paling kanan).
        float[] xs = { -240f, 0f, 240f };
        for (int slot = 0; slot < 3; slot++)
        {
            int i = (int)BAR_ORDER[slot];

            var btn = MakeSprite("item" + i, barGO.transform, ICOL[i]);
            var rt = btn.rectTransform;
            Place(rt, new Vector2(0.5f, 0f), new Vector2(xs[slot], 400f), new Vector2(210, 150));
            _itemBtn[i] = rt;

            var itSp = IconOf((Item)i);
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

    void BuildPay()
    {
        _pay = MakeFullPanel(_modal.transform, "Pay", new Color(0f, 0f, 0f, 0.92f));
        var card = MakeCard(_pay.transform, new Vector2(0, 60), new Vector2(860, 520), new Color(0.08f, 0.09f, 0.16f, 0.98f));
        MakeDecoRow(card, new Vector2(0, 150));
        _payText = MakeText("payTxt", card, 54, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        Place(_payText.rectTransform, C, new Vector2(0, -20), new Vector2(800, 300));
        _pay.SetActive(false);
    }

    void BuildShop()
    {
        _shop = MakeFullPanel(_modal.transform, "Shop", new Color(0f, 0f, 0f, 0.78f));
        var card = MakeCard(_shop.transform, new Vector2(0, 30), new Vector2(960, 2000),
            new Color(0.10f, 0.12f, 0.20f, 0.97f));

        // ---- header: judul kiri, counter permata di POJOK KANAN ATAS ----
        if (_spCrown != null)
        {
            var cr = MakeImage("shopCrown", card, Color.white);
            cr.sprite = _spCrown;
            cr.preserveAspect = true;
            Place(cr.rectTransform, C, new Vector2(-395, 892), new Vector2(86, 86));
        }

        var title = MakeText("sTitle", card, 74, TextAnchor.MiddleLeft, FontStyle.Bold, new Color(1f, 0.85f, 0.3f));
        title.text = "GEM SHOP";
        Place(title.rectTransform, C, new Vector2(-50, 890), new Vector2(560, 110));

        var pill = MakeSprite("shopGemPill", card, new Color(0f, 0f, 0f, 0.42f));
        Place(pill.rectTransform, C, new Vector2(330, 890), new Vector2(290, 96));
        _shopGemPill = pill.rectTransform;
        if (_spGem != null)
        {
            var gi = MakeImage("shopGemIcon", pill.rectTransform, Color.white);
            gi.sprite = _spGem;
            gi.preserveAspect = true;
            Place(gi.rectTransform, C, new Vector2(-98, 0), new Vector2(64, 64));
        }
        _shopGems = MakeText("sGems", pill.rectTransform, 50, TextAnchor.MiddleLeft, FontStyle.Bold,
            new Color(0.72f, 0.95f, 1f));
        _shopGems.text = "0";
        Place(_shopGems.rectTransform, C, new Vector2(30, 0), new Vector2(180, 70));

        // ---- bagian 1: kartu item (Bom, Palu, Undo) ----
        var sec1 = MakeText("sec1", card, 40, TextAnchor.MiddleLeft, FontStyle.Bold, new Color(0.62f, 0.68f, 0.82f));
        sec1.text = "ITEMS";
        Place(sec1.rectTransform, C, new Vector2(-215, 790), new Vector2(400, 60));

        float[] iy = { 660f, 452f, 244f };
        for (int slot = 0; slot < 3; slot++)
        {
            int i = (int)SHOP_ORDER[slot];
            var col = ICOL[i];

            var row = MakeCard(card, new Vector2(0, iy[slot]), new Vector2(880, 190),
                new Color(col.r * 0.20f, col.g * 0.20f, col.b * 0.20f, 0.82f));
            _shopCard[i] = row;

            var thumb = MakeSprite("th" + i, row, new Color(col.r, col.g, col.b, 0.20f));
            Place(thumb.rectTransform, C, new Vector2(-348, 0), new Vector2(150, 150));

            var ic = IconOf((Item)i);
            if (ic != null)
            {
                var ri = MakeImage("ri" + i, thumb.rectTransform, Color.white);
                ri.sprite = ic;
                ri.preserveAspect = true;
                Place(ri.rectTransform, C, Vector2.zero, new Vector2(112, 112));
            }

            var nm = MakeText("n" + i, row, 50, TextAnchor.MiddleLeft, FontStyle.Bold, col);
            nm.text = NAME[i];
            Place(nm.rectTransform, C, new Vector2(-78, 40), new Vector2(340, 66));

            _shopOwned[i] = MakeText("o" + i, row, 34, TextAnchor.MiddleLeft, FontStyle.Normal,
                new Color(0.74f, 0.80f, 0.92f));
            _shopOwned[i].text = "Owned: 0";
            Place(_shopOwned[i].rectTransform, C, new Vector2(-78, -38), new Vector2(340, 56));

            if (_spGem != null)
            {
                var pg = MakeImage("pg" + i, row, Color.white);
                pg.sprite = _spGem;
                pg.preserveAspect = true;
                Place(pg.rectTransform, C, new Vector2(62, 0), new Vector2(48, 48));
            }
            _shopPrice[i] = MakeText("p" + i, row, 44, TextAnchor.MiddleLeft, FontStyle.Bold,
                new Color(1f, 0.88f, 0.38f));
            _shopPrice[i].text = PRICE[i].ToString();
            Place(_shopPrice[i].rectTransform, C, new Vector2(178, 0), new Vector2(170, 64));

            _shopBuy[i] = MakeButton(row, "BUY", new Vector2(352, 0), new Vector2(172, 112),
                new Color(0.24f, 0.72f, 0.42f), 46);
        }

        // ---- bagian 2: paket permata (simulasi bayar) ----
        var div = MakeImage("div", card, new Color(1f, 1f, 1f, 0.12f));
        Place(div.rectTransform, C, new Vector2(0, 140), new Vector2(880, 3));

        var sec2 = MakeText("sec2", card, 46, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.85f, 0.35f));
        sec2.text = "GET MORE GEMS";
        Place(sec2.rectTransform, C, new Vector2(0, 76), new Vector2(880, 66));

        float[] py = { -40f, -246f, -452f };
        for (int i = 0; i < 3; i++)
        {
            var row = MakeCard(card, new Vector2(0, py[i]), new Vector2(880, 186),
                new Color(0.24f, 0.20f, 0.44f, 0.88f));

            if (_spGem != null)
            {
                var gi = MakeImage("pgi" + i, row, Color.white);
                gi.sprite = _spGem;
                gi.preserveAspect = true;
                Place(gi.rectTransform, C, new Vector2(-348, 0), new Vector2(128, 128));
            }

            var amt = MakeText("pa" + i, row, 54, TextAnchor.MiddleLeft, FontStyle.Bold,
                new Color(0.72f, 0.95f, 1f));
            amt.text = PACK_GEMS[i].ToString("N0");
            Place(amt.rectTransform, C, new Vector2(-70, 38), new Vector2(360, 68));

            var sub = MakeText("ps" + i, row, 32, TextAnchor.MiddleLeft, FontStyle.Normal,
                new Color(0.78f, 0.82f, 0.95f));
            sub.text = PACK_SUB[i];
            Place(sub.rectTransform, C, new Vector2(-70, -40), new Vector2(360, 54));

            if (PACK_TAG[i].Length > 0)
            {
                var tag = MakeSprite("pt" + i, row, new Color(1f, 0.62f, 0.20f, 0.95f));
                Place(tag.rectTransform, C, new Vector2(178, 54), new Vector2(184, 46));
                var tt = MakeText("ptt" + i, tag.rectTransform, 28, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
                tt.text = PACK_TAG[i];
                Place(tt.rectTransform, C, Vector2.zero, new Vector2(184, 46));
            }

            _packBuy[i] = MakeButton(row, PACK_PRICE[i], new Vector2(352, 0), new Vector2(172, 112),
                new Color(0.95f, 0.60f, 0.18f), 44);
        }

        _shopStatus = MakeText("sStat", card, 38, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.7f, 0.4f));
        _shopStatus.text = "";
        Place(_shopStatus.rectTransform, C, new Vector2(0, -608), new Vector2(880, 66));

        _shopClose = MakeButton(card, "CLOSE", new Vector2(0, -742), new Vector2(520, 140),
            new Color(0.45f, 0.47f, 0.55f), 58);
        _shop.SetActive(false);
    }

    void BuildTokoButton()
    {
        _tokoBtn = MakeButton(_modal.transform, "SHOP", new Vector2(0, -975), new Vector2(360, 150),
            new Color(1f, 0.72f, 0.25f), 64);
        _tokoBtn.gameObject.SetActive(false);
    }

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
        t.verticalOverflow =