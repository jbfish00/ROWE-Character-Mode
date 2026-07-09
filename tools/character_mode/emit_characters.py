#!/usr/bin/env python3
"""Generate src/data/characters.h from rosters_mapped.json.

For each character, matches in-ROM art by naming convention:
  overworld sprite  OBJ_EVENT_GFX_<NAME>   (include/constants/event_objects.h)
  trainer front pic TRAINER_PIC_<NAME>     (include/constants/trainers.h)
  battle back pic   TRAINER_BACK_PIC_<NAME>
Characters without a match fall back to the default costume (CHAR_ASSET_NONE).

Order follows characters.txt. Characters with empty rosters are dropped.
Writes sprite_report.txt listing which assets each character got.
"""
import json
import os
import re

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))


def read(path):
    with open(path, encoding="utf-8") as f:
        return f.read()


# Legendary/mythical/Ultra Beast evolution-family bases: kept on rosters
# (catchable) but never offered as starters.
LEGENDARY_BASES = {"SPECIES_" + s for s in """ARTICUNO ZAPDOS MOLTRES MEWTWO MEW
RAIKOU ENTEI SUICUNE LUGIA HO_OH CELEBI
REGIROCK REGICE REGISTEEL LATIAS LATIOS KYOGRE GROUDON RAYQUAZA JIRACHI DEOXYS
UXIE MESPRIT AZELF DIALGA PALKIA HEATRAN REGIGIGAS GIRATINA CRESSELIA PHIONE MANAPHY DARKRAI SHAYMIN ARCEUS
VICTINI COBALION TERRAKION VIRIZION TORNADUS THUNDURUS RESHIRAM ZEKROM LANDORUS KYUREM KELDEO MELOETTA GENESECT
XERNEAS YVELTAL ZYGARDE DIANCIE HOOPA VOLCANION
TYPE_NULL TAPU_KOKO TAPU_LELE TAPU_BULU TAPU_FINI COSMOG NECROZMA MAGEARNA MARSHADOW ZERAORA MELTAN
NIHILEGO BUZZWOLE PHEROMOSA XURKITREE CELESTEELA KARTANA GUZZLORD POIPOLE STAKATAKA BLACEPHALON
ZACIAN ZAMAZENTA ETERNATUS KUBFU ZARUDE REGIELEKI REGIDRAGO GLASTRIER SPECTRIER CALYREX ENAMORUS
WO_CHIEN CHIEN_PAO TING_LU CHI_YU KORAIDON MIRAIDON OKIDOGI MUNKIDORI FEZANDIPITI OGERPON TERAPAGOS PECHARUNT""".split()}

# Manual asset overrides: display name -> dict of asset constants.
# (Auto-matching covers most; add entries here only when it picks wrong.)
ASSET_OVERRIDES = {}


def ident(disp):
    """C identifier from display name."""
    return re.sub(r"[^A-Za-z0-9]", "", disp.title())


def display_name(disp):
    """Menu display name; page-title suffixes never shown."""
    if disp.endswith(" (anime)"):
        return disp[:-len(" (anime)")]
    return disp


def const_candidates(disp, prefix):
    base = disp
    if base.endswith(" (anime)"):
        base = base[:-len(" (anime)")]
    key = re.sub(r"[^A-Za-z0-9]+", "_", base).strip("_").upper()
    if prefix == "OBJ_EVENT_GFX_":
        # player-grade sheet (_NORMAL) beats plain NPC sprite
        return [prefix + key + "_NORMAL", prefix + key]
    if prefix == "TRAINER_PIC_":
        return [prefix + key,
                prefix + "LEADER_" + key,
                prefix + "ELITE_FOUR_" + key,
                prefix + "MAGMA_LEADER_" + key,
                prefix + "AQUA_LEADER_" + key,
                prefix + "RS_" + key]
    return [prefix + key]


def main():
    with open(os.path.join(HERE, "rosters_mapped.json")) as f:
        mapped = json.load(f)

    obj_gfx = set(re.findall(r"#define (OBJ_EVENT_GFX_\w+)",
                             read(os.path.join(TARGET, "include/constants/event_objects.h"))))
    trainer_consts = read(os.path.join(TARGET, "include/constants/trainers.h"))
    front_pics = set(re.findall(r"#define (TRAINER_PIC_\w+)", trainer_consts))
    back_pics = set(re.findall(r"#define (TRAINER_BACK_PIC_\w+)", trainer_consts))

    order = []
    with open(os.path.join(HERE, "characters.txt")) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            disp = line.split("|")[0].strip()
            if disp in mapped:
                order.append(disp)

    rosters, table, report, skipped = [], [], [], []
    seen_cids = set()
    for disp in order:
        info = mapped[disp]
        if not info["species"]:
            skipped.append(disp)
            continue
        cid = ident(disp)
        if cid in seen_cids:
            raise SystemExit("duplicate character identifier: " + cid)
        seen_cids.add(cid)
        ov = ASSET_OVERRIDES.get(disp, {})

        ow = ov.get("ow")
        if ow is None:
            ow = next((c for c in const_candidates(disp, "OBJ_EVENT_GFX_")
                       if c in obj_gfx), None)
        front = ov.get("front")
        if front is None:
            front = next((c for c in const_candidates(disp, "TRAINER_PIC_")
                          if c in front_pics), None)
        back = ov.get("back")
        if back is None:
            back = next((c for c in const_candidates(disp, "TRAINER_BACK_PIC_")
                         if c in back_pics), None)

        if ow and ow not in obj_gfx:
            raise SystemExit("override OW gfx missing: " + ow)
        if front and front not in front_pics:
            raise SystemExit("override front pic missing: " + front)
        if back and back not in back_pics:
            raise SystemExit("override back pic missing: " + back)

        report.append("%-16s ow=%-34s front=%-26s back=%s"
                      % (disp, ow or "-", front or "-", back or "-"))

        starters = [s for s in info["species"] if s not in LEGENDARY_BASES]
        legends = [s for s in info["species"] if s in LEGENDARY_BASES]
        # Signature ace leads the starter block; a sub-legendary signature
        # (Gladion's Type: Null) is exempted from the legendary ban.
        sig = info.get("signature")
        if sig:
            if sig in starters:
                starters.remove(sig)
            elif sig in legends:
                legends.remove(sig)
            starters.insert(0, sig)
        ordered = starters + legends  # starter row cycles only the first block
        if not starters:
            report.append("%-16s WARNING: all-legendary roster, starters fall back to full roster" % disp)
        rosters.append("static const u16 sRoster_%s[] =\n{\n    %s,\n    SPECIES_NONE,\n};\n"
                       % (cid, ",\n    ".join(ordered)))
        rosters.append('static const u8 sName_%s[] = _("%s");\n' % (cid, display_name(disp)))
        table.append(
            "    {\n"
            "        .name = sName_%s,\n"
            "        .roster = sRoster_%s,\n"
            "        .owGfxId = %s,\n"
            "        .trainerFrontPic = %s,\n"
            "        .backPic = %s,\n"
            "        .generation = %d,\n"
            "        .starterCount = %d,\n"
            "        .hasSignature = %d,\n"
            "    },\n" % (cid, cid,
                          ow or "CHAR_ASSET_NONE",
                          front or "CHAR_ASSET_NONE",
                          back or "CHAR_ASSET_NONE_U8",
                          info.get("gen", 0) or 1,
                          len(starters),
                          1 if info.get("signature") else 0))

    out = ("// Character Mode roster/appearance table.\n"
           "// GENERATED by tools/character_mode/emit_characters.py - do not hand-edit.\n"
           "// Sources: Bulbapedia (rosters), in-ROM assets (sprites).\n\n"
           + "\n".join(rosters)
           + "\nconst struct CharacterInfo gCharacters[] =\n{\n"
           + "".join(table)
           + "};\n\n#define NUM_CHARACTERS (ARRAY_COUNT(gCharacters))\n")

    with open(os.path.join(TARGET, "src/data/characters.h"), "w") as f:
        f.write(out)
    with open(os.path.join(HERE, "sprite_report.txt"), "w") as f:
        f.write("\n".join(report) + "\n")
        if skipped:
            f.write("\nSkipped (empty roster): %s\n" % ", ".join(skipped))

    print("emitted %d characters (%d skipped empty) -> src/data/characters.h"
          % (len(table), len(skipped)))


if __name__ == "__main__":
    main()
