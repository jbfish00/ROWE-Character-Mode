#!/usr/bin/env python3
"""Guards the hand-maintained QoL item ids against the generated item block.

include/constants/items.h is mostly OWNED by tools/character_mode/port_2x_items.py,
which rewrites everything between its ROWEITEM-PORT markers. The Character Mode
QoL items deliberately sit AFTER the end marker so a regeneration cannot erase
them -- but their ids are literals, so if the porter ever grows into that range
the two would collide silently and every save holding the QoL item would read a
different item back.

This is the gate that turns that from a silent collision into a build failure.

    python3 tools/check_qol_items.py
    python3 tools/check_qol_items.py --self-test   # its own negative control
"""
import os, re, sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONSTS = os.path.join(ROOT, "include/constants/items.h")
ENTRIES = os.path.join(ROOT, "src/data/items.h")
ICONS = os.path.join(ROOT, "src/data/item_icon_table.h")

# Every hand-maintained item, in id order. Add here when adding one.
QOL_ITEMS = ["ITEM_ZEROMIN"]

END_MARKER = "// ROWEITEM-PORT-END consts"


def read(p):
    with open(p, encoding="utf-8") as f:
        return f.read()


def check(text_consts=None):
    consts = text_consts if text_consts is not None else read(CONSTS)
    problems = []

    if END_MARKER not in consts:
        return ["include/constants/items.h has no %r marker" % END_MARKER]
    generated, hand = consts.split(END_MARKER, 1)

    # The porter's highest numeric id, taken from the generated half ONLY.
    gen_ids = [int(m) for m in re.findall(r"^#define ITEM_\S+\s+(\d+)\s*$",
                                          generated, re.M)]
    if not gen_ids:
        return ["found no generated item ids at all -- has the file moved?"]
    highest_generated = max(gen_ids)

    defines = dict((n, int(v)) for n, v in
                   re.findall(r"^#define (ITEM_\S+)\s+(\d+)\s*$", hand, re.M))

    expected = highest_generated + 1
    for name in QOL_ITEMS:
        if name not in defines:
            problems.append("%s is not defined after %r" % (name, END_MARKER))
            continue
        if name in generated:
            problems.append("%s appears in the GENERATED block -- the porter "
                            "will erase it on its next run" % name)
        if defines[name] != expected:
            problems.append(
                "%s is %d but should be %d (one past the porter's highest id, "
                "%d). The generated item table grew; move the QoL ids up and "
                "bump ITEMS_COUNT to match."
                % (name, defines[name], expected, highest_generated))
        expected += 1

    # ITEMS_COUNT must cover the hand-maintained ids, or gItems is short and
    # every lookup past the end reads whatever follows the array.
    counts = re.findall(r"^#define ITEMS_COUNT (\d+)\s*$", hand, re.M)
    if not counts:
        problems.append("ITEMS_COUNT is not restated after %r" % END_MARKER)
    else:
        want = max(defines.get(n, -1) for n in QOL_ITEMS) + 1
        if int(counts[-1]) != want:
            problems.append("ITEMS_COUNT is %s but should be %d (one past the "
                            "last QoL item)" % (counts[-1], want))
    return problems


def check_tables():
    problems = []
    entries, icons = read(ENTRIES), read(ICONS)
    for name in QOL_ITEMS:
        if "[%s] =" % name not in entries:
            problems.append("src/data/items.h has no gItems entry for %s" % name)
        if "[%s] =" % name not in icons:
            problems.append("src/data/item_icon_table.h has no icon for %s "
                            "-- the bag would draw whatever is at that index"
                            % name)
    return problems


def main():
    if "--self-test" in sys.argv:
        # Negative control: a tree where the porter has grown by one item must
        # be REJECTED. A checker that cannot fail is not a checker -- this repo
        # has shipped five assertions that could not.
        good = read(CONSTS)
        generated = good.split(END_MARKER, 1)[0]
        ids = [int(m) for m in re.findall(r"^#define ITEM_\S+\s+(\d+)\s*$",
                                          generated, re.M)]
        top = max(ids) if ids else None
        # Append one more GENERATED id, exactly as a porter run that added an
        # item would, and require the checker to notice the collision.
        broken = None
        if top is not None:
            m = re.search(r"^(#define ITEM_\S+\s+%d\s*)$" % top, generated, re.M)
            if m:
                broken = good.replace(
                    m.group(1),
                    m.group(1) + "\n#define ITEM_FAKE_NEW_PORTED_ITEM %d" % (top + 1),
                    1)
        if broken is None or broken == good:
            print("SELF-TEST INCONCLUSIVE: could not find the anchor to break")
            return 1
        problems = check(broken)
        if not problems:
            print("SELF-TEST FAILED: a colliding porter id was NOT rejected")
            return 1
        print("SELF-TEST PASSED: collision rejected -- %s" % problems[0])
        return 0

    problems = check() + check_tables()
    for p in problems:
        print("FAIL: %s" % p)
    if problems:
        return 1
    print("QoL item ids OK (%s)" % ", ".join(QOL_ITEMS))
    return 0


if __name__ == "__main__":
    sys.exit(main())
