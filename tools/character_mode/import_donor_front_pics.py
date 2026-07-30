#!/usr/bin/env python3
"""Import staged donor trainer front pics for Character Mode characters that have none.

ROWE already RENDERS a character's front pic: `src/trainer_card.c` draws
`GetAppearanceCharacter()->trainerFrontPic` on the trainer card whenever it is
not CHAR_ASSET_NONE. That surface has been live since the costume work. What is
missing is art -- most characters resolve to no TRAINER_PIC at all and fall back
to the default player portrait.

`import_sprites.py` filled 46 of them from donor *decomp trees* (pokefirered,
pokemonHnS, pokeemerald-platinum) checked out under a scratchpad path that no
longer exists, so it cannot be re-run. This script fills the rest from the 754
sprites staged in `sprites/donors/` -- the same art the four GBA binary hacks
inject -- which are already 64x64 indexed PNGs with 16-colour palettes, byte
format-identical to the decomp's own front pics. No conversion, only wiring.

It is additive and idempotent:
  - a character that already resolves to an existing TRAINER_PIC *from another
    source* is skipped, so the 46 imports above (and every vanilla pic) are
    left alone
  - all generated C lives in `donor-*` marker blocks, a separate namespace from
    import_sprites.py's, so the two tools never fight over the same text
  - re-running replaces those blocks in place, re-emitting EVERY character this
    script has ever imported and holding each one's TRAINER_PIC id fixed

⚠️ THAT LAST POINT IS LOAD-BEARING AND WAS ONCE FALSE. Because the blocks are
rewritten wholesale, anything missing from this run's `picks` is deleted, not
preserved. Until 2026-07-29 the "already has a pic" test counted this script's
own previous output, so the first run that actually had new art to import
emitted a block of only the new picks and wiped the other 99. See `mine()`.

Emits, per character (conventions copied exactly from import_sprites.py):
    graphics/trainers/front_pics/<snake>.png     the art
    graphics/trainers/palettes/<snake>.pal       JASC palette (-> .gbapal)
    include/constants/trainers.h                 #define TRAINER_PIC_<KEY>
    include/graphics.h                           externs
    src/data/graphics/trainers.h                 INCBINs
    src/data/trainer_graphics/front_pic_tables.h coords + sprite + palette rows

The constants are named exactly what `emit_characters.py`'s `const_candidates()`
already looks for (`TRAINER_PIC_<DISPLAYNAME>`), so that script picks the new
art up with no change at all. Run this, then re-run emit_characters.py, then
make.

⚠️ `gTrainerFrontPicCoords` needs a row for every pic or the sprite draws 32 px
too low (this repo's CLAUDE.md records that one the hard way), so a coords row
is emitted for each.

⚠️ TRAINER_PIC ids already exceed 255 in this repo, and `struct Trainer.trainerPic`
is a u8 -- so these ids are usable ONLY by Character Mode, whose
`trainerFrontPic` is a u16 and whose consumer
(`CreateTrainerCardTrainerPicSprite`) takes a u16. Never assign one to a real
trainer.

Usage:  python3 tools/character_mode/import_donor_front_pics.py [--dry-run]
"""
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from PIL import Image
from import_sprites import (TARGET, MS, ME, camel, snake, read, write,
                            png_to_jasc, normalize_indexed)
from emit_characters import const_candidates

HERE = os.path.dirname(os.path.abspath(__file__))
DONORS = os.path.join(TARGET, "sprites", "donors")

# Best source first. Same order the four GBA repos' emit_sprite_table.py uses,
# and for the same reasons: `ashgray` is anime-specific art available nowhere
# else, `rogue` is the largest coherent set with one consistent style, `taar`
# has recoverable per-author attribution, and `platinum` has no per-sprite
# credit at all so it is the last resort.
PREFERENCE = ["ashgray", "rogue", "taar", "hns", "pokesho", "loulilie", "platinum"]

# Characters whose staged art is filed under a different stem. Kept identical
# to the sibling repos so a fix in one place is a fix everywhere.
ALIAS = {
    "Gary": "gary", "Ash": "ash", "Jessie": "jessie", "James": "jessie_james",
    "Lt. Surge": "lt_surge", "Crasher Wake": "crasher_wake",
    "Oak": "oak", "Samson Oak": None,
}

slug = lambda s: re.sub(r"[^a-z0-9]+", "_", s.lower()).strip("_")


def to_indexed(img, who):
    """Return a P-mode image, converting only when the source is truecolour.

    98 of the 99 staged sources are already 64x64 P-mode with a 16-colour
    palette -- byte format-identical to the decomp's own front pics. Exactly
    one (`rogue/lysandre_front.png`) ships as RGBA. Converting it is lossless
    (15 distinct colours, fully opaque), but the count is ASSERTED rather than
    quantised: silently dropping colours to fit 4bpp would corrupt art in a way
    that looks plausible and would only be caught by eye, which is exactly the
    failure mode this project keeps re-learning.
    """
    if img.mode == "P":
        return normalize_indexed(img)
    rgba = img.convert("RGBA")
    cols = rgba.getcolors(maxcolors=1 << 20) or []
    opaque = {c[1][:3] for c in cols if c[1][3] != 0}
    assert len(opaque) <= 16, (
        "%s: %d colours, will not fit 4bpp -- quantise it deliberately, do not "
        "let this script guess" % (who, len(opaque)))
    return normalize_indexed(rgba.convert("P", palette=Image.ADAPTIVE, colors=16))


def display_names():
    """Character display names, in characters.txt order."""
    out = []
    with open(os.path.join(HERE, "characters.txt")) as f:
        for line in f:
            line = line.strip()
            if line and not line.startswith("#"):
                out.append(line.split("|")[0].strip())
    return out


def candidates(disp):
    """Every staged front pic for this character, best source first.

    Matching is `<stem>_front*`, so Ash Gray's anime-styled alternates
    (`brock_anime_front.png`) cannot shadow the game-art version of the same
    character -- which is what we want, since those characters already have a
    pic and are skipped before this is reached.
    """
    base = disp[:-len(" (anime)")] if disp.endswith(" (anime)") else disp
    stems = [slug(base)]
    a = ALIAS.get(base, "")
    if a:
        stems.append(a)
    elif a is None:
        return []
    out = []
    for src in PREFERENCE:
        d = os.path.join(DONORS, src)
        if not os.path.isdir(d):
            continue
        for stem in stems:
            for f in sorted(os.listdir(d)):
                if f.startswith(stem + "_front") and f.endswith(".png"):
                    out.append((src, os.path.join(d, f)))
    return out


def mine(trainers_h):
    """`{KEY: id}` for the pics THIS script emitted on a previous run.

    ⚠️ THE REASON THIS FUNCTION EXISTS -- it is the whole idempotency story,
    and the docstring above used to claim idempotency this script did not have.

    Every block is REWRITTEN WHOLESALE on each run: `_block()` deletes the old
    marker block and writes a new one built from `picks`. So a character absent
    from `picks` is not "left alone", it is DELETED. And the old `have` test
    treated this script's OWN previous output as somebody else's art and skipped
    those characters -- so the second run with real work to do emitted a block
    containing only the NEW picks and silently dropped every earlier one.

    That is not a hypothetical. Run on 2026-07-29 with 9 newly staged sprites,
    it took `include/constants/trainers.h` from 287 TRAINER_PIC defines to 197:
    99 previously imported pics destroyed, 9 added. It survived since `ca2657fa`
    only because every re-run until then found 0 to import and returned at the
    `if not picks` early-out before touching a file -- the bug was unreachable
    in exactly the case anyone ever tested.

    So: previously-imported characters are re-picked from staged art every run,
    and their ids are held FIXED, so the emitted block is a superset and re-runs
    are genuinely idempotent.
    """
    m = re.search(re.escape(MS.format(tag="donor-pic-ids")) + r"(.*?)"
                  + re.escape(ME.format(tag="donor-pic-ids")), trainers_h, re.S)
    if not m:
        return {}
    return {k: int(v) for k, v in
            re.findall(r"#define TRAINER_PIC_(\w+)\s+(\d+)", m.group(1))}


def main():
    dry = "--dry-run" in sys.argv
    trainers_h_path = os.path.join(TARGET, "include/constants/trainers.h")
    trainers_h = read(trainers_h_path)
    have = set(re.findall(r"#define (TRAINER_PIC_\w+)", trainers_h))
    ours = mine(trainers_h)
    # Our own defines are not "somebody already covered this character".
    have -= {"TRAINER_PIC_" + k for k in ours}

    picks, skipped, missing, lost = [], [], [], []
    for disp in display_names():
        key = re.sub(r"[^A-Za-z0-9]+", "_",
                     disp[:-len(" (anime)")] if disp.endswith(" (anime)") else disp
                     ).strip("_").upper()
        if any(c in have for c in const_candidates(disp, "TRAINER_PIC_")):
            skipped.append(disp)
            continue
        cands = candidates(disp)
        if not cands:
            # A character WE imported before must still resolve, or this run
            # would quietly delete art that is live in the ROM.
            if key in ours:
                lost.append(disp)
            else:
                missing.append(disp)
            continue
        src, path = cands[0]
        picks.append(dict(disp=disp, key=key, src=src, path=path,
                          snake="cm_donor_" + slug(disp)))

    if lost:
        sys.exit("REFUSING TO RUN -- %d character(s) imported by a previous run no "
                 "longer resolve to any staged donor art: %s\n"
                 "Re-running now would DELETE their defines, INCBINs and table rows "
                 "while leaving the ROM referencing them. Restore the staged art (or "
                 "remove them from the donor-* blocks deliberately) first."
                 % (len(lost), ", ".join(lost)))

    fresh = [p for p in picks if p["key"] not in ours]
    print(f"{len(skipped)} characters have a front pic from another source (untouched)")
    print(f"{len(picks)} donor pics to emit ({len(fresh)} new, "
          f"{len(picks) - len(fresh)} re-emitted), {len(missing)} still have no staged art")
    by_src = {}
    for p in fresh:
        by_src[p["src"]] = by_src.get(p["src"], 0) + 1
    for s in PREFERENCE:
        if by_src.get(s):
            print(f"   new from {s:<12} {by_src[s]}")
    if missing:
        print(f"  no art: {', '.join(missing[:14])}" + (" ..." if len(missing) > 14 else ""))
    if dry:
        return 0
    if not picks:
        print("nothing to do")
        return 0

    # --- art files -------------------------------------------------------
    fp_dir = os.path.join(TARGET, "graphics/trainers/front_pics")
    pal_dir = os.path.join(TARGET, "graphics/trainers/palettes")
    for p in picks:
        img = to_indexed(Image.open(p["path"]), p["disp"])
        assert img.size == (64, 64), (p["disp"], img.size)
        img.save(os.path.join(fp_dir, p["snake"] + ".png"))
        png_to_jasc(img, os.path.join(pal_dir, p["snake"] + ".pal"))

    # --- TRAINER_PIC ids -------------------------------------------------
    # Continue above the current maximum. Ids are sparse and designated-
    # initialized, so gaps are free; what matters is never reusing one.
    # An id we issued before is HELD, so a re-run is a superset and not a
    # renumbering -- `characters.h` is regenerated from these, and letting them
    # shuffle would repoint every portrait on every run for no reason.
    maxpic = max(int(m) for m in re.findall(r"#define TRAINER_PIC_\w+\s+(\d+)", trainers_h))
    nxt = maxpic + 1
    for p in picks:
        if p["key"] in ours:
            p["id"] = ours[p["key"]]
        else:
            p["id"] = nxt
            nxt += 1
    ids_block = "\n".join("#define TRAINER_PIC_%s%s%d"
                          % (p["key"], " " * max(1, 24 - len(p["key"])), p["id"])
                          for p in picks)
    _block(trainers_h_path, "donor-pic-ids", ids_block,
           r"^// CHARMODE-SPRITES-START back-ids", before=True)

    # --- externs ---------------------------------------------------------
    externs = "".join(
        "extern const u32 gTrainerFrontPic_%s[];\n"
        "extern const u16 gTrainerPalette_%s[];\n"
        % (camel(p["key"]), camel(p["key"])) for p in picks)
    path = os.path.join(TARGET, "include/graphics.h")
    text = read(path)
    start, end = MS.format(tag="donor-externs"), ME.format(tag="donor-externs")
    text = re.sub(re.escape(start) + r".*?" + re.escape(end) + r"\n?", "", text, flags=re.S)
    pos = text.rfind("#endif")
    write(path, text[:pos] + "%s\n%s%s\n" % (start, externs, end) + text[pos:])

    # --- INCBINs ---------------------------------------------------------
    incbins = "".join(
        'const u32 gTrainerFrontPic_%s[] = INCBIN_U32("graphics/trainers/front_pics/%s.4bpp.lz");\n'
        'const u16 gTrainerPalette_%s[] = INCBIN_U16("graphics/trainers/palettes/%s.gbapal");\n'
        % (camel(p["key"]), p["snake"], camel(p["key"]), p["snake"]) for p in picks)
    _block(os.path.join(TARGET, "src/data/graphics/trainers.h"),
           "donor-front-incbins", incbins, r"\Z", before=True)

    # --- the three front-pic tables --------------------------------------
    # Each is a designated-initializer array, so rows may go anywhere inside
    # the braces; they are appended just before each closing `};`.
    path = os.path.join(TARGET, "src/data/trainer_graphics/front_pic_tables.h")
    coords = "".join("    [TRAINER_PIC_%s] = {.size = 8, .y_offset = 1},\n" % p["key"]
                     for p in picks)
    sprites = "".join("    TRAINER_SPRITE(%s, gTrainerFrontPic_%s, 0x800),\n"
                      % (p["key"], camel(p["key"])) for p in picks)
    pals = "".join("    TRAINER_PAL(%s, gTrainerPalette_%s),\n"
                   % (p["key"], camel(p["key"])) for p in picks)
    for tag, block, table in (("donor-front-coords", coords, "gTrainerFrontPicCoords"),
                              ("donor-front-sprites", sprites, "gTrainerFrontPicTable"),
                              ("donor-front-pals", pals, "gTrainerFrontPicPaletteTable")):
        text = read(path)
        s_, e_ = MS.format(tag=tag), ME.format(tag=tag)
        text = re.sub(re.escape(s_) + r".*?" + re.escape(e_) + r"\n?", "", text, flags=re.S)
        m = re.search(re.escape(table) + r"\[\]\s*=\s*\{", text)
        assert m, table
        close = text.index("\n};", m.end()) + 1
        write(path, text[:close] + "%s\n%s%s\n" % (s_, block, e_) + text[close:])

    manifest = "\n".join("%-28s %-10s %s" % (p["disp"], p["src"],
                                             os.path.basename(p["path"])) for p in picks)
    write(os.path.join(HERE, "donor_front_pics.txt"),
          "# Character front pics imported from sprites/donors/ by\n"
          "# tools/character_mode/import_donor_front_pics.py -- regenerate, do not edit.\n"
          + manifest + "\n")
    if fresh:
        print("imported %d NEW front pics (ids %s), re-emitted %d existing"
              % (len(fresh), ", ".join(str(p["id"]) for p in fresh),
                 len(picks) - len(fresh)))
    else:
        print("re-emitted %d front pics unchanged (no new staged art)" % len(picks))
    print("next: python3 tools/character_mode/emit_characters.py && make -j")
    return 0


def _block(path, tag, block, anchor_re, before=True):
    text = read(path)
    start, end = MS.format(tag=tag), ME.format(tag=tag)
    text = re.sub(re.escape(start) + r".*?" + re.escape(end) + r"\n?", "", text, flags=re.S)
    wrapped = "%s\n%s\n%s\n" % (start, block.rstrip("\n"), end)
    m = list(re.finditer(anchor_re, text, re.M))
    assert m, (path, anchor_re)
    pos = m[-1].start() if before else m[-1].end()
    if not before:
        wrapped = "\n" + wrapped
    write(path, text[:pos] + wrapped + text[pos:])


if __name__ == "__main__":
    sys.exit(main())
