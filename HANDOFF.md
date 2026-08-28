# Kubika Blast — HANDOFF / Ringkasan Project

> File ini adalah **titik lanjut (handoff)** untuk sesi chat/AI berikutnya. Baca ini dulu
> supaya langsung paham konsep, status, arsitektur kode, dan langkah selanjutnya
> tanpa mengulang dari nol.
>
> Terakhir diperbarui: **28 Agustus 2026** (setelah Tahap 3 — Input & drag-drop selesai + push ke GitHub).

---

## 1. Apa ini?

**Kubika Blast** = game puzzle baru, gabungan:
- **Kubika Tower** (game asli developer, repo `Tetris3D`, Unity) — papan **silinder 3D** yang kolomnya membungkus (wrap).
- **Block Blast** — gameplay taruh potongan (drag & drop) dari **tray 3 potongan**, tanpa gravity.

Dibuat sebagai **project & repo terpisah** dari Kubika Tower.

### Engine & lingkungan
- **Unity 6** (bukan Godot — rencana Godot dibatalkan). Bahasa **C#**.
- Render pipeline: **URP** (Universal Render Pipeline).
- Scene: pakai ulang **SampleScene** bawaan (ada Main Camera, Directional Light, Global Volume).
- Target akhir: mobile (APK/AdMob), integrasi modul **SALDOKU/TOKO/Currency** seperti Kubika Tower (belum dikerjakan).

---

## 2. Aturan main (game design)

| Aspek | Kubika Blast |
| --- | --- |
| Papan | Silinder 3D, kolom membungkus keliling (wrap). Contoh ukuran: 12 kolom × 10 baris. |
| Balok | **Diam** (tidak jatuh / no gravity). Pemain menaruh manual. |
| Kontrol | **Drag & drop** potongan dari tray berisi **3 potongan**. |
| Rotasi | **Hanya TABUNG/papan yang bisa diputar** (swipe). **Potongan TIDAK bisa diputar** (standar Block Blast). |
| Clear | Baris **cincin penuh** (satu ring keliling) ATAU **kolom penuh** (vertikal) → hilang. **Tanpa gravity** (blok lain tidak jatuh mengisi). |
| Skor | Per sel terisi = 10 (CELL_POINTS), per garis clear = 100 (CLEAR_POINTS), ada combo. |
| Game over | Tidak ada satu pun dari 3 potongan tray yang muat di papan. |

### Visual: tabung gaya "gulungan kabel" (cable reel)
- **Drum** = spool bagian dalam (silinder, dibuat lebih kecil dari cincin blok).
- **2 flange** = piringan/tutup atas & bawah (radius sedikit lebih besar dari blok).
- **Axle** = poros tengah opsional.
- **Blok** menempel di **tepi tutup** (rim), bukan menempel di drum.
- **Kamera** membidik titik tengah tabung `(0, Height*cellHeight/2, 0)`.

---

## 3. Arsitektur kode (folder `Assets/Scripts/`)

Semua kelas logika ada di namespace **`KubikaBlast`**.

### `Shapes.cs`
- `Shapes.All` = **12 bentuk** potongan (single, domino, tromino, tetromino, dll) sebagai offset sel `(int x, int y)[]`.

### `BlastCore.cs` — logika inti (murni, tanpa Unity/rendering)
- Konstruktor: `BlastCore(columns, height, numColors = 5, seed?)`
- `Grid[c, r]` : `int` — `-1` = kosong, `>=0` = index warna.
- `Wrap(c)` : bikin kolom membungkus (mis. `Wrap(-1) = columns-1`).
- `Piece { (int x,int y)[] Cells; int Color; bool Used }`
- `Tray[3]` : 3 potongan siap taruh.
- `CanPlace(piece, col, row)` / `CanPlaceAnywhere(piece)`
- `PlacePiece(trayIndex, col, row)` → menaruh potongan ke Grid.
- `ResolveClears()` → hapus ring/kolom penuh; hasil di `LastClear { Rings, Cols, Cells }`.
- Properti: `Score`, `Combo`, `LinesCleared`, `GameOver`.
- `IsGameOver()`, `ToText()` (debug ASCII grid).

### `BlastTest.cs` — test logika (MonoBehaviour)
- Ditempel ke GameObject kosong, jalankan Play → hasil di **Console**.
- **Status: 7 tes LOLOS**.

### `RoundedCube.cs` — mesh kubus membulat
- Port prosedural dari `Tetris3D.RoundedBlock.cs`.
- `RoundedCube.Shared()` → Mesh kubus satuan (cache). `RoundedCube.Build(half, radius, seg)`.
- **Bukan prefab** — mesh di-generate di kode.

### `BlastGame.cs` — render tabung 3D (MonoBehaviour)
Ditempel ke GameObject `Game`. Membangun tabung + spawn kubus dari `BlastCore.Grid`.
- `CellToWorld(c, r)`: kembalikan koordinat **LOKAL** (relatif transform) → blok & ghost ikut berputar saat tabung diputar. `angle = c/columns * 2π`; `_radius = columns*cellWidth/(2π)`.
- `CellRotation(c)` (**public**): kubus menghadap keluar.
- **Hook publik untuk BlastInput (Tahap 3):** `Core` (BlastCore), `Radius` (float), `CellMesh` (Mesh), `TryPlace(trayIndex, col, row)` (taruh potongan + render ulang).
- Semua anak (Reel/Blocks/Ghost) memakai **localPosition/localRotation** → seluruh tabung berputar utuh saat `transform` diputar.
- `Rebuild()` — `[ContextMenu("Rebuild Tabung")]`.
- `SetupCamera()` — dilewati kalau `autoCamera` di-uncheck.
- `demoFill` (bool, default **false**) — dulu `DemoFill()` Tahap 2; sekarang OFF, papan mulai kosong. Nyalakan hanya untuk debug.

### `BlastInput.cs` — input & drag-drop (MonoBehaviour) — **BARU (Tahap 3)**
Tempel di GameObject `Game` yang SAMA dengan BlastGame (`[RequireComponent(typeof(BlastGame))]`).
- **Raycast matematis** kamera → silinder `x²+z²=R²` (di ruang lokal, jadi rotasi tabung terhitung), lalu titik kena diubah jadi `(col,row)` = kebalikan `CellToWorld`. Tidak butuh collider.
- **Ghost preview**: kubus semi-transparan **hijau** (valid) / **merah** (invalid) mengikuti pointer. Pakai `CellMesh` + material transparan.
- **Taruh**: klik kiri / tap di sel valid → `BlastGame.TryPlace()` → `PlacePiece` + `ResolveClears` + render ulang + update skor.
- **Pilih potongan tray**: tombol `1/2/3`, atau `TAB` untuk potongan berikutnya. Auto-pilih potongan pertama yang belum dipakai.
- **Putar TABUNG** (bukan potongan): drag **klik-kanan**, tombol **Q/E**, panah **Kiri/Kanan**, atau **dua jari** (touch). `keyRotateSpeed`, `dragRotateSpeed` bisa diatur di Inspector.
- Skor / combo / game over sementara lewat `Debug.Log` (UI menyusul Tahap 4).

#### Parameter Inspector BlastGame (semua `public`):
- **Ukuran papan:** `columns` (12), `height` (10), `numColors` (5)
- **Dimensi:** `cellWidth` (1), `cellHeight` (1), `blockDepth` (0.6), `gap` (0.92)
- **Flange:** `flangeMargin` (0.4), `flangeThickness` (0.3), `drumRadiusFactor` (0.55), `showAxle` (true)
- **Kamera:** `autoCamera` (true — UNCHECK untuk kamera manual), `camDistanceFactor` (3.2), `camHeightFactor` (0.8)
- **Debug:** `demoFill` (false)
- **`palette`** (array warna kubus)

---

## 4. Status progres

- ✅ **Konsep** — lengkap (gameplay, visual 3D, tabung gulungan kabel).
- ✅ **Tahap 1 — Logika inti** (`BlastCore.cs`, `Shapes.cs`, `BlastTest.cs`). Semua tes lolos.
- ✅ **Tahap 2 — Render tabung 3D statis** (`RoundedCube.cs`, `BlastGame.cs`).
- ✅ **Tahap 3 — Input & drag-drop** (`BlastInput.cs` + hook di `BlastGame.cs`). Raycast ke tabung, ghost preview, taruh potongan, putar tabung. `DemoFill` dimatikan (papan mulai kosong).
- ✅ **Push ke GitHub** — seluruh project Unity ada di repo ini (private, branch `main`).
- ⏳ **Tahap 4 — UI** (tray visual 3 potongan, panel skor/combo, layar game over + restart). Ini langkah berikutnya.
- ⏳ **Tahap 5 — Audio, build, SALDOKU, AdMob.** Belum.

---

## 5. Langkah berikutnya — Tahap 4 (UI)

Target: pemain melihat tray, skor, dan bisa restart tanpa mengandalkan Console.
1. **Tray UI** — tampilkan 3 potongan (mini-preview 2D/3D). Sorot potongan terpilih; klik tray untuk memilih (ganti tombol 1/2/3).
2. **Drag dari tray** — idealnya drag potongan langsung dari panel tray ke tabung (sekarang: pilih di tray lalu tap tabung). Manfaatkan raycast & `TryPlace` yang sudah ada.
3. **Panel skor** — tampilkan `Core.Score`, `Core.Combo`, `Core.LinesCleared` (baca via `BlastGame.Core`).
4. **Efek clear** — animasi/partikel saat `LastClear` berisi ring/kolom.
5. **Game over** — panel saat `Core.GameOver`, tombol restart → `BlastGame.Rebuild()`.

---

## 6. Referensi

### GitHub
- Repo ini: `muhrizky645-png/KubikaBlast` (private, Unity 6, branch `main`).
- Repo Kubika Tower asli (sumber `RoundedBlock`): `muhrizky645-png/Tetris3D`.
- Ada repo kosong `muhrizky645-png/kubikablast3d` yang tak terpakai (boleh dihapus).

### Notion (dokumen desain — milik developer)
- Halaman konsep: "Konsep Game: Kubika Blast (Kubika Tower × Block Blast)".
- Subhalaman: "Tahap 1 — Kode Logika Inti" dan "Tahap 2 — Render Tabung 3D".

### Alur kerja git (GitHub Desktop)
- Setelah tiap perubahan: tab **Changes** → isi **Summary** → **Commit to main** → **Push origin**.
- Kalau ada perubahan yang dibuat langsung di GitHub (mis. via AI), **Pull origin** dulu di GitHub Desktop sebelum lanjut ngoding.
- `.gitignore` Unity sudah aktif (folder `Library/`, `Temp/`, dll tidak ikut).

---

## 7. Keputusan penting & koreksi (jangan diulang salah)

- **Unity, BUKAN Godot.**
- **Potongan tidak bisa diputar; hanya tabung yang diputar** (swipe / drag / Q-E / panah).
- **Tanpa gravity** — blok yang tersisa tidak jatuh saat ada clear.
- **Clear** terjadi pada **ring penuh** ATAU **kolom penuh**.
- **RoundedBlock itu mesh prosedural**, bukan prefab — sudah diport ke `RoundedCube.cs`.
- **Visual gulungan kabel:** drum kecil (di dalam) + flange (tutup) lebih besar; **blok di tepi tutup**.
- Kamera bisa diatur manual (uncheck `autoCamera`). Perubahan transform **saat Play mode akan hilang** ketika Stop — atur di Edit mode.
- **Blok/ghost pakai koordinat LOKAL** (localPosition/localRotation), jangan world position — kalau world, blok tak ikut berputar saat tabung diputar.
- **Raycast tabung dihitung matematis** (ray vs silinder), bukan physics collider — collider primitive memang sengaja dibuang di `Paint()`.
