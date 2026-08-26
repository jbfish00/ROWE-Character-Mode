# PLAN.md — Pokemon ROWE, where everything stands

**Read this first if you are picking this repo up cold.** It is the per-repo
handoff across *every* workstream at once — Character Mode rosters, sprites, the
name-length expansion, playthrough readiness and the open engine work — plus the
traps specific to this tree.

`CLAUDE.md` (gitignored) remains the authority for architecture and history; this
file is **state and next steps**. Re-derived against this working tree on
**2026-08-09**, after a full rebuild, an anchor regeneration and a clean 19-run
suite. See §10 for that session.

🛑 **THE "What remains" TABLE JUST BELOW IS THE CURRENT OPEN-WORK LIST
(re-derived 2026-08-20, item 7 closed 2026-08-21).** Fourteen items, split by
who can actually do them: three need you, three need art that does not exist,
and **eight were ordinary code and test work — one of which is now done and one
half-done**. Read that table and §12; §0 and §7 further down are older.
⚠️ The suite is **22 runs** as of 2026-08-21, not 21.

🛑 **§0 AND §7 ARE OUT OF DATE (2026-08-19).** Three
specific things in them are now wrong, and all three are the kind that read as
authoritative: (1) **every one of §10's six "still unverified" leads was closed
on 2026-08-17**, and this file carried them as open; (2) the **ROM md5 is cited
three different ways in this file and all three are stale** — it is
`ead4fc6d7488c71361ba38314ccf10b0` at HEAD; (3) the suite is **21 runs**, not 19.
§12 also carries the session's own find — an 8-byte party-menu buffer the game
can write 16 entries into — and the measured, final answer on the SoulGold
sprite question.

🔴 **"There is no open code work" was TRUE and WRONG, and that is the lesson of
2026-08-09.** This file carried that headline for six days on the strength of an
18/18 green suite. An adversarial sweep then found **nine confirmed bugs**,
including two memory-safety defects reachable in ordinary play — one of them in
the first five minutes of a Nemona playthrough. Every one predated the green
run. The suite was not lying; it was answering a narrower question than the
headline claimed, and **nothing in it entered a Battle Frontier facility, opened
the party menu with a Gen 9 starter, or drove a PC deposit.**

⚠️ **Do not read a green suite as "the tree is correct".** Read it as "the paths
the suite covers did not regress". The gap between those two sentences is where
all nine lived. When you next want to write "there is no open code work", write
"no *known* open code work, last swept <date>" instead.

✅ **All nine are fixed as of 2026-08-09** (§10), suite 19/19 on ROM
`90fa8e3cf4fe57a0c092dd55c1743c60`. Superseded 2026-08-10 by the sprite import
(§11): current ROM `4d5cd678a8982fc82d66a75b8342e34a`, map digest
`bb34c4b8a4fa5e6f`, suite still 19/19.

**What remains — re-derived against the tree on 2026-08-20.**

⚠️ The previous version of this table opened *"and none of it is an agent's"*.
**That is no longer true**, and it was the sentence that made this section stop
being read: **rows 7-14 below are ordinary code and test work**, and eight of
them are things an agent should pick up. The old table also still carried a
"push the local commits" row that had been done since 2026-08-09.

**Nothing here is KNOWN broken.** Suite 21/21 on `ead4fc6d7488c71361ba38314ccf10b0`,
selftest 36/36 on every run, all five static checkers green, tree clean and level
with `origin/character-mode`. What follows is unfinished, not failing.

### Needs a person — an agent cannot do these

| # | item | why it is yours |
|---|---|---|
| 1 | **The playthrough** | **23 of 33** coverage rows are already machine-proven and 6 more partly. Read `../Character Hacks/game_plans/rowe_playthrough_coverage.md` BEFORE working the list or you will re-verify by hand what the suite asserts every run. What is genuinely left: reach the credits, look at your character animate, and pick someone who is **not Red** (the default, and a mid-table 7.6% early roster — every suite run uses him, so the automated coverage is built on him too) |
| 2 | **Send the two art-permission requests** | `../Character Hacks/PERMISSION_REQUESTS.md`, drafted and verified send-ready 2026-08-03, **still unsent**. Emerald Enhanced (closes Lusamine + Lillie's back pic) and Wolfang62 (four professors). They must come from your own account |
| 3 | **Decide on the Professor Elm mugshot** | `../Character Hacks/art_harvest_2026-08-19/` — format-clean 64×64 by **Mudskip**, and the ONLY candidate in the entire Heart & Soul family. It is a head-and-shoulders bust, not a full-body trainer sprite like every other `TRAINER_PIC_*`. Import steps and attribution are in that README. Pure look-and-feel; an agent should not make this call |

### Needs art that does not exist yet

| # | item | state |
|---|---|---|
| 4 | **52 front / 217 back / 64 overworld** of 236 | Derived 2026-08-20 from `tools/character_mode/sprite_report.txt`, not copied. **Every plausible donor is now measured empty**: TAAR (all 7,380 PNGs), Emerald Rogue (consumed), Recharged Yellow (no assets), and as of 2026-08-19 the whole Heart & Soul family — SoulGold, HnS and smithk200's expansion port — swept whole-tree, by constant, and by PNG dimension (§12.4). ⚠️ **The back-pic hypothesis is dead and it was the plausible one**: a Johto remake ought to carry Gen 1/2 leader backs and carries **none**. This needs a new class of source or commissioned art. The Hisui cast (25 characters) has **zero art of any kind in any slot** |
| 5 | **Selection-screen portrait / 10th mode row** | §7.4. Needs the `ui_menu` tilemap redrawn — re-verified 2026-08-03 by rendering the screen, largest free square is **0×0**. ⚠️ Do not re-measure this a fourth time |
| 6 | **Female icons for 15 gendered species** | `78512b0b` (2026-08-17) made `pokemon_icon.c` fall back to the male icon where the female table has NULL rows. That closed the **crash**; it did not author art. Starly line, Bidoof, Kricketot line, Shinx, Combee, Hippopotas line |

### Ordinary code and test work — an agent CAN do these

| # | item | why it matters |
|---|---|---|
| 7 | ✅ **DONE 2026-08-21 — the bound is MEASURED** | §12.6. `party_menu_actions_e2e.lua` (31) runs the real builder against the live party and all 1,463 species. **Both halves confirmed in-engine**: natural-moveset demand peaks at **9** (Charizard), which overflowed the old `u8[8]`; teaching Cut + Secret Power reaches **11**, which exceeds the window. The historical `MAX=20` fix, rebuilt as a control, reports **`tilemapTop` 253** — the u8 wrap, observed rather than argued |
| 8 | **The Nickname row: half proven 2026-08-21** | §12.6. Its PRESENCE in the action list is now asserted on a non-egg party mon, and deleting the append turns the run red. ⚠️ **The row's BEHAVIOUR is still undriven** — `CursorCb_Nickname` → naming screen → write is party-menu UI, which no headless run in this repo drives. Do not read "the Nickname row is tested" out of a green suite |
| 9 | ✅ **ROOT-CAUSED 2026-08-21 — and §12.3 blamed the wrong function** | §12.7. It is the **getter**, not the write guard: `GetBoxMonData` has an `else` branch vanilla does not, which zeroes both egg bits on every read of any encrypted field of a checksum-healthy mon — *before* the switch reads them. So `GetMonData(MON_DATA_IS_EGG)` **can never return 1**, anywhere. ⚠️ The FIX is a design decision and is NOT applied; see §12.7. Old text: §12.3. Neither egg bit can be written on a party mon in this tree, with the write proved to run. `SetBoxMonData`'s checksum guard is a silent `return` here where vanilla sets `isBadEgg` — so if that guard is firing, **every** encrypted write is silently droppable under some condition, and that is much bigger than the egg. Until it is understood, the ball swap's egg refusal is unproven |
| 10 | **`TakeSelectedPokemonFromDaycare` has no e2e** | The ungated-party-writer bug was fixed in `78512b0b`, but no script in `tools/mgba_scripts/` drives the daycare-withdraw path at all. Model it on `pc_sweep_e2e.lua` |
| 11 | **Only Falkner is proven playable as his own gym leader** | `johto_gym_e2e.lua` is the sole leader-as-player run; the other 15 leaders/E4 with rosters have no equivalent. The static argument that it generalises is in the 2026-07-17 session notes — it is an argument, not a run |
| 12 | **The learnset NULL sweep spot-checks 4 species** | `basculegion_hang_e2e.lua` covers exactly the four that hung the game in July. `tmhm_bound_e2e` and `pre_evolution_e2e` sweep exhaustively; this one does not, so a fifth malformed row would not be caught |
| 13 | **Two SoulGold QoL groups not ported** | Requested 2026-08-19, not built: **faster battle messages** (combine stat up/down and play them during the animation) + **music resumes** after battle instead of restarting; and a **shiny battle frame** + **fishing that yields items**. Music resume is the risky one — it needs `gMPlayInfo_BGM` state saved across the battle |
| 14 | **Cogita and Iscan emit no roster at all** | `emit_characters.py` reports `Skipped (empty roster): Cogita, Iscan`. They are not selectable, so nothing is broken — but two named characters silently produce nothing, and that has never been written down before |

⚠️ **Do not re-derive 4 or 5 from scratch — both are measured, and the negative
results are recorded.** Three sessions re-measured the `game_plans/rowe.md` drift
instead of acting on it; do not make that four.

> A mirror of this file lives at
> `/home/jbfish00/Documents/Character Hacks/game_plans/rowe.md`, alongside plans
> for the five ports. Keep them in step, or delete one — do not let them drift.

---

## 0. TL;DR

**The most feature-complete game in the project, and no longer blocked.** The
12-character-name change is landed, a live out-of-bounds write in the Pokedex is
fixed, the 1% legendary encounter rule is shipped, and the whole suite is green.
✅ **The encounter markers (§7.14) SHIPPED 2026-08-02/03** — the 10% roster
override and the 1% legendary now announce themselves by name in the wild-battle
intro, so a feature that was *unobservable* (it hands out a family root the map's
own table could equally have produced) is a yes/no reading.
✅ **Both remaining automatable test gaps are closed too** — the in-game trade
path (§7 item 2b / checklist 11) and costume persistence (checklist 26).
✅ **The TAAR attribution debt is paid** (§7 item 3).
⬜ **There is no open code work in this repo.** What is left is a human
playthrough, art acquisition, and two permission requests the user must send.

| | |
|---|---|
| Branch | `character-mode`, **working tree clean and LEVEL WITH `origin`** (`jbfish00/ROWE-Character-Mode`) at HEAD `89ef5ce7` — ✅ **pushed 2026-08-07**, which closes the one item that used to look like unfinished state. 25 commits landed 07-29 → 08-07. ⚠️ **Do not trust this row for HEAD** — several passes ended with a doc or anchors commit after the last feature commit. Re-check: `git rev-list --left-right --count origin/character-mode...HEAD` (`0  0` today) |
| Rosters | **AUDITED** — 236 table slots / **206 selectable** / 30 hidden, **3,359** rows, **every row sourced** |
| Threshold | **ENFORCED** — the only game in the project where it is |
| Sprites | **184 of 236** have a front pic (52 are `CHAR_ASSET_NONE`). Overworld **172 of 236** as of 2026-08-10 (128 → 172; was 101 on 07-29) and back pics **19 of 236**. ⚠️ **The overworld jump needed no new art and no permission** — 44 sheets were already in the pinned donor commit behind an untraversed path (§11). Of the 206 SELECTABLE characters: portrait 175, overworld 172, back 19 |
| Name length | **12/12 LANDED** (`71cebcbe`), verified by a new headless suite |
| Legendary rule | **SHIPPED** — 1% wild encounters, offered-until-caught, no roaming |
| Modes | **Randomized Party Mode SHIPPED** (`c231ba2a`), exclusive with Character Mode; both Game Modes menus de-drifted and pinned |
| Readiness | **GREEN** — selftest **36/36** and **all 19 suite runs passing** on `90fa8e3cf4fe57a0c092dd55c1743c60` (boot 2, continue 2, ot_roundtrip 17, legendary 20, encounter_doc 60, catch_gate 14, pc_sweep 10, johto_gym 13, gigaton 9, basculegion_hang 34, mode_exclusion 72, char_select 11, tobias_legend 14, enc_marker 41, trade_gate 10, **pre_evolution 2**, costume_persist 12, starter red 6 + normal 6). ⭐ **The tallies are ARGUMENTS to `run()` now, and the runner fails on a mismatch.** They sat in a bottom-of-file comment reading "compare EVERY run" while nothing compared them, and the self-test count was printed and never checked — deleting 35 of the 36 `Check()` calls still reported ALL RUNS PASS. Both are asserted (`EXPECTED_SELFTEST=36`), and both guards were broken on purpose to prove they fail. ⚠️ **ot_roundtrip is 17, not 19** — two of its assertions compared one Lua constant to another. ⚠️ **pre_evolution is NEW to the list** (2026-08-09); it had existed unrun since July while this file cited it as proof. It passes. **Run it with `bash tools/mgba_scripts/run_suite.sh`**. ⚠️ **Budget ~80 minutes and DETACH it.** Every run burns its full 240 s `RUN_TIMEOUT` by design (`H.finish()` does not stop the emulator) and the fixture step burns one too — 20 × 240 s. A foreground call under a shorter timeout dies mid-suite and reads as a hang; `setsid nohup … &` and poll. ⚠️ **Selftest 36 is the floor**: §7.14 added three checks and a 33 is a regression. Anchors regenerated first; map digest `0078bac7e41ab1e0`, second `gen_anchors.py` run byte-identical |
| Species tables | **COMPLETE** — every species with a `gBaseStats` row now has a learnset, a name and front/back pic coords, gated by `tools/check_species_tables.py`. Four had none and **hung the game** (§7.11) |

Every number above was re-derived from this tree, not taken from notes.
⚠️ The suite is **19 runs as of 2026-08-09** — seventeen scripts plus the two
`starter_regression` paths. It was **11** (nine scripts) until 2026-07-30, and for
three sessions §0 and §7 claimed 12 while §8 correctly said 11: that 12th was a
*phantom*. Since then: 12 `basculegion_hang_e2e` (§7.11), 13 `mode_exclusion_e2e`,
14 `character_select_e2e`, 15 `tobias_legendary_e2e` (all §7 item 2b), then
**16 `encounter_marker_e2e` (§7.14), 17 `trade_gate_e2e` (checklist item 11) and
18 `costume_persist_e2e` (checklist item 26)** on 2026-08-02/03. Do not fold the
two facts together; the tallies are in §7.

### If you are picking this up cold, start here

**Nothing is KNOWN broken.** Tree clean, **21/21 green** (see §12; it was
19/19 when this line was written), selftest 36/36. There is no rescue work waiting and **no open code work at
all** — see the handoff table at the top of this file for the five things that
remain, all of which need the user rather than an agent.
✅ **Everything is pushed** (HEAD `89ef5ce7`, level with `origin` as of
2026-08-07). Earlier revisions of this file warned that four local commits were
the one piece of state that looked like unfinished work; they are published now,
so there is nothing outstanding in git either.

1. **Sanity-check the tree before believing any of this**, in this order —
   `make -j$(nproc)` → `python3 tools/mgba_scripts/gen_anchors.py` →
   `bash tools/mgba_scripts/run_suite.sh`. Expect ROM md5
   `90fa8e3cf4fe57a0c092dd55c1743c60`, map digest `0078bac7e41ab1e0`, and a
   second `gen_anchors.py` run that changes nothing. (Both changed on
   2026-08-03 — the previous build was `4ba53b39…` / `45cfe76e469fceeb`.)
   ⚠️ **Regenerate anchors BEFORE the suite, and never judge staleness by
   mtime** — `make` relinks on every invocation, so the ROM is always newer.
2. **The largest remaining work is a human playthrough**, and it is genuinely
   the user's to do, not an agent's. §7 item 1. But read
   `../Character Hacks/game_plans/rowe_playthrough_coverage.md` first: **23 of
   the 33 coverage rows are fully machine-proven** and 6 more partly, so most of
   that list does not need a person at all. (Re-counted 2026-08-07 from that
   file's own status column; it said "22 of 34", and there is no 34th row.)
   ⚠️ **Before you go looking for automatable items in it: there are none left.**
   Items 11, 26, 12 and 13 all closed on 2026-08-02/03 and item 19's
   corruption half is answered by a contact sheet. What is left is reaching the
   credits and four judgement calls. Re-deriving that list is wasted work.
3. ✅ **"Nobody has watched one animate" is no longer true** (2026-08-03). All
   **22** characters from the 07-30 art batch were photographed in-engine
   walking in four directions by
   `tools/mgba_scripts/sprite_visual_check.lua`, and every sprite is coherent —
   no scrambled walk cycle, no half-sliced frames, no palette mangling. Contact
   sheet: `../Character Hacks/rowe_sprite_contact_sheet_2026-08-03.png`.
   ⭐ **`emu:screenshot(path)` works in HEADLESS mGBA.** That retires this
   repo's standing assumption that anything visual needs `mgba-qt` + xdotool,
   and it is why a visual check is now seconds rather than an afternoon.
   ⚠️ **`CM_REQ_SET_CHARACTER` alone photographs the WRONG character** — the
   player object keeps the graphics it was created with, so the shot shows the
   previous costume and looks perfectly fine. `CM_REQ_REFRESH_AVATAR` (the call
   `ApplyCostumeChoice` makes) is what repaints it.
   ⚠️ **The trainer BACK sprite is only on screen during the send-out throw.**
   A fixed delay photographs the transition wipe (blank) and waiting for the
   action menu photographs the battle after the trainer has already left — two
   reasonable-looking shots that both miss it. The script bursts the intro.
4. **Two things are waiting on the user specifically** and no agent should do
   them: send the two drafted art-permission requests
   (`../Character Hacks/PERMISSION_REQUESTS.md`), and decide about the TAAR
   attribution debt (§7 item 3).
5. ✅ **No automatable test gap is left.** Item 11 (the in-game trade path) and
   item 26 (costume persistence) both closed 2026-08-03; the list is empty.
6. ✅ **The encounter markers (§7.14) are DONE** — requested and shipped
   2026-08-02/03, message-only, rates untouched. **There is no open code work in
   this repo.** If you are looking for something to build, there isn't one; read
   §7 "So what is actually next" and expect a playthrough and art.

⚠️ **The most useful habit in this repo, stated once:** when a new assertion
goes green on the first try, **break it on purpose before believing it.** Five
vacuously-passing checks have shipped here. The fifth was caught by tooling
(`run_suite.sh` now fails a run that reports PASS with zero assertions) — the
first four were caught by someone happening to notice.

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
(2026-07-29). **Overworld 172 of 236** (128 → 172 on 2026-08-10, §11) and
**back pics 19 of 236**. Re-counted from `src/data/characters.h` on 2026-08-10:
`.trainerFrontPic` has **52** `CHAR_ASSET_NONE`, `.owGfxId` has **64**, and
`.backPic` has **217** `CHAR_ASSET_NONE_U8`.
⚠️ **Count the SENTINEL PER FIELD.** `.backPic` uses `CHAR_ASSET_NONE_U8`; the
other two use `CHAR_ASSET_NONE`. An exact-match comparison against the wrong one
reports all 206 selectable characters as having a back sprite instead of 19 —
which is exactly what happened while building the coverage artifact on
2026-08-09. Match on the `CHAR_ASSET_NONE` PREFIX.

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

14. ✅ **ENCOUNTER MARKERS — SHIPPED 2026-08-02/03.** Requested 2026-08-02,
    built and proven the same pass. Two new wild-battle intro messages, and
    **the rates were not touched**:

    | path | message |
    |---|---|
    | 10% roster override | `A wild {SPECIES} destined for\n{CHARACTER} appeared!` |
    | 1% legendary | `{SPECIES} revealed itself\nto {CHARACTER}!` |
    | anything else | the vanilla `Wild {SPECIES} appeared!` |

    ⭐ **Why it was worth doing.** A 10% override that returns a **family ROOT**
    is *unobservable*: rosters store canonical family bases, so it hands you a
    **Gible**, not a Garchomp — and a wild Gible is exactly what the map's own
    table might have produced. Platinum shipped the identical feature, a
    playthrough reported "no on-roster encounters", and **there was no bug**.
    Checklist items 12 and 13 asked a player to judge a ~10% and a ~1% rate by
    eye over "a few dozen encounters"; they are now yes/no readings.

    ### How it is wired

    - **The signal.** `CharacterMode_RollWildOverrideSpecies` gained an
      `outKind` out-param (NULL allowed), written **only** when it returns a real
      species. The kind itself lives in `sWildEncounterKind`
      (`src/wild_encounter.c`), read through
      `CharacterMode_{Get,Set}WildEncounterKind`.
      ⚠️ **It is in `wild_encounter.c`, not `character_mode.c`, for a linker
      reason worth knowing**: this tree's `ld_script.txt` names every object's
      sections explicitly and has **no `.data` output section**, so
      `static u8 x = 0;` in a file with no `sym_ewram.txt`/`sym_bss.txt` entry
      links as a reference into a *discarded* section. `wild_encounter.o` is
      already in `sym_ewram.txt`; `character_mode.o` is in none of the three.
    - **Both wild call sites now share one function**,
      `CreateWildMonWithCharacterOverride` — roll, make the mon, record the
      kind. Sharing it is what lets a test drive the shipping code path instead
      of a re-implementation that would agree with itself no matter what shipped.
    - **The message.** `battle_message.c`'s wild `else` branch of
      `STRINGID_INTROMSG`, tested **last** so `BATTLE_TYPE_LEGENDARY`,
      `BATTLE_TYPE_DOUBLE` and the Wally tutorial keep their exact vanilla
      strings. (A wild double has two opponents and only one could be the
      override, so it stays unmarked rather than naming half a battle.)
    - **`B_TXT_CHARACTER_NAME` = `0x3E`**, appended in `include/battle_message.h`
      and `charmap.txt`. `gCharacters[].name` is already charmap-encoded, so it
      copies straight out. Falls back to `gText_EmptyString2` when there is no
      active character — the copy loop dereferences unconditionally.
    - **Both language blocks got the strings.** The Spanish block keeps English
      text on purpose: *destinado/destinada* must agree with the species' gender
      and the string cannot know it, and its two neighbours
      (`sText_WildPkmnAppeared2`, `sText_TwoWildPkmnAppeared`) are already
      untranslated there. `GAME_LANGUAGE` is `LANGUAGE_ENGLISH`, so that block is
      compiled out today.

    ### The four traps, and what each cost

    1. ✅ **A flag set by the ROLL is not a property of the BATTLE.** Handled by
       setting the kind beside the mon's creation, never in the roll, and by
       `CreateWildMon` clearing it for **every** wild mon so a path written next
       year is unmarked by default. `CreateScriptedWildMon`,
       `CreateScriptedDoubleWildMon` and `CreateRoamerMonInstance` bypass
       `CreateWildMon`, so those three clear it explicitly.
    2. ✅ **The self-test's 4000-roll loops leak nothing** — they pass `NULL`.
       Asserted at every boot: *"200 rolls with no battle leave the marker clear"*.
    3. ✅ **The string was MEASURED, then rendered, then looked at.** Worst case
       is `A wild Brambleghast destined for` at **170 px** against B_WIN_MSG's
       **208** (26 tiles), and `to Crasher Wake!` at 86. Proven three ways:
       `tools/check_battle_strings.py` measures the worst of all
       236 × 1023 name combinations offline; `CM_REQ_BATTLE_STRING_WIDTH` makes
       the ROM measure its own printed string with `GetStringWidth`; and the two
       worst-case strings were built into a throwaway ROM and **screenshotted**
       (both fit, with margin). The offline model agrees with the ROM to the
       pixel on three real strings (146 / 119 / 131), and those three are pinned
       in the checker so the model cannot drift away from the engine.
    4. ✅ **The rates are untouched.** `legendary_encounter_e2e`'s "rate is
       consistent with 1% (15..75 of 4000)" and the boot self-test's rarity bound
       both still hold at their baseline tallies.

    ### The test: `tools/mgba_scripts/encounter_marker_e2e.lua` (41 assertions)

    **Six real battles in one run**, and *nothing is forced*:
    `CM_REQ_OVERRIDE_WILD_BATTLE` loops the shipping
    `CreateWildMonWithCharacterOverride` until the roll produces the kind under
    test, then starts the battle through `BattleSetup_StartWildBattle` — the same
    entry point `TryStandardWildEncounter` uses. Ordinary, roster override and
    1% legendary therefore all occur in the same run, so a marker hardwired
    either on or off fails one of them. Three in-band controls: an ordinary
    encounter **after** a marked one, a scripted spawn, and a bare
    `CreateWildMon` with the marker deliberately pre-set.

    ⭐⭐ **THE FINDING WORTH CARRYING: A NEGATIVE CONTROL CAN PASS AND STILL BE
    TELLING YOU SOMETHING.** Deleting `CreateWildMon`'s clear and rebuilding left
    the run **fully green** — because `CreateWildMonWithCharacterOverride` writes
    the kind on *every* call, `NORMAL` included, and so never depended on that
    clear. The clear exists for the four paths that do **not** go through the
    wrapper — outbreak, Feebas, DexNav, the trade mon — and **none of them was
    exercised**, so the one line protecting all four was untested. A sixth
    battle (`CM_REQ_PLAIN_WILD_BATTLE`) now drives that shape, and the same
    deletion turns the run red. **When a control passes, either the code is fine
    or your test does not reach it. Find out which.**

    Three commit-time controls, all re-broken on purpose:

    | break | result |
    |---|---|
    | delete `CreateWildMon`'s clear | 3 failures, **all** in `plain-wild-after-marked` |
    | delete the wrapper's `SetWildEncounterKind` | 8 failures, all in `roster` + `legendary` |
    | hardwire the roster marker ON | 9 failures, all in the four *unmarked* battles |

    ### Everything else that landed with it

    - **`ENCOUNTERS.md`** documents both messages (regenerated by
      `emit_encounter_docs.py` — the header text lives in the generator).
    - **`PLAYTHROUGH_CHECKLISTS.md` §4 items 12/13** rewritten from "judge a rate
      by eye" to "walk in grass until you see the line once".
    - **`game_plans/rowe_playthrough_coverage.md`** — rows 12, 13 and a new 12b.
    - **`tools/check_battle_strings.py`** is a new static gate (with
      `--self-test` as its negative control) — it also fails if a marker string
      is added to only one `GAME_LANGUAGE` block, or reworded to stop naming the
      character.

**Nothing here blocks a playthrough, and nothing on this list is open.** 1-3, 5,
6, 7, **9**, **10**, **11**, **12**, **13** and now **14** are done and green.
**4 was implemented and reverted** — it is art-blocked after all, and the way that was established
(render the tilemap, do not reason about coordinates) is now the rule for this
repo's screens. **8b landed 2026-07-30.** **8 is the only real art wall left**,
and it is acquisition: as of that pass every staged sprite in every slot is
imported, and the tools to import a newly staged one already exist.

### So what is actually next, in order

0. ✅ **The encounter markers (§7.14) — DONE 2026-08-02/03.** They were put
   ahead of the playthrough deliberately, because they change what a playthrough
   can *observe*: checklist items 12 and 13 are now yes/no readings instead of
   rates judged by eye, and the single most likely false bug report in this whole
   project ("I never saw an on-roster encounter") is no longer possible.
   Message-only; the rates were not touched.

1. **The playthrough (§7.7). It is 33 items** — recounted 2026-08-03 with
   `grep -c "^- \[ \]"`; the workspace total is **121**. It has been wrong four
   times (24 → 28 → 32 → 33); derive it, never copy it. Both numbers had
   been copied forward for sessions under a note that said *"recount it, do not
   copy it"*. Derive them.

   ⭐ **One more slice of it got measured on 2026-08-03.**
   `tools/character_mode/roster_playability_report.py` answers the data half of
   *"is this roster miserable to play"*: the game's own **3,729** wild slots
   against each roster, excluding the 10% override because the override is the
   floor everyone already has. **The median selectable character matches 2.0%**
   of the game's wild slots (mean 3.4%), and **26 characters match ZERO on the
   Hoenn opening routes.** For most characters the override is doing nearly all
   the work of letting you build a team — which is exactly why the §7.14 markers
   matter, and why *"I never saw an on-roster encounter"* was always the most
   likely false bug report. Sanity: Goh (86 families) 29.4%, Brendan 7.3%,
   Roxanne 2.0%, Tobias 0.0% (two legendaries, none in wild tables).
   ⚠️ Counts SLOTS, not encounter probability, and `early%` assumes the Hoenn
   opening though ROWE lets you start on any of eight islands. **Flags for which
   characters to watch, never verdicts, and never a gate.**

   ⭐ **2026-08-07: it prints a BEST 20 too, and that is the half the playthrough
   needs.** The report only ever showed the worst 20, which answers "who is at
   risk" and never "who should I play". Best early coverage: **Goh 28.1%, Oak
   17.4%, Juan 16.0%, Misty 13.9%, May 13.2%, Birch 12.5%, Ash 11.8%.**
   ⚠️ **Red — the DEFAULT pick, and the character every suite run uses — is
   7.6%.** So the automated coverage is built on a mid-table roster, and a
   playthrough done as Red will see the feature at less than its best. If the
   point of the run is to judge whether Character Mode feels good, pick from the
   top of that list; if it is to judge the worst case, pick from the bottom.
   Either is defensible, but it is a choice, and defaulting to Red makes it by
   accident.

   ⚠️ **This is now the ONLY thing on this list that an agent cannot advance**,
   and the sub-items that could be automated have been: 23 of 33 coverage rows
   are fully machine-proven, item 19's "is the art corrupt" half is answered by
   a contact sheet, and items 11, 26, 12 and 13 all closed on 2026-08-02/03.
   What is left is a person playing the game — level curve, whether a roster is
   miserable over 40 hours, whether the new prompts read clearly to someone who
   has not read the source, and reaching the credits.

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

   ✅ **Item 15 is closed too** — `tobias_legendary_e2e.lua` (14 assertions).
   His pool is exactly `{Darkrai, Latios}`, he **IS** flagged as an
   all-legendary roster, and after marking one CAUGHT the pool is **still 2**.
   That is the §1.2 exemption: applying the normal offered-until-caught filter
   to a wholly legendary roster would empty his wild pool and leave him nothing
   to meet.
   ⭐ **It carries an in-band contrast, and that is the point.** *"The pool still
   has 2 entries after catching one"* passes when the exemption works **and**
   when `repeatable` is hardwired TRUE for everybody — which would quietly make
   every character's legendaries farmable. So the run asks the same question as
   **Red** immediately afterwards and requires the opposite answer
   (`repeatable == 0`, and a different pool size). **A test that only ever
   exercises the exempt case cannot tell an exemption from a no-op.**

   ✅ **Items 11 and 26 closed 2026-08-03, so the list is now EMPTY.**

   - **Item 11, the in-game trade path** — `trade_gate_e2e.lua` (10 assertions).
     It had been "statically audited" for weeks, which meant nobody had run a
     trade: the sweep sits at **case 74** of the cutscene's state machine, after
     the fade and the free, so nothing short of running the whole cutscene
     reaches it. `CM_REQ_INGAME_TRADE` sets the two script vars and calls the
     same two specials the trade scripts call, in the same order.
     ⭐ **Discriminating pair**: off-roster incoming (Dracovish) → PC box count
     **+1** and party −1; on-roster incoming → box count **unchanged**. Without
     the second half a build that swept the whole party after any trade passes.
     ⭐ **The controls check themselves** — both species go through the gift gate
     first, so the 2026-07-24 failure (a roster sync silently made three tests'
     off-roster control on-roster) fails loudly here instead of going quiet.
     ⚠️ It trades away slot **1**, never slot 0: `SweepPartyToPC`'s `keptOne`
     guard refuses to empty the party, so an off-roster mon left alone would be
     KEPT and read as a broken gate.
     **Negative control:** deleting the sweep from both trade sites → exactly 2
     failures, both off-roster; the on-roster half stayed green.
   - **Item 26, costume persistence** — `costume_persist_e2e.lua` (12
     assertions). `VAR_COSTUME_CHARACTER` (17008) and `VAR_COSTUME_NUMBER`
     (0x409D) survive save → **reset** → Continue, alongside
     `FLAG_CHARACTER_MODE` and the party, so all three thirds of item 26 are
     proven on one reload.
     ⭐ **The control is the half that can fail**: it then writes *different*
     values, does **NOT** save, resets again, and requires the **saved** values
     back. A GBA reset zero-fills EWRAM, so a value that survives came out of
     flash — without this, "the var still reads 7" passes on a build where the
     reload never happened or the write never landed.
     ⚠️ **It is the only suite run that WRITES to its fixture** (it has to).
     It runs last, and `run_suite.sh` mints a fresh fixture per invocation.
   ⚠️ **Do not re-plan items 3, 15, 16 or 21/22/23 from an older copy of this
   list** — they are done, and an earlier version of this section described
   15/16 as "a `starter_regression` variant, cheap", which was wrong: they
   needed character-menu steering that did not exist.
3. **Art acquisition (§7.8)** — 52 characters with no front pic, 217 with no back
   pic, **64** with no overworld art (⚠️ this line said **108** until 2026-08-19;
   the 2026-08-10 Emerald Rogue import took overworld from 128 to 172 of 236 and
   the correction reached §0 and §11 but never this line). Runbook is
   `../Character Hacks/SPRITE_PLAN.md`. Nine of the 52 (Paul, Zoey, Nando, Trip,
   Sawyer, Goh, Chloe, Cerise, Tobias) have no usable art anywhere searched, so
   the realistic ceiling here is well short of 236. The two open permission
   requests — **Emerald Enhanced** (would close Lusamine + Lillie's back pic;
   they "rarely decline") and **Wolfang62** (four professors) — are the
   highest-value moves and **nobody has asked yet**.
   📄 **Both are now DRAFTED** in `../Character Hacks/PERMISSION_REQUESTS.md`
   with a tracking table — ready to send, **not sent**. Sending is the user's to
   do, not an agent's.
   ✅ **The attribution debt is PAID (2026-08-03).**
   `CREDITS_CHARACTER_MODE.md` claimed a `harvest_index.json` in
   `sprites/donors/taar/` made each file's author recoverable; **that file did
   not exist**, so six TAAR overworld sheets in the ROM could not be attributed
   to an individual — weaker than TAAR's licence asks.
   `tools/character_mode/rebuild_taar_index.py` re-fetches the tree at the
   recorded commit `36b619ec…` (still `main`'s HEAD) and matches **by content
   hash**: the staging pass copied rather than converted, so all **257** staged
   PNGs are byte-identical to their upstream files and **all 257 matched, zero
   unmatched**. `harvest_index.json` now exists for `taar/` and `taar_gap/`,
   covering **22 named artists**.
   The six: **Korrina** and **Acerola** → *Kasen*; **Nessa** → *Galaxeeh* **and**
   *aveontrainer* (⚠️ Galaxeeh's folder is *"Overworld Trainer Sprite Resizes"*
   and its README credits aveontrainer for the original — crediting only the
   resizer would have dropped the artist); **Bede** and **Larry** →
   *PurrfectDoodle (Eva)*; **Palmer** → *spilledpizza*.
   ⭐ **The script carries its own control**: Rowan's author was known
   independently from the artist's README *before* it existed, and it is
   asserted — so a matcher pairing files with the wrong upstream path fails
   loudly instead of emitting a plausible index of wrong names. It also refuses
   to write a partial index, because an index missing its misses reads as
   complete. **Re-run it in the same pass as any new TAAR staging**, or the
   credits claim goes stale again.

   📄 **MEASURED NEGATIVE, 2026-08-03: TAAR is EXHAUSTED for this roster — do
   not re-search it.** While the clone was on disk, all three missing slots were
   swept against the full upstream tree (789 overworld files, plus the front and
   back sets), by exact normalised name *and* by substring so nested layouts like
   `spilledpizza/…/DP_palmer.png` could not hide: **0 of 52 missing front pics,
   0 of 108 missing overworld, 0 of 217 missing back pics** have a TAAR file.
   The only four substring hits were false positives (Milo→*milotic*,
   Kabu→*kabuto*, Rika→*Erika*, Ress→*colress*), which is a good reminder that a
   name match is a candidate and not a find — the 07-29 harvest's own trap was a
   format-perfect `paul_front_pic.png` that is a cartoon stranger in a top hat.
   This confirms "every staged sprite in every slot is imported" and extends it:
   **the upstream source is also empty.** New art must come from a different
   donor or from the two open permission requests.
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
python3 tools/check_qol_items.py            # hand-maintained QoL item ids vs the generated block (§12)
python3 tools/check_qol_items.py --self-test    # its negative control
python3 tools/check_battle_strings.py       # marker strings fit B_WIN_MSG (§7.14)
python3 tools/character_mode/roster_playability_report.py [--csv]  # which rosters to watch
python3 tools/check_battle_strings.py --self-test   # its negative control
python3 tools/character_mode/rebuild_taar_index.py <taar-clone>  # art attribution
python3 tools/mgba_scripts/gen_anchors.py   # MUST re-run after every build
bash tools/mgba_scripts/run_suite.sh        # all 19 runs, one line each
# Visual check -- NOT a suite run, it asserts nothing about how art LOOKS.
CM_SAV=<fixture> CM_SHOTS=/tmp/shots CM_NO_BATTLE=1 CM_CHARS=112,113 \
  timeout 280 "$MGBA" --script tools/mgba_scripts/sprite_visual_check.lua pokeemerald.gba
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

The suite is **19 runs** as of 2026-08-09 — seventeen scripts plus the two
`starter_regression` paths. Logs are ~130 MB each; `timeout` exit 124 is NORMAL
— the harness never exits on its own and the RESULT line prints well before the
timeout, so **judge by the RESULT line, never by the exit code**.

**Use the runner, not a hand-rolled loop** — it mints a fresh fixture, encodes
every trap, and fails a run that reports PASS with zero assertions:

```bash
bash tools/mgba_scripts/run_suite.sh
```

⚠️ **The loop that used to live here listed ten scripts and is gone.** Six runs
have been added since it was written, and a hand-rolled loop that silently omits
a third of the suite prints all-green. If you need to run one script alone:

```bash
MGBA="../Character Hacks/Seaglass-Character-Mode/tools/mgba_src/build/mgba-headless"
CM_SAV=/tmp/fixture.sav timeout 240 "$MGBA" \
    --script tools/mgba_scripts/<name>.lua pokeemerald.gba > /tmp/t.log 2>&1
grep -aoE 'RESULT: [A-Z]+|PASSED [0-9]+, FAILED [0-9]+' /tmp/t.log | tail -2
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
- **`count` is a MACRO in this tree** (it preprocesses to `data[14]`), so a
  function parameter named `count` makes a header prototype and a textually
  identical definition fail with "conflicting types", naming the definition. Read
  `build/emerald/src/<file>.i` when a prototype and its definition disagree and
  you cannot see a difference. (§12.6)
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

---

## 10. Session 2026-08-09 — nine bugs behind a green suite

**An adversarial sweep of a tree this file called finished found nine confirmed
bugs.** All nine predated the 18/18 green run recorded above; none was a
regression from it. Four read-only agents were pointed at failure classes this
repo has actually shipped before — vacuous tests, roster-enforcement bypasses,
the newest code, and bounds/generator defects — and every claim below was
re-verified against the source before being acted on. Several agent claims did
**not** survive that check and were dropped; see "over-reported" at the end.

### The two that mattered

**1. `gTMHMLearnsets` / `sTutorLearnsets` were indexed past their ends.**
The tables stop at their highest designator — 1199 and 1207 elements — while
species ids run to `NUM_SPECIES-1` = 1481, and all three accessors index them
raw and then walk the returned pointer until they find `0xFF`. **49 species on
this branch's own rosters sit past that end.** Nemona's fixed starter is
`SPECIES_PAWMI`, id **1245**, granted at level 10 in the intro — and
`ShowPartyMenu` calls `CanMonLearnTMHM` twice plus `CanLearnTutorMove` once on
the highlighted slot to decide whether to offer Fly/Dig/Cut. So an ordinary
party-menu open, five minutes into that playthrough, read ~46 pointers past the
array and dereferenced whatever was there. Fixed by sizing both to
`[NUM_SPECIES]` (holes become NULL) plus bound and NULL checks in the accessors.

**2. The Battle Pyramid stores INDICES in its species field.**
`gBattlePyramid_1_LandMons` is twelve rows of ids 1..4 used as index 0..3 into
an **eight-entry** round table; `GenerateBattlePyramidWildMon` does
`id = species - 1`. The 10% roster override handed it a real species, so `id`
became several hundred and read kilobytes past the table, writing a garbage
species that then indexed `gBaseStats` and `gMonFrontAnimsPtrTable`. ~11% of
Pyramid encounters in Character Mode. The override is now refused inside both
frontier facilities, in the shared wrapper so every caller is covered.

### The other seven

| # | bug | shape |
|---|---|---|
| 3 | `FLAG_RANDOMIZED_MODE` remapped every override species via `GetWildPokemon`, deleting the feature while the marker still announced it | feature silently absent |
| 4 | Transform/Imposter defeated the catch gate — it read `gBattleMons[].species`, which a transformed Ditto overwrites with YOURS | gate reads mutable state |
| 5 | Depositing your last on-roster mon let the sweep's `keptOne` fallback keep an off-roster one **permanently** | guard asked the wrong question |
| 6 | `candidates[64]` truncated Goh's 83 non-legendary families; `ENCOUNTERS.md` advertised all 19 unreachable ones | silent cap |
| 7 | `gMonIconTable` missing exactly the four species that hung the game in July | gate covered only tables that had already bitten |
| 8 | `GetFormSpeciesId` indexed a 1482-entry table with a `species + 5000` palette tag | tag used as an id |
| 9 | `sTradingBoardTypes[19]` had 18 initialisers — Fairy missing, 19th row drawn from a NULL string | short initialiser list |

### Why the suite did not catch any of them

⚠️ **This is the part worth carrying.** The suite was green and honest. It simply
never enters a Battle Frontier facility, never opens the party menu holding a
Gen 9 starter, never drives a PC deposit, and never ticks Randomized Mode. A
green suite means *the covered paths did not regress*. It has never meant *the
tree is correct*, and this file said otherwise for six days.

Worse, four of its own checks could not have failed:

- The self-test's "mode off: everything allowed" asked about **Meowth, which is
  on Red's roster** — allowed either way, so the whole mode-off section passed
  with Character Mode still on. Its partner was a single sample of an ~11%
  event, a ~89% pass on a broken build.
- `run_suite.sh` carried the expected tallies in a comment saying "compare EVERY
  run" and **compared none of them**; the self-test count was captured, printed
  and never checked.
- `pre_evolution_e2e.lua` had existed since July, was cited in this file as
  proof, and **was not in the run list**.
- `ot_roundtrip` asserted `PLAYER_NAME_LENGTH > OT_NAME_LENGTH` — two Lua
  constants, 12 and 7. It could not fail for any build.

All fixed. Tallies are now arguments to `run()`, the self-test count is asserted,
and both new guards were broken on purpose to prove they fail.

### Tooling, same pass

`audit_rosters.py` fails if a roster outgrows `CHARACTER_MAX_ROSTER_CANDIDATES`
(read from the header, not duplicated). `check_species_tables.py` gained
`gMonIconTable` and asserts the two sized pointer tables are still
`[NUM_SPECIES]`. `rebuild_taar_index.py` no longer writes the partial index its
docstring promises it refuses to write, and its control now checks what the run
COMPUTED rather than re-reading the file it just wrote. Four generator insertion
idioms gained a blank line per run, which destroys "run it twice and diff" as an
idempotency test — fixed and each proven stable by simulation.

⚠️ **Over-reported, do not go looking:** the agents also flagged
`port_2x_species_aliases.py` as non-byte-stable (**it is stable** — simulated),
and claimed the `SPECIES_SHINY_PAL` rows were simply the wrong macro (they are
not; the engine's `formSpeciesId > SPECIES_SHINY_TAG` branch expects that tag —
the defect was the unbounded index, which is what got fixed).

### Still unverified, from the same reports — ✅ ALL SIX CLOSED 2026-08-17

This section listed six leads on 2026-08-09 and was never updated when they were
worked. **Every one of them is fixed**, across four commits on 2026-08-17, and
this file carried them as open for two more days:

| lead | closed by | what changed |
|---|---|---|
| `gMonFootprintTable` NULL holes | `78512b0b` | `src/pokedex.c` — 813 species with no footprint row now draw blank instead of dereferencing whatever follows the table |
| female icon/palette tables have NULL holes | `78512b0b` | `src/pokemon_icon.c` — falls back to the male icon for the 15 gendered species with no female row. ⚠️ This closed the CRASH, not the art: there is still no female-specific icon for those 15 |
| `TakeSelectedPokemonFromDaycare` ungated party writer | `78512b0b` | `src/daycare.c` — gated to match the July fix already applied to `_GiveEggFromDaycare` |
| `encounter_doc_e2e` has no floor on its probe set | `744af90f` | the run now asserts a minimum probe count, so a shrinking probe list goes red instead of green |
| `check_battle_strings.py` excludes apostrophe names | `744af90f` | unescapes `\'` and `\\` only. ⚠️ The first attempt broke the `\l` / `\p` / `\n` control codes and was caught by the pinned-ROM regression in the same commit — the checker's own worst case was wrong in both directions |
| porters assign ids positionally from a name-sorted list | `744af90f` | `port_2x_items.py` and `port_2x_species.py` now REFUSE to write if a committed id would move |

Plus one not on the list: `3239fd27` added `tmhm_bound_e2e.lua`, giving the
2026-08-09 unbounded-accessor fix the regression test it had been shipped
without.

⚠️ **The lesson is the same one §0 already carries, from the other direction.**
A "still unverified" list is as capable of going stale as a "nothing is broken"
headline. These sat as open leads through two sessions that could have read the
git log in one command. **Re-derive this section against `git log` before
believing any row in it.**

---

## 11. Session 2026-08-10 — 44 overworld sprites that were never missing

**Overworld coverage 128 → 172 of 236, and it cost nothing but reading the right
directory.** The characters were Alola 10, Galar 8, Kalos 7, Paldea 11 and
8 rivals (Arven, Gladion, Hau, Hop, Marnie, Nemona, Penny, Shauna).

⚠️ **This repo spent two weeks believing art acquisition was blocked on two
unsent permission emails. It was not.** Emerald Rogue keeps its own custom NPC
art under `graphics/object_events/pics/rogue/npc/<region>/`, separate from the
`pics/people/` tree the 2026-07-25 harvest read. The filter never traversed it,
reported it had consumed everything, and §7 item 3 recorded acquisition as
exhausted on that basis.

**It was not an upstream change.** The pinned commit `79c1df5f` and HEAD hold the
*same 158 files* — verified by diffing both trees. The art was there in July.

⭐ **The rule was already written in CLAUDE.md, in July, about a different tool:**
*a tool reporting nothing to do is not evidence there is nothing to do; check
what it actually reads.* It was written after `import_donor_front_pics.py --dry-run`
reported 0 and the conclusion "there is no un-imported art on disk" turned out
false. The identical mistake then happened to the overworld importer. **When a
harvest reports a directory consumed, print the directories it walked.**

### What was checked before staging, and why each check exists

- **Every one of the 44 was viewed.** The 07-28 harvest contained a
  format-perfect `paul_front_pic.png` that is a cartoon stranger in a top hat.
- **Backdrop confirmed at palette index 0** on all 44. `phoebe_back.png` once had
  hers at slot 6, which ships an opaque box round the sprite.
- **All 44 passed the importer's own `_checked_ow()`**, frame-boundary score
  included, before being staged — not after.
- `characters.h` differs from HEAD on **44 `.owGfxId` lines and nothing else**;
  `audit_rosters` still reads 236 / 2775 and `.selectable` is still 206.
  `map_species.py` was deliberately NOT re-run.

### What is still genuinely missing

**31 portraits and 34 overworld.** Swept TAAR (all 7,380 PNGs — 3 hits, all
already imported, so it IS exhausted), Emerald Rogue (now consumed), Pokémon
SoulGold (`Eemeliri/soulgold` — zero overlap; it is Kanto/Johto and ROWE already
has every one of those) and Pokémon Recharged Yellow (no obtainable assets; ROM
patch only, no source repo, nothing on The Spriters Resource).

The remainder is **Hisui** (Adaman, Akari, Irida, Kamado, Rei, Volo, Zisu) and
**anime-only** characters (Cerise, Chloe, Goh, Paul, Ritchie, Sawyer, Tobias,
Trip, Zoey, Nando). No mainline-region hack carries either group. This needs a
different class of source or commissioned art — **not** a permission reply.

⚠️ Paul, Zoey and Nando have single 16×22 frames in `sprites/donors/pokesho_field/`.
They are NOT importable: the player avatar needs a 9- or 18-frame strip, and the
importer refuses partial ids because falling through to a wrong `OBJ_EVENT_GFX_*`
is the documented crash. Do not "just wire them up".


---

## 12. Session 2026-08-19 — SoulGold's QoL, and a buffer that took twice what it held

**Two things came out of reading another hack: two QoL items worth porting, and
a definitive answer to a sprite question this file had already guessed at.** A
third thing came out of porting them, and it is the one that matters.

### What Pokemon SoulGold actually is

`Eemeliri/soulgold` is a **Gen 3 `pokeemerald-expansion` fork**, not the NDS
project its HeartGold-shaped name suggests. Lineage: `pokeemerald` → Pokemon
Heart & Soul (`PokemonHnS-Development/pokemonHnS`) → smithk200's expansion port
→ SoulGold. Full public C source, full `graphics/` tree, **the same Gen 3 asset
format ROWE uses**. No LICENSE file on any of the three, which is the scene norm;
credit is by convention and by named artist.

⚠️ **Most of its advertised QoL is stock `pokeemerald-expansion`, not SoulGold's
own work**, and ROWE — which is NOT expansion-based — already has its own
versions of nearly all of it: DexNav, followers, auto-run, an extended two-page
options menu, IV/EV display, and reusable TMs (the removal is commented out at
`src/party_menu.c`, `Task_LearnedMove`). **Do not port from its feature list
without checking the tree first**; the list is mostly a description of the base
it sits on.

### Ported (§12.1) — three QoL features, all global and always-on

| feature | what it does | covered by |
|---|---|---|
| **Zeromin** (`ITEM_ZEROMIN`) | a vitamin that resets all six EVs to zero. ROWE already had six single-stat EV-reducing berries; this is the all-at-once one | `qol_items_e2e.lua` |
| **Ball swap** | any Poke Ball used from the bag on a party member changes which ball it lives in, no refund. Balls already carried `.type = 1` so they already routed to the party menu; only a `.fieldUseFunc` was missing | `qol_items_e2e.lua` |
| **Nickname row** | rename any non-egg party member from the field party menu | ⛔ **nothing** |

**The item ids sit OUTSIDE the `ROWEITEM-PORT` markers on purpose.**
`port_2x_items.py` rewrites everything between them, so an id placed inside
would be erased on its next run. `tools/check_qol_items.py` is the gate that
turns a future collision into a build failure rather than a silent id clash that
would make every save holding a Zeromin read back a different item.

**The effects are split out of their party-menu callbacks** into
`CharacterMode_ZeroAllEVs` / `CharacterMode_SwapMonBall`, so the headless run
drives the same functions the items drive. Without that split the only honest
claim available would have been "statically audited" — the phrase this repo has
been burned by twice.

⚠️ **The suite does NOT drive the bag → party-menu UI**, for any of the three.
What is proven is effect logic and its refusal branches. The Nickname row is
**entirely unproven**: it is party-menu UI, and no headless run in this repo
drives that menu.

### 12.2 — The find: `PartyMenuInternal.actions` was `u8[8]` and takes 16

`AppendToList` (`src/start_menu.c:1749`) is `list[*pos] = newEntry; (*pos)++;`
with **no bound of any kind**, and `numActions` is the byte immediately after
`actions[]`. So the 9th append writes its entry **on top of the length counter**,
and every append after that lands wherever that corrupted counter now points —
into `palBuffer`.

The field builder can emit **up to 16 rows** for a single Pokemon: Summary, Fly,
Dig, Cut, Soft-Boiled, Teleport, Milk Drink, Sweet Scent, up to `MAX_MON_MOVES`
known field moves, Switch, Mail or Item, Follow/Unfollow, and Cancel.

**It does not take an exotic party member to pass eight.** ROWE lets any mon that
*can learn* Fly/Dig/Cut use them without knowing the move, so
`Summary + Fly + Dig + Cut + Switch + Item + Follow + Cancel` is **exactly 8**
with no field move known at all — one known Surf is the ninth.

Fixed: the buffer is `MAX_PARTY_MENU_ACTIONS` and all 17 append sites in
`party_menu.c` go through `AppendPartyMenuAction`, which refuses to write past
the end. `AppendToList` itself is untouched — it is shared with the start menu,
and changing it under another caller is a separate decision.

⚠️ **The bound is 9, and the first attempt at this fix got it wrong in an
instructive way.** It used 20 — comfortable headroom for the 16 rows the builder
can emit — which stopped the buffer overflow and **swapped it for a different
one**. `DisplaySelectionWindow` builds the action window as
`tilemapTop = 19 - (numActions * 2)` with `height = numActions * 2`, and
`tilemapTop` is a **u8**: 9 actions gives top 1 / height 18, exactly filling the
screen, and **10 gives 19 - 20 = -1, which wraps to 255**. So the window itself
imposes the ceiling, and sizing the buffer without checking what consumes it is
the same mistake one layer up. Rows past 9 are dropped deliberately, and because
Cancel is appended last it would be the first row lost, `AppendPartyMenuCancel`
gives it the final slot outright — B always closed the menu anyway, but a party
menu with no visible Cancel reads as a bug.

⚠️ **FOUND BY INSPECTION, NOT DEMONSTRATED IN-ENGINE.** The arithmetic above is
from reading the builder; **no run has observed a 9th append**. Do not promote
it to a proven live defect without one, and do not demote it to theoretical
either — nothing in the code prevented it. **This is the top open lead.**

### 12.3 — `MON_DATA_IS_EGG` cannot be written on a party mon here

`CM_REQ_SET_MON_EGG` was added to test the ball swap's egg refusal, and **it does
not work**. The request body was proved to run (a `0xE0000000` marker came back
in `mb->result`) and **both** egg bits still read back 0 afterwards — the
encrypted `MON_DATA_IS_EGG` *and* the plain unencrypted
`MON_DATA_SANITY_IS_EGG`. `SetBoxMonData`'s checksum guard is a silent `return`
here where vanilla sets `isBadEgg`, so a refused write leaves no trace at all.

**Root cause NOT established.** The request is kept because it is the only handle
on the question, and it carries a warning not to build a test on it — such a
test would pass by never creating an egg, which is this repo's single most
repeated failure shape. The egg-refusal branch of the ball swap is
correspondingly **unproven**. Second open lead.

### 12.4 — Sprites: the HnS family is a measured dead end

§11 recorded SoulGold as "zero overlap" on the strength of it being a Kanto/Johto
game. That guess was right, and it is now **measured across all three repos** —
SoulGold, base Heart & Soul, and smithk200's expansion port — by whole-tree
sweep (33,374 / 13,014 / 29,565 asset files), by every `TRAINER_PIC_*`,
`TRAINER_BACK_PIC_*` and `OBJ_EVENT_GFX_*` constant, and by classifying every
`P`-mode PNG by dimension so art filed under an unrelated name could not hide.

⚠️ **The back-pic hypothesis is dead, and it was the plausible one.** ROWE has
back pics for only 19 of 236, and a Johto+Kanto remake ought to carry backs for
Gen 1/2 leaders, E4 and Rocket admins. **It carries none.** All three ship only
the ~9–11 stock pokeemerald/FRLG back pics; `TRAINER_BACK_PIC_*` counts are
2 / 8 / 0. The only variation is that they reskin `brendan.png` → HGSS Ethan and
`may.png` → HGSS Lyra, both of which ROWE already has.

**One candidate exists in the entire family**, and it was NOT imported:
`soulgold/graphics/field_mugshots/elm.png` — a format-clean 64×64 P-mode
Professor Elm with the backdrop already at palette index 0, by **Mudskip**. It is
a **head-and-shoulders mugshot**, not a full-body trainer sprite, so it would sit
differently on the trainer card from every other `TRAINER_PIC_*`. Left for a
human to judge; the clones are gone but the path is recorded here.

**So the standing conclusion is unchanged and now much better founded: the
remaining 52 front / 217 back / 64 overworld need a different class of source or
commissioned art.** The Hisui cast (25 characters, zero art of any kind in any
slot) and the anime-only cast have nothing in any mainline-region hack.

### 12.5 — Numbers, re-derived

| | |
|---|---|
| ROM | **`ead4fc6d7488c71361ba38314ccf10b0`** at HEAD. ⚠️ §0 cites `90fa8e3c…`, §7 cites `4ba53b39…` and §10 cites `08eef0c3…` — **all three are stale**, and none matched the working tree even before this session |
| Suite | ✅ **ALL 21 RUNS PASS**, run to completion on this exact ROM. Every tally matched the count declared in `run_suite.sh`, and the in-ROM selftest read **36/36 on all 21**. Nineteen scripts plus the two `starter_regression` paths; §0 says 19, which predates both `tmhm_bound_e2e` (2026-08-17) and `qol_items_e2e` (today) |
| Anchors | map digest `844123840bbc68bc`, second `gen_anchors.py` run byte-identical |
| Checkers | `check_qol_items` (+ its self-test), `check_species_tables`, `check_mode_menus`, `check_name_lengths`, `check_species_names` all green; `audit_rosters` reads 236 characters / 2775 entries |

⚠️ **Read that green the way §0 tells you to.** It means the covered paths did not
regress. **None of the 21 runs opens the party menu's action window**, which is
where this session's two findings live — so the buffer bound and the Nickname row
are exactly as unproven after a 21/21 green as they were before it.

⚠️ **A trap re-learned the hard way today, already written in `run_suite.sh`'s
own header:** a test was rebuilt four times without re-running
`gen_anchors.py`, went red, and was misdiagnosed as a flaky intro drive and
"hardened" before the real cause turned up. **`make` then `gen_anchors.py` then
the run, every time.** The hardening was reverted.


## 12.6 — Session 2026-08-21: the party-menu bound, measured

**PLAN.md item #7 is closed.** Suite **22/22 PASS** on ROM
`315cbff9953219a12b742f40834ecf8d`, map digest `da136dd94eae5529`, selftest
36/36 on every run, every pre-existing tally identical to baseline.

⚠️ **The runner said "ALL 21 RUNS PASS" while 22 ran.** The total was a string
literal that the new run did not update — *the exact shape the comment fifteen
lines above it warns about* ("a tally that is printed but not asserted is
decoration"). It counts `run()` calls now. The per-run tallies were always
asserted; only the headline was decoration, which is why 22 green runs could
print a confident 21.

`tools/mgba_scripts/party_menu_actions_e2e.lua`
(**31** assertions, suite run 22) drives `CharacterMode_ProbePartyMenuActions`
and `CharacterMode_SweepPartyMenuActions` — two entry points at the bottom of
`src/party_menu.c` that run **the real builder** through the same dispatcher the
field menu uses, and report two numbers rather than one:

| | |
|---|---|
| `numActions` | what the menu would SHOW. Clamped by `AppendPartyMenuAction`, so it can never exceed 9 — and therefore **cannot settle anything on its own**: it reads identically on a build whose builder never wants a 9th row |
| `demand` | how many appends were ATTEMPTED, unclamped. A new one-byte counter in `party_menu.c`, reset where `numActions` is reset. **This is the number the finding needed** |

### What was measured

- **Natural movesets, all 1,463 real species, level 50, two-mon party, follower
  option on: the maximum demand is 9**, at `SPECIES_CHARIZARD` (6). **Nine
  appends into the `u8[8]` this buffer used to be is the overflow** — the 9th
  landing on `numActions` itself. §12.2's arithmetic was right, and it is now a
  measurement.
- **No species exceeds the WINDOW on a natural moveset — 0 of 1,463.** The two
  defects are not the same defect and this is where they separate.
- **Teaching Cut and Secret Power takes Charizard to demand 11**, which does
  exceed the window. Both are ordinary player moves (HM01, TM43), so **the
  `tilemapTop` underflow is reachable by an ordinary player**, not just in
  principle. The clamp holds: shown 9, `tilemapTop` 1.

### ⚠️ Two things §12.2 and CLAUDE.md say that are wrong

1. **"one known Surf is the ninth" — no.** Surf is in the builder's own
   break-list, along with Waterfall, Strength, Rock Smash, Dive, Fly, Flash,
   Soft-Boiled, Teleport, Milk Drink, Sweet Scent and Dig: knowing any of them
   appends **nothing**. Of the 14 `sFieldMoves`, exactly **two** can add a row
   from a known move — **Cut and Secret Power**. Cut is the sharp one: a mon
   that can *learn* Cut already has a tutor row, so knowing the move gives it a
   **second** Cut row.
2. **The Nickname row is not "one step closer", it is the step.** Rebuilt with
   the Nickname append disabled, the natural maximum drops from 9 to **8** — the
   old buffer's exact capacity. On a natural moveset the overflow was reachable
   **because** the Nickname row shipped on 2026-08-19. The feature and the defect
   arrived in the same commit.

### The controls, both proved red

- **`MAX_PARTY_MENU_ACTIONS` back to 20** — the historical wrong fix from §12.2 —
  rebuilt: `PASSED 29 / FAILED 2`, reporting shown **11** and **`tilemapTop`
  253**. That is the u8 wrap of `19 - 22`, observed in-engine for the first time.
  The test would have caught the first attempt at this fix.
- **Nickname append disabled**: `PASSED 29 / FAILED 2` — the Nickname assertion
  and the overflow headline, exactly the two that should move.
- In-band, every run: the automatic-follower option is turned on, probed, turned
  off and re-probed, and the demand must fall by **exactly one**. A probe
  returning a constant satisfies every inequality in the file and dies here.

### ⚠️ A hang found on the way, and why it is NOT a live bug

The first sweep **wedged the emulator at species 1208**. A progress marker (the
sweep writes the id it is about to probe before probing it) named it:
**`SPECIES_KLEAVOR`**. It, `SPECIES_SNEASLER` (1211) and `SPECIES_ENAMORUS` have
**no `gBaseStats` row at all** — so no name, no learnset, and the builder's
level-up scan walks a NULL row with a `u8` index and no bound. That is exactly
the §7.11 hang.

**It is not reachable in play**: all three are absent from every roster,
encounter table and trainer party, and with no base stats the engine cannot
create one. The sweep now skips ids with no `gBaseStats` row and **counts them
out loud** — 19 of 1,482. But it stands as a demonstration that **the July fix
filled four missing ROWS and left the LOOP unbounded**; anything that ever
produces one of those ids hangs the game.

### ⚠️ NEW LEAD, found while proving the above is unreachable

**`SPECIES_ENAMORUS` is in `sLegendaryFamilyBases[]` (`character_mode.c:214`)
and has no `gBaseStats` row.** Today that is harmless: the 1% legendary rule
builds its pool by walking `character->roster[]`, and **no roster contains
Enamorus** (checked: 0 hits in `src/data/characters.h`), so it can never be
offered. Kleavor and Sneasler are in no list at all.

**The day anyone adds Enamorus to a roster, the 1% rule offers a wild encounter
that hangs the game** — and nothing would stop them. `check_species_tables.py`
gates "every species WITH a `gBaseStats` row has a learnset", so a species with
**no** base-stats row is outside the check by construction, and Enamorus is a
perfectly legitimate-looking legendary name for a future roster pass to add.

Cheap fix, not applied here because it is a separate concern with its own
control to write: assert every entry of `sLegendaryFamilyBases` has a
`gBaseStats` row. That is the exact shape of the standing warning in §10 —
*"when you add a checker, list the tables that have NOT bitten yet"*.

### New plumbing

| request | id | note |
|---|---|---|
| `CM_REQ_PARTY_MENU_ACTIONS` | 39 | live party slot, touches no state |
| `CM_REQ_PARTY_ACTION_SWEEP` | 40 | species chunk; `howMany == 0` asks for `NUM_SPECIES` so the test does not mirror a `#define` behind three `#ifdef`s |
| `CM_REQ_SET_FOLLOWER_OPTION` | 41 | ⚠️ a request and **not** a `gTestStructOffsets` entry: `optionsAutomaticFollower` is a **one-bit bitfield**, so there is no byte a test could write without clobbering the options packed beside it. This was tried first and fails to compile — `cannot take address of bitfield` |

### ⚠️ Trap: `count` is a macro in this tree

`u32 f(u32 first, u32 count)` declared in a header and defined identically in the
.c fails with **"conflicting types"**, because `count` preprocesses to
`data[14]` — so the definition's second parameter is not the one the prototype
declared. The two lines are textually identical and the error names the
definition, which sends you looking at the wrong thing. **Read the `.i` file**
(`build/emerald/src/<file>.i`) when a prototype and its definition disagree and
you can see no difference.


## 12.7 — Session 2026-08-21: `MON_DATA_IS_EGG`, root-caused

**§12.3 named the wrong function, and the suspect it named is innocent.** It
blamed `SetBoxMonData`'s checksum guard — the silent `return` where vanilla sets
`isBadEgg`. That guard never fires on a healthy mon. What actually happens is in
the **getter**.

`GetBoxMonData`, for any field past `MON_DATA_ENCRYPT_SEPARATOR`:

```c
DecryptBoxMon(boxMon);
if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum) {
    fix = CalculateBoxMonChecksum(boxMon);
    SetBoxMonData(boxMon, MON_DATA_CHECKSUM, &fix);   // re-stamps, silently
}
if (CalculateBoxMonChecksum(boxMon) != boxMon->checksum) {
    boxMon->isBadEgg = 1; boxMon->isEgg = 1; substruct3->isEgg = 1;
} else {
    boxMon->isBadEgg = 0; boxMon->isEgg = 0; substruct3->isEgg = 0;   // <-- BUG
}
```

**Vanilla has no `else`.** This one clears both egg bits on every read of any
encrypted field of a checksum-healthy Pokemon — and it runs *before* the
`switch` that reads `substruct3->isEgg`. So the getter zeroes the bit and then
returns the zero it just wrote: **`GetMonData(mon, MON_DATA_IS_EGG)` cannot
return 1 in this tree for any Pokemon, ever.**

### Measured, not read — `tools/mgba_scripts/party_egg_diag.lua`

Reads the bits at their STORAGE locations and the checksum the guard compares,
so "the write was dropped" and "the write landed and the getter lies" stop being
one observation. On the starter, in order:

| step | sanity | encrypted | checksum |
|---|---|---|---|
| before anything | 0 | 0 | 38122 / 38122 MATCH |
| write SANITY (field 6, unencrypted, no guard) | **1** | 0 | 38122 / 38122 MATCH |
| write IS_EGG (field 45) | **1** | **1** | — |
| re-read raw, **no getter in between** | **1** | **1** | **54506 / 54506 MATCH** |
| one getter | 1 | **0** | — |
| re-read raw after that getter | **0** | **0** | 38122 / **54506 MISMATCH** |
| a second getter | 0 | 0 | 38122 / 38122 **repaired** |

The write is correct and durable across frames, and leaves the mon perfectly
consistent. One getter destroys it.

### Two consequences, and they have very different severities

1. **Permanent and total: eggs cannot be observed to exist.** Any read of an
   encrypted field un-eggs the mon. `ScriptGiveEgg` is the only live producer of
   `isEgg = 1` — the daycare sets it **FALSE** in both places (`daycare.c:994`
   and `:1029`), ROWE hands over hatched babies by design — and
   `ScriptGiveEgg`'s very next call is `GiveMonToPlayer`, whose first act is
   `GetMonData(mon, MON_DATA_IS_EGG, NULL)`. The egg is cleared before it
   reaches the party. ⚠️ **This means the Water Labyrinth Togepi and the
   mystery-gift Pichu arrive as ordinary Pokemon, not eggs.** Not yet driven
   in-engine — that is the obvious next run.
2. **Transient: encrypted writes are dropped for exactly one call.** The clear
   happens on a decrypted mon and `GetBoxMonData` re-encrypts **without**
   recomputing the checksum, so the stored checksum is briefly stale and
   `SetBoxMonData`'s guard drops encrypted writes. Measured as **self-healing**:
   the next encrypted read re-stamps it. So §12.3's fear — *"every encrypted
   write is silently droppable"* — is **real but one call wide**, not the
   open-ended hazard it was written up as.

### ⚠️ The fix is a DESIGN DECISION and is deliberately NOT applied

Two separable changes:

- **Unambiguous bug, no design implication:** the `else` branch mutates the mon
  and the function re-encrypts without recomputing the checksum. Under *any*
  intent that is wrong — if you clear the bits you must re-stamp. Safe to fix
  on its own.
- **Needs a ruling:** deleting the `else` restores vanilla egg semantics and
  makes gift eggs real eggs that must be hatched. That is a gameplay change.
  ROWE looks like it disabled eggs on purpose — `IsBoxMonBadEgg` is hardwired
  `retVal = FALSE`, `MON_DATA_SANITY_IS_BAD_EGG`'s setter is a documented no-op,
  and the daycare refuses to make eggs. Whether eggs are *meant* to work here is
  the user's call, not an agent's.

⚠️ **Until it is fixed, `CM_REQ_SET_MON_EGG` keeps its warning and the ball
swap's egg-refusal branch stays unproven** — a test built on it would still pass
by never making an egg. `CM_REQ_EGG_DIAG` (42) is a **diagnostic, not a test**,
and carries the same warning.

