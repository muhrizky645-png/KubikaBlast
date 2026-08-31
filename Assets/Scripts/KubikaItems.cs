// Dukung DUA backend input Unity (Input Manager lama & Input System baru).
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
/// SISTEM ITEM / POWER-UP + PERMATA untuk Kubika Blast (ADD-ON, tanpa edit kode game).
///
/// >>> TANPA SETTING UNITY <<< Taruh file ini di folder "Assets", tekan Play.
///
/// Item:
///   - PALU  : hancurkan 1 block yang di-tap.
///   - BOM   : hancurkan area 3x3 di sekitar block yang di-tap.
///   - UNDO  : batalkan langkah (penempatan) terakhir.
/// Cara dapat: BUBBLE item jatuh acak saat main -> di-tap -> konfirmasi nonton
/// iklan (simulasi) -> item MASUK KOLEKSI (tidak langsung terpakai).
/// Permata: didapat dari hadiah COMBO; dipakai belanja item di TOKO (dibuka dari
/// menu Home & menu Jeda). Harga: Bom 600, Undo 400, Palu 200.
///
/// Semua tap dideteksi manual (tanpa EventSystem). Skrip ini berjalan pada
/// execution order default (0), jadi LEBIH DULU dari BlastInput (order 1000) =>
/// bisa mengambil snapshot papan SEBELUM langkah pemain untuk fitur UNDO.
/// </summary>
public class KubikaItems : MonoBehaviour
{
    public static KubikaItems Instance { get; private set; }

    enum Item { Hammer = 0, Bomb = 1, Undo = 2 }
    enum Mode { None, Hammer, Bomb }
    Mode _mode = Mode.None;

    // ---- PlayerPrefs keys ----
    const string GEM_KEY = "kubika_gems";
    static readonly string[] ITEM_KEY = { "kubika_item_hammer", "kubika_item_bomb", "kubika_item_undo" };
    static readonly int[] PRICE = { 200, 600, 400 };            // Palu, Bom, Undo
    static readonly string[] NAME = { "PALU", "BOM", "UNDO" };
    static readonly Color[] ICOL =
    {
        new Color(1.00f, 0.72f, 0.30f), // Palu - oranye
        new Color(1.00f, 0.36f, 0.48f), // Bom  - merah muda
        new Color(0.31f, 0.76f, 0.97f), // Undo - biru
    };

    BlastGame _game;
    BlastInput _input;
    BlastCore _core;
    Camera _cam;
    bool _built;

    Canvas _play, _modal;
    Font _font;
    Sprite _round;

    // Item bar (di atas tray)
    GameObject _itemBar;
    RectTransform[] _itemBtn = new RectTransform[3];
    Text[] _itemCount = new Text[3];
    Text _gemLabel;

    // Targeting hint (Palu/Bom)
    GameObject _hint;
    Text _hintText;
    RectTransform _btnCancel;

    // Bubble
    GameObject _bubble;
    RectTransform _bubbleRT;
    Item _bubbleItem;
    float _nextBubble;

    // Konfirmasi iklan
    GameObject _confirm;
    Text _confirmText;
    RectTransform _btnYes, _btnNo;
    Item _pending;

    // Iklan (simulasi)
    GameObject _adPanel;
    Text _adText;
    float _adTimer;
    int _adPhase;   // 0 = tayang iklan, 1 = tampil hadiah
    Item _adItem;

    // Toko
    GameObject _shop;
    Text _shopGems, _shopStatus;
    Text[] _shopOwned = new Text[3];
    RectTransform[] _shopBuy = new RectTransform[3];
    RectTransform _shopClose;
    RectTransform _tokoBtn;   // tombol mengapung di menu Home/Jeda

    // Reward combo
    int _lastLines = -1;

    // ---- Snapshot untuk UNDO ----
    int[,] _snapGrid, _undoGrid;
    int _snapScore, _snapCombo, _snapLines, _undoScore, _undoCombo, _undoLines;
    bool _snapGO, _undoGO;
    BlastCore.Piece[] _snapTray, _undoTray;
    bool _hasSnap, _hasUndo, _selfModified;

    static readonly Vector2 C = new Vector2(0.5f, 0.5f);

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

    void Update()
    {
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_input == null) _input = FindFirstObjectByType<BlastInput>();
        if (_cam == null) _cam = Camera.main;
        if (_game == null) return;
        _core = _game.Core;
        if (_core == null) return;

        if (!_built) BuildUI();

        // ---- UNDO: deteksi langkah pemain & jaga snapshot (jalan sebelum BlastInput) ----
        HandleUndoSnapshot();
        // ---- Hadiah permata dari combo ----
        HandleComboReward();

        // ---- Visibilitas ----
        bool playing = Time.timeScale > 0f && !_core.GameOver;
        bool anyModal = _confirm.activeSelf || _adPanel.activeSelf || _shop.activeSelf;
        _itemBar.SetActive(playing && _mode == Mode.None && !anyModal);
        _hint.SetActive(playing && _mode != Mode.None && !anyModal);
        UpdateItemCounts();

        // Tombol TOKO hanya muncul di menu Home / Jeda.
        string menu = KubikaMenu.CurrentScreenName;
        bool showToko = !anyModal && (menu == "Home" || menu == "Paused");
        _tokoBtn.gameObject.SetActive(showToko);

        // ---- Bubble ----
        HandleBubble(playing && _mode == Mode.None && !anyModal);

        // ---- Iklan (timer) ----
        if (_adPanel.activeSelf) HandleAdTimer();

        // ---- Input ----
        HandleTaps();

        _selfModified = false;
    }

    // ============================================================
    //  UNDO SNAPSHOT
    // ============================================================
    void HandleUndoSnapshot()
    {
        // Rebuild / restart -> reset baseline.
        if (!_hasSnap || _core.LinesCleared < _snapLines || (_snapGrid != null &&
            (_snapGrid.GetLength(0) != _core.Columns || _snapGrid.GetLength(1) != _core.Height)))
        {
            TakeSnapshot();
            _hasUndo = false;
            _lastLines = _core.LinesCleared;
            return;
        }

        // Langkah pemain terdeteksi (skor berubah / grid berubah) & bukan aksi item kita.
        if (!_selfModified && (_core.Score != _snapScore || !GridEquals(_core.Grid, _snapGrid)))
        {
            // snapshot sebelumnya = kondisi SEBELUM langkah -> jadi titik undo.
            _undoGrid = CloneGrid(_snapGrid);
            _undoScore = _snapScore; _undoCombo = _snapCombo; _undoLines = _snapLines; _undoGO = _snapGO;
            _undoTray = DeepCopyTray(_snapTray);
            _hasUndo = true;
        }

        TakeSnapshot(); // baseline = kondisi saat ini (akhir frame ini)
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
        // Kembalikan grid.
        for (int c = 0; c < _core.Columns; c++)
            for (int r = 0; r < _core.Height; r++)
                _core.Grid[c, r] = _undoGrid[c, r];
        _core.Score = _undoScore; _core.Combo = _undoCombo; _core.LinesCleared = _undoLines; _core.GameOver = _undoGO;
        // Kembalikan tray.
        var t = DeepCopyTray(_undoTray);
        for (int i = 0; i < _core.Tray.Length && i < t.Length; i++) _core.Tray[i] = t[i];

        _game.RenderGrid();
        if (_input != null) _input.ResetSelection();

        AddItem(Item.Undo, -1);
        _hasUndo = false;
        _selfModified = true;
        TakeSnapshot();
        _lastLines = _core.LinesCleared;
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
    //  HADIAH PERMATA DARI COMBO
    // ============================================================
    void HandleComboReward()
    {
        if (_lastLines < 0) { _lastLines = _core.LinesCleared; return; }
        if (_core.LinesCleared < _lastLines) { _lastLines = _core.LinesCleared; return; } // reset
        if (_core.LinesCleared > _lastLines)
        {
            // Ada clear. Hadiah = nilai combo (min 1). Combo besar -> permata lebih banyak.
            int gain = Mathf.Max(1, _core.Combo);
            AddGems(gain);
        }
        _lastLines = _core.LinesCleared;
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

        // Spawn acak bila belum ada bubble aktif.
        if ((_bubble == null || !_bubble.activeSelf) && Time.unscaledTime >= _nextBubble)
        {
            SpawnBubble();
        }

        // Jatuhkan.
        if (_bubble != null && _bubble.activeSelf)
        {
            var p = _bubbleRT.anchoredPosition;
            p.y -= 300f * Time.deltaTime; // px/detik
            _bubbleRT.anchoredPosition = p;
            _bubbleRT.Rotate(0f, 0f, 40f * Time.deltaTime);
            if (p.y < -1300f) { _bubble.SetActive(false); ScheduleNextBubble(); }
        }
    }

    void ScheduleNextBubble() { _nextBubble = Time.unscaledTime + Random.Range(9f, 17f); }

    void SpawnBubble()
    {
        _bubbleItem = (Item)Random.Range(0, 3);
        _bubbleRT.anchoredPosition = new Vector2(Random.Range(-380f, 380f), 1250f);
        _bubbleRT.localRotation = Quaternion.identity;
        var img = _bubble.GetComponent<Image>();
        img.color = ICOL[(int)_bubbleItem];
        _bubbleLabel.text = NAME[(int)_bubbleItem];
        _bubble.SetActive(true);
    }
    Text _bubbleLabel;

    // ============================================================
    //  IKLAN (SIMULASI)
    // ============================================================
    void OpenConfirm(Item it)
    {
        _pending = it;
        _confirmText.text = "Nonton iklan untuk dapat\n\"" + NAME[(int)it] + "\"?";
        _confirm.SetActive(true);
    }

    void StartAd()
    {
        _confirm.SetActive(false);
        _adItem = _pending;
        _adPhase = 0;
        _adTimer = 2.5f;
        _adText.text = "Menampilkan iklan...\n(simulasi)";
        _adPanel.SetActive(true);
    }

    void HandleAdTimer()
    {
        _adTimer -= Time.unscaledDeltaTime;
        if (_adTimer > 0f)
        {
            if (_adPhase == 0)
            {
                int s = Mathf.CeilToInt(_adTimer);
                _adText.text = "Menampilkan iklan...\n(simulasi)  " + s;
            }
            return;
        }
        if (_adPhase == 0)
        {
            AddItem(_adItem, +1);
            _adPhase = 1;
            _adTimer = 1.3f;
            _adText.text = "+1 " + NAME[(int)_adItem] + "\nmasuk koleksi!";
        }
        else
        {
            _adPanel.SetActive(false);
        }
    }

    // ============================================================
    //  PAKAI ITEM (Palu / Bom / Undo)
    // ============================================================
    void OnItemButton(Item it)
    {
        if (GetItem(it) <= 0) { OpenShop(); return; } // habis -> arahkan ke toko
        switch (it)
        {
            case Item.Undo:
                if (_hasUndo) DoUndo();
                else FlashHint("Belum ada langkah untuk di-undo");
                break;
            case Item.Hammer: EnterTargeting(Mode.Hammer); break;
            case Item.Bomb: EnterTargeting(Mode.Bomb); break;
        }
    }

    void EnterTargeting(Mode m)
    {
        _mode = m;
        _hintText.text = (m == Mode.Hammer)
            ? "PALU: tap 1 block untuk dihancurkan"
            : "BOM: tap block, area 3x3 hancur";
    }

    void CancelTarget() { _mode = Mode.None; }

    void TryTargetTap(Vector2 sp)
    {
        if (_cam == null) _cam = Camera.main;
        if (_cam == null) return;
        if (!RaycastCell(sp, out int c, out int r)) return; // meleset -> tetap di mode

        if (_mode == Mode.Hammer)
        {
            _core.Grid[c, r] = -1;
            AddItem(Item.Hammer, -1);
        }
        else if (_mode == Mode.Bomb)
        {
            for (int dc = -1; dc <= 1; dc++)
                for (int dr = -1; dr <= 1; dr++)
                {
                    int cc = _core.Wrap(c + dc);
                    int rr = r + dr;
                    if (rr >= 0 && rr < _core.Height) _core.Grid[cc, rr] = -1;
                }
            AddItem(Item.Bomb, -1);
        }

        _game.RenderGrid();
        _selfModified = true;
        _hasUndo = false;        // aksi item tidak bisa di-undo
        TakeSnapshot();
        _mode = Mode.None;
    }

    // Pasang collider sementara ke tiap block, raycast, lalu ambil (c,r) dari nama.
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
    void OpenShopInternal()
    {
        _shopStatus.text = "";
        RefreshShop();
        _shop.SetActive(true);
    }
    void CloseShop() { _shop.SetActive(false); }

    void Buy(Item it)
    {
        int price = PRICE[(int)it];
        if (GetGems() < price) { _shopStatus.text = "Permata kurang!"; return; }
        AddGems(-price);
        AddItem(it, +1);
        _shopStatus.text = "Beli " + NAME[(int)it] + " berhasil!";
        RefreshShop();
    }

    void RefreshShop()
    {
        _shopGems.text = "Permata: " + GetGems();
        for (int i = 0; i < 3; i++) _shopOwned[i].text = "Punya: " + GetItem((Item)i);
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
        if (_gemLabel != null) _gemLabel.text = "Permata: " + GetGems();
    }

    void FlashHint(string msg)
    {
        _shopStatus.text = msg; // dipakai ulang sbg status ringan (tidak fatal)
    }

    // ============================================================
    //  INPUT
    // ============================================================
    void HandleTaps()
    {
        bool down = PDown();
        Vector2 p = PPos();

        // Prioritas modal.
        if (_adPanel.activeSelf) return; // iklan: tunggu selesai
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

        // Tombol TOKO di menu.
        if (_tokoBtn.gameObject.activeSelf && Hit(_tokoBtn, p)) { OpenShop(); return; }

        // Mode targeting (Palu/Bom).
        if (_mode != Mode.None)
        {
            if (Hit(_btnCancel, p)) CancelTarget();
            else TryTargetTap(p);
            return;
        }

        // Saat main.
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
        _play = MakeCanvas("KubikaItemsCanvas", 150);
        _modal = MakeCanvas("KubikaItemsModal", 330);

        BuildItemBar();
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

            var lbl = MakeText("lbl" + i, rt, 46, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
            lbl.text = NAME[i];
            Place(lbl.rectTransform, C, new Vector2(0, 10), new Vector2(210, 90));

            var badge = MakeSprite("badge" + i, rt, new Color(0f, 0f, 0f, 0.55f));
            Place(badge.rectTransform, new Vector2(1f, 1f), new Vector2(-6, -6), new Vector2(84, 60));
            var cnt = MakeText("cnt" + i, badge.rectTransform, 40, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.9f, 0.4f));
            cnt.text = "x0";
            Place(cnt.rectTransform, C, Vector2.zero, new Vector2(84, 60));
            _itemCount[i] = cnt;
        }

        _gemLabel = MakeText("gem", barGO.transform, 44, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(0.55f, 0.95f, 1f));
        _gemLabel.text = "Permata: 0";
        Place(_gemLabel.rectTransform, new Vector2(0.5f, 0f), new Vector2(0, 580), new Vector2(700, 70));
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
        _hintText = MakeText("hintTxt", card.rectTransform, 46, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        Place(_hintText.rectTransform, C, new Vector2(0, 24), new Vector2(900, 70));

        _btnCancel = MakeButton(card.rectTransform, "BATAL", new Vector2(0, -44), new Vector2(300, 74),
            new Color(0.55f, 0.35f, 0.35f), 40);
        _hint.SetActive(false);
    }

    void BuildBubble()
    {
        var img = MakeSprite("Bubble", _play.transform, ICOL[0]);
        _bubble = img.gameObject;
        _bubbleRT = img.rectTransform;
        _bubbleRT.anchorMin = _bubbleRT.anchorMax = _bubbleRT.pivot = C;
        _bubbleRT.sizeDelta = new Vector2(170, 170);
        _bubbleRT.anchoredPosition = new Vector2(0, 1250);
        _bubbleLabel = MakeText("bubTxt", _bubbleRT, 40, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        _bubbleLabel.text = NAME[0];
        Place(_bubbleLabel.rectTransform, C, Vector2.zero, new Vector2(170, 170));
        _bubble.SetActive(false);
    }

    void BuildConfirm()
    {
        _confirm = MakeFullPanel(_modal.transform, "Confirm", new Color(0f, 0f, 0f, 0.6f));
        var card = MakeCard(_confirm.transform, new Vector2(0, 60), new Vector2(820, 560), new Color(0.12f, 0.13f, 0.24f, 0.97f));
        _confirmText = MakeText("cTxt", card, 52, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        Place(_confirmText.rectTransform, C, new Vector2(0, 150), new Vector2(760, 220));
        _btnYes = MakeButton(card, "YA, NONTON", new Vector2(0, -60), new Vector2(560, 150), new Color(0.30f, 0.75f, 0.40f), 60);
        _btnNo = MakeButton(card, "TIDAK", new Vector2(0, -230), new Vector2(560, 130), new Color(0.5f, 0.5f, 0.58f), 54);
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
        title.text = "TOKO PERMATA";
        Place(title.rectTransform, C, new Vector2(0, 590), new Vector2(880, 130));

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
            var price = MakeText("p" + i, row, 42, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.9f, 0.4f));
            price.text = PRICE[i] + " \ud83d\udc8e".Replace("\ud83d\udc8e", "permata");
            price.text = PRICE[i] + " permata";
            Place(price.rectTransform, C, new Vector2(70, 0), new Vector2(320, 70));
            _shopBuy[i] = MakeButton(row, "BELI", new Vector2(310, 0), new Vector2(190, 120), new Color(0.30f, 0.70f, 0.42f), 46);
        }

        _shopStatus = MakeText("sStat", card, 40, TextAnchor.MiddleCenter, FontStyle.Bold, new Color(1f, 0.7f, 0.4f));
        Place(_shopStatus.rectTransform, C, new Vector2(0, -370), new Vector2(880, 70));

        _shopClose = MakeButton(card, "TUTUP", new Vector2(0, -560), new Vector2(520, 150), new Color(0.45f, 0.47f, 0.55f), 60);
        _shop.SetActive(false);
    }

    void BuildTokoButton()
    {
        _tokoBtn = MakeButton(_modal.transform, "TOKO", new Vector2(0, -975), new Vector2(360, 150),
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

    // ---- Pointer abstraksi ----
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
