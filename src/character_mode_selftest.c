#include "global.h"
#include <stddef.h>  // offsetof, for the struct-layout beacon below
#include "character_mode.h"
#include "battle.h"
#include "battle_setup.h"
#include "event_data.h"
#include "item.h"
#include "mgba.h"
#include "level_scaling.h"  // GetFirstEvolution + its reference implementation
#include "pokedex.h"  // GetSetPokedexFlag / FLAG_*_CAUGHT for the legendary pool
#include "pokemon.h"
#include "save.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "string_util.h"
#include "text.h"  // EOS, GetStringWidth
#include "trade.h"  // CreateInGameTradePokemon / DoInGameTradeScene (item 11)
#include "battle_bg.h"  // CM_REQ_SHINY_FRAME
#include "palette.h"   // the palette buffers it snapshots
#include "pokemon_storage_system.h"  // CountMonsInBox
#include "wild_encounter.h"  // CreateWildMonWithCharacterOverride + the fishing roll
#include "field_player_avatar.h"  // RefreshPlayerAvatarGraphics
#include "constants/trade.h"
#include "constants/species.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/vars.h"
#include "daycare.h"  // CM_REQ_DAYCARE drives the real store/take pair
#include "party_menu.h"            // CanLearnTutorMove -- CM_REQ_TMHM_PROBE
#include "constants/party_menu.h"  // TUTOR_MOVE_CUT

// Character Mode boot self-test.
//
// Runs once per boot (CB2_InitCopyrightScreenAfterBootup), ONLY under mGBA --
// mgba_open() fails on hardware and other emulators, so players never pay for
// it. Results go to the mGBA log (visible in mgba-qt's log window and on
// mgba-headless stderr) AND to gCharacterModeSelftestResult in EWRAM, which
// the headless Lua harness (tools/mgba_scripts/boot_smoke.lua) reads at the
// address recorded for it in pokeemerald.map. This is the ROWE port of the
// Lazarus/Radical Red in-ROM self-test technique: the assertions execute the
// REAL in-ROM code paths, not a host-side re-implementation of them.

struct CharacterModeSelftestResult
{
    u32 magic;   // CM_SELFTEST_MAGIC once the run is complete
    u16 passed;
    u16 failed;
};

#define CM_SELFTEST_MAGIC 0x434D5354  // "CMST"

EWRAM_DATA struct CharacterModeSelftestResult gCharacterModeSelftestResult = {0};

// Headless test mailbox. The Lua harness (tools/mgba_scripts/) writes a
// request into this struct; CB2_Overworld pumps it once per field frame, so
// every request executes the REAL game calls (FlagSet/AddBagItem/
// CreateScriptedWildMon/ScriptGiveMon) from a legal overworld context.
// Gated exactly like the boot self-test: mGBA only (the pump keys off the
// self-test magic, which only a boot under mGBA ever sets), zero cost on
// hardware, absent entirely without GBA_PRINTF.
//
// Field offsets (the Lua side mirrors these): +0 magic u32, +4 request u8,
// +5 status u8, +6 argA u16, +8 argB u16, +12 result u32.

// battle_interface.h can't be included here (it pulls battle_controllers.h,
// which needs the full battle.h type soup); declare the one guard we probe.
bool32 CanThrowLastUsedBall(void);

#define CM_TESTMB_MAGIC 0x434D5442  // "CMTB"

// APPEND ONLY. These ids are positional and the Lua side mirrors them by
// number (tools/mgba_scripts/intro_drive.lua, D.REQ). Inserting in the
// middle silently renumbers every later request, so a test keeps running
// and starts asking for something else entirely.
enum
{
    CM_REQ_NONE = 0,
    CM_REQ_SET_CHARACTER,  // argA: character id (1-based), 0 = mode off; result = InCharacterMode()
    CM_REQ_GIVE_ITEM,      // argA: item id, argB: quantity; result = AddBagItem()
    CM_REQ_SET_LAST_BALL,  // argA: ball item id (for the R-button quick throw)
    CM_REQ_WILD_BATTLE,    // argA: species, argB: level. Level must be >= 5:
                           // CreateScriptedWildMon treats 1-4 as scaling codes.
    CM_REQ_GIVE_MON,       // argA: species, argB: level; result = ScriptGiveMon() code
    CM_REQ_UNLOCK,         // ScriptContext2_Disable() -- a scripted wild battle
                           // returns to the field with the script lock still held
    CM_REQ_QUERY_BALL,     // argA: item id. result = lastUsedBall << 16
                           //   | CanThrowLastUsedBall() << 1 | CheckBagHasItem(argA, 1)
    CM_REQ_QUERY_PARTY_MON,// argA: party slot. result = level << 16 | species
                           // (0 for an empty/out-of-range slot)
    CM_REQ_QUERY_FLAG,     // argA: flag id. result = FlagGet(argA)
    CM_REQ_QUERY_VAR,      // argA: var id. result = VarGet(argA)
    CM_REQ_RUN_SCRIPT,     // argA: script address low 16, argB: high 16.
                           // Rejected while another script holds the lock.
    CM_REQ_SET_MON_HP,     // argA: party slot, argB: hp (0 faints the mon,
                           // e.g. so a scripted battle auto-sends the next)
    CM_REQ_SET_BATTLE_STYLE, // argA: 0 = SHIFT, 1 = SET. SET kills the
                             // "will you switch?" prompt a blind battle
                             // drive can wedge on.
    CM_REQ_SET_MON_MOVE,   // argA: party slot | (move slot << 8),
                           // argB: move id. PP is set to 10.
    CM_REQ_SWEEP_PARTY,    // run CharacterMode_SweepPartyToPC() (the exact
                           // call Cb2_ExitPSS makes on leaving the storage
                           // UI); result = party count after the sweep
    CM_REQ_SAVE,           // TrySavingData(SAVE_NORMAL); result = its return.
                           // Lets a headless run mint a .sav fixture in the
                           // CURRENT save format instead of shipping a stale
                           // one -- see tools/mgba_scripts/make_fixture_save.lua
    CM_REQ_QUERY_OT,       // argA: party slot. Everything the 12-character-name
                           // change put at risk, in one word:
                           //   bit0    IsOtherTrainer(otId, otName)  (want 0)
                           //   bit1    MON_DATA_SANITY_IS_BAD_EGG    (want 0)
                           //   bit2    OT name matches the player's  (want 1)
                           //   b8-15   strlen of the OT name read back
                           //   b16-23  strlen of the nickname read back
                           //   b24-31  strlen of the player name
    CM_REQ_SET_PLAYER_NAME,// argA: character to repeat, argB: how many (clamped
                           // to PLAYER_NAME_LENGTH). The naming screen's A-mash
                           // happens to stop at 6 characters, which is SHORTER
                           // than OT_NAME_LENGTH -- so a drive that relies on it
                           // never exercises OT truncation at all. This sets the
                           // name directly so the truncating case is reachable.
                           // result = strlen of the player name read back.
    CM_REQ_SET_NICKNAME,   // argA: party slot, argB: character to repeat.
                           // Fills the nickname with POKEMON_NAME_LENGTH copies
                           // of argB -- a maximum-length name with no room for
                           // a terminator, which is the case that overflows.
                           // result = strlen of the nickname read back.
    CM_REQ_LEGENDARY_POOL, // argA: level, argB: index into the pool.
                           // result = count | (pool[argB] << 16), so one request
                           // gives both the size and an entry. Proves the 1%
                           // legendary feature POSITIVELY -- a 1% roll on its own
                           // can never distinguish "correctly suppressed" from
                           // "never ran".
    CM_REQ_WILD_ROLL_STATS,// argA: level, argB: trials (capped at 4000). Runs the
                           // REAL CharacterMode_RollWildOverrideSpecies, the same
                           // function wild_encounter.c calls.
                           // result = legendaryFires | (totalFires << 16)
                           // This is the end-to-end positive assertion: it proves
                           // the 1% path is reachable through the shipping entry
                           // point, which no "a legendary never appeared" check
                           // can ever establish.
    CM_REQ_DEX_CAUGHT,     // argA: species, argB: 0 = query, 1 = set caught.
                           // Takes a SPECIES and converts internally, because
                           // passing a species id straight to GetSetPokedexFlag
                           // (which wants a national dex number) is the exact
                           // mistake this feature has to avoid.
                           // result = natdex << 16 | caughtFlag
    CM_REQ_LEGENDARY_ROLL_STATS, // argA: level, argB: trials (capped at 4000).
                           // Loops CharacterMode_RollWildLegendarySpecies alone.
                           // result = fires | (poolNonEmpty << 16)
                           //
                           // Exists because CM_REQ_WILD_ROLL_STATS is far too
                           // slow to sample heavily: measured at ~11.8 frames
                           // PER TRIAL, because the 10% path rebuilds a 47-entry
                           // candidate list and every entry costs a
                           // CharacterMode_FamilyBase evolution-table walk. The
                           // legendary roll early-outs on 99 of 100 calls, so it
                           // can be sampled thousands of times cheaply -- which
                           // is what makes a NON-FLAKY positive assertion on a
                           // 1% event possible at all.
    CM_REQ_PICK_STAGE,     // argA: species (a family base), argB: level.
                           // result = CharacterMode_PickEvolutionStageForLevel().
                           // The stage picker is what decides which evolution a
                           // wild roster spawn comes out as, and it is the model
                           // ENCOUNTERS.md reimplements in Python. Exposing it
                           // lets a test check the doc's model against the
                           // ENGINE rather than against itself.
    CM_REQ_VERIFY_PREEVO,  // argA: first species, argB: how many. Compares
                           // GetFirstEvolution against GetFirstEvolutionReference
                           // over that range. result = mismatches | (checked<<16).
                           // The fast path is a precomputed reverse of
                           // gEvolutionTable; this proves it EXHAUSTIVELY
                           // equivalent to the scan it replaced instead of
                           // spot-checking a few species. Chunked because a full
                           // sweep of the reference is ~22M iterations.
    CM_REQ_LEARNSET_PROBE, // argA: party slot | (op << 8), argB: op argument.
                           // Drives the three UNBOUNDED scans over
                           // gLevelUpLearnsets[species]. That array is
                           // designated-initializer, so a species with no row
                           // is a NULL pointer, and every one of these walks it
                           // with a u8 index and no bound -- on hardware the
                           // NULL read returns a constant BIOS-prefetch value
                           // whose .move is never LEVEL_UP_END, so the index
                           // wraps forever and the game HANGS. Four Legends:
                           // Arceus species shipped in exactly that state.
                           //   op 0: MonTryLearningNewMove sweep at the mon's
                           //         current level (the level-up path).
                           //         result = granted << 16 | iterations.
                           //   op 1: MonTryLearningNewMoveEvolution sweep (the
                           //         learn-on-evolution path, the level-0
                           //         sentinel rows). Same result encoding.
                           //   op 2: result = the mon's move in slot argB.
                           //   op 3: the party_menu.c:2851 field-move scan
                           //         shape -- walk to LEVEL_UP_END, capped at
                           //         250. result = entries | (found << 16).
                           //   op 4: evolve in place, the way the level-up
                           //         evolution check does.
                           //         result = GetEvolutionTargetSpecies().
                           // Every op returns a result AT ALL only because the
                           // row exists; a hang shows up as the request never
                           // completing, which is the point.
    CM_REQ_OVERRIDE_WILD_BATTLE, // argA: the map-table species to fall back to
                           // when the roll does not fire. argB: level |
                           // (wantKind << 8), wantKind being CHAR_WILD_ENCOUNTER_*.
                           // Calls the REAL CreateWildMonWithCharacterOverride
                           // -- the function BOTH shipping wild call sites go
                           // through -- over and over until the encounter kind
                           // it produces is the one asked for, then starts the
                           // battle through BattleSetup_StartWildBattle, the
                           // same entry point TryStandardWildEncounter uses.
                           //
                           // ⚠️ It does NOT force the kind, and that is the
                           // whole point. A test that sets the marker itself
                           // and then reads it back proves only that a byte
                           // round-trips; this one asks the shipping roll for
                           // an override, an ordinary encounter and a legendary
                           // IN THE SAME RUN, so a marker hardwired either on
                           // or off fails one of the three. Expected attempts:
                           // ~1 for NORMAL, ~11 for ROSTER, ~100 for LEGENDARY.
                           // result = species | (kind << 16), or 0 if the
                           // requested kind did not come up inside the cap (in
                           // which case NO battle is started).
    CM_REQ_PLAIN_WILD_BATTLE, // argA: species, argB: level. Marks the encounter
                           // kind ROSTER, then starts a wild battle the way
                           // every NON-override wild path does -- a bare
                           // CreateWildMon followed by BattleSetup_StartWildBattle,
                           // which is the shape of the mass outbreak
                           // (wild_encounter.c:442), the Feebas spot (:915),
                           // the DexNav spawns and the in-game trade mon.
                           //
                           // ⚠️ THIS REQUEST EXISTS BECAUSE A NEGATIVE CONTROL
                           // PASSED. Deleting CreateWildMon's clear left
                           // encounter_marker_e2e fully green: the override
                           // wrapper writes the kind on every call, NORMAL
                           // included, so it never depended on that clear. The
                           // clear is what protects the four paths above -- and
                           // nothing exercised any of them, so the line
                           // guarding all four was untested. This drives one.
    CM_REQ_BATTLE_STRING_WIDTH, // The width in pixels of the widest line of
                           // gDisplayedStringBattle, measured by the GAME's own
                           // GetStringWidth with the battle box's font and
                           // letter spacing. B_WIN_MSG is 26 tiles = 208 px, so
                           // anything above that is clipped on a real screen.
                           // result = width | (kind << 16), kind being
                           // CharacterMode_GetWildEncounterKind() at the moment
                           // of the read, so a test can tie the measurement to
                           // the string it is measuring.
    CM_REQ_INGAME_TRADE,   // argA: INGAME_TRADE_* index, argB: party slot to
                           // trade away. Sets the two script vars the trade
                           // scripts set and calls the SAME two specials they
                           // call -- CreateInGameTradePokemon then
                           // DoInGameTradeScene -- so the whole real cutscene
                           // runs, including the CharacterMode_SweepPartyToPC()
                           // at trade.c:3905/4422 that nothing has ever driven.
                           // Index 6 is the engine's "trade your own mon and get
                           // it back" mode, which is how a test gets an
                           // ON-roster incoming mon out of a table whose four
                           // real entries are all off-roster fossils.
                           // result = party count before the trade.
    CM_REQ_BOX_COUNT,      // Mons in PC box argA (0..TOTAL_BOXES_COUNT-1), or
                           // the total across every box when argA == 0xFFFF.
                           // "It left the party" and "it went to the PC" are
                           // different claims; the sweep's keptOne guard can
                           // make the first true while the second is false.
                           // result = the count.
    CM_REQ_REFRESH_AVATAR, // RefreshPlayerAvatarGraphics() -- the call
                           // ApplyCostumeChoice makes so a costume change is
                           // visible without leaving the map. SET_CHARACTER
                           // changes VAR_CHARACTER_ID but the player object
                           // keeps the graphics it was created with, so without
                           // this a visual check of a character's overworld art
                           // photographs the PREVIOUS character and looks fine.
    CM_REQ_SET_VAR,        // argA: var id, argB: value. VarSet(). Exists for the
                           // costume vars, which no other request can reach --
                           // VAR_COSTUME_CHARACTER is written by the costume
                           // menu and nothing else.
    CM_REQ_TMHM_PROBE,     // argA: first species, argB: how many. Runs the THREE
                           // accessors the party menu calls on the highlighted
                           // slot -- CanSpeciesLearnTMHM twice (Fly, Dig) and
                           // CanLearnTutorMove once (Cut) -- across that range.
                           // ⚠️ THE ASSERTION IS THAT THEY RETURN AT ALL. Both
                           // tables are designated-initializer arrays with
                           // hundreds of holes, and both accessors walked the
                           // returned pointer until they happened to find 0xFF.
                           // 49 roster species sat past the end of
                           // gTMHMLearnsets (Nemona's starter SPECIES_PAWMI is
                           // 1245 against 1199 rows) so opening the party menu
                           // read arbitrary ROM and walked it as a pointer.
                           // Same shape as CM_REQ_LEARNSET_PROBE and the July
                           // hang: a wedge here never answers, and every later
                           // step fails on its deadline.
                           // result = species checked | (learnable hits << 16).
    CM_REQ_MON_EV,         // argA: party slot | (ev index << 8), argB: value.
                           // Writes one EV, then reports it back.
                           // ev index is 0..5 = HP/Atk/Def/Speed/SpAtk/SpDef,
                           // matching sAllEvFields in party_menu.c.
                           // result = the EV read back | (sum of all six << 16).
                           // The sum is in the same word deliberately: "this one
                           // stat is 0" and "the mon has no EVs left at all" are
                           // different claims, and Zeromin has to make the second.
    CM_REQ_ZERO_ALL_EVS,   // argA: party slot. Runs CharacterMode_ZeroAllEVs --
                           // the SAME function ItemUseCB_ZeroAllEV calls, not a
                           // reimplementation of it.
                           // result = returned bool | (sum of all six EVs << 16).
                           // ⚠️ The bool is the half that matters. Zeroing an
                           // already-zero mon must return FALSE, or the item
                           // would be consumed for nothing -- and a test that
                           // only ever checks "the EVs are 0 afterwards" passes
                           // identically on a build that hardwires TRUE.
    CM_REQ_SWAP_BALL,      // argA: party slot, argB: ball item id. Runs
                           // CharacterMode_SwapMonBall, the function
                           // ItemUseCB_BallSwap calls.
                           // result = returned bool | (MON_DATA_POKEBALL << 16).
    CM_REQ_SET_MON_EGG,    // argA: party slot, argB: 0 or 1.
                           // result = IS_EGG | (SANITY_IS_EGG << 8), both read
                           // back after writing.
                           //
                           // ⚠️ IT DOES NOT WORK, AND THAT IS A FINDING, NOT A
                           // BUG IN THIS REQUEST. Writing either egg bit on an
                           // existing PARTY mon silently does nothing in this
                           // tree: the case was proved to run (a 0xE0000000
                           // marker came back in mb->result on 2026-08-19) and
                           // both reads still returned 0, for the plain
                           // unencrypted sanity bit as well as the encrypted
                           // one. SetBoxMonData's checksum guard is a SILENT
                           // `return` here where vanilla sets isBadEgg, so a
                           // refused write leaves no trace at all.
                           // Root cause NOT established. Kept because it is the
                           // only handle on the question, and because the
                           // ball swap's egg refusal is unprovable without it.
                           // ⚠️ Do not build a test on this until it is fixed --
                           // it will pass vacuously by never making an egg.
    CM_REQ_PARTY_MENU_ACTIONS, // argA: party slot. Runs the REAL party-menu
                           // action builder against the LIVE gPlayerParty and
                           // reports what it produced. Touches no state.
                           // result = 0 if it refused, else:
                           //   [31] ran | [25] Nickname row present
                           //   [24] last visible row is Cancel
                           //   [23:16] tilemapTop as the window computes it
                           //   [15:8] appends ATTEMPTED (unclamped)
                           //   [7:0]  numActions (what the menu would show)
                           // ⚠️ [15:8] is the half that settles PLAN.md item
                           // #7. [7:0] is clamped by AppendPartyMenuAction, so
                           // it reads the same on a build whose builder never
                           // wants a 9th row -- asserting on it alone is the
                           // vacuous shape this repo keeps re-inventing.
    CM_REQ_PARTY_ACTION_SWEEP, // argA: first species, argB: how many (<= 64).
                           // The same builder over synthetic two-mon parties,
                           // one per species, asking for the ceiling.
                           // result = [31] ran | [27:19] how many species
                           //   exceeded the window | [18:11] the largest demand
                           //   seen | [10:0] the species that produced it.
                           // ⚠️ Forces optionsAutomaticFollower on for the
                           // duration and restores it: the Follow row is one of
                           // the rows in dispute, so sweeping with the option
                           // off would understate the ceiling by one and call
                           // that a measurement.
    CM_REQ_SET_FOLLOWER_OPTION, // argA: 0 or 1. The automatic-follower option,
                           // which decides whether the party menu offers a
                           // Follow/Unfollow row at all -- one of the rows in
                           // dispute in PLAN.md item #7, so a probe run without
                           // control of it understates the builder's demand by
                           // exactly one and calls that a measurement.
                           // A request rather than a gTestStructOffsets entry
                           // because it is a ONE-BIT BITFIELD: there is no byte
                           // a test could write without clobbering the options
                           // packed beside it.
                           // result = the bit read back.
    CM_REQ_EGG_DIAG,       // argA: party slot, argB: op. PLAN.md item #9.
                           // Reads the egg bits at their STORAGE locations and
                           // the checksum the SetBoxMonData guard compares --
                           // see CharacterMode_EggDiag in pokemon.c for the ops
                           // and the bit layout.
                           // ⚠️ Ops 2 and 3 WRITE. They are a diagnostic, not a
                           // test: do not build an assertion on them until #9
                           // is root-caused, for exactly the reason
                           // CM_REQ_SET_MON_EGG carries the same warning.
    CM_REQ_EGG_POOL,       // argA: pool mode (CM_EGG_POOL_*), argB: a species to
                           // look for (0 = don't look).
                           // result = [31] ran | [30] species is in the pool
                           //          | [15:0] pool size.
                           // Asserts the EXCLUSIONS directly. Inferring them
                           // from draws would need thousands of trials to
                           // notice an exclusion had stopped working.
    CM_REQ_EGG_WEIGHT,     // argA: species. result = [31] ran | [23:0] weight.
                           // The curve itself: 255*100/catchRate, so Beldum (3)
                           // must read 8500 and Caterpie (255) must read 100.
    CM_REQ_EGG_ROLL,       // one draw from the live picker. result = species,
                           // 0 = SPECIES_NONE. Touches the RNG, nothing else.
    CM_REQ_EGG_ROLL_STATS, // argA: species to count, argB: trials (capped).
                           // result = [31] ran | [15:0] hits. Proves the RNG
                           // path actually CONSUMES the weights -- a pool and a
                           // weight table can both be right while the draw
                           // ignores them.
    CM_REQ_DAYCARE,        // argA: op | (slot << 8). PLAN.md item #10 -- the
                           // withdraw path had no e2e at all.
                           //   op 0: deposit party slot (argA >> 8) through the
                           //         REAL StoreSelectedPokemonInDaycare, with
                           //         gPartyMenu.slotId set the way the party
                           //         menu sets it (GetCursorSelectionMonId
                           //         returns exactly that field).
                           //   op 1: withdraw daycare slot (argA >> 8) through
                           //         the REAL TakePokemonFromDaycare, which
                           //         reads gSpecialVar_0x8004. That is the path
                           //         that writes straight into gPlayerParty and
                           //         then runs CharacterMode_SweepPartyToPC.
                           //         result = species << 16 | party count.
                           //   op 2: query. result = daycare count.
                           // ops 0 and 2 also return the daycare count in the
                           // low half, so a deposit that silently did nothing
                           // is visible without a second request.
    CM_REQ_LEARNSET_SWEEP, // argA: first species, argB: how many (<= 64).
                           // PLAN.md item #12. CM_REQ_LEARNSET_PROBE op 3 walks
                           // ONE mon's row; basculegion_hang_e2e spot-checks the
                           // four species that hung the game in July, so a FIFTH
                           // malformed row would not be caught. This walks
                           // gLevelUpLearnsets[sp] to LEVEL_UP_END for a RANGE
                           // of species, the same shape as CM_REQ_VERIFY_PREEVO
                           // and CM_REQ_TMHM_PROBE, so the Lua side can chunk
                           // the whole table.
                           // result = entries << 16 | checked << 8 | bad.
                           // "checked" counts only species with a gBaseStats
                           // row -- an id that cannot exist cannot hang the
                           // game. "bad" is a reachable species whose row is
                           // NULL or does not reach LEVEL_UP_END: the July four
                           // would have scored 4 here. "entries" is the in-band
                           // control, because zero bad rows is equally true of
                           // a sweep that walked nothing at all.
    CM_REQ_NICKNAME_APPLY, // argA: party slot, argB: character to repeat.
                           // PLAN.md item #8. Fills gStringVar2 the way the
                           // naming screen does, then calls the REAL
                           // CB2_SetPartyMonNickname via
                           // CharacterMode_TestNicknameApply -- as opposed to
                           // CM_REQ_SET_NICKNAME, which re-implements the write
                           // with its own SetMonData and so cannot prove
                           // anything about the row's own code.
                           // result = [31] ran | [23:16] read-back length |
                           //          [15:0] first mismatching index + 1, or 0
                           //          if every character survived.
    CM_REQ_FISHING_ITEM,   // argA: rod | (op << 8), argB: trials.
                           // PLAN.md item #13, the fishing-yields-an-item QoL.
                           //   op 0: run the PURE roll argB times and count the
                           //         hits. result = [31] ran | [15:0] hits.
                           //         Drives CharacterMode_PickFishingItem, so
                           //         the odds asserted are the game's own.
                           //   op 1: keep rolling (up to argB) until an item
                           //         comes up and return it, with NO bag
                           //         involvement. result = the item id, or 0.
                           //         For asserting the per-rod table.
                           //   op 2: the WHOLE path, bag and all --
                           //         CharacterMode_TryFishingItem, repeated up
                           //         to argB times until it fires.
                           //         result = [31] ran | [30] the bag actually
                           //         grew | [15:0] the item.
                           //   op 3: result = CharacterMode_FishingItemAt(rod,
                           //         argB) -- the game's OWN table, so a test
                           //         asserts membership against the ROM rather
                           //         than against ids retyped in Lua.
    CM_REQ_SHINY_FRAME,    // argA: op, argB: op argument. PLAN.md item #13, the
                           // shiny battle frame.
                           //   op 0: result = CharacterMode_ShinyFrameTint(argB)
                           //         -- the PURE transform, no battle needed.
                           //   op 1: build a SHINY enemy lead and run the whole
                           //         thing. result = [31] ran | [30] it
                           //         reported applying | [29] palette entries
                           //         actually changed.
                           //   op 2: the same with a NON-shiny lead. Both bits
                           //         must come back CLEAR -- without this pair
                           //         "the frame was tinted" is equally true of
                           //         a build that tints every battle.
                           //   op 3: a SHINY lead but NO battle in progress --
                           //         the evolution scene's exact shape, which
                           //         shares LoadBattleTextboxAndBackground and
                           //         never sets gBattleTypeFlags. Must also
                           //         come back clear.
                           // ⚠️ ops 1 and 2 RESTORE the palette afterwards:
                           // they run on the overworld, where those 32 entries
                           // are the live overworld palette.
};

enum
{
    CM_STATUS_WORKING = 0,  // Lua sets this before writing request
    CM_STATUS_DONE = 1,
    CM_STATUS_REJECTED = 2, // request not runnable right now (script lock held)
};

struct CharacterModeTestMailbox
{
    u32 magic;
    u8 request;
    u8 status;
    u16 argA;
    u16 argB;
    u16 padding;
    u32 result;
};

EWRAM_DATA struct CharacterModeTestMailbox gCharacterModeTestMailbox = {0};

#ifdef GBA_PRINTF

static void Check(const char *what, bool32 cond)
{
    if (cond)
    {
        gCharacterModeSelftestResult.passed++;
    }
    else
    {
        gCharacterModeSelftestResult.failed++;
        mgba_printf(MGBA_LOG_ERROR, "CM-SELFTEST FAIL: %s", what);
    }
}

// How many rosters contain the canonical family base of `species`.
static u32 CountRostersCovering(u16 species)
{
    u16 base = CharacterMode_FamilyBase(species);
    u32 count = 0;
    u32 i, j;

    for (i = 0; i < GetCharacterCount(); i++)
    {
        for (j = 0; gCharacters[i].roster[j] != SPECIES_NONE; j++)
        {
            if (gCharacters[i].roster[j] == base)
            {
                count++;
                break;
            }
        }
    }
    return count;
}

void CharacterMode_RunBootSelftest(void)
{
    u16 savedChar;
    bool8 savedFlag;

    if (!mgba_open())
        return;

    gCharacterModeSelftestResult.magic = 0;
    gCharacterModeSelftestResult.passed = 0;
    gCharacterModeSelftestResult.failed = 0;

    // --- family canonicalization: forms and evolution interleave ---
    Check("FamilyBase(Pikachu) == Pichu",
          CharacterMode_FamilyBase(SPECIES_PIKACHU) == SPECIES_PICHU);
    Check("FamilyBase(Raichu) == Pichu",
          CharacterMode_FamilyBase(SPECIES_RAICHU) == SPECIES_PICHU);
    Check("FamilyBase(Bulbasaur) == itself",
          CharacterMode_FamilyBase(SPECIES_BULBASAUR) == SPECIES_BULBASAUR);
    Check("FamilyBase(Charizard) == Charmander",
          CharacterMode_FamilyBase(SPECIES_CHARIZARD) == SPECIES_CHARMANDER);
    Check("FamilyBase(Galarian Farfetch'd) == Farfetch'd",
          CharacterMode_FamilyBase(SPECIES_FARFETCHD_GALARIAN) == SPECIES_FARFETCHD);
    Check("FamilyBase(Sirfetch'd) == Farfetch'd",
          CharacterMode_FamilyBase(SPECIES_SIRFETCHD) == SPECIES_FARFETCHD);
    Check("FamilyBase(Clodsire) == Wooper",
          CharacterMode_FamilyBase(SPECIES_CLODSIRE) == SPECIES_WOOPER);
    Check("FamilyBase(Paldean Wooper) == Wooper",
          CharacterMode_FamilyBase(SPECIES_WOOPER_PALDEA) == SPECIES_WOOPER);
    Check("FamilyBase(Shedinja) == Nincada",
          CharacterMode_FamilyBase(SPECIES_SHEDINJA) == SPECIES_NINCADA);

    // --- roster data coverage (regressions found 2026-07-16) ---
    Check("Clodsire line reachable on >= 4 rosters (Rika/Katy/Larry/Tulip)",
          CountRostersCovering(SPECIES_CLODSIRE) >= 4);
    Check("Galarian Farfetch'd line reachable on >= 6 rosters",
          CountRostersCovering(SPECIES_FARFETCHD_GALARIAN) >= 6);

    // --- the gate itself, driven through the real flag/var state ---
    savedChar = VarGet(VAR_CHARACTER_ID);
    savedFlag = FlagGet(FLAG_CHARACTER_MODE);

    FlagSet(FLAG_CHARACTER_MODE);
    VarSet(VAR_CHARACTER_ID, 1);  // gCharacters[0] = Red (characters.txt order)
    Check("canary: character 1 roster leads with Pikachu (Red)",
          gCharacters[0].roster[0] == SPECIES_PIKACHU);
    Check("Red: Pikachu allowed",
          IsSpeciesAllowedForCharacter(SPECIES_PIKACHU) == TRUE);
    Check("Red: Pichu allowed",
          IsSpeciesAllowedForCharacter(SPECIES_PICHU) == TRUE);
    Check("Red: Raichu allowed",
          IsSpeciesAllowedForCharacter(SPECIES_RAICHU) == TRUE);
    Check("Red: Charizard allowed",
          IsSpeciesAllowedForCharacter(SPECIES_CHARIZARD) == TRUE);
    // Off-roster control: Meowth until 2026-07-24, when the roster sync gave
    // Red the Persian line (his researched rematch teams). Controls must be
    // picked by FAMILY BASE and re-checked after any roster change.
    Check("Red: Poochyena blocked",
          IsSpeciesAllowedForCharacter(SPECIES_POOCHYENA) == FALSE);
    Check("Red: Treecko blocked",
          IsSpeciesAllowedForCharacter(SPECIES_TREECKO) == FALSE);
    Check("Red: SPECIES_NONE blocked",
          IsSpeciesAllowedForCharacter(SPECIES_NONE) == FALSE);
    Check("Red: out-of-range species blocked",
          IsSpeciesAllowedForCharacter(NUM_SPECIES) == FALSE);

    // --- wild encounter roster override (10% swap, never a legendary) ---
    Check("legendary check: Mewtwo flagged",
          CharacterMode_IsLegendaryOrMythical(SPECIES_MEWTWO) == TRUE);
    Check("legendary check: Pikachu not flagged",
          CharacterMode_IsLegendaryOrMythical(SPECIES_PIKACHU) == FALSE);
    Check("legendary check: Raichu (evolved form) not flagged",
          CharacterMode_IsLegendaryOrMythical(SPECIES_RAICHU) == FALSE);

    Check("stage pick: Bulbasaur at Lv.5 stays Bulbasaur",
          CharacterMode_PickEvolutionStageForLevel(SPECIES_BULBASAUR, 5) == SPECIES_BULBASAUR);
    Check("stage pick: Bulbasaur at Lv.20 becomes Ivysaur (evolves at 16)",
          CharacterMode_PickEvolutionStageForLevel(SPECIES_BULBASAUR, 20) == SPECIES_IVYSAUR);
    Check("stage pick: Bulbasaur at Lv.40 becomes Venusaur (Ivysaur evolves at 32)",
          CharacterMode_PickEvolutionStageForLevel(SPECIES_BULBASAUR, 40) == SPECIES_VENUSAUR);

    {
        // Red's roster includes Articuno/Deoxys/Entei/Raikou/Regigigas/Suicune
        // (6 legendaries) alongside ~41 ordinary members. 200 rolls at 10%
        // fire close to certainly (P(zero fires) = 0.9^200 ~= 1.6e-10) and
        // give the legendary exclusion many chances to fail if it's broken.
        u32 trial, fired = 0;
        u32 legendaryCount = 0;
        bool8 anyLegendary = FALSE;
        u32 kindMismatches = 0;
        u32 kindWithoutSpecies = 0;

        for (trial = 0; trial < 200; trial++)
        {
            // 0xFF, not NORMAL: a roll that returns SPECIES_NONE must leave the
            // out-param ALONE, and seeding it with a legal value would make
            // "never written" indistinguishable from "written as unmarked".
            u8 kind = 0xFF;
            u16 result = CharacterMode_RollWildOverrideSpecies(30, &kind);

            if (result != SPECIES_NONE)
            {
                u8 want = CharacterMode_IsLegendaryOrMythical(result)
                        ? CHAR_WILD_ENCOUNTER_LEGENDARY : CHAR_WILD_ENCOUNTER_ROSTER;

                fired++;
                if (kind != want)
                    kindMismatches++;
                if (CharacterMode_IsLegendaryOrMythical(result))
                {
                    anyLegendary = TRUE;
                    legendaryCount++;
                }
            }
            else if (kind != 0xFF)
            {
                kindWithoutSpecies++;
            }
        }
        Check("wild override: fired at least once in 200 rolls at 10% (Red active)",
              fired > 0);
        // The encounter marker's whole content. A kind hardwired to either value
        // fails one of these two, because the loop sees both outcomes: the kind
        // has to TRACK the species that actually came back, and a roll that
        // produced nothing must not label anything.
        Check("encounter kind: matches the species the roll returned, every time",
              kindMismatches == 0);
        Check("encounter kind: a roll that did not fire labels nothing",
              kindWithoutSpecies == 0);
        // Trap 1, asserted at every boot: 200 rolls just fired ~20 overrides and
        // started no battle. If the kind were stored by the ROLL rather than
        // beside the mon's creation, it would be standing here -- and the next
        // ordinary encounter would be announced as somebody's destiny.
        Check("encounter kind: 200 rolls with no battle leave the marker clear",
              CharacterMode_GetWildEncounterKind() == CHAR_WILD_ENCOUNTER_NORMAL);
        // NOTE: the old assertion here was "never produced a legendary", which
        // became WRONG when the 1% legendary roll landed -- and, worse, would
        // have stayed green either way. Legendaries are now expected from this
        // path; what must hold is that they stay RARE. 200 rolls at 1% average
        // 2, and P(>=12) is about 4e-6, so this catches the legendary roll
        // leaking into the 10% path without flaking.
        Check("wild override: legendaries stay rare (< 12 in 200 rolls at 1%)",
              legendaryCount < 12);
        (void)anyLegendary;
    }

    // The 1% legendary encounter feature. These assert the POSITIVE direction on
    // purpose: a 1% event is the ideal hiding place for a test that cannot fail,
    // because once the dex filter can suppress legendaries, "no legendary
    // appeared" is satisfied both by correct suppression AND by the feature
    // being completely dead. Everything below tests the pool directly, so it is
    // deterministic rather than probabilistic.
    {
        u16 pool[16];
        u8 count, i;
        u16 firstDex;
        bool8 wasCaught;

        // Red's roster carries 6 legendaries (Articuno, Deoxys, Entei, Raikou,
        // Regigigas, Suicune), so an uncaught dex must yield a non-empty pool.
        count = CharacterMode_BuildLegendaryPool(30, pool, ARRAY_COUNT(pool), NULL);
        Check("legendary pool: non-empty for a character with legendaries (Red)",
              count > 0);

        for (i = 0; i < count; i++)
        {
            if (!CharacterMode_IsLegendaryOrMythical(pool[i]))
                break;
        }
        Check("legendary pool: every entry is actually a legendary/mythical",
              i == count);

        // Every entry must resolve to a real national dex number. A 0 here is
        // the failure that silently filters the wrong Pokemon -- the accessor
        // takes a NATIONAL DEX number, not a species id, and in this tree those
        // differ.
        for (i = 0; i < count; i++)
        {
            if (SpeciesToNationalPokedexNum(pool[i]) == 0)
                break;
        }
        Check("legendary pool: every entry has a national dex number",
              i == count);

        // The "offered until caught" filter is NOT tested here on purpose: it
        // requires setting a caught flag, and this self-test runs at every boot
        // against the player's REAL save. Mutating the dex to prove a test point
        // is not worth corrupting a playthrough. That proof lives in
        // tools/mgba_scripts/legendary_encounter_e2e.lua, which runs against a
        // throwaway generated fixture where mutation costs nothing.
        (void)firstDex;
        (void)wasCaught;
    }

    FlagClear(FLAG_CHARACTER_MODE);
    VarSet(VAR_CHARACTER_ID, 0);
    // ⚠️ MUST be a species the active character would REFUSE, or this check
    // cannot fail. It asked about SPECIES_MEOWTH until 2026-08-09 -- and Meowth
    // is ON Red's roster (characters.h), while the block above sets
    // VAR_CHARACTER_ID = 1 = Red. Allowed either way, so deleting the
    // FlagClear above, or hardwiring InCharacterMode() to TRUE, left this
    // green. Poochyena is already proven off-roster for Red 140 lines up, which
    // makes this the in-band opposite of that check rather than a restatement.
    Check("mode off: everything allowed",
          IsSpeciesAllowedForCharacter(SPECIES_POOCHYENA) == TRUE);
    // A SINGLE roll here was a ~89% pass on a build where the mode never
    // turned off: the two rolls together fire only ~11% of the time, so one
    // sample mostly missed. 200 rolls makes a stuck-on mode a certainty rather
    // than a coin flip, and costs nothing on a correct build -- with the mode
    // off, GetActiveCharacter() returns NULL and the function returns on its
    // first line, well before the expensive candidate-list walk.
    {
        u32 offRolls;
        bool8 everFired = FALSE;

        for (offRolls = 0; offRolls < 200; offRolls++)
        {
            if (CharacterMode_RollWildOverrideSpecies(30, NULL) != SPECIES_NONE)
            {
                everFired = TRUE;
                break;
            }
        }
        Check("wild override: mode off never fires", everFired == FALSE);
    }

    if (savedFlag)
        FlagSet(FLAG_CHARACTER_MODE);
    VarSet(VAR_CHARACTER_ID, savedChar);

    mgba_printf(gCharacterModeSelftestResult.failed ? MGBA_LOG_ERROR : MGBA_LOG_WARN,
                "CM-SELFTEST: %d passed, %d failed",
                gCharacterModeSelftestResult.passed,
                gCharacterModeSelftestResult.failed);
    gCharacterModeSelftestResult.magic = CM_SELFTEST_MAGIC;
}

// Struct-layout beacon for the Lua harness.
//
// The mGBA scripts used to hardcode struct offsets recovered from a savestate
// probe (`struct BattleResults: battleTurnCounter +0x13, lastUsedMovePlayer
// +0x22`). Those went stale the moment POKEMON_NAME_LENGTH went 10 -> 12,
// because BattleResults embeds playerMon1Name[POKEMON_NAME_LENGTH + 1] at 0x8 --
// so battleTurnCounter moved to 0x15 and lastUsedMovePlayer to 0x26.
//
// The cost of that was not a broken game but a LYING TEST:
// gigaton_reselect_e2e read a turn counter that never changed and a last-move
// that was always 0, so it reported the Gigaton Hammer selection gate broken
// while the ROM was performing it correctly -- and the handover notes recorded
// that as a red suite blocking the release.
//
// Offsets now come from the compiler. A test that reads them here cannot drift.
// Append only, and mirror any addition in tools/mgba_scripts/harness.lua.
const u16 gTestStructOffsets[] =
{
    offsetof(struct BattleResults, battleTurnCounter),   // [0]
    offsetof(struct BattleResults, lastUsedMovePlayer),  // [1]
    sizeof(struct BattlePokemon),                        // [2]
    offsetof(struct BattlePokemon, hp),                  // [3]
    offsetof(struct BattlePokemon, maxHP),               // [4]
    offsetof(struct BattlePokemon, moves),               // [5]
    offsetof(struct BattlePokemon, nickname),            // [6]
    offsetof(struct BattlePokemon, otName),              // [7]
    // [8] Lets a test set/clear an arbitrary flag DIRECTLY in SaveBlock1 at a
    // moment when the mailbox pump is not running -- the pump is only called
    // from CB2_Overworld and BattleMainCB2, so while the Character Mode menu
    // owns the screen there is no other way to change game state at all. That
    // is exactly the state mode_exclusion_e2e has to create to prove the START
    // commit clears FLAG_FULL_RANDOMIZED_MODE. Reads go back through the
    // mailbox's FlagGet, so the raw write is always cross-checked by the game's
    // own accessor rather than trusted.
    offsetof(struct SaveBlock1, flags),                  // [8]
    // ⚠️ optionsAutomaticFollower does NOT belong here and was tried: it is a
    // one-bit bitfield, so there is no byte address to hand a test and writing
    // the containing byte would clobber every option packed beside it. It is
    // CM_REQ_SET_FOLLOWER_OPTION instead.
};

void CharacterMode_PumpTestMailbox(void)
{
    struct CharacterModeTestMailbox *mb = &gCharacterModeTestMailbox;

    // Only a boot under mGBA sets the self-test magic; on hardware and other
    // emulators this compare is the whole cost of the pump.
    if (gCharacterModeSelftestResult.magic != CM_SELFTEST_MAGIC)
        return;

    mb->magic = CM_TESTMB_MAGIC;  // tells the harness the pump is alive
    if (mb->request == CM_REQ_NONE)
        return;

    mb->result = 0;
    switch (mb->request)
    {
    case CM_REQ_SET_CHARACTER:
        if (mb->argA == 0)
        {
            FlagClear(FLAG_CHARACTER_MODE);
            VarSet(VAR_CHARACTER_ID, 0);
        }
        else
        {
            FlagSet(FLAG_CHARACTER_MODE);
            VarSet(VAR_CHARACTER_ID, mb->argA);
        }
        mb->result = InCharacterMode();
        break;
    case CM_REQ_GIVE_ITEM:
        mb->result = AddBagItem(mb->argA, mb->argB);
        break;
    case CM_REQ_SET_LAST_BALL:
        gSaveBlock2Ptr->lastUsedBall = mb->argA;
        break;
    case CM_REQ_WILD_BATTLE:
        if (ScriptContext2_IsEnabled())
        {
            mb->request = CM_REQ_NONE;
            mb->status = CM_STATUS_REJECTED;
            return;
        }
        CreateScriptedWildMon(mb->argA, mb->argB, ITEM_NONE);
        BattleSetup_StartScriptedWildBattle();
        break;
    case CM_REQ_GIVE_MON:
        mb->result = ScriptGiveMon(mb->argA, mb->argB, ITEM_NONE, 3, 0, 0);
        break;
    case CM_REQ_UNLOCK:
        ScriptContext2_Disable();
        break;
    case CM_REQ_QUERY_BALL:
        mb->result = ((u32)gSaveBlock2Ptr->lastUsedBall << 16)
                   | (CanThrowLastUsedBall() ? 2 : 0)
                   | (CheckBagHasItem(mb->argA, 1) ? 1 : 0);
        break;
    case CM_REQ_QUERY_PARTY_MON:
        if (mb->argA < PARTY_SIZE)
            mb->result = ((u32)GetMonData(&gPlayerParty[mb->argA], MON_DATA_LEVEL, NULL) << 16)
                       | GetMonData(&gPlayerParty[mb->argA], MON_DATA_SPECIES, NULL);
        break;
    case CM_REQ_QUERY_FLAG:
        mb->result = FlagGet(mb->argA);
        break;
    case CM_REQ_QUERY_VAR:
        mb->result = VarGet(mb->argA);
        break;
    case CM_REQ_RUN_SCRIPT:
        if (ScriptContext2_IsEnabled())
        {
            mb->request = CM_REQ_NONE;
            mb->status = CM_STATUS_REJECTED;
            return;
        }
        ScriptContext1_SetupScript((const u8 *)((u32)mb->argA | ((u32)mb->argB << 16)));
        break;
    case CM_REQ_SET_MON_HP:
        if (mb->argA < PARTY_SIZE)
        {
            u16 hp = mb->argB;
            SetMonData(&gPlayerParty[mb->argA], MON_DATA_HP, &hp);
            mb->result = GetMonData(&gPlayerParty[mb->argA], MON_DATA_HP, NULL);
        }
        break;
    case CM_REQ_SET_BATTLE_STYLE:
        gSaveBlock2Ptr->optionsBattleStyle = mb->argA;
        mb->result = gSaveBlock2Ptr->optionsBattleStyle;
        break;
    case CM_REQ_SWEEP_PARTY:
        CharacterMode_SweepPartyToPC();
        mb->result = CalculatePlayerPartyCount();
        break;
    case CM_REQ_SAVE:
        mb->result = TrySavingData(SAVE_NORMAL);
        break;
    case CM_REQ_QUERY_OT:
        if (mb->argA < PARTY_SIZE)
        {
            struct Pokemon *mon = &gPlayerParty[mb->argA];
            u8 otName[OT_NAME_LENGTH + 1];
            u8 nickname[POKEMON_NAME_LENGTH + 1];
            u32 otId;
            u8 i;
            bool8 matches = TRUE;

            // Both buffers are sized the way the game sizes them. If either
            // accessor still writes PLAYER_NAME_LENGTH bytes, this smashes the
            // stack -- which is exactly the defect worth catching.
            GetMonData(mon, MON_DATA_OT_NAME, otName);
            GetMonData(mon, MON_DATA_NICKNAME, nickname);
            otId = GetMonData(mon, MON_DATA_OT_ID, NULL);

            for (i = 0; i < OT_NAME_LENGTH; i++)
            {
                if (otName[i] == EOS)
                    break;
                if (otName[i] != gSaveBlock2Ptr->playerName[i])
                    matches = FALSE;
            }

            mb->result = (IsOtherTrainer(otId, otName) ? 1 : 0)
                       | (GetMonData(mon, MON_DATA_SANITY_IS_BAD_EGG, NULL) ? 2 : 0)
                       | (matches ? 4 : 0)
                       | ((u32)StringLength(otName) << 8)
                       | ((u32)StringLength(nickname) << 16)
                       | ((u32)StringLength(gSaveBlock2Ptr->playerName) << 24);
        }
        break;
    case CM_REQ_LEGENDARY_POOL:
        {
            u16 pool[16];
            bool8 repeatable = FALSE;
            u8 count = CharacterMode_BuildLegendaryPool(mb->argA, pool,
                                                        ARRAY_COUNT(pool),
                                                        &repeatable);
            u16 entry = (mb->argB < count) ? pool[mb->argB] : SPECIES_NONE;

            // count in bits 0-7, the §1.2 repeatable exemption in bit 8, the
            // requested entry in the high half.
            mb->result = ((u32)entry << 16) | (repeatable ? 0x100 : 0) | count;
        }
        break;
    case CM_REQ_WILD_ROLL_STATS:
        {
            u16 trials = mb->argB;
            u16 t;
            u16 legendaryFires = 0;
            u16 totalFires = 0;

            if (trials > 4000)
                trials = 4000;

            for (t = 0; t < trials; t++)
            {
                // NULL out-param on purpose: this loop measures RATES and must
                // not label anything. The kind belongs to a battle, and there
                // is no battle here -- see CHAR_WILD_ENCOUNTER_* in the header.
                u16 got = CharacterMode_RollWildOverrideSpecies(mb->argA, NULL);

                if (got == SPECIES_NONE)
                    continue;
                totalFires++;
                if (CharacterMode_IsLegendaryOrMythical(got))
                    legendaryFires++;
            }
            mb->result = ((u32)totalFires << 16) | legendaryFires;
        }
        break;
    case CM_REQ_OVERRIDE_WILD_BATTLE:
        {
            u8 level = mb->argB & 0xFF;
            u8 wantKind = mb->argB >> 8;
            u16 species = SPECIES_NONE;
            u16 attempt;
            bool8 got = FALSE;

            if (ScriptContext2_IsEnabled())
            {
                mb->request = CM_REQ_NONE;
                mb->status = CM_STATUS_REJECTED;
                return;
            }

            // 3000 is ~30x the mean wait for the rarest case (the 1% legendary),
            // so a miss means the feature is dead rather than unlucky. Each
            // attempt builds a real mon, which is the cost of driving the
            // shipping function instead of a stripped-down copy of it.
            for (attempt = 0; attempt < 3000; attempt++)
            {
                species = CreateWildMonWithCharacterOverride(mb->argA, level);
                if (CharacterMode_GetWildEncounterKind() == wantKind)
                {
                    got = TRUE;
                    break;
                }
            }

            if (!got)
            {
                mb->result = 0;
                break;
            }

            mb->result = ((u32)wantKind << 16) | species;
            BattleSetup_StartWildBattle();
        }
        break;
    case CM_REQ_PLAIN_WILD_BATTLE:
        if (ScriptContext2_IsEnabled())
        {
            mb->request = CM_REQ_NONE;
            mb->status = CM_STATUS_REJECTED;
            return;
        }
        // Mark FIRST, so the only thing that can unmark this battle is
        // CreateWildMon itself. A test that started from an already-clear
        // marker would pass whether the clear ran or not.
        CharacterMode_SetWildEncounterKind(CHAR_WILD_ENCOUNTER_ROSTER);
        CreateWildMon(mb->argA, mb->argB);
        mb->result = CharacterMode_GetWildEncounterKind();
        BattleSetup_StartWildBattle();
        break;
    case CM_REQ_BATTLE_STRING_WIDTH:
        // FONT_NORMAL with letterSpacing 0 is what sTextOnWindowsInfo_Normal[0]
        // prints the battle message with; GetStringWidth returns the widest
        // LINE, having reset at each CHAR_NEWLINE, which is the number that has
        // to fit B_WIN_MSG.
        mb->result = ((u32)CharacterMode_GetWildEncounterKind() << 16)
                   | (GetStringWidth(1, gDisplayedStringBattle, 0) & 0xFFFF);
        break;
    case CM_REQ_INGAME_TRADE:
        if (ScriptContext2_IsEnabled())
        {
            mb->request = CM_REQ_NONE;
            mb->status = CM_STATUS_REJECTED;
            return;
        }
        gSpecialVar_0x8004 = mb->argA;   // which trade
        gSpecialVar_0x8005 = mb->argB;   // which party slot goes away
        mb->result = CalculatePlayerPartyCount();
        CreateInGameTradePokemon();
        DoInGameTradeScene();
        break;
    case CM_REQ_BOX_COUNT:
        {
            u16 total = 0;
            u8 box;

            if (mb->argA == 0xFFFF)
            {
                for (box = 0; box < TOTAL_BOXES_COUNT; box++)
                    total += CountMonsInBox(box);
            }
            else if (mb->argA < TOTAL_BOXES_COUNT)
            {
                total = CountMonsInBox(mb->argA);
            }
            mb->result = total;
        }
        break;
    case CM_REQ_REFRESH_AVATAR:
        RefreshPlayerAvatarGraphics();
        break;
    case CM_REQ_SET_VAR:
        VarSet(mb->argA, mb->argB);
        mb->result = VarGet(mb->argA);
        break;
    case CM_REQ_VERIFY_PREEVO:
        {
            u16 first = mb->argA;
            u16 count = mb->argB;
            u16 mismatches = 0;
            u16 checked = 0;
            u16 sp;

            if (count > 64)
                count = 64;   // the reference is O(NUM_SPECIES * EVOS_PER_MON)
            for (sp = first; sp < first + count && sp < NUM_SPECIES; sp++)
            {
                checked++;
                if (GetFirstEvolution(sp) != GetFirstEvolutionReference(sp))
                    mismatches++;
            }
            mb->result = ((u32)checked << 16) | mismatches;
        }
        break;
    case CM_REQ_TMHM_PROBE:
        {
            u16 first = mb->argA;
            u16 count = mb->argB;
            u16 checked = 0;
            u16 tmhmHits = 0;
            u16 tutorHits = 0;
            u16 sp;

            if (count > 256)
                count = 256;
            // The exact three calls ShowPartyMenu makes on the highlighted slot
            // to decide whether to offer Fly, Dig and Cut. Reaching the end of
            // this loop IS the assertion: before gTMHMLearnsets and
            // sTutorLearnsets were sized to NUM_SPECIES and the accessors
            // NULL-checked, a species past the last designator read an
            // arbitrary ROM word and walked it looking for 0xFF.
            for (sp = first; sp < first + count && sp < NUM_SPECIES; sp++)
            {
                checked++;
                if (CanSpeciesLearnTMHM(sp, ITEM_TM76_FLY - ITEM_TM01_FOCUS_PUNCH))
                    tmhmHits++;
                if (CanSpeciesLearnTMHM(sp, ITEM_TM28_DIG - ITEM_TM01_FOCUS_PUNCH))
                    tmhmHits++;
                if (CanLearnTutorMove(sp, TUTOR_MOVE_CUT))
                    tutorHits++;
            }
            // ⚠️ The two accessors are counted SEPARATELY and packed apart. A
            // single combined counter cannot tell them apart, and the negative
            // control proved that matters: neutering CanSpeciesLearnTMHM alone
            // still left CanLearnTutorMove contributing hits, so a
            // "hits > 0" assertion stayed green on a build where two thirds of
            // the field-move offers were dead. Per chunk: tmhmHits <= 512,
            // tutorHits <= 256, checked <= 256 -- 10 + 10 + 12 bits.
            mb->result = ((u32)checked << 20) | ((u32)tutorHits << 10) | tmhmHits;
        }
        break;
    case CM_REQ_PICK_STAGE:
        mb->result = CharacterMode_PickEvolutionStageForLevel(mb->argA, mb->argB);
        break;
    case CM_REQ_LEGENDARY_ROLL_STATS:
        {
            u16 trials = mb->argB;
            u16 t;
            u16 fires = 0;
            u16 pool[16];
            u8 poolCount;

            if (trials > 4000)
                trials = 4000;

            for (t = 0; t < trials; t++)
            {
                if (CharacterMode_RollWildLegendarySpecies(mb->argA) != SPECIES_NONE)
                    fires++;
            }

            poolCount = CharacterMode_BuildLegendaryPool(mb->argA, pool,
                                                         ARRAY_COUNT(pool), NULL);
            mb->result = ((u32)(poolCount > 0 ? 1 : 0) << 16) | fires;
        }
        break;
    case CM_REQ_DEX_CAUGHT:
        {
            u16 natNum = SpeciesToNationalPokedexNum(mb->argA);

            if (mb->argB == 1)
                GetSetPokedexFlag(natNum, FLAG_SET_CAUGHT);
            mb->result = ((u32)natNum << 16)
                       | (GetSetPokedexFlag(natNum, FLAG_GET_CAUGHT) ? 1 : 0);
        }
        break;
    case CM_REQ_SET_PLAYER_NAME:
        {
            u8 n = mb->argB;
            u8 i;

            if (n > PLAYER_NAME_LENGTH)
                n = PLAYER_NAME_LENGTH;
            for (i = 0; i < n; i++)
                gSaveBlock2Ptr->playerName[i] = mb->argA;
            // playerName is PLAYER_NAME_LENGTH + 1 bytes, so a full-length name
            // still terminates inside the field.
            gSaveBlock2Ptr->playerName[n] = EOS;
            mb->result = StringLength(gSaveBlock2Ptr->playerName);
        }
        break;
    case CM_REQ_SET_NICKNAME:
        if (mb->argA < PARTY_SIZE)
        {
            u8 nickname[POKEMON_NAME_LENGTH + 1];
            u8 i;

            for (i = 0; i < POKEMON_NAME_LENGTH; i++)
                nickname[i] = mb->argB;
            nickname[POKEMON_NAME_LENGTH] = EOS;

            SetMonData(&gPlayerParty[mb->argA], MON_DATA_NICKNAME, nickname);
            GetMonData(&gPlayerParty[mb->argA], MON_DATA_NICKNAME, nickname);
            mb->result = StringLength(nickname);
        }
        break;
    case CM_REQ_MON_EV:
        {
            u8 slot = mb->argA & 0xFF;
            u8 evIndex = mb->argA >> 8;
            u8 value = mb->argB & 0xFF;
            static const u8 sEvFieldsForTest[] =
            {
                MON_DATA_HP_EV, MON_DATA_ATK_EV, MON_DATA_DEF_EV,
                MON_DATA_SPEED_EV, MON_DATA_SPATK_EV, MON_DATA_SPDEF_EV,
            };
            if (slot < PARTY_SIZE && evIndex < ARRAY_COUNT(sEvFieldsForTest))
            {
                struct Pokemon *mon = &gPlayerParty[slot];
                SetMonData(mon, sEvFieldsForTest[evIndex], &value);
                CalculateMonStats(mon);
                mb->result = GetMonData(mon, sEvFieldsForTest[evIndex], NULL)
                           | (CharacterMode_SumAllEVs(mon) << 16);
            }
        }
        break;
    case CM_REQ_ZERO_ALL_EVS:
        {
            u8 slot = mb->argA & 0xFF;
            if (slot < PARTY_SIZE)
            {
                struct Pokemon *mon = &gPlayerParty[slot];
                u16 changed = CharacterMode_ZeroAllEVs(mon);
                mb->result = changed | (CharacterMode_SumAllEVs(mon) << 16);
            }
        }
        break;
    case CM_REQ_SWAP_BALL:
        {
            u8 slot = mb->argA & 0xFF;
            if (slot < PARTY_SIZE)
            {
                struct Pokemon *mon = &gPlayerParty[slot];
                u16 changed = CharacterMode_SwapMonBall(mon, mb->argB);
                mb->result = changed
                           | (GetMonData(mon, MON_DATA_POKEBALL, NULL) << 16);
            }
        }
        break;
    case CM_REQ_SET_MON_EGG:
        {
            u8 slot = mb->argA & 0xFF;
            u8 isEgg = mb->argB & 0xFF;
            if (slot < PARTY_SIZE)
            {
                struct Pokemon *mon = &gPlayerParty[slot];
                // Both bits, because they are stored in different places:
                // boxMon->isEgg is the sanity bit and substruct3->isEgg is the
                // encrypted one, and only the second is what MON_DATA_IS_EGG
                // reads back.
                SetMonData(mon, MON_DATA_SANITY_IS_EGG, &isEgg);
                SetMonData(mon, MON_DATA_IS_EGG, &isEgg);
                mb->result = GetMonData(mon, MON_DATA_IS_EGG, NULL)
                           | (GetMonData(mon, MON_DATA_SANITY_IS_EGG, NULL) << 8);
            }
        }
        break;
    case CM_REQ_SET_FOLLOWER_OPTION:
        gSaveBlock2Ptr->optionsAutomaticFollower = (mb->argA != 0);
        mb->result = gSaveBlock2Ptr->optionsAutomaticFollower;
        break;
    case CM_REQ_EGG_DIAG:
        mb->result = CharacterMode_EggDiag(mb->argA & 0xFF, mb->argB & 0xFF);
        break;
    case CM_REQ_EGG_POOL:
        {
            u16 pool[CHARACTER_MAX_ROSTER_CANDIDATES];
            u8 count = CharacterMode_BuildEggPool(mb->argA & 0xFF, pool, ARRAY_COUNT(pool));
            u32 result = 0x80000000 | count;
            u32 i;

            if (mb->argB != SPECIES_NONE)
            {
                for (i = 0; i < count; i++)
                {
                    if (pool[i] == mb->argB)
                    {
                        result |= 0x40000000;
                        break;
                    }
                }
            }
            mb->result = result;
        }
        break;
    case CM_REQ_EGG_WEIGHT:
        mb->result = 0x80000000 | (CharacterMode_EggWeight(mb->argA) & 0x00FFFFFF);
        break;
    case CM_REQ_EGG_ROLL:
        mb->result = CharacterMode_RollEggSpecies();
        break;
    case CM_REQ_EGG_ROLL_STATS:
        {
            u32 trials = mb->argB > 4000 ? 4000 : mb->argB;
            u32 hits = 0;
            u32 i;

            for (i = 0; i < trials; i++)
            {
                if (CharacterMode_RollEggSpecies() == mb->argA)
                    hits++;
            }
            mb->result = 0x80000000 | (hits & 0xFFFF);
        }
        break;
    case CM_REQ_SHINY_FRAME:
        {
            u8 op = mb->argA;

            if (op == 0)
            {
                mb->result = 0x80000000 | CharacterMode_ShinyFrameTint(mb->argB);
            }
            else if (op == 1 || op == 2 || op == 3)
            {
                u16 saveUnfaded[32];
                u16 saveFaded[32];
                u16 i;
                u32 changed = 0;
                bool8 applied;
                bool8 savedInBattle;

                for (i = 0; i < 32; i++)
                {
                    saveUnfaded[i] = gPlttBufferUnfaded[i];
                    saveFaded[i] = gPlttBufferFaded[i];
                }

                // otId ^ personality == 0 is shiny by construction, so no
                // brute-force search is needed for the positive case. For the
                // negative one, a personality whose halves cannot cancel a zero
                // otId. op 3 uses the SHINY setup deliberately -- see below.
                CreateMon(&gEnemyParty[0], SPECIES_PIKACHU, 5, 32, TRUE,
                          (op == 2) ? 0x1234ABCD : 0, OT_ID_PRESET, 0, 0);

                // ⭐ op 3 IS THE REGRESSION TEST for the evolution-scene bug.
                // LoadBattleTextboxAndBackground is shared with
                // evolution_scene.c, which never sets gBattleTypeFlags, so a
                // guard built only out of those flags did not fire there -- and
                // a zeroed gEnemyParty slot reads as SHINY (0^0^0^0 = 0 <
                // SHINY_ODDS). op 3 asks for the tint with a genuinely shiny
                // lead but NO battle in progress, which is the evolution
                // scene's exact shape, and the answer must still be no.
                //
                // The mailbox pump runs from CB2_Overworld, where inBattle is
                // already 0, so ops 1 and 2 have to assert it to reach the
                // decision at all. It is restored immediately.
                savedInBattle = gMain.inBattle;
                gMain.inBattle = (op == 3) ? FALSE : TRUE;
                applied = CharacterMode_ApplyShinyBattleFrame();
                gMain.inBattle = savedInBattle;

                for (i = 0; i < 32; i++)
                {
                    if (gPlttBufferUnfaded[i] != saveUnfaded[i])
                        changed++;
                }

                for (i = 0; i < 32; i++)
                {
                    gPlttBufferUnfaded[i] = saveUnfaded[i];
                    gPlttBufferFaded[i] = saveFaded[i];
                }

                mb->result = 0x80000000;
                if (applied)
                    mb->result |= 0x40000000;
                if (changed)
                    mb->result |= 0x20000000;
                mb->result |= (changed & 0xFFFF);
            }
        }
        break;
    case CM_REQ_FISHING_ITEM:
        {
            u8 rod = mb->argA & 0xFF;
            u8 op = mb->argA >> 8;
            u32 trials = mb->argB > 4000 ? 4000 : mb->argB;
            u32 i;

            if (op == 0)
            {
                u32 hits = 0;

                for (i = 0; i < trials; i++)
                {
                    if (CharacterMode_PickFishingItem(rod) != ITEM_NONE)
                        hits++;
                }
                mb->result = 0x80000000 | (hits & 0xFFFF);
            }
            else if (op == 1)
            {
                for (i = 0; i < trials; i++)
                {
                    u16 item = CharacterMode_PickFishingItem(rod);

                    if (item != ITEM_NONE)
                    {
                        mb->result = item;
                        break;
                    }
                }
            }
            else if (op == 2)
            {
                u16 item = ITEM_NONE;
                u32 before = 0;
                u32 after = 0;
                u8 j;

                // Sum every item this rod can give, BEFORE and after: the roll
                // decides which one, so no single id can be snapshotted, and
                // "the player has one" is not the claim -- "the player has one
                // MORE" is.
                for (j = 0; j < FISHING_ITEMS_PER_ROD; j++)
                    before += CountTotalItemQuantityInBag(
                        CharacterMode_FishingItemAt(rod, j));

                for (i = 0; i < trials; i++)
                {
                    if (CharacterMode_TryFishingItem(rod, &item))
                        break;
                }

                for (j = 0; j < FISHING_ITEMS_PER_ROD; j++)
                    after += CountTotalItemQuantityInBag(
                        CharacterMode_FishingItemAt(rod, j));

                mb->result = 0x80000000 | (item & 0xFFFF);
                if (after > before)
                    mb->result |= 0x40000000;
            }
            else if (op == 3)
            {
                mb->result = CharacterMode_FishingItemAt(rod, mb->argB);
            }
        }
        break;
    case CM_REQ_DAYCARE:
        {
            u8 op = mb->argA & 0xFF;
            u8 slot = mb->argA >> 8;

            // ⚠️ THE FULL-DAYCARE CHECK IS OURS TO MAKE, and it is not
            // optional. Daycare_FindEmptySpot returns -1 when both slots are
            // taken and StorePokemonInEmptyDaycareSlot uses that return
            // UNCHECKED -- &daycare->mons[-1] is an out-of-bounds WRITE, into
            // whatever precedes the daycare in SaveBlock1. Vanilla never
            // reaches it because the daycare SCRIPT checks capacity before
            // offering to deposit; this mailbox is an ungated caller of the
            // same function, so the check has to live here.
            if (op == 0 && slot < PARTY_SIZE
                && CountPokemonInDaycare(&gSaveBlock1Ptr->daycare) < DAYCARE_MON_COUNT)
            {
                // GetCursorSelectionMonId() returns gPartyMenu.slotId, so this
                // is the deposit the party menu performs, not a copy of it.
                gPartyMenu.slotId = slot;
                StoreSelectedPokemonInDaycare();
            }
            else if (op == 1)
            {
                u16 species;

                gSpecialVar_0x8004 = slot;
                species = TakePokemonFromDaycare();
                mb->result = ((u32)species << 16) | CalculatePlayerPartyCount();
                break;
            }
            mb->result = CountPokemonInDaycare(&gSaveBlock1Ptr->daycare);
        }
        break;
    case CM_REQ_LEARNSET_SWEEP:
        {
            u16 first = mb->argA;
            u16 count = mb->argB;
            u16 checked = 0;
            u16 bad = 0;
            u16 entries = 0;
            u16 sp;

            if (count > 64)
                count = 64;
            for (sp = first; sp < first + count && sp < NUM_SPECIES; sp++)
            {
                u16 i = 0;

                // Only species that can actually EXIST are the question. An id
                // with no gBaseStats row cannot be created, caught, traded or
                // evolved into, so a NULL learnset there is unreachable and
                // counting it would bury the reachable ones in noise.
                if (gBaseStats[sp].baseHP == 0 && gBaseStats[sp].baseSpeed == 0
                    && gBaseStats[sp].catchRate == 0)
                    continue;
                checked++;

                // ⚠️ A NULL row IS the July defect -- do not walk it. The three
                // shipping loops (src/pokemon.c:4864, :9525,
                // src/party_menu.c:2851) walk it with a u8 index and no bound
                // at all and simply hang; doing the same here would wedge the
                // harness instead of reporting the species.
                if (gLevelUpLearnsets[sp] == NULL)
                {
                    bad++;
                    continue;
                }

                // The cap exists ONLY so a malformed row reports a number
                // instead of wedging. The shipping loops have no cap.
                while (i < 250 && gLevelUpLearnsets[sp][i].move != LEVEL_UP_END)
                    i++;
                if (i >= 250)
                    bad++;
                entries += i;
            }
            // entries is the in-band control: "0 bad rows" is equally true of a
            // sweep that walks nothing at all, which is one edit away (`while
            // (0)`), so the Lua side asserts a large entry count too.
            mb->result = ((u32)entries << 16) | ((u32)checked << 8) | bad;
        }
        break;
    case CM_REQ_NICKNAME_APPLY:
        {
            u8 slot = mb->argA & 0xFF;
            u8 want = mb->argB;
            u8 readback[POKEMON_NAME_LENGTH + 1];
            u8 i;
            u32 firstBad = 0;

            if (slot >= PARTY_SIZE)
                break;

            // Exactly what CB2_NicknamePartyMon leaves behind for the naming
            // screen to edit: the buffer the screen writes into is gStringVar2.
            for (i = 0; i < POKEMON_NAME_LENGTH; i++)
                gStringVar2[i] = want;
            gStringVar2[POKEMON_NAME_LENGTH] = EOS;

            CharacterMode_TestNicknameApply(slot);

            GetMonData(&gPlayerParty[slot], MON_DATA_NICKNAME, readback);
            for (i = 0; i < POKEMON_NAME_LENGTH; i++)
            {
                if (readback[i] != want)
                {
                    firstBad = i + 1;
                    break;
                }
            }
            mb->result = 0x80000000
                       | ((u32)StringLength(readback) << 16)
                       | (firstBad & 0xFFFF);
        }
        break;
    case CM_REQ_PARTY_MENU_ACTIONS:
        mb->result = CharacterMode_ProbePartyMenuActions(mb->argA & 0xFF);
        break;
    case CM_REQ_PARTY_ACTION_SWEEP:
        mb->result = CharacterMode_SweepPartyMenuActions(mb->argA, mb->argB, &mb->result);
        break;
    case CM_REQ_SET_MON_MOVE:
        {
            u8 slot = mb->argA & 0xFF;
            u8 moveSlot = mb->argA >> 8;
            u16 move = mb->argB;
            u8 pp = 10;
            if (slot < PARTY_SIZE && moveSlot < MAX_MON_MOVES)
            {
                SetMonData(&gPlayerParty[slot], MON_DATA_MOVE1 + moveSlot, &move);
                SetMonData(&gPlayerParty[slot], MON_DATA_PP1 + moveSlot, &pp);
                mb->result = GetMonData(&gPlayerParty[slot], MON_DATA_MOVE1 + moveSlot, NULL);
            }
        }
        break;
    case CM_REQ_LEARNSET_PROBE:
        {
            u8 slot = mb->argA & 0xFF;
            u8 op = mb->argA >> 8;
            struct Pokemon *mon;
            u16 move;
            u16 species;
            u16 targetSpecies;
            u8 targetFormId;
            u32 granted;
            u32 iterations;

            if (slot >= PARTY_SIZE)
                break;
            mon = &gPlayerParty[slot];
            granted = 0;
            iterations = 0;

            switch (op)
            {
            case 0:
                // The level-up path, exactly as LevelUpMon drives it.
                move = MonTryLearningNewMove(mon, TRUE);
                while (move != 0 && iterations < 32)
                {
                    if (move != MON_HAS_MAX_MOVES && move != MON_ALREADY_KNOWS_MOVE)
                        granted++;
                    iterations++;
                    move = MonTryLearningNewMove(mon, FALSE);
                }
                mb->result = (granted << 16) | iterations;
                break;
            case 1:
                // The learn-on-evolution path (the LEVEL_UP_MOVE(0, X) rows).
                move = MonTryLearningNewMoveEvolution(mon, TRUE);
                while (move != 0 && iterations < 32)
                {
                    if (move != MON_HAS_MAX_MOVES && move != MON_ALREADY_KNOWS_MOVE)
                        granted++;
                    iterations++;
                    move = MonTryLearningNewMoveEvolution(mon, FALSE);
                }
                mb->result = (granted << 16) | iterations;
                break;
            case 2:
                if (mb->argB < MAX_MON_MOVES)
                    mb->result = GetMonData(mon, MON_DATA_MOVE1 + mb->argB, NULL);
                break;
            case 3:
                // The party_menu.c:2851 field-move scan shape: walk the row to
                // LEVEL_UP_END. Capped here ONLY so a regression reports a
                // number instead of wedging the harness; the shipping loop has
                // no cap at all.
                species = GetMonData(mon, MON_DATA_SPECIES, NULL);
                while (iterations < 250
                       && gLevelUpLearnsets[species][iterations].move != LEVEL_UP_END)
                    iterations++;
                if (iterations < 250)
                    granted = 1;   // LEVEL_UP_END was actually reached
                mb->result = (granted << 16) | iterations;
                break;
            case 4:
                targetFormId = 0;
                targetSpecies = GetEvolutionTargetSpecies(mon, 0, ITEM_NONE, SPECIES_NONE, &targetFormId);
                if (targetSpecies != SPECIES_NONE)
                {
                    SetMonData(mon, MON_DATA_SPECIES, &targetSpecies);
                    SetMonData(mon, MON_DATA_FORM_ID, &targetFormId);
                    CalculateMonStats(mon);
                }
                mb->result = targetSpecies;
                break;
            }
        }
        break;
    }
    mb->request = CM_REQ_NONE;
    mb->status = CM_STATUS_DONE;
}

#else

void CharacterMode_RunBootSelftest(void)
{
}

void CharacterMode_PumpTestMailbox(void)
{
}

#endif // GBA_PRINTF
