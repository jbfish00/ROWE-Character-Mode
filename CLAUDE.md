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

## Phase 5 (the deferred 2.X systems) — audited; most were already there

Audit result: far less was missing than the old notes claimed. The **full 2.X rebase
already brought the real scripts** — `data/scripts/sevii_stubs.inc` is GONE, and
`alpha_mon_scripts.pory` / `legendary_mon_scripts.pory` / the gift-mon and Mega Stone
Guru scripts are all live. What was actually missing was **C support for the flags
those scripts raise** — the same "gate reads a flag nothing implements" shape as the
badge bug.

- **Alpha bosses — FIXED.** `SetAlphaDefaultData` raises `FLAG_ALPHA_CREATION` before
  `setwildbattle`, but no C read it, so all **21** Alpha encounters (the ones that award
  the mega stones) spawned as ordinary wild Pokemon with random IVs. `CreateBoxMon` now
  gives them perfect IVs, cleared one-shot alongside `FLAG_SHINY_CREATION`.
- **Alpha portals — already work.** `FLAG_DISABLE_PORTALS` is the object's *visibility
  flag* in map.json, and `Common_Eventscript_Enable_Alphas` clears it at 11 badges. No C
  needed. Do not "fix" this.
- **Quests/achievements — already work.** `src/quests.c` is one of the donor's four
  engine files and `QuestMenu_Init` is reachable from the start menu.
- **Mega Stone Gurus — already work.** They sell stones for BP, gated on
  `FLAG_GOT_BADGE_11` (via the `FLAG_UNLOCK_MEGA_STONES` alias).

Still open, with the reason:
- **Seasons cannot be ported from the donor.** `VAR_CURRENT_SEASON` is written by the
  picker but has **no C reader**, and the donor ships **no season graphics or palettes**.
  2.X's seasonal visuals live in engine code we do not have. The picker is honest about
  storing your choice and nothing more.
- **"Change Date" is inert.** `VAR_OVERWORLD_SPECIALS` / `SPECIAL_SET_DATE` /
  `FLAG_SYS_RESET_DATE` have zero consumers. It still says "You Changed the Date!".
  Either implement the RTC offset or drop the menu entry (index 8 of `sSetBlueNurse`,
  which must stay in step with `pkmn_center_jack.pory`).
- **Juan's rematch escalation is a 2.X DATA bug.** `SootopolisCity_Gym_1F` picks his
  rematch party with `goto_if_unset FLAG_RECEIVED_TM42 / TM40`, but 2.X changed the
  badge 3-6 gym TMs, so those TMs are never given by anyone. He always uses the weakest
  party. (Our gyms also never `setflag` the TMs they *do* give.)
- **`VAR_BOSS_BATTLE_HP_MULTIPIER` is only ever set to 100** (= 1.0x), so implementing it
  would be a no-op. Deliberately skipped.
- **Trainer card shows only the Hoenn 8 badges** — the Johto 8 need new art and a second
  row (badge tiles run 192..223 and the row is 22 tiles wide).

**Phase 4 is now VERIFIED IN-GAME, end to end:** a full 2-Pokemon trainer battle
(moves, flinch, KO, switch-in, EXP, prize, defeat flag); white-out -> respawn;
save -> reload; map connections; the start-location chooser; the **Blue Nurse menu**;
the **Colress ticket chain** (menu -> Colress -> pick an island -> "put away Sevii
Ticket 1" -> teleport, island renders); a **gym badge reward** (beat Roxanne ->
Stone Badge -> Amulet Coin, i.e. BADGE_ITEM_01); **mega evolution** (Venusaur +
Venusaurite + Mega Bracelet -> START on the move menu -> Mega Venusaur); catching;
the Pokedex; badge-driven **level scaling** (wild mons Lv7-8 at 0 badges -> Lv9-11
at 1 badge).

**RUNTIME-UNTESTED:** Battle Styles; ability effects; most new move effects; **the Alpha
BATTLE** (see below).

## Systems test pass (2026-07-12)

**PROVEN IN-GAME:** the costume menu (all 101 character sprites; wore Ghetsis, restored a
base outfit, redraws in place); the move tutor (**500 -> 496 BP** for an Egg move); the ferry
at Slateport (Lilycove leads the list, **Cancel exits** instead of sailing you to Navel Rock,
sailed to One Island and it rendered); the Mega Stone Guru (**500 -> 300 -> 100 BP**, then
"You don't have enough BP."); the badge count reading **16**; the **Alpha portal rendering**
at 16 badges (Alpha Scrafty visible at FiveIsland_Meadow (12,23)); white-out -> respawn;
Character Mode keeping an off-roster-looking-but-allowed mon (Charizard, since Charmander is
on Red's roster) and correctly skipping the starter grant.

**The fossil menu needs no test** -- audited exhaustively: 15 fossils + Cancel, every case
index matches, every species correct (incl. the four Galar two-item combos), `default:` present.

**Alpha bosses: PROVEN.** Caught an Alpha Starmie; its summary Skills page reads
**31/31/31/31/31/31** with **Perfect IVs mode OFF** -- so those are the real IVs from
`CreateBoxMon` setting `fixedIV = 31` on `FLAG_ALPHA_CREATION`, not a display override.
(`FLAG_PERFECT_IVS_MODE` forces the IV *display* to 31; leave that mode unticked or the test
lies to you.) It was also holding `ITEM_STARMINITE`, so the mega-stone award works.

**Fastest way to reach an Alpha: `Debug > Give X > "CHEAT start"`.** `Debug_CheatStart`
(debug.pory) is literally `goto(Common_EventScript_Alpha_Starmie)` -- an instant Alpha battle
from anywhere, no navigation. In Character Mode you must play a character whose roster has the
species or the catch is blocked: **Misty** (Gen I, 9 rights from Red) has Staryu.

**KNOWN BUG: the Master Ball does not catch.** Two Master Balls broke free from a Lv5 Alpha
Starmie; a plain Poke Ball caught it on the first throw. `Cmd_handleballthrow` reads correctly
(`if (gLastUsedItem == ITEM_MASTER_BALL) shakes = maxShakes;` then `if (shakes == maxShakes)`
-> caught), and two *different* failure messages mean the RANDOM branch ran -- so
`gLastUsedItem` was not `ITEM_MASTER_BALL` (= 1) by then. Suspects: ROWE's `lastUsedBall`
feature clobbering it, the `F_ULTRA_BEAST` block that forces `ballMultiplier = 1` for any
non-Beast-Ball, and `if (gLastUsedItem > ITEM_SAFARI_BALL)` which excludes the Master Ball
from the ball switch entirely.

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

## The BP economy (fixed 2026-07-12 -- read before touching prices)

2.X prices things in **Battle Points** and says so in the text, but 1.9.4's engine had
**no BP anywhere**: `shop.c` billed `gSaveBlock1Ptr->money` for everything, the tutor
scripts call `checkmoney`/`removemoney`, and `VAR_SHOP_MONEY_TYPE` /
`MART_MONEY_TYPE_BATTLE_POINTS` had **zero C readers**. So every BP price was charged in
Pokedollars: mega stones cost P200, an Egg move P4, Wonder Trade P5.

BP is now real. Two halves, keep them in step:
- **Shops**: `CreateShopMenu` captures `VAR_SHOP_MONEY_TYPE` into `gMartInfo.moneyType`
  **and resets the var**. That reset is load-bearing -- 19 script sites set the var to
  BATTLE\_POINTS and almost none set it back, so leaving it live makes the *next* ordinary
  Poke Mart charge BP.
- **Scripts**: new commands `takebp` / `checkbp` / `showbpbox` / `hidebpbox`
  (opcodes 0xEE-0xF1 in `asm/macros/event.inc` + `data/script_cmd_table.inc`), mirroring
  the money four. Any script that prices in BP must use these, never `checkmoney`.
- BP lives in `gSaveBlock2Ptr->frontier.battlePoints`.
- The BP box prints "200BP" and draws **no money-label sprite** -- so `Task_ExitBuyMenu`
  must skip `RemoveMoneyLabelObject()` in BP mode, or it frees a sprite it never made.

## Costumes = characters (rebuilt 2026-07-12)

The costume list is **built at runtime** (`BuildCostumeList` in `script_menu.c`) from the 4
base outfits plus every `gCharacters[]` entry with overworld art (101 of 182), and consumed
by `ApplyCostumeChoice` **in the same file**. That co-location is the point: this menu used
to be a 16-case switch in `.pory` against a list in C, and it drifted.
- `VAR_COSTUME_CHARACTER` (reused the free 17008 slot, so SaveBlock1 did NOT grow):
  0 = none (wear the Character Mode character), 1..N = wear character N,
  `COSTUME_CHARACTER_BASE` (0xFFFF) = explicitly wearing a base outfit.
- `GetAppearanceCharacter()` drives **appearance** (OW/back/card); `GetActiveCharacter()`
  still drives the **roster**. Do not merge them.
- `GetCostume()` (field_control_avatar.c) is the **single clamping choke point** for
  `VAR_COSTUME_NUMBER`; all ~45 readers go through it. Only 4 costumes have sprite data.

## Species tables: a MISSING ROW IS A NULL POINTER, AND NULL IS A CRASH

The species graphics tables are **designated-initializer arrays** (`SPECIES_SPRITE(X, ...)`
expands to `[SPECIES_X] = ...`). A species with no row therefore gets a **zero entry -- a
NULL pointer** -- and the battle engine dereferences it the instant that Pokemon is sent out:

    sprite->anims = gMonFrontAnimsPtrTable[species];   // NULL -> "Jumped to invalid address"

That shipped: **120 Gen 9 species (Toedscruel, Annihilape, Armarouge, Baxcalibur, Ceruledge...)
had front/back/palette art but NO row in `gMonFrontAnimsPtrTable`**, so every one of them hard-
crashed the game. It is reachable from an ordinary trainer battle -- ROWE's `GetTrainerPokemon()`
**randomises the species**, so ANY trainer can roll one; the party data in trainers.h is only a
hint. 622 NULL entries across five tables. `tools/character_mode/fix_species_graphics.py` fills
every gap and is the thing to re-run after adding species. **Never add a species without running
it.**

Two more shapes of the same crash, both fixed -- check for them when adding data:
- **An anim array needs TWO slots.** `sAnims_X[] = {sAnim_GeneralFrame0, sAnim_X_1}`: the engine
  plays **anims[1]** as the send-out intro, so a ONE-entry array is read out of bounds and its
  garbage pointer is jumped to. (`sAnims_SPINDA` had this bug in the base tree.)
- **`sMonFrontAnimIdsTable` feeds a function-pointer table.** `sprite->callback =
  sMonAnimFunctions[frontAnimId]`, and sMonAnimFunctions has **153 entries (0..152)**. Toxapex and
  Poipole were set to **153** -- one past the end -- i.e. a garbage function pointer.

## Trainers: parties, sprites, and the .lvl SENTINEL

- **`.lvl` is a SENTINEL, not a level** (battle_main.c): **1** = scale to the badge-appropriate
  trainer level, **3** = LeaderMinLevel (gym leaders), 2/5/6 = various random modes, anything else
  = a literal level + boost. The donor's raw `.lvl` must be **MAPPED**, never copied: a donor
  `.lvl = 2` lands in a branch with no case for 2 and becomes a **literal level 2**, so a Rocket
  grunt at 16 badges led with a level-2 Pokemon.
- **`gTrainerFrontPicCoords` missing entry = sprite drawn 32px too low.** The Y is
  `(8 - size) * 4 + 40`; a missing row means `size = 0`, so 72 instead of 40. Every entry in the
  table is `{.size = 8, .y_offset = 1}` -- there is no reason for a pic to lack one.
- **A trainer with `.partySize = 0` is a battle against nobody.** 91 of them shipped -- including
  **all 8 Johto gym leaders (gyms 9-16)** -- because `port_2x_new_trainers.py` matched
  `.party = {.Field = sParty_X}` while the donor writes `.party = TRAINER_PARTY(sParty_X)`. The
  regex matched nothing and the code **fell through and emitted them empty without a skip line**.
  A generator must FAIL LOUDLY, never emit a silently-empty record.
- **Only 14 trainer BACK sprites exist.** 170 of the 182 Character Mode characters (Ash included)
  fall back to the default protagonist in battle. That needs art, not code.

## Traps that have bitten more than once

- **DO NOT trust the debug menu's "Warp to map warp" for a movement bug.** It drops you on
  the destination's *warp tile*, and a door warp tile is **collision 1 by design** -- every
  building exit in the game is. Normally the door-exit animation walks you off it; the debug
  warp skips that, so you land stranded on a solid tile and it looks exactly like the
  walk-off-the-map bug. I nearly "fixed" FiveIsland_Meadow (13,20) over this. **Before
  calling a stuck tile a bug, check a known-good door** (e.g. SlateportCity_PokemonCenter_1F
  warp 0 -> SlateportCity (19,19), collision 1) and confirm the same shape is normal.
  Also: the camera CLAMPS at map edges, so "the screen didn't change" does not mean the
  player didn't move -- read the coords out of the save instead.
- **Emulator navigation eats sessions.** The debug menu remembers cursor positions, so a
  blind key sequence lands in the wrong submenu; screenshot after *every* press. In the
  warp selector, **Left/Right change the STEP SIZE and Up/Down change the value.** To reach
  a specific tile, BFS a path from the map's blockdata rather than eyeballing it -- but
  **exclude water** (collision 0 + you start with a Surfboard, so a collision-only path will
  cheerfully surf you into a wild encounter).
- **Three parallel badge flag families, all live.** `FLAG_BADGE0N_GET` (Hoenn 8, set by the
  gym leader scripts), `FLAG_RECEIVED_BADGE_09..16` (Johto 8), and `FLAG_GOT_BADGE_01..16`
  (set by `Special_Gym_EventScript_Give_Item`, alongside `VAR_NUM_BADGES`). The **Mega Stone
  Gurus and Alpha portals gate on `FLAG_GOT_BADGE_11`**; the move tutors gate on
  `VAR_NUM_BADGES`; `GetBadgeCount()` counts the first two. A test patch that sets only some
  of them will make working content look broken.
- **Hardcoded counts vs grown data.** Seven instances now -- the latest: `BufferSaveMenuText`
  wrote the badge count as a **single character** (`flagCount + CHAR_0`), which is only a
  digit for 0..9, so the save box printed a garbage glyph at 16 badges. Also: `gBattleAnims_Moves`
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
- **`special` vs `specialvar` are NOT the same.** This tree's `specialvar` uses the
  special's **RETURN VALUE** (`scrcmd.c`: `*var = gSpecials[...]()`), not
  `gSpecialVar_Result`. A `void` special that only writes `gSpecialVar_Result` hands the
  script whatever was in r0. Cost an hour on the Character Mode starter skip.
- **A var whose 0-default means "off", and a switch with no `default:`.**
  `VAR_CRY_SPECIES` selects the cry style; 0 is the options menu's "Disabled" choice and
  `PlayCry`'s switch has no case 0 -- so out of the box **every Pokemon was silent**.
  New games now default it to `CRY_TYPE_GENERIC`. (The "Normal"/"Anime" choices only
  `mgba_printf` for an external cry player, so Generic is the only one that makes a sound
  on a stock emulator.) Real per-species cries do NOT fit: the 934 samples in
  `sound/direct_sound_samples/cries/` would add ~8.1 MB and only ~7.9 MB of ROM is free.
  That is why ROWE ships them disabled -- do not "just enable" them.
- **Sprite tables: check by NUMERIC ID, never by constant NAME.** Many `OBJ_EVENT_GFX_*`
  names alias one id (BALDING_MAN, MAN, CLERK, MAN_FRLG and WORKER_M are all 19), so a
  name-based "missing entry" scan reports ~55 phantom crashes. Resolve the constants with
  the C preprocessor and index by value: 1232 entries / 1232 distinct ids / 0 collisions.
  The real bugs were six entries naming the wrong species (`OBJ_EVENT_GFX_WINGULL` ->
  `Pokemon_Species_279`, i.e. Pelipper -- that is Mr. Briney's Peeko).
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
