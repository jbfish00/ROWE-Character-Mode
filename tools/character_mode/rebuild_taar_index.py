#!/usr/bin/env python3
"""Rebuild the `harvest_index.json` the TAAR staging pass never wrote.

WHY THIS EXISTS. Team Aqua's Asset Repo is organised `<asset type>/<creator>/…`,
so the upstream PATH *is* the attribution, and TAAR's licence requires crediting
the original creator of each asset. The 2026-07-25 staging pass flattened the
filenames (`Overworld Trainer Sprites/Kasen/korrina.png` -> `korrina_ow.png`) and
`manifest.json` recorded only the flat name. `CREDITS_CHARACTER_MODE.md` claimed
a `harvest_index.json` in the staged directory "preserves each file's original
path" -- and that file did not exist. Six overworld sheets already in the ROM
(Korrina, Acerola, Nessa, Bede, Larry, Palmer) were therefore credited to
"TAAR contributors" collectively, which is weaker than the licence asks.

HOW IT RECOVERS THEM. The staged PNGs were copied, not converted, so every one
of them is byte-identical to its upstream file: match by content hash and the
path -- and therefore the author -- comes back exactly. This is not a guess and
not a filename heuristic.

⚠️ IT REFUSES TO WRITE A PARTIAL INDEX. A staged file with no upstream match
means either the wrong commit or an edited asset, and in both cases the author
is NOT recoverable by this method -- so emitting an index for the rest would
quietly assert provenance for files that have none. Any miss is a hard failure.

⚠️ ITS OWN CONTROL: `rowan_ow.png`'s author (spilledpizza) was known
independently, from the artist's own folder README, before this script existed.
It is asserted below, so a matcher that pairs files with the wrong upstream path
fails here rather than producing a plausible-looking index of wrong names.

Usage:
    git clone https://github.com/TeamAquasHideout/Team-Aquas-Asset-Repo /tmp/taar
    python3 tools/character_mode/rebuild_taar_index.py /tmp/taar
"""
import hashlib
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
TARGET = os.path.abspath(os.path.join(HERE, "..", ".."))

# The commit CREDITS_CHARACTER_MODE.md records for this donor set.
EXPECTED_COMMIT = "36b619ecd1d2df95212b375c95803af78414f78a"

DONORS = ["taar", "taar_gap"]

# Independently-known author, used as this script's negative control.
CONTROL = ("taar", "rowan_ow.png", "spilledpizza")


def author_from_path(path):
    """TAAR is `<asset type>/<creator>/…`, so the second element is the author.

    A few creators file their work under a nested project layout
    (`spilledpizza/graphics/object_events/…`); the creator is still element 2.
    """
    parts = path.replace("\\", "/").split("/")
    return parts[1] if len(parts) >= 2 else None


def index_upstream(root):
    """content hash -> sorted list of upstream paths."""
    index = {}
    for dirpath, dirnames, files in os.walk(root):
        dirnames[:] = [d for d in dirnames if d != ".git"]
        for f in files:
            if not f.lower().endswith(".png"):
                continue
            full = os.path.join(dirpath, f)
            try:
                with open(full, "rb") as fh:
                    h = hashlib.md5(fh.read()).hexdigest()
            except OSError:
                continue
            index.setdefault(h, []).append(os.path.relpath(full, root))
    for h in index:
        index[h].sort()
    return index


def main():
    if len(sys.argv) != 2:
        raise SystemExit(__doc__)
    upstream_root = sys.argv[1]

    head = os.path.join(upstream_root, ".git")
    if os.path.isdir(head):
        import subprocess
        got = subprocess.run(["git", "-C", upstream_root, "rev-parse", "HEAD"],
                             capture_output=True, text=True).stdout.strip()
        if got != EXPECTED_COMMIT:
            print("WARNING: clone is at %s, CREDITS records %s.\n"
                  "         Matching by content still works, but the paths "
                  "(and so the authors) are this commit's."
                  % (got or "?", EXPECTED_COMMIT))

    index = index_upstream(upstream_root)
    print("indexed %d distinct upstream PNG contents" % len(index))

    failures = []
    pending_writes = []
    for donor in DONORS:
        staged_dir = os.path.join(TARGET, "sprites/donors", donor)
        if not os.path.isdir(staged_dir):
            failures.append("missing staged directory: %s" % staged_dir)
            continue

        entries = {}
        authors = {}
        for name in sorted(os.listdir(staged_dir)):
            if not name.endswith(".png"):
                continue
            with open(os.path.join(staged_dir, name), "rb") as fh:
                h = hashlib.md5(fh.read()).hexdigest()
            paths = index.get(h)
            if not paths:
                failures.append("%s/%s has NO upstream match -- author not "
                                "recoverable by content" % (donor, name))
                continue
            author = author_from_path(paths[0])
            if not author:
                failures.append("%s/%s matched %r, which has no author element"
                                % (donor, name, paths[0]))
                continue
            entries[name] = {
                "upstream_path": paths[0],
                "author": author,
                "md5": h,
                # More than one upstream path can hold identical bytes (an
                # aggregate folder re-hosting a creator's file). Record them
                # all rather than silently picking one.
                "also_at": paths[1:],
            }
            authors.setdefault(author, []).append(name)

        out = {
            "_comment": (
                "Reconstructed by tools/character_mode/rebuild_taar_index.py. "
                "TAAR is organised <asset type>/<creator>/..., so upstream_path "
                "IS the attribution. Every entry is an EXACT content match "
                "against the upstream tree -- no filename heuristics."),
            "source": "https://github.com/TeamAquasHideout/Team-Aquas-Asset-Repo",
            "commit": EXPECTED_COMMIT,
            "files": entries,
        }
        # ⚠️ DO NOT WRITE YET. This script's own docstring promises it "refuses
        # to write a partial index", and it did exactly that: an unmatched PNG
        # was appended to `failures` and `continue`d, then the file was written
        # anyway from the incomplete dict, and only afterwards did the failure
        # get reported. A re-run against a TAAR clone at a different commit
        # therefore DELETED the attribution rows this script exists to preserve
        # -- and the control below re-reads the file it just wrote, so it
        # validated the damage. Queue the writes; commit them only if every
        # donor and the control came back clean.
        out_path = os.path.join(staged_dir, "harvest_index.json")
        pending_writes.append((out_path, out))
        print("\n%s: %d files, %d authors -> %s (pending)"
              % (donor, len(entries), len(authors),
                 os.path.relpath(out_path, TARGET)))
        for a in sorted(authors, key=lambda x: (-len(authors[x]), x.lower())):
            print("    %-32s %3d" % (a, len(authors[a])))

    # The control -- against what this run COMPUTED, not what is on disk.
    # Reading the file back only proved the previous run's contents (and, before
    # the pending-write change above, proved whatever this run had just
    # overwritten it with). Neither tests the attribution logic.
    donor, name, want = CONTROL
    path = os.path.join(TARGET, "sprites/donors", donor, "harvest_index.json")
    computed = None
    for out_path, out in pending_writes:
        if os.path.dirname(out_path) == os.path.dirname(path):
            computed = out["files"].get(name, {}).get("author")
            break
    if computed is None:
        failures.append("CONTROL FAILED: %s/%s was not resolved by this run at "
                        "all, so the attribution logic is unproven" % (donor, name))
    elif computed != want:
        failures.append("CONTROL FAILED: %s/%s resolved to %r, but its "
                        "author is independently known to be %r"
                        % (donor, name, computed, want))
    else:
        print("\ncontrol ok: %s/%s -> %s (independently known)"
              % (donor, name, computed))

    if failures:
        print("\nFAILED -- nothing written, the existing index files are "
              "untouched:")
        for f in failures:
            print("  " + f)
        return 1

    for out_path, out in pending_writes:
        with open(out_path, "w", encoding="utf-8") as fh:
            json.dump(out, fh, indent=2, sort_keys=True)
            fh.write("\n")
    print("\nwrote %d index file(s)" % len(pending_writes))
    return 0


if __name__ == "__main__":
    sys.exit(main())
