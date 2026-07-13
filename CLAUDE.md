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
- **Set saveblock state DIRECTLY in the temp patch, don't click it in.** e.g.
  `gSaveBlock1Ptr->trainerSkillLevel[SKILL_REBIRTH] = 10;` beats navigating the Skills
  menu — no dropped inputs, and the value is exact. `FlagClear(FLAG_CHARACTER_MODE)` in
  the same block stops the roster check sweeping your granted test mons to the PC.
- **Design each test so the prediction is PARTIAL and numeric.** A skill set to its max
  (a 100% heal) is indistinguishable from "the mon was already full" — that wasted a
  whole pass. Pick a mid level (30% heal on a mon at 2/28 HP → predict exactly 10/28) so
  a pass and a fail look different. And for a probabilistic effect, stack N subjects
  (4 fainted mons = 4 rolls in one battle) instead of re-running the battle N times.
- **Nasty Plot is the ideal PP-burner**: a status move drains PP over many turns and
  lets the enemy chip your mon down, without you accidentally killing it.

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
- Skill EFFECTS: **22 of 25** implemented and build-clean (2026-07-13); six PROVEN in
  mGBA to the exact formula (XP Boost-Pokemon, Rebirth, Revitalize, Skill Restore,
  Max PP, Bargain). See "Trainer Skill effects" below. Only Bonus Battle, Loot Boost and
  Rock Smash Boost remain — each needs a system the engine lacks.

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
- **Trainer card shows only the Hoenn 8 badges** — the Johto 8 need new art and a second
  row (badge tiles run 192..223 and the row is 22 tiles wide).
- **`FLAG_FULL_RANDOMIZED_MODE` cannot be enabled without new art.** 22 C reads, zero
  setters, and it is absent from `ModeFlags[]` (`ui_mode_menu.c`). Adding a 10th mode is
  a one-line `NUM_MODES` bump *in C* -- but the mode NAMES are **baked into the UI
  tilemap**, not printed as text (only the checkboxes are blitted, in a `NUM_MODES`
  loop). A 10th row would get a working checkbox with no label. Needs tilemap art.
  Same for `FLAG_TRAINER_SKILLS_MODE`, `FLAG_LEVEL_EVO_ONLY`, `FLAG_ENABLE_EV_CHANGES`.

Fixed since (Juan's rematch escalation and `VAR_BOSS_BATTLE_HP_MULTIPIER` used to be
listed here; both are done -- see the bug-fix pass below). **Seasons and "Change Date"
also used to be listed here as impossible/inert -- both have been REAL since commits
b6e73031 / e62103c0** (seasons: `day_night.c` reads `VAR_CURRENT_SEASON`, proven
in-game; date: `RtcSetDate`/`SetGameDate` shift `localTimeOffset` like the wall-clock
setter). Do not re-audit them.

## The nine "flag with no setter" leftovers — audited 2026-07-13, ALL closed, NO code changes

Every one was checked against the donor: **the donor has the identical gap in all nine**
(and `FLAG_EON_LATI` doesn't exist there at all — it's 1.9.4's). Per the
upstream-incomplete rule, none warrants a fix. Do not re-chase these:

- `FLAG_LEARNED_YES_NAH_CHANSEY` — the locked Rocket Warehouse door is CORRECT:
  `FiveIsland_RocketWareHouse` is **empty** (2 warps back to the Meadow, 0 objects,
  0 dialogue) — upstream-incomplete like Lost Cave. Opening the door would be worse.
  The first password ("Goldeen need log") is granted unconditionally by the door script;
  only the second has no source (FRLG taught it in Icefall Cave; 2.X dropped the grunt).
- `FLAG_DEFEATED_SUDOWOODO` — moot: **2.X removed the Sudowoodo object itself** from
  `BattleFrontier_OutsideEast` (25 objects on the map, none is it). The OnLoad show/hide
  and the old woman's "odd tree" line are dead leftovers, identical in the donor.
- `FLAG_HIDDEN_ITEM_ROUTE_116_BLACK_GLASSES` — **not dead at all**: it's a hidden-item
  bg event flag, set by the engine (`SetHiddenItemFlag`) on pickup. The earlier audit
  over-included it.
- `FLAG_OPEN_PC_BOX_FROM_MENU` — a 2.X engine QoL (jump straight to storage from a menu)
  whose C side we never had. The unset path IS the normal PC; nothing is broken.
- `FLAG_EON_LATI` — cosmetic: soaring always shows Latios instead of maybe-Latias
  (`soar.c` sprite pick). The Eon Flute needs BOTH Latis defeated, so "which one" has no
  principled answer; left as always-Latios.
- `FLAG_SCOTT_CALL_BATTLE_FRONTIER`, `FLAG_ENABLE_ROXANNE_FIRST_CALL`,
  `FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT`, `FLAG_RECEIVED_RUNNING_SHOES` — all gate only
  optional match-call chatter or house-interior flavor text; the unset branch is normal
  dialogue. 2.X cut the events that set them (Groudon's hideout awakening, the running
  shoes handout) without cutting the readers.

## Trainer Skill effects (implemented + mGBA-tested 2026-07-13)

22 of 25 skills do something; all effect math lives in `src/trainer_skills.c` so
the magnitudes are auditable in one place. The official doc gives each skill's effect
but NOT its per-level numbers (2.X engine code the donor doesn't ship), so magnitudes
are reconstructed — each is commented at its function; user play-testing is the
arbiter. Every effect is a no-op at level 0. Only the IV replacement is gated behind
`FLAG_TRAINER_SKILLS_MODE`; general effects are live in normal play (same as the
already-shipped XP Boost-Trainer).

### THE BADGE-ARRAY AUDIT (2026-07-13) — this class is now CLOSED, here is how to re-check

Everything indexed by a badge count has been swept. **Two badge-count sources, different
ranges — always know which one you have:**
- `GetBadgeCount()` (event_data.c) = literal badges, **0..16**.
- `GetNumBadges()` (level_scaling.c) = a *scaling index*, **0..18** (16 + after-league +
  endgame). Anything it indexes needs **19** entries.

Current state:
- The 21 level-scaling tables are all 19 entries, and `getScalingDataForBadge()` clamps
  internally — safe.
- `sShopInventories` (10 entries) overflowed and is now clamped in `GetNumberOfBadges()`.
- `sBadgeFlags[NUM_BADGES]` in **battle_setup.c** and **match_call.c** declared 16 slots
  but listed only the 8 Hoenn flags. C zero-fills the tail, and **flag id 0 is a real temp
  flag**, so `HasAtLeastFiveBadges()` / `GetNumOwnedBadges()` were reading a scratch flag
  as a badge and never counted Johto. Both now list all 16.
- `sBadgeFlags[8]` in **battle_script_commands.c** is EIGHT on purpose: its count indexes
  `sWhiteOutBadgeMoney[9]`. **Do not widen it to 16** without resizing that money table to
  17 in the same commit. (Consequence, accepted: the white-out penalty stops scaling after
  badge 8.)

**Two traps that make this class hide from a naive grep — use both checks:**
1. The index is often a **local**, not a call: `grep 'array\[GetNumBadges()\]'` finds
   nothing for shop.c, because it reads `sShopInventories[badgeCount]`. Chase variables
   assigned from a badge function, and multi-dim `t[a][b][badges]` too.
2. A **short initializer list is silent**. `u16 x[NUM_BADGES] = { ..8 items.. }` compiles
   clean and zero-fills. Since flag 0 is a valid flag, the zeros do not even crash — they
   just quietly lie. Count initializers against the declared size, don't eyeball it.

### THE MART CRASH: 9+ BADGES OVERFLOWED sShopInventories (fixed) — and how I misdiagnosed it

**Every Poke Mart in the game crashed once you had 9 or more badges** — i.e. the whole
back half of a playthrough, no items purchasable. Select Buy and the game dies the
instant the list draws (mGBA reports `Jumped to invalid address`, or the ROM just
reboots to the copyright screen).

Cause: `sShopInventories[]` (shop.c) has **10 entries** — the 9 Hoenn badge tiers 0..8
plus one post-league list. `GetNumberOfBadges()` returns `GetBadgeCount()`, which since
the 16-badge rework **counts the Johto badges too** and so reaches 16 (17 with game
clear). `SetShopItemsForSale` indexed the array with that **unguarded**, grabbing a
pointer up to 7 slots past the end, and its `while (gMartInfo.itemList[i])` scan then
walked unrelated memory. Fixed by clamping the index in `GetNumberOfBadges()`; badges
9-16 now get the post-league stock.

This is *exactly* the "array sized for 8 badges, now indexed by up to 16" class already
fixed in ~21 other tables (see Phase 4 notes) — this one was missed because reproducing
it needs 9+ badges **and** a money mart, a combination no earlier test happened to hit.

**The misdiagnosis is the real lesson.** I first blamed the Bargain skill hook and
reverted it (cfd0fb0f), on the strength of a bisect that *looked* clean: parent commit →
mart fine; HEAD with shop.c reverted → mart fine. But that bisect was **confounded** —
the working ROMs were also built with a *different temp grant* (8 badges) than the
crashing one (16 badges). I changed two variables at once and read the result as proof.
Bargain was innocent all along and is now restored.

**Rule: when A/B-ing a ROM, the temp grant is part of the experiment.** Hold it byte-
identical and vary exactly one thing. The controlled re-run (same 8-badge grant, hook
ON vs OFF) showed no crash either way in seconds, which is what cracked it.

Hook points (one line each; the callee does the level check):
- EXP: `Cmd_getexp` (battle_script_commands.c) — Gold Rush: `Cmd_getmoneyreward` —
  Sniper Ball: `CriticalCapture()`, added AFTER the dex-count scaling so it works
  early game when a small dex zeroes crit odds.
- Rebirth / Revitalize / Skill Restore: one call, `ApplyPostBattleSkills()` in
  `ReturnFromBattleToOverworld` (battle_main.c); skips link/frontier/trainer-hill.
- Stay Away: both repel `VarSet(VAR_REPEL_STEP_COUNT, ...)` sites (item_use.c +
  script_menu.c `HandleRepelMenuChoice`). Repels only — the doc names repels; lures
  are untouched.
- Quick Exit: `TryRunFromBattle` (battle_util.c), added in a u16 temp so the roll
  can't wrap; level 0 preserves the vanilla u8 truncation quirk exactly.
- Joy Boost: `AdjustFriendship`; ceil so vanilla's tiny 2..5 gains actually grow.
- Max PP Boost: `CalculatePPWithBonus`. NB current PP is stored separately, so a
  freshly caught mon shows e.g. 15/17 until its first heal — cosmetic, self-corrects.
- Step Heal: `ApplySkillStepHeal()` from `TryStartStepCountScript`, counter in
  `VAR_SKILL_STEPS` (reserved for exactly this). Heals `level` HP per 100 steps,
  never revives.
- Deep Scan: chain RESETS to 5*level instead of 0 — `ResetDexNavChain()` replaced all
  five `VarSet(VAR_DEXNAV_CHAIN, 0)` sites in dexnav.c. Increment/decrement untouched.
  **Quirk, confirmed in-game:** it only bites on the NEXT chain reset (i.e. next map
  change). Raise Deep Scan while standing on a route and DexNav still reads SEARCH
  LEVEL 0, because the reset for that map already ran at level 0. Not a bug; don't
  "fix" it by re-flooring the chain on every read (that would make the chain unloseable).
- Rare Sight: `TryFindHiddenPokemon` search roll (+2%/level on the base 60).
- Eggcelerate: daycare compatibility roll (+5%/level).

Not implemented — do NOT fake them with the wrong hook: **Bonus Battle** (nothing awards
BP per trainer battle), **Loot Boost** (no wild-drop system), **Rock Smash Boost** (rock
smash yields no items here).

### What the mGBA pass actually proved (2026-07-13)

Driven on a fresh save, Character Mode = Red, temp grant (250k trainerExp = 70 skill
points, 16 badges, 999 BP, ₽100k) in the START-commit path of `ui_mode_menu.c`
(reverted after; tree clean).

**PROVEN:**
- **The Skills menu economy.** 70 points from trainerExp; RIGHT raises / LEFT lowers;
  each skill caps at 10 and further raises are correctly rejected; spend total tracks
  (70 → 60 → 50); levels persist across menu close, save and reload.
- **XP Boost-Pokemon — EXACT.** Same Alpha Starmie kill by the same Lv70 Charizard:
  **182 EXP at level 0 → 273 EXP at level 10.** 182 × 1.5 = 273 to the point, which is
  precisely the coded +5%/level. Reproduced twice (273, 273). This also proves the whole
  `Cmd_getexp` hook path, i.e. the effect plumbing works end to end.
- **Bargain — EXACT.** At level 10 (-1%/level) with 16 badges: Poke Ball 200 -> **180**,
  Great Ball 600 -> **540**, Ultra Ball 1200 -> **1080**, Potion 300 -> **270**, Super
  Potion 700 -> **630**, Max Potion 2500 -> **2250**. All exactly -10%. And the BP side of
  the contract holds: the Mega Stone Guru still charges a full **200BP** per orb (the
  `if (!ShopUsesBattlePoints())` guard), so BP prices are never discounted.
- **The 9+ badge mart crash** (see above) — found here, misdiagnosed as Bargain, then
  correctly root-caused to the `sShopInventories` overflow and fixed.
- **Deep Scan's next-reset-only quirk** (see above).
- **Max PP Boost.** At level 10 Pikachu's Nasty Plot read max **30** (base 20) and
  Thunder Shock max **45** (base 30) — exactly +50%. Also confirms the documented
  cosmetic quirk: *current* PP stays at the old value until the mon is healed.

**Rebirth / Revitalize / Skill Restore — ALL THREE PROVEN EXACTLY (second pass).**
The first attempt was inconclusive for a dumb reason worth not repeating: the test mon
was barely scratched, so a level-10 (=100%) Revitalize was indistinguishable from simply
being at full HP, and one fainted mon gave only a single 50% Rebirth coin-flip.

The fix was to pick levels that make **partial, falsifiable** predictions, and to set
them **directly in the temp patch** (`gSaveBlock1Ptr->trainerSkillLevel[SKILL_X] = N`)
rather than clicking through the menu — far faster and exact. Setup: Rebirth **10**,
Revitalize **3**, Skill Restore **1**; party = Pikachu + **four** Lv4-5 Magikarp (four
independent Rebirth rolls in ONE won battle) + a Lv70 Charizard to close it out. Ground
Pikachu down to 2/28 HP and 12/20 PP on Nasty Plot (a status move — it burns PP and lets
the enemy chip you without you killing it), fainted all four Magikarp, then won.

| skill | prediction | observed |
|---|---|---|
| Revitalize 3 | HP 2 → 2 + 28×3/10 = **10**/28 (partial) | **10/28** |
| Rebirth 10 | fainted mon revives at maxHP/4 = **3**/15, ~50% each | **3/15**, 1 of 4 revived |
| Skill Restore 1 | Nasty Plot 12 → 12 + 20×1/10 = **14**/20 | **14/20** |

Moves already at full PP (30/30) were correctly left alone (the `pp >= maxPP` guard).
1 revive out of 4 coin-flips is a 25%-likely outcome, so the earlier "3 straight
non-revives" was ordinary bad luck, **not** a bug — Rebirth is fine.

**Still unproven (RNG-only, low value to chase):** Sniper Ball, Quick Exit, Rare Sight,
Eggcelerate, Joy Boost, Step Heal, Stay Away, Gold Rush.

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

## Bug-fix pass (2026-07-12) — commits 0bab1cc4, d349d012

All build-clean. **Everything here is RUNTIME-UNTESTED except where noted** -- the next
session should regression-test these before adding features.

- **The Master Ball did not catch** (found in the Alpha test above; two broke free from a
  Lv5 Starmie). Not `Cmd_handleballthrow`, which reads fine -- `HandleAction_UseItem`
  (battle_util.c) literally did `if (gLastUsedItem == ITEM_MASTER_BALL) gLastUsedItem =
  ITEM_POKE_BALL;` before dispatching, destroying the guaranteed catch it then looked up.
  Deleted the special case.
- **Waterfall was gated on `FLAG_RECEIVED_TM40`, which nothing sets** -- the waterfall could
  never be climbed, so **the game was uncompletable**. Now `FLAG_BADGE08_GET`.
  **CONFIRMED IN-GAME 2026-07-12** -- climbed Victory Road B2F's waterfall end to end. See the
  regression-test section below.
- **All 69 gym rematch gates** (8 gyms) read the same dead TM flags, so every leader always
  used their weakest rematch party. Re-pointed at the badge flags. Juan included.
- **`VAR_BOSS_BATTLE_HP_MULTIPIER` now has a C reader** (`ApplyBossHpMultiplier`,
  script_pokemon_util.c), called from both `CreateScriptedWildMon` and the double variant.
- **The Legendary Mega Stone Guru had a script but no object on any map**, so ~8 stones were
  unobtainable -- `ITEM_MEWTWONITE_X`'s only reference in the entire repo was one line in a
  mart no NPC could open. Placed him in `OldaleTown_House1` (2,6) and enabled the 4 commented
  stones whose Pokemon have real Mega forms. Necrozmanite stays commented: **there is no Mega
  Necrozma**, so it would be a dead item.
- **`FiveIsland_LostCave_Entrance` had ZERO warp events** -- entering dropped you at the map
  centre with no way out. Wired its unused `MB_LADDER` at (5,5) back to Resort Gorgeous.
- **Achievements 1-4, `getbadgenumber`, Pin Missile's scaling and the Match Call unlocks**
  all read the dead `FLAG_RECEIVED_BADGE_01..08` aliases. Re-pointed.
- Six routes never set their `FLAG_VISITED_ROUTE` (un-flyable); Wally's dad was frozen on one
  line by a `FLAG_RECEIVED_HM03` gate whose giving side no longer exists.

The nine remaining "flag with no setter" leftovers were audited 2026-07-13 and ALL
closed with no code changes — donor-identical gaps, empty content behind the gates, or
not actually dead. See "The nine 'flag with no setter' leftovers" section above.

**Upstream-incomplete -- do NOT "fix" these, the donor has the same gaps:** Lost Cave (14
maps), Seafoam Islands (5), Mt Ember Ruby Path (7) all ship with zero warps in 2.X too.

**Needs ART, not code:** 170 of 182 Character Mode characters have no back sprite (only 14
`TRAINER_BACK_PIC_*` assets exist); the trainer card's Johto badge row; per-species cries
(the 934 samples are ~8.1 MB and only ~7.9 MB of ROM is free -- that is why ROWE ships them
disabled; do not "just enable" them).

## Regression test of the bug-fix pass (2026-07-12) — 7 of 7 PROVEN

Driven in mGBA on a fresh save, Character Mode = Misty, with a temp grant (16 badges,
5 Master Balls, 999 BP, a Lv70 Gyarados) in the START-commit path of `ui_mode_menu.c`
(reverted afterwards; tree is clean).

**PROVEN:**
- **The Master Ball catches.** Alpha Starmie, full HP, first throw -> "Gotcha!". Before the
  fix two broke free from this exact Pokemon.
- **The Legendary Mega Stone Guru.** Walked to him in `OldaleTown_House1`, shop opened,
  **bought Mewtwonite X** -- an item whose only reference in the repo used to be one line in
  a mart no NPC could open -- and BP went **999 -> 799**, so the BP economy debits correctly.
  Heatranite / Zeraoranite / Urishifunite (3 of the 4 I re-enabled) are all in the list.
- **The Lost Cave softlock is gone.** Warped into `FiveIsland_LostCave_Entrance`, stepped on
  the ladder at (5,5), warped out to Resort Gorgeous. That map used to have ZERO warps.
- **The badge count renders "16"** in the save box (the `BufferSaveMenuText` single-char bug).
- **Level scaling is live** -- wild Zubat at **Lv45** with 16 badges.
- **Waterfall works.** Confirmed 2026-07-12 in a second session: surfed to Victory Road B2F's
  first waterfall (climb tile (9,14), waterfall column (9,11)-(9,13)), set `FLAG_BADGE08_GET`
  via the debug flag menu, faced north, pressed A -> `EventScript_UseWaterfall`'s Yes/No fired,
  and confirming it moved the player from (9,14) to (9,10) (read straight out of the .sav both
  times), i.e. all the way up the shaft and into the upper lake. The prior session's "no
  response" was **not a code bug** -- see the mGBA input-focus trap below. The fix
  (`FLAG_RECEIVED_TM40` -> `FLAG_BADGE08_GET` in `field_control_avatar.c`) is correct as shipped.

## Driving mGBA: things that cost me hours this pass

- **`xdotool keydown --window <id>` silently no-ops if the mGBA window is not the X-active
  window**, even though it targets a specific window id via XSendEvent. This produced a long
  false alarm: several consecutive "the waterfall does nothing" attempts across two sessions
  were actually keypresses that never reached the emulator at all -- the before/after
  screenshots were pixel-identical because nothing had happened, not because the game ignored
  a real press. Symptom: two opposite key presses (e.g. Up then Down) both leave the sprite
  facing the same way. **Run `xdotool windowactivate <parent-window-id>` before any input
  burst that follows a period of Read/Bash tool use**, and if a screenshot ever looks
  suspiciously identical to the previous one after a keypress, activate the window and retry
  before concluding the game didn't respond.
- **Numeric-entry debug dialogs (Give X, Set Flag XXXX, Warp to map warp) do not always hold
  input focus over a *batch* of rapid keypresses sent without a screenshot between them.**
  Batching 5-8 presses at once occasionally leaked the tail of the batch into overworld
  movement -- once triggering an unwanted wild battle. Sending one key, screenshotting,
  confirming the dialog is still showing the expected field, then sending the next key was
  100% reliable across ~40 consecutive presses; batches of >2 were not.

- **Auto-run is ON by default, so ONE key press moves TWO tiles.** This silently wrecks every
  dead-reckoned path. Press **R (`s`)** to toggle it off before doing any precise positioning.
- **Prefer routes that END AT A WALL.** "Hold LEFT until blocked" is self-correcting;
  "press LEFT 6 times" is not. Overshoot is the default failure.
- **The naming screen ignores START** (both `m` and a rebound key). Move the cursor onto the
  OK button instead: DOWN x3, then RIGHT until the cursor leaves the letter grid, then A.
- **You can only enter water from an ELEVATION-3 land tile** --
  `IsPlayerFacingSurfableFishableWater()` hardcodes `PlayerGetZCoord() == 3`. 2.X's cave
  ledges are elevation **4**, so a collision-only BFS will happily route you to a shore you
  can never surf from (this is not a bug; it is how the multi-level caves are built). Any
  path-finder must model elevation, not just collision.
- **The SELECT menu remembers its cursor**, so a blind `DOWN x2, A` lands on Save one time and
  Debug the next. Screenshot before every A -- several of my "saves" silently opened Debug
  instead, and I then read a STALE position out of the .sav and chased a phantom.
- A **message box caught mid-render screenshots as green/black stripes** with no text. It is
  not corruption -- wait ~1.5s and shoot again.

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
- **START IS `q`, NOT `m`.** The binding in `~/.config/mgba/config.ini`
  [gba.input.QT_K] is `keyStart=81` = **q**. Older notes in this file said `m` and cost
  a long false alarm on the Character Mode menu: the commit simply never fired and it
  looked like the menu was ignoring input. **Read the config, don't trust the note.**
  Current map: A=x(88) B=z(90) Up=i(73) Down=k(75) Left=j(74) Right=l(76) **Start=q(81)**
  Select=n(78) L=a(65) R=s(83).
- **`export DISPLAY=:1`** — this box is a `tty` session (`XDG_SESSION_TYPE=tty`, DISPLAY
  unset), so mgba-qt aborts on launch until you set it. `who` shows the `:1` seat.
- **mGBA input**: synthetic X events only deliver **letter keys** -- Return,
  arrows and Backspace never arrive.
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
  This is the single most productive bug shape in the repo -- it has now bitten
  **eight** times (level scaling, item megas, Waterfall, all 69 gym rematch gates,
  achievements 1-4, `getbadgenumber`, Pin Missile's scaling, the Match Call unlocks).
  The Waterfall one made the game **uncompletable**: `FLAG_RECEIVED_TM40` gates the
  field move, and no script sets it, so the Sootopolis waterfall could never be climbed.
- **THREE badge-flag families exist and only two are live. Know which you are reading.**
  - `FLAG_BADGE01_GET..08` -- Hoenn. **Set by the gym leader scripts. Real.**
  - `FLAG_RECEIVED_BADGE_09..16` -- Johto. **Set. Real.** (See the alias trap below.)
  - `FLAG_RECEIVED_BADGE_01..08` -- **DEAD.** `#define`d to the gym-TM flags
    (BADGE_01=TM39, 02=TM08, 03=TM34, 04=TM50, 05=TM42, 06=TM40, 07=TM04, 08=TM03),
    which nothing sets. Any C that reads these is reading zero forever.
  - `FLAG_GOT_BADGE_01..16` -- a fourth, parallel set written by
    `Special_Gym_EventScript_Give_Item`. The Mega Stone Gurus and the Alpha portals
    gate on `FLAG_GOT_BADGE_11`. Live, but not interchangeable with the above.
- **Poryscript `const` aliases hide flag writes from grep, and a name-based audit will
  report a FALSE game-breaking bug.** `gym_scripts.pory:2411` says
  `const FLAG_BADGE09_GET = FLAG_RECEIVED_BADGE_09`, so the Johto gyms *do* set
  `FLAG_RECEIVED_BADGE_09..16` -- but `grep 'setflag FLAG_RECEIVED_BADGE_09'` over the
  `.pory` sources finds **nothing**. An audit of mine concluded on that basis that the
  game could not be finished and told me to fix it first; "fixing" it would have been a
  pure regression. **Always confirm a flag audit against the GENERATED `.inc`, which has
  the aliases expanded** -- and resolve constants to NUMBERS, since many alias each other.
- **Badge flags expand to an expression containing SPACES** (`(SYSTEM_FLAGS + 0x8)`), so
  in poryscript `goto_if_unset FLAG_BADGE02_GET, Label` **needs the explicit comma**.
  Without it the macro's arg-splitting swallows the label and the branch silently dies.
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
