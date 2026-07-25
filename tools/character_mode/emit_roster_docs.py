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
    "anime": "Anime", "professor": "Professor",
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
    nums = {}
    for m in re.finditer(r"SPECIES_TO_NATIONAL\((\w+)\)", read(os.path.join(TARGET, "src/pokemon.c"))):
        nums["SPECIES_" + m.group(1)] = dex_consts.get("NATIONAL_DEX_" + m.group(1), 0)
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
                out.add(collapse.get(cur, cur))
            stack.extend(children)
            stack.extend(siblings.get(cur, ()))
        # A cosmetic form that cannot evolve (the cap Pikachus) is a leaf of
        # the walk but collapses onto a species that CAN evolve - listing
        # "Pikachu" as a final evolution is just noise. Perrserker/Clodsire/
        # Runerigus survive this: they are their own species, not forms.
        return {s for s in out if not kids.get(s)}

    chars = []
    for menu_name, gen, _cid in emitted_characters():
        key, info = by_menu_name[menu_name]
        finals = set()
        for base in info["species"]:
            finals |= finals_of(base)
        ordered = sorted(finals, key=lambda s: (dex.get(s, 9999), names.get(s, s)))
        chars.append({
            "name": menu_name,
            "gen": gen,
            "label": CATEGORY_LABEL.get(info["category"], info["category"].title()),
            "finals": [(names.get(s, s), dex.get(s, 0)) for s in ordered],
        })

    by_gen = defaultdict(list)
    for c in chars:
        by_gen[c["gen"]].append(c)
    for g in by_gen:
        by_gen[g].sort(key=lambda c: c["name"])
    gens = sorted(by_gen)

    # ---- ROSTERS.md --------------------------------------------------------
    out = ["# Character Mode — Final-Evolution Rosters (Pokémon ROWE)", "",
           "Every playable character and the **final evolutions** their complete roster "
           "resolves to, in **National Pokédex order**. Rosters were researched from "
           "Bulbapedia (union of all games, remakes, rematches, and anime) and "
           "cross-checked where possible. Regional/cosmetic forms show as their base "
           "species. Off-roster Pokémon are routed to your PC.", "",
           "**%d characters.** Sprite version: `ROSTERS_SPRITES.md`." % len(chars), "",
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
            out.append(", ".join(n for n, _ in c["finals"]))
            out.append("")
    with open(os.path.join(TARGET, "ROSTERS.md"), "w", encoding="utf-8") as f:
        f.write("\n".join(out).rstrip() + "\n")

    # ---- ROSTERS_SPRITES.md + sprites/gen_N.md -----------------------------
    idx = ["# Character Mode — Roster Sprites (Pokémon ROWE)", "",
           "Each character's **final-evolution** roster, in **National Pokédex order**, "
           "with sprites and names. Split by generation to keep pages fast. "
           "Regional/cosmetic forms show as base species. Sprites via "
           "[PokéAPI](https://github.com/PokeAPI/sprites). Text: `ROSTERS.md`.", "",
           "**%d characters.**" % len(chars), "",
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
            for name, num in c["finals"]:
                cell = ('<td align="center" width="80"><img width="56" src="%s">'
                        "<br><sub>%s</sub></td>" % (SPRITE_URL % num, name))
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
