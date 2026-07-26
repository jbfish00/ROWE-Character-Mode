#!/usr/bin/env python3
"""Find species names that were abbreviated to fit the old 10-character limit.

Ground truth comes from the file itself: every entry is a designated initializer
of the form

    [SPECIES_CORVIKNIGHT] = _("Corviknigh"),

so the constant spells the intended name.

The distinction that matters is where the string stops. A form variant stops at an
underscore boundary in the constant -- [SPECIES_CHARIZARD_MEGA] = "Charizard" is
correct, because a Mega displays under its base name. A truncation stops mid-token:
[SPECIES_CORVIKNIGHT] = "Corviknigh" cuts the final T. So an entry is TRUNCATED
only when its normalized string is a strict prefix of the normalized constant AND
is not equal to any prefix taken at a token boundary. Everything else that differs
is reported as a MISMATCH for review.

Run after any change to POKEMON_NAME_LENGTH or to the species table:

    python3 tools/check_species_names.py            # report
    python3 tools/check_species_names.py --quiet    # exit status only

Exit status is nonzero if any truncation survives, so this can gate a build.
"""
import re
import sys

NAMES = "src/data/text/species_names.h"
GLOBAL = "include/constants/global.h"

ENTRY = re.compile(r'\[\s*(SPECIES_\w+)\s*\]\s*=\s*_\("([^"]*)"\)')


ACCENTS = str.maketrans("ÉÈÊËÁÀÂÄÍÌÎÏÓÒÔÖÚÙÛÜÑÇ", "EEEEAAAAIIIIOOOOUUUUNC")


def norm(s):
    """Collapse to comparable form: uppercase alphanumerics, accents folded.

    Folding accents matters: Flabebe is spelled "Flabebe" with acutes, and
    without folding it reads as a mismatch against SPECIES_FLABEBE.
    """
    return re.sub(r'[^A-Z0-9]', '', s.upper().translate(ACCENTS))


def name_length():
    with open(GLOBAL) as f:
        m = re.search(r'^#define\s+POKEMON_NAME_LENGTH\s+(\d+)', f.read(), re.M)
    return int(m.group(1))


def main():
    quiet = "--quiet" in sys.argv
    limit = name_length()

    with open(NAMES) as f:
        entries = ENTRY.findall(f.read())

    truncated, mismatched, overlong, spacing = [], [], [], []
    for const, name in entries:
        if len(name) > limit:
            overlong.append((const, name))
        tokens = const[len("SPECIES_"):].split("_")
        n = norm(name)
        c = norm("".join(tokens))
        if not n or set(name) == {"?"}:
            continue
        # Prefixes of the constant taken at token boundaries: these are the
        # legitimate display names (base species, and every form of it).
        boundaries = {norm("".join(tokens[:i])) for i in range(1, len(tokens) + 1)}
        if n == c and len(tokens) > 1:
            # Spans every token, so the name is the whole multi-word species.
            # It must carry a separator, or a space was dropped to save a
            # character: "IronThorns" for SPECIES_IRON_THORNS. This class is
            # invisible to the prefix test because it normalizes to an exact
            # match.
            if not re.search(r"[ .'\-:]", name):
                spacing.append((const, name))
            continue
        if n in boundaries:
            continue
        if c.startswith(n):
            truncated.append((const, name, len(name)))
        else:
            mismatched.append((const, name))

    if not quiet:
        print(f"{len(entries)} entries, POKEMON_NAME_LENGTH = {limit}\n")
        if overlong:
            print(f"!! {len(overlong)} entries EXCEED the field and will be cut at runtime:")
            for const, name in overlong:
                print(f"     {const:44} {name!r} ({len(name)})")
            print()
        def dump(label, rows):
            print(f"{len(rows)} {label}:")
            for row in rows:
                const, name = row[0], row[1]
                print(f"     {const:44} {name!r} ({len(name)})")
            print()

        dump("TRUNCATED (cut mid-token)", truncated)
        dump("COMPRESSED (letters dropped to fit)", mismatched)
        dump("SPACING (separator dropped to fit)", spacing)

    return 1 if (truncated or overlong or mismatched or spacing) else 0


if __name__ == "__main__":
    sys.exit(main())
