#!/bin/bash
# Run the whole headless suite and print one line per run.
#
#   bash tools/mgba_scripts/run_suite.sh
#
# There was no runner until 2026-07-30 -- every session re-derived the
# invocation from CLAUDE.md prose and re-hit the same traps. The traps are
# encoded here now; read them before changing anything.
#
# 1. ALWAYS `make` and then `gen_anchors.py` BEFORE running this. A suite that
#    passes on stale anchors is the exact shape of failure this repo keeps
#    hitting. This script refuses to run if anchors.lua is missing, but it
#    CANNOT tell whether it is stale -- and do not judge staleness by mtime,
#    because `make` relinks on every invocation so the ROM is always newer.
#    The real test is whether re-running gen_anchors.py changes anchors.lua.
#
# 2. EVERY run burns its FULL timeout. `H.finish()` does not stop the emulator,
#    so each mgba-headless call runs until `timeout` kills it and exits 124.
#    That is normal and is NOT a failure -- judge by the RESULT line, never by
#    the exit code. Total wall time is roughly RUN_TIMEOUT x number of runs.
#
# 3. Never pipe headless output through grep directly; redirect to a file and
#    grep the file.
#
# 4. `.sav` files are BUILD ARTIFACTS. The 12/12 name change bumped the
#    per-sector signature, so any pre-2026-07-26 .sav is refused by design and
#    the tests then A-mash a "Continue" that is not there. This script mints a
#    fresh fixture every time. Never check one in, never reuse a stale one.
#    make_fixture_save.lua needs CM_SAV_OUT to already exist as 128 KiB of 0xFF.

set -u
cd "$(dirname "$0")/../.." || exit 1

MGBA="${MGBA:-../Character Hacks/Seaglass-Character-Mode/tools/mgba_src/build/mgba-headless}"
ROM="${ROM:-pokeemerald.gba}"
RUN_TIMEOUT="${RUN_TIMEOUT:-240}"
OUT="${OUT:-/tmp/rowe-suite-$$}"

[ -x "$MGBA" ] || { echo "mgba-headless not found or not executable: $MGBA" >&2; exit 1; }
[ -f "$ROM" ]  || { echo "ROM not found: $ROM (run make first)" >&2; exit 1; }
[ -f tools/mgba_scripts/anchors.lua ] || {
    echo "anchors.lua missing -- run: python3 tools/mgba_scripts/gen_anchors.py" >&2; exit 1; }

mkdir -p "$OUT"
FIX="$OUT/fixture.sav"
python3 -c "open('$FIX','wb').write(b'\xff'*131072)"
CM_SAV_OUT="$FIX" timeout "$RUN_TIMEOUT" "$MGBA" \
    --script tools/mgba_scripts/make_fixture_save.lua "$ROM" > "$OUT/fixture.log" 2>&1

fail=0
run() {
    local name=$1 script=$2; shift 2
    env "$@" timeout "$RUN_TIMEOUT" "$MGBA" \
        --script "tools/mgba_scripts/$script" "$ROM" > "$OUT/$name.log" 2>&1
    local res p f st
    res=$(grep -oE 'RESULT: (PASS|FAIL)' "$OUT/$name.log" | tail -1)
    p=$(grep -oE 'PASSED [0-9]+' "$OUT/$name.log" | tail -1 | awk '{print $2}')
    f=$(grep -oE 'FAILED [0-9]+' "$OUT/$name.log" | tail -1 | awk '{print $2}')
    st=$(grep -oE 'CM-SELFTEST: [0-9]+ passed, [0-9]+ failed' "$OUT/$name.log" | tail -1)
    printf '%-18s %-13s pass=%-4s fail=%-4s %s\n' \
        "$name" "${res:-NO-RESULT}" "${p:-?}" "${f:-?}" "$st"
    # No RESULT line at all means the run wedged before finishing -- a failure.
    # And a run that reports PASS with ZERO assertions is not a pass either: a
    # script that calls H.finish() before D.run() emits an empty
    # "PASSED 0, FAILED 0 / RESULT: PASS" summary at load time, which is
    # indistinguishable from success to anything that only reads RESULT.
    # Caught exactly that way on 2026-07-30.
    if [ "$res" != "RESULT: PASS" ] || [ -z "${p:-}" ] || [ "${p:-0}" -eq 0 ]; then
        fail=1
        [ "${p:-0}" -eq 0 ] 2>/dev/null && \
            echo "    ^ ZERO assertions ran -- treating as failure, not a pass"
    fi
}

# 18 runs: sixteen scripts plus the two starter_regression paths.
run boot           boot_smoke.lua
run continue       continue_smoke.lua         CM_SAV="$FIX"
run ot_roundtrip   ot_roundtrip_e2e.lua
run legendary      legendary_encounter_e2e.lua
run encounter_doc  encounter_doc_e2e.lua
run catch_gate     catch_gate_e2e.lua         CM_SAV="$FIX"
run pc_sweep       pc_sweep_e2e.lua
run johto_gym      johto_gym_e2e.lua
run gigaton        gigaton_reselect_e2e.lua   CM_SAV="$FIX"
run basculegion    basculegion_hang_e2e.lua
run mode_exclusion mode_exclusion_e2e.lua
run char_select    character_select_e2e.lua
run tobias_legend  tobias_legendary_e2e.lua
run enc_marker     encounter_marker_e2e.lua   CM_SAV="$FIX"
run trade_gate     trade_gate_e2e.lua         CM_SAV="$FIX"
# ⚠️ costume_persist WRITES to its fixture (it has to -- it proves a save
# survives a reload). It runs LAST of the CM_SAV users so the mutated
# fixture cannot leak into another run, and the fixture is minted fresh
# every invocation anyway.
run costume_persist costume_persist_e2e.lua   CM_SAV="$FIX"
run starter_red    starter_regression.lua     CM_PATH=red
run starter_normal starter_regression.lua     CM_PATH=normal

echo
if [ "$fail" -eq 0 ]; then
    echo "ALL 18 RUNS PASS.  logs: $OUT"
else
    echo "SUITE FAILED -- read the logs in $OUT"
fi
# Expected tallies (compare EVERY run, a changed tally is a regression even if
# the run still says PASS): boot 2, continue 2, ot_roundtrip 19, legendary 20,
# encounter_doc 60, catch_gate 14, pc_sweep 10, johto_gym 13, gigaton 9,
# basculegion 34, mode_exclusion 72, char_select 11, tobias_legend 14,
# enc_marker 41, trade_gate 10, costume_persist 12,
# starter red 6 + normal 6.
# Selftest 36/36 -- was 33 until the §7.14 encounter markers added three checks
# (the kind tracks the species the roll returned; a roll that did not fire
# labels nothing; 200 rolls with no battle leave the marker clear).
exit "$fail"
