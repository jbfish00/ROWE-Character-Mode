#!/usr/bin/env python3
"""Map scraped roster names to ROWE SPECIES_* constants.

Reads rosters_raw.json, resolves each display name to a SPECIES_* constant
(parsing src/data/text/species_names.h for the authoritative name->constant
mapping, which includes the ported Gen 9 block), normalizes every species to
its evolution-family base stage via src/data/pokemon/first_stage.h, dedupes,
and writes:
  - rosters_mapped.json   (character -> sorted base-stage SPECIES_* list)
  - roster_review.csv     (for the user to audit: one row per character/species)
  - unmatched_names.txt   (names that resolved to nothing, for fixing)
"""
import csv
import json
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))


def read(path):
    with open(path, encoding="utf-8") as f:
        return f.read()


def name_to_const():
    """Display name -> SPECIES_* from species_names.h (first occurrence wins:
    base species come before forms in the file)."""
    text = read(os.path.join(TARGET, "src/data/text/species_names.h"))
    mapping = {}
    for m in re.finditer(r'\[(SPECIES_\w+)\]\s*=\s*_\("([^"]+)"\)', text):
        const, name = m.group(1), m.group(2)
        if name not in mapping:
            mapping[name] = const
    return mapping


def first_stage_map():
    """SPECIES_X -> base-stage SPECIES_Y from gFirstEvolutionTable."""
    text = read(os.path.join(TARGET, "src/data/pokemon/first_stage.h"))
    base = {}
    for m in re.finditer(r"\[(SPECIES_\w+)\]\s*=\s*\{(SPECIES_\w+)", text):
        base[m.group(1)] = m.group(2)
    return base


# Bulbapedia name -> in-game display name divergences (10-char cap, forms).
NAME_FIXES = {
    "Nidoran♀": "Nidoran♀", "Nidoran♂": "Nidoran♂",
    "Mr. Mime": "Mr. Mime", "Mime Jr.": "Mime Jr.",
    "Farfetch'd": "Farfetch'd", "Sirfetch'd": "Sirfetch'd",
    "Meowscarada": "Meowscrada", "Oinkologne": "Oinkolgne",
    "Squawkabilly": "Squawkbily", "Kilowattrel": "Kilowattrl",
    "Brambleghast": "Brmbleghst", "Dudunsparce": "Dudnsparce",
    "Poltchageist": "Poltchagst", "Fezandipiti": "Fezandipti",
    "Scream Tail": "ScreamTail", "Brute Bonnet": "BruteBonet",
    "Flutter Mane": "FluttrMane", "Slither Wing": "SlithrWing",
    "Sandy Shocks": "SandyShock", "Iron Treads": "IronTreads",
    "Iron Bundle": "IronBundle", "Iron Jugulis": "IronJuglis",
    "Iron Thorns": "IronThorns", "Iron Valiant": "IrnValiant",
    "Roaring Moon": "RoarngMoon", "Walking Wake": "WalkngWake",
    "Iron Leaves": "IronLeaves", "Gouging Fire": "GougngFire",
    "Raging Bolt": "RagingBolt", "Iron Boulder": "IronBouldr",
    "Flabébé": "Flabébé",
}


def main():
    with open(os.path.join(HERE, "rosters_raw.json")) as f:
        raw = json.load(f)

    n2c = name_to_const()
    base = first_stage_map()
    unmatched = set()
    mapped = {}

    for disp, info in sorted(raw.items()):
        consts = set()
        for name in info["species"]:
            name = NAME_FIXES.get(name, name)
            const = n2c.get(name)
            if const is None:
                unmatched.add(name)
                continue
            consts.add(base.get(const, const))
        mapped[disp] = {"page": info["page"], "category": info["category"],
                        "species": sorted(consts)}

    with open(os.path.join(HERE, "rosters_mapped.json"), "w") as f:
        json.dump(mapped, f, indent=1, sort_keys=True)

    with open(os.path.join(HERE, "roster_review.csv"), "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["character", "category", "base_species", "keep(Y/n)"])
        for disp, info in sorted(mapped.items()):
            for c in info["species"]:
                w.writerow([disp, info["category"], c, "Y"])

    with open(os.path.join(HERE, "unmatched_names.txt"), "w") as f:
        f.write("\n".join(sorted(unmatched)) + "\n")

    empty = [d for d, i in mapped.items() if not i["species"]]
    print("mapped %d characters; %d unmatched names; %d empty rosters%s"
          % (len(mapped), len(unmatched), len(empty),
             (": " + ", ".join(empty)) if empty else ""))


if __name__ == "__main__":
    main()
