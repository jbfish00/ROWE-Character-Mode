#!/usr/bin/env python3
"""Generate ENCOUNTERS.md -- what each character can actually MEET in the wild.

Spec: ../Character Hacks/game_plans/legendary_encounters.md §3.

GENERATED. Never hand-edit ENCOUNTERS.md; regenerate it.

WHAT THIS IS NOT. ROSTERS.md documents what a character can OWN: it walks form
siblings as well as evolutions, because the catch gate canonicalizes forms, so
owning the Wooper family legalises Paldean Wooper and therefore Clodsire. This
file documents what the game can SPAWN, which is a different and strictly
narrower thing: CharacterMode_PickEvolutionStageForLevel walks gEvolutionTable
alone and never consults the form tables, so a form that is legal to own may be
impossible to meet. Do not "fix" one to match the other.

Derived from src/data/characters.h -- the emitted table the ROM actually uses --
and NOT from rosters_mapped.json. The spec is explicit about this: that file sits
upstream of the level-band computation and of the per-game dex filter, so a doc
built from it would promise families the ROM cannot spawn. That exact drift
(docs and ROM disagreeing in both directions) is what forced the 2026-07-24
roster resync.

Determinism: rows sort by national dex number, then display name, then the
SPECIES_ constant. The constant is the final tiebreak because a regional form
shares BOTH its dex number and its species_names.h string with its base form, so
without it the rows tie and fall into set-iteration order -- which made every
regeneration diff ~190 lines with no data change (fixed in 33483fdf).
"""

import json
import os
import re
import sys
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))

# Mirrors src/character_mode.c. Both rates are independent rolls, legendary
# first, so the roster override sees only the 99% that the legendary roll
# declined.
LEGENDARY_PCT = 1
OVERRIDE_PCT = 10

# sEvoDepthFallbackLevel in src/character_mode.c: the level assumed for an
# evolution whose trigger carries no level (item, trade, friendship...), indexed
# by how deep the walk is.
EVO_DEPTH_FALLBACK = [16, 32, 40, 48, 56, 64, 72, 80, 88, 96]

# IsLevelBasedEvoMethod in src/character_mode.c -- these read .param as a level.
LEVEL_METHODS = {
    "EVO_LEVEL", "EVO_LEVEL_ATK_GT_DEF", "EVO_LEVEL_ATK_EQ_DEF",
    "EVO_LEVEL_ATK_LT_DEF", "EVO_LEVEL_SILCOON", "EVO_LEVEL_CASCOON",
    "EVO_LEVEL_NINJASK", "EVO_LEVEL_SHEDINJA", "EVO_LEVEL_FEMALE",
    "EVO_LEVEL_MALE", "EVO_LEVEL_NIGHT", "EVO_LEVEL_DAY", "EVO_LEVEL_DUSK",
    "EVO_LEVEL_RAIN", "EVO_LEVEL_DARK_TYPE_MON_IN_PARTY",
    "EVO_LEVEL_NIGHT_ALOLA", "EVO_LEVEL_SEVII", "EVO_LEVEL_NOT_SEVII",
}

# Battle-only forms; the stage picker skips them, so they can never spawn.
NON_EVOLUTION_METHODS = {"EVO_MEGA_EVOLUTION", "EVO_MOVE_MEGA_EVOLUTION"}

MAX_LEVEL = 100


def read(path):
    with open(path, encoding="utf-8", errors="replace") as f:
        return f.read()


def legendary_bases():
    """LEGENDARY_BASES from emit_characters.py, EXECUTED rather than regex-parsed.

    A regex over that literal is how the roster-audit invariant came out as an
    empty set and passed vacuously; every membership test was false and the check
    proved nothing. Hard-fail if the set is implausibly small rather than emit a
    document that quietly claims nobody has a legendary.
    """
    src = read(os.path.join(HERE, "emit_characters.py"))
    start = src.index("LEGENDARY_BASES")
    end = src.index("# Manual asset overrides")
    ns = {}
    exec(compile(src[start:end], "legendary_bases", "exec"), ns)
    bases = ns["LEGENDARY_BASES"]
    if len(bases) < 90:
        sys.exit("emit_encounter_docs: LEGENDARY_BASES came out at %d entries, "
                 "expected ~98 -- extraction is broken and every legendary "
                 "column would be silently empty" % len(bases))
    return bases


def species_ids():
    """SPECIES_* -> numeric id, resolving the expression forms species.h uses
    (aliases, GEN_9_START + n, FORMS_START arithmetic). Reuses audit_rosters.py's
    resolver rather than duplicating it, so the two cannot disagree."""
    src = read(os.path.join(HERE, "audit_rosters.py"))
    ns = {"__file__": os.path.join(HERE, "audit_rosters.py")}
    exec(compile(src.split("def main()")[0], "species_ids", "exec"), ns)
    ids, _raw = ns["species_ids"]()
    return {k: v for k, v in ids.items() if k.startswith("SPECIES_") and v is not None}


def species_display_names():
    """SPECIES_* -> display name, from the same table the ROM prints."""
    text = read(os.path.join(TARGET, "src/data/text/species_names.h"))
    out = {}
    for m in re.finditer(r'\[(SPECIES_\w+)\]\s*=\s*_\("([^"]*)"\)', text):
        out[m.group(1)] = m.group(2)
    return out


def national_dex_numbers():
    """SPECIES_* -> National Dex number, for a stable sort."""
    text = read(os.path.join(TARGET, "src/pokemon.c"))
    body = re.search(r"gSpeciesToNationalPokedexNum\[NUM_SPECIES\]\s*=.*?\{(.*?)^\};",
                     text, re.S | re.M)
    out = {}
    if not body:
        return out
    for m in re.finditer(r"\[(SPECIES_\w+)\s*-\s*1\]\s*=\s*(NATIONAL_DEX_\w+|\d+)",
                         body.group(1)):
        out[m.group(1)] = m.group(2)
    consts = {}
    sp = read(os.path.join(TARGET, "include/constants/species.h"))
    for m in re.finditer(r"#define\s+(NATIONAL_DEX_\w+)\s+(\d+)", sp):
        consts[m.group(1)] = int(m.group(2))
    return {k: (consts.get(v, 0) if not v.isdigit() else int(v))
            for k, v in out.items()}


def evolutions():
    """SPECIES_* -> [(method, param, target)], mega/battle-only entries dropped.

    param is kept as text: for a level method it is the required level, for
    anything else it is an item/other id the stage picker ignores.
    """
    text = read(os.path.join(TARGET, "src/data/pokemon/evolution.h"))
    body = re.search(r"gEvolutionTable\[NUM_SPECIES\]\[EVOS_PER_MON\]\s*=\s*\{(.*?)^\};",
                     text, re.S | re.M).group(1)
    rows = [(m.start(), m.group(1)) for m in re.finditer(r"\[(SPECIES_\w+)\]\s*=", body)]
    evo = defaultdict(list)
    for t in re.finditer(r"\{\s*(EVO_\w+)\s*,\s*([^,]+?)\s*,\s*(SPECIES_\w+)", body):
        if t.group(1) in NON_EVOLUTION_METHODS:
            continue
        src = None
        for pos, name in rows:
            if pos < t.start():
                src = name
            else:
                break
        if src and t.group(3) != src:
            evo[src].append((t.group(1), t.group(2).strip(), t.group(3)))
    return evo


def required_level(method, param, depth):
    """Exactly CharacterMode_PickEvolutionStageForLevel's rule."""
    if method in LEVEL_METHODS:
        try:
            return int(param)
        except ValueError:
            return EVO_DEPTH_FALLBACK[min(depth, len(EVO_DEPTH_FALLBACK) - 1)]
    return EVO_DEPTH_FALLBACK[min(depth, len(EVO_DEPTH_FALLBACK) - 1)]


def reachable(evo, species, level, depth=0, seen=None):
    """Every species the picker can return for `species` at `level`.

    Mirrors the C: at each depth collect every target whose required level is
    <= level; if ANY qualify the walk advances (the C picks one at random, so
    the possible outcomes are the union over candidates); if none qualify the
    current species is the answer.
    """
    if seen is None:
        seen = set()
    if depth >= len(EVO_DEPTH_FALLBACK) or species in seen:
        return {species}
    seen = seen | {species}
    cands = [t for (m, p, t) in evo.get(species, [])
             if required_level(m, p, depth) <= level]
    if not cands:
        return {species}
    out = set()
    for t in cands:
        out |= reachable(evo, t, level, depth + 1, seen)
    return out


def chain_text(evo, base, names):
    """A compact rendering of the family's spawn stages and their thresholds.

    Built by simulation over every level rather than by reading thresholds off
    the table, because branching and the depth-indexed fallback make the
    effective threshold differ from the raw .param.
    """
    first_seen = {}
    for lvl in range(1, MAX_LEVEL + 1):
        for sp in reachable(evo, base, lvl):
            first_seen.setdefault(sp, lvl)
    ordered = sorted(first_seen.items(), key=lambda kv: (kv[1], kv[0]))
    parts = []
    for sp, lvl in ordered:
        label = names.get(sp, pretty(sp))
        parts.append(label if lvl <= 1 else "%s (%d)" % (label, lvl))
    return " → ".join(parts)


def pretty(const):
    return const.replace("SPECIES_", "").replace("_", " ").title()


def rosters():
    """Display name -> (generation, [roster species], selectable) in gCharacters
    order, from the EMITTED table."""
    text = read(os.path.join(TARGET, "src/data/characters.h"))
    names = dict(re.findall(r'static const u8 sName_(\w+)\[\]\s*=\s*_\("([^"]+)"\)', text))
    rost = {}
    for m in re.finditer(r"static const u16 sRoster_(\w+)\[\]\s*=\s*\{(.*?)\};", text, re.S):
        entries = [e for e in re.findall(r"(SPECIES_\w+)", m.group(2))
                   if e != "SPECIES_NONE"]
        rost[m.group(1)] = entries
    out = []
    for m in re.finditer(
            r"\.name = sName_(\w+),.*?\.roster = sRoster_(\w+),.*?"
            r"\.generation = (\d+),.*?\.selectable = (\d+)", text, re.S):
        out.append((names[m.group(1)], int(m.group(3)),
                    rost.get(m.group(2), []), m.group(4) == "1", m.group(1)))
    return out


def main():
    legend = legendary_bases()
    names = species_display_names()
    dex = national_dex_numbers()
    evo = evolutions()
    chars = rosters()
    if not chars:
        sys.exit("emit_encounter_docs: parsed 0 characters from characters.h")

    def sort_key(sp):
        # dex, then display name, then the constant -- the constant is the final
        # tiebreak so regional forms (same dex, same printed name) never tie.
        return (dex.get(sp, 0), names.get(sp, pretty(sp)), sp)

    lines = []
    lines.append("# ENCOUNTERS.md — what each character can meet in the wild")
    lines.append("")
    lines.append("**GENERATED by `tools/character_mode/emit_encounter_docs.py`. "
                 "Do not hand-edit — regenerate.**")
    lines.append("")
    lines.append("Every wild encounter rolls twice, independently, before the "
                 "area's own table is used:")
    lines.append("")
    lines.append("| roll | chance | pool |")
    lines.append("|---|---|---|")
    lines.append("| legendary | **%d%%** | a legendary from this character's "
                 "roster, offered until caught |" % LEGENDARY_PCT)
    lines.append("| roster | **%d%%** of the remaining %d%% | any non-legendary "
                 "family on the roster |" % (OVERRIDE_PCT, 100 - LEGENDARY_PCT))
    lines.append("| — | the rest | the area's own wild table, untouched |")
    lines.append("")
    lines.append("A character with no legendary never rolls the first one at "
                 "all, so its rates are exactly the shipped %d%% / %d%%."
                 % (OVERRIDE_PCT, 100 - OVERRIDE_PCT))
    lines.append("")
    lines.append("⚠️ **This is what can SPAWN, which is narrower than what can "
                 "be OWNED.** `ROSTERS.md` walks form siblings as well as "
                 "evolutions, because the catch gate canonicalizes forms. The "
                 "wild stage picker walks the evolution table alone, so a form "
                 "that is legal to own can be impossible to meet.")
    lines.append("")
    lines.append("A number after a stage is the level from which it can appear; "
                 "the stage before it stops appearing at that level.")
    lines.append("")

    empty, no_legendary, repeatable_chars = [], 0, []
    body = []

    for disp, gen, roster, selectable, cid in chars:
        legends = sorted([s for s in roster if s in legend], key=sort_key)
        ordinary = sorted([s for s in roster if s not in legend], key=sort_key)

        # The §1.2 exemption: no ordinary family means the legendaries stay
        # repeatable, because otherwise this character catches its one legendary
        # and can then catch nothing at all for the rest of the run.
        repeatable = not ordinary
        if repeatable and legends:
            repeatable_chars.append(disp)
        if not roster:
            empty.append(disp)
        if not legends:
            no_legendary += 1

        head = "## %s — Gen %d" % (disp, gen)
        if not selectable:
            head += " *(not selectable)*"
        body.append(head)
        body.append("")

        if not roster:
            body.append("**EMPTY POOL — this character can meet nothing and "
                        "catch nothing.** Both rolls decline every time, so "
                        "every encounter falls through to the area's own table.")
            body.append("")
            continue

        if legends:
            body.append("**Legendary — %d%%, %s:** %s"
                        % (LEGENDARY_PCT,
                           "repeatable (no ordinary family on this roster)"
                           if repeatable else "each offered until caught",
                           " · ".join(names.get(s, pretty(s)) for s in legends)))
        else:
            body.append("**Legendary — none on this roster, so the 1%% roll "
                        "never runs.**")
        body.append("")

        if ordinary:
            body.append("**Roster — %d%% of encounters, %d families:**"
                        % (OVERRIDE_PCT, len(ordinary)))
            body.append("")
            for s in ordinary:
                body.append("- " + chain_text(evo, s, names))
        else:
            body.append("**Roster — no ordinary families.** The %d%% roll can "
                        "never produce anything, which is why the legendaries "
                        "above stay repeatable." % OVERRIDE_PCT)
        body.append("")

    lines.append("## Summary")
    lines.append("")
    lines.append("- **%d** characters in the table." % len(chars))
    lines.append("- **%d** have at least one legendary; **%d** have none and are "
                 "completely unaffected by the 1%% roll."
                 % (len(chars) - no_legendary, no_legendary))
    lines.append("- **%d** have an all-legendary roster, so their legendaries "
                 "stay repeatable (spec §1.2)%s."
                 % (len(repeatable_chars),
                    ": " + ", ".join(repeatable_chars) if repeatable_chars else ""))
    if empty:
        lines.append("- ⚠️ **%d have an EMPTY pool and can meet nothing: %s.** "
                     "That is the catch-nothing failure mode."
                     % (len(empty), ", ".join(empty)))
    else:
        lines.append("- No character has an empty pool.")
    lines.append("")
    lines.extend(body)

    # Machine-readable expectations for the engine cross-check. The doc's model
    # of the stage picker is a Python reimplementation of
    # CharacterMode_PickEvolutionStageForLevel; agreeing with itself proves
    # nothing, so emit the cases a headless test replays against the real ROM.
    # Chosen to cover the shapes that actually differ: a plain three-stage line,
    # a branch (Eevee), a non-level trigger that falls back to the depth table,
    # and a single-stage legendary.
    probe_species = ["SPECIES_BULBASAUR", "SPECIES_EEVEE", "SPECIES_POOCHYENA",
                     "SPECIES_ARTICUNO", "SPECIES_MAGIKARP", "SPECIES_WOOPER"]
    probes = []
    for sp in probe_species:
        if sp not in evo and sp not in names:
            continue
        for lvl in (5, 16, 30, 50, 100):
            expect = sorted(reachable(evo, sp, lvl))
            probes.append((sp, lvl, expect))
    # Emitted as Lua, with species CONSTANTS resolved to numeric ids, because
    # the mGBA harness dofile()s it directly and has no JSON parser.
    ids = species_ids()
    probe_path = os.path.join(TARGET, "tools/mgba_scripts/encounter_probes.lua")
    rows = []
    skipped = []
    for sp, lvl, exp in probes:
        if sp not in ids or any(e not in ids for e in exp):
            skipped.append(sp)
            continue
        rows.append("    {%d, %d, {%s}},  -- %s Lv%d -> %s"
                    % (ids[sp], lvl, ", ".join(str(ids[e]) for e in exp),
                       names.get(sp, pretty(sp)), lvl,
                       ", ".join(names.get(e, pretty(e)) for e in exp)))
    if not rows:
        sys.exit("emit_encounter_docs: produced 0 engine probes -- the replay "
                 "test would pass while checking nothing")
    with open(probe_path, "w", encoding="utf-8") as f:
        f.write("-- GENERATED by tools/character_mode/emit_encounter_docs.py.\n"
                "-- Do not hand-edit. Replayed against the real in-ROM stage\n"
                "-- picker by tools/mgba_scripts/encounter_doc_e2e.lua, so that\n"
                "-- ENCOUNTERS.md is checked against the ENGINE and not merely\n"
                "-- against the generator's own model of it.\n"
                "-- Each row is {species id, level, {every stage that may result}}.\n"
                "return {\n")
        f.write("\n".join(rows))
        f.write("\n}\n")
    if skipped:
        print("  note: %d probe species had no resolvable id and were skipped: %s"
              % (len(skipped), ", ".join(sorted(set(skipped)))))

    out = os.path.join(TARGET, "ENCOUNTERS.md")
    with open(out, "w", encoding="utf-8") as f:
        f.write("\n".join(lines).rstrip() + "\n")
    print("wrote %s (%d characters, %d with a legendary, %d empty)"
          % (out, len(chars), len(chars) - no_legendary, len(empty)))
    print("wrote %s (%d engine cross-check probes)" % (probe_path, len(rows)))


if __name__ == "__main__":
    main()
