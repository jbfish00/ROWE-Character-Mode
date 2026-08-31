#!/usr/bin/env python3
"""The stat-change battle scripts print DURING the animation, in the built ROM.

PLAN.md item #13, the "faster battle messages" half of the SoulGold QoL group.

The premise is worth stating because it is easy to get backwards by reading the
script alone: `playanimation` is asynchronous, but `Cmd_printfromtable` opens
with `if (gBattleControllerExecFlags == 0)`, so with the animation first the
message does not print until the animation has finished. Putting the print
first is what actually overlaps them; the following `waitmessage` still waits on
the controller, so nothing is cut short.

⭐ THIS READS THE ROM, NOT THE SOURCE. Every other static checker here re-parses
the text that was compiled; this decodes the bytes the assembler emitted, at the
addresses the linker chose, which is the one form that cannot be satisfied by a
source file that did not make it into the build (Seaglass's CM_BuildFingerprint
lesson, ported to a script this time).

Exit non-zero on any mismatch.
"""
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(HERE)
ROM = os.path.join(ROOT, "pokeemerald.gba")
MAP = os.path.join(ROOT, "pokeemerald.map")

ROM_BASE = 0x08000000

# From the command table in src/battle_script_commands.c.
OP_WAITMESSAGE    = 0x12   # + u16 operand
OP_PRINTFROMTABLE = 0x13   # + u32 table pointer
OP_RETURN         = 0x3C
OP_PLAYANIMATION  = 0x45   # + battler, animId, u32 arg pointer

B_WAIT_TIME_SHORT = 32

# name -> the opcode sequence it must begin with, and why.
EXPECTED = {
    "BattleScript_StatUp": (
        [OP_PRINTFROMTABLE, OP_PLAYANIMATION, OP_WAITMESSAGE, OP_RETURN],
        "the message must be printed BEFORE the animation is queued, or "
        "Cmd_printfromtable blocks until the animation is over"),
    "BattleScript_StatDown": (
        [OP_PRINTFROMTABLE, OP_PLAYANIMATION, OP_WAITMESSAGE, OP_RETURN],
        "same reordering as StatUp"),
    "BattleScript_StatUpMsg": (
        [OP_PRINTFROMTABLE, OP_WAITMESSAGE, OP_RETURN],
        "the stat-STEALING entry point (battle_script_commands.c:7893) is "
        "message-only and must NOT gain an animation"),
}

SIZES = {
    OP_WAITMESSAGE: 3,
    OP_PRINTFROMTABLE: 5,
    OP_RETURN: 1,
    OP_PLAYANIMATION: 7,
}


def symbols():
    out = {}
    pat = re.compile(r"^\s+(0x[0-9a-f]{8})\s+(\w+)\s*$")
    for line in open(MAP, encoding="utf-8", errors="replace"):
        m = pat.match(line)
        if m and m.group(2) in EXPECTED:
            out.setdefault(m.group(2), int(m.group(1), 16))
    return out


def main():
    for path in (ROM, MAP):
        if not os.path.exists(path):
            print("FAIL: missing %s -- run make first" % path)
            return 1

    rom = open(ROM, "rb").read()
    syms = symbols()
    problems = []

    for name, (want, why) in EXPECTED.items():
        if name not in syms:
            problems.append("%s is not in pokeemerald.map" % name)
            continue
        off = syms[name] - ROM_BASE
        got = []
        cursor = off
        for _ in range(len(want)):
            op = rom[cursor]
            got.append(op)
            if op not in SIZES:
                break
            cursor += SIZES[op]
        if got != want:
            problems.append(
                "%s at %s decodes as %s, expected %s -- %s"
                % (name, hex(syms[name]),
                   " ".join("%02X" % o for o in got),
                   " ".join("%02X" % o for o in want), why))
            continue

        # The wait operand, read out of the ROM the same way.
        wpos = off
        for op in want:
            if op == OP_WAITMESSAGE:
                break
            wpos += SIZES[op]
        wait = rom[wpos + 1] | (rom[wpos + 2] << 8)
        if wait != B_WAIT_TIME_SHORT:
            problems.append("%s waits %d frames, expected B_WAIT_TIME_SHORT "
                            "(%d)" % (name, wait, B_WAIT_TIME_SHORT))
        else:
            print("  ok    %-24s %s, waits %d frames"
                  % (name, hex(syms[name]), wait))

    print()
    if problems:
        for p in problems:
            print("FAIL: " + p)
        return 1
    print("OK -- the stat-change scripts print during the animation, in the "
          "ROM that was actually built.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
