using System.Reflection;
using UnityEngine;
using UnityEngine.UI;
using KubikaBlast;

/// <summary>
/// HUD juicy gaya Block Blast untuk Kubika Blast (ADD-ON, tanpa edit BlastUI).
///
/// >>> TANPA EDIT KODE GAME & TANPA SETTING UNITY <<<
/// Taruh file ini di folder "Assets" (mis. Assets/Scripts/KubikaHud.cs), tekan Play.
///
/// Otomatis:
///  - Menyembunyikan teks Score/Level/Combo bawaan BlastUI, lalu menggambar
///    versi animasi di posisi yang sama (pakai canvas & skala yang sama).
///  - SCORE: angka saja + animasi NAIK per-digit (count-up) + punch.
///  - LEVEL: punch saat naik level.
///  - COMBO: pop-up "COMBO xN" (muncul membesar lalu mengecil).
///  - PUJIAN: teks pop-up di tengah "GOOD! / AWESOME!! / AMAZING!! ..." tiap clear,
///    tingkatnya mengikuti combo (suaranya di-handle KubikaSfx).
/// </summary>
public class KubikaHud : MonoBehaviour
{
    public static KubikaHud Instance { get; private set; }

    BlastGame _game;
    BlastCore _lastCore;
    bool _ready;

    Text _score, _level, _combo, _praise;
    RectTransform _scoreRT, _levelRT, _comboRT, _praiseRT;
    Vector2 _praiseBase, _comboBase;

    float _scoreDisplay, _scorePulse, _comboPop, _levelPulse, _praiseT;
    int _lastLines, _shownCombo = -1, _shownLevel = -1;
    bool _praiseActive;

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
        // Jika UI dibangun ulang (scene reload) referensi bisa hilang -> setup lagi.
        if (_ready && (_score == null || _level == null)) _ready = false;
        if (!_ready) { TrySetup(); if (!_ready) return; }

        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_game == null) return;
        var core = _game.Core;
        if (core == null) return;

        // Reset baseline saat game baru / restart.
        if (!ReferenceEquals(core, _lastCore))
        {
            _lastCore = core;
            _scoreDisplay = core.Score;
            _lastLines = core.LinesCleared;
            _shownCombo = core.Combo;
            _shownLevel = core.Level;
            _praiseActive = false;
            SetAlpha(_praise, 0f);
            if (_combo != null) _combo.text = "";
        }

        AnimateScore(core);
        AnimateLevel(core);
        AnimateCombo(core);
        DetectClear(core);
        AnimatePraise();
    }

    // ================= SCORE (angka saja + count-up per-digit) =================
    void AnimateScore(BlastCore core)
    {
        int target = core.Score;
        if (target < Mathf.RoundToInt(_scoreDisplay)) _scoreDisplay = target; // snap turun
        if (_scoreDisplay < target)
        {
            float diff = target - _scoreDisplay;
            float step = Mathf.Max(diff * Time.deltaTime * 7f, 40f * Time.deltaTime);
            _scoreDisplay = Mathf.Min(target, _scoreDisplay + step);
            _scorePulse = 1f;
        }
        _score.text = Mathf.RoundToInt(_scoreDisplay).ToString();
        _scorePulse = Mathf.MoveTowards(_scorePulse, 0f, Time.deltaTime * 4f);
        _scoreRT.localScale = Vector3.one * (1f + 0.14f * _scorePulse);
    }

    // ================= LEVEL (punch saat naik) =================
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

    // ================= COMBO (pop-up) =================
    void AnimateCombo(BlastCore core)
    {
        if (_combo == null) return;
        if (core.Combo >= 2 && core.Combo != _shownCombo)
        {
            _combo.text = "COMBO x" + core.Combo;
            _comboPop = 1f;
        }
        if (core.Combo < 2) _combo.text = "";
        _shownCombo = core.Combo;

        _comboPop = Mathf.MoveTowards(_comboPop, 0f, Time.deltaTime * 3f);
        _comboRT.localScale = Vector3.one * (1f + 0.6f * _comboPop);
    }

    // ================= PUJIAN (Good/Awesome/Amazing...) =================
    void DetectClear(BlastCore core)
    {
        if (core.LinesCleared > _lastLines)
            ShowPraise(core.Combo);
        _lastLines = core.LinesCleared;
    }

    void ShowPraise(int combo)
    {
        _praise.text = PraiseFor(combo);
        _praise.color = PraiseColor(combo);
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

    string PraiseFor(int combo)
    {
        switch (Mathf.Clamp(combo, 1, 99))
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

    Color PraiseColor(int combo)
    {
        switch (Mathf.Clamp(combo, 1, 99))
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

    // ================= SETUP: clone teks bawaan lalu sembunyikan aslinya =================
    void TrySetup()
    {
        var ui = FindFirstObjectByType<BlastUI>();
        if (ui == null) return;
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();

        Text srcScore = FindText(ui, "_scoreText", "Score", "Skor");
        Text srcLevel = FindText(ui, "_levelText", "Level", "LEVEL");
        Text srcCombo = FindText(ui, "_comboText", "Combo", "COMBO");
        if (srcScore == null || srcLevel == null) return; // UI belum dibangun

        Transform parent = srcScore.transform.parent;

        _score = Clone(srcScore, Color.white);
        _scoreRT = _score.rectTransform;
        _score.fontSize = Mathf.RoundToInt(srcScore.fontSize * 1.05f);

        _level = Clone(srcLevel, srcLevel.color);
        _levelRT = _level.rectTransform;

        if (srcCombo != null)
        {
            _combo = Clone(srcCombo, new Color(1f, 0.85f, 0.3f));
            _combo.fontStyle = FontStyle.Bold;
            _combo.text = "";
            _comboRT = _combo.rectTransform;
            _comboBase = _comboRT.anchoredPosition;
            srcCombo.enabled = false;
        }

        _praise = MakePraise(srcScore.font, parent);
        _praiseRT = _praise.rectTransform;
        _praiseBase = _praiseRT.anchoredPosition;

        srcScore.enabled = false;
        srcLevel.enabled = false;

        _ready = true;
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

        var ol = go.AddComponent<Outline>();
        ol.effectColor = new Color(0f, 0f, 0f, 0.65f);
        ol.effectDistance = new Vector2(3f, -3f);
        var sh = go.AddComponent<Shadow>();
        sh.effectColor = new Color(0f, 0f, 0f, 0.5f);
        sh.effectDistance = new Vector2(2f, -2f);

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

        var ol = go.AddComponent<Outline>();
        ol.effectColor = new Color(0f, 0f, 0f, 0.7f);
        ol.effectDistance = new Vector2(4f, -4f);
        var sh = go.AddComponent<Shadow>();
        sh.effectColor = new Color(0f, 0f, 0f, 0.5f);
        sh.effectDistance = new Vector2(3f, -3f);

        SetAlpha(t, 0f);
        go.transform.SetAsLastSibling();
        return t;
    }

    // Cari Text: 1) via field privat BlastUI, 2) fallback via nama GO / isi teks.
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
