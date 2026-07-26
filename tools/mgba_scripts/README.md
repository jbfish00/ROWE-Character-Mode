# Headless mGBA test harness

Ported back from the Lazarus/Seaglass Character Mode projects. Replaces the
xdotool/mgba-qt drive for everything that doesn't need pixels: deterministic
frame-exact pad input, direct RAM read/write at linker-map addresses, and
(optionally) breakpoints.

## Pieces

- **`gen_anchors.py`** — extracts global addresses from `pokeemerald.map` into
  `anchors.lua`. Re-run after any build that may have moved EWRAM/IWRAM
  symbols. No reverse engineering: this is the luxury of a source build.
- **`harness.lua`** — `dofile` this from a test script: input queue
  (`H.press`/`H.sequence`/`H.mash`), memory (`H.rd8..wr32`), assertions
  (`H.assertEq`/`H.assertTrue`/`H.finish`), breakpoints (`H.breakpoint`,
  needs `MGBA_HEADLESS_DEBUGGER=1`).
- **`boot_smoke.lua`** — boots the ROM and reads back the **in-ROM self-test**
  (`src/character_mode_selftest.c`): 21 checks of family canonicalization,
  roster coverage, and the catch/gift gate, executed by the real in-ROM code
  at every boot under mGBA (hardware and other emulators skip it via
  `mgba_open()`), published to `gCharacterModeSelftestResult` in EWRAM.
- **The test mailbox** (`gCharacterModeTestMailbox`, same file) — Lua writes a
  request (set character / give item / set last ball / scripted wild battle /
  give mon / unlock / query), and the pump — called each frame from
  `CB2_Overworld` AND `BattleMainCB2`, mGBA-gated like the self-test —
  executes it with real game calls. Offsets: +0 magic "CMTB" u32, +4 request
  u8, +5 status u8 (1 done / 2 rejected), +6 argA u16, +8 argB u16,
  +12 result u32.
- **`catch_gate_e2e.lua`** — the Phase 6 battle e2e: proves the catch BLOCK
  (off-roster Meowth, Master Ball → BattleScript_CharacterBallBlock, no
  catch), the catch ALLOW (on-roster Pikachu → B_OUTCOME_CAUGHT → party), and
  the gift gate (off-roster → PC, on-roster → party) in one headless run
  (~10 s). Needs CM_SAV like continue_smoke.
- **`intro_drive.lua`** — the new-game intro drive (erased flash → Birch speech
  → naming screen → truck questions menu → Character Mode commit → the wall
  clock → the field) plus the step state machine, extracted from
  `starter_regression.lua` so new tests don't each grow their own copy.
  `starter_regression.lua` deliberately keeps its own copy: it is the
  regression gate for the intro itself, so the two can be diffed if a drive
  breaks. Also carries the mailbox request-id table — **keep `D.REQ` in step
  with the enum in `src/character_mode_selftest.c`**, the ids are positional.
- **`make_fixture_save.lua`** — mints a `.sav` in the **current** save format by
  driving a real new game and calling the game's own `TrySavingData`. Needed
  because the 12-character-name change bumped the per-sector signature, so every
  pre-change `.sav` (`rowe_test_skills.sav` and friends) is now refused by
  design — `SAVE_STATUS_OLD_FORMAT`, main menu offers New Game only. A stale
  fixture makes `continue_smoke`, `catch_gate_e2e` and `gigaton_reselect_e2e`
  fail in ways that look like engine bugs and are not. Regenerate, don't
  check a binary in:
  ```bash
  head -c 131072 /dev/zero | tr '\0' '\377' > ~/Documents/rowe_fixture.sav
  CM_SAV_OUT=~/Documents/rowe_fixture.sav timeout 300 <mgba-headless> \
      --script tools/mgba_scripts/make_fixture_save.lua pokeemerald.gba
  ```
  mGBA has no Lua "flush savedata" call; `loadSaveFile(path, false)` binds the
  file and writes through, so the script waits after saving. The output grows
  to 131088 bytes (mGBA's flash footer) — that is normal.
- **`ot_roundtrip_e2e.lua`** — the regression gate for the 12-character-name
  change. Note what it does **not** test: obedience. `IsMonDisobedient`
  (battle_util.c) has its whole body commented out and returns 0, and
  `IsTradedMon` is stubbed `FALSE` — the only two callers of `IsOtherTrainer` —
  so nothing in ROWE can disobey and an "it obeyed" assertion could not fail.
  It tests the real exposure instead: a `PLAYER_NAME_LENGTH` name truncating
  into the 7-byte OT field without overrunning into markings/checksum (the mon
  must not decode as a Bad Egg), full-length nicknames, and all of it surviving
  a save. **It sets the player name explicitly** — the intro A-mash yields a
  6-character name, shorter than `OT_NAME_LENGTH`, which never truncates and so
  would prove nothing.
- **`debug_r_input.lua` / `debug_r_bp.lua`** — one-off diagnostics kept as
  templates: RAM-probing `gMain.newKeys` for scripted input, and late-armed
  breakpoints (`MGBA_HEADLESS_DEBUGGER=1`). The bp script hardcodes function
  addresses from a specific `pokeemerald.map` — refresh before reuse.

## Run

The emulator is Seaglass's patched build (do not rebuild):

```bash
cd "~/Documents/Pokemon Rowe Alteration"
python3 tools/mgba_scripts/gen_anchors.py   # after a fresh build
timeout 120 "../Character Hacks/Seaglass-Character-Mode/tools/mgba_src/build/mgba-headless" \
    --script tools/mgba_scripts/boot_smoke.lua pokeemerald.gba \
    > /tmp/boot_smoke.log 2>&1
grep -E "CM-SELFTEST|RESULT" /tmp/boot_smoke.log
```

## Gotchas (inherited, do not relearn)

- `H.finish()` does **not** stop the emulator — always run under `timeout`.
- Never pipe headless output through `grep`/`head` — redirect to a file first.
- Headless runs ~1800 fps — bound every wait with a frame deadline.
- Breakpoints/watchpoints single-step the core once armed — arm late.
- `MGBA_HEADLESS_DEBUGGER=1` is required for `H.breakpoint` to register at
  all (stock headless returns id -1 and never fires).
- **The battle intro waits on a keypress** before the action menu appears —
  an input mash that only presses the key under test (e.g. R for the
  quick-throw) leaves the battle stuck in the intro forever, and the key
  "mysteriously does nothing". Interleave B taps (advance text; no-op at the
  action menu in singles) with the key under test. Cost a session to find:
  breakpoint on CanThrowLastUsedBall showed the input handler never ran.
