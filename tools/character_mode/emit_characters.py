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
ASSET_OVERRIDES = {
    "Tate": {"front": "TRAINER_PIC_LEADER_TATE_AND_LIZA"},
    "Liza": {"front": "TRAINER_PIC_LEADER_TATE_AND_LIZA"},
    # Gary is Blue (user: "Gary and Blue can be the same sprites exactly")
    "Gary": {"ow": "OBJ_EVENT_GFX_CM_BLUE", "front": "TRAINER_PIC_BLUE"},
}


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
        # imported player-safe sheet (CM_) or player-grade costume (_NORMAL)
        return [prefix + "CM_" + key, prefix + key + "_NORMAL", prefix + key]
    if prefix == "TRAINER_PIC_":
        # The FACILITY-TITLE prefixes are the Frontier Brains, and they are not
        # a hypothetical: Anabel, Brandon, Greta, Lucy, Noland, Spenser and
        # Tucker had their 64x64 front pics, palettes, INCBINs and
        # gTrainerFrontPicCoords rows sitting in this tree the whole time --
        # vanilla Emerald Battle Frontier art -- and were listed as "no art of
        # any kind" purely because this function never tried their titles.
        # Seven characters closed with zero new art (2026-07-29).
        # Each title matches exactly one character, so none can shadow another.
        return [prefix + key,
                prefix + "LEADER_" + key,
                prefix + "ELITE_FOUR_" + key,
                prefix + "CHAMPION_" + key,
                prefix + "MAGMA_LEADER_" + key,
                prefix + "AQUA_LEADER_" + key,
                prefix + "RS_" + key,
                prefix + "SALON_MAIDEN_" + key,
                prefix + "DOME_ACE_" + key,
                prefix + "PALACE_MAVEN_" + key,
                prefix + "ARENA_TYCOON_" + key,
                prefix + "FACTORY_HEAD_" + key,
                prefix + "PIKE_QUEEN_" + key,
                prefix + "PYRAMID_KING_" + key]
    if prefix == "TRAINER_BACK_PIC_":
        return [prefix + "CM_" + key, prefix + key]
    return [prefix + key]


def load_drops():
    """Characters present in the table but NOT offerable in this game.

    The 2026-07-25 roster audit drops a character from a game when fewer than
    six fully-evolved members of their roster exist in that game's dex (a
    legendary on the roster exempts them). Saves store the character INDEX, so
    the row has to stay where it is -- deleting it would repoint every existing
    save at a different character. `.selectable = 0` keeps the slot and takes
    the character out of the menu instead."""
    path = os.path.join(HERE, "character_drops.json")
    if not os.path.isfile(path):
        return set()
    with open(path, encoding="utf-8") as f:
        return set(json.load(f).get("unselectable", []))


# PLAN.md item #14 -- the empty-roster INVENTORY.
#
# Two characters used to emit nothing at all and say so only in a line at the
# bottom of sprite_report.txt that nobody read. Re-derived 2026-08-30:
#
#   Cogita -- LEGITIMATELY empty. Her entire roster is Enamorus, which this ROM
#             does not have: no gBaseStats row, no species_names.h row, only a
#             SPECIES_ENAMORUS #define and a national dex number. Nothing to
#             emit, and nothing to fix short of porting the species.
#   Iscan  -- WAS WRONGLY EMPTY, and is emitted again as of 2026-08-30. His
#             roster is Basculegion, which the ROM gained base stats and a name
#             for on 2026-08-09; rosters_mapped.json simply predated that. The
#             lesson is the general one: a DERIVED artifact that is older than
#             the data it derives from reports a stale answer confidently.
#
# This is the workspace's inventory pattern (see tools/check_egg_paths.py): a
# new silent skip must FAIL here rather than arrive unnoticed. If a character
# legitimately joins or leaves this set, edit it deliberately.
EMPTY_ROSTER_EXPECTED = {"Cogita"}


def main():
    drops = load_drops()
    with open(os.path.join(HERE, "rosters_mapped.json")) as f:
        mapped = json.load(f)

    # Only overworld sprites built as 18-frame PLAYER-GRADE sheets are safe to
    # use as the player avatar (they carry the full 24-entry player animation
    # table, whose walk/run anims reference frames 0-17). Assigning ROWE's
    # native NPC gfx ids (Steven, gym leaders, the Frontier Brains, ...) as the
    # player OW sprite reads past the end of a SHORT pic table and crashes - so
    # restrict owGfxId to the two importers' own allowlists.
    #   imported_ow.txt        import_sprites.py       (95 sheets, 2026-07)
    #   imported_ow_donor.txt  import_donor_ow_backs.py
    imported_ow = set()
    for fname in ("imported_ow.txt", "imported_ow_donor.txt"):
        imp_path = os.path.join(HERE, fname)
        if os.path.isfile(imp_path):
            imported_ow |= {t for t in read(imp_path).split()
                            if t.startswith("OBJ_EVENT_GFX_")}

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
            # Safe player OW sprites: our imports, or ROWE's own player-costume
            # sprites (the *_NORMAL ids: Red/Leaf/Brendan/May/Hilbert). Plain
            # NPC ids (Steven, gym leaders) use a short anim table and crash.
            ow = next((c for c in const_candidates(disp, "OBJ_EVENT_GFX_")
                       if c in obj_gfx
                       and (c in imported_ow or c.endswith("_NORMAL"))), None)
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
            "        .selectable = %d,\n"
            "    },\n" % (cid, cid,
                          ow or "CHAR_ASSET_NONE",
                          front or "CHAR_ASSET_NONE",
                          back or "CHAR_ASSET_NONE_U8",
                          info.get("gen", 0) or 1,
                          len(starters),
                          1 if info.get("signature") else 0,
                          0 if disp in drops else 1))

    out = ("// Character Mode roster/appearance table.\n"
           "// GENERATED by tools/character_mode/emit_characters.py - do not hand-edit.\n"
           "// Sources: Bulbapedia (rosters), in-ROM assets (sprites).\n\n"
           + "\n".join(rosters)
           + "\nconst struct CharacterInfo gCharacters[] =\n{\n"
           + "".join(table)
           + "};\n\n#define NUM_CHARACTERS (ARRAY_COUNT(gCharacters))\n")

    with open(os.path.join(TARGET, "src/data/characters.h"), "w") as f:
        f.write(out)
    # The inventory check, BEFORE anything is written: a character who silently
    # produces no roster is either a data bug (Iscan was, for three weeks) or a
    # deliberate exemption, and there is no third case.
    if set(skipped) != EMPTY_ROSTER_EXPECTED:
        raise SystemExit(
            "empty-roster inventory mismatch (PLAN.md item #14)\n"
            "  expected: %s\n"
            "  got:      %s\n"
            "A character emitting NO roster is a data bug until proven "
            "otherwise -- check whether the species exist in this ROM before "
            "adding a name to EMPTY_ROSTER_EXPECTED. ⚠️ And a character who "
            "GAINS a first roster must be moved to the END of characters.txt "
            "first: emitting them in place shifts every later table index, and "
            "saves store the character INDEX."
            % (sorted(EMPTY_ROSTER_EXPECTED), sorted(skipped)))

    with open(os.path.join(HERE, "sprite_report.txt"), "w") as f:
        f.write("\n".join(report) + "\n")
        if skipped:
            f.write("\nSkipped (empty roster): %s\n" % ", ".join(skipped))

    print("emitted %d characters (%d skipped empty, %d not selectable) "
          "-> src/data/characters.h"
          % (len(table), len(skipped), sum(1 for d in order if d in drops)))


if __name__ == "__main__":
    main()
