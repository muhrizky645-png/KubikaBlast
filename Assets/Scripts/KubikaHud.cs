using System.Reflection;
using UnityEngine;
using UnityEngine.UI;
using KubikaBlast;

/// <summary>
/// HUD juicy gaya Block Blast untuk Kubika Blast (ADD-ON, tanpa edit BlastUI).
///
/// >>> TANPA EDIT KODE GAME & TANPA SETTING UNITY <<<
/// Taruh file ini di folder "Assets", tekan Play.
///
/// - Menyembunyikan Score/Level/Combo/"Baris hancur" bawaan BlastUI.
/// - SCORE: angka saja + count-up per-digit + punch SEKALI tiap skor berubah
///   (tidak lagi berkedut saat combo). Diturunkan ke posisi teks "Baris hancur".
/// - LEVEL: punch saat naik.
/// - COMBO: kotak sendiri = teks "COMBO xN" (pop) + BAR KUNING timer yang menyusut
///   selama comboWindow. Selama clear berikutnya dalam comboWindow detik, streak
///   terus naik (Good -> Awesome -> ...). Pujian muncul pop-up di tengah.
/// </summary>
public class KubikaHud : MonoBehaviour
{
    public static KubikaHud Instance { get; private set; }

    [Tooltip("Berapa detik jeda maksimum antar-clear agar combo/pujian terus naik.")]
    [Range(1f, 30f)] public float comboWindow = 10f;

    BlastGame _game;
    BlastCore _lastCore;
    bool _ready;

    Text _score, _level, _praise, _comboText;
    RectTransform _scoreRT, _levelRT, _praiseRT, _comboBox, _comboFill;
    Vector2 _praiseBase;
    float _comboBarWidth = 560f;

    float _scoreDisplay, _scorePulse, _comboPop, _levelPulse, _praiseT;
    int _lastLines, _shownCombo = -1, _shownLevel = -1, _lastScoreTarget;
    bool _praiseActive;

    int _streak;
    float _lastClearTime = -999f;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void AutoBootstrap()
    {
        if (Instance != null) return;
        var go = new GameObject("KubikaHud (auto)");
        go.AddComponent<KubikaHud>();
    }

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
    }

    void Update()
    {
        if (_ready && (_score == null || _level == null)) _ready = false;
        if (!_ready) { TrySetup(); if (!_ready) return; }

        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_game == null) return;
        var core = _game.Core;
        if (core == null) return;

        if (!ReferenceEquals(core, _lastCore))
        {
            _lastCore = core;
            _scoreDisplay = core.Score;
            _lastScoreTarget = core.Score;
            _lastLines = core.LinesCleared;
            _shownCombo = -1;
            _shownLevel = core.Level;
            _streak = 0;
            _lastClearTime = -999f;
            _praiseActive = false;
            SetAlpha(_praise, 0f);
            if (_comboBox != null) _comboBox.gameObject.SetActive(false);
        }

        AnimateScore(core);
        AnimateLevel(core);
        DetectClear(core);
        AnimateCombo();
        AnimatePraise();
    }

    void AnimateScore(BlastCore core)
    {
        int target = core.Score;

        // Punch HANYA sekali saat skor benar-benar berubah (bukan tiap frame),
        // supaya tidak berkedut selama count-up combo.
        if (target != _lastScoreTarget)
        {
            if (target > _lastScoreTarget) _scorePulse = 1f;
            _lastScoreTarget = target;
        }

        if (target < Mathf.RoundToInt(_scoreDisplay)) _scoreDisplay = target;
        if (_scoreDisplay < target)
        {
            float diff = target - _scoreDisplay;
            float step = Mathf.Max(diff * Time.deltaTime * 6f, 60f * Time.deltaTime);
            _scoreDisplay = Mathf.Min(target, _scoreDisplay + step);
        }
        _score.text = Mathf.RoundToInt(_scoreDisplay).ToString();

        // Skor dibuat STABIL: tanpa punch skala sama sekali, supaya angka tidak
        // bergetar/berkedut saat skor naik beruntun selama combo. Count-up tetap
        // jalan (angka bergulir naik halus), hanya efek skala yang dihilangkan.
        _scorePulse = 0f;
        _scoreRT.localScale = Vector3.one;
    }

    void AnimateLevel(BlastCore core)
    {
        if (core.Level != _shownLevel)
        {
            if (_shownLevel > 0 && core.Level > _shownLevel) _levelPulse = 1f;
            _shownLevel = core.Level;
        }
        _level.text = "LEVEL " + core.Level;
        _levelPulse = Mathf.MoveTowards(_levelPulse, 0f, Time.deltaTime * 3f);
        _levelRT.localScale = Vector3.one * (1f + 0.22f * _levelPulse);
    }

    void DetectClear(BlastCore core)
    {
        if (core.LinesCleared > _lastLines)
        {
            if (Time.time - _lastClearTime <= comboWindow) _streak++;
            else _streak = 1;
            _lastClearTime = Time.time;
            ShowPraise(_streak);
        }
        _lastLines = core.LinesCleared;
    }

    void AnimateCombo()
    {
        if (_comboBox == null) return;

        if (_streak > 0 && Time.time - _lastClearTime > comboWindow) _streak = 0;

        bool show = _streak >= 2;
        if (_comboBox.gameObject.activeSelf != show) _comboBox.gameObject.SetActive(show);
        if (!show) { _shownCombo = _streak; return; }

        if (_streak != _shownCombo)
        {
            _comboText.text = "COMBO x" + _streak;
            _comboPop = 1f;
            _shownCombo = _streak;
        }

        // Bar kuning timer: menyusut dari penuh -> kosong selama comboWindow.
        float remain = Mathf.Clamp01(1f - (Time.time - _lastClearTime) / Mathf.Max(0.01f, comboWindow));
        var sd = _comboFill.sizeDelta;
        sd.x = _comboBarWidth * remain;
        _comboFill.sizeDelta = sd;

        _comboPop = Mathf.MoveTowards(_comboPop, 0f, Time.deltaTime * 3f);
        float s = 1f + 0.5f * _comboPop;
        _comboBox.localScale = new Vector3(s, s, 1f);
    }

    void ShowPraise(int tier)
    {
        _praise.text = PraiseFor(tier);
        _praise.color = PraiseColor(tier);
        if (KubikaSfx.Instance != null) KubikaSfx.Instance.PlayPraise(tier); // suara = tier SAMA dgn teks -> selalu sinkron
        _praiseActive = true;
        _praiseT = 0f;
        _praiseRT.anchoredPosition = _praiseBase;
        _praiseRT.localScale = Vector3.one * 0.4f;
    }

    void AnimatePraise()
    {
        if (!_praiseActive) return;
        _praiseT += Time.deltaTime;
        const float dur = 0.95f;
        float k = _praiseT / dur;
        if (k >= 1f) { _praiseActive = false; SetAlpha(_praise, 0f); _praiseRT.localScale = Vector3.one; return; }

        float s = k < 0.16f ? Mathf.Lerp(0.4f, 1.18f, k / 0.16f)
                : k < 0.28f ? Mathf.Lerp(1.18f, 1f, (k - 0.16f) / 0.12f)
                : 1f;
        _praiseRT.localScale = Vector3.one * s;
        float a = k < 0.62f ? 1f : Mathf.Lerp(1f, 0f, (k - 0.62f) / 0.38f);
        SetAlpha(_praise, a);
        _praiseRT.anchoredPosition = _praiseBase + new Vector2(0f, Mathf.Lerp(0f, 70f, k));
    }

    string PraiseFor(int tier)
    {
        switch (Mathf.Clamp(tier, 1, 99))
        {
            case 1: return "GOOD!";
            case 2: return "AWESOME!!";
            case 3: return "AMAZING!!";
            case 4: return "FANTASTIC!!";
            case 5: return "INCREDIBLE!!";
            case 6: return "UNSTOPPABLE!!";
            default: return "LEGENDARY!!";
        }
    }

    Color PraiseColor(int tier)
    {
        switch (Mathf.Clamp(tier, 1, 99))
        {
            case 1: return new Color(0.55f, 0.95f, 0.55f);
            case 2: return new Color(0.35f, 0.80f, 1.00f);
            case 3: return new Color(1.00f, 0.85f, 0.30f);
            case 4: return new Color(1.00f, 0.60f, 0.25f);
            case 5: return new Color(1.00f, 0.45f, 0.55f);
            case 6: return new Color(0.80f, 0.50f, 1.00f);
            default: return new Color(1.00f, 0.90f, 0.40f);
        }
    }

    void TrySetup()
    {
        var ui = FindFirstObjectByType<BlastUI>();
        if (ui == null) return;
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();

        Text srcScore = FindText(ui, "_scoreText", "Score", "Skor");
        Text srcLevel = FindText(ui, "_levelText", "Level", "LEVEL");
        Text srcCombo = FindText(ui, "_comboText", "Combo", "COMBO");
        Text srcLines = FindText(ui, "_linesText", "Lines", "Baris");
        if (srcScore == null || srcLevel == null) return;

        Transform parent = srcScore.transform.parent;

        _score = Clone(srcScore, Color.white);
        _scoreRT = _score.rectTransform;
        _score.fontSize = Mathf.RoundToInt(srcScore.fontSize * 1.05f);

        if (srcLines != null)
        {
            var lrt = srcLines.rectTransform;
            _scoreRT.anchorMin = lrt.anchorMin;
            _scoreRT.anchorMax = lrt.anchorMax;
            _scoreRT.pivot = lrt.pivot;
            _scoreRT.anchoredPosition = lrt.anchoredPosition;
            srcLines.enabled = false;
        }

        _level = Clone(srcLevel, srcLevel.color);
        _levelRT = _level.rectTransform;

        if (srcCombo != null) srcCombo.enabled = false;

        BuildComboBox(parent, srcScore.font);

        _praise = MakePraise(srcScore.font, parent);
        _praiseRT = _praise.rectTransform;
        _praiseBase = _praiseRT.anchoredPosition;

        srcScore.enabled = false;
        srcLevel.enabled = false;

        _ready = true;
    }

    void BuildComboBox(Transform parent, Font font)
    {
        var boxGO = new GameObject("Hud_ComboBox", typeof(RectTransform));
        boxGO.transform.SetParent(parent, false);
        _comboBox = boxGO.GetComponent<RectTransform>();
        _comboBox.anchorMin = _comboBox.anchorMax = new Vector2(0.5f, 1f);
        _comboBox.pivot = new Vector2(0.5f, 1f);
        _comboBox.sizeDelta = new Vector2(720f, 150f);
        _comboBox.anchoredPosition = new Vector2(0f, -360f);

        // Teks COMBO xN
        var tGO = new GameObject("Txt", typeof(RectTransform));
        tGO.transform.SetParent(_comboBox, false);
        _comboText = tGO.AddComponent<Text>();
        _comboText.font = font;
        _comboText.fontStyle = FontStyle.Bold;
        _comboText.fontSize = 72;
        _comboText.alignment = TextAnchor.UpperCenter;
        _comboText.horizontalOverflow = HorizontalWrapMode.Overflow;
        _comboText.verticalOverflow = VerticalWrapMode.Overflow;
        _comboText.raycastTarget = false;
        _comboText.color = new Color(1f, 0.85f, 0.25f);
        var trt = _comboText.rectTransform;
        trt.anchorMin = trt.anchorMax = new Vector2(0.5f, 1f);
        trt.pivot = new Vector2(0.5f, 1f);
        trt.sizeDelta = new Vector2(720f, 90f);
        trt.anchoredPosition = Vector2.zero;
        AddFx(tGO);

        // Latar bar
        var bgGO = new GameObject("Bar", typeof(RectTransform));
        bgGO.transform.SetParent(_comboBox, false);
        var bg = bgGO.AddComponent<Image>();
        bg.color = new Color(0f, 0f, 0f, 0.4f);
        bg.raycastTarget = false;
        var brt = bg.rectTransform;
        brt.anchorMin = brt.anchorMax = new Vector2(0.5f, 1f);
        brt.pivot = new Vector2(0.5f, 1f);
        brt.sizeDelta = new Vector2(_comboBarWidth, 26f);
        brt.anchoredPosition = new Vector2(0f, -98f);

        // Isi bar (kuning), nempel kiri, menyusut dari kanan
        var fGO = new GameObject("Fill", typeof(RectTransform));
        fGO.transform.SetParent(bgGO.transform, false);
        var fill = fGO.AddComponent<Image>();
        fill.color = new Color(1f, 0.82f, 0.15f, 1f);
        fill.raycastTarget = false;
        _comboFill = fill.rectTransform;
        _comboFill.anchorMin = new Vector2(0f, 0f);
        _comboFill.anchorMax = new Vector2(0f, 1f);
        _comboFill.pivot = new Vector2(0f, 0.5f);
        _comboFill.anchoredPosition = Vector2.zero;
        _comboFill.sizeDelta = new Vector2(_comboBarWidth, 0f);

        _comboBox.gameObject.SetActive(false);
    }

    Text Clone(Text src, Color col)
    {
        var go = new GameObject("Hud_" + src.gameObject.name, typeof(RectTransform), typeof(Text));
        go.transform.SetParent(src.transform.parent, false);

        var rt = go.GetComponent<RectTransform>();
        var srt = src.rectTransform;
        rt.anchorMin = srt.anchorMin;
        rt.anchorMax = srt.anchorMax;
        rt.pivot = srt.pivot;
        rt.sizeDelta = srt.sizeDelta;
        rt.anchoredPosition = srt.anchoredPosition;
        rt.localScale = Vector3.one;

        var t = go.GetComponent<Text>();
        t.font = src.font;
        t.fontStyle = src.fontStyle;
        t.fontSize = src.fontSize;
        t.alignment = src.alignment;
        t.horizontalOverflow = HorizontalWrapMode.Overflow;
        t.verticalOverflow = VerticalWrapMode.Overflow;
        t.raycastTarget = false;
        t.color = col;

        AddFx(go);
        go.transform.SetAsLastSibling();
        return t;
    }

    Text MakePraise(Font font, Transform parent)
    {
        var go = new GameObject("Hud_Praise", typeof(RectTransform), typeof(Text));
        go.transform.SetParent(parent, false);

        var rt = go.GetComponent<RectTransform>();
        rt.anchorMin = rt.anchorMax = new Vector2(0.5f, 0.5f);
        rt.pivot = new Vector2(0.5f, 0.5f);
        rt.sizeDelta = new Vector2(1400f, 300f);
        rt.anchoredPosition = new Vector2(0f, 320f);

        var t = go.GetComponent<Text>();
        t.font = font;
        t.fontStyle = FontStyle.Bold;
        t.fontSize = 150;
        t.alignment = TextAnchor.MiddleCenter;
        t.horizontalOverflow = HorizontalWrapMode.Overflow;
        t.verticalOverflow = VerticalWrapMode.Overflow;
        t.raycastTarget = false;
        t.text = "";

        AddFx(go);
        SetAlpha(t, 0f);
        go.transform.SetAsLastSibling();
        return t;
    }

    static void AddFx(GameObject go)
    {
        var ol = go.AddComponent<Outline>();
        ol.effectColor = new Color(0f, 0f, 0f, 0.7f);
        ol.effectDistance = new Vector2(3f, -3f);
        var sh = go.AddComponent<Shadow>();
        sh.effectColor = new Color(0f, 0f, 0f, 0.5f);
        sh.effectDistance = new Vector2(2f, -2f);
    }

    Text FindText(BlastUI ui, string field, string goName, string prefix)
    {
        var f = typeof(BlastUI).GetField(field, BindingFlags.NonPublic | BindingFlags.Public | BindingFlags.Instance);
        if (f != null && f.GetValue(ui) is Text tf && tf != null) return tf;

        var all = ui.GetComponentsInChildren<Text>(true);
        foreach (var t in all)
            if (t.gameObject.name == goName) return t;
        foreach (var t in all)
            if (!string.IsNullOrEmpty(t.text) && t.text.StartsWith(prefix)) return t;
        return null;
    }

    static void SetAlpha(Text t, float a)
    {
        if (t == null) return;
        var c = t.color; c.a = a; t.color = c;
    }
}
