#!/usr/bin/env python3
"""Every species with base stats must also have a learnset, a name and pic coords.

`tools/character_mode/fix_species_graphics.py` fills the five GRAPHICS tables
(front pic, back pic, palette, shiny palette, front anims) and knows nothing
about anything else. That is why four Legends: Arceus species -- Wyrdeer,
Ursaluna, Basculegion, Overqwil -- shipped with base stats, dex numbers,
pre-evolution rows AND complete battle graphics, and still HUNG the game:

    gLevelUpLearnsets[SPECIES_BASCULEGION] == NULL

`gLevelUpLearnsets` is a designated-initializer array, so a species with no row
is a NULL pointer. `MonTryLearningNewMove` (src/pokemon.c) walks it with an
UNBOUNDED `while` over an `EWRAM_DATA static u8 sLearningMoveTableID`, and
`party_menu.c`'s field-move scan does the same with a `u8 k`. A NULL read on
real hardware returns a constant BIOS-prefetch value whose `.move` is never
`LEVEL_UP_END`, so the u8 index wraps forever -> the game hangs. Basculegion is
reachable in ordinary play (Basculin-White-Striped evolves at level 43 and has
22 wild-encounter slots), so this was a live hang, not a theoretical one.

The same argument applies to three more designated arrays:
  gSpeciesNames      -> a species with no row displays/copies an empty name
  gMonFrontPicCoords -> a missing row means `.size = 0`, i.e. a 0x0 sprite
  gMonBackPicCoords  -> ditto

A build is clean either way. Nothing else in this tree checks it.

Run:  python3 tools/check_species_tables.py
Exit 0 = every base-stats species has all four rows. Exit 1 = it names them.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))

# A gBaseStats set smaller than this means the extraction broke, not that the
# tree shrank. A check built on an extracted set MUST fail loudly when the set
# comes out empty -- this repo has shipped four vacuously-passing checks.
MIN_BASE_STATS_ROWS = 900

TABLES = [
    ("gLevelUpLearnsets", "src/data/pokemon/level_up_learnset_pointers.h"),
    ("gSpeciesNames", "src/data/text/species_names.h"),
    ("gMonFrontPicCoords", "src/data/pokemon_graphics/front_pic_coordinates.h"),
    ("gMonBackPicCoords", "src/data/pokemon_graphics/back_pic_coordinates.h"),
]


def read(path):
    with open(os.path.join(ROOT, path), encoding="utf-8") as f:
        return f.read()


def resolve_species():
    """SPECIES_* -> numeric id, via the real preprocessor (aliases and all)."""
    src = read("include/constants/species.h")
    names = re.findall(r"#define\s+(SPECIES_\w+)\s", src)
    tmp = "/tmp/_check_species_tables.c"
    with open(tmp, "w") as f:
        f.write('#include "constants/species.h"\n' + "\n".join(names) + "\n")
    out = subprocess.run(["cpp", "-I", os.path.join(ROOT, "include"), "-P", tmp],
                         capture_output=True, text=True).stdout
    lines = [l.strip() for l in out.split("\n") if l.strip()]
    if len(lines) != len(names):
        sys.exit("!! cpp returned %d values for %d SPECIES_ names" % (len(lines), len(names)))
    name2id, id2name = {}, {}
    for n, l in zip(names, lines):
        try:
            v = int(eval(l))
        except Exception:
            continue
        name2id[n] = v
        id2name.setdefault(v, n)   # first spelling wins; aliases exist
    return name2id, id2name


def array_body(text, name, path):
    """The body of `<type> name[...] = { ... \n};` -- the NAMED array, not the
    file's last one. Several of these headers hold more than one array
    (base_stats.h also holds gVanillaBaseStats)."""
    # `gSpeciesNames[][POKEMON_NAME_LENGTH + 1]` has TWO bracket groups.
    m = re.search(re.escape(name) + r"\s*(?:\[[^\]]*\]\s*)+=\s*\{(.*?)\n\};", text, re.S)
    if not m:
        sys.exit("!! %s not found in %s" % (name, path))
    return m.group(1)


def designators(body, name2id):
    ids = set()
    for mm in re.finditer(r"\[\s*(SPECIES_\w+)\s*\]\s*=", body):
        key = mm.group(1)
        if key in name2id:
            ids.add(name2id[key])
    return ids


def main():
    name2id, id2name = resolve_species()

    base = designators(array_body(read("src/data/pokemon/base_stats.h"),
                                  "gBaseStats", "src/data/pokemon/base_stats.h"),
                       name2id)
    if len(base) < MIN_BASE_STATS_ROWS:
        sys.exit("!! only %d gBaseStats rows extracted (expected >= %d) -- the "
                 "extraction is broken, not the data" % (len(base), MIN_BASE_STATS_ROWS))

    print("gBaseStats               %5d species" % len(base))

    bad = {}
    for tname, path in TABLES:
        have = designators(array_body(read(path), tname, path), name2id)
        missing = sorted(base - have)
        print("%-24s %5d rows, %4d base-stats species missing"
              % (tname, len(have), len(missing)))
        for i in missing:
            bad.setdefault(i, []).append(tname)

    if not bad:
        print("\nOK: all %d species with base stats have a learnset, a name, "
              "front pic coords and back pic coords." % len(base))
        return 0

    print("\nFAIL: %d species have base stats but are missing rows:" % len(bad))
    for i in sorted(bad):
        print("  %-40s (id %4d)  missing: %s"
              % (id2name.get(i, "SPECIES_?"), i, ", ".join(bad[i])))
    print("\nA missing gLevelUpLearnsets row is a NULL pointer and HANGS the game "
          "(see this file's docstring).")
    return 1


if __name__ == "__main__":
    sys.exit(main())
