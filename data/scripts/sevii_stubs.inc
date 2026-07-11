@ ============================================================================
@ 2.X Sevii: the Landorus legendary (real, below) plus STUBS for the feature
@ systems this branch has not ported yet.
@
@ The stubs belong to 2.X systems whose engine support we lack. Each needs more
@ than its script: the Alpha encounters want FLAG_ALPHA_CREATION,
@ FLAG_ENABLE_ALPHA_WILD_BATTLE_BOOST, FLAG_GOOD_MOVESET_CREATION,
@ LEVEL_SCALE_WILD_BOSS and the boss HP-multiplier var; the Water Starter Man
@ wants SCROLLING_STARTER_REGION and VAR_LAST_AVAILABLE_GEN. Porting the scripts
@ alone would compile but behave wrong, so they stay stubs until the systems land:
@   - Alpha Pokemon encounters  (alpha_mon_scripts.pory)
@   - Gift Pokemon              (gift_mon_scripts.pory)
@   - Mega Stone Gurus          (pkmn_center_jack.pory)
@
@ The NPCs/objects that reference them exist on the maps and are interactable;
@ they just say nothing until the systems land. Everything else on the islands
@ works. Replace these with the real scripts when those systems are ported.
@ ============================================================================

Common_EventScript_Alpha_Dragonite::
	end

Common_EventScript_Alpha_Garchomp_Z::
	end

Common_EventScript_Alpha_Scolipede::
	end

Common_EventScript_Alpha_Scrafty::
	end

Common_Eventscript_Enable_Alphas_Scolipede::
	end

@ ---------------------------------------------------------------------------
@ Landorus (SevenIsland_TanobyRuins_ViapoisChamber) -- ported from 2.X's
@ legendary_mon_scripts.pory. This one is NOT a stub; the legendary boost flags
@ it needs (FLAG_TOTEM_BATTLE, VAR_NUM_WILD_POKEMON_STAT_BOOST) already exist in
@ our engine.
@
@ 2.X's helper also sets VAR_BOSS_BATTLE_HP_MULTIPIER, which our engine has no
@ concept of yet -- that var belongs to the boss/Alpha HP system, still unported.
@ Landorus is therefore boosted but not HP-inflated. Revisit with the Alpha system.
Common_EventScript_SetLegendaryDefaultData::
	setflag FLAG_TOTEM_BATTLE
	setvar VAR_NUM_WILD_POKEMON_STAT_BOOST, 2
	return

Common_EventScript_Landorus_Encounter::
	lock
	faceplayer
	call Common_EventScript_SetLegendaryDefaultData
	playmoncry SPECIES_LANDORUS, 2
	msgbox Common_Text_Landorus_Cry, MSGBOX_DEFAULT
	waitmoncry
	setwildbattlewithcustommoves SPECIES_LANDORUS, 75, ITEM_LEFTOVERS, MOVE_EARTH_POWER, MOVE_SLUDGE_BOMB, MOVE_GRASS_KNOT, MOVE_CALM_MIND, 0, NATURE_TIMID
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Common_EventScript_Landorus_Caught
	case B_OUTCOME_WON, Common_EventScript_Landorus_Fled
	case B_OUTCOME_RAN, Common_EventScript_Landorus_Fled
	case B_OUTCOME_PLAYER_TELEPORTED, Common_EventScript_Landorus_Fled
	release
	end

Common_EventScript_Landorus_Caught::
	setflag FLAG_DEFEATED_LANDORUS
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

@ 2.X removes the object on a win/run too -- Landorus leaves the ruins either
@ way -- but only a capture sets FLAG_DEFEATED_LANDORUS, so beating it without
@ catching it means it is gone for this visit and back on the next one.
Common_EventScript_Landorus_Fled::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox Common_Text_Landorus_Fled, MSGBOX_DEFAULT
	release
	end

Common_Text_Landorus_Cry:
	.string "Landorus: Lan… Doroooos!$"

Common_Text_Landorus_Fled:
	.string "Landorus soared away on the wind!$"

Common_EventScript_Water_Starter_Man::
	end

Common_Mega_Stone_Guru_ER::
	end

Common_Mega_Stone_Guru_SWSH::
	end

EightIsland_EventScript_BattleMartSign::
	end
