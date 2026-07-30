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
| Sprites | **184 of 236** have a front pic (52 are `CHAR_ASSET_NONE`) — 168 → 184 on 2026-07-29: 9 newly staged from the 07-28 harvest, 7 Frontier Brains closed with zero new art. Back pics **12 of 236**, overworld **101 of 236**, both now TOOLING-blocked not art-blocked (§7.8b) |
| Name length | **12/12 LANDED** (`71cebcbe`), verified by a new headless suite |
| Legendary rule | **SHIPPED** — 1% wild encounters, offered-until-caught, no roaming |
| Modes | **Randomized Party Mode SHIPPED** (`c231ba2a`), exclusive with Character Mode; both Game Modes menus de-drifted and pinned |
| Readiness | **GREEN** — selftest 33/33 and **all 11 suite runs passing**, tallies identical to the pre-change baseline. Re-run 2026-07-29 on the art-pass build `e2b047c4…` (boot 2, continue 2, ot_roundtrip 19, legendary 20, encounter_doc 60, catch_gate 14, pc_sweep 10, johto_gym 13, gigaton 9, starter red 6 + normal 6) — every tally matches the `08eef0c3…` baseline exactly |

Every number above was re-derived from this tree, not taken from notes.
⚠️ The suite is **11 runs**, not 12 — §0 and §7 both said 12 while §8 said 11.
Nine scripts plus the two `starter_regression` paths; the 11 tallies are in §7.

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
   conversion. Also **224 of 236 have no back pic** (only 12 exist) and **135
   have no overworld art** — and for those two the blocker is now TOOLING, not
   art: 19 characters have overworld sheets and 6 have back pics staged and
   unused, because the only importer that reads `sprites/donors/` handles front
   pics alone. See §7.8b.
   ⚠️ The importer counts **238**, not 236 — it iterates the roster data, which
   still holds Cogita and Iscan, the two dropped from `gCharacters` entirely.
   Do not chase the off-by-one against the table's count; it is this.
   Sourcing leads are in `../Character Hacks/SPRITE_PLAN.md`, which is the
   runbook — not this file.

8b. **The next real sprite item is an overworld/back-pic importer, and it is
   CODE, not acquisition.** `import_sprites.py` resolves its donors from a
   scratchpad path that no longer exists, so it cannot be re-run; nothing else
   reads `sprites/donors/` for anything but front pics. Sitting staged and unused
   right now: **overworld sheets** for Jessie, James, Lyra, Korrina, Acerola,
   Nessa, Bede, Larry, Oak, Birch, Rowan, Anabel, Brandon, Greta, Lucy, Noland,
   Palmer, Spenser, Tucker (19), and **back pics** for Blue, Lance, Lyra, Phoebe,
   Calem, Serena (6).
   ⚠️ **The overworld slot is NOT the same one-line alias fix the Frontier Brains'
   front pics were.** `emit_characters.py` gates it deliberately — an id is
   accepted only if it is in `imported_ow.txt` or ends in `_NORMAL`, because
   plain NPC ids use a short anim table and **CRASH** when used as the player's
   own overworld sprite. Birch, Anabel, Brandon, Greta, Lucy, Noland, Spenser and
   Tucker all have an `OBJ_EVENT_GFX_*` constant already and it looks like a free
   win; wiring it would ship a crash. The slot needs a real player-grade 18-frame
   sheet built by `build_ow_sheet()`, which is what the staged donor strips are
   for. Also note `taar_gap/noland_back.png` has the right 64x256 geometry but
   ships RGBA with **56** distinct colours against 4bpp's 16 — a deliberate
   quantisation call, not an importer's guess.

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

**Nothing here blocks a playthrough.** 1-3, 5, 6, 7, **9** and **10** are done,
green and **committed** (`0f321aea`..`e5e40c83`). **4 was implemented and
reverted** — it is art-blocked after all, and the way that was established
(render the tilemap, do not reason about coordinates) is now the rule for this
repo's screens. **8 is the only real art wall left**, and it is acquisition:
every staged sprite is already imported.

### So what is actually next, in order

1. **The playthrough (§7.7).** 24 checklist items, 0 done. It is the largest
   piece of unfinished work in this repo and **nothing automated can close it** —
   the headless suite covers gates and data, not whether the game is any good to
   play. Three of the four newest features (the trainer card's second badge row,
   Randomized Party Mode's prompts, the wild-encounter block) are code- and
   render-verified but have never been seen by a player.
2. **An overworld / back-pic importer (§7.8b)** — this is now ahead of art
   acquisition, because it is CODE and the art is already on disk: 19 overworld
   sheets and 6 back pics staged and unreachable, because the only tool that
   reads `sprites/donors/` does front pics alone. Do NOT take the
   `OBJ_EVENT_GFX_*` shortcut; it ships a crash (the gate is there on purpose).
3. **Art acquisition (§7.8)** — 52 characters with no front pic, 224 with no back
   pic, 135 with no overworld art. Runbook is
   `../Character Hacks/SPRITE_PLAN.md`. Nine of the 52 (Paul, Zoey, Nando, Trip,
   Sawyer, Goh, Chloe, Cerise, Tobias) have no usable art anywhere searched, so
   the realistic ceiling here is well short of 236. The two open permission
   requests — **Emerald Enhanced** (would close Lusamine + Lillie's back pic;
   they "rarely decline") and **Wolfang62** (four professors) — are the
   highest-value moves and **nobody has asked yet**.
4. **The selection-screen portrait (§7.4)** and any 10th mode row — both need the
   `ui_menu` tilemap redrawn. Same class as 2, not ahead of it.

There is no open engine defect on this list. If one turns up, §9 is the trap
list to read first.

---

## 8. Commands

```bash
make -j$(nproc)                             # agbcc, MODERN=0. NEVER `make compare`.
python3 tools/check_name_lengths.py         # 16 checks — the gate for the 12/12 change
python3 tools/check_species_names.py        # abbreviated-species-name detector
python3 tools/check_mode_menus.py           # menu row <-> pory switch case drift (§7.10)
python3 tools/check_mode_menus.py --self-test   # its negative control
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
