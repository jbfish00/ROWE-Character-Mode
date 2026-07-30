# Character Mode — Art Credits

Character Mode's playable-character sprites are adapted from the following
games, decompilation projects, and fan works. Huge thanks to every artist.
This mod is distributed as a patch only, never as a prebuilt ROM.

## Base game / engine
- **Pokémon R.O.W.E.** by rioluwott and contributors (pokeemerald base).
- **pret/pokeemerald** decompilation and **pokeemerald-expansion**
  (RHH) — engine, Gen 9 species data.

## Overworld & trainer sprites
- **pret/pokefirered** — FRLG overworld sprites and trainer fronts for
  Kanto characters (Lorelei, Agatha, and Gen I trainer portraits).
- **sinnoh-remakes/pokeemerald-platinum** — Gen IV (DPPt) overworld
  sheets and DP trainer fronts (Lucas, Dawn, Cynthia, gym leaders,
  Elite Four, Team Galactic).
- **PokemonHnS-Development/pokemonHnS** — HGSS-style overworld sheets and
  trainer fronts for Johto characters (Ethan, Kris, gym leaders, Elite
  Four, Team Rocket executives) and HGSS-style walking upgrades for the
  Kanto cast.
- **DiegoWT — "Gen 5 Characters in Gen 4 OW style"**
  (https://eeveeexpo.com/resources/370/) — Unova cast overworld sprites
  (Hilda, Nate, Rosa, gym leaders, Elite Four, rivals, Team Plasma).
  Downscaled 0.5x to GBA proportions for this mod. Credit required by
  the resource terms; please keep this notice with any redistribution.

- **StreakOfSprites** (https://www.deviantart.com/streakofsprites) —
  Ash Ketchum FRLG-style overworld sprite set
  (tools/character_mode/donor_sheets/ash_streakofsprites.png).

## Trainer card badges
- **pret/pokecrystal** decompilation — the eight **Johto badge** shapes on the
  trainer card's second row (`graphics/trainer_card/badges_johto.png`), converted
  from that project's own `gfx/trainer_card/badges.png`. The source art is 2bpp
  and renders through a near-greyscale palette upstream; the four shades are
  remapped onto a gold ramp here. The Hoenn and Kanto badge sheets are
  pokeemerald's and pokefirered's own.

## Rosters
- Character Pokémon rosters compiled from **Bulbapedia**
  (https://bulbapedia.bulbagarden.net), CC BY-NC-SA.


## Emerald Rogue — trainer, back and overworld sprites (added 2026-07-25)

Staged in `sprites/donors/rogue/` — 294 sprites covering 160 Character Mode
characters (149 trainer front pics, 133 overworld sheets, 12 battle back pics),
filtered from a 531-file harvest down to characters actually on the roster.

- **Source**: https://github.com/Pokabbie/pokeemerald-rogue, branch `vanilla`,
  commit `79c1df5f8a2ebb423c7a48d29de0cf21ef5783e7`, fetched 2026-07-25.
- **Format**: converted from the repo's PNGs by `tools/png_to_gba.py` into
  `.4bpp` + `.gbapal` and LZ77 (BIOS type 0x10) streams of each. Every blob was
  round-tripped through the decompressor before staging.
- **Licensing**: the repository has **no LICENSE file**. Its in-game credits
  roll is the only attribution trail that exists, and it maps no artist to any
  individual file — so the **whole list travels with any subset of the art**.

**"Additional Sprites" — Emerald Rogue credits roll, reproduced in full:**

AveonTrainer · PurpleZaffre · UlithiumDragon · HighNoonMoon · xDracolich ·
ZacWeavile · Gnomowladny · Beliot419 · Brumirage · Kyledove · Kymotionian ·
cSc-A7X · 2and2makes5 · Pokegirl4ever · Fernandojl · Silver-Skie · Kid1513 ·
TyranitarDark · Getsuei-H · Milomilotic11 · Kyt666 · kdiamo11 · Chocosrawloid ·
SyleDude · Gallanty · Gizamimi-Pichu · princess-phoenix · LunarDusk6 ·
Larryturbo · Kidkatt · Zender1752 · SageDeoxys · Lasee0 · Ezerart · Wolfang62 ·
DarkusShadow · Anarlaurendil · Lasse00 · shaderr31 · CarmaNekko · EduarPokeN ·
TintjeMadelintje101

Plus the Emerald Rogue project itself (Pokabbie) for assembling and converting
the set.


## Team Aqua's Asset Repo, pokemonHnS, pokeemerald-platinum (added 2026-07-25)

Three more donor sets staged alongside `rogue/`, converted by
`tools/png_to_gba.py` and filtered to characters on the Character Mode roster.

### `sprites/donors/taar/` — 251 sprites, 92 characters
- **Source**: https://github.com/TeamAquasHideout/Team-Aquas-Asset-Repo, branch
  `main`, commit `36b619ecd1d2df95212b375c95803af78414f78a`, fetched 2026-07-25.
- **Licence** (repo README, verbatim): *"This is a collection of free to use
  assets that are intended to be used for Generation 3 Pokémon decomp hacking...
  All assets are both free to use and edit by default, but if any assets
  specifically mention not being free to edit, please respect the author's
  wishes... provided they are submitted alongside credit to their original
  creator."*
- **Attribution is per-author and mandatory.** The second path element of every
  upstream file IS the author — `Trainer Back Sprites/yoshord/…` is yoshord's
  work. `harvest_index.json` in the staged directory preserves each file's
  original path, so the author is always recoverable. Named contributors whose
  work is staged here include **yoshord** (Lance back, 64x384 six-frame — his
  README ships the matching `sAnimCmd_Lance_Back[]`), **ShinyDragonHunter**
  (Blue/Gary back, 64x320), **spilledpizza** (Prof. Rowan overworld, Cynthia
  mugshot), **Phantomony** (Archie mugshot), **mudskip** (Phoebe back),
  **Kalarie** (anime front pics), **Ringloom** (HGSS Lyra), **kwenio**, **Lhea**,
  **KyuZee**, **hyo**, **Solo993**.
- Aggregate folders re-credit upstream creators per subfolder — read the
  author's own README before shipping any single sprite.

### `sprites/donors/hns/` — 41 sprites, 30 characters
- **Source**: https://github.com/PokemonHnS-Development/pokemonHnS, branch
  `main`, commit `751823abaf677020bcd72c45fe3e7cb2b8a576e4`.
- HGSS-style 64x64 front pics; covers **Lance, Blue, Misty, Brock**, Red, Karen,
  Clair, Giovanni, Sabrina and the Johto/Kanto leaders and Elite Four.
- **Licence**: no LICENSE file. README, verbatim: *"it's also completely open
  source, and is intended to be a base for a new generation of Johto rom
  hacks"* / *"If you'd like to improve, expand upon, or make your own version of
  HnS, feel free to take advantage of the open source!"*
- **Sprite credit** (flat, no per-file attribution available):
  **Cesare_CBass, AveonTrainer, PurpleZaffre, BatimaTheBat**.

### `sprites/donors/platinum/` — 49 sprites, 36 characters
- **Source**: https://github.com/sinnoh-remakes/pokeemerald-platinum, branch
  `master`, commit `09091ed1d8c07c3353608ac91603ac59ab41fc70`.
- Covers **Cynthia**, **Cyrus**, Dawn, Lucas, Barry, Bertha, Lucian, Volkner,
  Candice, Maylene, Fantina, Roark, Byron, Crasher Wake, Mars/Jupiter/Saturn.
- **⚠️ Weakest attribution of the three.** No LICENSE, no asset licence, and no
  per-sprite attribution at all; the README is the inherited RHH one
  (*"If you use pokeemerald-expansion, please credit RHH (Rom Hacking
  Hideout)."*). It is a fan remake, so some art may be third-party redistributed
  without individual credit. **Prefer the TAAR version of a character where one
  exists with a named author**, and treat this set as the fallback for the
  Sinnoh cast.


## Pokesho, kalarie, LouLilie — anime and rival art (added 2026-07-25)

### `sprites/donors/pokesho/` (27 front pics) and `sprites/donors/pokesho_field/` (19 frames)
- **Source**: ポケしょ / Pokesho, by ポケモア (Pokemore) — http://www.pokesho.com
  **Both galleries are retired from the live site**; retrieved from the Wayback
  Machine capture of **2018-08-15** (bulk archives `img_zip/icon_battle.zip` and
  `img_zip/f_chara.zip`), 2026-07-25.
- **Licence, verbatim from the archived gallery**:
  「GBA風トレーナードット絵を展示しています。**フリー素材になります**。」
  ("GBA-style trainer pixel art is exhibited here. **These are free
  materials.**") and 「すべて64×64サイズ。透明色合わせて最大16色です。
  **素材としての使用も可能です**。」 Site FAQ: 「素材もらってもいいですか！？」→
  「**どうぞどうぞ！！**」 ("May I take the materials!? — **Please, go right
  ahead!!**")
- **Credit as**: 「ポケしょ / Pokesho（ポケモア）」
- **Ethical note kept deliberately**: the permission above was granted while the
  galleries were published, and the author has since retired them, stating he
  removes work he considers lower quality. This art is used on archived
  permission. If he ever asks for it to be withdrawn, honour that.
- `pokesho_field/` is **reference-only** — 16x22 single front-facing frames, not
  tile-aligned and not injectable without someone drawing the side and back
  frames. Staged because it is the only existing GBA-style art for **Paul,
  Zoey, Nando** and a **solo James**. See that directory's README.txt.

### `sprites/donors/kalarie/` — 69 anime overworld sheets
- **Source**: kalarie, PokéCommunity thread 407124 ("Fire Red Overworld Sprite
  Resource"), anime section. 144x32 (one 160x32) nine-frame FireRed NPC sheets.
- **Licence, verbatim**: *"You're free to use any of these sprites in your hack,
  that's the whole purpose of this resource. Be sure to give proper credit
  though."*
- **Credit**: **Kalarie** (all anime sprites); **Pokesho** (various first frames
  — kalarie animated Pokesho's front frames into full sheets, and says so).
- **Technical caveat**: these do not all fit FireRed's default palettes and need
  Navenatox's Dynamic Overworld Palettes patch.
- **Identification caveat**: the sprites are unlabelled at source. Only
  **Misty, Brock, Jessie and James** are confidently matched to roster
  characters; the other 65 are staged honestly as `anime_npc_*` rather than
  guessed at. `CONTACT_SHEET_front_frames.png` is included for a human ID pass.

### `sprites/donors/loulilie/` — 4 sprites
- **Source**: LouLilie, DeviantArt — "FRLG Rival Green as Player" and "FRLG
  Player Blue LGPE Design".
- **Licence, verbatim**: *"Feel free to use in your projects with credit!"*
- **Credit**: **LouLilie**
- Provides a second **Blue/Gary back pic** (64x320, 16 colours) extracted from a
  pixel-perfect 2x sheet, alongside the TAAR/ShinyDragonHunter one. One
  documented judgement call: the five aligned frames span 68px, so the window
  chosen keeps four frames pixel-complete and clips only the tip of a thrown
  Poké Ball leaving frame 4 — which is how FRLG back pics behave anyway.

### `sprites/donors/ashgray/` — 19 trainer front pics (added 2026-07-26)
- **Source**: **Pokemon Ash Gray v4.5.3**, a FireRed hack by **metapod23**.
  The art was ripped from a ROM built locally from the project's own BPS patch
  applied to a byte-matching `pret/pokefirered` build — no ROM was downloaded
  and none is redistributed. Provenance and the rip method are recorded in
  `sprites/donors/ashgray/README.md`; `manifest.json` carries each sprite's
  index in that game's own front-pic table.
- **Credit**: **metapod23**.
- **Why it is here**: anime-arc characters that exist in no other donor set.
  Of the 19, four fill Character Mode slots nothing else could — **Gary**,
  **Ritchie**, **Tracey** and **Jessie & James** (a duo pic, which is how that
  game draws them). The rest are anime-styled alternates of characters who
  already have game art, and are deliberately NOT used: the importer skips any
  character that already resolves to a TRAINER_PIC, so `brock_anime` and
  friends sit unused rather than overriding the canonical portraits.

---

## Greenphx, MrDollSteak's thread, and one unattributed sprite (added 2026-07-29)

Nine front pics staged from the 2026-07-28 harvest
(`../Character Hacks/art_harvest_2026-07-28/rowe/`), which measured and credited
them but deliberately staged nothing, leaving two calls to a human. Both were
made on 2026-07-29 and both are recorded at the point of use.

Four of the nine — **Ghetsis, Kiawe, Lana, Mallow** — are **Emerald Rogue** art
from the same commit (`79c1df5f`) as the set already credited above; they were
simply missed by the 2026-07-25 staging filter. **The 42-name "Additional
Sprites" roll reproduced in that section covers them**; no new credit is owed,
but the omission is noted so the count is not mistaken for new sourcing.

### `sprites/donors/greenphx/` — 2 front pics (Argenta, Dahlia)
- **Source**: Greenphx, "GBA (64x64 + 16-colour) Trainer Sprites!",
  PokeCommunity thread 463927. The thread is Cloudflare-403 to automated
  fetching; it was read through a Wayback capture, and the MediaFire archive
  host served the `.rar` directly.
- **Licence, verbatim** (thread OP): *"Also, if you do use these, I'd like
  credits, but they aren't required."* And from the archive's own `readme.txt`:
  *"All sprites shrunk by Greenphx. … Please give credits if used. Not required
  tho."*
- **Credit**: **Greenphx** for the 80x80 → 64x64 / 16-colour conversion, which
  is the work that makes these usable at all; **The Spriters Resource** for the
  DS-era rips underneath (HGSS sheet 28037 / Platinum fullview 18524).
- Credit is not contractually required here. This project credits anyway.

### `sprites/donors/dollsteak/` — 1 front pic (Lillie)
- **Source**: MrDollSteak's "The DS-Style 64x64 Trainer Sprite Resource",
  PokeCommunity thread 308798; the sprite was contributed to that thread by
  **Shinya-kun & Mika-kun**.
- **Licence, verbatim** (thread OP, MrDollSteak): *"you **ARE** allowed to use
  these for your hack, this is the entire point of the resource! Just make sure
  you credit this thread if you do use any of the sprites."*
- **Credit**: **Shinya-kun & Mika-kun** (the sprite) and **MrDollSteak** (the
  resource thread the grant comes from).
- ⚠️ **The grant is the thread OWNER's, not the contributor's.** The thread's
  stated purpose is a shared free-to-use resource and the sprite was posted into
  it, so the grant reasonably reads as covering it — but that inference is ours.
  Same judgement class as the Pokesho set above. **If either artist asks for
  withdrawal, honour it.**
- ⚠️ The file was **indexed by this project**, not taken as-is: the
  contributor's own indexed attachment is HTTP 403 and absent from the Wayback
  Machine, so the only reachable copy was the forum CDN's re-encoded truecolour
  one. The conversion is lossless, not a quantisation — the source holds exactly
  16 distinct fully-opaque colours, and the converter asserts that rather than
  guessing. `sprites/donors/dollsteak/lillie_rgba_source.png` is the unmodified
  download, kept so the conversion stays auditable.

### `sprites/donors/unattributed/` — 1 front pic (Colress)
- **Source**: https://github.com/fakuzatsu/verdant — a personal fork of
  rh-hideout/pokeemerald-expansion.
- **Licence**: **NONE STATED.** No LICENSE file, no per-sprite credit, and the
  commit that introduced the art says only *"add various sprites"*. Upstream
  pokeemerald-expansion ships no Colress front pic, so the art entered at the
  fork and the trail ends there.
- **Credit**: **artist unknown**; via github.com/fakuzatsu/verdant.
  **If you drew this, we would like to credit you properly — please get in
  touch.**
- ⚠️ **This is the weakest provenance in the project and it is shipped
  knowingly**, on an explicit user decision (2026-07-29) to take it with an
  honest credit rather than leave Colress portrait-less. It is the same defect
  for which *SwSh Ultimate Plus* was rejected as a primary source, so it is
  quarantined rather than folded into a neighbouring set: the directory is named
  `unattributed`, and it sits **last** in the importer's `PREFERENCE` order —
  below `platinum`, previously the weakest — so it can never outrank a source
  that can name its artist. Stage an attributed Colress anywhere else and it
  wins automatically.
- A second copy of the same artwork exists at ProfLeonDias/Pokeemerald-Expansion
  with the same problem; it was **not** staged, so no importer is given a silent
  choice between them.

### Thorton — a deliberate choice between two clean sources
Thorton was available from both Greenphx's pack and **Team Aqua's Asset Repo**.
TAAR's was taken (artist: **BrandonXL**, already credited in the TAAR section
above), because TAAR carries an explicit free-to-use grant *and* a named creator
per folder — the strongest licence position of any set staged here. Greenphx's
Thorton was **deliberately not staged**, so `PREFERENCE` order never gets to make
that call silently.

### Not new art at all — the seven Frontier Brains
**Anabel, Brandon, Greta, Lucy, Noland, Spenser and Tucker** also gained
portraits on 2026-07-29 and are **vanilla Emerald Battle Frontier art already in
this tree** — already covered by the base-game credit at the top of this file.
They were listed as "no art of any kind" for months only because the asset
name-matcher never tried their facility titles (`TRAINER_PIC_SALON_MAIDEN_ANABEL`
and friends). Nothing was sourced, converted or added; seven constants were.

---

## Overworld sheets and battle back pics (added 2026-07-30)

`tools/character_mode/import_donor_ow_backs.py` filled the other two asset slots
from art that had been staged in `sprites/donors/` and unreachable, because the
only tool that read that directory did front pics alone. **27 overworld sheets**
(101 → 128 of 236) and **7 battle back pics** (12 → 19 of 236). No new donor
*sets* were harvested; everything below is already licensed under a section
above, except `taar_gap/`, which is new to this tree and detailed at the end.

Nothing here is a drop-in copy. Each overworld donor is a 9-frame NPC strip and
the player avatar needs an **18-frame** sheet (`build_ow_sheet`-style), so every
one was re-laid-out; each back pic was re-framed to the 4- or 5-frame throw
animation the engine plays, and one was quantised.

### Overworld — Emerald Rogue (`sprites/donors/rogue/`), 16 characters
Lyra (walk **and** run), Calem, Serena, Elio, Selene, Victor, Gloria, Oak,
Birch, Anabel, Brandon, Greta, Lucy, Noland, Spenser, Tucker. Licence and the
full "Additional Sprites" artist list are in the Emerald Rogue section above;
that list travels with any subset of the art.

### Overworld — Team Aqua's Asset Repo (`sprites/donors/taar/`), 7 characters
Korrina, Acerola, Nessa, Bede, Larry, Palmer, Rowan.
- **Rowan** — artist **spilledpizza**, whose folder README carries its own
  credit list, reproduced here as it must travel with the file: *"spilledpizza
  (myself) / TheWiggliestJiggliest / RichardPT / robloxmaster376 / The Spriters
  Resource / The Radiant Quartz / Prismatic Platinum team for their support."*
- ⚠️ **The other six cannot be attributed to an individual from this tree, and
  TAAR's licence requires it.** TAAR is organised `<asset type>/<creator>/…`, so
  the upstream path IS the attribution — but the 2026-07-25 staging pass flattened
  the filenames and `manifest.json` records only the flat staged name. The
  `harvest_index.json` that the TAAR credit block above says "preserves each
  file's original path" **is not present in `sprites/donors/taar/`.** Until it is
  recovered (re-fetch the tree at commit `36b619ec…` and match by content), these
  six are credited to **Team Aqua's Asset Repo contributors** collectively, which
  is weaker than the licence asks for. **This is a known debt, recorded rather
  than papered over.**

### Overworld — kalarie (`sprites/donors/kalarie/`), 2 characters
**Jessie** and **James**, from kalarie's PokéCommunity anime overworld set —
the only GBA-style overworld art of the Team Rocket duo anywhere searched.
Credit **Kalarie**, and **Pokesho** for the front frames kalarie animated (both
per the kalarie section above).

### Back pics — Team Aqua's Asset Repo, 3 characters
- **Blue** — **ShinyDragonHunter** (64x320, five frames, FRLG throw).
- **Lance** — **yoshord** (64x384, six frames). ⚠️ **Re-framed, deliberately.**
  His sheet has one extra intermediate arm-raise (frame 3) that the engine's
  five-frame FRLG animation has no slot for, so frames 0,1,2,4,5 are taken and
  frame 3 is dropped. yoshord's own README ships a matching six-frame
  `sAnimCmd_Lance_Back[]` upstream, which was **not** harvested with the art; if
  it is ever fetched, a six-frame path is the better answer than this crop.
- **Phoebe** — **mudskip** (64x256, four frames, Emerald throw).

### Back pics — Emerald Rogue, 3 characters
**Lyra**, **Calem** and **Serena** (64x320, five frames each). Same collective
credit list as the overworld set above.

### `sprites/donors/taar_gap/` — TAAR gap-fill pass (NEW to this tree)
Five files from the 2026-07-28 harvest
(`../Character Hacks/art_harvest_2026-07-28/rowe/taar_gap/`), staged here on
2026-07-30. Same repository and licence as `taar/` above
(github.com/Pawkkie/Team-Aquas-Asset-Repo, commit `36b619ec…`) — free to use and
edit, **credit to the original creator required** — but unlike `taar/` this set
kept its per-file artist, so it ranks ABOVE `taar/` in the importer's
`PREFERENCE`. Its own `CREDITS.txt` travels with it.
- **`elm_ow.png`** — Professor Elm overworld, artist **IAG**, whose README asks:
  *"If you use any of these sprites, please credit IAG."* **Used.**
- **`kiawe_ow.png`** — Kiawe overworld, artist **PurrfectDoodle (Eva)**, whose
  README asks: *"Please credit PurrfectDoodle (Eva) :)"*. **Used.**
- **`noland_back.png`** — Noland back pic, artist **kwenio**. **Used, and
  QUANTISED.** It ships 64x256 (correct geometry) but as fully-opaque RGBA with
  **56 distinct colours** against 4bpp's 16. The deliberate call, recorded in the
  importer's `QUANTISE` table: mask every pixel within 8/255 per channel of the
  corner colour to palette slot 0 (the backdrop is opaque, so alpha cannot do
  it, and a backdrop anywhere but slot 0 renders as a solid box behind the
  player), then MEDIANCUT the remaining 54 colours to 15 with **dithering off**.
  Compared against the original as a decoded contact sheet before shipping: the
  hat, glove, vest and skin ramps all survive; the loss is one step of forearm
  shading. The importer refuses to quantise any file not named in that table.
- **`birch_ow_hyo.png`** (artist **hyo**) and **`rowan_ow_spilledpizza.png`**
  (artist **spilledpizza**) are staged but **NOT used** — Birch and Rowan resolve
  to `rogue/` and `taar/` first, and the importer matches exact filenames so an
  `_hyo`/`_spilledpizza` suffix can never be picked silently. Recorded here
  because the art is in the tree.
