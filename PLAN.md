# PLAN.md — Pokemon ROWE, where everything stands

**Read this first if you are picking this repo up cold.** It is the per-repo
handoff across *every* workstream at once — Character Mode rosters, sprites, the
name-length expansion, playthrough readiness and the open engine work — plus the
traps specific to this tree.

`CLAUDE.md` (gitignored) remains the authority for architecture and history; this
file is **state and next steps**. Verified 2026-07-26 against this working tree.

> A mirror of this file lives at
> `/home/jbfish00/Documents/Character Hacks/game_plans/rowe.md`, alongside plans
> for the five ports. Keep them in step, or delete one — do not let them drift.

---

## 0. TL;DR

**The most feature-complete game in the project, and no longer blocked.** The
12-character-name change is landed, the whole suite is green, and a live
out-of-bounds write in the Pokedex is fixed.

| | |
|---|---|
| Branch | `character-mode`, HEAD `fa09f30a`, **working tree clean** |
| Rosters | **AUDITED** — 236 table slots / **206 selectable** / 30 hidden, 3,376 rows, **every row sourced** |
| Threshold | **ENFORCED** — the only game in the project where it is |
| Sprites | **168 of 236** have a front pic (68 are `CHAR_ASSET_NONE`) |
| Name length | **12/12 LANDED** (`71cebcbe`), verified by a new headless suite |
| Readiness | **GREEN** — selftest 30/30 and **all 9 suite runs passing** |

Every number above was re-derived from this tree, not taken from notes.

---

## 1. What the old blocker actually was

Three suites were red. **None of them was a game defect**, and the two causes
were different — worth keeping, because both will recur.

**Stale fixtures** (`continue_smoke`, `catch_gate_e2e`). They load a `.sav` via
`CM_SAV`, and the documented file predated the save-format change, so it is now
refused *by design*: the signature bump makes `GetSaveValidStatus` return
`SAVE_STATUS_OLD_FORMAT` and the main menu offers New Game only. The test then
A-mashed a "Continue" that was not there and failed looking exactly like a
save-system bug.

**A lying test** (`gigaton_reselect_e2e`). It hardcoded struct offsets from a
savestate probe. `struct BattleResults` embeds
`playerMon1Name[POKEMON_NAME_LENGTH + 1]` at `0x8`, so growing names pushed
`battleTurnCounter` `0x13`→`0x15` and `lastUsedMovePlayer` `0x22`→`0x26`. It read
a turn counter frozen at 0, concluded the Gigaton Hammer gate was broken, and
**that was written up here as a release blocker.** The ROM was correct the whole
time — dumping `gDisplayedStringBattle` during the wedge showed *"used Gigaton
Hammer!"* on turn 1 and *"can't use the same move in a row"* on turn 2.

Both classes are now structurally closed — see §8.

⚠️ **The general lesson, because it cost most of a session:** four plausible
hypotheses were wrong before the right one (the max-length nickname, the
healthbox `GetFontIdToFit` call, `sizeof(BattlePokemon)`, and the test's
pre-battle setup). Each *sounded* convincing. What settled it was dumping the
actual battle message, not reasoning about the diff. **A/B one variable and read
the game's own output.**

---

## 2. Rosters — the reference implementation

The 2026-07-25 adversarial roster audit landed here first (`f9f61363`, `d9f96d59`,
`2ca9d486`, `5dfdda7f`). Verified in `src/data/characters.h`: **236 slots,
206 selectable, 30 hidden**, 3,376 documented rows, **every row carries a Source** —
the only game at 100% attribution (the ports sit at 96%, residue in Goh/Ash/Red).

**This is the only game where the playability threshold is actually enforced.**
`u8 selectable` on `struct CharacterInfo`, gating `FirstCharacterInGen()` and
`CycleCharacter()`. Every port computes `character_drops.json` and enforces
nothing — **this repo is the model they should copy.**

`tools/character_mode/` is the source of truth the ports borrow from:
`derive_drops.py`, `emit_roster_docs.py`, `verify_docs.py`, `fill_sources.py`,
`extract_source_candidates.py`, and the `audit_keeps.json` overlay. **The Frontier
Brains' 37 hand-made source labels exist only here** — copy them, do not
re-derive.

Rules the user set for roster work, all binding, in
`../Character Hacks/push_rosters.md` §1.

---

## 3. Sprites

**168 of 236 characters have a front pic**, up from 68 (`ca2657fa`). Confirmed by
counting `.trainerFrontPic` in `src/data/characters.h`: exactly **68 are
`CHAR_ASSET_NONE`**.

⚠️ **This repo does NOT need a render surface.** `src/trainer_card.c` has drawn
`GetAppearanceCharacter()->trainerFrontPic` since the costume work. Do not go
looking for one — the four GBA ports needed an injected renderer precisely because
they lack this.

`tools/character_mode/import_donor_front_pics.py` is built, proven, **additive and
idempotent**: re-running it picks up newly staged art with no further work. What is
missing is *art*, for the same names missing everywhere — Ash, Paul, Zoey, Nando,
Trip, Alain, Ghetsis, Colress, the Alola anime four, most professors.

Workspace runbook: `../Character Hacks/SPRITE_PLAN.md`.

---

## 4. Name length — LANDED (`71cebcbe`)

Pokémon and player names are 12 characters. **Stored OT names stay at 7**
(`OT_NAME_LENGTH`) — that decoupling is what keeps `BoxPokemon` at 80 bytes so PC
storage never grows. Paid for by `SECTOR_DATA_SIZE` 4000→4084 (the sector always
had `data[0xFF4]`) plus secret bases 5→3. 43 abbreviated species names fixed;
long names auto-narrow via `GetFontIdToFit`.

| | now | limit | spare |
|---|---|---|---|
| SaveBlock1 | 16220 | 16336 | **116** |
| SaveBlock2 | 3396 | 4084 | 688 |
| PokemonStorage | 33744 | 36756 | 3012 |
| BoxPokemon | 80 | — | unchanged |

**116 bytes is the entire remaining SaveBlock1 headroom.**

**Pre-change saves are refused**, deliberately: the per-sector signature is bumped
`0x8012025`→`0x8012026`, the old value is still *recognised*, and the main menu
says the file is from an older version rather than showing an empty cartridge.
Every `.sav` in `~/Documents/rowe_test_*.sav` is therefore dead. Generate fixtures
instead — §8.

### The verification, and why it is not the one the old plan asked for

The old plan called this BLOCKING: *catch a Pokémon and confirm it OBEYS*, on the
theory that a wrong ownership comparison makes every self-caught mon read as
traded. **That cannot be observed in this ROM.** `IsMonDisobedient`
(`src/battle_util.c:7743`) has its entire body wrapped in `/*/ … /*/` and returns
0 unconditionally; `IsTradedMon` (`src/pokemon.c:8827`) is stubbed `return FALSE`.
Those are `IsOtherTrainer`'s only two callers, so **nothing in ROWE can disobey**
and an "it obeyed" assertion could not have failed — a test that cannot fail.

`tools/mgba_scripts/ot_roundtrip_e2e.lua` (19/19) tests the real exposure
instead — memory, not behaviour. A 12-character player name truncating into the
7-byte OT field; the OT reading back at exactly `OT_NAME_LENGTH` and matching;
the mon **not** decoding as a Bad Egg (the canary for an overrun into markings
and the checksum); full-length nicknames; and all of it surviving a save.

⚠️ **It sets the player name explicitly, and must.** The intro A-mash yields a
**6**-character name — *shorter* than `OT_NAME_LENGTH`, so nothing ever truncates
and every assertion passes while proving nothing. The first version of the test
did exactly that.

Two findings worth carrying to any similar work:

- **Never size a struct in this repo with a modern compiler.** A host probe and
  `arm-none-eabi-gcc` agreed with each other and were both **332 bytes wrong**
  about `SaveBlock1`, because the ROM builds with GCC 2.95-era `agbcc`.
- **A green build proves almost nothing for this class of change.** An adversarial
  audit found **nine** buffer overflows — two reaching SaveBlock1, one a stack
  smash, one on every egg hatch — that all compiled clean, because `StringCopy*`
  take their lengths at runtime and buffers had been sized with hardcoded numbers
  rather than the defines.

The five closed-binary ports are untouched; Part B of that plan specs a
**feasibility assessment only**, no implementation until the user has seen it.

---

## 5. Encounter tables and the 1% legendary rule

Spec: `../Character Hacks/game_plans/legendary_encounters.md`. **Design locked by
the user 2026-07-26; surveyed in all six engines; implemented in none.** Of the
six, **this is the one the survey said "do it" outright for.**

The rule: if a legendary is on the roster, a **1% chance** to meet one in any area,
rolled *before* the existing 10% non-legendary override (independent, so a
character with no legendary is unaffected). Each legendary is offered **until
caught**, then dropped — via the **Pokédex caught flag**, costing zero new save
state. Characters with no non-legendary families keep theirs repeatable.

### What it costs here — almost nothing

| | |
|---|---|
| Roll insertion | before `src/character_mode.c:338` (existing rate `WILD_OVERRIDE_CHANCE_PERCENT 10` at `:198`) |
| Call sites | `src/wild_encounter.c:408` (land/water/rock) and `:422` (all rods) |
| New data | **none** — `sLegendaryFamilyBases[98]` (`character_mode.c:205-226`) and `CharacterMode_IsLegendaryOrMythical()` (`:228-239`) already exist |
| The mechanism | **invert the filter at `character_mode.c:343`** into a second candidate list |
| Rosters | already sort legendaries to the tail (`emit_characters.py:168-179`) |
| Once-each | `GetSetPokedexFlag(SpeciesToNationalPokedexNum(species), FLAG_GET_CAUGHT)`, `src/pokedex.c` |

**93 of the 206 selectable characters have ≥1 legendary; max 12 on one roster.**

⚠️ The legendary list is **hand-synced** between `character_mode.c:205-226` and
`tools/character_mode/emit_characters.py:28-38` (98 entries each, verified in sync).
Any change must touch both.

Level: `CharacterMode_PickEvolutionStageForLevel()` (`:284-322`) handles the few
legendaries with pre-evos correctly (Cosmog, Type: Null, Kubfu, Poipole, Phione),
but the ~90 standalone ones return at the route's rolled level — **a Lv.3 Mewtwo on
Route 101**. Raising it needs an out-param; the caller does
`CreateWildMon(species, level)` at `wild_encounter.c:412`/`:429`.

### Roaming — feasible here, at ZERO SaveBlock1 cost

**This repo already has an arbitrary-species roamer API**: `CreateOnlineRoamer(u16
species, u8 level)` at `src/roamer.c:63-83`, in live use by the companion feature
(`src/pokemon.c`). Repeatability is already solved for roamers —
`src/battle_main.c:5847-5858` sets `roamerFlag[VarGet(VAR_LAST_ROAMER_NUM)]` on
`B_OUTCOME_CAUGHT` and clears the slot. The design reuses the existing
`struct Roamer` at SB1 `0x31DC`, whose `u8 filler[0x8]` can absorb a persisted map
position — **none of the 116 spare bytes are needed.**

Concrete risks: `sRoamerLocation`/`sLocationHistory` are `EWRAM_DATA`
(`roamer.c:14-15`) so position is lost on load, recovering only via the 1/16 branch
at `:152`; the location table is Hoenn map group 0, routes 110-134 only (`:17-40`,
`MAP_GRP` hardcoded at `:81`, `:104`, `:135`); **one slot only**;
`CreateInitialRoamerMon` is stubbed to always `SPECIES_PHIONE` (`:85-91`); and
`InitRoamer` is a live script special (`data/specials.inc:310`, called from
`data/scripts/tv.inc:92`) that would overwrite a Character Mode roamer.
`roamerFlag[]` indices collide with the companion system unless a reserved
`VAR_LAST_ROAMER_NUM` value is claimed.

### What it breaks

**One hard failure:** `src/character_mode_selftest.c` —
`Check("wild override: never produced a legendary/mythical", anyLegendary == FALSE)`.
Its sibling survives (independent rolls give 0.99 × 10% = 9.9%).

⚠️ **A 1% event is the perfect hiding place for a test that cannot fail.** Once the
dex filter can suppress legendaries, *"no legendary appeared"* is satisfied both by
correct suppression **and** by the feature never running. Assert the positive
direction, on a save with a known-uncaught legendary. (This repo has now shipped
two such tests — see §1 and §4. Watch for the shape.)

---

## 6. The Pokedex out-of-bounds write — FIXED (`b6b677a7`)

`GetSetPokedexFlag` had no zero guard: `nationalDexNo--` on 0 gave `0xFFFF`, index
8191 into a 188-byte `dexSeen`/`dexCaught`, landing roughly `0x129B` past
`gSaveblock1` — **inside `gPokemonStorage`**. `FLAG_SET_CAUGHT` corrupted boxed
Pokémon, and `src/evolution_scene.c` sets that flag on **every evolution**.

**26 species** mapped to national dex 0 (the notes said 25). Both ends are now
guarded, but the guard only stops the corruption — the missing data was the real
defect, so **25 of the 26 now have a number**:

- Alolan Sandshrew/Sandslash → 27/28. A plain omission: every other regional form
  already mapped to its base species' number, and Alolan Sandslash's own **mega**
  form was already mapped to `NATIONAL_DEX_SANDSLASH`.
- The Hisui block (1207-1229): forms take their base species' number; the seven
  Hisui-exclusive evolutions take 899-905, already defined in `constants/species.h`.

The 26th is `SPECIES_EGG`, which correctly has none — that is what the guard is for.
Verified by reading `gSpeciesToNationalPokedexNum` back out of the built ROM: 26
zero entries before, 1 after.

*Cleared, so nobody re-chases it:* the Gen 9 `[SPECIES_X - 1] = NATIONAL_DEX_X`
form is functionally identical to the `SPECIES_TO_NATIONAL()` macro — a style
difference, not a defect.

---

## 7. Open work, in priority order

1. **68 characters still have no portrait** — art acquisition, not tooling (§3).
2. The legendary encounter feature (§5), if and when the user picks a starting game.
3. Trainer card shows only the Hoenn 8 badges; the Johto 8 need art and a second row.
4. `FLAG_FULL_RANDOMIZED_MODE` and friends cannot be enabled without tilemap art
   (the mode NAMES are baked into the UI tilemap, not printed as text).

Nothing is blocking a playthrough.

---

## 8. Commands

```bash
make -j$(nproc)                             # agbcc, MODERN=0. NEVER `make compare`.
python3 tools/check_name_lengths.py         # 16 checks — the gate for the 12/12 change
python3 tools/check_species_names.py        # abbreviated-species-name detector
python3 tools/mgba_scripts/gen_anchors.py   # MUST re-run after every build
```

**Save fixtures are GENERATED, never checked in.** Any `.sav` predating the
name-length change is refused by the ROM:

```bash
head -c 131072 /dev/zero | tr '\0' '\377' > ~/Documents/rowe_fixture.sav
CM_SAV_OUT=~/Documents/rowe_fixture.sav timeout 300 "$MGBA" \
    --script tools/mgba_scripts/make_fixture_save.lua pokeemerald.gba
```

The suite (9 runs). Logs are ~130 MB; `timeout` exit 124 is NORMAL — the harness
never exits on its own and the RESULT line prints well before the timeout:

```bash
MGBA="../Character Hacks/Seaglass-Character-Mode/tools/mgba_src/build/mgba-headless"
export CM_SAV=~/Documents/rowe_fixture.sav
for t in boot_smoke continue_smoke ot_roundtrip_e2e catch_gate_e2e \
         pc_sweep_e2e johto_gym_e2e gigaton_reselect_e2e; do
    timeout 100 "$MGBA" --script tools/mgba_scripts/$t.lua pokeemerald.gba > /tmp/$t.log 2>&1
    echo "$t $(grep -aoE 'RESULT: [A-Z]+' /tmp/$t.log | tail -1)"
done
CM_PATH=red    timeout 100 "$MGBA" --script tools/mgba_scripts/starter_regression.lua pokeemerald.gba > /tmp/sr.log 2>&1
CM_PATH=normal timeout 100 "$MGBA" --script tools/mgba_scripts/starter_regression.lua pokeemerald.gba > /tmp/sn.log 2>&1
```

There is **no `test/` directory** — the suite is the in-ROM boot selftest
(`src/character_mode_selftest.c`, invoked from `src/intro.c`) plus the mGBA Lua
scripts in `tools/mgba_scripts/`.

---

## 9. Traps

- **NEVER hardcode a struct offset in a test.** `gTestStructOffsets`
  (`character_mode_selftest.c`) is a compiler-generated `offsetof()` table,
  exported by `gen_anchors.py` and read as `H.off.*`. The hardcoded ones drifted
  silently and reported a working feature as broken (§1).
- **A `.sav` is a build artifact now.** Regenerate; never check one in, and never
  point `CM_SAV` at a pre-2026-07-26 file.
- **`make compare` will never pass** and is not the goal — this is a fork, not a
  byte-matching decomp.
- **`gen_anchors.py` must be re-run after every build**, or the mGBA scripts read
  stale addresses.
- **More than one session works in this tree.** Stage by name; **never
  `git add -A`.**
- **Never size a struct here with a modern compiler** (§4).
- The two legendary lists in §5 are hand-synced — change both or neither.
- **`gSelectionBattleScripts` holds the CURRENT instruction**, not the label — it
  advances within a frame or two, so test it as a range, never `==`.
