# PLAN.md — Pokemon ROWE, where everything stands

**Read this first if you are picking this repo up cold.** It is the per-repo
handoff across *every* workstream at once — Character Mode rosters, sprites, the
name-length expansion, playthrough readiness and the open engine work — plus the
traps specific to this tree.

`CLAUDE.md` (gitignored) remains the authority for architecture and history; this
file is **state and next steps**. Verified 2026-07-26 against this working tree;
§7 re-derived 2026-07-28, and the seven commits it describes were **landed
2026-07-29** (`0f321aea`..`e5e40c83`) after a full rebuild, an anchor regeneration
and a clean suite re-run. Tree clean.

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
| Branch | `character-mode`, **working tree clean and PUSHED to `origin`** (`jbfish00/ROWE-Character-Mode`) as of 2026-07-29. Last feature commit `c231ba2a`, followed by an anchors commit, a doc commit and a credits commit — don't treat any single hash as HEAD, and re-check with `git rev-list --left-right --count origin/character-mode...HEAD` rather than trusting this row |
| Rosters | **AUDITED** — 236 table slots / **206 selectable** / 30 hidden, **3,359** rows, **every row sourced** |
| Threshold | **ENFORCED** — the only game in the project where it is |
| Sprites | **184 of 236** have a front pic (52 are `CHAR_ASSET_NONE`) — 168 → 184 on 2026-07-29: 9 newly staged from the 07-28 harvest, 7 Frontier Brains closed with zero new art. Overworld **128 of 236** and back pics **19 of 236** as of 2026-07-30 (was 101 / 12) — §7.8b is DONE, the tooling block is gone, and what is left in those two slots is acquisition |
| Name length | **12/12 LANDED** (`71cebcbe`), verified by a new headless suite |
| Legendary rule | **SHIPPED** — 1% wild encounters, offered-until-caught, no roaming |
| Modes | **Randomized Party Mode SHIPPED** (`c231ba2a`), exclusive with Character Mode; both Game Modes menus de-drifted and pinned |
| Readiness | **GREEN** — selftest 33/33 and **all 14 suite runs passing**. Re-run 2026-07-30 on the mode-exclusion build `4ba53b39dc7f2c02bf1f023a95302467` (boot 2, continue 2, ot_roundtrip 19, legendary 20, encounter_doc 60, catch_gate 14, pc_sweep 10, johto_gym 13, gigaton 9, basculegion_hang 34, mode_exclusion 72, **char_select 11**, starter red 6 + normal 6) — the thirteen pre-existing tallies match the `08eef0c3…`, `e2b047c4…`, `dd0315b8…` and `b14e874b…` baselines EXACTLY, and `mode_exclusion` is the new run. Anchors regenerated first; map digest `45cfe76e469fceeb`, and a second `gen_anchors.py` run reproduces `anchors.lua` byte-identical |
| Species tables | **COMPLETE** — every species with a `gBaseStats` row now has a learnset, a name and front/back pic coords, gated by `tools/check_species_tables.py`. Four had none and **hung the game** (§7.11) |

Every number above was re-derived from this tree, not taken from notes.
⚠️ The suite is **14 runs as of 2026-07-30** — twelve scripts plus the two
`starter_regression` paths. It was **11** before that (nine scripts), and for
three sessions §0 and §7 claimed 12 while §8 correctly said 11: that 12th was a
*phantom*. The 12th now is real — `basculegion_hang_e2e`, §7.11 — and the 13th is
`mode_exclusion_e2e` and the 14th is `character_select_e2e`, both §7 item 2b.
Do not fold the
two facts together; the tallies are in §7.

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
206 selectable, 30 hidden**, **3,359** documented rows (3,376 before `2e71ffd2`
removed 17 duplicates — see §7.2), **every row carries a Source** — the only game
at 100% attribution (the ports sit at 96%, residue in Goh/Ash/Red).

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

**184 of 236 characters have a front pic**, up from 68 (`ca2657fa`) then 168
(2026-07-29). **Overworld 128 of 236** and **back pics 19 of 236** as of
2026-07-30. All three re-counted from `src/data/characters.h` on 2026-07-30:
`.trainerFrontPic` has **52** `CHAR_ASSET_NONE`, `.owGfxId` has **108**, and
`.backPic` has **217** `CHAR_ASSET_NONE_U8`.

⚠️ **This section read "168 … exactly 68" until 2026-07-30 while §0 and §7.8
already said 184/52** — the same count-drift this file keeps hitting. Note the
back-pic sentinel is `CHAR_ASSET_NONE_U8`, **not** `CHAR_ASSET_NONE`: counting
with the wrong one reports 236 of 236 covered, which is how a recount can be
confidently wrong. Derive all three together:

```bash
python3 - <<'EOF'
import re
s = open('src/data/characters.h').read()
tbl = s[s.index('gCharacters[] ='):]
for fld, sent in (('trainerFrontPic','CHAR_ASSET_NONE'),
                  ('owGfxId','CHAR_ASSET_NONE'),
                  ('backPic','CHAR_ASSET_NONE_U8')):
    v = re.findall(r'\.%s = ([A-Za-z0-9_]+)' % fld, tbl)
    print(fld, 'set', sum(1 for x in v if x != sent), 'of', len(v))
EOF
```

📄 A live per-character view of all three slots, parsed from this same file, is
published at `claude.ai/code/artifact/652cffb5-6998-4d4a-a4e7-30d455bb5261`.
⚠️ It is **ROWE-only** and does **not** supersede the cross-game
*Character Mode — Sprite Coverage by Character* artifact, which carries
hand-written provenance and licence caveats for all five ports. Neither can be
regenerated from the other.

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

Re-derived 2026-07-28 from this tree, not from notes. **The previous version of
this section said "every remaining item needs ART, not code" — that was wrong.**
Four code items were open and unlisted; three of them are data/doc correctness
bugs that the existing verifier passes over by construction.

**The five code/parity items are FIXED and now COMMITTED** — `0f321aea`,
`2e71ffd2`, `913e13eb`, `ef8cdb7e`, `77ac8e20`, `c231ba2a`, `e5e40c83`
(2026-07-29). Suite re-run on the final build: `make` 0 errors ·
`audit_rosters.py` OK (236 characters, 2775 entries) · `verify_docs.py` OK ·
`check_name_lengths.py` 16/16 · `check_mode_menus.py` OK (25 rows) + its
self-test · in-ROM selftest **33/33** · **all 11 suite runs PASS**, tallies
IDENTICAL to the pre-change baseline (boot 2, continue 2, ot_roundtrip 19,
legendary 20, encounter_doc 60, catch_gate 14, pc_sweep 10, johto_gym 13,
gigaton 9, starter red 6 + normal 6) — so nothing regressed.

⚠️ **Two process points from the commit pass, both worth repeating.**
`gen_anchors.py` had NOT been re-run after the final link — `anchors.lua`
predated `pokeemerald.gba` by two minutes, so any suite run made before it was
reading stale addresses. Regenerate, then run. And the three new `verify_docs`
checks plus the `audit_rosters` `starterCount == 0` guard were **re-proven by
negative control at commit time**, not taken on the strength of the note saying
they had been: inject a duplicate row, bump a header, restore the old `32`, force
a 0 onto Red's roster — each exits 1 and names the culprit.

### Code — DONE

1. ✅ **Tobias always starts with Darkrai.** He was the only `.starterCount = 0`
   row (`hasSignature = 0`, roster `[DARKRAI, LATIOS]`), so `GetNumStarters()`
   fell through to the full roster and `RandomizeStarterSelection()` rolled
   `Random() % 2` — a *random* legendary. **User ruling 2026-07-28: an
   all-legendary roster DOES get a starter, and always the same one.**
   `RandomizeStarterSelection` now takes `roster[0]` when `hasSignature` **or**
   `starterCount == 0`. Written generically, so any future all-legendary
   character behaves the same.
   ⚠️ Tobias is the entire population of this case here — Cogita and Iscan
   resolve to EMPTY rosters in ROWE's dex and are not in `gCharacters` at all,
   unlike Unbound/Radical Red where Cogita is the sharp case.
   **Guarded**: `audit_rosters.py` now fails if `starterCount == 0` appears on a
   roster that is not genuinely all-legendary — that 0 is read as "hand out
   roster[0]", so on an ordinary roster it would silently kill the starter
   choice. Proven by negative control (forcing Tucker to 0 exits 1 and names his
   five non-legendary entries).

2. ✅ **The 17 duplicated roster rows are gone** (3376 → **3359**, exactly 17
   removed, 0 added). Root cause was `regional_form()` testing a bare
   `endswith()`, so `SPECIES_SANDSLASH_MEGA_ALOLA` and
   `SPECIES_DARMANITAN_ZEN_MODE_GALARIAN` were classified as plain regional forms
   and rendered to the same display name as the real ones ("Alolan Sandslash" ×11
   characters, "Galarian Darmanitan" ×6). A constant now earns its own row only
   when what remains after stripping the region is a base species rather than
   another form. All 17 headers now match their distinct counts (Oak 75 → 74).
   `derive_drops.py` shares the classifier, so the threshold was re-derived: it
   is **unchanged** at 206 offered / 30 hidden. (Melony goes 7 → 6 finals and
   still clears the bar.)

3. ✅ **The hidden-slot count is derived from the compiled table.** New
   `hidden_slot_count()` counts `.selectable = 0` in `characters.h` instead of
   `len(character_drops.json)`, so ROSTERS.md and ROSTERS_SPRITES.md now say
   **30**, not 32. The coverage note no longer trails *"the remainder … has not
   been established yet"* once attribution reaches 100%.

   ⚠️ **`verify_docs.py` could not see 2 or 3, by construction** — it accumulated
   into a LIST on both sides, so duplicates inflated both equally and
   `3376 == 3376` passed. It now compares against the DISTINCT set and has three
   new checks, **each proven by negative control**: an injected duplicate row, a
   header disagreeing with its distinct count (the exact historical symptom), and
   a hidden-slot claim disagreeing with the compiled table. This was the fourth
   vacuously-passing check in this repo (§9) — the pattern is the point.

4. ⛔ **Selection-screen portrait — IMPLEMENTED AND REVERTED THE SAME DAY. It is
   art-blocked, not wiring.** The first pass put a 64×64 `trainerFrontPic` sprite
   at (150, 60), reasoning it sat clear of the mode checkbox column at screen
   x 184. That was the wrong landmark: the checkboxes are at x 184 but the mode
   **labels** start at x ≈118, so the sprite covered the "MODES" heading and
   seven of the nine mode names.
   **How that was settled — reuse this, it is cheap.** Render
   `graphics/ui_menu/tilemap.bin` (uncompressed, 32×32 entries, tile id in the
   low 10 bits, flips at bits 10/11) over `graphics/ui_menu/tiles.png` and draw
   the proposed sprite rect on top. That produces the actual screen without
   booting anything, and it showed the layout is **full**: the widest free gaps
   are the **16 px** between the left option panel and the modes panel, and the
   **40 px** to the right of the modes panel. There is no free 64×64 region.
   Showing a portrait therefore needs the menu tilemap redrawn to make room —
   which puts it in the same class as §7.8-10, not ahead of them.
   ⚠️ **The general lesson: a coordinate argument about a screen is not evidence
   about that screen.** The bounds check was arithmetically correct and still
   wrong, because it was checked against the one element whose position was in
   the C source (the checkbox blit) rather than against the elements that are in
   the tilemap. Render the tilemap before placing anything on this menu.

5. ✅ **Character Mode ON/OFF** in the debug Flags submenu, the counterpart to
   the ports' `CMDbgOff`. It toggles the FLAG only and deliberately keeps
   `VAR_CHARACTER_ID`, so switching back on resumes the SAME character instead of
   the broken flag-set-but-no-character state; enabling with no character ever
   selected is refused. Debug-only, so normal play still has the mode locked in
   for the save — which is what the playthrough checklist promises.

### Process — DONE

6. ✅ **`derive_drops.py` is now in the documented pipeline order** in
   `CLAUDE.md`, with the reason attached. It must run **before**
   `emit_characters.py`, which reads `character_drops.json` to set
   `.selectable` — so following the old chain after a roster change emitted the
   PREVIOUS roster's threshold, silently. That is how the 2026-07-25 pass shipped
   20 characters who could not field six fully-evolved Pokemon while hiding 5 who
   could. The file itself was always fine (it reproduces byte-identical); the bug
   was that nothing told you to re-run it.

7. ✅ **ROWE's playthrough checklist now has a wild-encounter block** — it ships
   the 10% roster override and the 1% legendary rule and asked the player to
   verify neither, while Unbound, Lazarus and Seaglass all did. Added the 10%/1%
   checks, the offered-until-caught rule, the area-level (not canon-level) note,
   Tobias's repeatable legendaries and always-Darkrai starter, and the
   ROSTERS-vs-ENCOUNTERS "own but cannot meet" caveat, plus a check on the
   selection screen. **ROWE is now 24 items, workspace total 112, 0 done.**
   (`READINESS_PLAN.md` said 76 in one place and 68 in another; both were stale
   before Seaglass's section landed. Both corrected, with a note to recount
   rather than copy.)

   **The playthrough itself remains the single largest piece of unfinished work
   in this repo, and nothing automated can close it.**

### Art — re-examined 2026-07-28. Two of the three were smaller than documented.

8. **Front pics: 168 → 184 of 236 (2026-07-29). Partly worked, still open.**

   ⚠️ **The previous version of this item was WRONG in the way that matters.**
   It said *"there is no un-imported art sitting on disk"* on the strength of
   `import_donor_front_pics.py --dry-run` reporting **0 to import**. The dry-run
   was accurate and the conclusion was not: the importer only ever looks at
   `sprites/donors/`, and the **2026-07-28 harvest deliberately staged nothing
   there** — it left 9 measured, format-clean front pics sitting in
   `../Character Hacks/art_harvest_2026-07-28/rowe/` pending two decisions it
   could not make alone (ship art nobody can attribute? which of two Thorton
   sprites?). **A tool reporting nothing to do is not evidence that there is
   nothing to do — check what it actually looks at.**

   **Landed 2026-07-29, +16 characters:**
   - **9 newly staged and imported** — Ghetsis, Kiawe, Lana, Mallow (Emerald
     Rogue, missed by the 2026-07-25 staging filter), Argenta, Dahlia (Greenphx),
     Lillie (MrDollSteak thread), Thorton (TAAR/BrandonXL, chosen over Greenphx's
     by the user), Colress (**unattributed** — shipped on an explicit user ruling
     with an honest "artist unknown" credit; see `CREDITS_CHARACTER_MODE.md`).
   - **7 with ZERO new art** — Anabel, Brandon, Greta, Lucy, Noland, Spenser,
     Tucker. Their front pics, palettes, INCBINs and `gTrainerFrontPicCoords`
     rows were **already in this tree** (vanilla Emerald Battle Frontier art);
     only `emit_characters.py`'s `const_candidates()` missed them, because they
     are filed under FACILITY TITLES (`TRAINER_PIC_SALON_MAIDEN_ANABEL`, …).
     Seven characters closed by adding seven prefixes. **When a character is
     reported as having no art, check whether the ENGINE already has it under
     another name before going looking for a donor.**

   ⚠️ **A destructive bug in the importer was found and fixed doing this, and it
   had been live since `ca2657fa`.** Every `donor-*` marker block is rewritten
   wholesale, and the "already has a pic" test counted the script's OWN previous
   output — so the first run with real work to do emitted a block of only the new
   picks and **deleted the other 99**, taking `trainers.h` from 287 TRAINER_PIC
   defines to 197. It survived for months because every re-run until now found 0
   to import and returned at the `if not picks` early-out **before touching a
   file — the bug was unreachable in exactly the case anyone ever tested.** The
   script now re-emits every pic it has ever imported, holds each id fixed, and
   **refuses to run** if a previously-imported character no longer resolves to
   staged art (proven by negative control: hide `ashgray/gary_front.png`, it
   exits 1 naming Gary and writes nothing).

   **Still open, and still genuinely acquisition-blocked: 52 characters have no
   front pic** (Ash, Tate, Paul, Zoey, Nando, Trip, Alain, Sawyer, Guzma,
   Plumeria, Lusamine, Rose, Goh, Chloe, most professors …). Nine of those —
   **Paul, Zoey, Nando, Trip, Sawyer, Goh, Chloe, Cerise, Tobias** — have no
   usable trainer-sprite art in ANY format anywhere searched; the anime cast that
   does exist is uniformly DS/Essentials scale and would need a redraw, not a
   conversion. The other two slots were TOOLING-blocked and are not any more
   (§7.8b, landed 2026-07-30): **108 of 236 still have no overworld art** and
   **217 have no back pic**, and every staged sheet is now imported, so both are
   acquisition again.
   ⚠️ The importer counts **238**, not 236 — it iterates the roster data, which
   still holds Cogita and Iscan, the two dropped from `gCharacters` entirely.
   Do not chase the off-by-one against the table's count; it is this.
   Sourcing leads are in `../Character Hacks/SPRITE_PLAN.md`, which is the
   runbook — not this file.

8b. ✅ **The overworld / back-pic importer — BUILT AND LANDED 2026-07-30.**
   `tools/character_mode/import_donor_ow_backs.py`. **Overworld 101 → 128 of
   236, back pics 12 → 19 of 236.** Roster data untouched: `characters.h` differs
   from HEAD on the `.owGfxId` and `.backPic` lines and nothing else, and
   `audit_rosters.py` still reads 236 characters / 2775 entries / 206 selectable.

   **It found MORE staged art than this section had counted: 27 overworld
   sheets, not 19, and 7 back pics, not 6.** The extra six overworld characters
   — **Calem, Serena, Elio, Selene, Victor, Gloria** — have `<name>_ow_walking.png`
   in `sprites/donors/rogue/`, which the hand count missed because it looked for
   `<name>_ow.png`. The extra back pic is **Noland** (the `taar_gap` file below).
   Two more came from staging `taar_gap/` into `sprites/donors/`: **Elm** (IAG)
   and **Kiawe** (PurrfectDoodle). Nothing else in `sprites/donors/` resolves to
   an overworld strip or a back pic for a character that lacks one — the tool
   iterates the whole roster, so that count is now derived, not eyeballed.

   ⚠️ **The `OBJ_EVENT_GFX_*` shortcut was NOT taken, and the gate is proven.**
   Every id it emits is a real 18-frame player-grade sheet, added to a new
   `imported_ow_donor.txt` that `emit_characters.py` now reads alongside
   `imported_ow.txt`. Negative control: delete `OBJ_EVENT_GFX_CM_ANABEL` from
   that allowlist and Anabel falls back to `CHAR_ASSET_NONE` — she does **not**
   fall through to `OBJ_EVENT_GFX_ANABEL` (id 70), which is the crash.

   ⚠️ **A frame width is not in a filename, and guessing it builds clean.**
   `taar/nessa_ow.png` is 288x32 — which is 18 frames of 16 px OR 9 of 32, and
   every 288-wide strip in `sprites/donors/` is the latter. The first version
   assumed 16, sliced every Nessa frame down the middle and paired the halves;
   it compiled, linked and produced a plausible-looking sprite sheet. **It was
   caught only by decoding the built `.4bpp` back out and looking at it.** The
   width is now MEASURED (worst sprite content either side of a candidate frame
   boundary; 144-wide sheets score 0-8 at fw=16, 288-wide ones score 19-21 at
   fw=16 and 0 at fw=32 — two clusters, threshold 12 between them). Proven by
   negative control: raise the threshold to 999 and Nessa comes out 16x576
   again.

   ⚠️ **"Backdrop at index 0" is not free.** `import_sprites.normalize_indexed()`
   returns a donor UNTOUCHED when it already fits 16 slots, backdrop wherever it
   sits — and `taar/phoebe_back.png` has its backdrop at slot **6**. The GBA
   renders sprite slot 0 transparent whatever its colour, so that ships an opaque
   box round Phoebe and makes slot 6's real colour vanish. `bg_to_slot0()` rotates
   it, losslessly.

   ⚠️ **Two of the tables it writes are POSITIONAL, not designated** —
   `gTrainerBackPicTable` and `gSpriteTemplateTable_TrainerBackSprites` are
   indexed by back-pic id with no `[id] =` on the rows. Those two blocks are
   emitted sorted by id and appended at the end of their arrays; the other
   seven arrays are designated and order-free.

   **`taar_gap/noland_back.png` — quantised, deliberately.** 64x256 (right
   geometry) but fully-opaque RGBA with 56 distinct colours. Chosen: mask
   everything within 8/255 per channel of the corner colour to slot 0 (alpha
   cannot do it — the backdrop is opaque), MEDIANCUT the rest to 15, dithering
   OFF. Compared against the original as a decoded contact sheet: hat, glove,
   vest and skin ramps survive, the loss is one step of forearm shading. The
   importer **refuses to quantise any file not named in its `QUANTISE` table**
   (negative control: remove the entry, it exits 1 and writes nothing).

   **Refuses to run, and re-derives its whole output** — the discipline
   `import_donor_front_pics.py` learned the hard way. Negative controls: hide
   `taar/korrina_ow.png` or `taar/lance_back.png` and it exits 1 naming them with
   nothing written. **But "still resolves" is not "still the same art":** hiding
   `rogue/oak_ow.png` leaves `taar/oak_ow.png` standing, the refusal never fires,
   the run reports "0 new" — and Oak's sprite silently becomes a different
   artist's drawing. Found by negative control, not by reasoning. A source change
   is now reported loudly (it is legitimate, it is never silent).

   Also fixed here: `import_sprites._block`'s after-anchor insert prepends a
   `\n` it never strips, so every re-run leaves one more blank line and the file
   is not byte-stable. The new tool anchors past the anchor line's own newline —
   three consecutive runs reproduce all 50 outputs byte-identical.

9. ✅ **Trainer card now draws all 16 badges — Johto in gold on a second row.**
   The old in-code comment blamed a tile collision ("a 16-badge loop pushes x to
   49 and badge 9's tiles collide with badge 1's"). That is true only of ONE row,
   and it hid the fact that the tile budget was never the problem:
   `badgeTiles` is `0x80 * NUM_BADGES` = **2048 bytes = 64 tiles**, uploaded by
   `LoadBgTiles(3, …, ARRAY_COUNT(...), 0)` against a bg3 template whose
   `.baseTile` is 192 — so tiles **192-255 were already reserved and uploaded**,
   while a badge sheet is only 1024 bytes = **32 tiles**. **Half of it was
   allocated, sent to VRAM, and left uninitialised.** The Johto eight go there
   (tiles 224-255) and a second row goes at y 17/18, which `front.bin`
   (600 entries = 30×20) leaves near-uniform.

   **Art**: `graphics/trainer_card/badges_johto.png`, 128×16 — the 8 Johto shapes
   converted from the pokecrystal decomp's own card sheet
   (`../Character Hacks/Prism-Character-Mode/tools/pokecrystal_donor/gfx/trainer_card/badges.png`,
   11 sprites of 16×16; the first 8 are Zephyr … Rising). That art is 2bpp and
   renders through `PREDEFPAL_CGB_BADGE`
   (`RGB 31,31,31, 26,21,22, 15,15,18, 00,00,00`) — near-greyscale even upstream
   — so **the user chose gold** (2026-07-28) and the 4 shades are remapped onto
   a light/mid/dark gold ramp.
   ⚠️ **It needs NO new palette and NO new palette slot.** It draws with
   `palNum 4`, which `SetCardBgsAndPals` already loads with `sTrainerCardGold_Pal`
   **unconditionally**, outside the Hoenn/Kanto branch. Index 0 is the same
   backdrop value the Hoenn sheet uses, so it stays transparent. The two rows
   deliberately use different tiles AND different palettes.

   **Placement was checked by rendering, not by arithmetic** — `front.bin`
   composited over `card.png` with both badge sheets pasted where the code draws
   them. After §7.4 that is the rule on this repo's screens, not an optional
   extra.

10. ✅ **`FLAG_FULL_RANDOMIZED_MODE` — SHIPPED as "Randomized Party Mode",
    mutually exclusive with Character Mode** (user ruling 2026-07-29). The
    gameplay analysis below was right and is why the ruling went that way. The
    *implementation* analysis was wrong in an instructive direction.

    ⚠️ **It was never a missing setter. It was a MISROUTED one.** The intro
    already ships a complete enable/disable/explain flow —
    `Start_EventScript_Game_Mode_Random_Party`, the donor's — and it set
    **`FLAG_PARTY_RANDOMIZED_MODE` (0x30), which no C in this fork reads.**
    Meanwhile `FLAG_FULL_RANDOMIZED_MODE` (9137, our own appended block) had the
    24 readers and no writer. Two halves of one feature, never joined: 2.X's
    script setting 2.X's flag, our engine reading ours. **The fix was repointing
    a flag, not adding a 10th checkbox row to `ModeFlags[]` — `NUM_MODES` is
    untouched and the tilemap was never involved.**
    The general lesson: *"no setter"* was derived from grepping C. The setter was
    in `data/`, under a different flag name for the same feature. **When a flag
    has readers and no writers, grep `data/` for the FEATURE, not just for the
    flag.**

    ⚠️ **And the menu it lives in was mislabeled — all of it.** Both
    `SCROLLING_GAME_MODES` and `SCROLLING_OTHER_GAME_MODES` pointed at `sSet6`, a
    17-entry list, while the two scripts switch on **9** and **14** cases.
    `SCROLLING_OTHER_GAME_MODES` had never been given a list at all. So picking
    "Perfect Iv Mode" set Grindless, "Randomized Mode" set Gym Shuffle, and
    "Random Party Mode" set plain Randomized — only "No Evs" and "Double Battle"
    happened to line up. This is the **menu↔script index drift** class that
    already hit the Blue Nurse and the Slateport ferry at the rebase; the modes
    menu had simply never been audited. `sSet6` is now the correct 9+Save list,
    `sSetOtherGameModes` is new and correct, and **`tools/check_mode_menus.py`
    pins all 25 rows to their switch cases and fails loudly on either side**
    (proven by negative control: `--self-test` swaps two rows and is caught).
    Perfect IVs / No Evolution / Leveless are not lost — the switch never had
    cases for them; they are set from the checkbox panel in `ui_mode_menu.c`.

    **The exclusion, enforced in four places** (all four must stay):
    - `Start_EventScript_Game_Mode_Random_Party` — enabling it while Character
      Mode is on prompts *"Turn Character Mode off?"*; NO changes nothing, YES
      clears `FLAG_CHARACTER_MODE` + `VAR_CHARACTER_ID`.
    - `Start_EventScript_Character_Mode` — the mirror prompt. It has to ask
      **before** opening the menu: `Task_MenuMain` has **no `B_BUTTON` case**, so
      the mode menu cannot be backed out of and entering it always commits a
      character. This is the only point where NO can still mean anything.
    - `ui_mode_menu.c` at the START commit — `FlagClear(FLAG_FULL_RANDOMIZED_MODE)`,
      and the debug toggle does the same, so the invariant holds on paths that
      never see a prompt.
    - `battle_main.c` at the `RandomizeParty()` call site — **Character Mode
      wins if both are somehow set.** This is the one that actually protects the
      roster (old saves, the debug toggle), and it is the guard to keep if any
      of the others are ever refactored away.
    - `Start_EventScript_Game_Modes_Default` ("all of the modes were disabled")
      cleared the dead 0x30 and so left the mode running; it clears 9137 now.

    Why the ruling was the right one, kept from the original analysis: its own
    Hall of Fame string calls it **"Random Party Mode"** (`hall_of_fame.c:1124`),
    which is the accurate name. Every full-random call site passes `SPECIES_NONE`
    to `GetRandomFirstStage`, taking the `Random() % POKEMON_FAMILIES` branch
    rather than the seeded one — a *fresh* roll every call, not the fixed
    per-save shuffle `FLAG_RANDOMIZED_MODE` gives. It also re-rolls **the whole
    party at the start of every battle** (`RandomizeParty`,
    `level_scaling.c:2325` — wipes all four move slots, replaces the species,
    renames, recalculates stats, regrants a moveset, keeping only the level);
    disables evolution (`pokemon.c:7089`); gives **every** species Bulbasaur's
    growth rate (`pokemon.c:9569`); disables New Game+ (`new_game.c:309`); hides
    the game-clear main-menu options (`main_menu.c:843/865/892`); and suppresses
    DexNav's own randomiser (`dexnav.c:959/1030/1188`). **`RandomizeParty`
    overwrites roster-legal Pokemon with arbitrary species, bypassing the catch
    gate** — teaching it the roster would have meant a per-battle roster-filtered
    reroll, i.e. a different feature. Exclusion was the smaller, honest answer.

11. ✅ **A LIVE HANG: four species had base stats and no learnset — FIXED
    2026-07-30.** `SPECIES_WYRDEER`, `SPECIES_URSALUNA`, `SPECIES_BASCULEGION`
    and `SPECIES_OVERQWIL` had base stats, dex numbers, pre-evolution rows and
    (since `fix_species_graphics.py`) complete battle graphics — and **no row in
    `gLevelUpLearnsets`, `gSpeciesNames`, `gMonFrontPicCoords` or
    `gMonBackPicCoords`.** Those are designated-initializer arrays, so the
    learnset entry was a **NULL pointer**, and three shipping loops walk that row
    with a `u8` index and no bound: `MonTryLearningNewMove`
    (`src/pokemon.c:4864`, every level-up), `MonTryLearningNewMoveEvolution`
    (`:9525`, every evolution) and the field-move scan in
    `src/party_menu.c:2851` (opening the party menu). A NULL read never yields
    `LEVEL_UP_END`, so the index wraps forever — **the game hangs.**

    ⚠️ **Basculegion is reachable in ordinary play.**
    `[SPECIES_BASCULIN_WHITE_STRIPED] = {{EVO_LEVEL, 43, SPECIES_BASCULEGION}}`
    is a LIVE row (its red- and blue-striped siblings use the dead
    `EVO_HUSIAN`), and Basculin-White-Striped has **22 wild-encounter slots**.
    Catch one, level it to 43, and the next level-up — or one press of A on it in
    the party menu — wedges the game.

    **The full fix landed:** all four learnsets copied verbatim from the donor
    (every move constant in them already exists here), their four pointer rows,
    their four `gSpeciesNames` rows spelled in full (12-char names, so the
    donor's `"Basculegn"` abbreviation is not needed), and front/back pic coords
    matching `[SPECIES_NONE]` — because these four still render the
    `CircledQuestionMark` placeholder, which is what that row describes. They
    remain art-blocked; that is accepted.

    ⚠️ **A clean build proved nothing here, and neither did five green graphics
    tables.** `fix_species_graphics.py` fills front pic / back pic / palette /
    shiny palette / front anims and knows nothing about learnsets, names or
    coords — so these four looked *fixed* and hung anyway.
    **`tools/check_species_tables.py`** now asserts that every species with a
    `gBaseStats` row has a row in all four of the other tables. Before the fix it
    named exactly those four; after, it is clean. Proven by negative control
    twice: delete the Basculegion pointer row and it exits 1 naming Basculegion;
    raise its extracted-set floor and it refuses to run rather than pass on an
    empty set.
    ⚠️ The remaining ~18 Legends: Arceus species (Kleavor, Sneasler, Enamorus,
    the 15 `_HISUI` forms) have **no base stats either**, so a `gBaseStats`-keyed
    check correctly ignores them. Do not port those.

    **And the hang itself is now a suite run.** `tools/mgba_scripts/
    basculegion_hang_e2e.lua` (34/34) creates a real Basculin-White-Striped at
    Lv43, evolves it through `GetEvolutionTargetSpecies`, and then RUNS all three
    scans via the new `CM_REQ_LEARNSET_PROBE` mailbox request. **The assertion is
    that they return at all.** Negative control: rebuild with the Basculegion
    pointer row deleted and the walk hits its 250 cap instead of `LEVEL_UP_END`,
    then the very next two requests **never answer** — the emulator is wedged
    inside the unbounded loop, and every later step fails on its deadline. That
    is the hang, reproduced on demand.

12. ✅ **11 learn-on-evolution moves restored** (2026-07-30). `LEVEL_UP_MOVE(0, X)`
    is this engine's **learn-on-evolution sentinel**, not level zero —
    `MonTryLearningNewMoveEvolution` grants it when a mon evolves, and there are
    330 such rows here. Eleven the donor has were missing: Gallade/Sacred Sword,
    Garchomp/Dig, Honchkrow/Beat Up, Houndstone/Last Respects, Inteleon/Snipe
    Shot, Malamar/Inverse Room, Meowscarada/Flower Trick, Pawmot/Supercell Slam,
    Quaquaval/Aqua Step, Skeledirge/Torch Song, Tinkaton/Gigaton Hammer.

    **Seven moves that were in the ROM but unobtainable now have an acquisition
    path**: Gigaton Hammer, Flower Trick, Aqua Step, Torch Song, Last Respects,
    Supercell Slam, Inverse Room. Gigaton Hammer in particular means the
    already-proven `gigaton_reselect_e2e` no-twice-in-a-row gate can be reached
    in actual play for the first time.

    ⚠️ **Only 3 of the 11 arrays differed from the donor by the level-0 line
    alone** (Houndstone, Inteleon — where ours had it commented out — and
    Tinkaton). The other 8 have further, pre-existing divergences that were
    deliberately NOT touched: Garchomp keeps our `(0, MOVE_CRUNCH)` **and** gains
    the donor's `(0, MOVE_DIG)`, so it now grants both on evolution where the
    donor grants only Dig; Gallade, Malamar, Meowscarada, Quaquaval, Skeledirge,
    Honchkrow and Pawmot each differ from the donor in other rows too. Anyone
    resyncing these arrays wholesale should read that list first.

13. ✅ **`map_species.py` did not reproduce the committed roster — FIXED
    (`6a6c5b56`, 2026-07-30).** Re-running the documented chain against HEAD's
    inputs gave **2775 → 2739 entries (−36)**, `unmatched_names.txt` 6 → 34, and
    Hala, Kabu and Kofu lost their `signature` key
    (`SIGNATURE UNRESOLVED: Kofu -> Crabominable`), which then hid **Kofu and
    Poppy** once `derive_drops.py` re-derived the threshold. **So the documented
    roster pipeline could not safely be re-run at all** — and nothing said so.

    **Cause.** `NAME_FIXES` maps Bulbapedia names to in-game display names and
    was written against the **10-character** `POKEMON_NAME_LENGTH`. `71cebcbe`
    raised it to 12 and restored the full spellings in `species_names.h`,
    orphaning **33 of the table's 42 rows** — `"Crabominable" -> "Crabminabl"`,
    `"Centiskorch" -> "Centiskorc"`, the whole Paradox block. `resolve()` returns
    `None` for an orphaned row, and `None` means *"the ROM does not have this
    species"* — **indistinguishable from a genuinely absent Hisuian form.**
    `rosters_mapped.json` was last generated the day *before* that commit, so the
    committed data was right and the **script** had rotted.
    ⚠️ `CharacterMode_FamilyBase` and the Crabrawler/Sizzlipede evolution data
    were never involved. Those three characters simply owned the affected ace
    names — which is exactly why the first diagnosis reached for the family walk.

    **Ground truth is the committed roster.** `SPECIES_CRABOMINABLE` and
    `SPECIES_CENTISKORCH` are real and obtainable; the regenerated file was
    deleting them. Kofu and Poppy are correctly selectable. After the fix the
    chain reproduces `rosters_mapped.json`, `character_drops.json`,
    `characters.h`, `ROSTERS.md`, `ROSTERS_SPRITES.md` and all 9
    `sprites/gen_*.md` **byte-identically**.

    **Three guards, each proven by negative control** (re-add a truncated row;
    point Kofu's ace at a dead name; point it at `Garchomp`; revert one
    `audit_keeps.json` name): a stale `NAME_FIXES` target, either signature
    failure path, and an unresolvable `audit_keeps.json` entry all now **exit 1
    and write nothing**. The signature drop was never a benign fallback — it
    downgrades the character to a random starter and can hide them.
    `audit_keeps.json` also had **23** names in the old 10-char spelling, so it
    was shielding nothing for them; normalized.

    ⭐ **The rule: a lookup table keyed on another file's contents is an
    undeclared dependency.** *"Not in the ROM"* and *"my table is stale"* are the
    same `None`. ⚠️ **Unbound, Lazarus, Radical Red and Seaglass all have a
    `NAME_FIXES` table and none of them has this guard** — measured 2026-07-30.
    Their rows may well still resolve (ROWE is the only game that took the 12/12
    change); the exposure is that nothing would tell them. **One unported check,
    not four new bugs.**

**Nothing here blocks a playthrough.** 1-3, 5, 6, 7, **9**, **10**, **11**,
**12** and **13** are done,
green and **committed** (`0f321aea`..`e5e40c83`). **4 was implemented and
reverted** — it is art-blocked after all, and the way that was established
(render the tilemap, do not reason about coordinates) is now the rule for this
repo's screens. **8b landed 2026-07-30.** **8 is the only real art wall left**,
and it is acquisition: as of that pass every staged sprite in every slot is
imported, and the tools to import a newly staged one already exist.

### So what is actually next, in order

1. **The playthrough (§7.7). It is 28 items, not 24** — recounted 2026-07-30 with
   `grep -c "^- \[ \]"`; the workspace total is **116**, not 112. Both numbers had
   been copied forward for sessions under a note that said *"recount it, do not
   copy it"*. Derive them.

   ⚠️ **"Nothing automated can close it" is true of the WHOLE and false item by
   item, and that distinction was costing real work.**
   📄 `../Character Hacks/game_plans/rowe_playthrough_coverage.md` maps all 28 to
   the assertion that already proves them: **14 fully machine-proven, 4 partly,
   6 automatable-but-not-yet, 2 genuinely human, 2 not tests at all.** Read it
   before working the list, or you will re-verify by hand what the suite asserts
   on every run.

   The irreducible human list is short: **look at your character** (item 19 — and
   it just got bigger, 27 new overworld sheets and 7 back pics landed 2026-07-30
   verified as decoded artifacts but never seen animating), **reach the credits**
   (item 28), and the residue of 3/25/26 — pick someone who is *not* Red and
   confirm scroll-and-commit, their set-piece gates, and costume persistence.

   ⚠️ **One checklist item was factually wrong until 2026-07-30**: it told players
   an off-roster catch goes to the PC. **ROWE refuses the ball**
   (`BattleScript_CharacterBallBlock`) and nothing reaches the box — that is the
   *other four games'* behaviour. Anyone following it would have filed a bug that
   was not one.
2. ✅ **The overworld / back-pic importer (§7.8b)** — DONE 2026-07-30.
2b. **The automatable playthrough gaps — 3 of 6 are now CLOSED** (`25a81317`,
   2026-07-30). `tools/mgba_scripts/mode_exclusion_e2e.lua` (72 assertions) covers
   items **21, 22 and 23** plus enforcement point 3. **The suite is 13 runs.**

   ⭐ **It is anchored twice, and the second anchor is the one to copy.**
   *"The party was not re-rolled"* passes equally when the exclusion works and
   when `RandomizeParty` never ran — the exact shape of the four vacuous checks
   this repo has shipped. So:
   - **In-band, permanently:** the same run turns Character Mode **off** with RPM
     still on and asserts the party **IS** re-rolled (≥3 of 4 slots changing
     species *and* move 0). If the feature ever goes dead, that control goes red
     first, in **every future run** — not just at commit time.
   - **Out-of-band, at commit time:** rebuilt with the
     `&& !FlagGet(FLAG_CHARACTER_MODE)` half of the `battle_main.c` guard deleted
     → **PASSED 64 / FAILED 8**, and the 8 were exactly the roster-protection
     assertions (slot species 25/1/4/7 → 298/1309/820/463, every move 0
     rewritten). Nothing else moved. Guard restored, md5 back to `4ba53b39…`.

   **A commit-time negative control proves the test could fail once. An in-band
   control proves it can still fail tomorrow.** Prefer both; if only one, the
   in-band one.

   ✅ **Items 3 and 16 are also closed** — `character_select_e2e.lua`
   (11 assertions) steers the menu to **Tobias, character 233**, and commits him.
   Every other drive in this suite takes the DEFAULT Gen I/Red pick, so the
   *scrolling* half of the game's only selection mechanism had never been
   exercised. The commit grants **Darkrai at level 10**, not Latios.
   ⭐ **He is one keypress away, not 232.** `CycleCharacter` skips entries whose
   generation does not match `genSelection` and **wraps** — and Tobias is the
   LAST selectable character in generation 4, so a single LEFT from anywhere in
   gen 4 lands on him.
   ⚠️ **The steering is closed-loop and that is not optional.** `gen_anchors.py`
   now exports `ui_mode_menu.c`'s file-static `cursorRow` / `genSelection` /
   `characterSelection`, so each phase reads where the menu actually is rather
   than counting keypresses — mGBA drops short taps, so a fixed count lands
   somewhere different every run. Same lesson `gTestMenuPtr` taught the intro.

   ⚠️ **Writing it exposed a hole in `run_suite.sh`, now fixed.** The first
   version called `H.finish()` after `D.run()` — but `D.run()` calls it itself,
   so the extra call fired at script LOAD and emitted
   `PASSED 0, FAILED 0 / RESULT: PASS` before a single frame ran. Had the real
   run then wedged, that empty summary would have been the only one and the
   runner, which reads the LAST `RESULT` line, would have called it a pass.
   **A run reporting PASS with zero assertions is now a failure**, proven by a
   throwaway script that does nothing but call `H.finish()`. Fifth entry in this
   repo's vacuous-pass ledger, and the first one caught by tooling rather than by
   someone noticing.

   Still open, in the order worth doing them:
   the **Randomized Party Mode exclusion** (items 21/22/23 — newest feature, four
   enforcement points, zero e2e coverage, and item 22 guards a screen with no
   cancel button, so it is the highest risk per unit of work); **Tobias's
   always-Darkrai starter** and **repeatable legendaries** (16/15 — a
   `starter_regression` variant, cheap); **the in-game trade path** (11 — audited
   statically, never driven); and **costume persistence across a reload** (26).
3. **Art acquisition (§7.8)** — 52 characters with no front pic, 217 with no back
   pic, 108 with no overworld art. Runbook is
   `../Character Hacks/SPRITE_PLAN.md`. Nine of the 52 (Paul, Zoey, Nando, Trip,
   Sawyer, Goh, Chloe, Cerise, Tobias) have no usable art anywhere searched, so
   the realistic ceiling here is well short of 236. The two open permission
   requests — **Emerald Enhanced** (would close Lusamine + Lillie's back pic;
   they "rarely decline") and **Wolfang62** (four professors) — are the
   highest-value moves and **nobody has asked yet**.
   📄 **Both are now DRAFTED** in `../Character Hacks/PERMISSION_REQUESTS.md`
   with a tracking table — ready to send, **not sent**. Sending is the user's to
   do, not an agent's.
   ⚠️ **An attribution debt is open on art already shipped.**
   `CREDITS_CHARACTER_MODE.md` claims a `harvest_index.json` in
   `sprites/donors/taar/` makes each file's author recoverable. **That file does
   not exist**, so six TAAR overworld sheets now in the ROM (Korrina, Acerola,
   Nessa, Bede, Larry, Palmer) cannot be attributed to an individual — weaker
   than TAAR's licence asks. Fix: re-fetch at `36b619ec…` and match by content.
4. **The selection-screen portrait (§7.4)** and any 10th mode row — both need the
   `ui_menu` tilemap redrawn. Same class as 2, not ahead of it.

⚠️ **"There is no open engine defect on this list" was WRONG when it was
written** — §7.11 was a live hang, reachable in ordinary late-game play, sitting
undetected behind five green checkers and an 11-run suite. It is fixed. Treat the
sentence as a claim to re-earn after each pass, not a standing property: what
found it was asking *"which tables does `fix_species_graphics.py` NOT know
about?"*, and the answer was four. §9 is the trap list to read first.

---

## 8. Commands

```bash
make -j$(nproc)                             # agbcc, MODERN=0. NEVER `make compare`.
python3 tools/check_name_lengths.py         # 16 checks — the gate for the 12/12 change
python3 tools/check_species_names.py        # abbreviated-species-name detector
python3 tools/check_mode_menus.py           # menu row <-> pory switch case drift (§7.10)
python3 tools/check_mode_menus.py --self-test   # its negative control
python3 tools/check_species_tables.py       # base stats <-> learnset/name/coords (§7.11)
python3 tools/mgba_scripts/gen_anchors.py   # MUST re-run after every build
bash tools/mgba_scripts/run_suite.sh        # all 14 runs, one line each (NEW 2026-07-30)
```

⚠️ **`run_suite.sh` is new because there was no runner** — every session
re-derived the invocation from `CLAUDE.md` prose and re-hit the same traps. It
encodes them: mint a fresh fixture `.sav` every time (they are build artifacts,
and a pre-2026-07-26 one is refused by design); never judge a run by its exit
code, because `H.finish()` does not stop the emulator so **every** run is killed
by `timeout` and exits 124; and redirect before grepping. It still cannot tell
you whether `anchors.lua` is stale — **`make` then `gen_anchors.py` first**, and
judge staleness by whether re-running changes the file, never by mtime.

The expected tallies are in a comment at the bottom of the script. **Compare
every one of them**: a changed tally is a regression even when the run still
says PASS.

**Save fixtures are GENERATED, never checked in.** Any `.sav` predating the
name-length change is refused by the ROM:

```bash
head -c 131072 /dev/zero | tr '\0' '\377' > ~/Documents/rowe_fixture.sav
CM_SAV_OUT=~/Documents/rowe_fixture.sav timeout 300 "$MGBA" \
    --script tools/mgba_scripts/make_fixture_save.lua pokeemerald.gba
```

The suite (**14 runs** as of 2026-07-30 — twelve scripts plus the two
`starter_regression` paths; `basculegion_hang_e2e` is the new tenth script, a
REAL script and not the phantom 12th §0 used to miscount). Logs are ~130 MB;
`timeout` exit 124 is NORMAL — the harness never exits on its own and the
RESULT line prints well before the timeout:

```bash
MGBA="../Character Hacks/Seaglass-Character-Mode/tools/mgba_src/build/mgba-headless"
export CM_SAV=~/Documents/rowe_fixture.sav
for t in boot_smoke continue_smoke ot_roundtrip_e2e legendary_encounter_e2e \
         encounter_doc_e2e catch_gate_e2e pc_sweep_e2e johto_gym_e2e \
         gigaton_reselect_e2e basculegion_hang_e2e; do
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
- **A flag with C readers and no C writer may be written from `data/` under a
  DIFFERENT NAME.** `FLAG_FULL_RANDOMIZED_MODE` was written up as "no setter" on
  the strength of a C grep; the setter was the donor's intro script, setting the
  2.X-named `FLAG_PARTY_RANDOMIZED_MODE` for the same feature. Grep `data/` for
  the FEATURE before concluding a flag is dead. (§7.10)
- **`scrollingmultichoice` menus are matched to their scripts BY POSITION and
  nothing checks it.** Ours are in `src/script_menu.c`, the switches are 2.X's in
  `data/`. Three menus have drifted so far (Blue Nurse, Slateport ferry, both
  Game Modes menus). `tools/check_mode_menus.py` now pins the two modes menus;
  the rest are still grep-and-read.
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
- **A species table with no row for a species is a NULL/zero entry, not an
  absence, and the engine does not check.** `gLevelUpLearnsets`, `gSpeciesNames`,
  `gMonFrontPicCoords`, `gMonBackPicCoords` and the five graphics tables are all
  designated-initializer arrays. A missing `gLevelUpLearnsets` row is a NULL
  pointer walked by three UNBOUNDED `u8` loops — it **hangs the game** (§7.11).
  A missing coords row is `size = 0`. `tools/check_species_tables.py` is the
  gate; run it after anything that adds a species.
- **`fix_species_graphics.py` fills FIVE tables and nothing else.** A species can
  pass every graphics check, build clean, render fine, and still hang. Filling
  the tables you thought of is not evidence about the tables you did not.
- **`make compare` will never pass** and is not the goal — this is a fork, not a
  byte-matching decomp.
- **`gen_anchors.py` must be re-run after every build**, or the mGBA scripts read
  stale addresses. It had not been, before the 2026-07-29 commit pass —
  `anchors.lua` predated the link by two minutes. ⚠️ **But mtime is the wrong
  test**: `make` relinks on every invocation even with nothing to do, so the ROM
  is *always* newer than the anchors afterwards. Compare `gen_anchors.py`'s **map
  digest** and whether re-running changes the file (`d8509533df699ec0` /
  no change, for this build), and compare the ROM by checksum
  (`08eef0c3f892247cfc16836c1078eb72`) rather than by timestamp.
- **A whitespace-only source edit can be verified for free.** Rebuild and compare
  the ROM md5; if it is identical, an already-green suite result carries over and
  does not need re-running. Used for a stray blank line in `ui_mode_menu.c`.
- **More than one session works in this tree.** Stage by name; **never
  `git add -A`.**
- **Never size a struct here with a modern compiler** (§4).
- The two legendary lists in §5 are hand-synced — change both or neither.
- **`gSelectionBattleScripts` holds the CURRENT instruction**, not the label — it
  advances within a frame or two, so test it as a range, never `==`.
