#!/usr/bin/env python3
"""Pin every path that can hand the player a Pokemon through an "egg".

WHY THIS EXISTS
---------------
The gift-egg roster roll (PLAN.md §13) gates ScriptGiveEgg so that a scripted
egg yields a species from the active character's roster. The workspace's
lesson #1 is that a checker which greps the files that ALREADY contain a hook
cannot see a bypass in a file with no hook -- that is how Platinum missed the
Manaphy egg and then the Daycare, after a commit announced it had found "three,
not two".

So this is an INVENTORY, not a grep for the hook: every producer is listed
below with a verdict, and a producer that is not on the list fails the check.
Adding an egg path is fine; adding one SILENTLY is not.

Run:  python3 tools/check_egg_paths.py     (exit 0 = ok, 1 = a path changed)
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

# (file, symbol that must appear in the enclosing function, verdict, why)
INVENTORY = [
    ("src/script_pokemon_util.c", "ScriptGiveEgg", "GATED",
     "the two `giveegg` script sites (Water Labyrinth Togepi, mevent Pichu) "
     "both reach the player through here; it calls CharacterMode_RollEggSpecies"),
    ("src/daycare.c", "_GiveEggFromDaycare", "EXEMPT",
     "breeding keeps parent-species inheritance -- the user's ruling of "
     "2026-08-26. It already hands over a hatched baby, not an egg."),
    ("src/daycare.c", "CreateEgg", "CONSTRUCTOR",
     "builds the mon but never hands it over; both callers are listed above"),
]

def fail(msg):
    print("FAIL: " + msg)
    return 1


def strip_comments(text):
    """Remove /* */ and // comments.

    ⚠️ THIS IS LOAD-BEARING, and its absence was a real defect in the first
    version of this file. Check 3 below tested `"CharacterMode_RollEggSpecies"
    not in source` -- and the egg-path inventory comment at the top of
    ScriptGiveEgg NAMES that function in prose. So replacing the actual call
    with `0` left the checker green: the documentation defeated the check.

    That is the workspace's own lesson #2 ("a substring or token test standing
    in for an expression") landing one idiom over, in the checker written to
    encode lesson #1.
    """
    out = []
    i, n = 0, len(text)
    while i < n:
        if text.startswith("/*", i):
            end = text.find("*/", i + 2)
            i = n if end == -1 else end + 2
        elif text.startswith("//", i):
            end = text.find("\n", i)
            i = n if end == -1 else end
        else:
            out.append(text[i])
            i += 1
    return "".join(out)


def calls(text, symbol):
    """True if `symbol` is CALLED here -- word-boundaried, with its paren.

    ⚠️ Not `symbol in text`. `_GiveEggFromDaycareRenamed` CONTAINS
    `_GiveEggFromDaycare`, so a plain `in` test reports a renamed-away function
    as still present, which is how a stale inventory passes itself.
    """
    return re.search(r"\b" + re.escape(symbol) + r"\s*\(", text) is not None

def main():
    errors = 0

    # 1. Every CreateEgg() call site must sit in an inventoried file.
    allowed_files = {f for f, _, _, _ in INVENTORY}
    for path in sorted((ROOT / "src").glob("*.c")):
        body = strip_comments(path.read_text(errors="replace"))
        for i, line in enumerate(body.splitlines(), 1):
            if re.search(r"\bCreateEgg\s*\(", line):
                rel = "src/" + path.name
                if rel not in allowed_files:
                    errors += fail(
                        f"{rel}:{i} calls CreateEgg() and is not in the egg-path "
                        f"inventory in {__file__}. Add it with a verdict.")

    # 2. Every inventoried symbol must still exist -- a rename must not quietly
    #    empty this list out, which would make the check pass by covering
    #    nothing. This is the "a checker that cannot fail" shape.
    for rel, symbol, verdict, _why in INVENTORY:
        text = strip_comments((ROOT / rel).read_text(errors="replace"))
        if not calls(text, symbol):
            errors += fail(f"{rel} no longer defines {symbol} ({verdict}) -- "
                           "the inventory is stale.")

    # 3. The GATED path must actually consult the picker. Matching the FUNCTION
    #    NAME rather than a guard expression is deliberate here: there is only
    #    one call and no condition to invert.
    gated = strip_comments((ROOT / "src/script_pokemon_util.c").read_text(errors="replace"))
    if not calls(gated, "CharacterMode_RollEggSpecies"):
        errors += fail("ScriptGiveEgg no longer calls CharacterMode_RollEggSpecies "
                       "-- the gift-egg roster roll is bypassed.")

    # 4. The daycare exemption must stay an exemption ON PURPOSE. If someone
    #    routes it through the picker, that is a gameplay change the user
    #    rejected, and it should require editing this file to land.
    daycare = strip_comments((ROOT / "src/daycare.c").read_text(errors="replace"))
    if calls(daycare, "CharacterMode_RollEggSpecies"):
        errors += fail("src/daycare.c now calls CharacterMode_RollEggSpecies. "
                       "Breeding keeping parent-species inheritance was ruled by "
                       "the user on 2026-08-26; if that changed, update the "
                       "inventory and PLAN.md §13.")

    if errors:
        print(f"\n{errors} problem(s).")
        return 1

    print(f"OK -- {len(INVENTORY)} egg paths inventoried, "
          f"{sum(1 for _, _, v, _ in INVENTORY if v == 'GATED')} gated, "
          f"{sum(1 for _, _, v, _ in INVENTORY if v == 'EXEMPT')} deliberately exempt.")
    return 0

if __name__ == "__main__":
    sys.exit(main())
