# 1 "data/scripts/character_mode_gift.pory"

# 2 "data/scripts/character_mode_gift.pory"
@ Character Mode gift announcement (2026-08-26).
# 3 "data/scripts/character_mode_gift.pory"
@
# 4 "data/scripts/character_mode_gift.pory"
@ ScriptGiveEgg swaps the scripted species for a weighted draw from the active
# 5 "data/scripts/character_mode_gift.pory"
@ character's roster, and buffers the result: STR_VAR_1 = the species the player
# 6 "data/scripts/character_mode_gift.pory"
@ actually received, STR_VAR_2 = the character it belongs to.
# 7 "data/scripts/character_mode_gift.pory"
@
# 8 "data/scripts/character_mode_gift.pory"
@ Without this the NPC says "you received an EGG" and hands over a Beldum, and
# 9 "data/scripts/character_mode_gift.pory"
@ the player has no way to tell a working feature from a broken one -- the exact
# 10 "data/scripts/character_mode_gift.pory"
@ shape of the §7.14 encounter markers, and of Platinum's "no on-roster
# 11 "data/scripts/character_mode_gift.pory"
@ encounters" report, which was a MESSAGE defect and not a rate defect.
# 12 "data/scripts/character_mode_gift.pory"
@
# 13 "data/scripts/character_mode_gift.pory"
@ Outside Character Mode this costs one special call and returns, so both gift
# 14 "data/scripts/character_mode_gift.pory"
@ sites can call it unconditionally.
# 15 "data/scripts/character_mode_gift.pory"
EventScript_CharacterModeAnnounceGift::
# 16 "data/scripts/character_mode_gift.pory"
	specialvar VAR_RESULT, IsPlayerInCharacterMode
# 17 "data/scripts/character_mode_gift.pory"
	compare VAR_RESULT, 1
# 18 "data/scripts/character_mode_gift.pory"
	goto_if_ne EventScript_CharacterModeAnnounceGift_Done
# 19 "data/scripts/character_mode_gift.pory"
	msgbox Text_CharacterModeGiftNamed, MSGBOX_DEFAULT
# 20 "data/scripts/character_mode_gift.pory"
EventScript_CharacterModeAnnounceGift_Done::
# 21 "data/scripts/character_mode_gift.pory"
	return

Text_CharacterModeGiftNamed::
# 24 "data/scripts/character_mode_gift.pory"
	.string "It hatched on the spot!\p"
	.string "It's {STR_VAR_1}, destined for\n{STR_VAR_2}!$"
