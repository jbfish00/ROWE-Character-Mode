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
| Branch | `character-mode`, HEAD `48a41097`, **working tree clean** |
| Rosters | **AUDITED** — 236 table slots / **206 selectable** / 30 hidden, 3,376 rows, **every row sourced** |
| Threshold | **ENFORCED** — the only game in the project where it is |
| Sprites | **168 of 236** have a front pic (68 are `CHAR_ASSET_NONE`) |
| Name length | **12/12 LANDED** (`71cebcbe`), verified by a new headless suite |
| Legendary rule | **SHIPPED** — 1% wild encounters, offered-until-caught, no roaming |
| Readiness | **GREEN** — selftest 33/33 and **all 11 suite runs passing** |

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

### Two follow-up fixes (`ROLL-ORDER` + `13x`)

**The RNG check now precedes the data check.** The first version consumed a
`Random()` before testing whether the character had any legendary at all, so the
**113 of 206 selectable characters with none** burned an extra RNG call per wild
encounter and their roll stream silently diverged from what the same save
produced before — breaking §1.1's "completely unaffected" guarantee. Nothing
looks broken; the rolls just stop matching. Unbound hit this independently and
the spec now states it as a rule for every game: **the data check goes before the
RNG call.**

**The wild-override path is ~13x faster.** The cost centre is
`GetFirstEvolution` (`src/level_scaling.c:239`) — a triple-nested scan that, for
a species with no pre-evolution, compares all `NUM_SPECIES * EVOS_PER_MON`
entries and finds nothing. `CharacterMode_FamilyBase` called it once per roster
entry, so a fired encounter walked it ~47 times.

Rosters store **canonical family bases**, so for a roster entry plain membership
in `sLegendaryFamilyBases` is exact — no walk needed. `IsLegendaryRosterEntry()`
does that, and the three roster-scanning paths use it. `CharacterMode_
IsLegendaryOrMythical` stays for arbitrary species (a caught mon, a rolled
evolution stage), which genuinely need the walk.

| | before | after |
|---|---|---|
| 200 rolls | 2354 frames | **181 frames** |
| per roll | 11.8 frames | **0.9 frames** |
| GBA time per fired encounter | ~0.2 s | **~0.015 s** |

⚠️ **The shortcut is exact only while an entry's legendary-ness matches its
canonical base's, and that is now a build gate.** `audit_rosters.py` fails if any
roster entry disagrees with its base, naming the entry and telling you to fall
back to the walking version. Verified by negative control (injecting a fake
mismatch makes it exit 1). Its `LEGENDARY_BASES` extraction also hard-fails below
90 entries — **the first version of that check silently parsed an empty set and
passed vacuously**, which is the same failure shape as §1 and §4.

### Per-character encounter tables — DONE (spec §3)

`ENCOUNTERS.md` (126 KB, GENERATED) — what each of the 236 characters can meet
in the wild, from `tools/character_mode/emit_encounter_docs.py`. Built from
`src/data/characters.h`, the table the ROM compiles, **not**
`rosters_mapped.json` (which sits upstream of the level bands and would promise
families the ROM cannot spawn). Deterministic across `PYTHONHASHSEED`.

**93 of 236 have a legendary; 143 have none and never roll the 1%. One roster is
all-legendary (Tobias), so his stay repeatable. No character has an empty pool** —
that last one is the catch-nothing failure mode and is called out explicitly at
the top rather than left to be noticed.

⚠️ **`ENCOUNTERS.md` is narrower than `ROSTERS.md` on purpose.** ROSTERS.md
documents what can be OWNED and walks form siblings, because the catch gate
canonicalizes forms (owning Wooper legalises Clodsire). The wild stage picker
walks `gEvolutionTable` **alone**, so a form that is legal to own can be
impossible to meet. Do not "fix" one to match the other.

**The generator's model is checked against the ENGINE, not itself.** It
reimplements `CharacterMode_PickEvolutionStageForLevel` in Python, and a
generator agreeing with its own model is exactly how ROSTERS.md and the ROM
drifted apart in both directions before the 2026-07-24 resync. So it also emits
`tools/mgba_scripts/encounter_probes.lua`, which
`tools/mgba_scripts/encounter_doc_e2e.lua` replays against the real in-ROM
function (60/60). Both directions are asserted — nothing undocumented appears,
**and** everything documented does appear; the second is the one a naive test
drops, and the one that catches a doc promising stages the ROM cannot produce.
Verified by negative control (a deliberately wrong probe fails both directions).

The rule: if a legendary is on the roster, a **1% chance** to meet one in any area,
rolled *before* the existing 10% non-legendary override (independent, so a
character with no legendary is unaffected). Each legendary is offered **until
caught**, then dropped — via the **Pokédex caught flag**, costing zero new save
state. Characters with no non-legendary families keep theirs repeatable.

## 5b. `GetFirstEvolution` — the repo-wide cost, fixed properly

§5 sidestepped this function in the wild-encounter path. It is now fixed at
source, for all **nine** callers — `CharacterMode_FamilyBase` (the catch gate,
hit on every caught species), six learnset helpers in `src/pokemon.c`,
`src/pokedex_area_screen.c`, and `level_scaling.c` itself.

It was a triple-nested scan: per walk-back step it swept all
`NUM_SPECIES * EVOS_PER_MON` entries of `gEvolutionTable` looking for anything
that evolves into the current species — **~14,820 comparisons that find nothing**
for a species with no pre-evolution, on every call.

`src/data/pokemon/pre_evolution.h` reverses that table once at build time
(`tools/character_mode/emit_pre_evolution.py`, 667 of 1482 species have a
pre-evolution), so the lookup is O(chain) instead of O(NUM_SPECIES × EVOS_PER_MON)
per step.

⚠️ **It is a ROM table, not a boot-built cache, and that was forced.** A
2,964-byte EWRAM array overflows this tree's EWRAM by 2,141 bytes — the link
fails with *"cannot move location counter backwards"*. **There is under 1 KB of
EWRAM free.** Anything needing runtime scratch of any size has to account for
that.

⚠️ **Two quirks of the old scan are preserved deliberately.** It did not filter
by method, so a mega form's pre-evolution is its base form; and
`gEvolutionTable` rows are zero-filled, so a short row still "targets"
`SPECIES_NONE` and the lowest such row (Bulbasaur) meant
`GetFirstEvolution(SPECIES_NONE) == SPECIES_BULBASAUR`. Odd, but shipped, and
some caller may lean on it. The zero-fill is invisible in the source and has to
be modelled by the generator.

**Equivalence is proven, not argued.** `GetFirstEvolutionReference` (the original
scan) is kept, and `tools/mgba_scripts/pre_evolution_e2e.lua` sweeps **all 1482
species** through both via `CM_REQ_VERIFY_PREEVO`: **0 mismatches**. The test also
asserts the sweep actually covered the table, so it cannot pass by checking
nothing.

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
2. Trainer card shows only the Hoenn 8 badges; the Johto 8 need art and a second row.
3. `FLAG_FULL_RANDOMIZED_MODE` and friends cannot be enabled without tilemap art
   (the mode NAMES are baked into the UI tilemap, not printed as text).

**Every remaining item needs ART, not code.** Nothing is blocking a playthrough,
and there is no outstanding engine work.

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

The suite (11 runs). Logs are ~130 MB; `timeout` exit 124 is NORMAL — the harness
never exits on its own and the RESULT line prints well before the timeout:

```bash
MGBA="../Character Hacks/Seaglass-Character-Mode/tools/mgba_src/build/mgba-headless"
export CM_SAV=~/Documents/rowe_fixture.sav
for t in boot_smoke continue_smoke ot_roundtrip_e2e legendary_encounter_e2e \
         encounter_doc_e2e catch_gate_e2e pc_sweep_e2e johto_gym_e2e \
         gigaton_reselect_e2e; do
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

- **EWRAM has under 1 KB free.** A ~3 KB runtime table overflows it and the link
  fails with "cannot move location counter backwards". Generate ROM data instead
  (§5b). A new `EWRAM_DATA` also needs its object listed in `sym_ewram.txt`, or
  the section is discarded and the link fails differently.
- **Mailbox request ids are DERIVED now**, by `gen_anchors.py` from the C enum
  into `anchors.lua`'s `REQ` table. The enum is positional and was hand-mirrored
  in Lua; inserting rather than appending renumbered every later request and a
  passing test carried on asking for something else. That happened **four times
  in one session** before it was automated. Never reintroduce a literal id.
- **NEVER hardcode a struct offset in a test.** `gTestStructOffsets`
  (`character_mode_selftest.c`) is a compiler-generated `offsetof()` table,
  exported by `gen_anchors.py` and read as `H.off.*`. The hardcoded ones drifted
  silently and reported a working feature as broken (§1).
- **A data check must precede any RNG call** in encounter code. Consuming a
  `Random()` before knowing the feature applies shifts the roll stream for every
  character it does not apply to. Nothing looks broken — the rolls just stop
  matching what the same save produced before.
- **Never hardcode a struct offset in a test** (see §1) — use `H.off.*`.
- **A check built on an extracted set must fail loudly if the set comes out
  empty.** The roster-audit invariant first "passed" against a zero-entry
  `LEGENDARY_BASES`, so both sides of every comparison were false. It now
  hard-fails below 90 entries. Three separate tests in this repo have now passed
  vacuously (§1, §4, this one) — when a new assertion goes green first try,
  break it on purpose and watch it fail before believing it.
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
