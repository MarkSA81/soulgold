# 1 "data/maps/OlivineCity/scripts.pory"

# 2 "data/maps/OlivineCity/scripts.pory"

# 3 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScripts::
# 4 "data/maps/OlivineCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
# 5 "data/maps/OlivineCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
# 6 "data/maps/OlivineCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
# 7 "data/maps/OlivineCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, OlivineCity_OnLoad
# 8 "data/maps/OlivineCity/scripts.pory"
	.byte 0
# 9 "data/maps/OlivineCity/scripts.pory"

# 10 "data/maps/OlivineCity/scripts.pory"
OlivineCity_OnLoad::
# 11 "data/maps/OlivineCity/scripts.pory"
	setrespawn HEAL_LOCATION_OLIVINE_CITY
# 12 "data/maps/OlivineCity/scripts.pory"
	end
# 13 "data/maps/OlivineCity/scripts.pory"

# 14 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScript_OnTransition::
# 15 "data/maps/OlivineCity/scripts.pory"
	call Common_EventScript_CheckElmRocketCall
# 16 "data/maps/OlivineCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 17 "data/maps/OlivineCity/scripts.pory"
	goto OlivineCity_MapScript_CheckWeather
# 18 "data/maps/OlivineCity/scripts.pory"

# 19 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScript_CheckWeather::
# 20 "data/maps/OlivineCity/scripts.pory"
	callnative SetTimeBasedEncounters
# 21 "data/maps/OlivineCity/scripts.pory"
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
# 22 "data/maps/OlivineCity/scripts.pory"
	end
# 23 "data/maps/OlivineCity/scripts.pory"

# 24 "data/maps/OlivineCity/scripts.pory"
OlivineCity_MapScript_ClearWeather::
# 25 "data/maps/OlivineCity/scripts.pory"
	setweather WEATHER_NONE
# 26 "data/maps/OlivineCity/scripts.pory"
	end
# 27 "data/maps/OlivineCity/scripts.pory"

# 28 "data/maps/OlivineCity/scripts.pory"
OlivineCity_OnFrame::
# 29 "data/maps/OlivineCity/scripts.pory"
	map_script_2 VAR_TEMP_F, 1, Mahoganytown_EventScript_RocketTrigger
# 30 "data/maps/OlivineCity/scripts.pory"
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
# 31 "data/maps/OlivineCity/scripts.pory"
	.2byte 0
# 32 "data/maps/OlivineCity/scripts.pory"

# 33 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_BaobaCall::
# 34 "data/maps/OlivineCity/scripts.pory"
	lock
# 35 "data/maps/OlivineCity/scripts.pory"
	pokenavcall OlivineCity_Text_Baoba
# 36 "data/maps/OlivineCity/scripts.pory"
	waitmessage
# 37 "data/maps/OlivineCity/scripts.pory"
	delay 30
# 38 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
# 39 "data/maps/OlivineCity/scripts.pory"
	release
# 40 "data/maps/OlivineCity/scripts.pory"
	end
# 41 "data/maps/OlivineCity/scripts.pory"

# 42 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Baoba:
# 43 "data/maps/OlivineCity/scripts.pory"
	.string "{PLAYER}!\p"
# 44 "data/maps/OlivineCity/scripts.pory"
	.string "This is Warden Baoba.\p"
# 45 "data/maps/OlivineCity/scripts.pory"
	.string "Sorry to have kept you waiting.\n"
# 46 "data/maps/OlivineCity/scripts.pory"
	.string "We've finally opened the Safari\l"
# 47 "data/maps/OlivineCity/scripts.pory"
	.string "Zone!\p"
# 48 "data/maps/OlivineCity/scripts.pory"
	.string "Do you know where it is?\p"
# 49 "data/maps/OlivineCity/scripts.pory"
	.string "You know the Gate inside the cavern\n"
# 50 "data/maps/OlivineCity/scripts.pory"
	.string "in Cianwood City?\p"
# 51 "data/maps/OlivineCity/scripts.pory"
	.string "If you go through there and walk for\n"
# 52 "data/maps/OlivineCity/scripts.pory"
	.string "a short while, you should soon see\l"
# 53 "data/maps/OlivineCity/scripts.pory"
	.string "the Safari Zone!\p"
# 54 "data/maps/OlivineCity/scripts.pory"
	.string "We're a little out of the way, but\n"
# 55 "data/maps/OlivineCity/scripts.pory"
	.string "please come visit!$"
# 56 "data/maps/OlivineCity/scripts.pory"

# 57 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
# 58 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
# 59 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_SILVER
# 60 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_VISITED_OLIVINE_CITY
# 61 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
# 62 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
# 63 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
# 64 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_GETFLY, 0
# 65 "data/maps/OlivineCity/scripts.pory"

# 66 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 1
# 67 "data/maps/OlivineCity/scripts.pory"

# 68 "data/maps/OlivineCity/scripts.pory"
	@cianwood flags
# 69 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_SUICUNE_ENCOUNTERS, 1
# 70 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
# 71 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_CIANWOOD_EUSINE
# 72 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_CIANWOOD_CITY_STATE, 1
# 73 "data/maps/OlivineCity/scripts.pory"
	end
# 74 "data/maps/OlivineCity/scripts.pory"

# 75 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverTrigger::
# 76 "data/maps/OlivineCity/scripts.pory"
	lock
# 77 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_OLIVINE_SILVER
# 78 "data/maps/OlivineCity/scripts.pory"
	opendoor 11, 27
# 79 "data/maps/OlivineCity/scripts.pory"
	addobject LOCALID_OLIVINE_SILVER
# 80 "data/maps/OlivineCity/scripts.pory"
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
# 81 "data/maps/OlivineCity/scripts.pory"
	delay 20
# 82 "data/maps/OlivineCity/scripts.pory"
	closedoor 11, 27
# 83 "data/maps/OlivineCity/scripts.pory"
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
# 84 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
# 85 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
# 86 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
# 87 "data/maps/OlivineCity/scripts.pory"
	createfieldmugshot MUGSHOT_SILVER
# 88 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
# 89 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 90 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
# 91 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
# 92 "data/maps/OlivineCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
# 93 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
# 94 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 95 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_OLIVINE_CITY_STATE, 2
# 96 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_SILVER
# 97 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_MAREANIES
# 98 "data/maps/OlivineCity/scripts.pory"
	removeobject LOCALID_OLIVINE_SILVER
# 99 "data/maps/OlivineCity/scripts.pory"
	fadedefaultbgm
# 100 "data/maps/OlivineCity/scripts.pory"
	release
# 101 "data/maps/OlivineCity/scripts.pory"
	end
# 102 "data/maps/OlivineCity/scripts.pory"

# 103 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer1::
# 104 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
# 105 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 106 "data/maps/OlivineCity/scripts.pory"
	return
# 107 "data/maps/OlivineCity/scripts.pory"

# 108 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer2::
# 109 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
# 110 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 111 "data/maps/OlivineCity/scripts.pory"
	return
# 112 "data/maps/OlivineCity/scripts.pory"

# 113 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverWalkToPlayer3::
# 114 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
# 115 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 116 "data/maps/OlivineCity/scripts.pory"
	return
# 117 "data/maps/OlivineCity/scripts.pory"

# 118 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverLeaveAdjust1::
# 119 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
# 120 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 121 "data/maps/OlivineCity/scripts.pory"
	return
# 122 "data/maps/OlivineCity/scripts.pory"

# 123 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_SilverLeaveAdjust2::
# 124 "data/maps/OlivineCity/scripts.pory"
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
# 125 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 126 "data/maps/OlivineCity/scripts.pory"
	return
# 127 "data/maps/OlivineCity/scripts.pory"

# 128 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer1:
# 129 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 130 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 131 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 132 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 133 "data/maps/OlivineCity/scripts.pory"
	step_end
# 134 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer2:
# 135 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 136 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 137 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 138 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 139 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 140 "data/maps/OlivineCity/scripts.pory"
	step_end
# 141 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverWalkToPlayer3:
# 142 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 143 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 144 "data/maps/OlivineCity/scripts.pory"
	walk_down
# 145 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 146 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 147 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 148 "data/maps/OlivineCity/scripts.pory"
	step_end
# 149 "data/maps/OlivineCity/scripts.pory"

# 150 "data/maps/OlivineCity/scripts.pory"

# 151 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Movement_SilverLeave:
# 152 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 153 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 154 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 155 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 156 "data/maps/OlivineCity/scripts.pory"
	walk_right
# 157 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 158 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 159 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 160 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 161 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 162 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 163 "data/maps/OlivineCity/scripts.pory"
	walk_up
# 164 "data/maps/OlivineCity/scripts.pory"
	step_end
# 165 "data/maps/OlivineCity/scripts.pory"

# 166 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_SilverEncounter:
# 167 "data/maps/OlivineCity/scripts.pory"
	.string "You again?\n"
# 168 "data/maps/OlivineCity/scripts.pory"
	.string "There's no need to be alert.\p"
# 169 "data/maps/OlivineCity/scripts.pory"
	.string "I don't bother with wimps\n"
# 170 "data/maps/OlivineCity/scripts.pory"
	.string "like you.\p"
# 171 "data/maps/OlivineCity/scripts.pory"
	.string "Speaking of weaklings, the\n"
# 172 "data/maps/OlivineCity/scripts.pory"
	.string "city's Gym Leader isn't here,\l"
# 173 "data/maps/OlivineCity/scripts.pory"
	.string "and is supposedly taking care\l"
# 174 "data/maps/OlivineCity/scripts.pory"
	.string "of a sick Pokémon at the\l"
# 175 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse.\p"
# 176 "data/maps/OlivineCity/scripts.pory"
	.string "Humph! Boo-hoo!\n"
# 177 "data/maps/OlivineCity/scripts.pory"
	.string "Just let sick Pokémon go!\p"
# 178 "data/maps/OlivineCity/scripts.pory"
	.string "A Pokémon that can't battle\n"
# 179 "data/maps/OlivineCity/scripts.pory"
	.string "is worthless!\p"
# 180 "data/maps/OlivineCity/scripts.pory"
	.string "Why don't you go train at the\n"
# 181 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse?\p"
# 182 "data/maps/OlivineCity/scripts.pory"
	.string "Who knows? It may make you a\n"
# 183 "data/maps/OlivineCity/scripts.pory"
	.string "bit of a better Trainer!$"
# 184 "data/maps/OlivineCity/scripts.pory"

# 185 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sailor1::
# 186 "data/maps/OlivineCity/scripts.pory"
	lock
# 187 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 188 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
# 189 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 190 "data/maps/OlivineCity/scripts.pory"
	release
# 191 "data/maps/OlivineCity/scripts.pory"
	end
# 192 "data/maps/OlivineCity/scripts.pory"

# 193 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sailor2::
# 194 "data/maps/OlivineCity/scripts.pory"
	lock
# 195 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 196 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
# 197 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 198 "data/maps/OlivineCity/scripts.pory"
	release
# 199 "data/maps/OlivineCity/scripts.pory"
	end
# 200 "data/maps/OlivineCity/scripts.pory"

# 201 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Youngster::
# 202 "data/maps/OlivineCity/scripts.pory"
	lock
# 203 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 204 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
# 205 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 206 "data/maps/OlivineCity/scripts.pory"
	release
# 207 "data/maps/OlivineCity/scripts.pory"
	end
# 208 "data/maps/OlivineCity/scripts.pory"

# 209 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Machoke::
# 210 "data/maps/OlivineCity/scripts.pory"
	lock
# 211 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 212 "data/maps/OlivineCity/scripts.pory"
	waitse
# 213 "data/maps/OlivineCity/scripts.pory"
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
# 214 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
# 215 "data/maps/OlivineCity/scripts.pory"
	waitmoncry
# 216 "data/maps/OlivineCity/scripts.pory"
	release
# 217 "data/maps/OlivineCity/scripts.pory"
	end
# 218 "data/maps/OlivineCity/scripts.pory"

# 219 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_Sign::
# 220 "data/maps/OlivineCity/scripts.pory"
	lock
# 221 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
# 222 "data/maps/OlivineCity/scripts.pory"
	end
# 223 "data/maps/OlivineCity/scripts.pory"

# 224 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_PortSign::
# 225 "data/maps/OlivineCity/scripts.pory"
	lock
# 226 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
# 227 "data/maps/OlivineCity/scripts.pory"
	end
# 228 "data/maps/OlivineCity/scripts.pory"

# 229 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_CafeSign::
# 230 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
# 231 "data/maps/OlivineCity/scripts.pory"
	end
# 232 "data/maps/OlivineCity/scripts.pory"

# 233 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_GymSign::
# 234 "data/maps/OlivineCity/scripts.pory"
	lock
# 235 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
# 236 "data/maps/OlivineCity/scripts.pory"
	end
# 237 "data/maps/OlivineCity/scripts.pory"

# 238 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_LighthouseSign::
# 239 "data/maps/OlivineCity/scripts.pory"
	lock
# 240 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
# 241 "data/maps/OlivineCity/scripts.pory"
	end
# 242 "data/maps/OlivineCity/scripts.pory"

# 243 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWoman::
# 244 "data/maps/OlivineCity/scripts.pory"
	lock
# 245 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 246 "data/maps/OlivineCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 247 "data/maps/OlivineCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
# 248 "data/maps/OlivineCity/scripts.pory"
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
# 249 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
# 250 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 251 "data/maps/OlivineCity/scripts.pory"
	release
# 252 "data/maps/OlivineCity/scripts.pory"
	end
# 253 "data/maps/OlivineCity/scripts.pory"

# 254 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWomanChamp::
# 255 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
# 256 "data/maps/OlivineCity/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 257 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 258 "data/maps/OlivineCity/scripts.pory"
	release
# 259 "data/maps/OlivineCity/scripts.pory"
	end
# 260 "data/maps/OlivineCity/scripts.pory"

# 261 "data/maps/OlivineCity/scripts.pory"
OlivineCity_EventScript_EonTicketWomanAfter::
# 262 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
# 263 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 264 "data/maps/OlivineCity/scripts.pory"
	release
# 265 "data/maps/OlivineCity/scripts.pory"
	end
# 266 "data/maps/OlivineCity/scripts.pory"

# 267 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_CafeSign:
# 268 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Cafe\n"
# 269 "data/maps/OlivineCity/scripts.pory"
	.string "Where Strong Sailors Enjoy\l"
# 270 "data/maps/OlivineCity/scripts.pory"
	.string "Hearty Meals Of Strength$"
# 271 "data/maps/OlivineCity/scripts.pory"

# 272 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman1:
# 273 "data/maps/OlivineCity/scripts.pory"
	.string "My name is Mary!\p"
# 274 "data/maps/OlivineCity/scripts.pory"
	.string "Just kidding, but I love Mary's\n"
# 275 "data/maps/OlivineCity/scripts.pory"
	.string "radio show!$"
# 276 "data/maps/OlivineCity/scripts.pory"

# 277 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman2:
# 278 "data/maps/OlivineCity/scripts.pory"
	.string "You must be {PLAYER}!!!\p"
# 279 "data/maps/OlivineCity/scripts.pory"
	.string "Oh my goodness! The champion!\p"
# 280 "data/maps/OlivineCity/scripts.pory"
	.string "I heard about you on Mary's\n"
# 281 "data/maps/OlivineCity/scripts.pory"
	.string "radio show!\p"
# 282 "data/maps/OlivineCity/scripts.pory"
	.string "Here, take this!$"
# 283 "data/maps/OlivineCity/scripts.pory"

# 284 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_EonTicketWoman3:
# 285 "data/maps/OlivineCity/scripts.pory"
	.string "I can't believe I met the\n"
# 286 "data/maps/OlivineCity/scripts.pory"
	.string "champion!!!$"
# 287 "data/maps/OlivineCity/scripts.pory"

# 288 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sailor1:
# 289 "data/maps/OlivineCity/scripts.pory"
	.string "Dark roads are dangerous\n"
# 290 "data/maps/OlivineCity/scripts.pory"
	.string "at night.\p"
# 291 "data/maps/OlivineCity/scripts.pory"
	.string "But in the pitch-black of\n"
# 292 "data/maps/OlivineCity/scripts.pory"
	.string "night, the sea is even more\l"
# 293 "data/maps/OlivineCity/scripts.pory"
	.string "treacherous!\p"
# 294 "data/maps/OlivineCity/scripts.pory"
	.string "Without the beacon of the\n"
# 295 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse to guide it,\l"
# 296 "data/maps/OlivineCity/scripts.pory"
	.string "no ship can sail.$"
# 297 "data/maps/OlivineCity/scripts.pory"

# 298 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_YoungsterPokegear:
# 299 "data/maps/OlivineCity/scripts.pory"
	.string "That thing you have--\n"
# 300 "data/maps/OlivineCity/scripts.pory"
	.string "it's a Pokégear, right?\l"
# 301 "data/maps/OlivineCity/scripts.pory"
	.string "Wow, that's cool.$"
# 302 "data/maps/OlivineCity/scripts.pory"

# 303 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_YoungsterPokedex:
# 304 "data/maps/OlivineCity/scripts.pory"
	.string "Wow, you have a Pokédex!\p"
# 305 "data/maps/OlivineCity/scripts.pory"
	.string "That is just so awesome.$"
# 306 "data/maps/OlivineCity/scripts.pory"

# 307 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sailor2:
# 308 "data/maps/OlivineCity/scripts.pory"
	.string "The league has Jasmine\n"
# 309 "data/maps/OlivineCity/scripts.pory"
	.string "pegged as the sixth\l"
# 310 "data/maps/OlivineCity/scripts.pory"
	.string "strongest Gym Leader!\p"
# 311 "data/maps/OlivineCity/scripts.pory"
	.string "Hah! That's a load of crud.\p"
# 312 "data/maps/OlivineCity/scripts.pory"
	.string "There's no way Pryce could\n"
# 313 "data/maps/OlivineCity/scripts.pory"
	.string "hurt Jasmine's Steel-type\l"
# 314 "data/maps/OlivineCity/scripts.pory"
	.string "Pokémon!\p"
# 315 "data/maps/OlivineCity/scripts.pory"
	.string "Bureaucracy if you ask me.\p"
# 316 "data/maps/OlivineCity/scripts.pory"
	.string "She's something to be feared,\n"
# 317 "data/maps/OlivineCity/scripts.pory"
	.string "that's for sure!$"
# 318 "data/maps/OlivineCity/scripts.pory"

# 319 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Sign:
# 320 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine City\p"
# 321 "data/maps/OlivineCity/scripts.pory"
	.string "The Port Closest to Foreign Lands$"
# 322 "data/maps/OlivineCity/scripts.pory"

# 323 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_PortSign:
# 324 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Port\n"
# 325 "data/maps/OlivineCity/scripts.pory"
	.string "Fast Ship Pier$"
# 326 "data/maps/OlivineCity/scripts.pory"

# 327 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_GymSign:
# 328 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine City Pokémon Gym\n"
# 329 "data/maps/OlivineCity/scripts.pory"
	.string "Leader: Jasmine\p"
# 330 "data/maps/OlivineCity/scripts.pory"
	.string "The Steel-Clad Defense Girl$"
# 331 "data/maps/OlivineCity/scripts.pory"

# 332 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_LighthouseSign:
# 333 "data/maps/OlivineCity/scripts.pory"
	.string "Olivine Lighthouse\n"
# 334 "data/maps/OlivineCity/scripts.pory"
	.string "Also known as the Glitter\l"
# 335 "data/maps/OlivineCity/scripts.pory"
	.string "Lighthouse$"
# 336 "data/maps/OlivineCity/scripts.pory"

# 337 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_BattleTowerSign:
# 338 "data/maps/OlivineCity/scripts.pory"
	.string "Battle Tower Ahead\n"
# 339 "data/maps/OlivineCity/scripts.pory"
	.string "Opening Now!$"
# 340 "data/maps/OlivineCity/scripts.pory"

# 341 "data/maps/OlivineCity/scripts.pory"
OlivineCity_Text_Machoke:
# 342 "data/maps/OlivineCity/scripts.pory"
	.string "Machoke: Cho!$"

OlivineCity_Littlegirl_Warf::
# 346 "data/maps/OlivineCity/scripts.pory"
	lock
# 347 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 348 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_Littlegirl_Warf_Text_0
# 350 "data/maps/OlivineCity/scripts.pory"
	release
	end


MareanieOlivine::
# 355 "data/maps/OlivineCity/scripts.pory"
	lock
# 356 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 357 "data/maps/OlivineCity/scripts.pory"
	playmoncry SPECIES_MAREANIE, CRY_MODE_NORMAL
# 358 "data/maps/OlivineCity/scripts.pory"
	msgbox MareanieOlivine_Text_0
# 359 "data/maps/OlivineCity/scripts.pory"
	waitmoncry
# 360 "data/maps/OlivineCity/scripts.pory"
	release
	end


OlivineSouvenirMart::
# 365 "data/maps/OlivineCity/scripts.pory"
	lock
# 366 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 367 "data/maps/OlivineCity/scripts.pory"
	message OlivineSouvenirMart_Text_0
# 368 "data/maps/OlivineCity/scripts.pory"
	waitmessage
# 369 "data/maps/OlivineCity/scripts.pory"
	pokemart SouvenirMart
# 370 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineSouvenirMart_Text_1
# 371 "data/maps/OlivineCity/scripts.pory"
	release
	end


	.align 2
# 375 "data/maps/OlivineCity/scripts.pory"
SouvenirMart:
# 376 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_STRANGE_SOUVENIR
# 377 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_UNREMARKABLE_TEACUP
# 378 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_MASTERPIECE_TEACUP
# 379 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_UTILITY_UMBRELLA
# 380 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_RED_NECTAR
# 381 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_YELLOW_NECTAR
# 382 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_PINK_NECTAR
# 383 "data/maps/OlivineCity/scripts.pory"
	.2byte ITEM_PURPLE_NECTAR
	.2byte ITEM_NONE

OlivineCity_RivalPier::
# 387 "data/maps/OlivineCity/scripts.pory"
	lock
# 388 "data/maps/OlivineCity/scripts.pory"
	faceplayer
# 389 "data/maps/OlivineCity/scripts.pory"
	createfieldmugshotrival
# 390 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_0
# 392 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_1
# 394 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_2
# 396 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_3
# 398 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_4
# 400 "data/maps/OlivineCity/scripts.pory"
	msgbox OlivineCity_RivalPier_Text_5
# 401 "data/maps/OlivineCity/scripts.pory"
	removefieldmugshot
# 402 "data/maps/OlivineCity/scripts.pory"
	closemessage
# 403 "data/maps/OlivineCity/scripts.pory"
	moveobjecttocoords LOCALID_OLIVINE_RIVAL, 19, 49, DIR_NORTH
# 404 "data/maps/OlivineCity/scripts.pory"
	waitmovement 0
# 405 "data/maps/OlivineCity/scripts.pory"
	setvar VAR_RIVAL_STATE, 9
# 406 "data/maps/OlivineCity/scripts.pory"
	setflag FLAG_HIDE_OLIVINE_RIVAL
# 407 "data/maps/OlivineCity/scripts.pory"
	removeobject LOCALID_OLIVINE_RIVAL
# 408 "data/maps/OlivineCity/scripts.pory"
	clearflag FLAG_HIDE_ICEPATH_RIVAL
# 409 "data/maps/OlivineCity/scripts.pory"
	release
	end


OlivineCity_Littlegirl_Warf_Text_0:
# 348 "data/maps/OlivineCity/scripts.pory"
	.string "I'm feeding the Mareanie every day!\n"
	.string "They sometimes let me play with them!$"

MareanieOlivine_Text_0:
# 358 "data/maps/OlivineCity/scripts.pory"
	.string "Maree!$"

OlivineSouvenirMart_Text_0:
# 367 "data/maps/OlivineCity/scripts.pory"
	.string "Welcome! How may I help you?$"

OlivineSouvenirMart_Text_1:
# 370 "data/maps/OlivineCity/scripts.pory"
	.string "Come back soon!$"

OlivineCity_RivalPier_Text_0:
# 390 "data/maps/OlivineCity/scripts.pory"
	.string "Oh. \n"
	.string "Hey...$"

OlivineCity_RivalPier_Text_1:
# 392 "data/maps/OlivineCity/scripts.pory"
	.string "Do you ever think that some people are\n"
	.string "just not... built for this?$"

OlivineCity_RivalPier_Text_2:
# 394 "data/maps/OlivineCity/scripts.pory"
	.string "Like it comes naturally\n"
	.string "and for others it's just...$"

OlivineCity_RivalPier_Text_3:
# 396 "data/maps/OlivineCity/scripts.pory"
	.string "Never mind.\n"
	.string "It's a dumb question.$"

OlivineCity_RivalPier_Text_4:
# 398 "data/maps/OlivineCity/scripts.pory"
	.string "Jasmine's Gym is closed.\n"
	.string "You're already on it, I assume.$"

OlivineCity_RivalPier_Text_5:
# 400 "data/maps/OlivineCity/scripts.pory"
	.string "See you around.$"
