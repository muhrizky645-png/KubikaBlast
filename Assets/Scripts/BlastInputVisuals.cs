// Dukung DUA backend input Unity (Input Manager lama & Input System baru).
// #define harus diulang di file ini karena sifatnya per-file.
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

// BAGIAN 2 dari 2 (visual + abstraksi tombol).
// Logika input & penempatan ada di BlastInput.cs.

using System.Collections.Generic;
using UnityEngine;
#if USE_NEW_INPUT
using UnityEngine.InputSystem;
#endif
using KubikaBlast;

public partial class BlastInput
{
    // ================= PREVIEW CLEAR =================
    void SetClearPreview(HashSet<(int, int)> cells)
    {
        EnsurePreviewRoot();
        if (cells == null || cells.Count == 0)
        {
            for (int i = 0; i < _previews.Count; i++)
                if (_previews[i] != null) _previews[i].SetActive(false);
            return;
        }

        EnsurePreviews(cells.Count);
        int used = 0;
        foreach (var (c, r) in cells)
        {
            var g = _previews[used++];
            g.SetActive(true);
            g.transform.localPosition = _game.CellToWorld(c, r);
            g.transform.localRotation = _game.CellRotation(c);
            // sedikit lebih besar dari blok supaya "membungkus" -> efek menyala.
            g.transform.localScale = new Vector3(_game.cellWidth * _game.gap * 1.06f,
                                                 _game.cellHeight * _game.gap * 1.06f,
                                                 _game.blockDepth * 1.14f);
            g.GetComponent<MeshRenderer>().sharedMaterial = _matPreview;
        }
        for (int i = used; i < _previews.Count; i++)
            if (_previews[i] != null) _previews[i].SetActive(false);
    }

    void EnsurePreviews(int n)
    {
        while (_previews.Count < n)
        {
            var go = new GameObject("ClearCube");
            go.transform.SetParent(_previewRoot, false);
            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _game.CellMesh;
            go.AddComponent<MeshRenderer>();
            go.SetActive(false);
            _previews.Add(go);
        }
    }

    void EnsurePreviewRoot()
    {
        if (_previewRoot != null) return;
        var pr = new GameObject("ClearPreview").transform;
        pr.SetParent(_game.transform, false); // anak Game -> ikut transform tabung
        _previewRoot = pr;
        _previews.Clear();
    }

    // ================= INDIKATOR SEL TUJUAN (highlight halus) =================
    void EnsureGhostRoot()
    {
        if (_ghostRoot != null) return;
        var gr = new GameObject("Ghost").transform;
        gr.SetParent(_game.transform, false);
        _ghostRoot = gr;
        _ghosts.Clear();
    }

    void SetGhost(bool show, BlastCore.Piece piece, int col, int row)
    {
        if (!show || piece == null)
        {
            for (int i = 0; i < _ghosts.Count; i++)
                if (_ghosts[i] != null) _ghosts[i].SetActive(false);
            return;
        }

        EnsureGhosts(piece.Cells.Length);

        int used = 0;
        foreach (var (dx, dy) in piece.Cells)
        {
            int r = row + dy;
            if (r < 0 || r >= _game.height) continue;
            int c = _game.Core.Wrap(col + dx);

            var g = _ghosts[used++];
            g.SetActive(true);
            g.transform.localPosition = _game.CellToWorld(c, r);
            g.transform.localRotation = _game.CellRotation(c);
            // highlight "membungkus" sel tujuan (sedikit lebih besar dari blok).
            g.transform.localScale = new Vector3(_game.cellWidth * _game.gap * 1.08f,
                                                 _game.cellHeight * _game.gap * 1.08f,
                                                 _game.blockDepth * 1.12f);
            g.GetComponent<MeshRenderer>().sharedMaterial = _matGhost;
        }
        for (int i = used; i < _ghosts.Count; i++)
            if (_ghosts[i] != null) _ghosts[i].SetActive(false);
    }

    void EnsureGhosts(int n)
    {
        while (_ghosts.Count < n)
        {
            var go = new GameObject("GhostCube");
            go.transform.SetParent(_ghostRoot, false);
            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _game.CellMesh;
            go.AddComponent<MeshRenderer>();
            go.SetActive(false);
            _ghosts.Add(go);
        }
    }

    // ================= BLOK MELAYANG =================
    void EnsureHeldRoot()
    {
        if (_heldRoot != null) return;
        var hr = new GameObject("HeldPiece").transform;
        // sengaja TANPA parent tabung supaya tidak ikut berputar bersama tabung.
        _heldRoot = hr;
        _held.Clear();
    }

    // Blok melayang punya DUA mode:
    //  (A) MELENGKUNG di tabung (saat terkunci ke ghost) -> tiap kubus dipetakan ke
    //      permukaan silinder pakai CellToWorld + CellRotation (persis seperti ghost),
    //      lalu diangkat RADIAL keluar sejauh heldGhostLiftCells. Karena sel tujuan
    //      kini dihitung dari TITIK INCAR (di atas jari), blok otomatis muncul di
    //      ATAS jari -> tidak ketutup jempol lagi.
    //  (B) OVERLAY LAYAR rata (fallback saat belum ada sel tujuan valid) -> mengikuti
    //      TITIK INCAR yang sama, menghadap kamera, seukuran blok asli.
    void SetHeldPiece(bool show, BlastCore.Piece piece)
    {
        EnsureHeldRoot();
        if (!show || piece == null || _cam == null)
        {
            for (int i = 0; i < _held.Count; i++)
                if (_held[i] != null) _held[i].SetActive(false);
            return;
        }

        EnsureHeld(piece.Cells.Length);

        bool lockedToGhost = _hasLast && _lastCanPlace;
        if (lockedToGhost) RenderHeldCurved(piece);   // (A) melengkung di tabung
        else RenderHeldFlatOverlay(piece);            // (B) overlay layar mengikuti titik incar
    }

    // (A) Blok melayang MELENGKUNG: dipetakan ke permukaan tabung seperti ghost,
    // lalu diangkat radial keluar biar "melayang" di atas bayangannya.
    void RenderHeldCurved(BlastCore.Piece piece)
    {
        float lift = _game.cellHeight * Mathf.Max(0f, heldGhostLiftCells);

        int used = 0;
        foreach (var (dx, dy) in piece.Cells)
        {
            int r = _lastRow + dy;
            if (r < 0 || r >= _game.height) continue;
            int c = _game.Core.Wrap(_lastCol + dx);

            Vector3 localPos = _game.CellToWorld(c, r);
            Quaternion localRot = _game.CellRotation(c);
            Vector3 outward = localRot * Vector3.forward; // arah radial keluar (ruang lokal tabung)
            localPos += outward * lift;                   // angkat menjauh dari permukaan

            var g = _held[used++];
            g.SetActive(true);
            // pakai transform tabung -> ikut posisi & rotasi tabung (sinkron dgn ghost).
            g.transform.position = _game.transform.TransformPoint(localPos);
            g.transform.rotation = _game.transform.rotation * localRot;
            g.transform.localScale = new Vector3(_game.cellWidth * _game.gap,
                                                 _game.cellHeight * _game.gap,
                                                 _game.blockDepth);
            g.GetComponent<MeshRenderer>().sharedMaterial = SolidMat(piece.Color);
        }
        for (int i = used; i < _held.Count; i++)
            if (_held[i] != null) _held[i].SetActive(false);
    }

    // (B) Fallback OVERLAY LAYAR rata: dipakai saat belum ada sel tujuan valid.
    // Tata letak sel dihitung dalam PIXEL layar relatif TITIK INCAR (bukan titik
    // jari), diproyeksikan dekat kamera (heldDepth) & selalu menghadap kamera.
    void RenderHeldFlatOverlay(BlastCore.Piece piece)
    {
        int len = piece.Cells.Length;
        float avgX = 0f, avgY = 0f;
        foreach (var (dx, dy) in piece.Cells) { avgX += dx; avgY += dy; }
        if (len > 0) { avgX /= len; avgY /= len; }

        float d = Mathf.Max(0.05f, heldDepth);
        float tanV = Mathf.Tan(_cam.fieldOfView * 0.5f * Mathf.Deg2Rad);
        float invH = 1f / Mathf.Max(1, Screen.height);

        // Ukuran sel blok melayang (pixel). Kalau matchBlockSize: hitung supaya
        // apparent size-nya SAMA dengan blok asli di permukaan DEPAN tabung.
        float effPx = heldPixelSize;
        if (matchBlockSize)
        {
            float pxPerUnit = PixelsPerWorldUnitAtTube();
            if (pxPerUnit > 1e-6f) effPx = (_game.cellWidth * _game.gap) * pxPerUnit;
        }
        effPx *= Mathf.Max(0.05f, heldSizeMultiplier);

        // Titik acuan blok melayang.
        // Kalau titik incar diangkat (liftAimAboveFinger), pakai titik incar yang
        // SAMA dengan yang dipakai raycast -> tidak ada lompatan posisi saat
        // berganti ke mode melengkung. Kalau tidak, pakai perilaku lama.
        Vector2 anchor;
        if (liftAimAboveFinger)
        {
            anchor = PointerAimPosition();
        }
        else
        {
            anchor = PointerPosition();
            anchor.y += heldScreenYOffset;
        }

        float worldPerPixel = (2f * d * tanV) * invH;
        float cube = effPx * worldPerPixel; // sisi kubus di dunia (~effPx px di layar)

        Quaternion rot = _cam.transform.rotation; // menghadap kamera -> tampak rata di layar

        // Material: warna asli potongan.
        Material mat = SolidMat(piece.Color);

        int used = 0;
        foreach (var (dx, dy) in piece.Cells)
        {
            // posisi sel di LAYAR (pixel), lalu proyeksikan ke dunia di depan kamera.
            Vector2 sp = anchor + new Vector2((dx - avgX) * effPx,
                                              (dy - avgY) * effPx);
            Vector3 world = _cam.ScreenToWorldPoint(new Vector3(sp.x, sp.y, d));

            var g = _held[used++];
            g.SetActive(true);
            g.transform.position = world;
            g.transform.rotation = rot;
            g.transform.localScale = new Vector3(cube * _game.gap, cube * _game.gap, cube * 0.6f);
            g.GetComponent<MeshRenderer>().sharedMaterial = mat;
        }
        for (int i = used; i < _held.Count; i++)
            if (_held[i] != null) _held[i].SetActive(false);
    }

    void EnsureHeld(int n)
    {
        while (_held.Count < n)
        {
            var go = new GameObject("HeldCube");
            go.transform.SetParent(_heldRoot, false);
            var mf = go.AddComponent<MeshFilter>();
            mf.sharedMesh = _game.CellMesh;
            go.AddComponent<MeshRenderer>();
            go.SetActive(false);
            _held.Add(go);
        }
    }

    // ================= MATERIAL =================
    // Material SOLID (opaque) berwarna asli potongan, dipakai untuk blok melayang.
    Material SolidMat(int color)
    {
        if (_solidMats.TryGetValue(color, out var found) && found != null) return found;
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);
        Color c = (_game.palette != null && color >= 0 && color < _game.palette.Length)
                  ? _game.palette[color] : Color.white;
        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", c);
        m.color = c;
        _solidMats[color] = m;
        return m;
    }

    // Material semi-transparan (URP Lit; fallback Standard). withEmission -> menyala.
    Material MakeGhostMaterial(Color col, bool withEmission)
    {
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);

        if (m.HasProperty("_Surface")) m.SetFloat("_Surface", 1f); // transparan
        m.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
        m.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
        m.SetInt("_ZWrite", 0);
        m.DisableKeyword("_SURFACE_TYPE_OPAQUE");
        m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
        m.EnableKeyword("_ALPHABLEND_ON");
        m.renderQueue = (int)UnityEngine.Rendering.RenderQueue.Transparent;

        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", col);
        m.color = col;

        if (withEmission && m.HasProperty("_EmissionColor"))
        {
            m.EnableKeyword("_EMISSION");
            m.SetColor("_EmissionColor", new Color(col.r, col.g, col.b) * 1.7f);
        }
        return m;
    }

    // ==================================================================
    // ============ ABSTRAKSI INPUT (lama vs baru) ======================
    // ==================================================================
    Vector2 PointerPosition()
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

    bool PointerPressedThisFrame()
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

    bool PointerHeld()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null && m.leftButton.isPressed) return true;
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null && ts.primaryTouch.press.isPressed) return true;
        return false;
#else
        return Input.GetMouseButton(0);
#endif
    }

    bool PointerReleased()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null && m.leftButton.wasReleasedThisFrame) return true;
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null && ts.primaryTouch.press.wasReleasedThisFrame) return true;
        return false;
#else
        return Input.GetMouseButtonUp(0);
#endif
    }

    bool MultiTouchActive()
    {
#if USE_NEW_INPUT
        var ts = Touchscreen.current;
        if (ts == null) return false;
        int n = 0;
        foreach (var t in ts.touches) if (t.isInProgress) n++;
        return n >= 2;
#else
        return Input.touchCount >= 2;
#endif
    }

    bool RightDown()
    {
#if USE_NEW_INPUT
        return Mouse.current != null && Mouse.current.rightButton.wasPressedThisFrame;
#else
        return Input.GetMouseButtonDown(1);
#endif
    }

    bool RightUp()
    {
#if USE_NEW_INPUT
        return Mouse.current != null && Mouse.current.rightButton.wasReleasedThisFrame;
#else
        return Input.GetMouseButtonUp(1);
#endif
    }

    bool RightHeld()
    {
#if USE_NEW_INPUT
        return Mouse.current != null && Mouse.current.rightButton.isPressed;
#else
        return Input.GetMouseButton(1);
#endif
    }

    bool RotLeftHeld()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current;
        return k != null && (k.qKey.isPressed || k.leftArrowKey.isPressed);
#else
        return Input.GetKey(KeyCode.Q) || Input.GetKey(KeyCode.LeftArrow);
#endif
    }

    bool RotRightHeld()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current;
        return k != null && (k.eKey.isPressed || k.rightArrowKey.isPressed);
#else
        return Input.GetKey(KeyCode.E) || Input.GetKey(KeyCode.RightArrow);
#endif
    }

    bool Digit1Down()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current; return k != null && k.digit1Key.wasPressedThisFrame;
#else
        return Input.GetKeyDown(KeyCode.Alpha1);
#endif
    }

    bool Digit2Down()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current; return k != null && k.digit2Key.wasPressedThisFrame;
#else
        return Input.GetKeyDown(KeyCode.Alpha2);
#endif
    }

    bool Digit3Down()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current; return k != null && k.digit3Key.wasPressedThisFrame;
#else
        return Input.GetKeyDown(KeyCode.Alpha3);
#endif
    }

    bool TabDown()
    {
#if USE_NEW_INPUT
        var k = Keyboard.current; return k != null && k.tabKey.wasPressedThisFrame;
#else
        return Input.GetKeyDown(KeyCode.Tab);
#endif
    }

    float TwoFingerAvgDeltaX()
    {
#if USE_NEW_INPUT
        var ts = Touchscreen.current;
        if (ts == null) return 0f;
        int n = 0; float sum = 0f;
        foreach (var t in ts.touches)
        {
            if (t.isInProgress) { sum += t.delta.ReadValue().x; n++; }
        }
        return n == 2 ? sum * 0.5f : 0f;
#else
        if (Input.touchCount == 2)
            return (Input.GetTouch(0).deltaPosition.x + Input.GetTouch(1).deltaPosition.x) * 0.5f;
        return 0f;
#endif
    }
}
