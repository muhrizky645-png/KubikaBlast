// KubikaTapPlace.cs — Add-on TAP-TO-PLACE untuk KUBIKA BLAST.
// TIDAK menyentuh kode inti (BlastCore/BlastGame/BlastUI/BlastInput). Auto-bootstrap.
//
// Cara main:
//   1) TAP potongan di tray (bawah) untuk memilih.
//   2) TAP di tabung, dekat posisi yang diinginkan -> potongan ditaruh ke sel
//      valid TERDEKAT (magnet), jadi tidak perlu presisi.
// Memutar tabung tetap pakai GESER (drag) bawaan BlastInput.
#if ENABLE_INPUT_SYSTEM && !ENABLE_LEGACY_INPUT_MANAGER
#define USE_NEW_INPUT
#endif

using UnityEngine;
using KubikaBlast;
#if USE_NEW_INPUT
using UnityEngine.InputSystem;
#endif

public class KubikaTapPlace : MonoBehaviour
{
    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void AutoBootstrap()
    {
        if (FindFirstObjectByType<KubikaTapPlace>() != null) return;
        var go = new GameObject("KubikaTapPlace (auto)");
        go.AddComponent<KubikaTapPlace>();
    }

    [Header("Deteksi tap (bukan geser)")]
    public float tapMaxDuration = 0.35f;   // durasi maksimum sebuah tap (detik)
    public float tapMaxMovePx = 26f;       // pergeseran maksimum supaya masih dianggap tap

    [Header("Batas area tabung")]
    public float tubeBandMarginY = 0.05f;  // toleransi atas/bawah (fraksi tinggi layar)
    public float tubeBandMarginX = 0.06f;  // toleransi kiri/kanan (fraksi lebar layar)

    BlastGame _game;
    BlastInput _input;
    Camera _cam;

    int _selected = -1;

    bool _down;
    Vector2 _downPos;
    float _downTime;
    bool _canceled;

    void Update()
    {
        EnsureRefs();
        if (_game == null) return;
        var core = _game.Core;
        if (core == null) return;

        // Hanya aktif saat benar-benar sedang MAIN.
        if (!IsPlaying()) { _down = false; return; }
        if (core.GameOver) { _selected = -1; _down = false; return; }

        if (ActiveTouchCount() > 1) _canceled = true; // multi-touch = gestur lain

        if (PressedThisFrame())
        {
            _down = true;
            _canceled = ActiveTouchCount() > 1;
            _downPos = PointerPos();
            _downTime = Time.unscaledTime;
        }

        if (ReleasedThisFrame())
        {
            bool wasDown = _down;
            _down = false;
            if (!wasDown || _canceled) return;
            Vector2 up = PointerPos();
            if (Time.unscaledTime - _downTime > tapMaxDuration) return;
            if (Vector2.Distance(_downPos, up) > tapMaxMovePx) return; // itu geser, bukan tap
            HandleTap(core, up);
        }
    }

    void HandleTap(BlastCore core, Vector2 p)
    {
        // 1) Tap pada slot tray -> pilih potongan itu.
        int slot = BlastUI.TraySlotAtPointer(p);
        if (slot >= 0)
        {
            _selected = slot;
            if (_input != null) _input.SelectTray(slot);
            return;
        }

        // Tap pada UI interaktif lain (mis. tombol restart) -> abaikan.
        if (BlastUI.PointerBlocksPlacement(p)) return;

        // 2) Tentukan potongan aktif.
        int idx = ResolvePieceIndex(core);
        if (idx < 0) return;
        var piece = core.Tray[idx];
        if (piece == null || piece.Used) return;

        var cam = _cam != null ? _cam : (_cam = Camera.main);
        if (cam == null) return;

        // Batasi hanya tap di area tabung, supaya tap area lain (bar item, skor,
        // tray) tidak ikut menaruh potongan.
        if (!InsideTubeBand(core, cam, p)) return;

        // 3) Cari sel valid TERDEKAT ke titik tap (magnet), hanya sisi depan tabung.
        int bestCol = -1, bestRow = -1;
        float bestDist = float.MaxValue;
        Vector3 camPos = cam.transform.position;
        int n = piece.Cells.Length;

        for (int row = 0; row < core.Height; row++)
            for (int col = 0; col < core.Columns; col++)
            {
                if (!core.CanPlace(piece, col, row)) continue;

                Vector2 sum = Vector2.zero;
                int frontCount = 0;
                bool behind = false;
                foreach (var (dx, dy) in piece.Cells)
                {
                    int c = core.Wrap(col + dx);
                    int r = row + dy;
                    Vector3 world = _game.transform.TransformPoint(_game.CellToWorld(c, r));
                    Vector3 sp = cam.WorldToScreenPoint(world);
                    if (sp.z <= 0f) { behind = true; break; }
                    sum += new Vector2(sp.x, sp.y);
                    if (IsFront(core, c, camPos, world)) frontCount++;
                }
                if (behind || frontCount == 0) continue;

                float d = Vector2.Distance(sum / n, p);
                if (d < bestDist) { bestDist = d; bestCol = col; bestRow = row; }
            }

        if (bestCol < 0) return;

        if (_game.TryPlace(idx, bestCol, bestRow))
        {
            _selected = -1;
            if (_input != null) _input.ResetSelection(); // pindah highlight ke potongan berikutnya
        }
    }

    int ResolvePieceIndex(BlastCore core)
    {
        if (IsUsable(core, _selected)) return _selected;
        if (_input != null && IsUsable(core, _input.CurrentIndex)) return _input.CurrentIndex;
        for (int i = 0; i < core.Tray.Length; i++)
            if (IsUsable(core, i)) return i;
        return -1;
    }

    bool IsUsable(BlastCore core, int i)
    {
        return i >= 0 && core.Tray != null && i < core.Tray.Length
            && core.Tray[i] != null && !core.Tray[i].Used;
    }

    // Sel berada di sisi depan tabung bila normal keluarnya menghadap kamera.
    bool IsFront(BlastCore core, int c, Vector3 camPos, Vector3 world)
    {
        float ang = (float)c / core.Columns * Mathf.PI * 2f;
        Vector3 outward = _game.transform.rotation * new Vector3(Mathf.Cos(ang), 0f, Mathf.Sin(ang));
        return Vector3.Dot(outward, camPos - world) > 0f;
    }

    // Kotak layar yang ditempati tabung (hanya sel sisi depan).
    bool InsideTubeBand(BlastCore core, Camera cam, Vector2 p)
    {
        float minX = float.MaxValue, maxX = float.MinValue;
        float minY = float.MaxValue, maxY = float.MinValue;
        Vector3 camPos = cam.transform.position;
        bool any = false;
        for (int r = 0; r < core.Height; r++)
            for (int c = 0; c < core.Columns; c++)
            {
                Vector3 world = _game.transform.TransformPoint(_game.CellToWorld(c, r));
                if (!IsFront(core, c, camPos, world)) continue;
                Vector3 sp = cam.WorldToScreenPoint(world);
                if (sp.z <= 0f) continue;
                any = true;
                if (sp.x < minX) minX = sp.x;
                if (sp.x > maxX) maxX = sp.x;
                if (sp.y < minY) minY = sp.y;
                if (sp.y > maxY) maxY = sp.y;
            }
        if (!any) return false;
        float my = Screen.height * Mathf.Max(0f, tubeBandMarginY);
        float mx = Screen.width * Mathf.Max(0f, tubeBandMarginX);
        return p.x >= minX - mx && p.x <= maxX + mx && p.y >= minY - my && p.y <= maxY + my;
    }

    void EnsureRefs()
    {
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_game != null && _input == null) _input = _game.GetComponent<BlastInput>();
        if (_input == null) _input = FindFirstObjectByType<BlastInput>();
        if (_cam == null) _cam = Camera.main;
    }

    bool IsPlaying()
    {
        // Aman meski KubikaMenu belum set state.
        return KubikaMenu.CurrentScreenName == "Playing";
    }

    // ---------- abstraksi input (lama vs baru) ----------
    Vector2 PointerPos()
    {
#if USE_NEW_INPUT
        var m = Mouse.current;
        if (m != null) return m.position.ReadValue();
        var ts = Touchscreen.current;
        if (ts != null && ts.primaryTouch != null) return ts.primaryTouch.position.ReadValue();
        return Vector2.zero;
#else
        return (Vector2)Input.mousePosition;
#endif
    }

    bool PressedThisFrame()
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

    bool ReleasedThisFrame()
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

    int ActiveTouchCount()
    {
#if USE_NEW_INPUT
        var ts = Touchscreen.current;
        if (ts == null) return 0;
        int n = 0;
        foreach (var t in ts.touches)
        {
            if (t == null) continue;
            var ph = t.phase.ReadValue();
            if (ph == UnityEngine.InputSystem.TouchPhase.Began
             || ph == UnityEngine.InputSystem.TouchPhase.Moved
             || ph == UnityEngine.InputSystem.TouchPhase.Stationary)
                n++;
        }
        return n;
#else
        return Input.touchCount;
#endif
    }
}
