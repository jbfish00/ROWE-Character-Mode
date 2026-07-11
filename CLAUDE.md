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

Phases 1, 2 and most of 3 are COMMITTED and build-clean. `git log --oneline -12`.

**Phase 3 progress:**
- 3.1 Level caps: DONE. 2.X `gScalingInfo[difficulty][what][badges]` table in
  `level_scaling.c` (16-badge ready). NOTE: 1.9.4 ALREADY had level caps (stat
  clamp in CalculateMonStats + Hard-mode XP block in GetPkmnExpMultiplier);
  what 2.X changes is the VALUES (badge 8: 45, not 77). Both pre-existing paths
  now call `GetCurrentRawLevelCap()`. Do not add a second cap system.
- 3.2 Battle Styles: DONE. 8 styles, stat reshaping in `ApplyBattleStyle()`
  (called at the tail of CalculateMonStats + CalculateTrainerMonStats).
  Per-mon storage = 3 bits stolen from `hidden_nature` (u8 -> :5 + style:3),
  no save growth. Player picks with START on the summary Skills page.
  Opponents use them (trainer data's `.style`, wired in battle_main).
- 3.3 Trainer Skills: DONE (core + menu). `src/trainer_skills.c` +
  `src/trainer_skills_menu.c`. SaveBlock1 gained `trainerSkillLevel[100]` +
  `trainerExp`. The six stat skills REPLACE IVs under
  `FLAG_TRAINER_SKILLS_MODE` (3 IVs/point, final point 4 = exactly 31).
  Menu opens with START on the Start menu.
- **Exiolite: NEEDED NO WORK** -- 1.9.4 already ships it whole.
- 3.4 Blue Nurse suite: NOT STARTED (egg/tutor/TM tutoring by badge count,
  wonder trade, PC-storage battles, season change). Season change also
  unblocks MOVE_SEASONAL_BEAM, still stubbed.
- 3.5 Badge key-item rewards: NOT STARTED (most tool items already exist in
  1.9.4; this is gating alignment).

**Skill effects still unimplemented** (constants + points exist; only the six
stat/IV ones and XP Boost-Trainer actually do anything): Gold Rush, Bargain,
Sniper Ball, Step Heal, Rebirth, Stay Away, Skill Restore, Joy Boost,
Revitalize, Deep Scan, Eggcelerate, Rare Sight, Quick Exit, Bonus Battle,
Loot Boost, Max PP Boost, Rock Smash Boost, XP Boost-Pokemon.

**Trainer parties VERIFIED STATICALLY in the built ROM** (cheaper than driving
the emulator, which eats budget fast): dump `gTrainers` from the .gba (stride
0x28; partyFlags at +0, partySize at +0x20, party ptr at +0x24) and decode the
party. Roxanne = Onix with a real 6/252/252 EV spread; Brendan Route 103 =
Treecko. Both match the donor data, `partyFlags == 0x3`
(CUSTOM_MOVESET|HELD_ITEM), pointers valid. Reuse this technique -- it beats
navigating to a trainer.

**RUNTIME-UNTESTED (all committed, all build-clean):** everything in Phase 3
(level caps, Battle Styles, Trainer Skills + its menu), the ability effects,
most new move effects, and an actual trainer BATTLE (data is verified, but
CreateNPCTrainerParty has never been exercised on the rewritten structs).
Test ROM ready: `~/Documents/rowe_test_phase3.gba` (fresh save; any mode
commit grants a Lv40 Snorlax). Fastest live checks: fight the Route 103 rival,
open Trainer Skills with START on the Start menu, cycle a Battle Style with
START on the summary Skills page.

**Recently FIXED:** the Trick-o-nome crash was `gBattleAnims_Moves` (assembly,
so it escaped the MOVES_COUNT sweep) still having 756 entries for 943 moves --
ANY new move animating jumped through garbage. Ported all 188 via
`port_2x_move_anims.py`; verified 188/188 valid ROM pointers and 7 clean
Trickonome uses in-battle.

## Donor facts

- `~/Documents/RoweRepo-donor` (persistent clone; scripts default to it via
  `ROWEREPO_DONOR` env var).
- Donor trainer ids 852+ COLLIDE with ours — never adopt donor trainer ids.
- Donor moves ids matched ours exactly; species/items/abilities mostly match
  by NAME with ~110 spelling divergences handled by `ROWEALIAS` block in
  `include/constants/species.h`.
- Sevii/Kanto maps (Phase 4) exist complete in donor `data/maps/`; ~8 specials
  missing from our engine (see plan).
