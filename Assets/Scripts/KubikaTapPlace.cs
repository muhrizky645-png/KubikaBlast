using UnityEngine;

/// <summary>
/// DINONAKTIFKAN — dulu ini sistem penempatan KEDUA yang balapan dengan BlastInput.
///
/// Kenapa dimatikan:
///   BlastInput punya [DefaultExecutionOrder(1000)], sedangkan file ini tidak punya
///   atribut urutan sama sekali (= 0). Unity menjalankan urutan yang lebih kecil
///   duluan, jadi tiap kali jari dilepas:
///
///     1. KubikaTapPlace.Update() jalan DULUAN -> menyisir SELURUH papan mencari
///        sel valid yang centroid-nya paling dekat ke titik lepas -> memanggil
///        _game.TryPlace(...) -> penempatan INI yang menang.
///     2. Baru BlastInput.Update() jalan -> mau menaruh di sel yang GHOST-nya
///        benar-benar dilihat pemain -> potongan sudah Used -> gagal diam-diam.
///
///   Dua algoritmanya beda total: BlastInput mencari dalam radius 2 sel dari jari
///   dan punya magnet ke clear; file ini menyisir seluruh papan tanpa magnet.
///   Akibatnya ghost menunjuk sel A tapi blok mendarat di sel B yang bisa jauh
///   sekali => terlihat seperti "muncul blok baru entah dari mana".
///
/// Kelas ini SENGAJA dibiarkan ada (bukan dihapus) supaya scene lama yang masih
/// menempelkan komponen ini tidak error. Isinya sekarang tidak melakukan apa pun,
/// dan komponennya akan mematikan dirinya sendiri saat Awake.
///
/// JANGAN dihidupkan lagi. Semua penempatan sekarang MILIK BlastInput seorang.
/// </summary>
[System.Obsolete("Penempatan sekarang sepenuhnya ditangani BlastInput. Komponen ini tidak berfungsi lagi.")]
public class KubikaTapPlace : MonoBehaviour
{
    void Awake()
    {
        // Matikan diri sendiri kalau ada yang masih menempelkannya di scene.
        enabled = false;
    }
}
