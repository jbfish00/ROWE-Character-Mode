# 1 "data/scripts/surf.pory"

# 2 "data/scripts/surf.pory"
EventScript_UseSurf::
# 3 "data/scripts/surf.pory"
	checkpartymove MOVE_SURF
# 4 "data/scripts/surf.pory"
	compare VAR_RESULT, PARTY_SIZE
# 5 "data/scripts/surf.pory"
	goto_if_eq EventScript_EndUseSurf
# 6 "data/scripts/surf.pory"
	bufferpartymonnick 0, VAR_RESULT
# 7 "data/scripts/surf.pory"
	setfieldeffectargument 0, VAR_RESULT
# 8 "data/scripts/surf.pory"
	lockall
# 9 "data/scripts/surf.pory"
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
# 10 "data/scripts/surf.pory"
	compare VAR_RESULT, NO
# 11 "data/scripts/surf.pory"
	goto_if_eq EventScript_ReleaseUseSurf
# 12 "data/scripts/surf.pory"
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
# 13 "data/scripts/surf.pory"
	dofieldeffect FLDEFF_USE_SURF
# 14 "data/scripts/surf.pory"
EventScript_ReleaseUseSurf::
# 15 "data/scripts/surf.pory"
	releaseall
# 16 "data/scripts/surf.pory"
EventScript_EndUseSurf::
# 17 "data/scripts/surf.pory"
	end

# 20 "data/scripts/surf.pory"

# 21 "data/scripts/surf.pory"
EventScript_ExploudSurf::
# 22 "data/scripts/surf.pory"
	setvar VAR_0x8004, SPECIES_LAPRAS
# 23 "data/scripts/surf.pory"
	setvar VAR_0x8008, MOVE_SURF
# 24 "data/scripts/surf.pory"
	setvar VAR_0x8009, 1
# 25 "data/scripts/surf.pory"
	bufferspeciesname 0, VAR_0x8004
# 26 "data/scripts/surf.pory"
	buffermovename 1, VAR_0x8008
# 27 "data/scripts/surf.pory"
	msgbox Text_ExploudSurf, MSGBOX_YESNO
# 28 "data/scripts/surf.pory"
	compare VAR_RESULT, NO
# 29 "data/scripts/surf.pory"
	goto_if_eq EventScript_ReleaseUseSurf
# 30 "data/scripts/surf.pory"
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
# 31 "data/scripts/surf.pory"
	closemessage
# 32 "data/scripts/surf.pory"
	dofieldeffect FLDEFF_USE_SURF
# 33 "data/scripts/surf.pory"
	end
