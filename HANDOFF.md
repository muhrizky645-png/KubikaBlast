# Kubika Blast — HANDOFF / Ringkasan Project

> File ini adalah **titik lanjut (handoff)** untuk sesi chat/AI berikutnya. Baca ini dulu
> supaya langsung paham konsep, status, arsitektur kode, dan langkah selanjutnya
> tanpa mengulang dari nol.
>
> Terakhir diperbarui: **28 Agustus 2026** (setelah Tahap 4 UI + Tahap 5 efek clear,
> polesan kamera "flat", starting fill pola acak, & blok melayang melengkung — semua sudah di-push ke GitHub).

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
- Input: mendukung **Input System baru** & **Input Manager lama** (auto lewat `#if`).
- Target akhir: mobile (APK/AdMob), integrasi modul **SALDOKU/TOKO/Currency** seperti Kubika Tower (belum dikerjakan).

---

## 2. Aturan main (game design)

| Aspek | Kubika Blast |
| --- | --- |
| Papan | Silinder 3D, kolom membungkus keliling (wrap). Default kode: 12 kolom × 10 baris (developer sempat pakai 16×8 di Inspector). |
| Balok | **Diam** (tidak jatuh / no gravity). Pemain menaruh manual. |
| Kontrol | **Seret potongan dari tray** (drag-from-tray ala Block Blast di HP). |
| Rotasi | **Hanya TABUNG/papan yang bisa diputar** (swipe/drag/Q-E/panah/2 jari). **Potongan TIDAK bisa diputar**. |
| Clear | Baris **cincin penuh** (satu ring keliling) ATAU **kolom penuh** (vertikal) → hilang. **Tanpa gravity**. |
| Skor | Per sel terisi = 10 (CELL_POINTS), per garis clear = 100 (CLEAR_POINTS), bonus multi-clear × combo. |
| Game over | Tidak ada satu pun dari 3 potongan tray yang muat di papan. |
| Mulai game | Papan sudah terisi **pola blok default acak** (starting fill) yang berubah tiap main. |

### Visual: tabung gaya "gulungan kabel" (cable reel)
- **Drum** = spool bagian dalam; dibuat **mepet ke sisi dalam blok**, disisakan celah `drumGap`.
- **2 flange** = piringan/tutup atas & bawah (radius sedikit lebih besar dari blok), digeser keluar setengah tebalnya agar tak memotong blok baris ujung.
- **Axle** = poros tengah opsional.
- **Blok** menempel di cincin (rim), menghadap keluar.
- **Kamera** "flat" ala Block Blast (lihat bagian kamera di bawah).

---

## 3. Arsitektur kode (folder `Assets/Scripts/`)

Semua kelas logika ada di namespace **`KubikaBlast`**.

### `Shapes.cs`
- `Shapes.All` = **12 bentuk** potongan sebagai offset sel `(int x, int y)[]`.

### `BlastCore.cs` — logika inti (murni C#, tanpa Unity/rendering)
- Konstruktor: `BlastCore(columns, height, numColors = 5, seed?)`
- `Grid[c, r]` : `int` — `-1` = kosong, `>=0` = index warna.
- `Wrap(c)` : kolom membungkus.
- `Piece { (int x,int y)[] Cells; int Color; bool Used }` — **public**.
- `Tray[3]` : 3 potongan siap taruh (**public**).
- `CanPlace(piece, col, row)` / `CanPlaceAnywhere(piece)` — **public**.
- `PlacePiece(trayIndex, col, row)` → taruh + `ResolveClears()` + refill tray + `CheckGameOver()`.
- `ResolveClears()` → hapus ring/kolom penuh; hasil di `LastClear { Rings, Cols, Cells }` (Cells simpan warna asli utk efek).
- Properti: `Score`, `Combo`, `LinesCleared`, `GameOver`, `Columns`, `Height`.
- `Reset(columns,height)` (dipakai konstruktor) mengisi grid -1 & refill tray.

### `BlastTest.cs` — test logika (MonoBehaviour). Status: tes lolos.

### `RoundedCube.cs` — mesh kubus membulat (port dari `Tetris3D.RoundedBlock`).
- `RoundedCube.Shared()` → Mesh kubus satuan (cache). Bukan prefab.

### `BlastGame.cs` — render tabung 3D + starting fill (MonoBehaviour)
Ditempel ke GameObject `Game`. Membangun tabung + spawn kubus dari `BlastCore.Grid`.
- `CellToWorld(c, r)`: koordinat **LOKAL** (relatif transform). `_radius = columns*cellWidth/(2π)`.
- `CellRotation(c)` (**public**): kubus menghadap keluar.
- **Hook publik:** `Core`, `Radius`, `CellMesh`, `TryPlace(trayIndex, col, row)` (taruh + efek clear + render ulang).
- `Rebuild()` — `[ContextMenu("Rebuild Tabung")]`; juga dipakai sebagai **Restart** oleh BlastUI. **Kamera hanya di-frame SEKALI** (`_cameraFramed`) supaya tak reset tiap Rebuild.
- `FrameCameraNow()` — `[ContextMenu]` paksa atur ulang kamera.
- **Efek clear (Tahap 5)** — `SpawnClearEffect` + coroutine `ClearSequence`/`AnimateFx`: kubus Fx hancur **berurutan satu-per-satu** (baris bawah→atas, kiri→kanan) dg jeda `clearStepDelay`.
- **Starting fill** — `StartingFill()` dipanggil di `Rebuild()` (kalau `startWithBlocks` & bukan `demoFill`). Lihat bagian 3a.
- `demoFill` (default **false**) — debug DemoFill lama; kalau ON menimpa starting fill.

#### 3a. Starting fill — POLA acak flat (ala Block Blast)
- Blok default **tersebar rata di seluruh tabung** (bukan menumpuk dari bawah).
- Tiap mulai/Restart pilih **1 dari 7 pola** acak (`rng.Next(7)`): 0 scatter, 1 garis vertikal, 2 pita horizontal, 3 **pasangan 2 blok serong ke atas** (domino diagonal, via `FillDiagonalPairs`), 4 diagonal melingkar, 5 gelombang sinus, 6 cluster/gumpalan (via `FillClusters`).
- **Pola catur DIHAPUS** — dulu bikin semua sel kosong terisolasi → langsung game over.
- **2 pengaman:** (1) tak ada cincin/kolom **penuh** (biar tak auto-clear saat mulai); (2) **anti langsung-mati** — pastikan minimal satu potongan tray muat (`AnyTrayFits()`); kalau tidak, kosongkan sel acak sampai ada ruang.
- `startSeed = 0` → pola **berubah tiap main**; selain 0 → pola **tetap** (reproducible).

### `BlastInput.cs` — input, drag-drop, blok melayang, preview-clear (MonoBehaviour)
Tempel di GameObject `Game` yang SAMA (`[RequireComponent(typeof(BlastGame))]`, `[DefaultExecutionOrder(1000)]` supaya jalan setelah BlastGame.Start).
- **Model seret-dari-tray (HP):** gestur WAJIB dimulai di slot tray (`BlastUI.TraySlotAtPointer`), lalu seret ke tabung. Menekan/menyeret langsung di tabung TIDAK menaruh apa pun.
- **Raycast matematis** kamera → silinder `x²+z²=R²` (ruang lokal, jadi rotasi tabung terhitung) → `(col,row)`. Tanpa collider.
- **Indikator sel tujuan (ghost):** highlight tipis "membungkus" sel, HANYA saat posisi PAS; dipusatkan di bawah jari (anchor = sel jari − centroid potongan).
- **Preview CLEAR:** sel yang AKAN hancur ikut menyala (`PredictClears`), ala Block Blast.
- **Blok melayang (2 mode)** — `SetHeldPiece()`:
  - (A) **MELENGKUNG di tabung** saat terkunci ke ghost (`RenderHeldCurved`): tiap kubus dipetakan ke permukaan silinder pakai `CellToWorld` + `CellRotation` (persis seperti ghost), lalu diangkat **radial keluar** sejauh `heldGhostLiftCells` → lengkungnya **sinkron dg bayangan** di angle/zoom apa pun. Pakai `transform.TransformPoint` → ikut rotasi tabung.
  - (B) **Overlay layar rata** (`RenderHeldFlatOverlay`): fallback saat belum ada sel tujuan valid — mengikuti jari, menghadap kamera, seukuran blok asli (`matchBlockSize`).
- **Taruh:** lepas jari di sel valid → `BlastGame.TryPlace()`. Lepas di luar/di atas UI (`BlastUI.PointerBlocksPlacement`) = batal.
- **Pilih tray:** tombol `1/2/3`, `TAB`, atau tap slot tray. API `SelectTray(i)`, `ResetSelection()`, `CurrentIndex`.
- **Putar TABUNG:** drag klik-kanan, Q/E, panah, atau 2 jari (`keyRotateSpeed`, `dragRotateSpeed`).

### `BlastUI.cs` — UI (Tahap 4) (MonoBehaviour)
- Tray 3 potongan, panel skor/combo/lines, layar game over + tombol Restart (→ `BlastGame.Rebuild()`).
- Menyediakan **static helper** yang dipakai BlastInput: `TraySlotAtPointer(pos)` (slot tray di bawah pointer, -1 kalau bukan) & `PointerBlocksPlacement(pos)` (true kalau pointer di atas UI → batalkan penempatan).

---

## 3b. Parameter Inspector (semua `public`)

### BlastGame
- **Ukuran papan:** `columns` (12), `height` (10), `numColors` (5)
- **Dimensi:** `cellWidth` (1), `cellHeight` (1), `blockDepth` (0.6), `gap` (0.92)
- **Flange:** `flangeMargin` (0.4), `flangeThickness` (0.3), `drumGap` (0.08), `showAxle` (true)
- **Kamera (auto-fit, di-frame SEKALI):** `autoCamera` (true), `cameraFov` (35 — kecil = flat), `cameraZoomOut` (1.25), `cameraTilt` (6°), `cameraAimHeight` (0.45)
- **Efek clear:** `enableClearFx` (true), `clearFxDuration` (0.4), `clearStepDelay` (0.06)
- **Debug:** `demoFill` (false)
- **Blok default saat mulai:** `startWithBlocks` (true), `startFillChance` (0.45), `startRandomColors` (true), `startSeed` (0)
- **`palette`** (array warna kubus)

### BlastInput
- **Putar:** `keyRotateSpeed` (90), `dragRotateSpeed` (0.3)
- **Ghost/drag:** `ghostOnlyWhileDragging` (true), `dragThreshold` (12)
- **Indikator tujuan:** `ghostHighlightColor`
- **Preview clear:** `enableClearPreview` (true), `clearPreviewColor`
- **Blok melayang:** `enableHeldPiece` (true), `heldGhostLiftCells` (0.6 — tinggi angkat radial saat melengkung), `heldScreenYOffset` (90), `matchBlockSize` (true), `heldSizeMultiplier` (1), `heldPixelSize` (90), `heldDepth` (2) — empat terakhir hanya untuk mode fallback overlay.

---

## 4. Status progres

- ✅ **Konsep** — lengkap.
- ✅ **Tahap 1 — Logika inti** (`BlastCore.cs`, `Shapes.cs`, `BlastTest.cs`). Tes lolos.
- ✅ **Tahap 2 — Render tabung 3D statis** (`RoundedCube.cs`, `BlastGame.cs`).
- ✅ **Tahap 3 — Input & drag-drop** (`BlastInput.cs`). Model seret-dari-tray, raycast, ghost.
- ✅ **Tahap 4 — UI** (`BlastUI.cs`). Tray, skor/combo, game over + restart.
- ✅ **Tahap 5 — Efek clear berurutan** (kubus hancur satu-per-satu + preview clear).
- ✅ **Polesan kamera** — auto-fit "flat" (FOV kecil + zoom-out + tilt + aim height), di-frame sekali.
- ✅ **Starting fill** — pola blok default acak yang berubah tiap main, dg pengaman anti auto-clear & anti langsung-mati.
- ✅ **Blok melayang melengkung** — sinkron dengan bayangan saat terkunci ke ghost.
- ✅ **Push ke GitHub** — seluruh project ada di repo ini (private, branch `main`).
- ⏳ **Berikutnya (Tahap 6)** — audio/SFX, polish juice (skor pop, screenshake), build APK, integrasi SALDOKU/TOKO/Currency, AdMob. Belum.

---

## 5. Ide / langkah berikutnya (belum dikerjakan)

1. **Audio & SFX** — suara taruh blok, clear, combo, game over.
2. **Juice visual** — animasi skor bertambah, efek combo, screenshake ringan saat multi-clear.
3. **Kurva kesulitan** — atur variasi/kepadatan starting fill atau distribusi bentuk tray seiring skor.
4. **Build mobile** — APK, uji sentuh di HP, orientasi portrait.
5. **Ekonomi game** — SALDOKU/TOKO/Currency + AdMob (mengikuti Kubika Tower).

---

## 6. Referensi

### GitHub
- Repo ini: `muhrizky645-png/KubikaBlast` (private, Unity 6, branch `main`).
- File di `Assets/Scripts/`: `Shapes.cs`, `BlastCore.cs`, `BlastTest.cs`, `RoundedCube.cs`, `BlastGame.cs`, `BlastInput.cs`, `BlastUI.cs`.
- Repo Kubika Tower asli (sumber `RoundedBlock`): `muhrizky645-png/Tetris3D`.
- Ada repo kosong `muhrizky645-png/kubikablast3d` yang tak terpakai (boleh dihapus).

### Notion (dokumen desain — milik developer)
- Halaman konsep: "Konsep Game: Kubika Blast (Kubika Tower × Block Blast)" + subhalaman tahap.

### Alur kerja git (GitHub Desktop)
- Perubahan via AI dibuat **langsung di GitHub** (branch `main`) → **Pull origin** dulu di GitHub Desktop sebelum lanjut ngoding lokal.
- Setelah edit lokal: **Changes** → Summary → **Commit to main** → **Push origin**.
- `.gitignore` Unity aktif (`Library/`, `Temp/`, dll tak ikut).

---

## 7. Keputusan penting & koreksi (jangan diulang salah)

- **Unity, BUKAN Godot.**
- **Potongan tidak bisa diputar; hanya tabung yang diputar.**
- **Tanpa gravity** — blok tersisa tidak jatuh saat ada clear.
- **Clear** = **ring penuh** ATAU **kolom penuh**.
- **Menaruh HANYA lewat seret dari tray** — menekan tabung langsung tidak menaruh.
- **RoundedBlock = mesh prosedural** (`RoundedCube.cs`), bukan prefab.
- **Visual gulungan kabel:** drum mepet sisi dalam blok (`drumGap`) + flange (tutup) lebih besar; blok di cincin.
- **Kamera di-frame SEKALI** (`_cameraFramed`); perubahan transform saat Play mode hilang saat Stop — atur di Edit mode. FOV kecil = tampilan flat.
- **Blok/ghost/blok-melayang-melengkung pakai koordinat/transform tabung** (localPosition/localRotation atau TransformPoint), bukan world murni — supaya ikut berputar & lengkungnya sinkron.
- **Raycast tabung dihitung matematis** (ray vs silinder), bukan physics collider — collider primitive sengaja dibuang di `Paint()`.
- **Starting fill**: JANGAN pakai pola papan catur (isolasi sel → instant game over). Selalu jaga pengaman anti auto-clear & anti langsung-mati.
- **Edit file via GitHub API butuh kirim SELURUH isi file** (tak ada patch parsial) + `sha` blob terbaru.
