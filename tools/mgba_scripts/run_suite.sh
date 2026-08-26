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
# Every run declares the assertion count it MUST produce. Until 2026-08-09 the
# expected tallies lived in a comment at the bottom of this file that said
# "compare EVERY run, a changed tally is a regression" -- and nothing compared
# them. Same for the self-test: the count was captured into $st, printed, and
# never checked, so deleting 35 of the 36 Check() calls still reported
# "ALL RUNS PASS". A tally that is printed but not asserted is decoration.
EXPECTED_SELFTEST=36

# ⚠️ DERIVED, not restated. This said "ALL 21 RUNS PASS" while 22 ran and all 22
# passed -- the run was added and the summary literal was not, which is the exact
# "tally that is printed but not asserted is decoration" shape the comment above
# warns about, one line lower down in the same file.
runs=0

run() {
    local name=$1 script=$2 expected=$3; shift 3
    runs=$((runs + 1))
    env "$@" timeout "$RUN_TIMEOUT" "$MGBA" \
        --script "tools/mgba_scripts/$script" "$ROM" > "$OUT/$name.log" 2>&1
    local res p f st sp sf
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
        return
    fi
    # A run can go green having quietly stopped asserting things: a probe list
    # that generated fewer rows, a loop that exited early, an assertion block
    # skipped by a changed precondition. RESULT: PASS cannot see any of that.
    if [ "${p}" != "$expected" ]; then
        fail=1
        echo "    ^ TALLY CHANGED: expected $expected assertions, got $p."
        echo "      A changed tally is a regression even when the run says PASS."
        echo "      If the change is intentional, update the expected count here."
    fi
    if [ -n "$st" ]; then
        sp=$(echo "$st" | awk '{print $2}')
        sf=$(echo "$st" | awk '{print $4}')
        if [ "$sp" != "$EXPECTED_SELFTEST" ] || [ "$sf" != "0" ]; then
            fail=1
            echo "    ^ SELFTEST CHANGED: expected $EXPECTED_SELFTEST passed / 0 failed, got $sp / $sf."
        fi
    fi
}

# 21 runs: nineteen scripts plus the two starter_regression paths.
# (18 until 2026-08-09, when pre_evolution_e2e was finally added to the list.)
#   run <name> <script> <expected assertions> [env ...]
run boot           boot_smoke.lua              2
run continue       continue_smoke.lua          2   CM_SAV="$FIX"
run ot_roundtrip   ot_roundtrip_e2e.lua        17
run legendary      legendary_encounter_e2e.lua 20
run encounter_doc  encounter_doc_e2e.lua       60
run catch_gate     catch_gate_e2e.lua          14  CM_SAV="$FIX"
run pc_sweep       pc_sweep_e2e.lua            10
run johto_gym      johto_gym_e2e.lua           13
run gigaton        gigaton_reselect_e2e.lua    9   CM_SAV="$FIX"
run basculegion    basculegion_hang_e2e.lua    34
run mode_exclusion mode_exclusion_e2e.lua      72
run char_select    character_select_e2e.lua    11
run tobias_legend  tobias_legendary_e2e.lua    14
run enc_marker     encounter_marker_e2e.lua    41  CM_SAV="$FIX"
run trade_gate     trade_gate_e2e.lua          10  CM_SAV="$FIX"
# pre_evolution_e2e existed since 2026-07 and was never in this list, while
# PLAN.md cited it as proof that pre_evolution.h matches evolution.h across all
# ~1470 species. A test nobody runs proves nothing; only the 9 hand-picked
# FamilyBase checks in the in-ROM selftest covered that table.
# Expected 2: the per-chunk assertion inside its loop fires ONLY on a mismatch,
# so a clean run emits just the two summary assertions (coverage + zero
# disagreements). A tally above 2 means real mismatches were found.
run pre_evolution  pre_evolution_e2e.lua       2
# Expected 4: Pawmi coverage, whole-table coverage, and the two SEPARATE in-band
# controls (CanSpeciesLearnTMHM and CanLearnTutorMove each still answer TRUE
# somewhere -- summing them hid a neutered accessor). Per-chunk steps assert nothing;
# reaching the end of the sweep IS the primary claim.
run tmhm_bound     tmhm_bound_e2e.lua          4
# ⚠️ costume_persist WRITES to its fixture (it has to -- it proves a save
# survives a reload). It runs LAST of the CM_SAV users so the mutated
# fixture cannot leak into another run, and the fixture is minted fresh
# every invocation anyway.
# Expected 21: the two SoulGold-derived QoL items (Zeromin's all-EV reset and
# the bag ball swap), added 2026-08-19. Both in-band controls -- "resetting an
# already-zero mon reports NO change" and "swapping to the ball it is already
# in reports NO change" -- are the assertions that can actually go red, and both
# were proved to by disabling the two guards and rebuilding (PASSED 19, FAILED 2,
# exactly those two, nothing else moving; guards restored, md5 back to
# 341ff5fc8285052f2d291b6bc74c5227).
# ⚠️ It does NOT drive the bag -> party-menu UI, only the effect functions the
# item callbacks call, and the egg-refusal branch is NOT covered at all. Read
# the script's header before treating this as full coverage of the two items.
run qol_items      qol_items_e2e.lua           21
# PLAN.md item #7. Runs the real party-menu action builder against the live
# party and against every species, and reports how many rows it ATTEMPTS as
# well as how many fit. Sweeps 1482 ids in 64-species chunks, so it is the one
# run whose tally moves if the species table grows -- 31 is with 1463 real
# species and 19 ids that have no gBaseStats row.
run party_actions  party_menu_actions_e2e.lua  31
run costume_persist costume_persist_e2e.lua   12  CM_SAV="$FIX"
run starter_red    starter_regression.lua      6   CM_PATH=red
run starter_normal starter_regression.lua      6   CM_PATH=normal

echo
if [ "$fail" -eq 0 ]; then
    echo "ALL $runs RUNS PASS.  logs: $OUT"
else
    echo "SUITE FAILED -- read the logs in $OUT"
fi
# The expected tallies are ARGUMENTS to run() now, not a comment here. They sat
# in this comment for months under the instruction "compare EVERY run" while
# nothing compared them, so a run could quietly stop asserting and still be
# scored green. Same for the self-test count -- see EXPECTED_SELFTEST above.
#
# ot_roundtrip went 19 -> 17 on 2026-08-09: two of its assertions compared one
# Lua constant against another and could not fail for any build.
exit "$fail"
