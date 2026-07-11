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

**Phase 5 (QoL/quests/achievements/NG+): NOT STARTED.**

**RUNTIME-UNTESTED:** actually standing on a Sevii island (data verified, but
navigating there in the emulator was never completed); a real trainer battle
(party data verified statically -- Roxanne = Onix w/ 6/252/252 EVs); Battle
Styles; level caps; ability effects; most new move effects.

## Donor facts

- `~/Documents/RoweRepo-donor` (persistent clone; scripts default to it via
  `ROWEREPO_DONOR` env var).
- Donor trainer ids 852+ COLLIDE with ours — never adopt donor trainer ids.
- Donor moves ids matched ours exactly; species/items/abilities mostly match
  by NAME with ~110 spelling divergences handled by `ROWEALIAS` block in
  `include/constants/species.h`.
- Sevii/Kanto maps (Phase 4) exist complete in donor `data/maps/`; ~8 specials
  missing from our engine (see plan).
