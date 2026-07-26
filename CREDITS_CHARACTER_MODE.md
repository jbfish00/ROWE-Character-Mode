# Character Mode — Art Credits

Character Mode's playable-character sprites are adapted from the following
games, decompilation projects, and fan works. Huge thanks to every artist.
This mod is distributed as a patch only, never as a prebuilt ROM.

## Base game / engine
- **Pokémon R.O.W.E.** by rioluwott and contributors (pokeemerald base).
- **pret/pokeemerald** decompilation and **pokeemerald-expansion**
  (RHH) — engine, Gen 9 species data.

## Overworld & trainer sprites
- **pret/pokefirered** — FRLG overworld sprites and trainer fronts for
  Kanto characters (Lorelei, Agatha, and Gen I trainer portraits).
- **sinnoh-remakes/pokeemerald-platinum** — Gen IV (DPPt) overworld
  sheets and DP trainer fronts (Lucas, Dawn, Cynthia, gym leaders,
  Elite Four, Team Galactic).
- **PokemonHnS-Development/pokemonHnS** — HGSS-style overworld sheets and
  trainer fronts for Johto characters (Ethan, Kris, gym leaders, Elite
  Four, Team Rocket executives) and HGSS-style walking upgrades for the
  Kanto cast.
- **DiegoWT — "Gen 5 Characters in Gen 4 OW style"**
  (https://eeveeexpo.com/resources/370/) — Unova cast overworld sprites
  (Hilda, Nate, Rosa, gym leaders, Elite Four, rivals, Team Plasma).
  Downscaled 0.5x to GBA proportions for this mod. Credit required by
  the resource terms; please keep this notice with any redistribution.

- **StreakOfSprites** (https://www.deviantart.com/streakofsprites) —
  Ash Ketchum FRLG-style overworld sprite set
  (tools/character_mode/donor_sheets/ash_streakofsprites.png).

## Rosters
- Character Pokémon rosters compiled from **Bulbapedia**
  (https://bulbapedia.bulbagarden.net), CC BY-NC-SA.


## Emerald Rogue — trainer, back and overworld sprites (added 2026-07-25)

Staged in `sprites/donors/rogue/` — 294 sprites covering 160 Character Mode
characters (149 trainer front pics, 133 overworld sheets, 12 battle back pics),
filtered from a 531-file harvest down to characters actually on the roster.

- **Source**: https://github.com/Pokabbie/pokeemerald-rogue, branch `vanilla`,
  commit `79c1df5f8a2ebb423c7a48d29de0cf21ef5783e7`, fetched 2026-07-25.
- **Format**: converted from the repo's PNGs by `tools/png_to_gba.py` into
  `.4bpp` + `.gbapal` and LZ77 (BIOS type 0x10) streams of each. Every blob was
  round-tripped through the decompressor before staging.
- **Licensing**: the repository has **no LICENSE file**. Its in-game credits
  roll is the only attribution trail that exists, and it maps no artist to any
  individual file — so the **whole list travels with any subset of the art**.

**"Additional Sprites" — Emerald Rogue credits roll, reproduced in full:**

AveonTrainer · PurpleZaffre · UlithiumDragon · HighNoonMoon · xDracolich ·
ZacWeavile · Gnomowladny · Beliot419 · Brumirage · Kyledove · Kymotionian ·
cSc-A7X · 2and2makes5 · Pokegirl4ever · Fernandojl · Silver-Skie · Kid1513 ·
TyranitarDark · Getsuei-H · Milomilotic11 · Kyt666 · kdiamo11 · Chocosrawloid ·
SyleDude · Gallanty · Gizamimi-Pichu · princess-phoenix · LunarDusk6 ·
Larryturbo · Kidkatt · Zender1752 · SageDeoxys · Lasee0 · Ezerart · Wolfang62 ·
DarkusShadow · Anarlaurendil · Lasse00 · shaderr31 · CarmaNekko · EduarPokeN ·
TintjeMadelintje101

Plus the Emerald Rogue project itself (Pokabbie) for assembling and converting
the set.
