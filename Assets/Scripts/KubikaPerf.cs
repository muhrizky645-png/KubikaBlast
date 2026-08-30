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
/// menjaga layar tetap aktif. Nilainya sinkron dengan slider KELANCARAN di
/// menu Pengaturan (KubikaMenu) lewat PlayerPrefs key "kubika_fps".
///
/// SENSITIVITAS: nilai 0.2 - 1.0 disimpan permanen (PlayerPrefs) dan diekspos
/// lewat KubikaPerf.Sensitivity. Nilai ini SIAP DIPAKAI oleh input drag; kalau
/// kamu mau block yang diseret ikut lebih 'ringan/responsif', tinggal pasang 1
/// baris hook di BlastInput (lihat catatan di bawah).
/// </summary>
public class KubikaPerf : MonoBehaviour
{
    public static KubikaPerf Instance { get; private set; }

    public const string FPS_KEY = "kubika_fps";
    public const string SENS_KEY = "kubika_sensitivity";

    /// <summary>Target FPS aktif (30/60/90/120).</summary>
    public static int TargetFps => Mathf.Clamp(PlayerPrefs.GetInt(FPS_KEY, 60), 30, 120);

    /// <summary>Sensitivitas layar 0.2 (lambat) - 1.0 (paling responsif).</summary>
    public static float Sensitivity => Mathf.Clamp(PlayerPrefs.GetFloat(SENS_KEY, 1f), 0.2f, 1f);

    public static void SetFps(int fps)
    {
        PlayerPrefs.SetInt(FPS_KEY, Mathf.Clamp(fps, 30, 120));
        PlayerPrefs.Save();
        if (Instance != null) Instance.Apply();
    }

    public static void SetSensitivity(float v)
    {
        PlayerPrefs.SetFloat(SENS_KEY, Mathf.Clamp(v, 0.2f, 1f));
        PlayerPrefs.Save();
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
    void OnEnable() { Apply(); }
}

// ============================================================================
// CATATAN: cara mengaitkan 'Sensitivity' ke drag block (opsional, 1 baris).
// Kalau kamu ingin block yang diseret mengikuti jari lebih ringan/responsif,
// di BlastInput, tempat piece dipindah ke posisi pointer, ganti pola lerp:
//
//     piece.position = Vector3.Lerp(piece.position, target, follow * Time.deltaTime);
//
// menjadi (sensitivitas 1.0 = langsung menempel, lebih kecil = lebih halus):
//
//     float f = Mathf.Lerp(12f, 40f, KubikaPerf.Sensitivity);
//     piece.position = Vector3.Lerp(piece.position, target, f * Time.deltaTime);
//
// Kalau BlastInput sudah menyetel posisi langsung (tanpa lerp), berarti drag
// sudah 'instan' dan rasa berat murni dari FPS/vSync yang sudah diperbaiki di atas.
// ============================================================================
