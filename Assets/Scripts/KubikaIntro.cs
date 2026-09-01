using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using KubikaBlast;

/// <summary>
/// TRANSISI PEMBUKA (penghias saat tombol MAIN ditekan).
///
/// Blok bawaan (starting fill dari BlastGame.StartingFill) sebenarnya sudah ada
/// sejak BlastGame.Start(), jauh sebelum pemain menekan MAIN. Script ini
/// menyembunyikan SEMUANYA lebih dulu -- selagi masih tertutup background menu --
/// lalu tiruan (copy) tiap blok terbang masuk dari segala arah SATU PER SATU dan
/// terpasang tepat di posisi aslinya. Begitu satu tiruan mendarat, blok asli
/// dinyalakan dan tiruannya dibuang.
///
/// PENTING (bug versi pertama):
///   Dulu blok asli disembunyikan DI DALAM LaunchOne(), yang dipanggil bertahap.
///   Akibatnya blok ke-2 sampai terakhir MASIH TERLIHAT selama animasi, jadi
///   tabung tampak sudah penuh lalu tiruan terbang masuk di atasnya. Sekarang
///   penyembunyian dilakukan SEKALIGUS lewat HideAllBlocks(), bahkan sebelum
///   pemain menekan MAIN, sehingga tabung benar-benar mulai KOSONG.
///
/// KENAPA FILE TERPISAH:
///   BlastGame.cs sudah 33 KB (di atas batas aman push) dan blok aslinya sudah
///   punya semua yang kita butuh sebagai anak GameObject "Blocks" (posisi,
///   rotasi, skala, material). Jadi script ini cuma MENIRU anak-anak itu --
///   nol perubahan di BlastGame.cs, nol material baru, nol kebocoran.
///
/// KUNCI PUTARAN:
///   Selama animasi, BlastInput dimatikan supaya tabung tidak bisa diputar dan
///   blok tidak bisa ditaruh. Penguncian dilakukan di LateUpdate() -- yang SELALU
///   jalan setelah semua Update() -- supaya tidak bisa ditimpa oleh KubikaMenu
///   yang juga mengatur _input.enabled.
/// </summary>
public class KubikaIntro : MonoBehaviour
{
    /// <summary>True selagi transisi pembuka berjalan. Script lain boleh memeriksa ini.</summary>
    public static bool Active { get; private set; }

    // ================= TOMBOL PENYETEL =================
    // Total waktu keberangkatan semua blok. Naikkan kalau mau lebih dramatis.
    const float SPAWN_WINDOW = 0.95f;
    // Jeda antar keberangkatan dijepit di antara dua nilai ini, jadi papan penuh
    // (60 blok) tidak bikin animasi kepanjangan, dan papan sepi (8 blok) tidak
    // selesai dalam sekejap.
    const float STAGGER_MIN = 0.012f;
    const float STAGGER_MAX = 0.055f;
    // Durasi terbang SATU blok. Sengaja pendek supaya banyak blok melayang bersamaan.
    const float FLY_TIME = 0.34f;
    // Jarak titik keberangkatan dari sasaran (unit dunia).
    const float TRAVEL = 7f;
    // 0 = arah datang acak murni, 1 = selalu dari sisi luar selnya sendiri.
    // Nilai tengah dipakai supaya terasa "dari mana-mana" TAPI tidak menembus drum.
    const float OUTWARD_BIAS = 0.55f;
    // Ukuran awal tiruan (kelipatan ukuran akhir).
    const float START_SCALE = 0.22f;
    // Batas aman: kalau animasi tersangkut, paksa selesai setelah sekian detik.
    const float WATCHDOG = 3f;

    const string BLOCKS_ROOT = "Blocks";
    const string FLY_ROOT = "IntroFly";

    BlastGame _game;
    BlastGame _hooked;
    BlastInput _input;
    Transform _flyRoot;

    bool _played;        // sudah jalan untuk ronde ini?
    bool _prehidden;     // blok sudah disembunyikan lebih awal?
    bool _seenInputOff;  // pernah melihat input MATI? (anti salah pancing di frame pertama)
    bool _running;
    int _flying;

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void Bootstrap()
    {
        if (FindFirstObjectByType<KubikaIntro>() != null) return;
        var go = new GameObject("KubikaIntro (auto)");
        go.AddComponent<KubikaIntro>();
    }

    void OnDestroy()
    {
        Unhook();
        Active = false;
    }

    void Update()
    {
        // Papan bisa dibangun ulang kapan saja, jadi rujukannya dicari terus
        // seperti yang dilakukan BlastBackground.
        if (_game == null) _game = FindFirstObjectByType<BlastGame>();
        if (_game != null && !ReferenceEquals(_game, _hooked)) Hook(_game);
        if (_input == null) _input = FindFirstObjectByType<BlastInput>();
        if (_game == null || _input == null) return;

        // Catat kalau input pernah MATI. KubikaMenu memadamkan BlastInput di semua
        // state kecuali Playing, jadi syarat ini pasti terpenuhi di menu utama.
        // Tanpa syarat ini, di frame pertama scene BlastInput masih menyala dari
        // serialisasi (sebelum KubikaMenu.Init memadamkannya) dan animasi akan
        // jalan diam-diam di balik menu. Kalau scene TIDAK punya KubikaMenu sama
        // sekali, syarat ini tidak akan pernah terpenuhi -- dan itu memang aman,
        // karena papan akan tetap tampil normal tanpa disembunyikan.
        if (!_input.enabled) _seenInputOff = true;

        if (_running) return;
        if (_played || !_seenInputOff) return;

        // Hanya untuk papan yang MASIH PERAWAN. Kalau pemain menjeda lalu lanjut,
        // atau sudah menaruh sesuatu, animasi pembuka tidak boleh muncul lagi.
        var core = _game.Core;
        if (core == null || core.GameOver) return;
        if (core.PiecesPlaced != 0 || core.Score != 0) return;

        // ===== KOSONGKAN LEBIH AWAL =====
        // Dilakukan selagi masih di menu (tabung tertutup background menu), jadi
        // tidak ada satu frame pun di mana pemain melihat tabung sudah penuh.
        if (!_prehidden) _prehidden = HideAllBlocks();

        // ===== PEMANCING: saat masuk mode bermain =====
        // BlastInput menyala HANYA di state Playing, jadi "input baru menyala"
        // = "pemain baru menekan MAIN".
        if (!_input.enabled) return;
        if (!_prehidden) return;

        StartCoroutine(IntroRoutine());
    }

    // Penguncian tabung. LateUpdate SELALU setelah semua Update, jadi ini yang
    // menang melawan siapa pun yang mencoba menyalakan input kembali.
    void LateUpdate()
    {
        if (!_running) return;
        if (_input != null && _input.enabled) _input.enabled = false;
    }

    void Hook(BlastGame g)
    {
        Unhook();
        _hooked = g;
        g.OnRebuilt += HandleRebuilt;
    }

    void Unhook()
    {
        if (_hooked != null) _hooked.OnRebuilt -= HandleRebuilt;
        _hooked = null;
    }

    // Ronde baru (termasuk PLAY AGAIN): pasang senjata lagi. SENGAJA tidak
    // mereset _seenInputOff -- Rebuild() bisa terjadi di frame yang sama dengan
    // SetState(Playing), dan meresetnya akan membuat animasi ronde kedua batal.
    void HandleRebuilt()
    {
        _played = false;
        _prehidden = false;
        _flyRoot = null; // Rebuild() menghapus semua anak, termasuk IntroFly
    }

    /// <summary>
    /// Sembunyikan SEMUA blok asli sekaligus. Transform-nya tetap bisa dibaca
    /// walau GameObject-nya mati, jadi data sasaran tidak hilang.
    /// Mengembalikan true kalau root "Blocks" sudah ada (walau kosong).
    /// </summary>
    bool HideAllBlocks()
    {
        if (_game == null) return false;
        var blocks = _game.transform.Find(BLOCKS_ROOT);
        if (blocks == null) return false;

        for (int i = 0; i < blocks.childCount; i++)
        {
            var t = blocks.GetChild(i);
            if (t != null && t.gameObject.activeSelf) t.gameObject.SetActive(false);
        }
        return true;
    }

    IEnumerator IntroRoutine()
    {
        _played = true;
        _running = true;
        Active = true;
        _flying = 0;

        bool restoreInput = _input != null && _input.enabled;
        if (_input != null) _input.enabled = false;

        try
        {
            var blocks = (_game != null) ? _game.transform.Find(BLOCKS_ROOT) : null;
            if (blocks == null) yield break;

            var targets = new List<Transform>(blocks.childCount);
            for (int i = 0; i < blocks.childCount; i++)
            {
                var t = blocks.GetChild(i);
                if (t == null) continue;
                // Jaring pengaman: kalau ada yang lolos dari HideAllBlocks (misal
                // papan baru dibangun di frame yang sama), matikan sekarang.
                if (t.gameObject.activeSelf) t.gameObject.SetActive(false);
                targets.Add(t);
            }
            if (targets.Count == 0) yield break;

            // Urutan pemasangan: dari bawah ke atas, lalu kiri ke kanan. Terasa
            // seperti papan sedang DIBANGUN, bukan hujan acak.
            targets.Sort(CompareBottomUp);

            EnsureFlyRoot();
            if (_flyRoot == null) yield break;

            float stagger = Mathf.Clamp(SPAWN_WINDOW / targets.Count, STAGGER_MIN, STAGGER_MAX);

            for (int i = 0; i < targets.Count; i++)
            {
                LaunchOne(targets[i]);
                yield return new WaitForSecondsRealtime(stagger);
            }

            // Tunggu yang masih melayang, dengan batas aman.
            float guard = 0f;
            while (_flying > 0 && guard < WATCHDOG)
            {
                guard += Time.unscaledDeltaTime;
                yield return null;
            }
        }
        finally
        {
            Finish(restoreInput);
        }
    }

    static int CompareBottomUp(Transform a, Transform b)
    {
        if (a == null || b == null) return 0;
        int cy = a.localPosition.y.CompareTo(b.localPosition.y);
        return cy != 0 ? cy : a.localPosition.x.CompareTo(b.localPosition.x);
    }

    void EnsureFlyRoot()
    {
        if (_game == null) return;
        if (_flyRoot != null) return;

        var existing = _game.transform.Find(FLY_ROOT);
        if (existing != null) { _flyRoot = existing; return; }

        var go = new GameObject(FLY_ROOT);
        go.transform.SetParent(_game.transform, false);
        _flyRoot = go.transform;
    }

    void LaunchOne(Transform real)
    {
        if (real == null || _game == null || _flyRoot == null) return;

        Vector3 pos = real.localPosition;
        Quaternion rot = real.localRotation;
        Vector3 scl = real.localScale;

        // Material blok asli dipakai ulang apa adanya: tampilannya dijamin sama
        // dan tidak ada material baru yang perlu dihancurkan.
        var srcMr = real.GetComponent<MeshRenderer>();
        Material mat = (srcMr != null) ? srcMr.sharedMaterial : null;

        var go = new GameObject("IntroBlock");
        go.transform.SetParent(_flyRoot, false);
        var mf = go.AddComponent<MeshFilter>();
        mf.sharedMesh = _game.CellMesh;
        var mr = go.AddComponent<MeshRenderer>();
        if (mat != null) mr.sharedMaterial = mat;
        mr.shadowCastingMode = UnityEngine.Rendering.ShadowCastingMode.Off;
        mr.receiveShadows = false;

        // Arah datang: dicampur antara acak dan "dari sisi luar selnya sendiri".
        // Campuran ini yang membuat blok terasa datang dari mana-mana tanpa harus
        // menembus drum di tengah tabung.
        Vector3 outward = new Vector3(pos.x, 0f, pos.z);
        outward = (outward.sqrMagnitude > 0.0001f) ? outward.normalized : Vector3.forward;
        Vector3 dir = Vector3.Slerp(Random.onUnitSphere, outward, OUTWARD_BIAS).normalized;
        Vector3 from = pos + dir * (TRAVEL * Random.Range(0.7f, 1.4f));

        _flying++;
        StartCoroutine(FlyOne(go.transform, real, from, pos, rot, scl));
    }

    IEnumerator FlyOne(Transform fly, Transform real, Vector3 from, Vector3 to,
                       Quaternion rot, Vector3 scl)
    {
        try
        {
            Quaternion rot0 = Random.rotation;
            Vector3 s0 = scl * START_SCALE;
            float dur = Mathf.Max(0.05f, FLY_TIME);

            if (fly != null)
            {
                fly.localPosition = from;
                fly.localRotation = rot0;
                fly.localScale = s0;
            }

            float t = 0f;
            while (t < dur)
            {
                if (fly == null) yield break;

                float k = t / dur;
                float glide = 1f - Mathf.Pow(1f - k, 3f); // meluncur cepat, melambat di ujung
                float snap = EaseOutBack(k);              // sedikit melewati lalu MENGUNCI

                fly.localPosition = Vector3.LerpUnclamped(from, to, glide);
                fly.localRotation = Quaternion.SlerpUnclamped(rot0, rot, glide);
                fly.localScale = Vector3.LerpUnclamped(s0, scl, snap);

                t += Time.unscaledDeltaTime;
                yield return null;
            }
        }
        finally
        {
            // Tiruan dibuang, blok ASLI dinyalakan. Ini titik serah-terimanya.
            if (fly != null) Destroy(fly.gameObject);
            if (real != null) real.gameObject.SetActive(true);
            _flying--;
        }
    }

    // Ease-out-back: nilainya melewati 1 sedikit lalu turun kembali ke 1, jadi
    // blok terasa "klik" saat terpasang, bukan cuma berhenti.
    static float EaseOutBack(float k)
    {
        const float s = 1.70158f;
        k = Mathf.Clamp01(k) - 1f;
        return 1f + k * k * ((s + 1f) * k + s);
    }

    void Finish(bool restoreInput)
    {
        _running = false;
        Active = false;
        _flying = 0;

        // Jaring pengaman: apa pun yang memutus animasi, papan TIDAK BOLEH
        // pernah terlihat bolong.
        RevealAll();

        if (_flyRoot != null)
            for (int i = _flyRoot.childCount - 1; i >= 0; i--)
                Destroy(_flyRoot.GetChild(i).gameObject);

        // Hanya nyalakan input kalau permainan MEMANG sedang berjalan. Kalau pemain
        // menjeda saat animasi, biarkan KubikaMenu yang menyalakannya via RESUME.
        if (restoreInput && _input != null && Time.timeScale > 0f) _input.enabled = true;
    }

    void RevealAll()
    {
        if (_game == null) return;
        var blocks = _game.transform.Find(BLOCKS_ROOT);
        if (blocks == null) return;
        for (int i = 0; i < blocks.childCount; i++)
        {
            var t = blocks.GetChild(i);
            if (t != null && !t.gameObject.activeSelf) t.gameObject.SetActive(true);
        }
    }
}
