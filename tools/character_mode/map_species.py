#!/usr/bin/env python3
"""Map scraped roster names to ROWE SPECIES_* constants.

Reads rosters_raw.json, resolves each display name to a SPECIES_* constant
(parsing src/data/text/species_names.h for the authoritative name->constant
mapping, which includes the ported Gen 9 block), canonicalizes every species
to its extended-family base (form-table collapse + evolution walk to a
fixpoint, mirroring the runtime CharacterMode_FamilyBase), dedupes, and
writes:
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
    """SPECIES_X -> base-stage SPECIES_Y, walking gEvolutionTable backwards.

    Mirrors the runtime GetFirstEvolution() (src/level_scaling.c) so offline
    normalization always agrees with the in-game roster check."""
    text = read(os.path.join(TARGET, "src/data/pokemon/evolution.h"))
    m = re.search(r"gEvolutionTable\[NUM_SPECIES\]\[EVOS_PER_MON\]\s*=\s*\{(.*?)^\};",
                  text, re.S | re.M)
    body = m.group(1)
    rows = [(r.start(), r.group(1))
            for r in re.finditer(r"\[(SPECIES_\w+)\]\s*=", body)]
    parent = {}
    for t in re.finditer(r"\{\s*EVO_\w+\s*,[^,{}]+,\s*(SPECIES_\w+)", body):
        src = None
        for pos, name in rows:
            if pos < t.start():
                src = name
            else:
                break
        if src and src != t.group(1):
            parent.setdefault(t.group(1), src)

    base = {}
    def find_base(c):
        seen = set()
        while c in parent and c not in seen:
            seen.add(c)
            c = parent[c]
        return c
    for child in list(parent):
        base[child] = find_base(child)
    return base


def base_form_map():
    """form-table member -> the table's slot-0 species. Mirrors the runtime
    GetBaseFormSpeciesId() (gFormSpeciesIdTables[id][0])."""
    text = read(os.path.join(TARGET, "src/data/pokemon/form_species_table.h"))
    collapse = {}
    for m in re.finditer(r"static const u16 \w+\[\]\s*=\s*\{(.*?)\};", text, re.S):
        members = re.findall(r"(SPECIES_\w+)", m.group(1))
        for member in members[1:]:
            collapse.setdefault(member, members[0])
    return collapse


def make_canonical(evo_base, form_base):
    """Family canonicalizer: alternate form-collapse and evolution-walk to a
    fixpoint, mirroring the runtime CharacterMode_FamilyBase(). One step of
    each is not enough: forms and evolution interleave (Sirfetch'd devolves to
    Galarian Farfetch'd, a FORM of Farfetch'd; Clodsire devolves to Paldean
    Wooper, a form of Wooper)."""
    def canonical(c):
        for _ in range(8):
            prev = c
            c = form_base.get(c, c)
            c = evo_base.get(c, c)
            if c == prev:
                return c
        return c
    return canonical


# Bulbapedia name -> in-game display name divergences (10-char cap, forms).
NAME_FIXES = {
    "Nidoran♀": "Nidoran♀", "Nidoran♂": "Nidoran♂",
    "Mr. Mime": "Mr. Mime",
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
    "Mime Jr.": "Mime jr.",
    "Porygon-Z": "Porygon-z",
    "Blacephalon": "Blacefalon",
    "Type: Null": "Type: Null",
    "Fletchinder": "Flechinder",
    "Crabominable": "Crabminabl",
    "Corvisquire": "Corvisquir",
    "Corviknight": "Corviknigh",
    "Barraskewda": "Barraskewd",
    "Centiskorch": "Centiskorc",
    "Polteageist": "Polteageis",
    "Stonjourner": "Stonjourne",
}



# Known signature/ace Pokemon per character (any stage; resolved to the
# family's first stage below). Characters absent here get a random starter.
SIGNATURES = {
 "Red":"Pikachu","Leaf":"Eevee","Blue":"Pidgeot","Lance":"Dragonite",
 "Lorelei":"Lapras","Bruno":"Machamp","Agatha":"Gengar","Koga":"Weezing",
 "Brock":"Onix","Misty":"Starmie","Lt. Surge":"Pikachu","Erika":"Vileplume",
 "Sabrina":"Alakazam","Blaine":"Arcanine","Giovanni":"Rhydon","Ash":"Pikachu",
 "Gary":"Blastoise","Ritchie":"Pikachu","Tracey":"Scyther","Jessie":"Ekans",
 "James":"Weezing",
 "Ethan":"Cyndaquil","Kris":"Totodile","Lyra":"Chikorita","Silver":"Totodile",
 "Falkner":"Hoothoot","Bugsy":"Scyther","Whitney":"Miltank","Morty":"Gengar",
 "Chuck":"Poliwrath","Jasmine":"Steelix","Pryce":"Piloswine","Clair":"Kingdra",
 "Will":"Xatu","Karen":"Umbreon","Janine":"Ariados","Archer":"Houndoom",
 "Ariana":"Arbok",
 "Brendan":"Treecko","May":"Blaziken","Wally":"Gallade","Steven":"Metagross",
 "Wallace":"Milotic","Sidney":"Absol","Phoebe":"Dusclops","Glacia":"Walrein",
 "Drake":"Salamence","Roxanne":"Nosepass","Brawly":"Hariyama","Wattson":"Manectric",
 "Flannery":"Torkoal","Norman":"Slaking","Winona":"Altaria","Tate":"Solrock",
 "Liza":"Lunatone","Juan":"Kingdra","Maxie":"Camerupt","Archie":"Sharpedo",
 "Drew":"Roserade",
 "Lucas":"Turtwig","Dawn":"Piplup","Barry":"Empoleon","Cynthia":"Garchomp",
 "Aaron":"Drapion","Bertha":"Hippowdon","Flint":"Infernape","Lucian":"Bronzong",
 "Roark":"Rampardos","Gardenia":"Roserade","Maylene":"Lucario","Crasher Wake":"Floatzel",
 "Fantina":"Mismagius","Byron":"Bastiodon","Candice":"Froslass","Volkner":"Shinx",
 "Cyrus":"Weavile","Mars":"Purugly","Jupiter":"Skuntank","Saturn":"Toxicroak",
 "Paul":"Electivire","Zoey":"Glameow","Nando":"Roserade",
 "Hilbert":"Oshawott","Hilda":"Tepig","Rosa":"Snivy","Cheren":"Stoutland",
 "Bianca":"Emboar","N":"Zorua","Alder":"Volcarona","Iris":"Haxorus",
 "Cilan":"Pansage","Chili":"Pansear","Cress":"Panpour","Lenora":"Watchog",
 "Burgh":"Leavanny","Elesa":"Zebstrika","Clay":"Excadrill","Skyla":"Swanna",
 "Brycen":"Beartic","Drayden":"Haxorus","Roxie":"Whirlipede","Marlon":"Jellicent",
 "Shauntal":"Chandelure","Marshal":"Conkeldurr","Grimsley":"Bisharp","Caitlin":"Gothitelle",
 "Ghetsis":"Hydreigon","Colress":"Klinklang","Trip":"Serperior",
 "Serena":"Fennekin","Shauna":"Chespin","Diantha":"Gardevoir","Malva":"Talonflame",
 "Siebold":"Clawitzer","Wikstrom":"Aegislash","Drasna":"Noivern","Viola":"Vivillon",
 "Grant":"Tyrunt","Korrina":"Lucario","Ramos":"Gogoat","Clemont":"Heliolisk",
 "Valerie":"Sylveon","Olympia":"Meowstic","Wulfric":"Avalugg","Lysandre":"Gyarados",
 "Alain":"Charizard","Sawyer":"Sceptile",
 "Elio":"Popplio","Selene":"Rowlet","Kukui":"Incineroar","Hau":"Raichu",
 "Molayne":"Dugtrio","Kahili":"Toucannon","Acerola":"Palossand","Hala":"Crabominable",
 "Olivia":"Lycanroc","Nanu":"Persian","Hapu":"Mudsdale","Gladion":"Type: Null",
 "Guzma":"Golisopod","Plumeria":"Salazzle","Lusamine":"Bewear","Lillie (anime)":"Vulpix",
 "Kiawe (anime)":"Turtonator","Lana (anime)":"Popplio","Mallow (anime)":"Tsareena",
 "Sophocles":"Togedemaru",
 "Leon":"Charizard","Milo":"Eldegoss","Nessa":"Drednaw","Kabu":"Centiskorch",
 "Bea":"Machamp","Allister":"Gengar","Opal":"Alcremie","Gordie":"Coalossal",
 "Melony":"Lapras","Piers":"Obstagoon","Raihan":"Duraludon","Hop":"Dubwool",
 "Bede":"Hatterene","Marnie":"Morpeko","Rose":"Copperajah","Goh":"Cinderace",
 "Chloe":"Eevee",
 "Geeta":"Glimmora","Nemona":"Pawmot","Rika":"Clodsire","Poppy":"Tinkaton",
 "Hassel":"Baxcalibur","Katy":"Teddiursa","Brassius":"Sudowoodo","Iono":"Bellibolt",
 "Kofu":"Crabominable","Larry":"Staraptor","Ryme":"Toxtricity","Tulip":"Florges",
 "Grusha":"Cetitan","Arven":"Mabosstiff","Penny":"Sylveon",
}

# Signatures used as the EXACT species (not reduced to first stage):
# these characters' partner is famously the mid-stage itself.
SIGNATURES_EXACT = {"Red", "Lt. Surge", "Ash", "Ritchie"}

def load_additions():
    """roster_additions.json: an OVERLAY of extra species per character, merged
    into rosters_raw.json here at map time rather than baked into it.

    Kept separate so the provenance of each add stays visible and a future
    re-scrape (which produces a strictly smaller set than the curated raw file)
    cannot silently drop them. Missing file = no additions."""
    path = os.path.join(HERE, "roster_additions.json")
    if not os.path.isfile(path):
        return {}
    with open(path, encoding="utf-8") as f:
        return json.load(f).get("additions", {})



def load_removals():
    """roster_removals.json: species the 2026-07-25 adversarial audit found do
    not belong to that character.

    The scraper's section filter matches narrative headings ("Pokemon Journeys:
    The Series"), so rosters absorbed Pokemon merely mentioned in an episode --
    Professor Oak's lab Pokemon landed on Tracey, Red's Clefairy on all three
    Striaton brothers. Kept as an overlay so a re-scrape cannot undo it and each
    removal keeps its citation.

    THE FAMILY RULE (user, 2026-07-25): a full family is allowed whenever any
    single member is canon, both directions. The file is generated with that
    applied -- only species whose ENTIRE family was removed appear -- so plain
    subtraction is correct.
    """
    path = os.path.join(HERE, "roster_removals.json")
    if not os.path.isfile(path):
        return {}
    with open(path, encoding="utf-8") as f:
        return json.load(f).get("removals", {})


def main():
    with open(os.path.join(HERE, "rosters_raw.json"), encoding="utf-8") as f:
        raw = json.load(f)

    additions = load_additions()
    added = 0
    for disp, adds in additions.items():
        if disp not in raw:
            print("ADDITION FOR UNKNOWN CHARACTER: %s" % disp)
            continue
        have = set(raw[disp]["species"])
        for a in adds:
            name = a["species"] if isinstance(a, dict) else a
            if name not in have:
                have.add(name)
                added += 1
        raw[disp]["species"] = sorted(have)
    if additions:
        print("overlay: %d species added across %d characters"
              % (added, len(additions)))

    removals = load_removals()
    dropped = 0
    for disp, rows in removals.items():
        if disp not in raw:
            continue
        gone = {r["species"] if isinstance(r, dict) else r for r in rows}
        have = set(raw[disp]["species"])
        raw[disp]["species"] = sorted(have - gone)
        dropped += len(have & gone)
    if removals:
        print("removals overlay: %d species dropped across %d characters"
              % (dropped, len(removals)))

    n2c = name_to_const()
    evo_base = first_stage_map()
    canonical = make_canonical(evo_base, base_form_map())
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
            consts.add(canonical(const))
        entry = {"page": info["page"], "category": info["category"],
                 "gen": info.get("gen", 0), "species": sorted(consts)}
        ace = SIGNATURES.get(disp)
        if ace:
            const = n2c.get(NAME_FIXES.get(ace, ace))
            if const is None:
                print("SIGNATURE UNRESOLVED: %s -> %s" % (disp, ace))
            else:
                # The starter keeps its regional form (Piers starts with
                # Galarian Zigzagoon): walk evolution only, don't collapse
                # forms. The catch gate canonicalizes forms at runtime, so a
                # form-species starter still passes it.
                sig_first_stage = evo_base.get(const, const)
                sig = const if disp in SIGNATURES_EXACT else sig_first_stage
                if canonical(const) in consts:
                    entry["signature"] = sig
                else:
                    print("SIGNATURE NOT ON ROSTER: %s -> %s (%s)"
                          % (disp, ace, canonical(const)))
        mapped[disp] = entry

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
