#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Sheer Cold deals resisted damage to Ice types regardless of legacy immunity config")
{
    u32 config;
    PARAMETRIZE { config = GEN_6; }
    PARAMETRIZE { config = GEN_7; }
    GIVEN {
        WITH_CONFIG(B_SHEER_COLD_IMMUNITY, config);
        ASSUME(!MoveHasNoEffectOnSameType(MOVE_SHEER_COLD));
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GLALIE) { HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, MOVE_SHEER_COLD); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SHEER_COLD, player);
        HP_BAR(opponent);
        MESSAGE("It's not very effective…");
    } THEN {
        EXPECT_GT(opponent->hp, 0);
        EXPECT_LT(opponent->hp, opponent->maxHP);
    }
}
