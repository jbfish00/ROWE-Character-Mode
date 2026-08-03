#!/usr/bin/env python3
"""Gate for the §7.14 encounter-marker strings: every line must fit the box.

The battle message window (B_WIN_MSG, gStandardBattleWindowTemplates in
src/battle_bg.c) is 26 tiles = 208 px wide and 2 lines tall, printed at x = 0
with letterSpacing 0 in FONT_NORMAL. A line wider than that is CLIPPED -- and
this is exactly the kind of thing nobody notices until a player with an unlucky
combination of names reports half a sentence.

Why a checker and not a screenshot: the marker strings interpolate a species
name (1023 of them) and a character name (236 of them), so the worst case is
one cell of a 241k-entry table and no amount of playing finds it. This measures
the WIDEST possible substitution with the game's own glyph widths.

Why you can trust the model: the same arithmetic was cross-checked against the
ROM's own GetStringWidth through CM_REQ_BATTLE_STRING_WIDTH on three real
battle strings and agreed to the pixel (146 / 119 / 131). Those three are
pinned below as a self-check, so if the font data or the charmap ever changes
under this script it fails here rather than silently measuring the wrong thing.

Usage:
    python3 tools/check_battle_strings.py
    python3 tools/check_battle_strings.py --self-test   # negative control
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.abspath(os.path.join(HERE, ".."))

# B_WIN_MSG: 26 tiles of 8 px.
LIMIT_PX = 26 * 8

# The strings under test, by their C identifier in src/battle_message.c.
MARKER_STRINGS = [
    "sText_CharacterWildPkmnAppeared",
    "sText_CharacterLegendaryAppeared",
]

# Every placeholder these strings may contain, mapped to the set of real values
# it can expand to. Anything else in a marker string is an error rather than a
# silent zero -- an unmeasured placeholder is how a string passes this check and
# still overflows.
PLACEHOLDER_SOURCES = {
    "B_OPPONENT_MON1_NAME": "species",
    "B_CHARACTER_NAME": "character",
}

# Cross-check against the ROM's own GetStringWidth (see the module docstring).
PINNED = [
    ("A wild Magikarp destined for", 146),
    ("Zapdos revealed itself", 119),
    ("Wild Poochyena appeared!", 131),
]

failures = []


def check(ok, msg):
    print("  %s  %s" % ("ok  " if ok else "FAIL", msg))
    if not ok:
        failures.append(msg)


# ---------------------------------------------------------------- font metrics

def load_widths():
    """gFont1LatinGlyphWidths, English branch of the #if in the .inc."""
    widths = []
    branch = None
    path = os.path.join(ROOT, "graphics/fonts/font1_latin_widths.inc")
    with open(path) as f:
        for line in f:
            s = line.strip()
            if s.startswith("#if"):
                branch = "es"
            elif s.startswith("#else"):
                branch = "en"
            elif s.startswith("#endif"):
                branch = None
            elif s.startswith(".byte") and branch != "es":
                widths.extend(int(v) for v in s[5:].split(","))
    if len(widths) < 256:
        raise SystemExit("check_battle_strings: parsed only %d glyph widths -- "
                         "the .inc format changed" % len(widths))
    return widths


def load_charmap():
    cmap = {}
    with open(os.path.join(ROOT, "charmap.txt"), encoding="utf-8") as f:
        for line in f:
            line = line.split("@")[0].rstrip("\n")
            m = re.match(r"^'(.)'\s+= ([0-9A-F]{2})\s*$", line)
            if m:
                cmap[m.group(1)] = int(m.group(2), 16)
    cmap.setdefault(" ", 0x00)
    if len(cmap) < 64:
        raise SystemExit("check_battle_strings: charmap.txt parsed to only %d "
                         "entries -- the format changed" % len(cmap))
    return cmap


WIDTHS = load_widths()
CHARMAP = load_charmap()


def width(text):
    """Pixel width of one line, the way GetStringWidth computes it."""
    total = 0
    for ch in text:
        b = CHARMAP.get(ch)
        if b is None:
            raise KeyError(ch)
        total += WIDTHS[b]
    return total


def safe_width(text):
    try:
        return width(text)
    except KeyError:
        return None


# ------------------------------------------------------------------- the data

def load_marker_strings():
    """identifier -> the string literal, taken from the ENGLISH block.

    battle_message.c defines both blocks with the same identifiers under
    `#if GAME_LANGUAGE == LANGUAGE_SPANISH` / `#else`, so a naive first-match
    grep reads the Spanish one. Take the LAST definition, which is the English
    block, and require both to exist -- a marker string added to only one block
    means one language silently keeps the unmarked text.
    """
    src = open(os.path.join(ROOT, "src/battle_message.c"), encoding="utf-8").read()
    out = {}
    for name in MARKER_STRINGS:
        hits = re.findall(r'%s\[\]\s*=\s*_\("((?:[^"\\]|\\.)*)"\)' % re.escape(name), src)
        if len(hits) != 2:
            raise SystemExit(
                "check_battle_strings: %s is defined %d time(s) in "
                "battle_message.c, expected 2 (one per GAME_LANGUAGE block). "
                "A marker string in only one block means one language keeps "
                "the unmarked text." % (name, len(hits)))
        out[name] = hits[-1]
    return out


def load_names(path, pattern):
    text = open(os.path.join(ROOT, path), encoding="utf-8").read()
    return sorted({n for n in re.findall(pattern, text) if n})


def widest(names, what):
    """The name with the greatest pixel width, skipping any the charmap cannot
    represent (those cannot be printed by this font at all)."""
    best, best_w = None, -1
    for n in names:
        w = safe_width(n)
        if w is not None and w > best_w:
            best, best_w = n, w
    if best is None:
        raise SystemExit("check_battle_strings: no measurable %s names" % what)
    return best, best_w


# ---------------------------------------------------------------------- checks

def main():
    self_test = "--self-test" in sys.argv

    print("Font/charmap model vs the ROM's own GetStringWidth:")
    for text, want in PINNED:
        got = safe_width(text)
        check(got == want, "%-30r %s px (ROM measured %d)" % (text, got, want))

    species = load_names("src/data/text/species_names.h", r'_\("([^"]*)"\)')
    characters = load_names("src/data/characters.h", r'_\("([^"]+)"\)')
    print("\n%d species names, %d character names" % (len(species), len(characters)))

    if self_test:
        # Negative control: a character name nobody could fit. If the check
        # below still passes with this in the pool, it is not measuring the
        # substitution at all.
        characters = characters + ["Wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"]
        print("SELF-TEST: injected an unfittable character name; "
              "the width checks below MUST fail.")

    worst_species, ws = widest(species, "species")
    worst_char, wc = widest(characters, "character")
    print("widest species name:   %-14r %3d px" % (worst_species, ws))
    print("widest character name: %-14r %3d px" % (worst_char, wc))

    print("\nMarker strings (limit %d px per line):" % LIMIT_PX)
    strings = load_marker_strings()
    for name, literal in strings.items():
        # \p and \l are page breaks, not glyphs -- GetStringWidth measures them
        # as zero (confirmed against the ROM). \n starts a new line.
        body = literal.replace("\\p", "").replace("\\l", "")
        lines = body.split("\\n")
        check(len(lines) <= 2,
              "%s uses at most 2 lines (B_WIN_MSG is 2 lines tall), got %d"
              % (name, len(lines)))

        seen_placeholders = set()
        for i, line in enumerate(lines):
            worst = line
            for ph, kind in PLACEHOLDER_SOURCES.items():
                token = "{%s}" % ph
                if token in worst:
                    seen_placeholders.add(ph)
                    worst = worst.replace(token, worst_species if kind == "species"
                                          else worst_char)
            leftover = re.search(r"\{([A-Z0-9_]+)\}", worst)
            check(leftover is None,
                  "%s line %d has no unmeasured placeholder%s"
                  % (name, i + 1, "" if leftover is None
                     else " (found {%s})" % leftover.group(1)))
            if leftover is not None:
                continue
            w = safe_width(worst)
            check(w is not None and w <= LIMIT_PX,
                  "%s line %d worst case %s px: %r"
                  % (name, i + 1, w, worst))

        # A marker that names no character is not a marker. The e2e run proves
        # the message is SELECTED; this proves the message still says the thing
        # the feature exists to say, which a reworded string could quietly lose.
        check("B_CHARACTER_NAME" in seen_placeholders,
              "%s names the character (that is the entire point of §7.14)" % name)
        check("B_OPPONENT_MON1_NAME" in seen_placeholders,
              "%s names the species" % name)

    print()
    if self_test:
        # The control passes when the checks FAIL. A negative control that
        # exits 0 either way proves nothing.
        if failures:
            print("SELF-TEST OK: %d check(s) failed as required." % len(failures))
            return 0
        print("SELF-TEST FAILED: an unfittable name did not trip any check -- "
              "this script is not measuring the substitution.")
        return 1

    if failures:
        print("FAILED %d check(s)" % len(failures))
        return 1
    print("All checks passed.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
