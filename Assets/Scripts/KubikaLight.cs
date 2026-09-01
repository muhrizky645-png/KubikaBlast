using System.Collections;
using UnityEngine;

/// <summary>
/// Mengunci setelan Directional Light utama supaya SELALU sama dengan setelan
/// acuan di Inspector. Tujuannya: pencahayaan tidak berubah / tidak jadi
/// terlalu terang & mengkilap saat game dijalankan.
/// Kalau ada lebih dari satu Directional Light, yang tambahan dimatikan supaya
/// terangnya tidak dobel.
/// </summary>
public class KubikaLight : MonoBehaviour
{
    public static KubikaLight Instance { get; private set; }

    // ===== NILAI ACUAN (sama dengan screenshot Inspector) =====
    static readonly Vector3 LIGHT_POS = new Vector3(0f, 3f, 0f);
    static readonly Vector3 LIGHT_ROT = new Vector3(40.277f, -12.448f, 6.663f);
    const float LIGHT_INTENSITY = 2f;      // Intensity
    const float LIGHT_INDIRECT = 1f;       // Indirect Multiplier
    const float LIGHT_TEMPERATURE = 5000f; // Temperature (Kelvin)

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.AfterSceneLoad)]
    static void AutoBootstrap()
    {
        if (Instance != null) return;
        var go = new GameObject("KubikaLight (auto)");
        go.AddComponent<KubikaLight>();
    }

    void Awake()
    {
        if (Instance != null && Instance != this) { Destroy(gameObject); return; }
        Instance = this;
        Apply();
    }

    void Start()
    {
        // Diterapkan ulang setelah semua Start() lain jalan, lalu sekali lagi
        // di frame berikutnya, supaya tidak ada script lain yang menimpanya.
        Apply();
        StartCoroutine(ApplyNextFrame());
    }

    IEnumerator ApplyNextFrame()
    {
        yield return null;
        Apply();
    }

    /// <summary>Terapkan nilai acuan ke Directional Light utama.</summary>
    public void Apply()
    {
        Light main = null;

        var all = FindObjectsByType<Light>(FindObjectsSortMode.None);
        for (int i = 0; i < all.Length; i++)
        {
            var l = all[i];
            if (l == null || l.type != LightType.Directional) continue;
            if (main == null) { main = l; continue; }
            if (l.enabled) l.enabled = false; // cegah cahaya dobel
        }

        // Kalau scene belum punya Directional Light, buat satu.
        if (main == null)
        {
            var go = new GameObject("Directional Light");
            main = go.AddComponent<Light>();
        }

        var t = main.transform;
        t.localPosition = LIGHT_POS;
        t.localEulerAngles = LIGHT_ROT;
        t.localScale = Vector3.one;

        main.type = LightType.Directional;
        main.color = Color.white;                    // Filter = putih
        main.useColorTemperature = true;             // Light Appearance = Filter and Temperature
        main.colorTemperature = LIGHT_TEMPERATURE;   // 5000 K
        main.intensity = LIGHT_INTENSITY;            // 2
        main.bounceIntensity = LIGHT_INDIRECT;       // 1
        main.cookie = null;                          // Cookie kosong
        main.shadows = LightShadows.None;            // Shadow Type = No Shadows
        main.enabled = true;
    }
}
