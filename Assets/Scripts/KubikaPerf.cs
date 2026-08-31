using UnityEngine;

/// <summary>
/// PERFORMA / KELANCARAN untuk Kubika Blast (ADD-ON, tanpa edit kode game).
///
/// >>> TANPA SETTING UNITY <<< Taruh file ini di folder "Assets", tekan Play.
///
/// Penyebab umum "lag & berat" di HP:
///   1) targetFrameRate default Unity di mobile kadang cuma 30 FPS.
///   2) vSync ikut campur sehingga input terasa 'berat'/telat.
///   3) Layar redup / sleep timeout mengubah refresh.
/// Script ini memaksa FPS sesuai pilihan (default 60), mematikan vSync, dan
/// menjaga layar tetap aktif.
///
/// SATU SUMBER KEBENARAN: nilainya disimpan di PlayerPrefs key "kubika_fps".
/// Slider KELANCARAN (SMOOTHNESS) di KubikaMenu menulis key yang SAMA, jadi
/// keduanya tidak mungkin berbeda. Kalau menambah tempat lain yang mengubah
/// FPS, lewatkan juga ke sini — jangan menyetel Application.targetFrameRate
/// langsung dari script baru.
///
/// CATATAN: dulu file ini juga menyimpan "Sensitivity" (0.2 - 1.0) beserta
/// komentar panjang tentang cara mengaitkannya ke drag. Semuanya sudah dibuang:
/// tidak ada yang pernah MEMBACA Sensitivity, tidak ada yang pernah MEMANGGIL
/// SetSensitivity, tidak ada slider sensitivitas di menu Pengaturan, dan
/// BlastInput menaruh potongan langsung di posisi pointer (tanpa lerp) sehingga
/// hook yang dijelaskan komentar itu tidak punya tempat menempel.
/// </summary>
public class KubikaPerf : MonoBehaviour
{
    public static KubikaPerf Instance { get; private set; }

    public const string FPS_KEY = "kubika_fps";

    /// <summary>Target FPS aktif (30/60/90/120).</summary>
    public static int TargetFps => Mathf.Clamp(PlayerPrefs.GetInt(FPS_KEY, 60), 30, 120);

    public static void SetFps(int fps)
    {
        PlayerPrefs.SetInt(FPS_KEY, Mathf.Clamp(fps, 30, 120));
        PlayerPrefs.Save();
        if (Instance != null) Instance.Apply();
    }

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    static void Boot()
    {
        if (Instance != null) return;
        var go = new GameObject("KubikaPerf (auto)");
        go.AddComponent<KubikaPerf>();
    }

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        DontDestroyOnLoad(gameObject);
        Apply();
    }

    void OnDestroy() { if (Instance == this) Instance = null; }

    public void Apply()
    {
        // vSync sering membuat sentuhan terasa 'berat/telat' di HP -> matikan.
        QualitySettings.vSyncCount = 0;
        // Paksa frame rate tinggi (default mobile kadang 30).
        Application.targetFrameRate = TargetFps;
        // Jangan biarkan layar tidur/redup saat main.
        Screen.sleepTimeout = SleepTimeout.NeverSleep;
    }

    // Jaga-jaga kalau ada sistem lain me-reset nilainya saat ganti scene.
    void OnEnable() { if (Instance == this) Apply(); }
}
