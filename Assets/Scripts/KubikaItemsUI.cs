// BAGIAN 2 dari 3 (pembangun UI). Logika ada di KubikaItems.cs, efek di KubikaItemsFx.cs.

using UnityEngine;
using UnityEngine.UI;

public partial class KubikaItems
{
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

    void BuildFxOverlay()
    {
        _flash = MakeImage("Flash", _fxCanvas.transform, new Color(1f, 1f, 1f, 0f));
        var rt = _flash.rectTransform;
        rt.anchorMin = Vector2.zero; rt.anchorMax = Vector2.one;
        rt.offsetMin = Vector2.zero; rt.offsetMax = Vector2.zero;
        _flash.raycastTarget = false;
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
                // Fallback: kalau ikon belum ada, tampilkan nama supaya tombol tak kosong.
                var lbl = MakeText("lbl" + i, rt, 44, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
                lbl.text = NAME[i];
                Place(lbl.rectTransform, C, new Vector2(0, 10), new Vector2(210, 90));
            }

            var badge = MakeSprite("badge" + i, rt, new Color(0f, 0f, 0f, 0.55f));
            Place(badge.rectTransform, new Vector2(1f, 1f), new Vector2(-6, -6), new Vector2(84, 60));
            var cnt = MakeText("cnt" + i, badge.rectTransform, 40, TextAnchor.MiddleCenter, FontStyle.Bold,
                new Color(1f, 0.9f, 0.4f));
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

        _gemLabel = MakeText("gem", _play.transform, 46, TextAnchor.MiddleLeft, FontStyle.Bold,
            new Color(0.72f, 0.95f, 1f));
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
        var card = MakeCard(_confirm.transform, new Vector2(0, 40), new Vector2(820, 700),
            new Color(0.12f, 0.13f, 0.24f, 0.97f));
        _confirmText = MakeText("cTxt", card, 52, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        Place(_confirmText.rectTransform, C, new Vector2(0, 190), new Vector2(760, 240));
        _btnYes = MakeButton(card, "WATCH AD", new Vector2(0, -30), new Vector2(560, 150),
            new Color(0.30f, 0.75f, 0.40f), 60);
        _btnNo = MakeButton(card, "NO THANKS", new Vector2(0, -210), new Vector2(560, 130),
            new Color(0.5f, 0.5f, 0.58f), 54);
        _confirm.SetActive(false);
    }

    void BuildAd()
    {
        _adPanel = MakeFullPanel(_modal.transform, "Ad", new Color(0f, 0f, 0f, 0.9f));
        var card = MakeCard(_adPanel.transform, new Vector2(0, 60), new Vector2(860, 520),
            new Color(0.08f, 0.09f, 0.16f, 0.98f));
        MakeDecoRow(card, new Vector2(0, 150));
        _adText = MakeText("adTxt", card, 58, TextAnchor.MiddleCenter, FontStyle.Bold, Color.white);
        Place(_adText.rectTransform, C, new Vector2(0, -20), new Vector2(800, 300));
        _adPanel.SetActive(false);
    }

    void BuildPay()
    {
        _pay = MakeFullPanel(_modal.transform, "Pay", new Color(0f, 0f, 0f, 0.92f));
        var card = MakeCard(_pay.transform, new Vector2(0, 60), new Vector2(860, 520),
            new Color(0.08f, 0.09f, 0.16f, 0.98f));
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

        // ---- header: mahkota + judul di kiri, counter permata di POJOK KANAN ATAS ----
        if (_spCrown != null)
        {
            var cr = MakeImage("shopCrown", card, Color.white);
            cr.sprite = _spCrown;
            cr.preserveAspect = true;
            Place(cr.rectTransform, C, new Vector2(-395, 892), new Vector2(86, 86));
        }

        var title = MakeText("sTitle", card, 74, TextAnchor.MiddleLeft, FontStyle.Bold,
            new Color(1f, 0.85f, 0.3f));
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

        // ---- bagian 1: kartu item, urutan Bom -> Palu -> Undo ----
        var sec1 = MakeText("sec1", card, 40, TextAnchor.MiddleLeft, FontStyle.Bold,
            new Color(0.62f, 0.68f, 0.82f));
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

        // ---- bagian 2: paket permata (SIMULASI bayar) ----
        var div = MakeImage("div", card, new Color(1f, 1f, 1f, 0.12f));
        Place(div.rectTransform, C, new Vector2(0, 140), new Vector2(880, 3));

        var sec2 = MakeText("sec2", card, 46, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.85f, 0.35f));
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
                var tt = MakeText("ptt" + i, tag.rectTransform, 28, TextAnchor.MiddleCenter,
                    FontStyle.Bold, Color.white);
                tt.text = PACK_TAG[i];
                Place(tt.rectTransform, C, Vector2.zero, new Vector2(184, 46));
            }

            _packBuy[i] = MakeButton(row, PACK_PRICE[i], new Vector2(352, 0), new Vector2(172, 112),
                new Color(0.95f, 0.60f, 0.18f), 44);
        }

        _shopStatus = MakeText("sStat", card, 38, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.7f, 0.4f));
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

    void Shake(float amount) { if (_game != null) _game.Shake(amount); }
    void HitStop(float seconds, float scale) { if (_game != null) _game.HitStop(seconds, scale); }
}
