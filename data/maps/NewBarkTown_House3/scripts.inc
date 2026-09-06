# 1 "data/maps/NewBarkTown_House3/scripts.pory"

# 2 "data/maps/NewBarkTown_House3/scripts.pory"
NewBarkTown_House3_MapScripts::
# 3 "data/maps/NewBarkTown_House3/scripts.pory"
    map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_House3_OnTransition
# 4 "data/maps/NewBarkTown_House3/scripts.pory"
	.byte 0
# 5 "data/maps/NewBarkTown_House3/scripts.pory"

# 6 "data/maps/NewBarkTown_House3/scripts.pory"
NewBarkTown_House3_OnTransition::
# 7 "data/maps/NewBarkTown_House3/scripts.pory"
    call Common_EventScript_SetupRivalGfxId
# 8 "data/maps/NewBarkTown_House3/scripts.pory"
    end

NewBarkTown_RivalsMom::
# 12 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 13 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 14 "data/maps/NewBarkTown_House3/scripts.pory"
	checkplayergender
# 15 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_0
# 16 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_RivalsMom_2
# 27 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 4
	goto_if_ge NewBarkTown_RivalsMom_12
NewBarkTown_RivalsMom_10:
# 33 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_4
NewBarkTown_RivalsMom_1:
# 37 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsMom_2:
# 17 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 4
	goto_if_ge NewBarkTown_RivalsMom_7
NewBarkTown_RivalsMom_5:
# 23 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_2
	goto NewBarkTown_RivalsMom_1

NewBarkTown_RivalsMom_6:
# 18 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_1
# 20 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsMom_7:
# 17 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTown_RivalsMom_6
	goto NewBarkTown_RivalsMom_5

NewBarkTown_RivalsMom_11:
# 28 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsMom_Text_3
# 30 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsMom_12:
# 27 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTown_RivalsMom_11
	goto NewBarkTown_RivalsMom_10


NewBarkTown_RivalsSister::
# 42 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 43 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 44 "data/maps/NewBarkTown_House3/scripts.pory"
	checkplayergender
# 45 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, MALE
	goto_if_eq NewBarkTown_RivalsSister_2
# 50 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsSister_Text_1
NewBarkTown_RivalsSister_1:
# 54 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTown_RivalsSister_2:
# 46 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTown_RivalsSister_Text_0
	goto NewBarkTown_RivalsSister_1


NewBarkTownRivalHouseRival::
# 60 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 61 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 62 "data/maps/NewBarkTown_House3/scripts.pory"
	createfieldmugshotrival
# 63 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 12
	goto_if_lt NewBarkTownRivalHouseRival_2
# 69 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RIVAL_STATE, 12
	goto_if_ge NewBarkTownRivalHouseRival_5
NewBarkTownRivalHouseRival_4:
# 250 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_2:
# 64 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_0, MSGBOX_NPC
# 66 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_5:
# 70 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 7
	goto_if_ge NewBarkTownRivalHouseRival_9
NewBarkTownRivalHouseRival_7:
# 84 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto_if_ge NewBarkTownRivalHouseRival_14
NewBarkTownRivalHouseRival_12:
# 95 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 0
	goto_if_eq NewBarkTownRivalHouseRival_20
# 130 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 1
	goto_if_eq NewBarkTownRivalHouseRival_27
NewBarkTownRivalHouseRival_26:
# 134 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 2
	goto_if_eq NewBarkTownRivalHouseRival_30
NewBarkTownRivalHouseRival_29:
# 140 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 3
	goto_if_eq NewBarkTownRivalHouseRival_33
# 162 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
	goto_if_eq NewBarkTownRivalHouseRival_36
NewBarkTownRivalHouseRival_35:
# 167 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 5
	goto_if_eq NewBarkTownRivalHouseRival_39
NewBarkTownRivalHouseRival_38:
# 177 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 6
	goto_if_eq NewBarkTownRivalHouseRival_42
# 207 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 7
	goto_if_eq NewBarkTownRivalHouseRival_45
# 207 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 8
	goto_if_eq NewBarkTownRivalHouseRival_45
NewBarkTownRivalHouseRival_44:
# 212 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 7
	goto_if_eq NewBarkTownRivalHouseRival_53
# 212 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 8
	goto_if_eq NewBarkTownRivalHouseRival_53
# 223 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 9
	goto_if_eq NewBarkTownRivalHouseRival_65
# 245 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
	goto_if_eq NewBarkTownRivalHouseRival_67
	goto NewBarkTownRivalHouseRival_4

NewBarkTownRivalHouseRival_8:
# 71 "data/maps/NewBarkTown_House3/scripts.pory"
	checkitem ITEM_HM_DIVE
# 72 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_17
	goto NewBarkTownRivalHouseRival_7

NewBarkTownRivalHouseRival_9:
# 70 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
	goto_if_le NewBarkTownRivalHouseRival_8
	goto NewBarkTownRivalHouseRival_7

NewBarkTownRivalHouseRival_13:
# 85 "data/maps/NewBarkTown_House3/scripts.pory"
	getcaughtmon SPECIES_DARKRAI
# 86 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_22
	goto NewBarkTownRivalHouseRival_12

NewBarkTownRivalHouseRival_14:
# 84 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
	goto_if_le NewBarkTownRivalHouseRival_13
	goto NewBarkTownRivalHouseRival_12

NewBarkTownRivalHouseRival_17:
# 73 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_1
# 75 "data/maps/NewBarkTown_House3/scripts.pory"
	giveitem ITEM_HM_DIVE
# 76 "data/maps/NewBarkTown_House3/scripts.pory"
	createfieldmugshotrival
# 77 "data/maps/NewBarkTown_House3/scripts.pory"
	checkitem ITEM_HM_DIVE
# 78 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_24
	goto NewBarkTownRivalHouseRival_7

NewBarkTownRivalHouseRival_20:
# 96 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_3
# 126 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 1
# 127 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_22:
# 87 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_2
# 91 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_24:
# 79 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_27:
# 131 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_4
	goto NewBarkTownRivalHouseRival_26

NewBarkTownRivalHouseRival_30:
# 135 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_5
	goto NewBarkTownRivalHouseRival_29

NewBarkTownRivalHouseRival_33:
# 141 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_6
# 158 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 4
# 159 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_36:
# 163 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_7
	goto NewBarkTownRivalHouseRival_35

NewBarkTownRivalHouseRival_39:
# 168 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_8
# 175 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 6
	goto NewBarkTownRivalHouseRival_38

NewBarkTownRivalHouseRival_42:
# 178 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_9
# 190 "data/maps/NewBarkTown_House3/scripts.pory"
	checkitem ITEM_HM_DIVE
# 191 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_50
NewBarkTownRivalHouseRival_49:
# 194 "data/maps/NewBarkTown_House3/scripts.pory"
	checkitem ITEM_HM_DIVE
# 195 "data/maps/NewBarkTown_House3/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq NewBarkTownRivalHouseRival_62
# 199 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 7
# 200 "data/maps/NewBarkTown_House3/scripts.pory"
	createfieldmugshotrival
# 201 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_10
# 204 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_45:
# 208 "data/maps/NewBarkTown_House3/scripts.pory"
	goto_if_set FLAG_ONETIME_GROUDON, NewBarkTownRivalHouseRival_58
	goto NewBarkTownRivalHouseRival_44

NewBarkTownRivalHouseRival_50:
# 192 "data/maps/NewBarkTown_House3/scripts.pory"
	giveitem ITEM_HM_DIVE
	goto NewBarkTownRivalHouseRival_49

NewBarkTownRivalHouseRival_53:
# 213 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_11
# 220 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_57:
# 209 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 9
	goto NewBarkTownRivalHouseRival_44

NewBarkTownRivalHouseRival_58:
# 208 "data/maps/NewBarkTown_House3/scripts.pory"
	goto_if_set FLAG_ONETIME_KYOGRE, NewBarkTownRivalHouseRival_57
	goto NewBarkTownRivalHouseRival_44

NewBarkTownRivalHouseRival_62:
# 196 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_65:
# 224 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_12
# 237 "data/maps/NewBarkTown_House3/scripts.pory"
	giveitem ITEM_OVAL_CHARM
# 238 "data/maps/NewBarkTown_House3/scripts.pory"
	createfieldmugshotrival
# 239 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_13
# 241 "data/maps/NewBarkTown_House3/scripts.pory"
	setvar VAR_POSTGAME_RIVAL_LEGENDARYQ, 10
# 242 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end

NewBarkTownRivalHouseRival_67:
# 246 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseRival_Text_14
	goto NewBarkTownRivalHouseRival_4


NewBarkTownRivalHouseMarill::
# 256 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 257 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 258 "data/maps/NewBarkTown_House3/scripts.pory"
	playmoncry SPECIES_MARILL, CRY_MODE_NORMAL
# 259 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseMarill_Text_0
# 260 "data/maps/NewBarkTown_House3/scripts.pory"
	waitmoncry
# 261 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end


NewBarkTownRivalHouseAzumarill::
# 266 "data/maps/NewBarkTown_House3/scripts.pory"
	lock
# 267 "data/maps/NewBarkTown_House3/scripts.pory"
	faceplayer
# 268 "data/maps/NewBarkTown_House3/scripts.pory"
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
# 269 "data/maps/NewBarkTown_House3/scripts.pory"
	msgbox NewBarkTownRivalHouseAzumarill_Text_0
# 270 "data/maps/NewBarkTown_House3/scripts.pory"
	waitmoncry
# 271 "data/maps/NewBarkTown_House3/scripts.pory"
	release
	end


NewBarkTown_RivalsMom_Text_0:
# 15 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Oh, hello {PLAYER}!$"

NewBarkTown_RivalsMom_Text_1:
# 18 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Crystal is currently out, if you were\n"
	.string "looking for her.$"

NewBarkTown_RivalsMom_Text_2:
# 23 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Crystal is currently upstairs if\n"
	.string "you are looking for her. She is playing\l"
	.string "with her Pokémon.$"

NewBarkTown_RivalsMom_Text_3:
# 28 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Gold is currently out, if you were\n"
	.string "looking for him.$"

NewBarkTown_RivalsMom_Text_4:
# 33 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Gold is currently upstairs if\n"
	.string "you are looking for him. He is playing\l"
	.string "with his Pokémon.$"

NewBarkTown_RivalsSister_Text_0:
# 46 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Elm gave my sister a Marill, I hope I\n"
	.string "can get a Pokémon to play with \l"
	.string "soon, too!$"

NewBarkTown_RivalsSister_Text_1:
# 50 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Elm gave my brother a Marill, I hope I\n"
	.string "can get a Pokémon to play with \l"
	.string "soon, too!$"

NewBarkTownRivalHouseRival_Text_0:
# 64 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Hey {PLAYER}! Have you visited\n"
	.string "any new places?$"

NewBarkTownRivalHouseRival_Text_1:
# 73 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "You'll need this to explore the\n"
	.string "underwater areas of Johto!$"

NewBarkTownRivalHouseRival_Text_2:
# 87 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "We still need to investigate Darkrai.\p"
	.string "Take Cresselia to the old inn in\n"
	.string "Cherrygrove City!$"

NewBarkTownRivalHouseRival_Text_3:
# 96 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Hey {PLAYER}! What's up?\p"
	.string "So I've been doing some thinking, and\n"
	.string "decided that I want to help Prof. Elm.\l"
	.string "with his research into legendary\l"
	.string "Pokémon!\p"
	.string "I've started looking into old rumours\n"
	.string "and stories that are circulating in\l"
	.string "Johto, and I've found my first lead.\p"
	.string "If you got time and happen to be in the\n"
	.string "area, would you mind helping me by\l"
	.string "checking them out?\p"
	.string "The first legendary I'm researching\n"
	.string "right now concerns not one but two\l"
	.string "Pokémon actually!\p"
	.string "Have you heard about Darkrai and\n"
	.string "Cresselia?\p"
	.string "One causes nightmares while the other\n"
	.string "cures them, fascinating!\p"
	.string "I think we should track down Cresselia\n"
	.string "first, in order to locate Darkrai.\p"
	.string "I hear that someone living near or in\n"
	.string "the Lake of Rage might know more.$"

NewBarkTownRivalHouseRival_Text_4:
# 131 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "I hear that someone living near or in\n"
	.string "the Lake of Rage might know more.$"

NewBarkTownRivalHouseRival_Text_5:
# 135 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Oh you found Cresselia's location?\p"
	.string "That's great! You should catch it\n"
	.string "if you're able to!$"

NewBarkTownRivalHouseRival_Text_6:
# 141 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "You caught Cresselia? \n"
	.string "Nice!\p"
	.string "I've been researching Darkrai's\n"
	.string "meanwhile.\p"
	.string "I'm quite sure that it has something\n"
	.string "to do with the old, run down inn in\l"
	.string "Cherrygrove City.\p"
	.string "It was closed due to some child\n"
	.string "falling to sleep and not waking up, real\l"
	.string "bad press for the inn.\p"
	.string "So in short, take Cresselia with you\n"
	.string "and go check out the inn in Cherrygrove\l"
	.string "City. See if you can find out anything!$"

NewBarkTownRivalHouseRival_Text_7:
# 163 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Go check out the old inn in\n"
	.string "Cherrygrove City. Remember to\l"
	.string "take Cresselia with you!$"

NewBarkTownRivalHouseRival_Text_8:
# 168 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "You caught Darkrai! Excellent!\p"
	.string "You look like you just had a\n"
	.string "nightmare though, did something\l"
	.string "happen?\p"
	.string "Anyway!$"

NewBarkTownRivalHouseRival_Text_9:
# 178 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "{PLAYER}! I've found another lead\n"
	.string "on legendaries!\p"
	.string "Apparently, Hoenn's very own duo\n"
	.string "is resting somewhere underwater\l"
	.string "here in Johto.\p"
	.string "There aren't many deep waters in\n"
	.string "here, so you'll have to look quite\l"
	.string "hard for them.\p"
	.string "You're going to need this!$"

NewBarkTownRivalHouseRival_Text_10:
# 201 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "They are probably quite far away\n"
	.string "from each other, so you should\l"
	.string "scour the region far and wide.$"

NewBarkTownRivalHouseRival_Text_11:
# 213 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Groudon is likely hidden in a cave which\n"
	.string "can only be accessed underwater. Maybe\l"
	.string "close to a hotter climate?\p"
	.string "Kyogre might prefer easier access to\n"
	.string "the open sea. So check on the\l"
	.string "coastlines!$"

NewBarkTownRivalHouseRival_Text_12:
# 224 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "You caught them both?!\p"
	.string "Send me your Pokédex data about them\n"
	.string "later. Elm is going to be thrilled\l"
	.string "about this!\p"
	.string "There isn't anything currently I'm\n"
	.string "looking for, and it might take a long\l"
	.string "while before I find another target\l"
	.string "we could search for.\p"
	.string "I don't have much to give, but you\n"
	.string "can have this!$"

NewBarkTownRivalHouseRival_Text_13:
# 239 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "So, thanks {PLAYER}! For being\n"
	.string "a genuine friend!$"

NewBarkTownRivalHouseRival_Text_14:
# 246 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Hey {PLAYER}! How's it going?\n"
	.string "Caught any new special Pokémon?$"

NewBarkTownRivalHouseMarill_Text_0:
# 259 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Marii!$"

NewBarkTownRivalHouseAzumarill_Text_0:
# 269 "data/maps/NewBarkTown_House3/scripts.pory"
	.string "Azumarill: Azuu!$"
