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
