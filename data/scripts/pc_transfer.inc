# 1 "data/scripts/pc_transfer.pory"

# 2 "data/scripts/pc_transfer.pory"
Common_EventScript_GetGiftMonPartySlot::
# 3 "data/scripts/pc_transfer.pory"
	getpartysize
# 4 "data/scripts/pc_transfer.pory"
	subvar VAR_RESULT, 1
# 5 "data/scripts/pc_transfer.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 6 "data/scripts/pc_transfer.pory"
	return
# 7 "data/scripts/pc_transfer.pory"

# 8 "data/scripts/pc_transfer.pory"
Common_EventScript_NameReceivedBoxMon::
# 9 "data/scripts/pc_transfer.pory"
	fadescreen FADE_TO_BLACK
# 10 "data/scripts/pc_transfer.pory"
	special ChangeBoxPokemonNickname
# 11 "data/scripts/pc_transfer.pory"
	waitstate
# 12 "data/scripts/pc_transfer.pory"
	lock
# 13 "data/scripts/pc_transfer.pory"
	faceplayer
# 14 "data/scripts/pc_transfer.pory"
	return
# 15 "data/scripts/pc_transfer.pory"

# 16 "data/scripts/pc_transfer.pory"
Common_EventScript_TransferredToPC::
# 17 "data/scripts/pc_transfer.pory"
	bufferboxname 0, VAR_PC_BOX_TO_SEND_MON
# 18 "data/scripts/pc_transfer.pory"
	bufferspeciesname 1, VAR_TEMP_1
# 19 "data/scripts/pc_transfer.pory"
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_TransferredSomeonesPC
# 20 "data/scripts/pc_transfer.pory"
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_TransferredLanettesPC
# 21 "data/scripts/pc_transfer.pory"
	return
# 22 "data/scripts/pc_transfer.pory"

# 23 "data/scripts/pc_transfer.pory"
EventScript_TransferredSomeonesPC::
# 24 "data/scripts/pc_transfer.pory"
	specialvar VAR_RESULT, ShouldShowBoxWasFullMessage
# 25 "data/scripts/pc_transfer.pory"
	compare VAR_RESULT, 1
# 26 "data/scripts/pc_transfer.pory"
	goto_if_eq EventScript_SomeonesPCBoxFull
# 27 "data/scripts/pc_transfer.pory"
	msgbox gText_PkmnTransferredSomeonesPC, MSGBOX_DEFAULT
# 28 "data/scripts/pc_transfer.pory"
	return
# 29 "data/scripts/pc_transfer.pory"

# 30 "data/scripts/pc_transfer.pory"
EventScript_SomeonesPCBoxFull::
# 31 "data/scripts/pc_transfer.pory"
	specialvar VAR_RESULT, GetPCBoxToSendMon
# 32 "data/scripts/pc_transfer.pory"
	bufferboxname 2, VAR_RESULT
# 33 "data/scripts/pc_transfer.pory"
	msgbox gText_PkmnTransferredSomeonesPCBoxFull, MSGBOX_DEFAULT
# 34 "data/scripts/pc_transfer.pory"
	return
# 35 "data/scripts/pc_transfer.pory"

# 36 "data/scripts/pc_transfer.pory"
EventScript_TransferredLanettesPC::
# 37 "data/scripts/pc_transfer.pory"
	specialvar VAR_RESULT, ShouldShowBoxWasFullMessage
# 38 "data/scripts/pc_transfer.pory"
	compare VAR_RESULT, TRUE
# 39 "data/scripts/pc_transfer.pory"
	goto_if_eq EventScript_LanettesPCBoxFull
# 40 "data/scripts/pc_transfer.pory"
	msgbox gText_PkmnTransferredLanettesPC, MSGBOX_DEFAULT
# 41 "data/scripts/pc_transfer.pory"
	return
# 42 "data/scripts/pc_transfer.pory"

# 43 "data/scripts/pc_transfer.pory"
EventScript_LanettesPCBoxFull::
# 44 "data/scripts/pc_transfer.pory"
	specialvar VAR_RESULT, GetPCBoxToSendMon
# 45 "data/scripts/pc_transfer.pory"
	bufferboxname 2, VAR_RESULT
# 46 "data/scripts/pc_transfer.pory"
	msgbox gText_PkmnTransferredLanettesPCBoxFull, MSGBOX_DEFAULT
# 47 "data/scripts/pc_transfer.pory"
	return

Common_EventScript_NoMoreRoomForPokemon::
# 51 "data/scripts/pc_transfer.pory"
	msgbox gText_NoMoreRoomForPokemon, MSGBOX_DEFAULT
# 52 "data/scripts/pc_transfer.pory"
	release
	return

