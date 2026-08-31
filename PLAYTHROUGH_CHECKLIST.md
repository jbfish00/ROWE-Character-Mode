# ROWE playthrough checklist — the things only a human can see

**Build `c9cd47db5d1e0c31abed0d62dd7e3cfb` · branch `character-mode` · HEAD `6938cfc8`**
Written 2026-08-31. Keep this open next to the game.

---

## Read this first — most of the feature is already proven

**Do not re-verify the basics by hand.** 23 of the 33 rows in
`../Character Hacks/game_plans/rowe_playthrough_coverage.md` are proven by named
assertions that run every suite pass, and 6 more partly. Re-checking them by
hand costs hours and finds nothing.

**Specifically, you do NOT need to test:** the intro question appearing, the
character list scrolling and committing, the mode locking into the save, the
starter grant, on-roster catches, off-roster catches being refused, gift routing
in both directions, the in-game trade gate, the 10% roster override, the 1%
legendary roll, the encounter markers naming your character, mode exclusion with
Randomized Party, save/reload persistence, or the party menu's action rows.

If one of those *does* misbehave, that is a big deal — a suite assertion is
wrong — so note it precisely rather than working around it.

**What is left for you is below.** Four features shipped whose *logic* is
asserted and whose *pixels* nobody has ever seen, plus the handful of rows that
were always going to need a person.

---

## A. The four features nobody has actually looked at

These are new (2026-08-26 and 2026-08-31) and are the real reason to keep this
file open. Each says what "working" looks like, and what a genuine bug looks
like as opposed to a thing that is meant to be that way.

### ☐ A1 — Battle messages are faster, and print *during* the animation

**When:** the first time anything raises or lowers a stat. Growl, Tail Whip,
Swords Dance — within the first few battles.

**Should look like:** the message appears *as* the stat arrow animation plays,
not after it, and the pause afterwards is about half what it used to be
(32 frames instead of 64).

**A real bug:** the message not appearing at all; the message appearing twice;
the battle hanging at a stat change; text overlapping the animation illegibly.

> ⚠️ Verified only by decoding the ROM's own battle-script bytes. Nobody has
> watched it happen.

### ☐ A2 — Fishing sometimes pulls up an item

**When:** any water tile, any rod. Roughly **1 bite in 10** gives an item
instead of a Pokémon. Ten or fifteen casts should show one or two.

**Should look like:** the rod animation reels in, and you get
`<name> fished up a <item>!` instead of a battle. Old Rod → Pearl / Stardust /
Heart Scale; Good Rod → Big Pearl / Stardust / Heart Scale; Super Rod →
Big Pearl / Star Piece / Nugget.

**A real bug:** the item message appearing but the item not being in the bag;
the game hanging after the message; fishing *never* producing a Pokémon again;
the message appearing on a "not even a nibble".

> ✅ The 10% rate is measured (204/2000), the per-rod tables are read out of the
> ROM, and the bag genuinely grows. **What was never driven is the fishing
> minigame's own state machine** — i.e. exactly the part you are looking at.
> If the bag is full it should quietly give you a Pokémon instead.

### ☐ A3 — A shiny wild Pokémon turns the battle frame gold

**When:** whenever you meet a shiny. Rare, so this may not happen at all — do
not hunt for it.

**Should look like:** the battle textbox/frame tinted gold, from the moment the
battle draws.

**A real bug — and this is the one to watch for:** the gold tint appearing
anywhere it should not. In particular **on the EVOLUTION screen**, or in a
trainer battle, or against a non-shiny wild Pokémon.

> 🔴 That exact bug existed and was fixed on 2026-08-31: the evolution screen
> shares the battle-frame loader, and a zeroed party slot reads as shiny, so
> evolving by stone before your first wild battle tinted it every time. It is
> fixed and has a regression test — but it is the freshest fix in the build, so
> **if you see gold anywhere outside a wild battle, that is a real bug.**

### ☐ A4 — A gift "egg" gives a Pokémon from your character's roster

**When:** the **Five Island Water Labyrinth** gift (the Togepi one). This is one
of only two places in the whole game it fires, so it is easy to miss.

**Should look like:** you are given a Pokémon — *not* an egg — drawn from your
character's own roster, at level 1, in its base stage, with a message naming
what you got and whose roster it came from. Rarer species are likelier.

**Not a bug, by design:** it arrives as an ordinary Pokémon rather than an egg
(eggs are deliberately disabled in ROWE); the daycare is exempt and still breeds
normally; the Mystery Gift Pichu gives a roster species but shows no
announcement.

---

## B. The rows that always needed a person

### ☐ B1 — Your character's overworld sprite looks right
Walk in all four directions, surf, ride the bike, go indoors. Also check the
trainer card portrait.

### ☐ B2 — Reach the credits with Character Mode active
The only row nothing else can close.

### ☐ B3 — Play someone who is **not Red**
Red is the default, and every automated run uses him — so the automated coverage
is built on him too. Picking anyone else is genuinely new information.
⭐ Worth picking someone with a *small* early roster, since that is where the
feature is under most strain.

### ☐ B4 — Character-specific set pieces
Only Falkner-as-Falkner is proven (his own gym, badge chain, gate still
discriminating). If you play a leader or Elite Four member, their own set piece
is new ground. A static check confirms no gym or E4 script reads Character Mode
state, so nothing *should* branch — but that is an argument, not a run.

### ☐ B5 — Hatching an egg from the daycare
The daycare is exempt from the roster gate, so it breeds normally — but an
off-roster **hatchling** is swept to the PC *after* hatching. That is intended.
No automated test covers the hatch.

---

## C. Things that are deliberate — do not report these

- **No portrait on the character-selection screen.** There is no room in the
  tilemap; measured three times. Not a bug.
- **Some characters are missing from the list.** 31 of 237 are hidden because
  fewer than 6 of their Pokémon are obtainable in this game.
- **Gift "eggs" are not eggs.** See A4.
- **Music restarts after a battle** rather than resuming. Deliberately not
  built — the fix would need track pointers restored into the live sound driver,
  which nothing headless can safely verify.
- **`ENCOUNTERS.md` lists fewer species than `ROSTERS.md`.** Different questions:
  what you can *meet in the wild* vs what you are *allowed to own*.

---

## D. If something goes wrong

Note **what you did, what you saw, and where** — map name, character, party.
Then, if you can:

- `git rev-parse HEAD` and the ROM md5, so it is clear which build it was.
- Save in place and keep a copy of the `.sav`. A save that reproduces a bug is
  worth more than any description of it.

⚠️ **Existing saves are safe with this build** — no save-format or character-index
change; Iscan was appended, not inserted. If you are mid-run as Calaba, Ingo,
Kamado or Mai your roster got slightly *larger*, which is intended.

---

## E. Fastest route through this list

1. Start a new game, pick **someone other than Red** (B3).
2. First few battles → watch a stat change (**A1**).
3. First water tile with a rod → cast 10–15 times (**A2**).
4. Walk around, surf, check the trainer card (**B1**).
5. Play. Watch for gold anywhere it should not be (**A3**).
6. If you pass Five Island, take the Water Labyrinth gift (**A4**).
7. Keep going to the credits (**B2**).

Everything else on this page is either already proven or deliberate.
