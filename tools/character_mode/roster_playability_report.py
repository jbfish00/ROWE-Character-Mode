#!/usr/bin/env python3
"""How much of the game's OWN wild data is on each character's roster?

WHY THIS EXISTS. The playthrough checklist's last irreducible question is
"whether a roster is miserable to play for 40 hours", and it has always been
filed as pure human judgement. Most of it is, but a large part is measurable and
nobody had measured it.

The playability threshold already guarantees six fully-evolved obtainable
Pokemon, and the 10% roster override guarantees you MEET your character's
Pokemon at a fixed rate everywhere. Neither answers the question that actually
decides whether a run drags: **when you walk into grass and something appears,
how often is it yours to keep?** That is the map's own encounter tables versus
the character's roster, and it is entirely in the data.

The number this prints is `natural%` — the share of the game's wild encounter
SLOTS, weighted by nothing (a slot is a slot), whose species canonicalizes to a
family on that character's roster. It deliberately does NOT include the 10%
override, because the override is the floor every character already has; what
distinguishes a comfortable roster from a miserable one is what happens in the
other 90%.

⚠️ WHAT THIS IS NOT. It is not a verdict, and it must never be turned into a
gate. A low score can be entirely fine (a character you play for the set pieces),
and a high score does not make a run fun. It is a flag for "check this one
during the playthrough", which is exactly what the checklist needs and what a
suite cannot give it.

⚠️ It counts SLOTS, not encounter probability. Slot 0 of a land table is 20% of
that map's encounters and slot 11 is 1%, so a roster that only matches rare
slots scores higher here than it plays. Weighting by the real slot chances is a
worthwhile refinement; it is not done, and this comment is here so the number is
not read as more precise than it is.

Usage: python3 tools/character_mode/roster_playability_report.py [--csv]
"""
import json
import os
import re
import sys
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))

# The early game, for the "do you have anything to catch before the first badge"
# half of the question. Encounter levels in this tree are scaled by badge count,
# so a fixed level band is the wrong cut -- the maps you can REACH early are the
# right one, and these are the Hoenn starting routes in map order.
#
# ⚠️ `early%` IS WEAKER THAN `natural%`, AND HERE IS WHY. ROWE ships a
# start-location chooser: a run can begin on any of eight Sevii islands, not
# only in Littleroot. This list is the HOENN opening, so `early%` answers
# "if you start the normal way", which is the common case and not the only one.
# `natural%` has no such assumption and is the number to trust.
EARLY_MAPS = {
    "MAP_ROUTE101", "MAP_ROUTE102", "MAP_ROUTE103", "MAP_ROUTE104",
    "MAP_PETALBURG_WOODS", "MAP_ROUTE110", "MAP_ROUTE116",
    "MAP_RUSTURF_TUNNEL", "MAP_ROUTE105", "MAP_ROUTE106",
}



def _resolve(names):
    """SPECIES_X -> int, via the C preprocessor.

    ⚠️ One constant does NOT expand to one token. Several species constants are
    aliases (the ROWEALIAS block in species.h) and some expand to arithmetic, so
    splitting cpp's output on whitespace mismatches the input list -- which is
    how the first version of this script silently paired names with the wrong
    values. Each name is emitted on its own marked line and evaluated.
    """
    import subprocess
    names = list(names)
    if not names:
        return {}
    src = '#include "constants/species.h"\n'
    src += "".join("@@@ %s\n" % n for n in names)
    out = subprocess.run(["arm-none-eabi-cpp", "-I", os.path.join(TARGET, "include")],
                         input=src, capture_output=True, text=True)
    if out.returncode != 0:
        raise SystemExit("cpp failed: " + out.stderr[:400])
    vals = []
    for line in out.stdout.splitlines():
        line = line.strip()
        if not line.startswith("@@@"):
            continue
        expr = line[3:].strip()
        try:
            vals.append(int(eval(expr, {"__builtins__": {}}, {})))
        except Exception:
            vals.append(None)
    if len(vals) != len(names):
        raise SystemExit("cpp returned %d marked lines for %d constants"
                         % (len(vals), len(names)))
    return {n: v for n, v in zip(names, vals) if v is not None}


def read(path):
    with open(os.path.join(TARGET, path), encoding="utf-8", errors="replace") as f:
        return f.read()


def species_constants():
    names = sorted(set(re.findall(r"\bSPECIES_[A-Z0-9_]+\b",
                                  read("src/data/wild_encounters.json"))))
    if not names:
        raise SystemExit("no SPECIES_ constants found in wild_encounters.json")
    return _resolve(names)


def wild_slots():
    """(map, species_constant) for every wild slot in the game."""
    data = json.loads(read("src/data/wild_encounters.json"))
    slots = []
    for group in data["wild_encounter_groups"]:
        for enc in group.get("encounters", []):
            m = enc.get("map", "?")
            for field, val in enc.items():
                if not isinstance(val, dict) or "mons" not in val:
                    continue
                for mon in val["mons"]:
                    slots.append((m, mon["species"]))
    return slots


def rosters():
    """character name -> set of roster family-base species ids, from the
    EMITTED data (src/data/characters.h), not from the research files -- the
    emitted table is what the ROM enforces."""
    h = read("src/data/characters.h")
    names = dict(re.findall(r'static const u8 sName_(\w+)\[\] = _\("([^"]+)"\)', h))
    consts = _resolve(sorted(set(re.findall(r"\bSPECIES_[A-Z0-9_]+\b", h))))

    rosters_by_key = {}
    for key, body in re.findall(r'static const u16 sRoster_(\w+)\[\] =\s*\{(.*?)\};', h, re.S):
        ids = {consts[c] for c in re.findall(r"\bSPECIES_[A-Z0-9_]+\b", body)
               if c in consts and consts[c] != 0}
        rosters_by_key[key] = ids

    out_rosters = {}
    for key, body in re.findall(r'\.name = sName_(\w+),(.*?)\n    \},', h, re.S):
        m = re.search(r'\.roster = sRoster_(\w+),', body)
        sel = re.search(r'\.selectable = (\d+)', body)
        if not m:
            continue
        out_rosters[names.get(key, key)] = (
            rosters_by_key.get(m.group(1), set()),
            sel and sel.group(1) == "1",
        )
    return out_rosters


def pre_evolution_map():
    """species id -> its family BASE, using the emitted pre_evolution table so
    this agrees with CharacterMode_FamilyBase rather than re-deriving it."""
    h = read("src/data/pokemon/pre_evolution.h")
    consts = _resolve(sorted(set(re.findall(r"\bSPECIES_[A-Z0-9_]+\b", h))))

    pre = {}
    for child, parent in re.findall(r'\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*(SPECIES_[A-Z0-9_]+)', h):
        if child in consts and parent in consts:
            pre[consts[child]] = consts[parent]

    def base(sp, guard=0):
        while sp in pre and pre[sp] and guard < 12:
            sp = pre[sp]
            guard += 1
        return sp
    return base


def main():
    as_csv = "--csv" in sys.argv
    sp_consts = species_constants()
    base_of = pre_evolution_map()
    slots = wild_slots()
    chars = rosters()

    total = len(slots)
    early = [s for s in slots if s[0] in EARLY_MAPS]
    print("wild slots in the game: %d (%d on the %d early maps)"
          % (total, len(early), len(EARLY_MAPS)), file=sys.stderr)

    # canonicalize every wild slot once
    slot_bases = [base_of(sp_consts[c]) for _, c in slots if c in sp_consts]
    early_bases = [base_of(sp_consts[c]) for m, c in slots
                   if m in EARLY_MAPS and c in sp_consts]

    rows = []
    for name, (roster, selectable) in chars.items():
        if not selectable:
            continue
        hit = sum(1 for b in slot_bases if b in roster)
        ehit = sum(1 for b in early_bases if b in roster)
        rows.append((name, len(roster),
                     100.0 * hit / max(1, len(slot_bases)),
                     100.0 * ehit / max(1, len(early_bases)),
                     ehit))
    rows.sort(key=lambda r: (r[3], r[2]))

    if as_csv:
        print("character,families,natural_pct,early_pct,early_slots")
        for r in rows:
            print("%s,%d,%.1f,%.1f,%d" % r)
        return 0

    print()
    print("Share of the game's own wild slots that are ON each roster.")
    print("The 10%% override is NOT counted -- it is the floor everyone has.")
    print()
    print("%-16s %8s %10s %10s %6s" % ("character", "families", "natural%",
                                       "early%", "early"))
    print("-" * 56)
    for r in rows[:20]:
        print("%-16s %8d %9.1f%% %9.1f%% %6d" % r)
    print("   ... %d selectable characters, worst 20 shown" % len(rows))
    print()
    zero = [r for r in rows if r[4] == 0]
    print("⚠️  %d characters have ZERO on-roster wild slots on the early maps."
          % len(zero))
    if zero:
        print("    They meet their own Pokemon ONLY through the 10%% override")
        print("    until later areas open up:")
        for r in zero[:25]:
            print("      %-16s %d families, %.1f%% of the game overall"
                  % (r[0], r[1], r[2]))
    print()
    print("These are FLAGS FOR THE PLAYTHROUGH, not verdicts. A low score can be")
    print("perfectly fine; it just means that character is worth watching.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
