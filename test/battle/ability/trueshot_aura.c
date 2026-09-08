#include "global.h"
#include "test/battle.h"
#include "battle_util.h"
#include "battle_ai_util.h"

ASSUMPTIONS
{
    ASSUME(gSpeciesInfo[SPECIES_INTELEON].innates[2] == ABILITY_TRUESHOT_AURA);
    ASSUME(gSpeciesInfo[SPECIES_INTELEON].abilities[2] == ABILITY_SNIPER);
    ASSUME(gSpeciesInfo[SPECIES_INTELEON_GMAX].abilities[0] == ABILITY_SNIPER);
    ASSUME(gSpeciesInfo[SPECIES_INTELEON_GMAX].abilities[1] == ABILITY_SNIPER);
    ASSUME(gSpeciesInfo[SPECIES_INTELEON_GMAX].abilities[2] == ABILITY_SNIPER);
    ASSUME(gSpeciesInfo[SPECIES_INTELEON_GMAX].innates[2] == ABILITY_TRUESHOT_AURA);
}

SINGLE_BATTLE_TEST("Trueshot Aura raises own critical-hit ratio by two stages")
{
    enum Ability ability = ABILITY_NONE, innate = ABILITY_NONE;
    PARAMETRIZE { ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_NONE; innate = ABILITY_TRUESHOT_AURA; }
    PASSES_RANDOMLY(1, 2, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Innates(innate); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

DOUBLE_BATTLE_TEST("Trueshot Aura raises ally critical-hit ratio by two stages without stacking")
{
    enum Ability ability, innate, allyAbility;
    PARAMETRIZE { ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; allyAbility = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_NONE; innate = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_TRUESHOT_AURA; }
    PASSES_RANDOMLY(1, 2, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, GEN_7);
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Innates(innate); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(allyAbility); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Trueshot Aura stacks with Super Luck, Scope Lens and high-crit moves")
{
    enum Ability innate;
    enum Item item;
    enum Move move;
    PARAMETRIZE { innate = ABILITY_SUPER_LUCK; item = ITEM_NONE; move = MOVE_SCRATCH; }
    PARAMETRIZE { innate = ABILITY_NONE; item = ITEM_SCOPE_LENS; move = MOVE_SCRATCH; }
    PARAMETRIZE { innate = ABILITY_NONE; item = ITEM_NONE; move = MOVE_SLASH; }
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, GEN_7);
        PLAYER(SPECIES_INTELEON_GMAX) { Ability(ABILITY_TRUESHOT_AURA); Innates(innate); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, move); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

SINGLE_BATTLE_TEST("Trueshot Aura does not boost damage and preserves the holder's Sniper", s16 damage)
{
    enum Ability ability = ABILITY_NONE, innate = ABILITY_NONE;
    bool32 critical = FALSE;
    for (u32 j = FALSE; j <= TRUE; j++) {
        PARAMETRIZE { critical = j; ability = ABILITY_NONE; innate = ABILITY_NONE; }
        PARAMETRIZE { critical = j; ability = ABILITY_SNIPER; innate = ABILITY_NONE; }
        PARAMETRIZE { critical = j; ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; }
        PARAMETRIZE { critical = j; ability = ABILITY_NONE; innate = ABILITY_TRUESHOT_AURA; }
        PARAMETRIZE { critical = j; ability = ABILITY_SNIPER; innate = ABILITY_TRUESHOT_AURA; }
    }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Innates(innate); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, criticalHit: critical); }
    } SCENE {
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        for (u32 j = 1; j < 5; j++)
            EXPECT_EQ(results[0].damage, results[j].damage);
        EXPECT_MUL_EQ(results[5].damage, UQ_4_12(1.5), results[6].damage);
        EXPECT_EQ(results[5].damage, results[7].damage);
        EXPECT_EQ(results[5].damage, results[8].damage);
        EXPECT_EQ(results[6].damage, results[9].damage);
    }
}

DOUBLE_BATTLE_TEST("Trueshot Aura does not grant allies Sniper damage", s16 damage)
{
    enum Ability ability, innate, allyAbility;
    PARAMETRIZE { ability = ABILITY_NONE; innate = ABILITY_NONE; allyAbility = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; allyAbility = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_NONE; innate = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; allyAbility = ABILITY_SNIPER; }
    PARAMETRIZE { ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; allyAbility = ABILITY_TRUESHOT_AURA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Innates(innate); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(allyAbility); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft, criticalHit: TRUE); }
    } SCENE {
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.5), results[3].damage);
        EXPECT_EQ(results[0].damage, results[4].damage);
    }
}

DOUBLE_BATTLE_TEST("Trueshot Aura does not boost opponents", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_NONE; }
    PARAMETRIZE { ability = ABILITY_TRUESHOT_AURA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); }
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponentLeft, MOVE_SCRATCH, target: playerRight, criticalHit: TRUE); }
    } SCENE {
        HP_BAR(playerRight, captureDamage: &results[i].damage);
    } THEN {
        struct BattleContext ctx = {0};
        ctx.battlerAtk = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        ctx.battlerDef = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        ctx.move = MOVE_SCRATCH;
        EXPECT_EQ(CalcCritChanceStage(&ctx), 0);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
    }
}

DOUBLE_BATTLE_TEST("Trueshot Aura stops when its source switches, faints or is suppressed")
{
    u32 removal;
    enum Ability ability = ABILITY_NONE, innate = ABILITY_NONE;
    s16 damage[2];
    PARAMETRIZE { removal = 0; ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; }
    PARAMETRIZE { removal = 1; ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; }
    PARAMETRIZE { removal = 2; ability = ABILITY_TRUESHOT_AURA; innate = ABILITY_NONE; }
    PARAMETRIZE { removal = 0; ability = ABILITY_NONE; innate = ABILITY_TRUESHOT_AURA; }
    PARAMETRIZE { removal = 1; ability = ABILITY_NONE; innate = ABILITY_TRUESHOT_AURA; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ability); Innates(innate); HP(1); Speed(3); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(1); }
        PLAYER(SPECIES_WOBBUFFET) { Speed(3); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(4); }
        OPPONENT(SPECIES_WOBBUFFET) { Speed(2); }
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft, criticalHit: TRUE); }
        TURN {
            if (removal == 0) SWITCH(playerLeft, 2);
            if (removal == 1) { MOVE(opponentRight, MOVE_SCRATCH, target: playerLeft); SEND_OUT(playerLeft, 2); }
            if (removal == 2) MOVE(opponentRight, MOVE_GASTRO_ACID, target: playerLeft);
            MOVE(playerRight, MOVE_SCRATCH, target: opponentLeft, criticalHit: TRUE);
        }
    } SCENE {
        HP_BAR(opponentLeft, captureDamage: &damage[0]);
        HP_BAR(opponentLeft, captureDamage: &damage[1]);
    } THEN {
        struct BattleContext ctx = {0};
        ctx.battlerAtk = GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT);
        ctx.battlerDef = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        ctx.move = MOVE_SCRATCH;
        EXPECT_EQ(CalcCritChanceStage(&ctx), 0);
        EXPECT_EQ(damage[0], damage[1]);
    }
}

SINGLE_BATTLE_TEST("Trueshot Aura respects critical-hit prevention")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_BATTLE_ARMOR; }
    PARAMETRIZE { ability = ABILITY_SHELL_ARMOR; }
    PARAMETRIZE { ability = ABILITY_NONE; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TRUESHOT_AURA); Innates(ABILITY_SUPER_LUCK); Speed(1); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ability); Speed(2); }
    } WHEN {
        TURN {
            if (ability == ABILITY_NONE) MOVE(opponent, MOVE_LUCKY_CHANT);
            MOVE(player, MOVE_SCRATCH);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        NOT MESSAGE("A critical hit!");
    }
}

DOUBLE_BATTLE_TEST("Trueshot Aura uses cached abilities and innates in AI calculations", u32 damage)
{
    u32 source;
    PARAMETRIZE { source = 0; }
    PARAMETRIZE { source = 1; }
    PARAMETRIZE { source = 2; }
    PARAMETRIZE { source = 3; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerLeft, MOVE_CELEBRATE); }
    } THEN {
        struct BattleContext ctx = {0};
        uq4_12_t effectiveness;
        ctx.battlerAtk = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        ctx.battlerDef = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        ctx.move = MOVE_SCRATCH;
        // The live battlers have no aura; only the AI cache supplies it.
        gAiLogicData->abilities[GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)] = ABILITY_NONE;
        gAiLogicData->abilities[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)] = ABILITY_NONE;
        if (source == 1)
            gAiLogicData->abilities[GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)] = ABILITY_TRUESHOT_AURA;
        if (source == 2)
            gAiLogicData->abilities[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)] = ABILITY_TRUESHOT_AURA;
        if (source == 3)
            gAiLogicData->innates[GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)][0] = ABILITY_TRUESHOT_AURA;
        gAiLogicData->aiCalcInProgress = TRUE;
        EXPECT_EQ(CalcCritChanceStage(&ctx), source == 0 ? 0 : 2);
        gAiLogicData->aiCalcInProgress = FALSE;
        struct SimulatedDamage damage = AI_CalcDamageSaveBattlers(
            MOVE_FROST_BREATH, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), &effectiveness, NO_GIMMICK, NO_GIMMICK);
        results[i].damage = damage.median;
    } FINALLY {
        for (u32 j = 1; j < 4; j++)
            EXPECT_EQ(results[0].damage, results[j].damage);
    }
}

SINGLE_BATTLE_TEST("Trueshot Aura is suppressed by Neutralizing Gas")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(ABILITY_TRUESHOT_AURA); }
        OPPONENT(SPECIES_WOBBUFFET) { Ability(ABILITY_NEUTRALIZING_GAS); }
    } WHEN {
        TURN { MOVE(player, MOVE_CELEBRATE); }
    } THEN {
        struct BattleContext ctx = {0};
        ctx.battlerAtk = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
        ctx.battlerDef = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
        ctx.move = MOVE_SCRATCH;
        EXPECT_EQ(CalcCritChanceStage(&ctx), 0);
    }
}

SINGLE_BATTLE_TEST("Trueshot Aura follows configured critical-hit odds")
{
    u32 genConfig, passes, trials;
    PARAMETRIZE { genConfig = GEN_1; passes = 5; trials = 16; }
    for (u32 j = GEN_2; j <= GEN_5; j++)
        PARAMETRIZE { genConfig = j; passes = 1; trials = 4; }
    for (u32 j = GEN_6; j <= GEN_9; j++)
        PARAMETRIZE { genConfig = j; passes = 1; trials = 2; }
    PASSES_RANDOMLY(passes, trials, RNG_CRITICAL_HIT);
    GIVEN {
        ASSUME(GetSpeciesBaseSpeed(SPECIES_TOGEPI) == 20);
        WITH_CONFIG(B_CRIT_CHANCE, genConfig);
        PLAYER(SPECIES_TOGEPI) { Ability(ABILITY_TRUESHOT_AURA); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}

DOUBLE_BATTLE_TEST("Trueshot Aura preserves an ally's Neuroforce", s16 damage)
{
    enum Ability aura, allyAbility, innate;
    PARAMETRIZE { aura = ABILITY_NONE; allyAbility = ABILITY_NONE; innate = ABILITY_NONE; }
    PARAMETRIZE { aura = ABILITY_NONE; allyAbility = ABILITY_NEUROFORCE; innate = ABILITY_NONE; }
    PARAMETRIZE { aura = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_NONE; innate = ABILITY_NONE; }
    PARAMETRIZE { aura = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_NEUROFORCE; innate = ABILITY_NONE; }
    PARAMETRIZE { aura = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_NONE; innate = ABILITY_NEUROFORCE; }
    PARAMETRIZE { aura = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_NEUROFORCE; innate = ABILITY_SNIPER; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(aura); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(allyAbility); Innates(innate); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_SHADOW_BALL, target: opponentLeft, criticalHit: TRUE); }
    } SCENE {
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.25), results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(1.875), results[5].damage);
        EXPECT_EQ(results[1].damage, results[3].damage);
        EXPECT_EQ(results[3].damage, results[4].damage);
        EXPECT_MUL_EQ(results[3].damage, UQ_4_12(1.5), results[5].damage);
    }
}

DOUBLE_BATTLE_TEST("Trueshot Aura preserves an ally's Tinted Lens", s16 damage)
{
    enum Ability aura, allyAbility, innate;
    PARAMETRIZE { aura = ABILITY_NONE; allyAbility = ABILITY_NONE; innate = ABILITY_NONE; }
    PARAMETRIZE { aura = ABILITY_NONE; allyAbility = ABILITY_TINTED_LENS; innate = ABILITY_NONE; }
    PARAMETRIZE { aura = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_NONE; innate = ABILITY_NONE; }
    PARAMETRIZE { aura = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_TINTED_LENS; innate = ABILITY_NONE; }
    PARAMETRIZE { aura = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_NONE; innate = ABILITY_TINTED_LENS; }
    PARAMETRIZE { aura = ABILITY_TRUESHOT_AURA; allyAbility = ABILITY_TINTED_LENS; innate = ABILITY_SNIPER; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET) { Ability(aura); }
        PLAYER(SPECIES_WOBBUFFET) { Ability(allyAbility); Innates(innate); }
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(playerRight, MOVE_CONFUSION, target: opponentLeft, criticalHit: TRUE); }
    } SCENE {
        HP_BAR(opponentLeft, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(2.0), results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, UQ_4_12(3.0), results[5].damage);
        EXPECT_EQ(results[1].damage, results[3].damage);
        EXPECT_EQ(results[3].damage, results[4].damage);
        EXPECT_MUL_EQ(results[3].damage, UQ_4_12(1.5), results[5].damage);
    }
}

SINGLE_BATTLE_TEST("Trueshot Aura gives Inteleon forms a 50 percent crit rate with Sniper")
{
    u32 species;
    PARAMETRIZE { species = SPECIES_INTELEON; }
    PARAMETRIZE { species = SPECIES_INTELEON_GMAX; }
    PASSES_RANDOMLY(1, 2, RNG_CRITICAL_HIT);
    GIVEN {
        WITH_CONFIG(B_CRIT_CHANCE, GEN_7);
        PLAYER(species) {
            Ability(gSpeciesInfo[species].abilities[2]);
            Innates(gSpeciesInfo[species].innates[0], gSpeciesInfo[species].innates[1], gSpeciesInfo[species].innates[2]);
        }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        MESSAGE("A critical hit!");
    }
}
