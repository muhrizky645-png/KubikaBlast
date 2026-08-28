# Kubika Blast — HANDOFF / Ringkasan Project

> File ini adalah **titik lanjut (handoff)** untuk sesi chat/AI berikutnya. Baca ini dulu
> supaya langsung paham konsep, status, arsitektur kode, dan langkah selanjutnya
> tanpa mengulang dari nol.
>
> Terakhir diperbarui: **28 Agustus 2026** (setelah Tahap 1 & 2 selesai + push ke GitHub).

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
- `CanPlace(trayIndex, col, row)` / `CanPlaceAnywhere(trayIndex)`
- `PlacePiece(trayIndex, col, row)` → menaruh potongan ke Grid.
- `ResolveClears()` → hapus ring/kolom penuh; hasil di `LastClear { Rings, Cols, Cells }`.
- Properti: `Score`, `Combo`, `LinesCleared`, `GameOver`.
- `IsGameOver()`, `ToText()` (debug ASCII grid).

### `BlastTest.cs` — test logika (MonoBehaviour)
- Ditempel ke GameObject kosong, jalankan Play → hasil di **Console**.
- **Status: 7 tes LOLOS** (Wrap negatif/overflow, PlacePiece, ring clear, LastClear, CanPlace pada sel terisi, domino wrap).

### `RoundedCube.cs` — mesh kubus membulat
- Port prosedural dari `Tetris3D.RoundedBlock.cs` (kubus bersudut membulat ala Block Blast).
- `RoundedCube.Shared()` → Mesh kubus satuan (dibuat sekali, di-cache).
- `RoundedCube.Build(half, radius, seg)` → default `Build(0.5f, 0.15f, 6)`, mesh "KubikaRoundedCube".
- **Bukan prefab** — mesh di-generate di kode, jadi tidak perlu aset tambahan.

### `BlastGame.cs` — render tabung 3D (MonoBehaviour)
Ditempel ke GameObject `Game`. Membangun tabung + spawn kubus dari `BlastCore.Grid`.
- `CellToWorld(c, r)`: `angle = c/columns * 2π`; `x = cos*_radius`; `z = sin*_radius`; `y = r*cellHeight + cellHeight/2`. `_radius = columns*cellWidth/(2π)`.
- `CellRotation(c)`: `LookRotation(outward, up)` — kubus menghadap keluar.
- `Rebuild()` — `[ContextMenu("Rebuild Tabung")]`: bangun ulang semua. Klik kanan komponen di Inspector → "Rebuild Tabung" untuk lihat perubahan **tanpa Play**.
- `SetupCamera()` — dilewati kalau `autoCamera` di-uncheck (biar kamera manual tidak ketimpa).
- `DemoFill()` — isi grid contoh (sementara, dihapus di Tahap 3).

#### Parameter Inspector (semua `public`, bisa diatur manual):
- **Ukuran papan:** `columns` (12), `height` (10), `numColors` (5)
- **Dimensi:** `cellWidth` (1), `cellHeight` (1), `blockDepth` (0.6), `gap` (0.92)
- **Flange:** `flangeMargin` (0.4), `flangeThickness` (0.3), `drumRadiusFactor` (0.55), `showAxle` (true)
- **Kamera:** `autoCamera` (true — UNCHECK untuk pakai kamera manual), `camDistanceFactor` (3.2), `camHeightFactor` (0.8)
- **`palette`** (array warna kubus)

---

## 4. Status progres

- ✅ **Konsep** — lengkap (gameplay, visual 3D, tabung gulungan kabel).
- ✅ **Tahap 1 — Logika inti** (`BlastCore.cs`, `Shapes.cs`, `BlastTest.cs`). Semua tes lolos.
- ✅ **Tahap 2 — Render tabung 3D statis** (`RoundedCube.cs`, `BlastGame.cs`). Tampilan sudah sesuai konsep (tabung gulungan kabel, blok di tepi tutup, kamera pas).
- ✅ **Push ke GitHub** — seluruh project Unity ada di repo ini (private, branch `main`).
- ⏳ **Tahap 3 — Input & drag-drop** (BELUM). Ini langkah berikutnya.
- ⏳ **Tahap 4 — UI** (tray, skor, game over). Belum.
- ⏳ **Tahap 5 — Audio, build, SALDOKU, AdMob.** Belum.

---

## 5. Langkah berikutnya — Tahap 3 (Input & drag-drop)

Target: game benar-benar bisa dimainkan. Rencana file baru: `BlastInput.cs`.
1. **Raycast** dari kamera ke drum → konversi titik kena jadi sel grid (kebalikan `CellToWorld`; manfaatkan `_radius` yang sudah ada).
2. **Ghost preview** — kubus semi-transparan hijau (valid) / merah (invalid) saat potongan didekatkan.
3. **Drag & drop** potongan dari tray → panggil `BlastCore.PlacePiece()` → spawn kubus asli → `ResolveClears()` → update skor.
4. **Swipe** untuk memutar TABUNG (bukan potongan) supaya bisa menaruh di sisi mana pun.
5. Hapus `DemoFill()` dari `BlastGame.cs` setelah input jalan.

---

## 6. Referensi

### GitHub
- Repo ini: `muhrizky645-png/KubikaBlast` (private, Unity 6, branch `main`).
- Repo Kubika Tower asli (sumber `RoundedBlock`): `muhrizky645-png/Tetris3D`.
- Ada repo kosong `muhrizky645-png/kubikablast3d` yang tak terpakai (boleh dihapus).

### Notion (dokumen desain — milik developer, mungkin tidak diakses sesi lain)
- Halaman konsep: "Konsep Game: Kubika Blast (Kubika Tower × Block Blast)".
- Subhalaman: "Tahap 1 — Kode Logika Inti" dan "Tahap 2 — Render Tabung 3D".

### Alur kerja git (GitHub Desktop)
- Setelah tiap perubahan: tab **Changes** → isi **Summary** → **Commit to main** → **Push origin**.
- `.gitignore` Unity sudah aktif (folder `Library/`, `Temp/`, dll tidak ikut).

---

## 7. Keputusan penting & koreksi (jangan diulang salah)

- **Unity, BUKAN Godot.**
- **Potongan tidak bisa diputar; hanya tabung yang diputar** (swipe).
- **Tanpa gravity** — blok yang tersisa tidak jatuh saat ada clear.
- **Clear** terjadi pada **ring penuh** ATAU **kolom penuh**.
- **RoundedBlock itu mesh prosedural**, bukan prefab — sudah diport ke `RoundedCube.cs`.
- **Visual gulungan kabel:** drum kecil (di dalam) + flange (tutup) lebih besar; **blok di tepi tutup**, bukan menempel drum.
- Kamera bisa diatur manual (uncheck `autoCamera`). Ingat: perubahan transform yang dilakukan **saat Play mode akan hilang** ketika Stop — atur di Edit mode.
