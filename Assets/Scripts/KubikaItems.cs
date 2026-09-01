// Dukung DUA backend input Unity (Input Manager lama & Input System baru).
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

// BAGIAN 1 dari 2 (logika). Bagian UI + efek ada di KubikaItemsUI.cs.
// Dipecah jadi partial class supaya tiap file tetap kecil dan aman di-push.

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
#if USE_NEW_INPUT
using UnityEngine.InputSystem;
#endif
using KubikaBlast;

public partial class KubikaItems : MonoBehaviour
{
    public static KubikaItems Instance { get; private set; }
    public static bool TargetingActive => Instance != null && Instance._mode != Mode.None;
    public static float LastBuffUseTime = -999f;

    // Enum & KEY simpanan sengaja TIDAK diubah supaya jumlah item milik pemain tidak
    // rusak. Yang berubah hanya URUTAN TAMPIL (lihat SHOP_ORDER / BAR_ORDER).
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

    // Shop (atas -> bawah): Bom, Palu, Undo.
    static readonly Item[] SHOP_ORDER = { Item.Bomb, Item.Hammer, Item.Undo };
    // Item bar (kiri -> kanan): Undo, Palu, Bom  => Bom paling kanan.
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

    // Posisi lokal sel papan -> koordinat lokal canvas HUD.
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

    // Titik tengah sebuah RectTransform dalam koordinat lokal canvas tertentu.
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
        // Hadiah diberikan, panel ditutup, lalu IKONNYA saja yang nge-pop & turun ke HUD.
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

        // BlastCells sudah memberi skor SETENGAH nilai sel biasa. Popup "+N" di bawah
        // dipakai supaya kenaikan skor itu KELIHATAN oleh pemain.
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

        // Ikon item nge-pop keluar dari kartunya, lalu turun sambil mengecil.
        Vector2 at = (_shopCard[(int)it] != null) ? CanvasPos(_shopCard[(int)it], _fxCanvas) : Vector2.zero;
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
        _shopGemAnim = GetGems();   // counter mulai dari nilai lama, lalu naik bertahap.
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

    bool Hit(RectTransform rt, Vector2 sp)
        => rt != null && rt.gameObject.activeInHierarchy
           && RectTransformUtility.RectangleContainsScreenPoint(rt, sp, null);

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
}
