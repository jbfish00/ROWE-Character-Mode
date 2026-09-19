# Pokémon R.O.W.E — Character Mode fork

> This is a fork of [BelialClover/RoweSource](https://github.com/BelialClover/RoweSource)
> that adds **Character Mode**, on the `character-mode` branch (the default here).
> The `main` branch tracks upstream ROWE unchanged.

**Character Mode** is an opt-in mode where you play as one of 206 iconic Pokémon
characters (Gen 1–9) — protagonist, rival, gym leader, Elite Four, champion,
villain, professor, or anime cast — and are restricted to catching and keeping only that
character's canon roster (Bulbapedia-documented, expanded to full evolution
families). An off-roster ball is **refused** — "It refuses to join {PLAYER}'s
journey!" — and the Pokémon is never caught; off-roster *gifts* are routed to
your PC instead. On-roster species (and all their evolutions) join your party.
It also drives ROWE's costume system so you visibly appear as your chosen
character.

Activate it at the start of a new game: in the intro question sequence, choose
**Character Mode**, scroll to your character, and confirm. This is the original
reference implementation the other ports (Unbound, Lazarus, Radical Red,
Seaglass, Prism) were derived from. Because ROWE is a full `pokeemerald`
decompilation, you build the ROM yourself with `make` — see `INSTALL.md`.

## ▶️ How to turn Character Mode on

> **Character Mode is opt-in. Nothing in the game changes until you do this —
> and you can only do it when starting a new game.**

**There are two ways in — at any time, or during the intro.**

### A. The START menu, at any point in the game ← easiest

1. Press **START**, then choose **Mode Menu**.
2. Tick **Character Mode**, pick your character, and confirm.

Turning it on mid-game sweeps any off-roster Pokémon in your party into the PC
and grants your character's starter if nothing on their roster remains. You can
come back to the same menu to change character or switch the mode off.

### B. The new-game intro

In the **intro question sequence** (before you reach the truck), choose
**Character Mode**, scroll to your character, and confirm.

Character Mode and **Randomized Party Mode** are mutually exclusive — turning
one on clears the other.

**You will know it worked:** your character's starter, their portrait on the
trainer card, and your costume changes so you visibly appear as them.

206 characters are selectable.

⚠️ ROWE is a full `pokeemerald` decompilation, so you **build the ROM yourself**
with `make` — see [`INSTALL.md`](INSTALL.md). There is no patch to download.

---

---

# Pokémon R.O.W.E

This is a the source code for the game Pokemon R.O.W.E.
The current source builds the update 1.9.4 Source Edition

## Links
[R.O.W.E. Patcher](https://belialclover.github.io/Rowe-Patcher/)

[Game Link and Information](https://www.pokecommunity.com/threads/pokemon-r-o-w-e-an-open-world-version-of-pok%C3%A9mon-emerald-gen-8-following-pok%C3%A9mon-costumes-and-much-more.442592/)

[Discord Link Invite](https://discord.gg/dsfgNP4b9a)

[Install Guide (Windows)](https://www.pokecommunity.com/threads/tutorial-how-to-build-the-pokémon-gba-decomps-using-wsl-win10.432351/)

