# 1 "data/scripts/obtain_item.pory"

# 2 "data/scripts/obtain_item.pory"
Std_ObtainItem::
# 3 "data/scripts/obtain_item.pory"
    copyvar VAR_0x8006, VAR_0x8000
# 4 "data/scripts/obtain_item.pory"
	additem VAR_0x8000, VAR_0x8001
# 5 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8007, VAR_RESULT
# 6 "data/scripts/obtain_item.pory"
	call EventScript_ObtainItemMessage
# 7 "data/scripts/obtain_item.pory"
	return
# 8 "data/scripts/obtain_item.pory"

# 9 "data/scripts/obtain_item.pory"
EventScript_ObtainItemMessage::
# 10 "data/scripts/obtain_item.pory"
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
# 11 "data/scripts/obtain_item.pory"
	checkitemtype VAR_0x8000
# 12 "data/scripts/obtain_item.pory"
	call EventScript_BufferPocketNameAndTryFanfare
# 13 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 14 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_ObtainedItem
# 15 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 0
# 16 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_NoRoomForItem
# 17 "data/scripts/obtain_item.pory"
	return
# 18 "data/scripts/obtain_item.pory"

# 19 "data/scripts/obtain_item.pory"
EventScript_BufferPocketNameAndTryFanfare::
# 20 "data/scripts/obtain_item.pory"
	switch VAR_RESULT
# 21 "data/scripts/obtain_item.pory"
	case POCKET_ITEMS, EventScript_BufferItemsPocket
# 22 "data/scripts/obtain_item.pory"
	case POCKET_MEDICINE, EventScript_BufferMedicinePocket
# 23 "data/scripts/obtain_item.pory"
	case POCKET_POKE_BALLS, EventScript_BufferPokeballsPocket
# 24 "data/scripts/obtain_item.pory"
	case POCKET_BATTLE_ITEMS, EventScript_BufferBattleItemsPocket
# 25 "data/scripts/obtain_item.pory"
	case POCKET_TYPE_ITEMS, EventScript_BufferTypeItemsPocket
# 26 "data/scripts/obtain_item.pory"
	case POCKET_MEGA_STONES, EventScript_BufferMegaStonesPocket
# 27 "data/scripts/obtain_item.pory"
	case POCKET_BERRIES, EventScript_BufferBerriesPocket
# 28 "data/scripts/obtain_item.pory"
	case POCKET_POWER_UP, EventScript_BufferPowerUpPocket
# 29 "data/scripts/obtain_item.pory"
	case POCKET_TM_HM, EventScript_BufferTMHMsPocket
# 30 "data/scripts/obtain_item.pory"
	case POCKET_KEY_ITEMS, EventScript_BufferKeyItemsPocket
# 31 "data/scripts/obtain_item.pory"
	end
# 32 "data/scripts/obtain_item.pory"

# 33 "data/scripts/obtain_item.pory"
EventScript_BufferItemsPocket::
# 34 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_ITEMS
# 35 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 36 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 37 "data/scripts/obtain_item.pory"
	return
# 38 "data/scripts/obtain_item.pory"

# 39 "data/scripts/obtain_item.pory"
EventScript_BufferKeyItemsPocket::
# 40 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_KEYITEMS
# 41 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 42 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 43 "data/scripts/obtain_item.pory"
	return
# 44 "data/scripts/obtain_item.pory"

# 45 "data/scripts/obtain_item.pory"
EventScript_BufferPokeballsPocket::
# 46 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_POKEBALLS
# 47 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 48 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 49 "data/scripts/obtain_item.pory"
	return
# 50 "data/scripts/obtain_item.pory"

# 51 "data/scripts/obtain_item.pory"
EventScript_BufferTMHMsPocket::
# 52 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_TMHMS
# 53 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 54 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedTMHM
# 55 "data/scripts/obtain_item.pory"
	return
# 56 "data/scripts/obtain_item.pory"

# 57 "data/scripts/obtain_item.pory"
EventScript_BufferBerriesPocket::
# 58 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_BERRIES
# 59 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 60 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 61 "data/scripts/obtain_item.pory"
	return
# 62 "data/scripts/obtain_item.pory"

# 63 "data/scripts/obtain_item.pory"
EventScript_BufferMedicinePocket::
# 64 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_MEDICINE
# 65 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 66 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 67 "data/scripts/obtain_item.pory"
	return
# 68 "data/scripts/obtain_item.pory"

# 69 "data/scripts/obtain_item.pory"
EventScript_BufferBattleItemsPocket::
# 70 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_BATTLEITEMS
# 71 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 72 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 73 "data/scripts/obtain_item.pory"
	return
# 74 "data/scripts/obtain_item.pory"

# 75 "data/scripts/obtain_item.pory"
EventScript_BufferPowerUpPocket::
# 76 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_POWERUP
# 77 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 78 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 79 "data/scripts/obtain_item.pory"
	return
# 80 "data/scripts/obtain_item.pory"

# 81 "data/scripts/obtain_item.pory"
EventScript_BufferTypeItemsPocket::
# 82 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_TYPEITEMS
# 83 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 84 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 85 "data/scripts/obtain_item.pory"
	return
# 86 "data/scripts/obtain_item.pory"

# 87 "data/scripts/obtain_item.pory"
EventScript_BufferMegaStonesPocket::
# 88 "data/scripts/obtain_item.pory"
	bufferstdstring 2, STDSTRING_MEGASTONES
# 89 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 90 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PlayFanfareObtainedItem
# 91 "data/scripts/obtain_item.pory"
	return
# 92 "data/scripts/obtain_item.pory"

# 93 "data/scripts/obtain_item.pory"
EventScript_ObtainedItem::
# 94 "data/scripts/obtain_item.pory"
	compare VAR_0x8001, 1
# 95 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_ObtainedItemMessage
# 96 "data/scripts/obtain_item.pory"
	buffernumberstring 0, VAR_0x8001
# 97 "data/scripts/obtain_item.pory"
	message gText_ObtainedTheItems
# 98 "data/scripts/obtain_item.pory"
	goto EventScript_ContinueObtainedItem
# 99 "data/scripts/obtain_item.pory"
EventScript_ObtainedItemMessage:
# 100 "data/scripts/obtain_item.pory"
	message gText_ObtainedTheItem
# 101 "data/scripts/obtain_item.pory"
EventScript_ContinueObtainedItem:
# 102 "data/scripts/obtain_item.pory"
    delay 10
# 103 "data/scripts/obtain_item.pory"
    showitemdesc
# 104 "data/scripts/obtain_item.pory"
	waitfanfare
# 105 "data/scripts/obtain_item.pory"
    msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 106 "data/scripts/obtain_item.pory"
	hideitemdesc
# 107 "data/scripts/obtain_item.pory"
    setvar VAR_RESULT, 1
# 108 "data/scripts/obtain_item.pory"
	return
# 109 "data/scripts/obtain_item.pory"

# 110 "data/scripts/obtain_item.pory"
EventScript_NoRoomForItem::
# 111 "data/scripts/obtain_item.pory"
	addpcitem VAR_0x8006, VAR_0x8001
# 112 "data/scripts/obtain_item.pory"
	compare VAR_RESULT, 1
# 113 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_ItemSentToPC
# 114 "data/scripts/obtain_item.pory"
	setvar VAR_RESULT, 0
# 115 "data/scripts/obtain_item.pory"
	return
# 116 "data/scripts/obtain_item.pory"

# 117 "data/scripts/obtain_item.pory"
EventScript_ItemSentToPC::
# 118 "data/scripts/obtain_item.pory"
	playfanfare MUS_OBTAIN_ITEM
# 119 "data/scripts/obtain_item.pory"
	message gText_ObtainedTheItem
# 120 "data/scripts/obtain_item.pory"
	delay 10
# 121 "data/scripts/obtain_item.pory"
	waitfanfare
# 122 "data/scripts/obtain_item.pory"
	waitmessage
# 123 "data/scripts/obtain_item.pory"
	msgbox gText_ItemSentToPC, MSGBOX_DEFAULT
# 124 "data/scripts/obtain_item.pory"
	setvar VAR_RESULT, 1
# 125 "data/scripts/obtain_item.pory"
	return
# 126 "data/scripts/obtain_item.pory"

# 127 "data/scripts/obtain_item.pory"
EventScript_PlayFanfareObtainedItem::
# 128 "data/scripts/obtain_item.pory"
	playfanfare MUS_OBTAIN_ITEM
# 129 "data/scripts/obtain_item.pory"
	return
# 130 "data/scripts/obtain_item.pory"

# 131 "data/scripts/obtain_item.pory"
EventScript_PlayFanfareObtainedTMHM::
# 132 "data/scripts/obtain_item.pory"
	playfanfare MUS_OBTAIN_TMHM
# 133 "data/scripts/obtain_item.pory"
	return
# 134 "data/scripts/obtain_item.pory"

# 135 "data/scripts/obtain_item.pory"
Std_ObtainDecoration::
# 136 "data/scripts/obtain_item.pory"
	adddecoration VAR_0x8000
# 137 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8007, VAR_RESULT
# 138 "data/scripts/obtain_item.pory"
	call EventScript_ObtainDecorationMessage
# 139 "data/scripts/obtain_item.pory"
	return
# 140 "data/scripts/obtain_item.pory"

# 141 "data/scripts/obtain_item.pory"
EventScript_ObtainDecorationMessage::
# 142 "data/scripts/obtain_item.pory"
	bufferdecorationname 1, VAR_0x8000
# 143 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 144 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_ObtainedDecor
# 145 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 0
# 146 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_NoRoomForDecor
# 147 "data/scripts/obtain_item.pory"
	return
# 148 "data/scripts/obtain_item.pory"

# 149 "data/scripts/obtain_item.pory"
EventScript_ObtainedDecor::
# 150 "data/scripts/obtain_item.pory"
	playfanfare MUS_OBTAIN_ITEM
# 151 "data/scripts/obtain_item.pory"
	message gText_ObtainedTheDecor
# 152 "data/scripts/obtain_item.pory"
	waitfanfare
# 153 "data/scripts/obtain_item.pory"
	msgbox gText_TheDecorWasTransferredToThePC, MSGBOX_DEFAULT
# 154 "data/scripts/obtain_item.pory"
	setvar VAR_RESULT, 1
# 155 "data/scripts/obtain_item.pory"
	return
# 156 "data/scripts/obtain_item.pory"

# 157 "data/scripts/obtain_item.pory"
EventScript_NoRoomForDecor::
# 158 "data/scripts/obtain_item.pory"
	setvar VAR_RESULT, 0
# 159 "data/scripts/obtain_item.pory"
	return
# 160 "data/scripts/obtain_item.pory"

# 161 "data/scripts/obtain_item.pory"
Std_FindItem::
# 162 "data/scripts/obtain_item.pory"
	lock
# 163 "data/scripts/obtain_item.pory"
	faceplayer
# 164 "data/scripts/obtain_item.pory"
	waitse
# 165 "data/scripts/obtain_item.pory"
    copyvar VAR_0x8006, VAR_0x8000
# 166 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8004, VAR_0x8000
# 167 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8005, VAR_0x8001
# 168 "data/scripts/obtain_item.pory"
	checkitemspace VAR_0x8000, VAR_0x8001
# 169 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8007, VAR_RESULT
# 170 "data/scripts/obtain_item.pory"
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
# 171 "data/scripts/obtain_item.pory"
	checkitemtype VAR_0x8000
# 172 "data/scripts/obtain_item.pory"
	call EventScript_BufferPocketNameAndTryFanfare
# 173 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 174 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_PickUpItem
# 175 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 0
# 176 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_NoRoomToPickUpItem
# 177 "data/scripts/obtain_item.pory"
	release
# 178 "data/scripts/obtain_item.pory"
	return
# 179 "data/scripts/obtain_item.pory"

# 180 "data/scripts/obtain_item.pory"
EventScript_PickUpItem::
# 181 "data/scripts/obtain_item.pory"
	removeobject VAR_LAST_TALKED
# 182 "data/scripts/obtain_item.pory"
	additem VAR_0x8004, VAR_0x8005
# 183 "data/scripts/obtain_item.pory"
    copyvar VAR_0x8006 VAR_0x8004
# 184 "data/scripts/obtain_item.pory"
	specialvar VAR_RESULT, BufferTMHMMoveName
# 185 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8008, VAR_RESULT
# 186 "data/scripts/obtain_item.pory"
	compare VAR_0x8008, 1
# 187 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_FoundTMHM
# 188 "data/scripts/obtain_item.pory"
	compare VAR_0x8008, 0
# 189 "data/scripts/obtain_item.pory"
	call_if_eq EventScript_FoundItem
# 190 "data/scripts/obtain_item.pory"
    delay 10
# 191 "data/scripts/obtain_item.pory"
    showitemdesc
# 192 "data/scripts/obtain_item.pory"
	waitfanfare
# 193 "data/scripts/obtain_item.pory"
	waitmessage
# 194 "data/scripts/obtain_item.pory"
	bufferitemnameplural 1, VAR_0x8004, VAR_0x8005
# 195 "data/scripts/obtain_item.pory"
	pyramid_inchallenge
# 196 "data/scripts/obtain_item.pory"
	compare VAR_RESULT, 1
# 197 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_PutBattlePyramidItemInBag
# 198 "data/scripts/obtain_item.pory"
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 199 "data/scripts/obtain_item.pory"
    hideitemdesc
# 200 "data/scripts/obtain_item.pory"
	return
# 201 "data/scripts/obtain_item.pory"

# 202 "data/scripts/obtain_item.pory"
EventScript_PutBattlePyramidItemInBag::
# 203 "data/scripts/obtain_item.pory"
	msgbox gText_PlayerPutItemInBag, MSGBOX_DEFAULT
# 204 "data/scripts/obtain_item.pory"
	return
# 205 "data/scripts/obtain_item.pory"

# 206 "data/scripts/obtain_item.pory"
EventScript_FoundTMHM::
# 207 "data/scripts/obtain_item.pory"
	bufferitemnameplural 0, VAR_0x8004, VAR_0x8005
# 208 "data/scripts/obtain_item.pory"
	message gText_PlayerFoundOneTMHM
# 209 "data/scripts/obtain_item.pory"
	return
# 210 "data/scripts/obtain_item.pory"

# 211 "data/scripts/obtain_item.pory"
EventScript_FoundItem::
# 212 "data/scripts/obtain_item.pory"
	message gText_PlayerFoundOneItem
# 213 "data/scripts/obtain_item.pory"
	return
# 214 "data/scripts/obtain_item.pory"

# 215 "data/scripts/obtain_item.pory"
EventScript_NoRoomToPickUpItem::
# 216 "data/scripts/obtain_item.pory"
	addpcitem VAR_0x8004, VAR_0x8005
# 217 "data/scripts/obtain_item.pory"
	compare VAR_RESULT, 1
# 218 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_FoundItemSentToPC
# 219 "data/scripts/obtain_item.pory"
	msgbox gText_ObtainedTheItem, MSGBOX_DEFAULT
# 220 "data/scripts/obtain_item.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 221 "data/scripts/obtain_item.pory"
	setvar VAR_RESULT, 0
# 222 "data/scripts/obtain_item.pory"
	return
# 223 "data/scripts/obtain_item.pory"

# 224 "data/scripts/obtain_item.pory"
EventScript_FoundItemSentToPC::
# 225 "data/scripts/obtain_item.pory"
	removeobject VAR_LAST_TALKED
# 226 "data/scripts/obtain_item.pory"
	playfanfare MUS_OBTAIN_ITEM
# 227 "data/scripts/obtain_item.pory"
	message gText_PlayerFoundOneItem
# 228 "data/scripts/obtain_item.pory"
	delay 10
# 229 "data/scripts/obtain_item.pory"
	waitfanfare
# 230 "data/scripts/obtain_item.pory"
	waitmessage
# 231 "data/scripts/obtain_item.pory"
	bufferitemnameplural 1, VAR_0x8004, VAR_0x8005
# 232 "data/scripts/obtain_item.pory"
	msgbox gText_ItemSentToPC, MSGBOX_DEFAULT
# 233 "data/scripts/obtain_item.pory"
	setvar VAR_RESULT, 1
# 234 "data/scripts/obtain_item.pory"
	return
# 235 "data/scripts/obtain_item.pory"

# 236 "data/scripts/obtain_item.pory"
EventScript_HiddenItemScript::
# 237 "data/scripts/obtain_item.pory"
	lockall
# 238 "data/scripts/obtain_item.pory"
	waitse
# 239 "data/scripts/obtain_item.pory"
    copyvar VAR_0x8006, VAR_0x8005
# 240 "data/scripts/obtain_item.pory"
	additem VAR_0x8005
# 241 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8007, VAR_RESULT
# 242 "data/scripts/obtain_item.pory"
	bufferitemnameplural 1, VAR_0x8005, 1
# 243 "data/scripts/obtain_item.pory"
	checkitemtype VAR_0x8005
# 244 "data/scripts/obtain_item.pory"
	call EventScript_BufferPocketNameAndTryFanfare
# 245 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 1
# 246 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_PickUpHiddenItem
# 247 "data/scripts/obtain_item.pory"
	compare VAR_0x8007, 0
# 248 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_NoRoomForHiddenItem
# 249 "data/scripts/obtain_item.pory"
	end
# 250 "data/scripts/obtain_item.pory"

# 251 "data/scripts/obtain_item.pory"
EventScript_PickUpHiddenItem::
# 252 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8008, VAR_0x8004
# 253 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8004, VAR_0x8005
# 254 "data/scripts/obtain_item.pory"
	specialvar VAR_RESULT, BufferTMHMMoveName
# 255 "data/scripts/obtain_item.pory"
	compare VAR_RESULT, 1
# 256 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_FoundHiddenTMHM
# 257 "data/scripts/obtain_item.pory"
	compare VAR_RESULT, 0
# 258 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_FoundHiddenItem
# 259 "data/scripts/obtain_item.pory"
	end
# 260 "data/scripts/obtain_item.pory"

# 261 "data/scripts/obtain_item.pory"
EventScript_FoundHiddenTMHM::
# 262 "data/scripts/obtain_item.pory"
	bufferitemnameplural 0, VAR_0x8004, 1
# 263 "data/scripts/obtain_item.pory"
	message gText_PlayerFoundOneTMHM
# 264 "data/scripts/obtain_item.pory"
	goto EventScript_PutHiddenItemInPocket
# 265 "data/scripts/obtain_item.pory"
	end
# 266 "data/scripts/obtain_item.pory"

# 267 "data/scripts/obtain_item.pory"
EventScript_FoundHiddenItem::
# 268 "data/scripts/obtain_item.pory"
	message gText_PlayerFoundOneItem
# 269 "data/scripts/obtain_item.pory"
	goto EventScript_PutHiddenItemInPocket
# 270 "data/scripts/obtain_item.pory"
	end
# 271 "data/scripts/obtain_item.pory"

# 272 "data/scripts/obtain_item.pory"
EventScript_PutHiddenItemInPocket::
# 273 "data/scripts/obtain_item.pory"
    delay 10
# 274 "data/scripts/obtain_item.pory"
    showitemdesc
# 275 "data/scripts/obtain_item.pory"
	waitmessage
# 276 "data/scripts/obtain_item.pory"
	waitfanfare
# 277 "data/scripts/obtain_item.pory"
	bufferitemnameplural 1, VAR_0x8004, 1
# 278 "data/scripts/obtain_item.pory"
	copyvar VAR_0x8004, VAR_0x8008
# 279 "data/scripts/obtain_item.pory"
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
# 280 "data/scripts/obtain_item.pory"
    hideitemdesc
# 281 "data/scripts/obtain_item.pory"
	special TryPutTreasureInvestigatorsOnAir
# 282 "data/scripts/obtain_item.pory"
	special SetHiddenItemFlag
# 283 "data/scripts/obtain_item.pory"
	releaseall
# 284 "data/scripts/obtain_item.pory"
	end
# 285 "data/scripts/obtain_item.pory"

# 286 "data/scripts/obtain_item.pory"
EventScript_NoRoomForHiddenItem::
# 287 "data/scripts/obtain_item.pory"
	addpcitem VAR_0x8005, 1
# 288 "data/scripts/obtain_item.pory"
	compare VAR_RESULT, 1
# 289 "data/scripts/obtain_item.pory"
	goto_if_eq EventScript_HiddenItemSentToPC
# 290 "data/scripts/obtain_item.pory"
	msgbox gText_PlayerFoundOneItem, MSGBOX_DEFAULT
# 291 "data/scripts/obtain_item.pory"
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
# 292 "data/scripts/obtain_item.pory"
	setvar VAR_RESULT, 0
# 293 "data/scripts/obtain_item.pory"
	releaseall
# 294 "data/scripts/obtain_item.pory"
	end
# 295 "data/scripts/obtain_item.pory"

# 296 "data/scripts/obtain_item.pory"
EventScript_HiddenItemSentToPC::
# 297 "data/scripts/obtain_item.pory"
	playfanfare MUS_OBTAIN_ITEM
# 298 "data/scripts/obtain_item.pory"
	message gText_PlayerFoundOneItem
# 299 "data/scripts/obtain_item.pory"
	delay 10
# 300 "data/scripts/obtain_item.pory"
	waitfanfare
# 301 "data/scripts/obtain_item.pory"
	waitmessage
# 302 "data/scripts/obtain_item.pory"
	bufferitemnameplural 1, VAR_0x8005, 1
# 303 "data/scripts/obtain_item.pory"
	msgbox gText_ItemSentToPC, MSGBOX_DEFAULT
# 304 "data/scripts/obtain_item.pory"
	special TryPutTreasureInvestigatorsOnAir
# 305 "data/scripts/obtain_item.pory"
	special SetHiddenItemFlag
# 306 "data/scripts/obtain_item.pory"
	setvar VAR_RESULT, 1
# 307 "data/scripts/obtain_item.pory"
	releaseall
# 308 "data/scripts/obtain_item.pory"
	end
