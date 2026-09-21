#!/usr/bin/env python3
"""Negative test for check_anchors_fresh.py.

A checker is only evidence if it can FAIL. This breaks the inputs on purpose,
four ways, and requires a non-zero exit each time -- plus two controls that
must still pass, because a checker that rejects everything is just as useless
as one that accepts everything.

EXPECT_CASES is a LITERAL, deliberately. Every tally in this workspace that was
computed from its own run agreed with itself by construction: delete a case and
it cheerfully reports "5/5 ALL PASS, exit 0". This file counts what it ran and
then checks that count against a number written down by hand, so deleting a
case is itself a failure.

Usage:  python3 tools/mgba_scripts/check_anchors_fresh_negative_test.py
"""
import os
import shutil
import subprocess
import sys
import tempfile

EXPECT_CASES = 6

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))
CHECKER = os.path.join(HERE, "check_anchors_fresh.py")
ANCHORS = os.path.join(HERE, "anchors.lua")
MAP = os.path.join(TARGET, "pokeemerald.map")


def run_checker():
    # Status taken directly. Never through a pipe -- that trap has fired in
    # this workspace twice, both times while validating a checker.
    return subprocess.run([sys.executable, CHECKER],
                          capture_output=True, text=True).returncode


def main():
    if not (os.path.exists(ANCHORS) and os.path.exists(MAP)):
        print("negative test needs a built tree: run make, then gen_anchors.py",
              file=sys.stderr)
        return 1

    tmp = tempfile.mkdtemp(prefix="anchors-neg-")
    keep_anchors = os.path.join(tmp, "anchors.lua")
    keep_map = os.path.join(tmp, "pokeemerald.map")
    shutil.copy2(ANCHORS, keep_anchors)
    shutil.copy2(MAP, keep_map)

    results = []

    def case(name, want, mutate):
        try:
            mutate()
            rc = run_checker()
        finally:
            shutil.copy2(keep_anchors, ANCHORS)
            shutil.copy2(keep_map, MAP)
        ok = (rc != 0) if want == "fail" else (rc == 0)
        results.append((name, want, rc, ok))
        print("  %-4s [%s] rc=%d (want %s)" % ("ok" if ok else "FAIL", name, rc, want))

    def write_anchors(text):
        with open(ANCHORS, "w", encoding="utf-8") as f:
            f.write(text)

    original = open(keep_anchors, encoding="utf-8").read()

    # Controls: the tree as generated must be accepted, before and after.
    case("control-fresh", "pass", lambda: None)

    case("stale-digest", "fail", lambda: write_anchors(
        original.replace(
            original.split('mapDigest = "')[1].split('"')[0],
            "deadbeefdeadbeef")))

    case("no-digest", "fail", lambda: write_anchors(
        "\n".join(l for l in original.splitlines() if "mapDigest" not in l)))

    case("missing-anchors", "fail", lambda: os.remove(ANCHORS))

    # The real 2026-09-19 case: anchors.lua untouched and correct-looking, but
    # the tree was rebuilt under it so every ROM address moved.
    def relink():
        with open(MAP, "a", encoding="utf-8") as f:
            f.write("\n/* simulated relink */\n")

    case("map-moved", "fail", relink)

    case("control-restored", "pass", lambda: None)

    shutil.rmtree(tmp, ignore_errors=True)

    passes = sum(1 for _, _, _, ok in results if ok)
    if len(results) != EXPECT_CASES:
        print("RESULT: ran %d cases, EXPECT_CASES says %d -- a case was added or "
              "deleted without updating the literal" % (len(results), EXPECT_CASES),
              file=sys.stderr)
        return 1
    if passes != EXPECT_CASES:
        print("RESULT: %d/%d FAILED" % (EXPECT_CASES - passes, EXPECT_CASES),
              file=sys.stderr)
        return 1

    print("RESULT: %d/%d ALL PASS" % (passes, EXPECT_CASES))
    return 0


if __name__ == "__main__":
    sys.exit(main())
