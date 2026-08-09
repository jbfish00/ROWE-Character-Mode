#!/usr/bin/env python3
"""Integrity audit of the GENERATED src/data/characters.h.

The runtime check (IsSpeciesAllowedForCharacter) canonicalizes a caught/gifted
species via CharacterMode_FamilyBase() -- form-table collapse
(GetBaseFormSpeciesId) alternating with an evolution walk (GetFirstEvolution)
to a fixpoint -- and compares THAT against the roster. So a roster entry only
ever matches if it IS a canonical family base; any other entry (the signature
ace SPECIES_PIKACHU leading Red's starter block, a regional form like
SPECIES_FARFETCHD_GALARIAN) is fine ONLY when its canonical base is also on
the same roster. This is the bug shape the Lazarus port hit (Red couldn't keep
his own Pikachu) -- this script proves ROWE's emitted data can't hit it.

Checks, per character:
  1. roster is non-empty
  2. every entry is a defined species constant with id < NUM_SPECIES
  3. every entry's canonical family base is also present on the roster
     (entries that are not canonical bases must be shadowed)
  4. starterCount <= roster length, and starterCount == 0 only on a roster that
     really is all-legendary (ui_mode_menu.c reads 0 as "hand out roster[0]")
  5. every starterCount == 0 character has a PINNED_STARTERS entry and its
     roster[0] still matches it. Check 4 passes happily on a REORDERED roster,
     and roster[0] is handed out verbatim -- so reordering is a data-only,
     silent way to change which Pokemon the player actually receives.

Exit code 1 on any finding; prints a summary either way.
"""
import os
import re
import pathlib
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))



# Characters whose starter is FIXED because their roster is all-legendary.
# ui_mode_menu.c's RandomizeStarterSelection hands these roster[0] verbatim
# rather than rolling, so the starter's identity is decided by roster ORDER --
# which is data, and reorders silently. User ruling 2026-07-28: an
# all-legendary roster DOES get a starter, and always the same one.
#   Tobias: roster is [DARKRAI, LATIOS]; he must always start with Darkrai,
#   never a coin flip, and never Latios.
PINNED_STARTERS = {
    "Tobias": "SPECIES_DARKRAI",
}

def read(path):
    with open(path, encoding="utf-8") as f:
        return f.read()


def max_roster_candidates():
    """Read CHARACTER_MAX_ROSTER_CANDIDATES out of the header rather than
    duplicating it here. A second copy of a size constant is the same drift bug
    this check exists to catch, one layer up."""
    src = read(os.path.join(TARGET, "include", "character_mode.h"))
    m = re.search(r"#define\s+CHARACTER_MAX_ROSTER_CANDIDATES\s+(\d+)", src)
    if not m:
        raise SystemExit("audit_rosters: could not find "
                         "CHARACTER_MAX_ROSTER_CANDIDATES in "
                         "include/character_mode.h -- refusing to guess it")
    return int(m.group(1))


def species_ids():
    """Identifier -> numeric id from species.h #defines, resolving full
    expressions (aliases, GEN_9_START + n, FORMS_START arithmetic, ...)."""
    text = read(os.path.join(TARGET, "include/constants/species.h"))
    raw = {}
    for m in re.finditer(r"#define\s+(\w+)\s+([^\n/]+)", text):
        raw[m.group(1)] = m.group(2).strip()
    ids = {}

    def resolve(name, depth=0):
        if name in ids:
            return ids[name]
        if depth > 50 or name not in raw:
            return None
        ids[name] = None  # cycle guard
        expr = raw[name]
        expr = re.sub(
            r"\b([A-Za-z_]\w*)\b",
            lambda mm: str(resolve(mm.group(1), depth + 1)), expr)
        try:
            val = eval(expr, {"__builtins__": {}})
            ids[name] = int(val)
        except Exception:
            ids[name] = None
        return ids[name]

    for name in raw:
        resolve(name)
    return ids, raw


def parent_map():
    """child SPECIES_* -> parent SPECIES_* from gEvolutionTable."""
    text = read(os.path.join(TARGET, "src/data/pokemon/evolution.h"))
    m = re.search(r"gEvolutionTable\[NUM_SPECIES\]\[EVOS_PER_MON\]\s*=\s*\{(.*?)^\};",
                  text, re.S | re.M)
    body = m.group(1)
    rows = [(r.start(), r.end(), r.group(1))
            for r in re.finditer(r"\[(SPECIES_\w+)\]\s*=", body)]
    parent = {}
    for i, (start, end, species) in enumerate(rows):
        chunk = body[end:rows[i + 1][0]] if i + 1 < len(rows) else body[end:]
        for t in re.finditer(r"\{\s*EVO_\w+\s*,\s*[^,]+,\s*(SPECIES_\w+)", chunk):
            child = t.group(1)
            if child != species and child not in parent:
                parent[child] = species
    return parent


def base_form_map():
    """form-table member -> the table's slot-0 species (GetBaseFormSpeciesId)."""
    text = read(os.path.join(TARGET, "src/data/pokemon/form_species_table.h"))
    collapse = {}
    for m in re.finditer(r"static const u16 \w+\[\]\s*=\s*\{(.*?)\};", text, re.S):
        members = re.findall(r"(SPECIES_\w+)", m.group(1))
        for member in members[1:]:
            collapse.setdefault(member, members[0])
    return collapse


def canonical_base(name, parent, form_base):
    """Mirror of the runtime CharacterMode_FamilyBase(): alternate
    form-collapse and evolution-walk to a fixpoint."""
    for _ in range(8):
        prev = name
        name = form_base.get(name, name)
        seen = set()
        while name in parent and name not in seen:
            seen.add(name)
            name = parent[name]
        if name == prev:
            return name
    return name


def rosters():
    """[(char_display_name, roster_var, [entries], starterCount)]"""
    text = read(os.path.join(TARGET, "src/data/characters.h"))
    tables = {}
    for m in re.finditer(
            r"static const u16 (sRoster_\w+)\[\]\s*=\s*\{(.*?)\};", text, re.S):
        entries = re.findall(r"(SPECIES_\w+)", m.group(2))
        assert entries and entries[-1] == "SPECIES_NONE", m.group(1)
        tables[m.group(1)] = entries[:-1]
    chars = []
    for m in re.finditer(
            r"\.name = sName_(\w+),\s*\.roster = (sRoster_\w+),.*?"
            r"\.starterCount = (\d+),", text, re.S):
        chars.append((m.group(1), m.group(2), tables[m.group(2)],
                      int(m.group(3))))
    return chars



def legendary_bases():
    """LEGENDARY_BASES from emit_characters.py, executed rather than parsed so a
    reformat of that literal cannot silently yield an empty set -- an empty set
    makes the invariant check below pass vacuously."""
    src = (pathlib.Path(__file__).resolve().parent / "emit_characters.py").read_text()
    start = src.index("LEGENDARY_BASES")
    end = src.index("# Manual asset overrides")
    ns = {}
    exec(compile(src[start:end], "legendary_bases", "exec"), ns)
    bases = ns["LEGENDARY_BASES"]
    if len(bases) < 90:
        raise SystemExit("audit_rosters: LEGENDARY_BASES came out at %d entries, "
                         "expected ~98 -- the extraction is broken and every "
                         "check using it would pass vacuously" % len(bases))
    return bases


def main():
    ids, raw = species_ids()
    parent = parent_map()
    form_base = base_form_map()
    num_species = ids.get("NUM_SPECIES")
    if num_species is None:
        print("WARNING: could not resolve NUM_SPECIES -- range check skipped")

    chars = rosters()
    legend = legendary_bases()
    MAX_ROSTER_CANDIDATES = max_roster_candidates()
    findings = []
    entry_total = 0
    shadowed = 0
    for name, var, entries, starter_count in chars:
        if not entries:
            findings.append("%s: EMPTY roster" % name)
            continue
        if starter_count > len(entries):
            findings.append("%s: starterCount %d > roster size %d"
                            % (name, starter_count, len(entries)))
        # CharacterMode_RollWildOverrideSpecies builds its 10%-override
        # candidate list into u16 candidates[CHARACTER_MAX_ROSTER_CANDIDATES]
        # and stops at the cap. Overflowing it does not crash and does not fail
        # any test -- the tail of the roster simply stops appearing in the wild,
        # while ENCOUNTERS.md keeps advertising it. Goh silently lost 19
        # families that way. Fail loudly instead.
        ordinary_count = len([e for e in entries
                              if canonical_base(e, parent, form_base) not in legend])
        if ordinary_count > MAX_ROSTER_CANDIDATES:
            findings.append(
                "%s: %d non-legendary entries exceeds "
                "CHARACTER_MAX_ROSTER_CANDIDATES (%d) in include/character_mode.h "
                "-- the 10%% wild override would silently drop the last %d, and "
                "ENCOUNTERS.md would still list them. Raise the #define and this "
                "constant together."
                % (name, ordinary_count, MAX_ROSTER_CANDIDATES,
                   ordinary_count - MAX_ROSTER_CANDIDATES))
        # starterCount == 0 means "no non-legendary starter exists", and
        # ui_mode_menu.c's RandomizeStarterSelection answers it by handing the
        # character roster[0] deliberately (Tobias always starts with Darkrai)
        # instead of rolling over its legendaries. That is only the right answer
        # when the roster really IS all-legendary -- for anything else a 0 here
        # would silently suppress the starter roll. Catch the second case the
        # moment a roster change creates one.
        if starter_count == 0:
            ordinary = [e for e in entries
                        if canonical_base(e, parent, form_base) not in legend]
            if ordinary:
                findings.append(
                    "%s: starterCount is 0 but the roster has %d non-legendary "
                    "entr%s (%s) -- ui_mode_menu.c treats starterCount 0 as "
                    "'all-legendary, hand out roster[0]', so this character "
                    "would lose its starter choice"
                    % (name, len(ordinary), "y" if len(ordinary) == 1 else "ies",
                       ", ".join(ordinary[:4])))
            # ...and the check above still passes if the roster is REORDERED.
            # RandomizeStarterSelection hands out roster[0] verbatim, so the
            # identity of the starter is decided entirely by which entry is
            # first -- a silent, data-only way to change what the player gets.
            # PINNED_STARTERS records the ruling; a reorder now fails loudly
            # instead of quietly swapping Darkrai for Latios.
            expected = PINNED_STARTERS.get(name)
            if expected is None:
                findings.append(
                    "%s: starterCount is 0, so this character is handed "
                    "roster[0] (%s) as a fixed starter, but no entry exists in "
                    "PINNED_STARTERS -- add one recording which species is "
                    "intended, or a roster reorder will change it silently"
                    % (name, entries[0]))
            elif entries[0] != expected:
                findings.append(
                    "%s: fixed starter is roster[0] = %s, but PINNED_STARTERS "
                    "says %s. Either the roster was reordered (the player now "
                    "gets a different starter) or the pin is out of date -- "
                    "resolve deliberately, do not just update the pin"
                    % (name, entries[0], expected))
        roster_set = set(entries)
        for e in entries:
            entry_total += 1
            sid = ids.get(e)
            if sid is None:
                findings.append("%s: %s is not a defined species" % (name, e))
                continue
            if num_species is not None and sid >= num_species:
                findings.append("%s: %s id %d >= NUM_SPECIES" % (name, e, sid))
            base = canonical_base(e, parent, form_base)
            # src/character_mode.c's IsLegendaryRosterEntry tests roster entries
            # against sLegendaryFamilyBases DIRECTLY, with no FamilyBase walk,
            # because that walk costs ~0.2 s of GBA time per fired wild
            # encounter. That shortcut is exact only while an entry's own
            # legendary-ness matches its canonical base's. Enforce it here so a
            # future roster addition cannot quietly make the wild-encounter
            # filter wrong.
            if (e in legend) != (base in legend):
                findings.append(
                    "%s: %s and its canonical base %s disagree on being "
                    "legendary -- character_mode.c's IsLegendaryRosterEntry "
                    "shortcut is no longer exact; it must fall back to "
                    "CharacterMode_IsLegendaryOrMythical" % (name, e, base))
            if base != e:
                shadowed += 1
                if base not in roster_set:
                    findings.append(
                        "%s: %s is not a canonical family base and its base "
                        "%s is NOT on the roster -- entry is dead, family "
                        "unobtainable via this entry" % (name, e, base))

    print("audited %d characters, %d roster entries "
          "(%d non-canonical entries, all must be base-shadowed)"
          % (len(chars), entry_total, shadowed))
    if findings:
        print("\n%d FINDINGS:" % len(findings))
        for f in findings:
            print("  " + f)
        sys.exit(1)
    print("OK: every entry defined, in range, and family-base-covered")


if __name__ == "__main__":
    main()
