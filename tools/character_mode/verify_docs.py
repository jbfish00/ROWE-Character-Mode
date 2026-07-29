#!/usr/bin/env python3
"""Prove ROSTERS.md describes exactly what the built ROM offers.

The docs are generated, but generated from the same intermediate files the ROM
is built from -- so a bug in the generator could still make them agree with each
other and disagree with the game. This checks them against `src/data/characters.h`
itself, which is what actually compiles into the ROM:

  1. every character in ROSTERS.md is present AND selectable in characters.h
  2. every selectable character in characters.h appears in ROSTERS.md
  3. every Pokemon listed under a character really is on that character's
     roster, expanded through evolution families exactly as the catch gate does
  4. no listed species is missing from the game's species table
  5. the counts in ROSTERS.md, ROSTERS_SPRITES.md and README.md agree
  6. no character has a DUPLICATED row, and each "Final evolutions (N)" header
     matches that character's DISTINCT row count
  7. the "N further characters remain in the data" claim matches the number of
     slots actually compiled with `.selectable = 0`

Checks 6 and 7 exist because this file used to compare a list against a list and
a JSON file against itself, so both of the defects they catch passed it: 17
characters carried a duplicated row (3376 == 3376) and ROSTERS.md promised save
compatibility for 32 hidden slots when only 30 existed. Both are proven by
negative control -- injecting either defect makes this exit 1 and name it.

Exit 1 on any mismatch. Run after emit_roster_docs.py.
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))


def read(path):
    with open(path, encoding="utf-8") as f:
        return f.read()


def main():
    header = read(os.path.join(TARGET, "src/data/characters.h"))
    names = dict(re.findall(r'static const u8 sName_(\w+)\[\]\s*=\s*_\("([^"]+)"\)', header))
    rosters = {k: [s for s in re.findall(r"SPECIES_\w+", v) if s != "SPECIES_NONE"]
               for k, v in re.findall(
                   r"static const u16 sRoster_(\w+)\[\]\s*=\s*\{(.*?)\};", header, re.S)}
    in_rom, selectable = {}, set()
    for m in re.finditer(r"\.name = sName_(\w+),.*?\.selectable = (\d+),", header, re.S):
        cid, sel = m.group(1), int(m.group(2))
        disp = names.get(cid, cid)
        in_rom[disp] = rosters.get(cid, [])
        if sel:
            selectable.add(disp)

    # the same family expansion the gate performs
    import importlib.util
    spec = importlib.util.spec_from_file_location(
        "erd", os.path.join(HERE, "emit_roster_docs.py"))
    erd = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(erd)
    kids = erd.evolution_children()
    collapse, siblings = erd.form_tables()
    display = erd.species_display_names()

    def family(base):
        out, stack, seen = set(), [base], set()
        while stack:
            cur = stack.pop()
            if cur in seen:
                continue
            seen.add(cur)
            out.add(cur)
            stack.extend(kids.get(cur, []))
            stack.extend(siblings.get(cur, ()))
        return out

    doc = {}
    doc_header_count = {}
    lines = read(os.path.join(TARGET, "ROSTERS.md")).splitlines()
    cur = None
    for line in lines:
        m = re.match(r"^### (.+?) — ", line)
        if m:
            cur = m.group(1).strip()
            doc[cur] = []
            continue
        m = re.match(r"^\*\*Final evolutions \((\d+)\):\*\*", line)
        if m and cur:
            doc_header_count[cur] = int(m.group(1))
            continue
        m = re.match(r"^\| (.+?) \| (.*?) \|$", line)
        if m and cur and m.group(1) not in ("Pokémon", "---"):
            doc[cur].append(m.group(1).strip())

    fails = []

    # A DUPLICATE ROW IS INVISIBLE TO A LIST-vs-LIST COMPARISON. Every count in
    # this file used to be len() of a list on both sides, so 17 characters
    # carrying a duplicated row (SPECIES_SANDSLASH_MEGA_ALOLA rendering as
    # "Alolan Sandslash", same as the plain form) inflated both sides equally
    # and 3376 == 3376 passed. Compare against the DISTINCT set, and say so.
    for char, listed in doc.items():
        dupes = sorted({mon for mon in listed if listed.count(mon) > 1})
        if dupes:
            fails.append("%s: duplicated row(s) in ROSTERS.md: %s"
                         % (char, ", ".join(dupes)))
        if char in doc_header_count and doc_header_count[char] != len(set(listed)):
            fails.append("%s: header says %d final evolutions, %d distinct rows"
                         % (char, doc_header_count[char], len(set(listed))))
    for char in doc:
        if char not in doc_header_count:
            fails.append("%s: no 'Final evolutions (N)' header in ROSTERS.md" % char)
    for char in doc:
        if char not in in_rom:
            fails.append("%s: in ROSTERS.md but not in characters.h" % char)
        elif char not in selectable:
            fails.append("%s: documented but NOT selectable in the ROM" % char)
    for char in selectable:
        if char not in doc:
            fails.append("%s: selectable in the ROM but missing from ROSTERS.md" % char)

    strip_region = re.compile(r"^(Alolan|Galarian|Hisuian|Paldean)\s+")
    for char, listed in doc.items():
        if char not in in_rom:
            continue
        allowed = set()
        for base in in_rom[char]:
            allowed |= family(base)
        allowed_names = {display.get(s) or erd.pretty(s) for s in allowed}
        for mon in listed:
            if strip_region.sub("", mon) not in allowed_names and mon not in allowed_names:
                fails.append("%s: doc lists %s, which is not on its ROM roster"
                             % (char, mon))

    # --- the sprite pages must mirror ROSTERS.md, cell for cell ----------
    sprite_chars, sprite_rows, missing_src = {}, 0, 0
    for path in sorted(os.listdir(os.path.join(TARGET, "sprites"))):
        if not re.match(r"gen_\d+\.md$", path):
            continue
        text = read(os.path.join(TARGET, "sprites", path))
        cur = None
        for line in text.splitlines():
            m = re.match(r"^### (.+?) — ", line)
            if m:
                cur = m.group(1).strip()
                sprite_chars[cur] = 0
                continue
            for cell in re.finditer(r"<sub>([^<]+)</sub>(<br><sub><i>([^<]*)</i></sub>)?", line):
                if cur is None:
                    continue
                sprite_chars[cur] += 1
                sprite_rows += 1
                if not cell.group(3):
                    missing_src += 1
    for char in doc:
        if char not in sprite_chars:
            fails.append("%s: in ROSTERS.md but missing from the sprite pages" % char)
        elif sprite_chars[char] != len(doc[char]):
            fails.append("%s: sprite pages show %d Pokemon, ROSTERS.md lists %d"
                         % (char, sprite_chars[char], len(doc[char])))
    for char in sprite_chars:
        if char not in doc:
            fails.append("%s: on a sprite page but not in ROSTERS.md" % char)

    counts = {}
    for path, pat in (("ROSTERS.md", r"\*\*(\d+) playable characters"),
                      ("ROSTERS_SPRITES.md", r"\*\*(\d+) characters"),
                      ("README.md", r"one of (\d+)")):
        m = re.search(pat, read(os.path.join(TARGET, path)))
        counts[path] = int(m.group(1)) if m else None
    if counts["ROSTERS.md"] != len(doc):
        fails.append("ROSTERS.md header says %s, lists %d" % (counts["ROSTERS.md"], len(doc)))
    for path in ("ROSTERS_SPRITES.md", "README.md"):
        if counts[path] is not None and counts[path] != len(doc):
            fails.append("%s says %s characters, ROSTERS.md lists %d"
                         % (path, counts[path], len(doc)))

    # The hidden-slot claim is a promise about SAVE COMPATIBILITY, so it has to
    # match the compiled table, not character_drops.json -- a character whose
    # roster comes out empty in this dex is dropped from gCharacters entirely
    # and has no slot to keep. The drops file says 32; only 30 slots exist.
    hidden_in_rom = len(re.findall(r"\.selectable = 0,", header))
    for path in ("ROSTERS.md", "ROSTERS_SPRITES.md"):
        m = re.search(r"(\d+) further characters remain in the data",
                      read(os.path.join(TARGET, path)))
        if m and int(m.group(1)) != hidden_in_rom:
            fails.append("%s claims %s hidden characters, characters.h compiles %d "
                         "slots with .selectable = 0" % (path, m.group(1), hidden_in_rom))
        if m is None and hidden_in_rom:
            fails.append("%s does not mention the %d hidden characters"
                         % (path, hidden_in_rom))

    print("characters.h: %d total, %d selectable" % (len(in_rom), len(selectable)))
    print("ROSTERS.md:   %d documented, %d Pokemon rows"
          % (len(doc), sum(len(v) for v in doc.values())))
    print("sprite pages: %d characters, %d cells, %d without a source line"
          % (len(sprite_chars), sprite_rows, missing_src))
    if fails:
        print("\n%d MISMATCHES:" % len(fails))
        for f in fails[:25]:
            print("   " + f)
        return 1
    print("\nOK: the documentation matches what the ROM offers")
    return 0


if __name__ == "__main__":
    sys.exit(main())
