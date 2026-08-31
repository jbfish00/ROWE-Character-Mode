#!/usr/bin/env python3
"""No gym-leader or Elite Four script reads Character Mode state.

PLAN.md item #11. `tools/mgba_scripts/johto_gym_e2e.lua` plays AS Falkner and
beats FALKNER'S OWN gym script end to end -- the script completes, the badge
chain fires, and the gift gate still sorts on-roster from off-roster while a
Johto leader is the player. That is one leader. The other fifteen leaders and
Elite Four members with rosters have no equivalent run, and the reason recorded
for believing it generalises was a static argument in the 2026-07-17 session
notes: "no gym script reads CM state".

An argument is not a check. This is the check, and it is an INVENTORY in the
sense the rest of this workspace uses the word: every leader/E4 script is
listed, and a NEW one that reads Character Mode state fails here rather than
arriving silently. Nothing about the shape of the Falkner run has to be
re-derived to notice it.

⚠️ WHAT THIS DOES NOT PROVE. It does not run fifteen more battles. If a leader
script is broken for a reason unrelated to Character Mode -- a bad trainer id,
a missing flag -- this is blind to it, exactly as it is for the leaders the
suite has never played. What it does prove is the one property the Falkner run
generalises ON: these scripts do not branch on who the player is.

Exit non-zero on any finding, so it can sit in a suite.
"""
import glob
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
DATA = os.path.join(ROOT, "data")

# The state Character Mode keeps. A gym script touching any of these is reading
# (or worse, writing) who the player has chosen to be.
CM_TOKENS = [
    "FLAG_CHARACTER_MODE",
    "VAR_CHARACTER_ID",
    "VAR_CHARACTER_MODE",
    "CharacterMode",
    "character_mode",
]

# The files that define leader / Elite Four encounters.
#
# ⚠️ The first version of this checker listed two files by hand, found 8 Johto
# leaders and ZERO Elite Four members, and printed OK -- because
# data/scripts/elite_four.pory turned out to be door and metatile plumbing,
# while every E4 battle lives in its own map script. It also carried a
# compiled-and-never-used E4 regex. That is this workspace's "a checker that
# cannot fail" shape, in the checker written to close an argument.
#
# So the list is DISCOVERED (a new gym map is picked up automatically) and then
# CHECKED against a pinned floor (a gym map that disappears, or a directory
# layout change that makes the glob match nothing, fails instead of passing
# quietly).
GLOBS = [
    "scripts/gym_scripts.pory",
    "scripts/elite_four.pory",
    "maps/*Gym*/scripts.pory",
    "maps/EverGrandeCity_*Room/scripts.pory",
]

# Every one of these must be found. Not a count -- names, so that "the glob
# still matches 14 things" cannot stand in for "it still matches the RIGHT
# things". (A bare count is this workspace's most repeated bug.)
REQUIRED = [
    "scripts/gym_scripts.pory",
    "maps/RustboroCity_Gym/scripts.pory",
    "maps/PetalburgCity_Gym/scripts.pory",
    "maps/SootopolisCity_Gym_1F/scripts.pory",
    "maps/EverGrandeCity_SidneysRoom/scripts.pory",
    "maps/EverGrandeCity_PhoebesRoom/scripts.pory",
    "maps/EverGrandeCity_GlaciasRoom/scripts.pory",
    "maps/EverGrandeCity_DrakesRoom/scripts.pory",
    "maps/EverGrandeCity_ChampionsRoom/scripts.pory",
]

LEADER_RE = re.compile(r"^\s*script\s+(Common_Eventscript_Gym_Leader_(\w+?))\s*\{", re.M)

# Sub-scripts, not characters: the emitted per-leader helpers all carry one of
# these suffixes, and CheckForAllBadges is a shared utility.
NOT_A_LEADER = {"CheckForAllBadges"}
SUFFIXES = ("_Battle_New", "_Give_Gifts", "_Text", "_1", "_2", "_3", "_4",
            "_5", "_6", "_7", "_8", "_9")


def leaders_in(text):
    found = set()
    for _, name in LEADER_RE.findall(text):
        if name in NOT_A_LEADER:
            continue
        base = name
        for suf in SUFFIXES:
            if base.endswith(suf):
                base = base[: -len(suf)]
        # numeric tails on the generated sub-scripts (…_Give_Gifts_17)
        base = re.sub(r"_\d+$", "", base)
        if base and base not in NOT_A_LEADER:
            found.add(base)
    return found


def main():
    problems = []
    all_leaders = set()
    battle_files = []
    scanned = []

    for pattern in GLOBS:
        hits = sorted(glob.glob(os.path.join(DATA, pattern)))
        if not hits:
            problems.append("glob matched nothing: %s -- the layout moved and "
                            "this checker would otherwise pass vacuously" % pattern)
        for path in hits:
            scanned.append(os.path.relpath(path, DATA))

    for req in REQUIRED:
        if req not in scanned:
            problems.append("required script file not found: %s" % req)

    for rel in scanned:
        text = open(os.path.join(DATA, rel), encoding="utf-8",
                    errors="replace").read()
        all_leaders |= leaders_in(text)
        if "trainerbattle" in text:
            battle_files.append(rel)

        # Strip comments before matching, so a comment that merely NAMES
        # Character Mode cannot fail the check -- and, the other way round, so
        # commenting a read out does not hide it. check_egg_paths.py learned
        # this the hard way: its first version was defeated by its own
        # documentation.
        stripped = re.sub(r"//[^\n]*", "", text)
        stripped = re.sub(r"/\*.*?\*/", "", stripped, flags=re.S)
        for token in CM_TOKENS:
            for m in re.finditer(re.escape(token), stripped):
                line = stripped[: m.start()].count("\n") + 1
                problems.append(
                    "%s:%d reads Character Mode state (%s). The Falkner run "
                    "(johto_gym_e2e.lua) is the ONLY leader-as-player run in "
                    "the suite, and it generalises only because these scripts "
                    "do not branch on who the player is. If this read is "
                    "deliberate, that leader now needs its own live run."
                    % (rel, line, token))

    if not battle_files:
        problems.append("not one scanned file contains a trainerbattle -- "
                        "whatever is being scanned, it is not the gyms")

    print("gym / Elite Four script inventory")
    print("  files scanned:      %d" % len(scanned))
    print("  with a trainerbattle: %d" % len(battle_files))
    print("  Johto leaders named:  %d  (%s)"
          % (len(all_leaders), ", ".join(sorted(all_leaders))))
    print("  live-run proven:      Falkner (tools/mgba_scripts/johto_gym_e2e.lua)")
    print("  every other leader and E4 member rests on the property checked")
    print("  here -- that these scripts do not branch on who the player is --")
    print("  and NOT on a run of their own.")

    if problems:
        print()
        for p in problems:
            print("FAIL: " + p)
        return 1
    print("\nOK -- no leader or Elite Four script reads Character Mode state.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
