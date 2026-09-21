#!/usr/bin/env python3
"""Every row the Character Mode roster screen will draw must be drawable.

src/character_roster_menu.c renders one row per family root straight out of
CharacterInfo.roster, with the row's label pointing INTO gSpeciesNames:

    items[i].name = gSpeciesNames[character->roster[i]];

There is no bounds check there and there cannot usefully be one -- the array is
indexed at draw time, so a bad id is an out-of-bounds read that renders as
garbage rather than crashing. That failure is silent, and it is per character,
so playing one of 237 characters would find it and the other 236 would not.

THIS READS THE BUILT ROM, NOT THE SOURCE, and that is deliberate. The first
version of this file parsed include/constants/species.h to resolve ids and had
to reimplement a chain of arithmetic #defines and #undefs (GEN_9_START + 115,
SPECIES_EGG redefined four times) -- i.e. reimplement the C preprocessor and
hope to match it. The shipped bytes are the thing the player sees; the source
is only how they got there. Same rule the ports follow: when a guard's effect
is compiled, assert on the compilation.

Asserts, per character, for every roster entry:
  [1] the name pointer lands inside gSpeciesNames and the label is TERMINATED
      within POKEMON_NAME_LENGTH+1 bytes (an unterminated label runs the text
      printer into whatever follows in ROM)
  [2] the label is non-empty and is not the SPECIES_NONE placeholder
  [3] no character lists the same root twice
And globally:
  [4] the ROM record count agrees with the number of rosters in characters.h
      -- two independent derivations, never a hardcoded literal
  [5] a probe far from index 0, because record 1 begins at byte 0 and decodes
      correctly under ANY stride

Usage:  python3 tools/check_roster_menu_renderable.py
Exit 0 if every row is renderable, 1 otherwise.
"""
import os
import re
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, ".."))
# Overridable so the negative test can tamper COPIES. It must never touch the
# real artifacts: the headless suite reads pokeemerald.gba while it runs, and a
# checker that corrupts the tree to prove itself is worse than no checker.
ROM = os.environ.get("CM_ROM") or os.path.join(TARGET, "pokeemerald.gba")
MAP = os.environ.get("CM_MAP") or os.path.join(TARGET, "pokeemerald.map")
CHARACTERS = os.environ.get("CM_CHARACTERS") or os.path.join(
    TARGET, "src", "data", "characters.h")
CHARMAP = os.path.join(TARGET, "charmap.txt")
GLOBAL_CONSTS = os.path.join(TARGET, "include", "constants", "global.h")

ROM_BASE = 0x08000000
# sizeof(struct CharacterInfo): 2 pointers + 2 u16 + 5 u8, padded to 4.
# Verified empirically against the ROM below rather than trusted from here.
STRIDE = 20
EOS = 0xFF


def die(msg):
    print("check_roster_menu_renderable: %s" % msg, file=sys.stderr)
    return 1


def map_symbol(text, name):
    m = re.search(r"0x([0-9a-f]{8})\s+%s\s*$" % re.escape(name), text, re.M)
    return int(m.group(1), 16) if m else None


def load_charmap():
    rev = {}
    if not os.path.exists(CHARMAP):
        return rev
    with open(CHARMAP, encoding="utf-8", errors="replace") as f:
        for line in f:
            line = line.split("@")[0]
            m = re.match(r"^\s*'?(.+?)'?\s*=\s*([0-9A-Fa-f]{2})\s*$", line)
            if m and len(m.group(1)) == 1:
                rev.setdefault(int(m.group(2), 16), m.group(1))
    return rev


def main():
    for path in (ROM, MAP, CHARACTERS, GLOBAL_CONSTS):
        if not os.path.exists(path):
            return die("missing %s (run make first)" % path)

    rom = open(ROM, "rb").read()
    mapping = open(MAP, encoding="utf-8", errors="replace").read()
    rev = load_charmap()

    m = re.search(r"#define\s+POKEMON_NAME_LENGTH\s+(\d+)", open(GLOBAL_CONSTS).read())
    if not m:
        return die("POKEMON_NAME_LENGTH not found")
    name_len = int(m.group(1))
    name_width = name_len + 1

    gCharacters = map_symbol(mapping, "gCharacters")
    gSpeciesNames = map_symbol(mapping, "gSpeciesNames")
    if gCharacters is None or gSpeciesNames is None:
        return die("gCharacters / gSpeciesNames not in pokeemerald.map")

    def off(addr):
        return addr - ROM_BASE

    def u16(o):
        return struct.unpack_from("<H", rom, o)[0]

    def u32(o):
        return struct.unpack_from("<I", rom, o)[0]

    def label(species):
        """Decode gSpeciesNames[species]; returns (text, terminated)."""
        base = off(gSpeciesNames) + species * name_width
        if base < 0 or base + name_width > len(rom):
            return (None, False)
        out = ""
        for k in range(name_width):
            b = rom[base + k]
            if b == EOS:
                return (out, True)
            out += rev.get(b, "\\x%02X" % b)
        return (out, False)

    placeholder, _ = label(0)          # SPECIES_NONE == "??????????"

    # [4] Independent derivation of the count: how many rosters the generated
    # source defines. Never a literal -- the hardcoded-count trap has fired
    # seven times in this workspace and never presents as a count error.
    src_rosters = re.findall(r"static const u16 sRoster_(\w+)\[\]",
                             open(CHARACTERS, encoding="utf-8",
                                  errors="replace").read())
    expected = len(src_rosters)
    if expected < 200:
        return die("parsed only %d rosters from characters.h -- the file shape "
                   "changed and every check below would be vacuous" % expected)

    def record_ok(i):
        o = off(gCharacters) + i * STRIDE
        if o + STRIDE > len(rom):
            return False
        namep, rosterp = u32(o), u32(o + 4)
        return (ROM_BASE <= namep < ROM_BASE + len(rom)
                and ROM_BASE <= rosterp < ROM_BASE + len(rom))

    count = 0
    while record_ok(count) and count < expected + 8:
        count += 1

    failures = []
    if count != expected:
        failures.append("gCharacters holds %d plausible records but "
                        "characters.h defines %d rosters -- stride %d or the "
                        "struct layout is wrong"
                        % (count, expected, STRIDE))

    rows = 0
    per_char = {}
    for i in range(min(count, expected)):
        o = off(gCharacters) + i * STRIDE
        namep, rosterp = u32(o), u32(o + 4)
        cname, cterm = "", True
        p = off(namep)
        for k in range(32):
            b = rom[p + k]
            if b == EOS:
                break
            cname += rev.get(b, "?")
        else:
            cterm = False
        if not cterm:
            failures.append("character %d: name is not terminated" % (i + 1))

        roster, p, seen = [], off(rosterp), set()
        while True:
            sp = u16(p)
            p += 2
            if sp == 0:
                break
            roster.append(sp)
            if len(roster) > 512:
                failures.append("character %d (%s): roster has no SPECIES_NONE "
                                "terminator within 512 entries" % (i + 1, cname))
                break

        per_char[i + 1] = (cname, len(roster))
        # [6] No ROWE character has an empty roster (measured: the smallest is
        # 1 entry). character_roster_menu.c DOES handle empty -- it prints "No
        # roster in this game." -- but that path exists for the ports, where
        # curated dexes really do empty some rosters (Lazarus 17, Seaglass 3).
        # In THIS game an empty roster means the data regressed, and without
        # this check it is invisible: a root of SPECIES_NONE simply terminates
        # the list early and every surviving row still validates. Found by the
        # negative test's root-is-species-none case.
        if not roster:
            failures.append("character %d (%s): empty roster -- the menu would "
                            "show the no-roster message, which should be "
                            "unreachable in ROWE" % (i + 1, cname))
        for sp in roster:
            rows += 1
            text, terminated = label(sp)
            if text is None:
                failures.append("%s: species %d points outside gSpeciesNames"
                                % (cname, sp))
                continue
            if not terminated:
                failures.append("%s: species %d label %r is not terminated "
                                "within %d bytes" % (cname, sp, text, name_width))
            if text == "":
                failures.append("%s: species %d has an empty label" % (cname, sp))
            elif text == placeholder:
                failures.append("%s: species %d renders as the SPECIES_NONE "
                                "placeholder %r" % (cname, sp, text))
            if sp in seen:
                failures.append("%s: species %d listed twice" % (cname, sp))
            seen.add(sp)

    # [5] A per-character probe that only ever runs character 1 proves nothing
    # about indexing -- record 1 starts at byte 0 and reads correctly under any
    # stride. Require a late record to have decoded sanely too.
    if count >= 200:
        late = per_char.get(count)
        if not late or not late[0] or late[1] == 0:
            failures.append("late-record probe failed: character %d decoded as "
                            "%r -- the stride is only proven near index 0"
                            % (count, late))

    if failures:
        for f in failures[:40]:
            print("FAIL: %s" % f, file=sys.stderr)
        if len(failures) > 40:
            print("... and %d more" % (len(failures) - 40), file=sys.stderr)
        return die("%d problems" % len(failures))

    print("check_roster_menu_renderable: OK -- %d characters, %d rows, every "
          "row terminated within %d bytes with a real name "
          "(late probe: #%d %s, %d rows)"
          % (count, rows, name_width, count, per_char[count][0],
             per_char[count][1]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
