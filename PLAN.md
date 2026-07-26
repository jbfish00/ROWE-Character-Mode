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
12-character-name change is landed, a live out-of-bounds write in the Pokedex is
fixed, the 1% legendary encounter rule is shipped, and the whole suite is green.

| | |
|---|---|
| Branch | `character-mode`, HEAD `7a11d933`, **working tree clean** |
| Rosters | **AUDITED** — 236 table slots / **206 selectable** / 30 hidden, 3,376 rows, **every row sourced** |
| Threshold | **ENFORCED** — the only game in the project where it is |
| Sprites | **168 of 236** have a front pic (68 are `CHAR_ASSET_NONE`) |
| Name length | **12/12 LANDED** (`71cebcbe`), verified by a new headless suite |
| Legendary rule | **SHIPPED** — 1% wild encounters, offered-until-caught, no roaming |
| Readiness | **GREEN** — selftest 33/33 and **all 10 suite runs passing** |

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

## 5. The 1% legendary rule — SHIPPED

Spec: `../Character Hacks/game_plans/legendary_encounters.md`. **Design locked by
the user 2026-07-26 and now implemented here** — the baseline 1% wild encounters,
no roaming (the user's call). Radical Red shipped it the same day; four games left.

### What was built

The roll lives **inside `CharacterMode_RollWildOverrideSpecies`**
(`src/character_mode.c`), ahead of the existing 10% roll. Both shipping call
sites — `src/wild_encounter.c:408` and `:422` — already route through that one
function, so **no call site changed**. Rates compose to ~1% legendary / ~9.9%
roster / ~89% vanilla, and a character with no legendary is bit-for-bit
unaffected.

`CharacterMode_BuildLegendaryPool()` is public specifically so the pool can be
asserted on **directly**; its `outRepeatable` out-param carries the §1.2
exemption (a roster with no ordinary family keeps its legendaries repeatable, so
Cogita-type characters can still catch something). "Offered until caught" is the
Pokédex caught flag — zero new save state, which is what makes the design
portable to the five closed binaries.

⚠️ **This depended on the §6 Pokédex fix landing first.** The dex accessor takes a
national dex number, and 26 species mapped to 0; without the guard the filter
would have written out of bounds on the first lookup. Any port must check that
before wiring the filter.

**Level** is §1.4 as written: the area's level, via the existing
`CharacterMode_PickEvolutionStageForLevel`. The out-param the old plan thought
was needed is not — a Lv.3 Mewtwo on Route 101 is the intended behaviour, and a
fixed canon level would be a different feature.

### Testing it, and the trap it walked into

`tools/mgba_scripts/legendary_encounter_e2e.lua` (19/19). The boot self-test's
old assertion — *"wild override: never produced a legendary/mythical"* — is
exactly the shape the spec warns about: once the dex filter can suppress
legendaries, it passes both when suppression works **and when the feature is
completely dead**. It is now a rarity bound, with the real proof in the positive
direction: the pool is non-empty, every entry has a real dex number, the roll
**fires** at ~1%, catching one removes exactly that one, and the 10% override
survives.

⚠️ **Sampling a 1% event here is expensive — measured at ~11.8 frames per trial**
through the full override, because the 10% path rebuilds a 47-entry candidate
list and every entry costs a `CharacterMode_FamilyBase` evolution-table walk.
2000 trials does not finish inside any sane deadline. The test therefore samples
the *legendary roll alone* (which early-outs on 99 of 100 calls) for statistical
weight and runs only a small end-to-end sample for wiring. That per-encounter
cost is **pre-existing**, not something this feature introduced, but it is real:
roughly 0.2 s of GBA time on the 10% path. Worth optimising if wild encounters
ever feel like they hitch.

### Still open here

**Per-character encounter tables** (spec §3) — the generated doc of what each
character can actually meet, with rates and empty pools called out. Not started;
it belongs beside `emit_roster_docs.py` and must be derived from emitted data,
never from `rosters_mapped.json`.

The rule: if a legendary is on the roster, a **1% chance** to meet one in any area,
rolled *before* the existing 10% non-legendary override (independent, so a
character with no legendary is unaffected). Each legendary is offered **until
caught**, then dropped — via the **Pokédex caught flag**, costing zero new save
state. Characters with no non-legendary families keep theirs repeatable.

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
2. **Per-character encounter tables** (§5, spec §3) — the one piece of the
   legendary work not yet done.
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

The suite (10 runs). Logs are ~130 MB; `timeout` exit 124 is NORMAL — the harness
never exits on its own and the RESULT line prints well before the timeout:

```bash
MGBA="../Character Hacks/Seaglass-Character-Mode/tools/mgba_src/build/mgba-headless"
export CM_SAV=~/Documents/rowe_fixture.sav
for t in boot_smoke continue_smoke ot_roundtrip_e2e legendary_encounter_e2e \
         catch_gate_e2e pc_sweep_e2e johto_gym_e2e gigaton_reselect_e2e; do
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
