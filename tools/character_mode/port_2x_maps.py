#!/usr/bin/env python3
"""Phase 4: import the ROWE 2.X Sevii Islands / Kanto maps from RoweRepo.

108 maps our tree lacks (Eight Island .. Sevii dungeons, Kanto gyms). Verified
safe up front:
  - the donor APPENDS them to the existing map groups, so no existing map's
    index shifts -> MAP_NUM/MAP_GROUP constants for current maps stay valid.
  - the new map scripts reference ZERO specials we lack (the plan's "~8 missing
    specials" turned out to be already implemented in our engine).
  - only 12 flags/vars are genuinely missing; they're added here.

Per map: the whole directory (map.json, scripts, header/events/connections),
its layout (registered in layouts.json), and any tileset it needs.

Idempotent: re-running skips what's already present. Reports everything it did.
"""
import json
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))
DONOR = os.environ.get("ROWEREPO_DONOR", "/home/jbfish00/Documents/RoweRepo-donor")

# Flags/vars the new maps need. Sevii progress flags go in the unused block we
# still have; the rest mirror the donor's own names.
NEW_FLAGS = [
    "FLAG_VISITED_FIVE_ISLAND",
    "FLAG_VISITED_SIX_ISLAND",
    "FLAG_VISITED_SEVEN_ISLAND",
    "FLAG_VISITED_EIGHT_ISLAND",
    "FLAG_GOT_TOGEPI_EGG",
    "FLAG_NO_ROOM_FOR_TOGEPI_EGG",
    "FLAG_GOT_TM42_AT_MEMORIAL_PILLAR",
    "FLAG_NO_ROOM_FOR_TM42_AT_MEMORIAL_PILLAR",
    "FLAG_HIDE_RESORT_GORGEOUS_INSIDE_SELPHY",
    "FLAG_LEARNED_YES_NAH_CHANSEY",
    "FLAG_UNLOCKED_ROCKET_WAREHOUSE",
]
NEW_VARS = [
    "VAR_MAP_SCENE_FIVE_ISLAND_RESORT_GORGEOUS",
]


def read(p):
    with open(p, encoding="utf-8", errors="ignore") as f:
        return f.read()


def write(p, s):
    with open(p, "w", encoding="utf-8") as f:
        f.write(s)


def main():
    dry = "--dry-run" in sys.argv
    tgt = lambda *p: os.path.join(TARGET, *p)
    dn = lambda *p: os.path.join(DONOR, *p)

    ours = set(os.listdir(tgt("data", "maps")))
    theirs = set(os.listdir(dn("data", "maps")))
    new_maps = sorted(m for m in theirs - ours
                      if os.path.isdir(dn("data", "maps", m)))

    our_layouts = json.load(open(tgt("data", "layouts", "layouts.json")))
    our_layout_ids = {l["id"] for l in our_layouts["layouts"]}
    donor_layouts = json.load(open(dn("data", "layouts", "layouts.json")))
    donor_layout_by_id = {l["id"]: l for l in donor_layouts["layouts"]}

    # which layouts + tilesets do the new maps need?
    need_layouts, need_tilesets = set(), set()
    for m in new_maps:
        j = json.load(open(dn("data", "maps", m, "map.json")))
        need_layouts.add(j["layout"])
    new_layouts = sorted(need_layouts - our_layout_ids)
    for lid in new_layouts:
        l = donor_layout_by_id[lid]
        for k in ("primary_tileset", "secondary_tileset"):
            if l.get(k):
                need_tilesets.add(l[k])

    def tileset_dir(sym):
        # gTileset_Foo -> data/tilesets/{primary,secondary}/foo
        name = re.sub(r"^gTileset_", "", sym)
        snake = re.sub(r"(?<!^)(?=[A-Z])", "_", name).lower()
        for kind in ("primary", "secondary"):
            if os.path.isdir(dn("data", "tilesets", kind, snake)):
                return kind, snake
        return None, None

    new_tilesets = []
    for sym in sorted(need_tilesets):
        kind, snake = tileset_dir(sym)
        if kind and not os.path.isdir(tgt("data", "tilesets", kind, snake)):
            new_tilesets.append((kind, snake, sym))

    print("maps: %d new | layouts: %d new | tilesets: %d new"
          % (len(new_maps), len(new_layouts), len(new_tilesets)))
    if dry:
        for m in new_maps[:10]:
            print("   map", m)
        for k, s, sym in new_tilesets:
            print("   tileset %s/%s (%s)" % (k, s, sym))
        return

    # ---- 1. flags + vars
    path = tgt("include", "constants", "flags.h")
    text = read(path)
    added_f = []
    # NB: whitespace in flags.h is inconsistent -- match the whole line
    # Free flags come in two spellings: a raw id, or (DAILY_FLAGS_START + N).
    # Match both, whole-line, since the whitespace in flags.h is inconsistent.
    free = re.findall(
        r"(?m)^#define (FLAG_UNUSED_0x[0-9A-F]+)[ \t]+(\(?[^/\n]+?\)?)[ \t]*// Unused Flag$",
        text)
    for name in NEW_FLAGS:
        if re.search(r"#define %s\b" % name, text):
            continue
        if not free:
            print("!! out of free flags for", name)
            break
        old_name, val = free.pop(0)
        text = re.sub(r"(?m)^#define %s[ \t]+%s[ \t]*// Unused Flag$"
                      % (re.escape(old_name), re.escape(val)),
                      "#define %-38s %s // 2.X Sevii" % (name, val), text, count=1)
        added_f.append((name, val))
    write(path, text)

    path = tgt("include", "constants", "vars.h")
    text = read(path)
    added_v = []
    for name in NEW_VARS:
        if re.search(r"#define %s\b" % name, text):
            continue
        m = re.search(r"#define (VAR_UNUSED_0x[0-9A-F]+)\s+(0x[0-9A-F]+)", text)
        if not m:
            print("!! out of free vars for", name)
            break
        text = text.replace(m.group(0),
                            "#define %-38s %s // 2.X Sevii" % (name, m.group(2)))
        added_v.append((name, m.group(2)))
    write(path, text)
    print("added %d flags, %d vars" % (len(added_f), len(added_v)))

    # ---- 2. tilesets
    for kind, snake, sym in new_tilesets:
        src = dn("data", "tilesets", kind, snake)
        dst = tgt("data", "tilesets", kind, snake)
        shutil.copytree(src, dst)
        # gbagfx rejects LF-terminated JASC palettes (same trap as the sprites)
        for root, _d, files in os.walk(dst):
            for fn in files:
                if fn.endswith(".pal"):
                    fp = os.path.join(root, fn)
                    data = open(fp, "rb").read().replace(b"\r\n", b"\n")
                    open(fp, "wb").write(data.replace(b"\n", b"\r\n"))
        print("   + tileset %s/%s" % (kind, snake))
    # tileset headers/graphics registration
    if new_tilesets:
        for relpath in ("data/tilesets/headers.inc", "data/tilesets/graphics.inc",
                        "data/tilesets/metatiles.inc"):
            if not os.path.isfile(dn(relpath)) or not os.path.isfile(tgt(relpath)):
                continue
            ours_t = read(tgt(relpath))
            theirs_t = read(dn(relpath))
            add = []
            for kind, snake, sym in new_tilesets:
                # copy each tileset's block from the donor file
                for m in re.finditer(
                        r"(?m)^(\w*%s\w*::.*?)(?=^\w+::|\Z)" % re.escape(sym.replace("gTileset_", "")),
                        theirs_t, re.S):
                    if m.group(1) not in ours_t:
                        add.append(m.group(1))
            if add:
                write(tgt(relpath), ours_t.rstrip("\n") + "\n\n" + "\n".join(add))

    # ---- 3. layouts (dirs + layouts.json)
    for lid in new_layouts:
        l = donor_layout_by_id[lid]
        # The asset dir comes from blockdata_filepath, NOT "name" (which carries
        # a _Layout suffix): data/layouts/EightIsland/map.bin -> EightIsland
        rel = os.path.dirname(l["blockdata_filepath"])   # e.g. data/layouts/EightIsland
        src = dn(rel)
        dst = tgt(rel)
        if os.path.isdir(src) and not os.path.isdir(dst):
            shutil.copytree(src, dst)
        our_layouts["layouts"].append(l)
    json.dump(our_layouts, open(tgt("data", "layouts", "layouts.json"), "w"),
              indent=2)
    print("registered %d layouts" % len(new_layouts))

    # ---- 4. map dirs
    for m in new_maps:
        src = dn("data", "maps", m)
        dst = tgt("data", "maps", m)
        if not os.path.isdir(dst):
            shutil.copytree(src, dst)
    print("copied %d map dirs" % len(new_maps))

    # ---- 5. map_groups.json -- append only, so existing indices never move
    ours_g = json.load(open(tgt("data", "maps", "map_groups.json")))
    theirs_g = json.load(open(dn("data", "maps", "map_groups.json")))
    added = 0
    for g in ours_g["group_order"]:
        for name in theirs_g.get(g, []):
            if name in new_maps and name not in ours_g[g]:
                ours_g[g].append(name)
                added += 1
    json.dump(ours_g, open(tgt("data", "maps", "map_groups.json"), "w"), indent=2)
    print("registered %d maps into groups (appended; no index shifts)" % added)

    with open(os.path.join(HERE, "rowe_map_port_report.txt"), "w") as f:
        f.write("Imported %d maps, %d layouts, %d tilesets\n"
                % (len(new_maps), len(new_layouts), len(new_tilesets)))
        f.write("\nFlags added:\n")
        for n, v in added_f:
            f.write("  %-42s %s\n" % (n, v))
        f.write("\nVars added:\n")
        for n, v in added_v:
            f.write("  %-42s %s\n" % (n, v))
        f.write("\nMaps:\n")
        for m in new_maps:
            f.write("  %s\n" % m)
    print("-> run make")


if __name__ == "__main__":
    main()
