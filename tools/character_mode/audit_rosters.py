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
  4. starterCount <= roster length

Exit code 1 on any finding; prints a summary either way.
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))


def read(path):
    with open(path, encoding="utf-8") as f:
        return f.read()


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


def main():
    ids, raw = species_ids()
    parent = parent_map()
    form_base = base_form_map()
    num_species = ids.get("NUM_SPECIES")
    if num_species is None:
        print("WARNING: could not resolve NUM_SPECIES -- range check skipped")

    chars = rosters()
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
