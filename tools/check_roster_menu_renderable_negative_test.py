#!/usr/bin/env python3
"""Negative test for check_roster_menu_renderable.py.

Corrupts COPIES of the ROM / map / characters.h, never the real ones -- the
headless suite reads pokeemerald.gba while it runs, and a checker that
corrupts the tree to prove itself is worse than no checker.

Each tamper is a defect the roster screen would actually render:
  * a species id past the end of gSpeciesNames  -> row reads out of bounds
  * a name with its 0xFF terminator removed     -> printer runs into ROM
  * a roster pointing at the SPECIES_NONE label -> row shows "??????????"
  * a duplicated root                           -> a row appears twice
  * a wrong character count                     -> stride/layout disagreement
plus two controls that must still PASS.

EXPECT_CASES is a LITERAL. Every tally in this workspace computed from its own
run agreed with itself by construction -- delete a case and it reports
"6/6 ALL PASS, exit 0". Counting what ran and checking it against a hand-written
number is what makes deleting a case a failure.

Usage:  python3 tools/check_roster_menu_renderable_negative_test.py
"""
import os
import re
import shutil
import struct
import subprocess
import sys
import tempfile

EXPECT_CASES = 7

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, ".."))
CHECKER = os.path.join(HERE, "check_roster_menu_renderable.py")
ROM = os.path.join(TARGET, "pokeemerald.gba")
MAP = os.path.join(TARGET, "pokeemerald.map")
CHARACTERS = os.path.join(TARGET, "src", "data", "characters.h")

ROM_BASE = 0x08000000
STRIDE = 20


def sym(text, name):
    m = re.search(r"0x([0-9a-f]{8})\s+%s\s*$" % re.escape(name), text, re.M)
    return int(m.group(1), 16)


def main():
    for p in (ROM, MAP, CHARACTERS):
        if not os.path.exists(p):
            print("negative test needs a built tree (run make)", file=sys.stderr)
            return 1

    mapping = open(MAP, encoding="utf-8", errors="replace").read()
    gCharacters = sym(mapping, "gCharacters") - ROM_BASE
    gSpeciesNames = sym(mapping, "gSpeciesNames") - ROM_BASE

    tmp = tempfile.mkdtemp(prefix="roster-neg-")
    results = []

    def case(name, want, mutate):
        rom = bytearray(open(ROM, "rb").read())
        chars = open(CHARACTERS, encoding="utf-8", errors="replace").read()
        rom, chars = mutate(rom, chars)

        rp = os.path.join(tmp, "rom.gba")
        cp = os.path.join(tmp, "characters.h")
        open(rp, "wb").write(bytes(rom))
        open(cp, "w", encoding="utf-8").write(chars)

        env = dict(os.environ, CM_ROM=rp, CM_MAP=MAP, CM_CHARACTERS=cp)
        # Status taken directly, never through a pipe.
        rc = subprocess.run([sys.executable, CHECKER], env=env,
                            capture_output=True, text=True).returncode
        ok = (rc != 0) if want == "fail" else (rc == 0)
        results.append(ok)
        print("  %-4s [%s] rc=%d (want %s)" % ("ok" if ok else "FAIL", name, rc, want))

    def roster_ptr(rom, index):
        o = gCharacters + index * STRIDE
        return struct.unpack_from("<I", rom, o + 4)[0] - ROM_BASE

    case("control-clean", "pass", lambda r, c: (r, c))

    def bad_species(rom, chars):
        # Character 1's first root becomes an id far past the names table.
        struct.pack_into("<H", rom, roster_ptr(rom, 0), 0xFFF0)
        return rom, chars
    case("species-out-of-range", "fail", bad_species)

    def unterminated(rom, chars):
        # Strip the 0xFF from the label the first root points at.
        sp = struct.unpack_from("<H", rom, roster_ptr(rom, 0))[0]
        base = gSpeciesNames + sp * 13
        for k in range(13):
            if rom[base + k] == 0xFF:
                rom[base + k] = 0xBB     # a printable glyph, not a terminator
        return rom, chars
    case("label-unterminated", "fail", unterminated)

    def placeholder(rom, chars):
        # Point a root at SPECIES_NONE, whose label is "??????????".
        struct.pack_into("<H", rom, roster_ptr(rom, 0), 0)
        return rom, chars
    # NOTE: species 0 is the roster TERMINATOR, so this shortens the list
    # rather than rendering the placeholder. It must still not be silently
    # accepted as a clean roster -- see the assertion below.
    case("root-is-species-none", "fail", placeholder)

    def duplicate(rom, chars):
        p = roster_ptr(rom, 0)
        first = struct.unpack_from("<H", rom, p)[0]
        struct.pack_into("<H", rom, p + 2, first)
        return rom, chars
    case("duplicate-root", "fail", duplicate)

    def miscount(rom, chars):
        # Drop one roster definition from the source side only, so the two
        # independent derivations disagree.
        return rom, chars.replace("static const u16 sRoster_Red[]",
                                  "static const u16 sRosterX_Red[]", 1)
    case("count-disagreement", "fail", miscount)

    case("control-clean-again", "pass", lambda r, c: (r, c))

    shutil.rmtree(tmp, ignore_errors=True)

    if len(results) != EXPECT_CASES:
        print("RESULT: ran %d cases, EXPECT_CASES says %d -- a case was added "
              "or deleted without updating the literal"
              % (len(results), EXPECT_CASES), file=sys.stderr)
        return 1
    passes = sum(1 for ok in results if ok)
    if passes != EXPECT_CASES:
        print("RESULT: %d/%d FAILED" % (EXPECT_CASES - passes, EXPECT_CASES),
              file=sys.stderr)
        return 1
    print("RESULT: %d/%d ALL PASS" % (passes, EXPECT_CASES))
    return 0


if __name__ == "__main__":
    sys.exit(main())
