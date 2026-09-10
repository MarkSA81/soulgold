#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Former OHKO moves deal normal damage with No Guard and require one recharge turn")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_GUILLOTINE; }
    PARAMETRIZE { move = MOVE_HORN_DRILL; }
    PARAMETRIZE { move = MOVE_FISSURE; }
    PARAMETRIZE { move = MOVE_SHEER_COLD; }
    GIVEN {
        ASSUME(GetMoveEffect(move) == EFFECT_HIT);
        ASSUME(GetMovePower(move) == 150);
        ASSUME(GetMoveAccuracy(move) == 90);
        ASSUME(GetMovePP(move) == 5);
        ASSUME(MoveHasAdditionalEffectSelf(move, MOVE_EFFECT_RECHARGE));
        PLAYER(SPECIES_MACHAMP) { Level(50); Ability(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET) { Level(100); HP(1000); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, move); }
        TURN { SKIP_TURN(player); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        MESSAGE("Machamp must recharge!");
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    } THEN {
        EXPECT_GT(opponent->hp, 0);
        EXPECT_LT(opponent->hp, opponent->maxHP);
    }
}

SINGLE_BATTLE_TEST("Former OHKO moves do not require recharge after missing or Protect")
{
    enum Move move;
    bool32 protect;
    PARAMETRIZE { move = MOVE_GUILLOTINE; protect = FALSE; }
    PARAMETRIZE { move = MOVE_GUILLOTINE; protect = TRUE; }
    PARAMETRIZE { move = MOVE_HORN_DRILL; protect = FALSE; }
    PARAMETRIZE { move = MOVE_HORN_DRILL; protect = TRUE; }
    PARAMETRIZE { move = MOVE_FISSURE; protect = FALSE; }
    PARAMETRIZE { move = MOVE_FISSURE; protect = TRUE; }
    PARAMETRIZE { move = MOVE_SHEER_COLD; protect = FALSE; }
    PARAMETRIZE { move = MOVE_SHEER_COLD; protect = TRUE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        if (protect)
            TURN { MOVE(opponent, MOVE_PROTECT); MOVE(player, move); }
        else
            TURN { MOVE(player, move, hit: FALSE); }
        TURN { MOVE(player, MOVE_TACKLE); }
    } SCENE {
        NONE_OF {
            ANIMATION(ANIM_TYPE_MOVE, move, player);
            MESSAGE("Wobbuffet must recharge!");
        }
        ANIMATION(ANIM_TYPE_MOVE, MOVE_TACKLE, player);
    }
}

SINGLE_BATTLE_TEST("Former OHKO moves can damage Sturdy targets below full HP")
{
    enum Move move;
    PARAMETRIZE { move = MOVE_GUILLOTINE; }
    PARAMETRIZE { move = MOVE_HORN_DRILL; }
    PARAMETRIZE { move = MOVE_FISSURE; }
    PARAMETRIZE { move = MOVE_SHEER_COLD; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_STURDY); HP(999); MaxHP(1000); }
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, move, player);
        HP_BAR(opponent);
        NOT ABILITY_POPUP(opponent, ABILITY_STURDY);
    } THEN {
        EXPECT_GT(opponent->hp, 0);
        EXPECT_LT(opponent->hp, 999);
    }
}

#if MAX_MON_TRAITS > 1
SINGLE_BATTLE_TEST("Mega Pinsir's innate No Guard does not make Guillotine an instant KO")
{
    GIVEN {
        PLAYER(SPECIES_PINSIR_MEGA) { Ability(ABILITY_AERILATE); Innates(ABILITY_NO_GUARD); }
        OPPONENT(SPECIES_WOBBUFFET) { HP(1000); MaxHP(1000); Defense(500); }
    } WHEN {
        TURN { MOVE(player, MOVE_GUILLOTINE); }
        TURN { SKIP_TURN(player); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_GUILLOTINE, player);
        HP_BAR(opponent);
        MESSAGE("Pinsir must recharge!");
    } THEN {
        EXPECT_GT(opponent->hp, 0);
        EXPECT_LT(opponent->hp, opponent->maxHP);
    }
}
#endif
