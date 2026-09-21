#!/usr/bin/env python3
"""Fail if anchors.lua was generated from a different pokeemerald.map than the
one sitting in the tree.

WHY THIS EXISTS -- and it is not hypothetical. run_suite.sh's trap #1 has long
said "ALWAYS make and then gen_anchors.py BEFORE running this", and then:

    "This script refuses to run if anchors.lua is missing, but it CANNOT tell
     whether it is stale -- and do not judge staleness by mtime ... The real
     test is whether re-running gen_anchors.py changes anchors.lua."

That claim was false the whole time. gen_anchors.py already writes a
`mapDigest` -- a sha1 of the very map it read -- and its own docstring claims
"the harness scripts assert on a map checksum to catch a stale anchors.lua".
No such assert existed: grep found exactly two references to mapDigest, the
line that wrote it and the line that stored it. Nothing read it.

The cost of that gap, measured: on 2026-09-19 a START-menu entry was added
(03466a10), the build shifted every ROM address, anchors.lua was NOT
regenerated, and ot_roundtrip / legendary / encounter_doc / catch_gate /
pc_sweep all went red together on intro navigation. The mechanism was never
diagnosed and the feature was reverted (3215ccd0) -- the revert restored a
byte-identical build, which silently made anchors.lua correct again, which is
why reverting "fixed" it. The feature was never the problem.

Concretely, that build moved Start_EventScript_Character_Mode from 0x0829F0FE
to 0x0829F566. That is the exact script intro_drive.lua breakpoints for "pick
Character Mode at questions index 2", so the driver waited at a dead address
and timed out.

Usage:  python3 tools/mgba_scripts/check_anchors_fresh.py
Exit 0 if fresh, 1 (with an explanation) if stale.
"""
import hashlib
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))
MAP = os.path.join(TARGET, "pokeemerald.map")
ANCHORS = os.path.join(HERE, "anchors.lua")


def main():
    for path, what in ((MAP, "pokeemerald.map (run make first)"),
                       (ANCHORS, "anchors.lua (run gen_anchors.py)")):
        if not os.path.exists(path):
            print("check_anchors_fresh: missing %s" % what, file=sys.stderr)
            return 1

    with open(MAP, encoding="utf-8", errors="replace") as f:
        actual = hashlib.sha1(f.read().encode("utf-8", "replace")).hexdigest()[:16]

    with open(ANCHORS, encoding="utf-8") as f:
        text = f.read()

    m = re.search(r'mapDigest\s*=\s*"([0-9a-f]{16})"', text)
    if not m:
        # An anchors.lua with no digest predates the guard, and is exactly as
        # untrustworthy as a stale one -- do not pass it.
        print("check_anchors_fresh: anchors.lua has no mapDigest -- regenerate "
              "it: python3 tools/mgba_scripts/gen_anchors.py", file=sys.stderr)
        return 1

    recorded = m.group(1)
    if recorded != actual:
        print("check_anchors_fresh: STALE ANCHORS -- anchors.lua was generated "
              "from a different build.\n"
              "  anchors.lua records map digest %s\n"
              "  pokeemerald.map is actually   %s\n"
              "Every ROM address in anchors.lua may have moved. Layers that set\n"
              "breakpoints will wait at dead addresses and fail as timeouts that\n"
              "look like feature bugs. Fix:\n"
              "  python3 tools/mgba_scripts/gen_anchors.py"
              % (recorded, actual), file=sys.stderr)
        return 1

    print("check_anchors_fresh: OK (map digest %s)" % actual)
    return 0


if __name__ == "__main__":
    sys.exit(main())
