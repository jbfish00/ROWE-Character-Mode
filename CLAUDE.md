# CLAUDE.md — Pokemon ROWE "Character Mode" + 2.X rebase

Guidance for Claude Code instances working in this repo. Read this AND the
current plan (`~/.claude/plans/magical-brewing-beacon.md`) before acting.

## What this project is

A mod of Pokemon ROWE (pokeemerald decomp) on branch `character-mode`:
1. **Character Mode** (done, shipped): play as ~184 iconic characters;
   catches/gifts restricted to the character's roster; OW/back/card sprites.
2. **2.X content rebase** (in progress): port ROWE 2.0.5.x content from the
   partial official dump at `~/Documents/RoweRepo-donor` (BelialClover/RoweRepo:
   all data + maps + graphics, but only 4 engine .c files — engine logic must be
   reconstructed, never assumed copyable).

## Standing user rules (do not violate)

1. **2.X-structure-first**: before changing anything already coded, check how
   2.X structures it in the donor. If 2.X's structure requires the change,
   follow 2.X's way (e.g. `.style` field added to TrainerMon, MAX_TRAINERS_COUNT
   2000, ability ids matching donor's numbering).
2. **Checkpoint rule**: at every pause/handoff, update this file and the plan
   file so a fresh Claude instance can continue seamlessly.
3. **Never renumber existing ids** (species/items/moves/trainers): append-only
   + `#define` name aliases. Renumbering breaks saves. Donor data links by
   NAME, never by number.
4. Distribution: UPS/BPS patch only, never a prebuilt ROM.
5. Ask the user questions until 95% confident.

## Build

- `make -j$(nproc)` (agbcc, MODERN=0). NEVER `make compare`.
- agbcc lives in `tools/agbcc` (installed manually — its install.sh breaks on
  the space in this repo's path). poryscript in `tools/poryscript`.
- agbcc is C89: declarations at block top; warnings are errors.
- Output: `pokeemerald.gba` (~33MB file, ~25MB used of 32MB cap).

## Porting pipeline (tools/character_mode/)

All generators are idempotent via marker blocks (`ROWEMEGA-`, `ROWESPEC-`,
`ROWEITEM-`, `ROWEMOVE-`, `ROWESIG-`, `ROWETRN-`, `ROWENEWTRN-`, `ROWEALIAS`,
`GEN9-PORT`, `CHARMODE-`). Run order if regenerating from scratch:
`port_gen9.py` → `port_2x_species_aliases.py` → `port_rowe_megas.py` →
`port_2x_species.py` → `port_2x_items.py` → `port_2x_moves.py` →
`port_2x_signature_moves.py` → `port_2x_abilities.py` → `port_2x_trainers.py`
→ `port_2x_new_trainers.py`. Each writes a `rowe_*_report.txt`.

Recurring traps (all handled inside the scripts — keep it that way):
- Multi-array headers: insert into the NAMED array, not the file's last `};`
  (battle_moves.h also holds gSignatureMoveList; contest_moves.h holds
  gContestEffectFuncs; base_stats.h holds gVanillaBaseStats).
- A script must strip its OWN marker blocks before diffing, or re-runs see
  their previous output as pre-existing and do nothing.
- Donor `.pal` files are LF; gbagfx requires CRLF.
- Donor items/text wrap `.name`/class names in ES/EN `#if` pairs.
- Donor price macros (EVO_ITEMS_PRICE) resolve to numbers, don't import.
- gSpeciesToNationalPokedexNum is `[SPECIES_X - 1]`-indexed.
- Charmap has no `_` — never emit underscores inside `_("...")` strings.

## Testing

- mGBA (`mgba-qt`) driven via xdotool: keydown/keyup with ≥0.4s holds
  (short taps get DROPPED — verify every press with a screenshot; the
  emulator drops even held arrows sometimes; A=x, B=z, Start=Return).
- Screenshot: `import -window <game-subwindow-id>` (find via
  `xdotool search --class mgba`, pick the 480x320 child of the running
  instance; the titled 480x344 window takes the key input).
- Known intro macro: Start, A×~18, name "A" via A+Start+A, A×8 → house;
  A×2 → question menu; Down Down A → Character Mode menu (defaults to
  Gen I/Red); START commits; A, Down×3, A, A×3 → clock; A, Up, A×3;
  Meowth Yes/No; A×5; location select A×3 → overworld.
- Route 101 from Littleroot spawn: Left 1.2s, Up 2.5s, Right 0.6s, Up 3s,
  (Left 0.7s, Up 5s through the tree-row gap), grass wiggle = alternate
  Left/Right 0.45s holds.
- Fresh saves REQUIRED since the MAX_TRAINERS_COUNT change (flag block
  shifted). Delete the `.sav` next to the test ROM.
- Temp test patches go in the START-commit path of `src/ui_mode_menu.c`
  (grant party mons/items on mode commit); ALWAYS revert + rebuild clean
  after cutting a test ROM. Test ROMs live in `~/Documents/rowe_test_*.gba`.

## Current state (2026-07-11)

Phases 1-4 (partially) COMMITTED and build-clean. `git log --oneline -15`.

**Phase 3 — DONE, and PLAY-TESTED** (testing found 3 real bugs, all fixed):
- Level caps (2.X gScalingInfo table). NB 1.9.4 ALREADY had level caps; 2.X only
  changes the VALUES. Do not add a second cap system.
- Battle Styles (8 styles; storage = 3 bits freed from hidden_nature).
- Trainer Skills (core + menu). Menu = "Skills" in the FIELD start menu.
  VERIFIED in-game: renders, lists skills, shows points, closes cleanly.
- **Exiolite and the Blue Nurse suite NEEDED NO WORK** -- 1.9.4 already ships
  both (PkmnCenterJack already does tutoring/wonder trade/PC battles/costumes).
- Skill EFFECTS beyond the six IV ones + XP Boost-Trainer are still stubs.

**Phase 4 — maps + access DONE; gyms/badges NOT DONE:**
- 4.1: 107 Sevii/Kanto maps imported (633 -> 740 maps). VERIFIED in the built
  ROM: all 658 layout pointers valid (incl. the 108 new), sane dimensions, real
  blockdata; the island MapScripts symbols all resolve.
- 4.2: travel wired -- "Travel to Sevii" added to the Pokemon Center menu ->
  Colress -> ticket-gated warp. Intro grants one random ticket (FAQ #12).
  VERIFIED in-game: Sevii Tickets appear in the Key Items pocket with the right
  icon and description.
- CRIES: no work needed. 1.9.4 already ships only 23 (the other ~957 sit unused
  in sound/direct_sound_data _with_cries.inc). ROM is 23.8 MB / 32 MB.
- STILL TO DO: Johto leaders as gyms 9-16, badge count -> 16, Mega Bracelet
  7 -> 11 badges, legendary placements, Victory Road gate at 16.
- 10 scripts are STUBBED (data/scripts/sevii_stubs.inc): Alpha Pokemon,
  legendary encounters, gift mons, Mega Stone Gurus -- 2.X systems that live
  only in the donor's .pory and are out of scope for a map import. The NPCs
  exist and are interactable, they just say nothing.
- InsideOfTruck2 (2.X's alternate intro) is deliberately EXCLUDED.

**Phase 4: COMPLETE AND TESTED IN-GAME**, but only after a FULL 2.X MAP REBASE
(see below). 16-badge system, Landorus, all 8 islands startable and walkable.

## THE MAP FORMAT (read this before touching any map)

ROWE 2.X changed the map-grid bit layout engine-wide. We have now adopted it:

    vanilla:  metatile id 10 bits | collision 2 bits | elevation 4 bits
    2.X (US): metatile id 12 bits | collision 1 bit  | elevation 3 bits

2.X needed the wider id because its primary tilesets grew (gTileset_General:
512 -> 2048 metatiles) and paid for it out of collision/elevation. Decoding 2.X
map.bin with the vanilla layout truncates every metatile id (garbled tiles) and
reads collision/elevation from the wrong bits (player boxed in, cannot move).
That was the Sevii bug -- NOT the coordinates. Constants: `METATILE_ID_MASK` etc.
in `include/global.fieldmap.h`, `NUM_METATILES_IN_PRIMARY 2048` in `fieldmap.h`.

**The void marker moves WITH the id width, and the FILL must move with it.**
Every map is surrounded by a 7-tile margin (`gBackupMapData`); cells no connection
fills are set to a void marker, and every accessor tests for it. Widening the id
moved that marker 0x03FF -> 0x0FFF, but `fieldmap.c` still *filled* with the
literal `0x03ff` -- so the test never matched, the void decoded as metatile 1023 /
collision 0 / elevation 0, and **the player could walk (or surf) straight off the
edge of the map** anywhere an edge tile was walkable but outside a connection's
overlap (1169 such tiles across 36 maps; Route 106's beach by Dewford has 17).
Out there `CanCameraMoveInDirection` blocks every direction lacking a connection,
so you get boxed in -- the "ran too far into the wall" bug. `METATILE_ID_UNDEFINED`
is now *derived* from `METATILE_ID_MASK` so fill and test cannot drift again.
`RescuePlayerStrandedOutsideMap()` (fieldmap.c) rescues saves made out in the void.
Nothing else may use the exact block value 0x0FFF -- verified: no map cell does.

Because 2.X's tilesets are NOT supersets of ours, the maps had to come with the
format: **`data/maps`, `data/layouts`, `data/tilesets` and `data/scripts` are now
the donor's, wholesale.** Hoenn is 2.X's Hoenn. Do not re-import piecemeal.

Deliberately NOT taken from 2.X (each would break something):
- **field_tools** (2.X's tool-based field moves). We keep HM/badge field moves;
  our engine C calls our `EventScript_CutTree` etc. Consequently the six badge
  rewards that hand out those tools (BADGE_ITEM_01/02/04/06/07/10 in
  `data/scripts/gym_scripts.pory`) are swapped for working items. Mega Bracelet
  stays at badge 11.
- **the runtime starter list.** 2.X's `generateStarters` builds it and the script
  passes SPECIES_NONE to showmonpic/givemon for 2.X's engine to resolve. Ours
  takes that literally -> species 0 -> CRASH on picking a starter. We use the
  fixed list (script_menu.c `sSet1` + `Script_Give_StarterN`).
- **the questions-menu indices.** 2.X dispatches Start Game at case 2; our menu
  has "Character Mode" there, so Start Game is case 3. Get this wrong and Start
  Game silently loops back.
- **SCROLLING_* ids.** 2.X's numbering differs from our `sScrollingSets` order
  (its STARTERS=0/TOWNS=1, ours is reversed). The names are defined in
  `include/constants/global.h` mapped to OUR indices. Never copy 2.X's values.

**Phase 5 (QoL/quests/achievements/NG+): NOT STARTED.**

**Phase 4 is now VERIFIED IN-GAME, end to end:** a full 2-Pokemon trainer battle
(moves, flinch, KO, switch-in, EXP, prize, defeat flag); white-out -> respawn;
save -> reload; map connections; the start-location chooser; the **Blue Nurse menu**;
the **Colress ticket chain** (menu -> Colress -> pick an island -> "put away Sevii
Ticket 1" -> teleport, island renders); a **gym badge reward** (beat Roxanne ->
Stone Badge -> Amulet Coin, i.e. BADGE_ITEM_01); **mega evolution** (Venusaur +
Venusaurite + Mega Bracelet -> START on the move menu -> Mega Venusaur); catching;
the Pokedex; badge-driven **level scaling** (wild mons Lv7-8 at 0 badges -> Lv9-11
at 1 badge).

**RUNTIME-UNTESTED:** Battle Styles; ability effects; most new move effects.

## Testing: how to actually drive the game

Do not fight the emulator blind -- this cost hours. What works:

- **Start on the island you want to test.** New game -> starter -> "What location
  would you like to start in?" -> scroll past "Surprise Me" to the 8 islands
  (indices 16-23). No need to play to the Sevii ferry.
- **Debug menu**: Start -> then **Select** (the field Select button alone is just
  "register an item"). That opens Save/Skills/Debug/Exit. `Debug_ShowMainMenu()`
  was dead code until wired up; its Utilities > Warp reaches any map. NB ROWE's
  *graphical* start menu is a fixed 8-slot grid with no room for new entries; the
  classic list menu only opens in dark caves.
- **READ THE PLAYER'S EXACT COORDS OUT OF THE SAVE.** Do not guess position from
  screenshots -- this is what finally made the void bug provable. Save in-game,
  then: each 4096-byte block of the `.sav` has a footer at +0x0FF4 =
  `u16 id, u16 checksum, u32 signature(0x08012025), u32 counter`. The block whose
  `id == 1` is the first SaveBlock1 chunk, and SaveBlock1 *starts* with
  `struct Coords16 pos`, so its first 4 bytes are `s16 x, s16 y`. (Two save slots
  alternate: sectors 0-13 and 14-27. Take the higher `counter`.)
- **mGBA input**: synthetic X events only deliver **letter keys** -- Return,
  arrows and Backspace never arrive. `~/.config/mgba/config.ini` [gba.input.QT_K]
  is rebound to: A=x B=z Up=i Down=k Left=j Right=l Start=m Select=n.
  Send with `xdotool keydown --window <child> KEY` (XSendEvent); plain XTEST does
  not reach it. **Menus: tap ~0.08s** (longer repeats and blasts through them).
  **Field movement: taps get DROPPED -- hold instead**, ~0.27s per tile
  (`keydown; sleep 0.9; keyup` walks ~3 tiles). Screenshot after every move; NPCs
  wander into you and trainers' sight lines start battles you did not plan for.
- Screenshot the 480x344 child window: `import -window <id> out.png`. Screenshot
  after *every* keypress in debug menus; they remember cursor positions, so blind
  key counts land in the wrong submenu.
- `pkill -f mgba` kills your own shell (the pattern matches the bash command
  line). Use `pkill -x mgba-qt`.

## Donor facts

- `~/Documents/RoweRepo-donor` (persistent clone; scripts default to it via
  `ROWEREPO_DONOR` env var).
- Donor trainer ids 852+ COLLIDE with ours — never adopt donor trainer ids.
- Donor moves ids matched ours exactly; species/items/abilities mostly match
  by NAME with ~110 spelling divergences handled by `ROWEALIAS` block in
  `include/constants/species.h`.
- Sevii/Kanto maps (Phase 4) exist complete in donor `data/maps/`; ~8 specials
  missing from our engine (see plan).
- **Donor `.pory` files declare scripts as `script Name{`, NOT `Name::`.** A
  `grep '^Name::'` will report a script "missing from the donor" when it is
  actually there. This wrongly wrote off the Landorus/Alpha/gift scripts once.

## The 2.X-data-on-an-old-engine bug class (read this)

Every bug in the rebase had the same shape: **2.X's data encodes something our
engine decodes differently, or assumes an engine feature we lack.** None fail the
build. Found and fixed so far:

- **`METATILE_*` constants name TWO different formats.** The map-grid BLOCK (2.X
  changed it) and the metatile ATTRIBUTE word (2.X did not). They agreed in vanilla
  only by coincidence -- the old elevation field (`0xF000 >> 12`) sat exactly where
  the attribute LAYER field is. `include/global.fieldmap.h` now keeps them apart
  (`METATILE_ATTR_BEHAVIOR/LAYER_*`). Get this wrong and every tile draws with the
  wrong layer type.
- **Elevation "cross any level" sentinel is 7 (`MAX_ELEVATION_LEVEL`), not 15.**
  3-bit field. Checking `0xF` matches nothing, so every transition tile blocks the
  player (bridges, cycling road).
- **Secondary-tileset metatile base is 2048, not 512.** Any hardcoded `0x200`, and
  any raw metatile literal, is wrong. Use the `METATILE_*` labels.
- **A MAPSEC must be < `MAPSEC_NONE`.** `gRegionMapEntries[]` is indexed UNGUARDED;
  a mapsec past the end divides by a garbage width. (`MAPSEC_EIGHT_ISLAND` was 0xD6.)
- **`SPECIES_NONE` in 2.X scripts means "resolve at runtime"** from the list its
  `generateStarters` builds. We have no such list -> species 0 -> crash. Our
  `ScriptGiveMon` has its own randomize sentinel: **`SPECIES_MEW`**.
- **porymap writes `dest_warp_id` as a STRING.** `tools/mapjson` called
  `int_value()` on it, which returns 0 -- so **997 of the game's 1700 warps** sent
  the player to warp 0 of the destination map (every building exit, Hoenn included).
- **Save blocks silently truncate.** `save.c` clamps each chunk with `min()` and
  checksums only the clamped bytes: an oversized block writes a VALID checksum over
  a TRUNCATED payload. SaveBlock2 had been over by 204 bytes and quietly dropping
  `roamerFlag[]` + option bits. There are now `STATIC_ASSERT`s on all three blocks --
  **never remove them.**

## Traps that have bitten more than once

- **Hardcoded counts vs grown data.** Six instances so far: `gBattleAnims_Moves`
  (the Trick-o-nome crash), `sScrollingSets`, the badge-indexed scaling arrays,
  `NUM_SOFT_CAPS`, `MAP_GROUP_COUNT[]` in debug.c (216 maps unreachable), and
  `bg_event` packing hiddenItemId into a **byte** (fine under 256 hidden items;
  2.X has thousands, so ids truncated 0xBEC -> 0xEC and collided).
  When you grow a data set, grep for every array sized to the old count --
  including ones in **assembly** and in **debug/tool code**.
- **A sentinel changed, but the code that WRITES it did not.** Same shape as the
  above, one level nastier: widening the metatile id moved the map-grid void
  marker 0x03FF -> 0x0FFF and every *reader* was updated, but the three
  `CpuFastFill`s in fieldmap.c still wrote the old literal. Readers and writers of
  a magic value must share one constant -- never a literal on either side. This
  let the player walk off the edge of the map (see THE MAP FORMAT above).
- **Movement is symmetric, so a walled-in tile you can REACH was entered one-way.**
  When "I'm stuck and can't move" is reported, the entry was a warp, a ledge jump,
  a Surf dismount, or walking off the map. Scan those four; do not scan for
  "tiles with no exit" (there are hundreds, and they are simply unreachable).
- **A C flag test whose flag NOTHING SETS.** `GetNumBadges()` (level_scaling.c --
  the index into EVERY scaling table) read the gym leaders' TM flags
  (`FLAG_RECEIVED_TM39` -> 1 badge, ...). No script sets them: the gyms hand the TM
  over with `giveitem`, which does not flag it. So it returned 0 for the whole Hoenn
  game and the game never got harder. `battle_util.c`'s mega gate had the SAME bug
  (`FLAG_RECEIVED_TM04`), which is why item megas were dead. **When a gate reads a
  flag, grep for a `setflag` of it.** Both now read the real badge flags.
- **Menu list (C) vs script case index (data) must agree, and nothing checks that.**
  `scrollingmultichoice`/`multichoice` pass the chosen ROW INDEX to the script, which
  switches on it. The lists live in `src/script_menu.c` (ours); the switches live in
  `data/scripts/*.pory` (2.X's, since the rebase). When the rebase replaced the
  scripts, every menu silently re-pointed: the Blue Nurse ran the wrong action for
  every entry, and the ferry's "Cancel" (index 10) meant SAIL_TO_NAVEL_ROCK. Audit
  script by script: `tools/` has no checker, so this is a grep-and-read job.
- **The import only copied maps we LACKED.** Donor edits to maps we already had
  were silently skipped -- that is how Colress went missing on islands 1-4 (the
  ticket chain dead-ended) and why 102 objects were absent. The full rebase fixed
  this; if you ever import selectively again, remember it.
- **`data/maps/*/scripts.inc` is GENERATED by poryscript from `scripts.pory`,
  and is gitignored.** Editing the .inc appears to work until the next clean
  build silently wipes it. Edit the `.pory` -- and new asm must go *inside* the
  file's `raw \` \`` block. (`data/scripts/*.inc` have no .pory and ARE sources.)
- **Check the 1.9.4 base before building anything.** Already present and nearly
  re-implemented by mistake: mega stone distribution, Exiolite, level caps, the
  Blue Nurse suite, the debug menu, and the **start-location chooser** (it only
  needed the islands appended).
- **Never renumber** species/items/moves/trainers/heal-locations -- append + alias.
