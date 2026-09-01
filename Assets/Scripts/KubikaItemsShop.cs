// BAGIAN 4: khusus layar TOKO (gaya kartu marketplace 3 kolom).
// Dipisah dari KubikaItemsUI.cs supaya file itu tidak melewati batas aman push
// dan supaya penyetelan tata letak toko ke depannya murah & tidak berisiko.

using UnityEngine;
using UnityEngine.UI;

public partial class KubikaItems
{
    // Tiga kolom berjajar, dipakai DUA KALI (baris item & baris paket permata)
    // supaya kedua baris itu dijamin lurus segaris.
    // Lebar 280 x 3 = 840, ditambah 2 jarak 20 = 880 -> pas di kartu 960.
    static readonly float[] SHOP_COL_X = { -290f, 0f, 290f };

    // Ukuran kolom. Tinggi item 460 & paket 440 dihitung dari bawah ke atas:
    // tombol 96 butuh 48 (setengah) + 18 (lapis gelap MakeButton) jarak dari
    // tepi kartu, sisanya baru dibagi untuk gambar / nama / harga.
    static readonly Vector2 ICOL_SIZE = new Vector2(280, 460);
    static readonly Vector2 PCOL_SIZE = new Vector2(280, 440);

    void BuildShop()
    {
        _shop = MakeFullPanel(_modal.transform, "Shop", new Color(0f, 0f, 0f, 0.78f));
        var card = MakeCard(_shop.transform, new Vector2(0, 30), new Vector2(960, 1560),
            new Color(0.10f, 0.12f, 0.20f, 0.97f));

        // ---- header: mahkota + judul di kiri, counter permata di pojok kanan ----
        if (_spCrown != null)
        {
            var cr = MakeImage("shopCrown", card, Color.white);
            cr.sprite = _spCrown;
            cr.preserveAspect = true;
            Place(cr.rectTransform, C, new Vector2(-395, 672), new Vector2(86, 86));
        }

        var title = MakeText("sTitle", card, 74, TextAnchor.MiddleLeft, FontStyle.Bold,
            new Color(1f, 0.85f, 0.3f));
        title.text = "GEM SHOP";
        Place(title.rectTransform, C, new Vector2(-50, 670), new Vector2(560, 110));

        var pill = MakeSprite("shopGemPill", card, new Color(0f, 0f, 0f, 0.42f));
        Place(pill.rectTransform, C, new Vector2(330, 670), new Vector2(290, 96));
        _shopGemPill = pill.rectTransform;
        if (_spGem != null)
        {
            var gi = MakeImage("shopGemIcon", pill.rectTransform, Color.white);
            gi.sprite = _spGem;
            gi.preserveAspect = true;
            Place(gi.rectTransform, C, new Vector2(-100, 0), new Vector2(60, 60));
        }
        _shopGems = MakeText("sGems", pill.rectTransform, 48, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(0.72f, 0.95f, 1f));
        _shopGems.text = "0";
        Place(_shopGems.rectTransform, C, new Vector2(34, 0), new Vector2(200, 70));

        // ---- baris 1: kolom item, urutan Bom -> Palu -> Undo (termahal di kiri) ----
        var sec1 = MakeText("sec1", card, 40, TextAnchor.MiddleLeft, FontStyle.Bold,
            new Color(0.62f, 0.68f, 0.82f));
        sec1.text = "ITEMS";
        Place(sec1.rectTransform, C, new Vector2(-215, 580), new Vector2(400, 60));

        for (int slot = 0; slot < 3; slot++)
            BuildItemColumn(card, slot);

        // ---- baris 2: paket permata (SIMULASI bayar), juga 3 kolom berjajar ----
        var div = MakeImage("div", card, new Color(1f, 1f, 1f, 0.12f));
        Place(div.rectTransform, C, new Vector2(0, 40), new Vector2(880, 3));

        var sec2 = MakeText("sec2", card, 46, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.85f, 0.35f));
        sec2.text = "GET MORE GEMS";
        Place(sec2.rectTransform, C, new Vector2(0, -24), new Vector2(880, 66));

        for (int i = 0; i < 3; i++)
            BuildPackColumn(card, i);

        _shopStatus = MakeText("sStat", card, 38, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.7f, 0.4f));
        _shopStatus.text = "";
        Place(_shopStatus.rectTransform, C, new Vector2(0, -560), new Vector2(880, 66));

        _shopClose = MakeButton(card, "CLOSE", new Vector2(0, -680), new Vector2(520, 140),
            new Color(0.45f, 0.47f, 0.55f), 58);
        _shop.SetActive(false);
    }

    // Satu kolom item: gambar -> nama -> jumlah dimiliki -> harga -> tombol BUY.
    void BuildItemColumn(Transform card, int slot)
    {
        int i = (int)SHOP_ORDER[slot];
        var col = ICOL[i];

        var box = MakeCard(card, new Vector2(SHOP_COL_X[slot], 310f), ICOL_SIZE,
            new Color(col.r * 0.20f, col.g * 0.20f, col.b * 0.20f, 0.82f));
        _shopCard[i] = box;

        var thumb = MakeSprite("th" + i, box, new Color(col.r, col.g, col.b, 0.20f));
        Place(thumb.rectTransform, C, new Vector2(0, 142), new Vector2(148, 148));

        var ic = IconOf((Item)i);
        if (ic != null)
        {
            var ri = MakeImage("ri" + i, thumb.rectTransform, Color.white);
            ri.sprite = ic;
            ri.preserveAspect = true;
            Place(ri.rectTransform, C, Vector2.zero, new Vector2(112, 112));
        }

        // Nama dicerahkan ke arah putih: warna asli item terlalu redup di atas
        // latar kolomnya sendiri yang memakai warna yang sama.
        var nm = MakeText("n" + i, box, 40, TextAnchor.MiddleCenter, FontStyle.Bold,
            Color.Lerp(col, Color.white, 0.30f));
        nm.text = NAME[i];
        Place(nm.rectTransform, C, new Vector2(0, 22), new Vector2(268, 56));

        _shopOwned[i] = MakeText("o" + i, box, 30, TextAnchor.MiddleCenter, FontStyle.Normal,
            new Color(0.74f, 0.80f, 0.92f));
        _shopOwned[i].text = "Owned: 0";
        Place(_shopOwned[i].rectTransform, C, new Vector2(0, -30), new Vector2(268, 46));

        // PENTING: MiddleCenter, bukan MiddleLeft. Teks rata-kiri menempel ke TEPI
        // KIRI kotaknya, bukan ke anchoredPosition-nya - itu sebabnya angka harga
        // tadi melompat ke belakang dan menabrak ikon permata.
        if (_spGem != null)
        {
            var pg = MakeImage("pg" + i, box, Color.white);
            pg.sprite = _spGem;
            pg.preserveAspect = true;
            Place(pg.rectTransform, C, new Vector2(-39, -88), new Vector2(40, 40));
        }
        _shopPrice[i] = MakeText("p" + i, box, 40, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.88f, 0.38f));
        _shopPrice[i].text = PRICE[i].ToString();
        Place(_shopPrice[i].rectTransform, C, new Vector2(26, -88), new Vector2(140, 56));

        _shopBuy[i] = MakeButton(box, "BUY", new Vector2(0, -166), new Vector2(228, 96),
            new Color(0.24f, 0.72f, 0.42f), 44);
    }

    // Satu kolom paket: label -> permata -> jumlah -> bonus -> tombol harga.
    void BuildPackColumn(Transform card, int i)
    {
        var box = MakeCard(card, new Vector2(SHOP_COL_X[i], -290f), PCOL_SIZE,
            new Color(0.24f, 0.20f, 0.44f, 0.88f));

        // POPULAR / BEST VALUE ditaruh di PUNCAK kolom. Di baris mendatar dulu
        // label ini duduk di samping angka, di kolom sempit itu pasti bertabrakan.
        if (PACK_TAG[i].Length > 0)
        {
            var tag = MakeSprite("pt" + i, box, new Color(1f, 0.62f, 0.20f, 0.95f));
            Place(tag.rectTransform, C, new Vector2(0, 182), new Vector2(190, 44));
            var tt = MakeText("ptt" + i, tag.rectTransform, 26, TextAnchor.MiddleCenter,
                FontStyle.Bold, Color.white);
            tt.text = PACK_TAG[i];
            Place(tt.rectTransform, C, Vector2.zero, new Vector2(190, 44));
        }

        if (_spGem != null)
        {
            var gi = MakeImage("pgi" + i, box, Color.white);
            gi.sprite = _spGem;
            gi.preserveAspect = true;
            Place(gi.rectTransform, C, new Vector2(0, 96), new Vector2(96, 96));
        }

        var amt = MakeText("pa" + i, box, 46, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(0.80f, 0.96f, 1f));
        amt.text = PACK_GEMS[i].ToString("N0");
        Place(amt.rectTransform, C, new Vector2(0, 6), new Vector2(268, 62));

        var sub = MakeText("ps" + i, box, 26, TextAnchor.MiddleCenter, FontStyle.Normal,
            new Color(0.80f, 0.84f, 0.96f));
        sub.text = PACK_SUB[i];
        Place(sub.rectTransform, C, new Vector2(0, -46), new Vector2(268, 44));

        _packBuy[i] = MakeButton(box, PACK_PRICE[i], new Vector2(0, -152), new Vector2(228, 96),
            new Color(0.95f, 0.60f, 0.18f), 42);
    }
}
