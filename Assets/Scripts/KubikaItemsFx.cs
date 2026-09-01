// BAGIAN 3 dari 3 (efek/animasi). Logika: KubikaItems.cs, UI: KubikaItemsUI.cs.

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public partial class KubikaItems
{
    // ================= EFEK LAYAR UMUM =================

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

    // ================= EFEK PALU / BOM =================

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

    IEnumerator HammerCascade(List<(int color, Vector3 pos, Quaternion rot)> caps, Vector3 center,
        Vector2 screenCenter, Mesh mesh, Vector3 bs)
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

    // ================= PERMATA DARI CLEAR =================

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
            yield return null;
        }
        Destroy(img.gameObject);
    }

    IEnumerator GemRing(Vector2 center, int combo)
    {
        Color col = (combo >= 7) ? new Color(1f, 0.55f, 0.80f, 0.60f)
                  : (combo >= 5) ? new Color(1f, 0.72f, 0.35f, 0.60f)
                                 : new Color(0.80f, 0.90f, 1f, 0.55f);

        var img = MakeImage("gemRing", _play.transform, col);
        img.sprite = RoundSprite();
        var rt = img.rectTransform;
        rt.anchorMin = rt.anchorMax = rt.pivot = C;
        rt.anchoredPosition = center;
        rt.sizeDelta = new Vector2(120, 120);

        float baseA = col.a;
        float t = 0f, dur = 0.34f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float k = t / dur;
            rt.localScale = Vector3.one * Mathf.Lerp(0.4f, 3.4f, k);
            var c = col; c.a = Mathf.Lerp(baseA, 0f, k); img.color = c;
            yield return null;
        }
        Destroy(img.gameObject);
    }

    IEnumerator GemGainPopup(int amount, Vector2 at)
    {
        var txt = MakeText("gemGain", _play.transform, 56, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(0.72f, 0.95f, 1f));
        txt.text = "+" + amount;
        Place(txt.rectTransform, C, at, new Vector2(320f, 90f));
        var rt = txt.rectTransform;

        Vector2 from = at, to = at + new Vector2(0f, 130f);
        float t = 0f, dur = 0.8f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / dur);
            rt.anchoredPosition = Vector2.Lerp(from, to, k * k * (3f - 2f * k));
            rt.localScale = Vector3.one * Mathf.Lerp(0.6f, 1.15f, Mathf.Min(1f, k * 4f));
            var c = txt.color;
            c.a = 1f - Mathf.Clamp01((k - 0.55f) / 0.45f);
            txt.color = c;
            yield return null;
        }
        Destroy(txt.gameObject);
    }

    IEnumerator PunchLabel(RectTransform rt)
    {
        if (rt == null) yield break;
        float t = 0f, dur = 0.18f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float s = 1f + 0.35f * Mathf.Sin((t / dur) * Mathf.PI);
            rt.localScale = new Vector3(s, s, 1f);
            yield return null;
        }
        rt.localScale = Vector3.one;
    }

    // ================= POPUP SKOR SAAT ITEM DIPAKAI =================

    // Skor dari alat sudah dihitung BlastCore (setengah nilai sel). Ini cuma
    // memunculkan angkanya supaya kenaikan skor kelihatan oleh pemain.
    IEnumerator ScorePopup(int amount, Vector2 at, float delay)
    {
        if (_play == null) yield break;
        if (delay > 0f) yield return new WaitForSecondsRealtime(delay);

        var txt = MakeText("itemScore", _play.transform, 66, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.95f, 0.55f));
        txt.text = "+" + amount;
        Place(txt.rectTransform, C, at, new Vector2(340f, 100f));
        var rt = txt.rectTransform;

        Vector2 from = at, to = at + new Vector2(0f, 200f);
        float t = 0f, dur = 0.9f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / dur);
            rt.anchoredPosition = Vector2.Lerp(from, to, k * k * (3f - 2f * k));
            rt.localScale = Vector3.one * Mathf.Lerp(0.5f, 1.25f, Mathf.Min(1f, k * 4f));
            var c = txt.color;
            c.a = 1f - Mathf.Clamp01((k - 0.5f) / 0.5f);
            txt.color = c;
            yield return null;
        }
        Destroy(txt.gameObject);
    }

    // ================= EFEK BELI ITEM DI SHOP =================

    // Ikon item nge-POP keluar dari kartunya, lalu TURUN sambil MENGECIL + memudar.
    IEnumerator BuyPopFx(Item it, Vector2 at)
    {
        if (_fxCanvas == null) yield break;

        var sp = IconOf(it);
        var img = MakeImage("buyFx", _fxCanvas.transform, Color.white);
        if (sp != null) { img.sprite = sp; img.preserveAspect = true; }
        else { img.sprite = RoundSprite(); img.color = ICOL[(int)it]; }

        var rt = img.rectTransform;
        rt.anchorMin = rt.anchorMax = rt.pivot = C;
        rt.anchoredPosition = at;
        rt.sizeDelta = new Vector2(170, 170);
        rt.localScale = Vector3.zero;

        if (KubikaSfx.Instance != null) KubikaSfx.Instance.PlayGemTick(0);

        // 1) POP keluar: membesar sambil naik sedikit.
        Vector2 top = at + new Vector2(0f, 150f);
        float t = 0f, pop = 0.28f;
        while (t < pop)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / pop);
            float s = (k < 0.62f) ? Mathf.Lerp(0.2f, 1.5f, k / 0.62f)
                                  : Mathf.Lerp(1.5f, 1.2f, (k - 0.62f) / 0.38f);
            rt.localScale = Vector3.one * s;
            rt.anchoredPosition = Vector2.Lerp(at, top, k * k * (3f - 2f * k));
            yield return null;
        }

        yield return new WaitForSecondsRealtime(0.06f);

        // 2) TURUN sambil MENGECIL dan memudar.
        Vector2 end = top + new Vector2(0f, -340f);
        t = 0f;
        float fall = 0.52f;
        while (t < fall)
        {
            float dt = Time.unscaledDeltaTime; t += dt;
            float k = Mathf.Clamp01(t / fall);
            rt.anchoredPosition = Vector2.Lerp(top, end, k * k);
            rt.localScale = Vector3.one * Mathf.Lerp(1.2f, 0.22f, k);
            rt.localRotation = Quaternion.Euler(0f, 0f, rt.localEulerAngles.z + 200f * dt);
            var c = img.color;
            c.a = 1f - Mathf.Clamp01((k - 0.3f) / 0.7f);
            img.color = c;
            yield return null;
        }
        Destroy(img.gameObject);
    }

    // ================= REWARD IKLAN -> HUD =================

    // HANYA ikonnya (tanpa bubble): nge-pop di tengah, turun ke slot item di HUD,
    // lalu keluar animasi "+1".
    IEnumerator RewardToHudFx(Item it)
    {
        if (_fxCanvas == null) yield break;

        var sp = IconOf(it);
        var img = MakeImage("adRewardFx", _fxCanvas.transform, Color.white);
        if (sp != null) { img.sprite = sp; img.preserveAspect = true; }
        else { img.sprite = RoundSprite(); img.color = ICOL[(int)it]; }

        var rt = img.rectTransform;
        rt.anchorMin = rt.anchorMax = rt.pivot = C;
        Vector2 start = new Vector2(0f, 260f);
        rt.anchoredPosition = start;
        rt.sizeDelta = new Vector2(230, 230);
        rt.localScale = Vector3.zero;

        if (KubikaSfx.Instance != null) KubikaSfx.Instance.PlayGemTick(0);

        // 1) POP di tengah layar.
        float t = 0f, pop = 0.36f;
        while (t < pop)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / pop);
            float s = (k < 0.58f) ? Mathf.Lerp(0.15f, 1.55f, k / 0.58f)
                                  : Mathf.Lerp(1.55f, 1.15f, (k - 0.58f) / 0.42f);
            rt.localScale = Vector3.one * s;
            yield return null;
        }

        yield return new WaitForSecondsRealtime(0.16f);

        // 2) TURUN ke slot item di HUD.
        Vector2 target = CanvasPos(_itemBtn[(int)it], _fxCanvas);
        Vector2 from = rt.anchoredPosition;
        Vector2 mid = (from + target) * 0.5f + new Vector2(0f, 130f);
        Color trailCol = new Color(1f, 0.92f, 0.6f, 0.45f);
        float trailAt = 0f;
        t = 0f;
        float fly = 0.6f;
        while (t < fly)
        {
            float dt = Time.unscaledDeltaTime; t += dt;
            float k = Mathf.Clamp01(t / fly);
            float e = k * k * (3f - 2f * k);
            Vector2 a = Vector2.Lerp(from, mid, e);
            Vector2 b = Vector2.Lerp(mid, target, e);
            rt.anchoredPosition = Vector2.Lerp(a, b, e);
            rt.localScale = Vector3.one * Mathf.Lerp(1.15f, 0.4f, e);

            trailAt -= dt;
            if (trailAt <= 0f)
            {
                trailAt = 0.03f;
                StartCoroutine(TrailDot(rt.anchoredPosition, 40f * (1f - e * 0.5f), trailCol));
            }
            yield return null;
        }
        Destroy(img.gameObject);

        // 3) Mendarat: kilat, "+1", dan badge jumlah nge-punch.
        StartCoroutine(LandFlash(target));
        StartCoroutine(PlusOnePopup(target));
        if (_itemCount[(int)it] != null) StartCoroutine(PunchLabel(_itemCount[(int)it].rectTransform));
        if (KubikaSfx.Instance != null) KubikaSfx.Instance.PlayGemTick(3);
    }

    IEnumerator PlusOnePopup(Vector2 at)
    {
        var txt = MakeText("plusOne", _fxCanvas.transform, 76, TextAnchor.MiddleCenter, FontStyle.Bold,
            new Color(1f, 0.9f, 0.4f));
        txt.text = "+1";
        Place(txt.rectTransform, C, at, new Vector2(260f, 110f));
        var rt = txt.rectTransform;

        Vector2 from = at, to = at + new Vector2(0f, 190f);
        float t = 0f, dur = 0.95f;
        while (t < dur)
        {
            t += Time.unscaledDeltaTime;
            float k = Mathf.Clamp01(t / dur);
            rt.anchoredPosition = Vector2.Lerp(from, to, k * k * (3f - 2f * k));
            rt.localScale = Vector3.one * Mathf.Lerp(0.35f, 1.35f, Mathf.Min(1f, k * 4f));
            var c = txt.color;
            c.a = 1f - Mathf.Clamp01((k - 0.5f) / 0.5f);
            txt.color = c;
            yield return null;
        }
        Destroy(txt.gameObject);
    }

    // ================= PEMBELIAN PAKET PERMATA =================

    IEnumerator PackGemFx(int gems)
    {
        if (_fxCanvas == null || _shopGemPill == null)
        {
            _shopGemAnim = -1;
            RefreshShop();
            yield break;
        }

        Vector2 target = CanvasPos(_shopGemPill, _fxCanvas);
        int n = 18;
        int per = Mathf.Max(1, Mathf.CeilToInt((float)gems / n));
        int given = 0;

        for (int i = 0; i < n; i++)
        {
            int worth = Mathf.Max(1, Mathf.Min(per, gems - given));
            given += worth;
            StartCoroutine(PackGemOne(i, new Vector2(Random.Range(-320f, 320f), -760f), target, worth));
            yield return new WaitForSecondsRealtime(0.045f);
        }

        yield return new WaitForSecondsRealtime(1.1f);
        _shopGemAnim = -1;
        RefreshShop();
    }

    IEnumerator PackGemOne(int index, Vector2 from, Vector2 target, int worth)
    {
        var img = MakeImage("packGem", _fxCanvas.transform, Color.white);
        if (_spGem != null) { img.sprite = _spGem; img.preserveAspect = true; }
        else { img.sprite = RoundSprite(); img.color = new Color(0.62f, 0.35f, 1f); }

        var rt = img.rectTransform;
        rt.anchorMin = rt.anchorMax = rt.pivot = C;
        rt.sizeDelta = new Vector2(104, 104);
        rt.anchoredPosition = from;
        rt.localScale = Vector3.zero;

        float t = 0f, birth = 0.16f;
        while (t < birth)
        {
            t += Time.unscaledDeltaTime;
            rt.localScale = Vector3.one * Mathf.Lerp(0.2f, 1.1f, t / birth);
            yield return null;
        }

        Vector2 mid = (from + target) * 0.5f
                    + new Vector2(Random.Range(-180f, 180f), Random.Range(140f, 320f));
        Color trailCol = new Color(0.72f, 0.95f, 1f, 0.45f);
        float trailAt = 0f;
        t = 0f;
        float fly = 0.58f + index * 0.012f;
        while (t < fly)
        {
            float dt = Time.unscaledDeltaTime; t += dt;
            float k = Mathf.Clamp01(t / fly);
            float e = k * k * (3f - 2f * k);
            Vector2 a = Vector2.Lerp(from, mid, e);
            Vector2 b = Vector2.Lerp(mid, target, e);
            rt.anchoredPosition = Vector2.Lerp(a, b, e);
            rt.localScale = Vector3.one * Mathf.Lerp(1.1f, 0.38f, e);
            rt.localRotation = Quaternion.Euler(0f, 0f, rt.localEulerAngles.z + 240f * dt);

            trailAt -= dt;
            if (trailAt <= 0f)
            {
                trailAt = 0.03f;
                StartCoroutine(TrailDot(rt.anchoredPosition, 34f * (1f - e * 0.5f), trailCol));
            }
            yield return null;
        }
        Destroy(img.gameObject);

        StartCoroutine(LandFlash(target));
        if (_shopGemAnim >= 0)
        {
            _shopGemAnim = Mathf.Min(GetGems(), _shopGemAnim + worth);
            RefreshShop();
        }
        if (_shopGems != null) StartCoroutine(PunchLabel(_shopGems.rectTransform));
        if (KubikaSfx.Instance != null) KubikaSfx.Instance.PlayGemTick(index);
    }
}
