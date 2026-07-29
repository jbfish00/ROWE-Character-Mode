#!/usr/bin/env python3
"""Menu-vs-script index drift check for the two intro Game Modes menus.

The lists live in src/script_menu.c (ours). The switches live in
data/maps/InsideOfTruck/scripts.pory (2.X's, since the map rebase).
scrollingmultichoice hands the script the chosen ROW INDEX, so row N of the
list and case N of the switch are the same thing -- and NOTHING in the build
checks that they agree.

They had already drifted, and badly: SCROLLING_GAME_MODES ran a 17-entry
grab-bag list against a 9-case switch (picking "Randomized Mode" set Gym
Shuffle; picking "Random Party Mode" set plain Randomized), and
SCROLLING_OTHER_GAME_MODES had never been given a list at all -- it pointed at
the game-modes list while switching on 14 different cases. Same shape as the
Blue Nurse and the Slateport ferry after the rebase.

This pins both menus to an explicit expected mapping, so a future edit to
EITHER file fails loudly instead of silently re-pointing every row.

    python3 tools/check_mode_menus.py            # exit 1 on any mismatch
    python3 tools/check_mode_menus.py --self-test  # negative control

Run it after touching either file.
"""

import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
SCRIPT_MENU = os.path.join(ROOT, "src", "script_menu.c")
PORY = os.path.join(ROOT, "data", "maps", "InsideOfTruck", "scripts.pory")

# row index -> (label symbol in script_menu.c, script the pory switch must goto)
# A row whose script is None is handled by the switch's `default:` and must NOT
# appear as an explicit case.
GAME_MODES = [
    ("sText_Mode_Grindless",          "Start_EventScript_Game_Mode_Grindless_Mode"),
    ("sText_Mode_No_Evs",             "Start_EventScript_Game_Mode_No_Evs"),
    ("sText_Mode_Last_Gen",           "Start_EventScript_Game_Mode_Last_Gen_Mode"),
    ("sText_Mode_Monotype",           "Start_EventScript_Game_Mode_Monotype_Mode"),
    ("sText_Mode_Gym_Shuffle",        "Start_EventScript_Game_Mode_Gym_Shuffle"),
    ("sText_Mode_Randomized",         "Start_EventScript_Game_Mode_Randomized"),
    ("sText_Mode_Double_Battle",      "Start_EventScript_Game_Mode_Double_Battle"),
    ("sText_Mode_Little_Cup",         "Start_EventScript_Game_Mode_Little_Cup"),
    ("sText_Mode_More_Modes",         "Start_EventScript_Game_Modes_Other"),
    ("sText_Mode_Save",               None),
]

OTHER_GAME_MODES = [
    ("sText_Mode_Scalemon",           "Start_EventScript_Game_Mode_Scalemon_Mode"),
    ("sText_Mode_Inverse",            "Start_EventScript_Game_Mode_Inverse"),
    ("sText_Mode_True_Random",        "Start_EventScript_Game_Mode_True_Random_Mode"),
    ("sText_Mode_Random_Party",       "Start_EventScript_Game_Mode_Random_Party"),
    ("sText_Mode_Random_Type_Mode",   "Start_EventScript_Game_Mode_Random_Type_Mode"),
    ("sText_Mode_Random_Ability_Mode", "Start_EventScript_Game_Mode_Random_Ability_Mode"),
    ("sText_Mode_Third_Type_Mode",    "Start_EventScript_Game_Mode_Third_Type_Mode"),
    ("sText_Mode_Old_STAB_Mode",      "Start_EventScript_Game_Mode_Old_STAB_Mode"),
    ("sText_Mode_No_Split",           "Start_EventScript_Game_Mode_No_Split"),
    ("sText_Mode_No_Mega",            "Start_EventScript_Game_Mode_No_Mega_Mode"),
    ("sText_Mode_Metronome_Only",     "Start_EventScript_Game_Mode_Metronome_Only"),
    ("sText_Mode_Vanilla",            "Start_EventScript_Game_Mode_Vanilla"),
    ("sText_Mode_No_Custom_Forms",    "Start_EventScript_Game_Mode_No_Custom_Forms"),
    ("sText_Mode_No_Signature",       "Start_EventScript_Game_Mode_No_Signature"),
    ("sText_Mode_Back",               None),
]

MENUS = [
    ("sSet6", "Start_EventScript_Game_Modes", GAME_MODES),
    ("sSetOtherGameModes", "Start_EventScript_Game_Modes_Other", OTHER_GAME_MODES),
]


def read(path):
    with open(path, encoding="utf-8", errors="replace") as handle:
        return handle.read()


def list_rows(src, name):
    """[(index, label symbol)] for a ListMenuItem array, in declaration order."""
    match = re.search(
        r"static const struct ListMenuItem %s\[\]\s*=\s*\{(.*?)\n\};" % re.escape(name),
        src, re.S)
    if not match:
        raise LookupError("list %s not found in src/script_menu.c" % name)
    return [(int(idx), sym)
            for sym, idx in re.findall(r"\{\s*(sText_\w+)\s*,\s*(\d+)\s*\}", match.group(1))]


def switch_cases(pory, name):
    """{case index: script it gotos} for a pory script's switch(var(VAR_RESULT))."""
    match = re.search(r"script %s\{(.*?)\n\}" % re.escape(name), pory, re.S)
    if not match:
        raise LookupError("script %s not found in the .pory" % name)
    return dict((int(num), "Start_EventScript_" + target) for num, target in
                re.findall(r"case (\d+):\s*goto\(Start_EventScript_(\w+)\)", match.group(1)))


def check(src, pory):
    errors = []
    for list_name, script_name, expected in MENUS:
        rows = list_rows(src, list_name)
        cases = switch_cases(pory, script_name)

        if len(rows) != len(expected):
            errors.append("%s: %d rows, expected %d -- add the new row to "
                          "check_mode_menus.py AND to %s"
                          % (list_name, len(rows), len(expected), script_name))
        for pos, (idx, sym) in enumerate(rows):
            if idx != pos:
                errors.append("%s row %d carries id %d; scrollingmultichoice "
                              "returns the id, so ids must be 0..n-1 in order"
                              % (list_name, pos, idx))
            if pos >= len(expected):
                continue
            want_sym, want_script = expected[pos]
            if sym != want_sym:
                errors.append("%s row %d is %s, expected %s"
                              % (list_name, pos, sym, want_sym))
            got_script = cases.get(pos)
            if want_script is None:
                if got_script is not None:
                    errors.append("%s case %d is an explicit goto(%s) but row %d "
                                  "(%s) is meant to fall to `default:`"
                                  % (script_name, pos, got_script, pos, sym))
            elif got_script != want_script:
                errors.append("%s case %d gotos %s, but row %d of %s is %s -- "
                              "expected %s"
                              % (script_name, pos, got_script, pos, list_name,
                                 sym, want_script))

        stray = sorted(set(cases) - set(i for i, _ in rows))
        if stray:
            errors.append("%s has cases %s with no row in %s -- unreachable"
                          % (script_name, stray, list_name))
    return errors


def main():
    src, pory = read(SCRIPT_MENU), read(PORY)

    if "--self-test" in sys.argv:
        # Negative control: swap two rows and confirm we actually notice.
        broken = src.replace("{sText_Mode_Randomized, \t     5},",
                             "{sText_Mode_Gym_Shuffle, \t     5},", 1)
        if broken == src:
            print("SELF-TEST INCONCLUSIVE: the injection point moved; "
                  "update it before trusting this checker")
            return 1
        found = check(broken, pory)
        if not found:
            print("SELF-TEST FAILED: an injected mismatch went unnoticed")
            return 1
        print("self-test OK -- injected mismatch was caught:\n  %s" % found[0])
        return 0

    errors = check(src, pory)
    if errors:
        print("mode menu drift, %d problem(s):" % len(errors))
        for err in errors:
            print("  " + err)
        return 1
    total = sum(len(rows) for _, _, rows in MENUS)
    print("OK -- %d rows across %d menus match their switches" % (total, len(MENUS)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
