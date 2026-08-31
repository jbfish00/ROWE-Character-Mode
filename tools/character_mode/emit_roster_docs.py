#!/usr/bin/env python3
"""Generate ROSTERS.md / ROSTERS_SPRITES.md / sprites/gen_*.md from the data
the ROM actually enforces (rosters_mapped.json + src/data/characters.h).

Why this exists: these docs used to be hand-maintained, and on 2026-07-18 a
research pass edited them WITHOUT regenerating the game data. The result was a
shipped doc that promised 194 family bases the catch gate refused, while
omitting ~2100 the ROM already allowed. Generating them closes that hole: the
docs can no longer drift from the ROM, because they are derived from it.

Roster entries are stored as family BASES; the docs show the FINAL evolutions
each base reaches (forward walk of gEvolutionTable, leaves only), with
regional/cosmetic forms collapsed to their base form, in National Dex order.

Run after emit_characters.py:
    python3 tools/character_mode/emit_roster_docs.py
"""
import json
import os
import re
from collections import defaultdict

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))

CATEGORY_LABEL = {
    "protagonist": "Protagonist", "rival": "Rival", "gymleader": "Gym Leader",
    "elite4": "Elite Four", "champion": "Champion", "villain": "Villain",
    "anime": "Anime", "professor": "Professor", "frontier": "Frontier Brain",
    "warden": "Warden", "galaxy": "Galaxy Team", "other": "Other",
}

SPRITE_URL = ("https://cdn.jsdelivr.net/gh/PokeAPI/sprites@master"
              "/sprites/pokemon/%d.png")
SPRITES_PER_ROW = 8


def read(path):
    with open(path, encoding="utf-8") as f:
        return f.read()


def species_display_names():
    """SPECIES_* -> display name. species_names.h is capped at 10 characters,
    so the pipeline's NAME_FIXES table (Bulbapedia name -> in-game name) is
    inverted to recover the real names for the docs."""
    import importlib.util
    spec = importlib.util.spec_from_file_location(
        "map_species", os.path.join(HERE, "map_species.py"))
    ms = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(ms)
    untruncate = {v: k for k, v in ms.NAME_FIXES.items()}

    names = {}
    for m in re.finditer(r'\[(SPECIES_\w+)\]\s*=\s*_\("([^"]+)"\)',
                         read(os.path.join(TARGET, "src/data/text/species_names.h"))):
        const, name = m.group(1), m.group(2)
        names.setdefault(const, untruncate.get(name, name))
    return names


def load_unselectable():
    """Characters present in the table but not offerable in this game.

    They keep their slot so save files (which store the character INDEX) stay
    valid, but a player cannot pick them -- so they must not appear in the
    documentation either. The docs describe what is AVAILABLE."""
    path = os.path.join(HERE, "character_drops.json")
    if not os.path.isfile(path):
        return set()
    with open(path, encoding="utf-8") as f:
        return set(json.load(f).get("unselectable", []))


def hidden_slot_count():
    """How many table slots are compiled with .selectable = 0.

    NOT len(load_unselectable()). A character the threshold drops keeps its slot
    and is hidden -- but one whose roster comes out EMPTY in this game's dex is
    dropped from gCharacters entirely and has no slot at all. Cogita and Iscan
    are in character_drops.json for that second reason, so the drops file says
    32 while only 30 slots exist. Printing the drops count made ROSTERS.md
    promise save compatibility for two slots that are not there."""
    text = read(os.path.join(TARGET, "src/data/characters.h"))
    return len(re.findall(r"\.selectable = 0,", text))


def load_sources():
    """{character: {species display name: {source, owned_form}}} from the
    2026-07-25 roster audit. Absent file = an empty Source column."""
    path = os.path.join(HERE, "roster_sources.json")
    if not os.path.isfile(path):
        return {}
    with open(path, encoding="utf-8") as f:
        return json.load(f).get("sources", {})


REGION_PREFIX = {"_ALOLAN": "Alolan", "_ALOLA": "Alolan", "_GALARIAN": "Galarian",
                 "_GALAR": "Galarian", "_HISUIAN": "Hisuian", "_HISUI": "Hisuian",
                 "_PALDEAN": "Paldean", "_PALDEA": "Paldean"}


_COLLAPSE = None


def _collapse_table():
    """Cached {form member -> slot-0 species}. regional_form needs it to tell a
    plain regional form from a mega/zen variant OF one."""
    global _COLLAPSE
    if _COLLAPSE is None:
        _COLLAPSE = form_tables()[0]
    return _COLLAPSE


def regional_form(const):
    """Region a SPECIES_ constant marks, or None. Regional forms get their own
    doc row (user, 2026-07-25); megas and cosmetic forms stay folded in.

    A constant can carry a form qualifier BEFORE the region --
    SPECIES_SANDSLASH_MEGA_ALOLA, SPECIES_DARMANITAN_ZEN_MODE_GALARIAN. A bare
    endswith() test called those plain regional forms, so they got their own row
    AND rendered to the same display name as the real one ("Alolan Sandslash",
    "Galarian Darmanitan"): a duplicate row for 17 characters, every one of
    their header counts one too high. They are variants of a regional form, not
    the regional form, and must fold in.

    The test is whether the constant is exactly <base><region> -- i.e. whatever
    is left after stripping the region is a base species and not itself a form.
    """
    collapse = _collapse_table()
    for suffix, prefix in REGION_PREFIX.items():
        if not const.endswith(suffix):
            continue
        # SPECIES_SANDSLASH_MEGA is a form of SPECIES_SANDSLASH, so
        # SPECIES_SANDSLASH_MEGA_ALOLA is a variant, not a regional form.
        if collapse.get(const[:-len(suffix)]) is not None:
            return None
        return prefix
    return None


PLACEHOLDER_FORMS = {"normal", "base", "none", "-", ""}


def source_cell(char_sources, base_const, names, shown_const):
    """"as Bulbasaur — Anime (Indigo League)", or just the source when the
    character owned the final stage itself. Sources are keyed by the Bulbapedia
    display name of the family BASE, which is what the audit recorded."""
    base_name = names.get(base_const) or (pretty(base_const) if base_const else None)
    info = (char_sources.get(base_name) if base_name else None) or {}
    src = info.get("source")
    if not src:
        return "—"
    owned = (info.get("owned_form") or "").strip()
    shown = names.get(shown_const) or pretty(shown_const)
    if owned and owned.lower() not in PLACEHOLDER_FORMS and owned != shown:
        return "as %s — %s" % (owned, src)
    return src


def pretty(const):
    """Readable name for a species that species_names.h has no string for
    (Ursaluna, Wyrdeer, Basculegion, Overqwil: they exist as constants and are
    reachable as evolutions, but the ported name table never got an entry).
    Without this the docs print the raw SPECIES_ identifier."""
    return const[len("SPECIES_"):].replace("_", " ").title()


# Battle-only transformations, not evolutions: they live in gEvolutionTable but
# a Charizard is still a final evolution. Counting them as children would drop
# every mega-capable species out of the "final evolutions" list.
NON_EVOLUTION_METHODS = {"EVO_MEGA_EVOLUTION", "EVO_MOVE_MEGA_EVOLUTION"}


def evolution_children():
    """SPECIES_* -> [species it can evolve into]."""
    text = read(os.path.join(TARGET, "src/data/pokemon/evolution.h"))
    body = re.search(r"gEvolutionTable\[NUM_SPECIES\]\[EVOS_PER_MON\]\s*=\s*\{(.*?)^\};",
                     text, re.S | re.M).group(1)
    rows = [(r.start(), r.group(1)) for r in re.finditer(r"\[(SPECIES_\w+)\]\s*=", body)]
    kids = defaultdict(list)
    for t in re.finditer(r"\{\s*(EVO_\w+)\s*,[^,{}]+,\s*(SPECIES_\w+)", body):
        if t.group(1) in NON_EVOLUTION_METHODS:
            continue
        src = None
        for pos, name in rows:
            if pos < t.start():
                src = name
            else:
                break
        if src and src != t.group(2) and t.group(2) not in kids[src]:
            kids[src].append(t.group(2))
    return kids


def form_tables():
    """(collapse, siblings): form member -> slot-0 species of its form table,
    and species -> every member of that table.

    Both directions matter. Collapse is display-only (Alolan Raichu shows as
    Raichu). Siblings matter for correctness: the catch gate canonicalizes
    forms, so owning the Wooper family means Paldean Wooper — and therefore
    CLODSIRE — is legal, even though a pure evolution walk from SPECIES_WOOPER
    only ever reaches Quagsire. Same shape for Perrserker and Runerigus."""
    text = read(os.path.join(TARGET, "src/data/pokemon/form_species_table.h"))
    collapse, siblings = {}, {}
    for m in re.finditer(r"static const u16 \w+\[\]\s*=\s*\{(.*?)\};", text, re.S):
        members = re.findall(r"(SPECIES_\w+)", m.group(1))
        for member in members[1:]:
            collapse.setdefault(member, members[0])
        for member in members:
            siblings.setdefault(member, members)
    return collapse, siblings


def national_dex_numbers():
    """SPECIES_* -> National Dex number."""
    dex_consts = {}
    for m in re.finditer(r"#define (NATIONAL_DEX_\w+)\s+(\d+)",
                         read(os.path.join(TARGET, "include/constants/species.h"))):
        dex_consts[m.group(1)] = int(m.group(2))
    pokemon_c = read(os.path.join(TARGET, "src/pokemon.c"))
    nums = {}
    for m in re.finditer(r"SPECIES_TO_NATIONAL\((\w+)\)", pokemon_c):
        nums["SPECIES_" + m.group(1)] = dex_consts.get("NATIONAL_DEX_" + m.group(1), 0)
    # The Gen 9 port writes its rows the long way instead of via the macro;
    # parsing only the macro leaves every Paldea species at dex 0, which shows
    # up as sprite id 0 and as alphabetical rather than dex ordering.
    for m in re.finditer(r"\[(SPECIES_\w+) - 1\]\s*=\s*(NATIONAL_DEX_\w+)", pokemon_c):
        nums.setdefault(m.group(1), dex_consts.get(m.group(2), 0))
    # Ursaluna, Wyrdeer, Basculegion and Overqwil were ported as evolution
    # targets without a gSpeciesToNationalPokedexNum row at all; their dex
    # constants do exist, so match them by name.
    for const, num in dex_consts.items():
        nums.setdefault("SPECIES_" + const[len("NATIONAL_DEX_"):], num)
    return nums


def emitted_characters():
    """Display name -> generation, in gCharacters order (the emitted set: what
    the player can actually pick)."""
    text = read(os.path.join(TARGET, "src/data/characters.h"))
    names = dict(re.findall(r'static const u8 sName_(\w+)\[\]\s*=\s*_\("([^"]+)"\)', text))
    out = []
    for m in re.finditer(r"\.name = sName_(\w+),.*?\.generation = (\d+),", text, re.S):
        out.append((names[m.group(1)], int(m.group(2)), m.group(1)))
    return out


def main():
    mapped = json.load(open(os.path.join(HERE, "rosters_mapped.json")))
    names = species_display_names()
    kids = evolution_children()
    collapse, siblings = form_tables()
    dex = national_dex_numbers()

    # characters.h stores the menu name ("Kiawe"); rosters_mapped.json may key
    # it by page name ("Kiawe (anime)").
    by_menu_name = {}
    for key, info in mapped.items():
        by_menu_name.setdefault(re.sub(r"\s*\(anime\)$", "", key), (key, info))

    sources = load_sources()

    def finals_of(base):
        """Leaves of the family rooted at base, walking evolutions AND form
        siblings (see form_tables), collapsed to base forms for display."""
        out, stack, seen = set(), [base], set()
        while stack:
            cur = stack.pop()
            if cur in seen:
                continue
            seen.add(cur)
            children = kids.get(cur, [])
            if not children:
                # a regional form keeps its own row; other forms fold into the
                # base form they share a table with
                out.add(cur if regional_form(cur) else collapse.get(cur, cur))
            stack.extend(children)
            stack.extend(siblings.get(cur, ()))
        # A cosmetic form that cannot evolve (the cap Pikachus) is a leaf of
        # the walk but collapses onto a species that CAN evolve - listing
        # "Pikachu" as a final evolution is just noise. Perrserker/Clodsire/
        # Runerigus survive this: they are their own species, not forms.
        return {s for s in out if not kids.get(s)}

    unselectable = load_unselectable()
    # The prose count of hidden slots must come from the COMPILED table, not
    # from the drops file -- see hidden_slot_count().
    hidden = hidden_slot_count()

    # The audit recorded a source against the species the character OWNED
    # ("Pikachu"); the roster stores that family's BASE ("Pichu"), which is what
    # the docs resolve finals from. Re-key every source onto its family base or
    # the lookup misses for every character whose owned stage is not the base --
    # which was 60% of all rows.
    import importlib.util as _il
    _spec = _il.spec_from_file_location("map_species", os.path.join(HERE, "map_species.py"))
    _ms = _il.module_from_spec(_spec)
    _spec.loader.exec_module(_ms)
    _n2c = _ms.name_to_const()
    _canon = _ms.make_canonical(_ms.first_stage_map(), _ms.base_form_map())
    _fixes = getattr(_ms, "NAME_FIXES", {})

    def _base_name(species_name):
        const = _n2c.get(_fixes.get(species_name, species_name)) or _n2c.get(species_name)
        if not const:
            # "Hisuian Arcanine" is keyed that way by the audit, but the roster
            # resolves it to the Growlithe line when the ROM has no Hisuian
            # form -- so the source has to follow it there.
            const = _ms.regional_fallback(species_name, _n2c)
        if not const:
            return None
        return names.get(_canon(const))

    rekeyed = {}
    for char, entries in sources.items():
        # ...and the audit keyed characters by PAGE name too ("Lana (anime)"),
        # while the lookup below uses the menu name. Four Alola captains lost
        # every source label to that mismatch.
        char = re.sub(r"\s*\(anime\)$", "", char)
        out = rekeyed.setdefault(char, {})
        for species_name, info in entries.items():
            out.setdefault(species_name, info)
            base = _base_name(species_name)
            if base:
                out.setdefault(base, info)
    sources = rekeyed

    chars = []
    for menu_name, gen, _cid in emitted_characters():
        if menu_name in unselectable:
            continue          # in the table, but the menu will not offer it
        key, info = by_menu_name[menu_name]
        finals, base_of = set(), {}
        for base in info["species"]:
            got = finals_of(base)
            for f in got:
                base_of.setdefault(f, base)
            finals |= got
        # The constant is the final tiebreak, and it is not decorative: a
        # regional form shares both its dex number AND its species_names.h
        # string with the base form ("Raichu" / "Raichu"), so without it the
        # two rows sort equal and land in set-iteration order -- which varies
        # per run with hash randomization, and made every regeneration produce
        # a spurious ~190-line diff.
        ordered = sorted(finals,
                         key=lambda s: (dex.get(s, 9999), names.get(s) or pretty(s), s))
        char_sources = sources.get(menu_name, {})
        chars.append({
            "name": menu_name,
            "gen": gen,
            "label": CATEGORY_LABEL.get(info["category"], info["category"].title()),
            "finals": [(("%s %s" % (regional_form(s), names.get(s) or pretty(s)))
                        if regional_form(s) else (names.get(s) or pretty(s)),
                        dex.get(s, 0),
                        source_cell(char_sources, base_of.get(s), names, s))
                       for s in ordered],
        })

    by_gen = defaultdict(list)
    for c in chars:
        by_gen[c["gen"]].append(c)
    for g in by_gen:
        by_gen[g].sort(key=lambda c: c["name"])
    gens = sorted(by_gen)

    # ---- ROSTERS.md --------------------------------------------------------
    sourced = sum(1 for c in chars for _n, _d, src in c["finals"] if src and src != "—")
    total_rows = sum(len(c["finals"]) for c in chars)
    # The "the remainder ..." clause only makes sense while there IS a
    # remainder; at 100% it read as an unexplained contradiction.
    coverage_note = (
        "Under each Pokémon is the source of that character's appearance — the game, "
        "the anime series or era, the movie, or the manga. **%d of %d entries (%.0f%%) "
        "are attributed**%s"
        % (sourced, total_rows, 100.0 * sourced / max(total_rows, 1),
           "." if sourced >= total_rows else
           "; the remainder joined the roster through an earlier research pass and "
           "their source has not been established yet."))

    out = ["# Character Mode — Final-Evolution Rosters (Pokémon ROWE)", "",
           "Every playable character and the **final evolutions** their complete roster "
           "resolves to, in **National Pokédex order**. Rosters were researched from "
           "Bulbapedia (union of all games, remakes, rematches, and anime) and "
           "cross-checked where possible. Regional/cosmetic forms show as their base "
           "species. An off-roster ball is refused outright (the Pokémon is "
           "never caught); off-roster gifts are routed to your PC instead.", "",
           "**%d playable characters.** Sprite version: `ROSTERS_SPRITES.md`."
           % len(chars), "",
           ("%d further characters remain in the data but are not offered in this "
            "game: fewer than six fully-evolved members of their roster exist in "
            "its Pokédex. They keep their slot so existing saves stay valid."
            % hidden) if hidden else "", "",
           coverage_note, "",
           "GENERATED by `tools/character_mode/emit_roster_docs.py` from the same data "
           "the ROM enforces (`rosters_mapped.json` + `src/data/characters.h`) — "
           "do not hand-edit, regenerate.", "",
           "## Contents"]
    for g in gens:
        out.append("- [Generation %d](#generation-%d)" % (g, g))
    out.append("")
    for g in gens:
        out += ["", "## Generation %d" % g, ""]
        for c in by_gen[g]:
            out.append("### %s — %s" % (c["name"], c["label"]))
            out.append("**Final evolutions (%d):**" % len(c["finals"]))
            out.append("")
            out.append("| Pokémon | Source |")
            out.append("|---|---|")
            for name, _dex, src in c["finals"]:
                out.append("| %s | %s |" % (name, src))
            out.append("")
    with open(os.path.join(TARGET, "ROSTERS.md"), "w", encoding="utf-8") as f:
        f.write("\n".join(out).rstrip() + "\n")

    # ---- ROSTERS_SPRITES.md + sprites/gen_N.md -----------------------------
    idx = ["# Character Mode — Roster Sprites (Pokémon ROWE)", "",
           "Each character's **final-evolution** roster, in **National Pokédex order**, "
           "with sprites. Split by generation to keep pages fast. Under every sprite "
           "is the Pokémon's name and, in italics, **where that character's appearance "
           "comes from** — the game, the anime series or era, the movie, or the manga. "
           "Regional forms are listed separately (Alolan Persian is its own entry); "
           "mega and cosmetic forms stay folded into the base. Sprites via "
           "[PokéAPI](https://github.com/PokeAPI/sprites). Text version: `ROSTERS.md`.",
           "", "**%d playable characters.**" % len(chars), "",
           coverage_note, "",
           ("%d further characters remain in the data but are not offered in this game "
            "and are therefore not listed here." % hidden)
           if hidden else "", "",
           "GENERATED by `tools/character_mode/emit_roster_docs.py` — do not hand-edit.",
           "", "## Generations", ""]
    for g in gens:
        idx.append("- [Generation %d](sprites/gen_%d.md) — %d characters"
                   % (g, g, len(by_gen[g])))
    with open(os.path.join(TARGET, "ROSTERS_SPRITES.md"), "w", encoding="utf-8") as f:
        f.write("\n".join(idx).rstrip() + "\n")

    os.makedirs(os.path.join(TARGET, "sprites"), exist_ok=True)
    for g in gens:
        page = ["# Pokémon ROWE — Roster Sprites (Generation %d)" % g, "",
                "Final-evolution rosters in National Pokédex order, sprites with names. "
                "[← back to index](../ROSTERS_SPRITES.md)", ""]
        for c in by_gen[g]:
            page.append("### %s — %s" % (c["name"], c["label"]))
            page.append("<table>")
            row = []
            for name, num, src in c["finals"]:
                note = ("<br><sub><i>%s</i></sub>" % src) if src and src != "—" else ""
                cell = ('<td align="center" width="100"><img width="56" src="%s">'
                        "<br><sub>%s</sub>%s</td>" % (SPRITE_URL % num, name, note))
                row.append(cell)
                if len(row) == SPRITES_PER_ROW:
                    page.append("<tr>" + "".join(row) + "</tr>")
                    row = []
            if row:
                page.append("<tr>" + "".join(row) + "</tr>")
            page += ["</table>", ""]
        with open(os.path.join(TARGET, "sprites/gen_%d.md" % g), "w", encoding="utf-8") as f:
            f.write("\n".join(page).rstrip() + "\n")

    total = sum(len(c["finals"]) for c in chars)
    print("wrote ROSTERS.md, ROSTERS_SPRITES.md and %d sprites/gen_*.md: "
          "%d characters, %d final-evolution entries"
          % (len(gens), len(chars), total))


if __name__ == "__main__":
    main()
