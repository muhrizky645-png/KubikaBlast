using System.Collections.Generic;
using UnityEngine;
using KubikaBlast;

/// <summary>
/// TAHAP 3 — Input & drag-drop untuk Kubika Blast.
/// Tempel komponen ini ke GameObject "Game" yang SAMA dengan BlastGame.
///
/// Kontrol:
///  - Arahkan pointer (mouse / sentuh) ke permukaan tabung -> muncul ghost preview
///    (hijau = boleh ditaruh, merah = tidak boleh).
///  - Klik kiri / tap -> taruh potongan tray yang sedang dipilih.
///  - Tombol 1 / 2 / 3 -> pilih potongan tray ke-1/2/3. TAB -> ganti ke potongan berikutnya.
///  - Putar TABUNG: drag pakai KLIK-KANAN, atau tombol Q/E, atau panah Kiri/Kanan,
///    atau DUA JARI di layar sentuh. (Potongan sendiri TIDAK diputar - khas Block Blast.)
///
/// Catatan: tray visual & panel skor menyusul di Tahap 4 (UI). Untuk sekarang skor,
/// potongan terpilih, dan game over ditampilkan lewat Console (Debug.Log).
/// </summary>
[RequireComponent(typeof(BlastGame))]
public class BlastInput : MonoBehaviour
{
    [Header("Kecepatan putar tabung")]
    public float keyRotateSpeed = 90f;    // derajat / detik (Q/E, panah kiri-kanan)
    public float dragRotateSpeed = 0.3f;  // derajat / pixel (drag klik-kanan atau 2 jari)

    [Header("Warna ghost preview (alpha = transparansi)")]
    public Color validColor = new Color(0.35f, 0.90f, 0.40f, 0.50f);
    public Color invalidColor = new Color(0.95f, 0.30f, 0.30f, 0.50f);

    BlastGame _game;
    Camera _cam;

    int _current = -1;                 // index potongan tray yang sedang dipilih
    Material _matValid, _matInvalid;
    Transform _ghostRoot;
    readonly List<GameObject> _ghosts = new List<GameObject>();

    // status drag-putar (klik-kanan)
    bool _rotating;
    float _lastPointerX;

    void Awake()
    {
        _game = GetComponent<BlastGame>();
    }

    void Start()
    {
        _cam = Camera.main;
        _matValid = MakeGhostMaterial(validColor);
        _matInvalid = MakeGhostMaterial(invalidColor);

        var gr = new GameObject("Ghost").transform;
        gr.SetParent(_game.transform, false);
        _ghostRoot = gr;

        SelectFirstUnused();
    }

    void Update()
    {
        if (_cam == null) _cam = Camera.main;
        var core = _game.Core;
        if (core == null) return;

        HandleRotation();
        HandleSelection();

        // pastikan potongan terpilih masih valid (mis. setelah refill tray)
        var piece = CurrentPiece();
        if (piece == null) { SelectFirstUnused(); piece = CurrentPiece(); }

        int col = 0, row = 0;
        bool haveCell = !core.GameOver && piece != null && PointerToCell(out col, out row);
        bool canPlace = haveCell && core.CanPlace(piece, col, row);

        SetGhost(haveCell, piece, col, row, canPlace);

        // Taruh potongan saat pointer dilepas di sel yang valid (mendukung klik & drag-drop).
        if (haveCell && canPlace && !_rotating && Input.GetMouseButtonUp(0))
        {
            if (_game.TryPlace(_current, col, row))
            {
                Debug.Log($"[KubikaBlast] Taruh potongan #{_current} di (c={col}, r={row}). " +
                          $"Skor={core.Score}  Combo={core.Combo}  Lines={core.LinesCleared}");
                SelectFirstUnused();
                if (core.GameOver)
                    Debug.Log("[KubikaBlast] GAME OVER - tidak ada potongan tray yang muat lagi.");
            }
        }
    }

    // ================= ROTASI TABUNG =================
    void HandleRotation()
    {
        float deltaDeg = 0f;

        // keyboard: Q/panah-kiri putar satu arah, E/panah-kanan arah sebaliknya
        float k = 0f;
        if (Input.GetKey(KeyCode.Q) || Input.GetKey(KeyCode.LeftArrow)) k += 1f;
        if (Input.GetKey(KeyCode.E) || Input.GetKey(KeyCode.RightArrow)) k -= 1f;
        deltaDeg += k * keyRotateSpeed * Time.deltaTime;

        // drag klik-kanan (desktop)
        if (Input.GetMouseButtonDown(1)) { _rotating = true; _lastPointerX = Input.mousePosition.x; }
        if (Input.GetMouseButtonUp(1)) _rotating = false;
        if (_rotating && Input.GetMouseButton(1))
        {
            float dx = Input.mousePosition.x - _lastPointerX;
            _lastPointerX = Input.mousePosition.x;
            deltaDeg += -dx * dragRotateSpeed;
        }

        // dua jari (touch)
        if (Input.touchCount == 2)
        {
            float avgX = (Input.GetTouch(0).deltaPosition.x + Input.GetTouch(1).deltaPosition.x) * 0.5f;
            deltaDeg += -avgX * dragRotateSpeed;
        }

        if (Mathf.Abs(deltaDeg) > 0.0001f)
            _game.transform.Rotate(0f, deltaDeg, 0f, Space.World);
    }

    // ================= PILIH POTONGAN TRAY =================
    void HandleSelection()
    {
        if (Input.GetKeyDown(KeyCode.Alpha1)) TrySelect(0);
        if (Input.GetKeyDown(KeyCode.Alpha2)) TrySelect(1);
        if (Input.GetKeyDown(KeyCode.Alpha3)) TrySelect(2);
        if (Input.GetKeyDown(KeyCode.Tab)) SelectNextUnused();
    }

    BlastCore.Piece CurrentPiece()
    {
        var tray = _game.Core.Tray;
        if (_current < 0 || _current >= tray.Length) return null;
        var p = tray[_current];
        return (p != null && !p.Used) ? p : null;
    }

    void TrySelect(int i)
    {
        var tray = _game.Core.Tray;
        if (i >= 0 && i < tray.Length && tray[i] != null && !tray[i].Used) _current = i;
    }

    void SelectFirstUnused()
    {
        var tray = _game.Core.Tray;
        for (int i = 0; i < tray.Length; i++)
            if (tray[i] != null && !tray[i].Used) { _current = i; return; }
        _current = -1;
    }

    void SelectNextUnused()
    {
        var tray = _game.Core.Tray;
        int startFrom = _current < 0 ? -1 : _current;
        for (int step = 1; step <= tray.Length; step++)
        {
            int i = (startFrom + step) % tray.Length;
            if (i < 0) i += tray.Length;
            if (tray[i] != null && !tray[i].Used) { _current = i; return; }
        }
        SelectFirstUnused();
    }

    // ================= RAYCAST -> SEL GRID (kebalikan CellToWorld) =================
    // Silinder blok: x^2 + z^2 = R^2 (di ruang LOKAL BlastGame). Kita cari titik
    // permukaan terdekat ke kamera, lalu ubah jadi (col,row).
    bool PointerToCell(out int col, out int row)
    {
        col = 0; row = 0;
        if (_cam == null) return false;

        float R = _game.Radius;
        if (R <= 0f) return false;

        Ray ray = _cam.ScreenPointToRay(Input.mousePosition);

        // ubah ray ke ruang lokal BlastGame supaya rotasi tabung ikut diperhitungkan
        Vector3 o = _game.transform.InverseTransformPoint(ray.origin);
        Vector3 d = _game.transform.InverseTransformDirection(ray.direction);
        d.Normalize();

        float a = d.x * d.x + d.z * d.z;
        if (a < 1e-6f) return false; // ray hampir sejajar sumbu tabung
        float b = 2f * (o.x * d.x + o.z * d.z);
        float c = o.x * o.x + o.z * o.z - R * R;
        float disc = b * b - 4f * a * c;
        if (disc < 0f) return false; // tidak kena silinder

        float sq = Mathf.Sqrt(disc);
        float t0 = (-b - sq) / (2f * a); // permukaan depan (dekat kamera)
        float t1 = (-b + sq) / (2f * a); // permukaan belakang
        float t = t0 >= 0f ? t0 : t1;
        if (t < 0f) return false;

        Vector3 hit = o + d * t;

        float ang = Mathf.Atan2(hit.z, hit.x);      // sama seperti sudut di CellToWorld
        int cc = Mathf.RoundToInt(ang / (2f * Mathf.PI) * _game.columns);
        col = _game.Core.Wrap(cc);

        int rr = Mathf.RoundToInt(hit.y / _game.cellHeight - 0.5f);
        if (rr < 0 || rr >= _game.height) return false;
        row = rr;
        return true;
    }

    // ================= GHOST PREVIEW =================
    void SetGhost(bool show, BlastCore.Piece piece, int col, int row, bool canPlace)
    {
        if (!show || piece == null)
        {
            for (int i = 0; i < _ghosts.Count; i++) _ghosts[i].SetActive(false);
            return;
        }

        var mat = canPlace ? _matValid : _matInvalid;
        EnsureGhosts(piece.Cells.Length);

        int used = 0;
        foreach (var (dx, dy) in piece.Cells)
        {
            int r = row + dy;
            if (r < 0 || r >= _game.height) continue; // di luar tinggi tabung -> tak digambar
            int c = _game.Core.Wrap(col + dx);

            var g = _ghosts[used++];
            g.SetActive(true);
            g.transform.localPosition = _game.CellToWorld(c, r);
            g.transform.localRotation = _game.CellRotation(c);
            g.transform.localScale = new Vector3(_game.cellWidth * _game.gap,
                                                 _game.cellHeight * _game.gap,
                                                 _game.blockDepth);
            g.GetComponent<MeshRenderer>().sharedMaterial = mat;
        }
        for (int i = used; i < _ghosts.Count; i++) _ghosts[i].SetActive(false);
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

    // Material semi-transparan untuk ghost (URP Lit; fallback Standard).
    Material MakeGhostMaterial(Color col)
    {
        var shader = Shader.Find("Universal Render Pipeline/Lit");
        if (shader == null) shader = Shader.Find("Standard");
        var m = new Material(shader);

        if (m.HasProperty("_Surface")) m.SetFloat("_Surface", 1f); // 0=opaque, 1=transparent
        m.SetInt("_SrcBlend", (int)UnityEngine.Rendering.BlendMode.SrcAlpha);
        m.SetInt("_DstBlend", (int)UnityEngine.Rendering.BlendMode.OneMinusSrcAlpha);
        m.SetInt("_ZWrite", 0);
        m.DisableKeyword("_SURFACE_TYPE_OPAQUE");
        m.EnableKeyword("_SURFACE_TYPE_TRANSPARENT");
        m.EnableKeyword("_ALPHABLEND_ON"); // untuk fallback Standard
        m.renderQueue = (int)UnityEngine.Rendering.RenderQueue.Transparent;

        if (m.HasProperty("_BaseColor")) m.SetColor("_BaseColor", col);
        m.color = col;
        return m;
    }
}
