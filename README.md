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

1. **Start a new game.** ⚠️ **"Continue" will not work** — see the warning below.
2. In the **intro question sequence** (the questions asked before you reach the
   truck), choose **Character Mode**.
3. **Scroll to your character** in the list and confirm.

⚠️⚠️ **THIS IS THE ONLY WAY IN.** Character Mode cannot be turned on after the
intro. The "Mode Menu" entry that would open it from the START menu exists in
the source but is **deliberately commented out**
(`src/start_menu.c`, `AddStartMenuAction(MENU_ACTION_UI_MODE_MENU)`), so a save
that was started without Character Mode has no way to enable it. Start a fresh
game to change or disable your choice.

**You will know it worked:** your character's starter, their portrait on the
trainer card, and your costume changes so you visibly appear as them.

206 characters are selectable. Character Mode and **Randomized Party Mode** are
mutually exclusive — picking one disables the other.

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

