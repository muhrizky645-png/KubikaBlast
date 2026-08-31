# KUBIKA BLAST - HANDOFF

Dokumen serah-terima untuk siapa pun (manusia atau AI) yang melanjutkan proyek ini.
Baca sampai habis sebelum menyentuh kode.

---

## 1. Identitas proyek

| | |
|---|---|
| Engine | **Unity 6**, URP |
| Bahasa | C# |
| Repo | `muhrizky645-png/KubikaBlast` (branch `main`) |
| Scene | `Assets/Scenes/SampleScene.unity` |
| Target | Mobile (portrait), referensi UI `1080 x 2400` |
| Bahasa UI | **Inggris** (semua teks yang dilihat pemain) |
| Bahasa komentar kode | **Indonesia** |

> Ada repo kosong `muhrizky645-png/kubikablast3d` yang tak terpakai (boleh dihapus).
> Jangan tertukar - repo yang benar namanya **KubikaBlast**, tanpa `3d`.

---

## 2. Konsep permainan

Balok-balok ditaruh pada permukaan **silinder** (tabung) yang bisa diputar.

- Papan berukuran `columns = 12` (melingkar penuh) x `height = 10`.
- Kolom **menyambung** kiri-kanan: kolom 11 bertetangga dengan kolom 0. Semua
  aritmetika kolom WAJIB lewat `BlastCore.Wrap(c)`.
- **Clear** terjadi kalau sebuah **ring** (baris melingkar penuh) atau sebuah
  **kolom** penuh terisi.

### Aturan desain yang TIDAK BOLEH dilanggar

1. Ini **Unity**, bukan Godot.
2. **Balok tidak bisa diputar.** Yang berputar hanya silindernya.
3. **Tidak ada gravitasi.** Balok diam di tempat balok itu ditaruh.
4. Clear = **ring penuh** ATAU **kolom penuh**. Tidak ada match-3.
5. Menaruh balok **hanya** dengan cara men-drag dari tray. Tidak ada tap-to-place.
6. `RoundedCube.cs` membangun mesh secara prosedural. **Bukan prefab.**
7. Kamera dibingkai **sekali saja** (`_cameraFramed`), tidak tiap frame.
8. Raycast papan adalah **matematis** (ray vs silinder). **Tanpa collider.**
9. Isi awal papan tidak boleh papan catur, dan wajib menjaga penjaga
   anti-auto-clear serta anti-mati-seketika.

---

## 3. Peta file (14 skrip, semua di `Assets/Scripts/`)

| File | Peran |
|---|---|
| `BlastCore.cs` | **Otak permainan.** Murni logika, tanpa Unity API. Grid, tray, skor, combo, level, permata, game over. |
| `Shapes.cs` | Kamus bentuk balok + kolam bentuk per level. |
| `BlastGame.cs` | Jembatan logika -> dunia 3D. Membangun silinder, render balok, efek clear, getar kamera, hit-stop, jam combo, **event**. |
| `BlastInput.cs` | Drag balok dari tray, hantu penempatan, pratinjau clear, putar silinder. |
| `BlastUI.cs` | HUD dalam permainan (skor, combo, baris, level) + tray. |
| `KubikaHud.cs` | Kotak combo besar + kata pujian (GOOD! ... LEGENDARY!), mulai dari clear ke-2. |
| `KubikaMenu.cs` | Home, Jeda, Pengaturan, **Game Over**, papan peringkat. |
| `KubikaItems.cs` | Permata, item (Hammer/Bomb/Undo), bubble, iklan simulasi, toko. |
| `KubikaSfx.cs` | Semua suara & musik, dibangkitkan secara prosedural (tanpa file audio). |
| `BlastBackground.cs` | Gradien latar per level + gelembung latar. |
| `KubikaPerf.cs` | Satu-satunya pemilik `Application.targetFrameRate`. |
| `RoundedCube.cs` | Mesh kubus bersudut tumpul, dibuat sekali lalu dipakai bersama. |
| `BlastTest.cs` | Uji logika `BlastCore`. **Editor saja**, tidak jalan otomatis. |
| `KubikaTapPlace.cs` | **SUDAH DIMATIKAN.** Lihat bagian 6. |

### Namespace

Hanya `BlastCore`, `Shapes`, dan `RoundedCube` yang berada di
`namespace KubikaBlast`. Semua MonoBehaviour bersifat global dan memakai
`using KubikaBlast;`.

### Execution order

- `BlastInput` = `[DefaultExecutionOrder(1000)]` (paling akhir).
- Semua yang lain = 0.

Urutan ini **penting**: `KubikaItems` harus jalan sebelum `BlastInput` supaya
bisa memotret papan SEBELUM langkah pemain, untuk fitur Undo.

### Bootstrap otomatis (tanpa setting di Editor)

| Skrip | Kapan |
|---|---|
| `KubikaSfx`, `KubikaPerf` | `BeforeSceneLoad` + `DontDestroyOnLoad` |
| `KubikaHud`, `KubikaMenu`, `KubikaItems`, `BlastBackground` | `AfterSceneLoad` |

---

## 4. Ekonomi: skor, level, combo, permata

Semua rumus tinggal di `BlastCore`. **Jangan menghitung ulang di tempat lain.**

```csharp
public const int LINES_PER_LEVEL = 12;
public const int COMBO_CAP       = 8;
public const float COMBO_STEP    = 0.35f;

public int Level          => Math.Max(1, LinesCleared / LINES_PER_LEVEL + 1);
public int LinesIntoLevel => LinesCleared % LINES_PER_LEVEL;

public static float MultiplierFor(int combo);   // 1 + 0.35*(min(combo,8)-1) -> maks 3.45x
public static int   GemsFor(int lines, int combo);
```

- **Level dari BARIS, bukan skor.** Dulu level naik tiap 1000 poin, jadi begitu
  pengali combo membesar, level ikut meroket dan bentuk sulit datang terlalu
  cepat. Sekarang naik tiap 12 baris, apa pun skornya.
- **Combo dibatasi 8.** Tanpa batas, satu rentetan bagus bisa membuat skor
  meledak dan angka di HUD jadi tak berarti.
- **Permata**: `GemsFor(1,1) = 3`, `GemsFor(3,5) = 13`. Bertambah karena jumlah
  baris DAN karena combo, jadi clear 4 baris tidak lagi dibayar sama dengan
  clear 1 baris.

Statistik yang tersedia untuk layar Game Over: `BestCombo`, `PiecesPlaced`,
`CellsCleared`, `GemsEarned`, `LinesCleared`.

### Combo memakai JENDELA WAKTU 10 detik

```csharp
public const double COMBO_WINDOW = 10.0;  // detik

public double Clock;                       // diisi dari luar, bukan dari Unity
public double LastClearTime;
public double ComboTimeLeft  { get; }      // sisa detik
public float  ComboFraction  { get; }      // 0..1, dipakai bar di HUD
public void   TickCombo(double now);
```

Aturan lengkapnya:

1. Clear menyambung rantai kalau datang **sebelum** 10 detik sejak clear
   terakhir. Kalau lewat, rantai mulai lagi dari 1.
2. **Menaruh balok tanpa clear TIDAK memutus rantai.** Yang memutus hanya
   **waktu**.
3. **Tingkat pujian = `Combo - 1`.** Clear pertama sengaja diam, clear kedua
   "GOOD!", ketiga "AWESOME!!", dan seterusnya sampai "LEGENDARY!!".
4. Alat (Palu/Bom) tidak menyentuh combo maupun jendelanya - rantai harus hasil
   bermain, bukan hasil membeli.

> **Jangan ulangi ini:** sempat dicoba combo "beruntun ketat", yaitu setiap
> penempatan yang tidak meng-clear langsung menolkan combo. Di atas kertas
> masuk akal, di praktik hancur - begitu satu ring hancur, baris itu kosong,
> sehingga balok berikutnya hampir mustahil langsung meng-clear lagi. Combo
> praktis tidak pernah sampai 2 dan pemain **cuma pernah melihat "GOOD!"**
> sepanjang permainan. `BlastTest.TestComboWindow()` mengunci aturan nomor 2
> supaya tidak diam-diam kembali.

`BlastCore` murni C# dan tidak tahu waktu Unity, jadi jamnya digerakkan dari
luar. `BlastGame.Update()` memanggil `_core.TickCombo(Time.time)` tiap frame.
Sengaja `Time.time` (**terskala**), bukan `Time.unscaledTime`: `KubikaMenu`
menyetel `timeScale = 0` saat jeda, sehingga membuka menu jeda tidak
menghanguskan rantai combo yang sedang berjalan.

### Harga item (`KubikaItems.PRICE`)

| Item | Harga |
|---|---|
| Hammer | 120 |
| Bomb | 260 |
| Undo | 180 |

Harga lama (200/600/400) membuat sebuah bom setara ~200 baris: praktis tak
pernah terbeli.

---

## 5. Event: cara sistem lain ikut bereaksi

`BlastGame` menyiarkan lima event. **Pakai ini**, jangan memantau nilai tiap
frame (polling).

```csharp
public event Action<int>                 OnPlaced;    // jumlah sel yang ditaruh
public event Action<BlastCore.ClearInfo> OnCleared;
public event Action<int>                 OnLevelUp;
public event Action                      OnGameOver;  // dijamin sekali saja
public event Action                      OnRebuilt;   // papan baru / restart
```

`ClearInfo` membawa `Rings`, `Cols`, `Cells`, `Combo`, `Score`, `Gems`, dan
**`FromTool`**.

> **`FromTool` itu penting.** Clear yang berasal dari Hammer/Bomb ditandai
> `FromTool = true`. `KubikaSfx` memakainya untuk melewati suara cascade, dan
> `KubikaItems` memakainya untuk **tidak** membayar permata - kalau dibayar,
> membeli palu bisa menghasilkan permata lebih banyak daripada harganya.

Aturan: setiap yang `+=` sebuah event WAJIB `-=` di `OnDestroy`, dan wajib
punya penjaga supaya tidak berlangganan dua kali (`_hookedGame`).

---

## 6. `KubikaTapPlace.cs` sudah dimatikan - jangan dihidupkan

File ini dulu adalah sistem tap-to-place kedua dengan algoritma pencariannya
sendiri (menyapu seluruh papan, tanpa magnet), berjalan di order 0 sehingga
**mendahului** `BlastInput` di order 1000. Keduanya bisa menaruh balok dari tap
yang sama, di tempat yang berbeda.

Itulah penyebab **"blok hancur, lalu muncul blok baru entah dari mana"**.

Sekarang isinya hanya `void Awake() { enabled = false; }` dan bootstrap-nya
sudah dicabut. Menaruh balok **hanya** lewat drag di `BlastInput` (lihat aturan
desain nomor 5).

---

## 7. Kepemilikan tunggal - jangan ada dua tuan

Sebagian besar bug di ronde ini lahir dari dua sistem yang memperebutkan satu
hal. Daftar berikut adalah pemilik sahnya.

| Yang diperebutkan | Pemilik sah | Cara pakai dari tempat lain |
|---|---|---|
| Posisi kamera (getar) | `BlastGame` (`_camBase` + `LateUpdate`) | `_game.Shake(amount)` |
| `Time.timeScale` saat hit-stop | `BlastGame` | `_game.HitStop(detik, skala)` |
| `Time.timeScale` saat menu | `KubikaMenu.SetState` | - |
| `Application.targetFrameRate` | `KubikaPerf` | `KubikaPerf.SetFps(n)` |
| Layar Game Over | `KubikaMenu` | - |
| Rumus skor/level/permata | `BlastCore` | `MultiplierFor` / `GemsFor` |
| Angka combo & jendelanya | `BlastCore` | baca `Combo` / `ComboFraction` |
| Jam yang menggerakkan combo | `BlastGame.Update` | `core.TickCombo(Time.time)` |

Catatan penting:

- **Hit-stop dan menu.** `KubikaMenu` punya jaring pengaman yang mengembalikan
  `Time.timeScale` ke 1. Jaring itu hanya tahu harus mengalah untuk
  `BlastGame.HitStopActive`. Kalau ada kode lain yang menyetel `timeScale`
  sendiri, jaring pengaman akan langsung membatalkannya.
- **FPS** disimpan di PlayerPrefs `kubika_fps`; `KubikaMenu` menulis kunci yang
  sama. PlayerPrefs adalah sumber kebenarannya.
- **Combo pernah punya TIGA penghitung** yang saling bertentangan:
  `BlastCore.Combo` (membayar skor & permata), `KubikaHud._streak` (timer 10
  detik, mengatur kata pujian), dan `KubikaSfx._streak` (timer 15 detik,
  mengatur nada). Angka yang dilihat pemain tidak pernah sama dengan angka yang
  membayar. Sekarang semuanya membaca `BlastCore.Combo` - termasuk timernya.
- **Layar Game Over.** Dulu ada DUA layar bertumpuk: satu di `BlastUI`
  (sortingOrder 100) dan satu di `KubikaMenu` (300). Yang tersembunyi tetap
  jalan tiap frame dan tombolnya duduk persis di bawah tombol yang terlihat.
  Yang di `BlastUI` sudah dihapus seluruhnya.

---

## 8. Audio - satu AudioSource untuk satu peran

`KubikaSfx` membangkitkan semua suara secara prosedural. Tidak ada berkas audio.

**Aturan emas:** peran yang mengubah `pitch` TIDAK BOLEH berbagi `AudioSource`
dengan peran yang suaranya panjang.

Sebabnya: `AudioSource.pitch` berlaku untuk **semua** suara yang sedang
berbunyi di source itu, bukan hanya yang berikutnya. Dulu semua percikan clear
memakai satu source bersama dan menyetel ulang `pitch` sebelum tiap
`PlayOneShot`, sehingga nada yang masih berbunyi ikut berubah di tengah jalan.
Itulah **"suaranya kayak nabrak"**.

Tujuh source berdedikasi:

| Source | Peran |
|---|---|
| `_sfx` | umum |
| `_cascadeSrc` | percikan clear - **`pitch` tidak pernah disentuh** |
| `_gemSrc` | tik permata |
| `_toolSrc` | palu & bom |
| `_melodic` | naik level |
| `_voiceSrc` | suara pujian |
| `_music` | musik latar |

Pengaman lain:

- Hanya boleh ada **satu** coroutine cascade (`StopCascade()` sebelum memulai).
- Maksimal `MAX_CASCADE_NOTES = 10` nada, dimampatkan ke `CASCADE_TOTAL = 0.26f`
  detik, dengan pembatas kenyaringan `1/sqrt(n)`.
- Saat game over: `_muted` menyala, semua suara diredam 0.12 detik, lalu sting
  game over berbunyi **sendirian**.

### Pujian setelah kalah

Dulu ketika langkah terakhir menghasilkan clear DAN sekaligus game over, kata
pujian ("AWESOME!!") tetap muncul di atas layar kalah. Sekarang `KubikaHud`
memeriksa cabang game over lebih dulu dan memanggil `CancelPraise()`, dan
`KubikaSfx` membisukan diri. Kalau menambah perayaan baru, **cek game over
lebih dulu.**

---

## 9. Layar Game Over

Ada di `KubikaMenu`. Terungkap bertahap, semua memakai waktu tak terskala:

judul -> kalimat motivasi -> skor dihitung naik -> rekor -> statistik -> tombol.

Mengetuk di mana saja yang bukan tombol akan **melewati** animasi.

Kalimat motivasi dipilih berdasarkan hasil main, dari empat kolam
`static readonly string[]` di bagian atas kelas:

| Kolam | Kapan dipakai |
|---|---|
| `MotivationRecord` | rekor baru |
| `MotivationStrong` | `ratio >= 0.75` atau `>= 30` baris |
| `MotivationSolid` | `ratio >= 0.35` atau `>= 12` baris |
| `MotivationShort` | selain itu |

`ratio = Score / rekor sebelumnya`. Untuk mengubah kalimatnya, sunting keempat
array itu - tidak ada tempat lain yang perlu disentuh.

> **Rencana:** kalimat motivasi di layar ini nantinya diganti **efek suara hasil
> render ElevenLabs**, bukan teks. Keempat kolam di atas sifatnya sementara.

---

## 10. Ranjau yang mudah terinjak

- **`KubikaHud` mencari teks HUD lewat REFLEKSI, berdasarkan nama field privat**
  di `BlastUI`: `_scoreText`, `_levelText`, `_comboText`, `_linesText`.
  **Mengganti nama field itu akan mematikan HUD tanpa error kompilasi.**
- **Efek clear harus hidup di `"ClearFx"`,** bukan langsung di bawah
  `BlastGame.transform`. Dulu kubus efek bersarang di sana, lalu `RenderGrid`
  menghitungnya sebagai balok - hantu di papan.
- **Material yang dibuat saat runtime wajib dilepas.** `BlastGame` melacaknya di
  `_ownedMats` dan membersihkannya di `OnDestroy`.
- **Alat wajib lewat `BlastCore.BlastCells`,** jangan menulis `Grid[c,r] = -1`
  sendiri. Menulis langsung melewatkan `RecheckGameOver()`, sehingga sebuah alat
  bisa membebaskan papan tapi permainan tetap merasa buntu. Hal yang sama
  berlaku setelah Undo.
- **Bentuk berat tidak boleh masuk kolam acak.** Solid 3x3 (9 sel) dan ring 3x3
  (8 sel) hidup di `Base3Heavy` / `Tier3Heavy` dan tidak pernah diundi.
  `BlastTest` menjaga aturan ini.
- **Animasi UI memakai `Time.unscaledDeltaTime`.** Saat menu terbuka
  `timeScale = 0`, jadi `Time.deltaTime` bernilai nol dan animasi membeku.
- **Jam combo justru memakai waktu TERSKALA** (`Time.time`), kebalikan dari
  animasi UI. Ini disengaja: jendela combo harus ikut membeku saat pemain
  membuka menu jeda.

---

## 11. Menjalankan uji logika

`BlastTest` **tidak** jalan otomatis (dulu jalan tiap `Start`, ikut terbawa ke
build). Cara memakainya:

1. Pasang komponen `BlastTest` pada sebuah GameObject di scene.
2. Klik kanan komponennya -> **Run Logic Tests**.
3. Baca Console: tiap baris `PASS` / `FAIL`, ditutup ringkasan.

Atau centang `runOnStart` - hanya berpengaruh di dalam Editor.

Yang diuji: wrap kolom, clear ring, sel terhalang, potongan yang melintasi
sambungan, aturan skor & pengali, **jendela combo 10 detik**, clear dari alat,
dan komposisi kolam bentuk.

---

## 12. Menyunting lewat GitHub API

Penyuntingan file di repo ini dilakukan lewat GitHub API dengan **isi file
utuh** - bukan tambalan/diff. Selalu ambil file terbaru dulu, ubah, lalu kirim
kembali seluruhnya.

> Repo ini **tidak terindeks** oleh pencarian kode GitHub; `search_code` selalu
> mengembalikan nol hasil. Pakai `get_file_contents` dan baca file utuh.

> **Hati-hati file besar.** `KubikaItems.cs` (~56 KB) pernah terkirim
> **terpotong di tengah fungsi** dan tetap dilaporkan sukses oleh API. Selalu
> periksa bahwa isi yang dikirim berakhir dengan kurung kurawal penutup kelas.

---

## 13. Aset lain

```
Assets/Resources/KubikaIcons/   Hammer_A, Boom_A, Undo_A, Gem_A, Crown_A
Assets/Resources/Voice/         good, awesome, amazing, fantastic,
                                incredible, unstoppable, legendary   (opsional)
```

Semua ikon dan suara bersifat **opsional**: kalau berkasnya tidak ada, kode
mundur dengan anggun ke bentuk prosedural (sprite bulat, teks, nada sintetis).

### Urutan canvas (sortingOrder)

| Order | Canvas |
|---|---|
| 5 | `KubikaItems` latar (bubble) |
| 100 | `BlastUI` |
| 150 | `KubikaItems` layar main |
| 300 | `KubikaMenu` |
| 330 | `KubikaItems` modal (toko, iklan) |
| 400 | `KubikaItems` efek (kilat layar) |

Semua canvas: `referenceResolution = (1080, 2400)`, `MatchWidthOrHeight`,
`matchWidthOrHeight = 0.5`.
