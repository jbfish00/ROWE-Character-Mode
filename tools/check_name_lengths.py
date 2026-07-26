#!/usr/bin/env python3
"""Regression gate for the 12-character name change.

Checks the things that are NOT enforced by the compiler. Every item here
corresponds to a way this change silently broke, or nearly broke, once:

  1. Save blocks still fit their sectors (read off the built ELF, not a probe --
     modern GCC disagrees with agbcc about SaveBlock1 by 332 bytes).
  2. BoxPokemon is still exactly 80 bytes, i.e. the nickname widening is still
     paid for out of the reclaimed u16 and PC storage has not grown.
  3. No species name is abbreviated (delegates to check_species_names.py).
  4. The fixed-length string helpers still take their bounds from the defines
     rather than a literal.
  5. The OT accessors are still bounded by OT_NAME_LENGTH, not PLAYER_NAME_LENGTH
     -- getting this wrong overruns otName into the encrypted block.

Usage: python3 tools/check_name_lengths.py [path/to/pokeemerald.elf]
"""
import re
import subprocess
import sys

ELF = sys.argv[1] if len(sys.argv) > 1 else "pokeemerald.elf"

# Sector budgets, derived from struct SaveSection.data[0xFF4] = 4084 bytes/sector.
SECTOR = 4084
BUDGETS = {
    "gSaveblock2": SECTOR * 1,
    "gSaveblock1": SECTOR * 4,
    "gPokemonStorage": SECTOR * 9,
}

failures = []


def check(ok, msg):
    print(f"  {'ok  ' if ok else 'FAIL'}  {msg}")
    if not ok:
        failures.append(msg)


def elf_sizes():
    out = subprocess.run(["nm", "-S", ELF], capture_output=True, text=True).stdout
    sizes = {}
    for line in out.splitlines():
        parts = line.split()
        if len(parts) == 4 and parts[3] in BUDGETS:
            sizes[parts[3]] = int(parts[1], 16)
    return sizes


def main():
    print("save block budgets")
    sizes = elf_sizes()
    for sym, budget in BUDGETS.items():
        got = sizes.get(sym)
        if got is None:
            check(False, f"{sym} not found in {ELF}")
        else:
            check(got <= budget, f"{sym} {got} <= {budget} ({budget - got} spare)")

    print("struct layout")
    ph = open("include/pokemon.h").read()
    box = re.search(r'struct BoxPokemon\s*\{(.*?)\n\};', ph, re.S)
    check(box is not None and "u16 unknown" not in box.group(1),
          "BoxPokemon no longer carries the reclaimed u16")
    check("otName[OT_NAME_LENGTH]" in ph,
          "BoxPokemon.otName is bounded by OT_NAME_LENGTH")

    print("name-length defines")
    g = open("include/constants/global.h").read()
    for name in ("POKEMON_NAME_LENGTH", "PLAYER_NAME_LENGTH", "OT_NAME_LENGTH"):
        m = re.search(rf'^#define\s+{name}\s+(\d+)', g, re.M)
        check(m is not None, f"{name} is defined" + (f" = {m.group(1)}" if m else ""))

    print("no reintroduced literals")
    su = open("gflib/string_util.c").read()
    check(re.search(r'limit\s*=\s*(10|7)\s*;', su) is None,
          "StringCopy10/StringGetEnd10/StringCopy7 use the defines, not literals")
    ns = open("src/naming_screen.c").read()
    check(re.search(r'\.maxChars\s*=\s*(7|10)\s*,', ns) is None,
          "player/mon naming templates use the defines, not literals")

    print("OT accessors bounded")
    pc = open("src/pokemon.c").read()
    # There are exactly two: the getter in GetBoxMonData and the setter in
    # SetBoxMonData. Assert the count -- an earlier version of this gate used a
    # 400-character window that silently matched only the setter, so a regression
    # in the getter would have passed.
    bodies = re.findall(r'case MON_DATA_OT_NAME:(.*?)\n\s*break;', pc, re.S)
    check(len(bodies) == 2, f"found both MON_DATA_OT_NAME accessors (got {len(bodies)})")
    for i, body in enumerate(bodies):
        check("OT_NAME_LENGTH" in body and
              not re.search(r'<\s*PLAYER_NAME_LENGTH', body),
              f"MON_DATA_OT_NAME accessor #{i} is bounded by OT_NAME_LENGTH")
    check(re.search(r'i\s*<\s*OT_NAME_LENGTH\s*&&\s*otName\[i\]\s*!=\s*EOS', pc) is not None,
          "IsOtherTrainer's comparison is bounded")

    print("species names")
    rc = subprocess.run([sys.executable, "tools/check_species_names.py", "--quiet"]).returncode
    check(rc == 0, "no species name is truncated, compressed or missing a separator")

    print()
    if failures:
        print(f"{len(failures)} FAILED")
        return 1
    print("all checks passed")
    return 0


if __name__ == "__main__":
    sys.exit(main())
