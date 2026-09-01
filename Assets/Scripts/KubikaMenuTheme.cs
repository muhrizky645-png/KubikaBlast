// BAGIAN 3 dari 3 (TEMA VISUAL): background terang + layar GAME OVER.
// Logika/state  -> KubikaMenu.cs
// Pembangun UI  -> KubikaMenuUI.cs
// Dipecah jadi partial class supaya tiap file tetap kecil dan aman di-push.

using UnityEngine;
using UnityEngine.UI;
using KubikaBlast;

public partial class KubikaMenu
{
    // ===================== PALET BACKGROUND (TERANG) =====================
    // Sebelumnya background memakai navy sangat gelap (0.07, 0.08, 0.16) sehingga
    // seluruh menu terasa muram. Sekarang: langit biru cerah di atas menuju krem
    // hangat di bawah, supaya suasananya ringan dan menyenangkan.
    static readonly Color BG_TOP = new Color(0.42f, 0.74f, 0.96f);
    static readonly Color BG_BOTTOM = new Color(0.99f, 0.90f, 0.76f);

    // Kartu SENGAJA tetap gelap (indigo). Di atas background terang, kartu gelap
    // memberi kontras paling tinggi untuk teks putih, dan semua teks yang warnanya
    // ditentukan dari logika (mis. Color.white) tetap terbaca tanpa perlu diubah.
    static readonly Color CARD_DEEP = new Color(0.16f, 0.15f, 0.33f, 0.96f);

    // Warna teks standar di dalam kartu gelap.
    static readonly Color TXT_MUTED = new Color(0.74f, 0.79f, 0.92f);
    static readonly Color TXT_LABEL = new Color(0.62f, 0.72f, 0.88f);
    static readonly Color TXT_GOLD = new Color(1f, 0.84f, 0.31f);

    // Baris statistik Game Over (label kiri, angka kanan).
    RectTransform _goStatsRoot;
    Text[] _goStatVals;

    // ===================== BACKGROUND =====================
    void BuildBackground()
    {
        var go = new GameObject("AnimatedBg", typeof(RectTransform));
        go.transform.SetParent(_canvas.transform, false);
        _bgRoot = go;
        var rt = go.GetComponent<RectTransform>();
        Stretch(rt);

        var baseImg = MakeImage("BgBase", go.transform, Color.white);
        baseImg.sprite = GradientSprite(BG_TOP, BG_BOTTOM);
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
            // Di atas background terang, alpha lama (0.28-0.5) bikin blok terlihat
            // kusam. Alpha dinaikkan supaya warnanya terbaca sebagai pastel cerah.
            var img = MakeSprite("bgb" + i, go.transform,
                PaletteA(Random.Range(0, Palette.Length), Random.Range(0.42f, 0.68f)));
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

    // ===================== GAME OVER =====================
    // Kartu dibuat lebih tinggi (1720) supaya tiap bagian punya ruang napas.
    // Urutan dari atas: deco - judul - kalimat pujian - garis - skor akhir -
    // rekor - garis - 4 baris statistik - tombol.
    void BuildGameOver()
    {
        _goPanel = MakePanel("GameOverPanel", new Color(0f, 0f, 0f, 0f));
        var root = _goPanel.transform;

        var card = MakeCard(root, new Vector2(0, 40), new Vector2(900, 1720), CARD_DEEP);
        MakeDecoRow(card, new Vector2(0, 740));

        _goTitle = MakeText("GO", card, 104, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.36f, 0.48f));
        _goTitle.text = "GAME OVER";
        Place(_goTitle.rectTransform, C, new Vector2(0, 610), new Vector2(840, 160));
        _goTitleRT = _goTitle.rectTransform;
        _cgTitle = _goTitle.gameObject.AddComponent<CanvasGroup>();

        _goMotivation = MakeText("Motivation", card, 40, TextAnchor.MiddleCenter, FontStyle.Normal, TXT_MUTED);
        _goMotivation.horizontalOverflow = HorizontalWrapMode.Wrap;
        _goMotivation.text = "";
        Place(_goMotivation.rectTransform, C, new Vector2(0, 475), new Vector2(740, 150));
        _cgMotivation = _goMotivation.gameObject.AddComponent<CanvasGroup>();

        Divider(card, 380f);

        // Label kecil + angka besar dijadikan satu grup (skor adalah anak label)
        // supaya keduanya muncul bersamaan lewat CanvasGroup yang sama.
        var scoreLabel = MakeText("ScoreLabel", card, 38, TextAnchor.MiddleCenter, FontStyle.Bold, TXT_LABEL);
        scoreLabel.text = "FINAL SCORE";
        Place(scoreLabel.rectTransform, C, new Vector2(0, 315), new Vector2(700, 64));
        _cgScore = scoreLabel.gameObject.AddComponent<CanvasGroup>();

        _goScore = MakeText("Score", scoreLabel.transform, 140, TextAnchor.MiddleCenter, FontStyle.Bold, TXT_GOLD);
        _goScore.text = "0";
        Place(_goScore.rectTransform, C, new Vector2(0, -115), new Vector2(780, 190));
        _goScoreRT = _goScore.rectTransform;

        // Warna & ukuran font baris ini di-override dari logika (NEW RECORD vs Best).
        _goRecord = MakeText("Record", card, 48, TextAnchor.MiddleCenter, FontStyle.Bold, TXT_GOLD);
        _goRecord.text = "";
        Place(_goRecord.rectTransform, C, new Vector2(0, 75), new Vector2(800, 110));
        _goRecordRT = _goRecord.rectTransform;
        _cgRecord = _goRecord.gameObject.AddComponent<CanvasGroup>();
        _goBest = _goRecord;

        Divider(card, -10f);

        var statsGO = new GameObject("Stats", typeof(RectTransform));
        statsGO.transform.SetParent(card, false);
        _goStatsRoot = statsGO.GetComponent<RectTransform>();
        Place(_goStatsRoot, C, new Vector2(0, -240), new Vector2(760, 380));
        _cgStats = statsGO.AddComponent<CanvasGroup>();

        // Tinggi baris 84 + jarak 8 => selisih 92 antar baris.
        _goStatVals = new Text[4];
        _goStatVals[0] = StatRow(statsGO.transform, 138f, "Lines cleared", new Color(0.31f, 0.76f, 0.97f));
        _goStatVals[1] = StatRow(statsGO.transform, 46f, "Gems earned", new Color(0.73f, 0.55f, 0.95f));
        _goStatVals[2] = StatRow(statsGO.transform, -46f, "Best combo", new Color(1f, 0.72f, 0.30f));
        _goStatVals[3] = StatRow(statsGO.transform, -138f, "Pieces placed", new Color(0.44f, 0.80f, 0.50f));

        var btnWrap = new GameObject("Buttons", typeof(RectTransform));
        btnWrap.transform.SetParent(card, false);
        _goButtonsRoot = btnWrap.GetComponent<RectTransform>();
        Place(_goButtonsRoot, C, new Vector2(0, -640), new Vector2(860, 420));
        _cgButtons = btnWrap.AddComponent<CanvasGroup>();

        _goRestart = MakeButton(btnWrap.transform, "PLAY AGAIN", new Vector2(0, 85), new Vector2(620, 170), BTN_GREEN, 76);
        // MAIN MENU dibuat sama dengan yang di layar PAUSED supaya konsisten.
        _goHome = MakeButton(btnWrap.transform, "MAIN MENU", new Vector2(0, -94), new Vector2(620, 140), BTN_SLATE, 56);
    }

    // Satu baris statistik: label rata KIRI, angka rata KANAN.
    // Ini menggantikan cara lama yang menyejajarkan kolom pakai spasi manual di
    // dalam satu Text (tidak pernah lurus karena font-nya proporsional).
    Text StatRow(Transform parent, float y, string label, Color valueColor)
    {
        var row = MakeSprite("Row" + label, parent, new Color(1f, 1f, 1f, 0.06f));
        Place(row.rectTransform, C, new Vector2(0f, y), new Vector2(740f, 84f));

        var lbl = MakeText("Lbl", row.transform, 40, TextAnchor.MiddleLeft, FontStyle.Normal, TXT_MUTED);
        lbl.text = label;
        Place(lbl.rectTransform, C, new Vector2(-140f, 0f), new Vector2(400f, 84f));

        var val = MakeText("Val", row.transform, 46, TextAnchor.MiddleRight, FontStyle.Bold, valueColor);
        val.text = "0";
        Place(val.rectTransform, C, new Vector2(200f, 0f), new Vector2(300f, 84f));
        return val;
    }

    void Divider(Transform parent, float y)
    {
        var d = MakeSprite("Divider", parent, new Color(1f, 1f, 1f, 0.10f));
        Place(d.rectTransform, C, new Vector2(0f, y), new Vector2(700f, 4f));
    }

    // Dipanggil dari ShowGameOver (KubikaMenu.cs) menggantikan perakitan string manual.
    void SetGameOverStats(BlastCore core)
    {
        if (_goStatVals == null || core == null) return;
        if (_goStatVals[0] != null) _goStatVals[0].text = core.LinesCleared.ToString();
        if (_goStatVals[1] != null) _goStatVals[1].text = core.GemsEarned.ToString();
        if (_goStatVals[2] != null) _goStatVals[2].text = "x" + Mathf.Max(1, core.BestCombo);
        if (_goStatVals[3] != null) _goStatVals[3].text = core.PiecesPlaced.ToString();
    }
}
