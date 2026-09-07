#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "item.h"
#include "new_game.h"
#include "pokemon.h"
#include "test/test.h"
#include "constants/flags.h"
#include "constants/vars.h"

TEST("Shiny odds use release defaults for new Pokemon on both beta and release saves")
{
    static const u16 savedOptions[] = {0, 1, 2, 3, MAX_u16};
    static const u16 thresholds[] = {256, 256, 128, 64, 256};
    struct BoxPokemon mon;

    for (u32 release = FALSE; release <= TRUE; release++)
    {
        if (release)
            FlagSet(FLAG_RELEASE_SHINY_ODDS);
        else
            FlagClear(FLAG_RELEASE_SHINY_ODDS);

        for (u32 i = 0; i < ARRAY_COUNT(savedOptions); i++)
        {
            u32 threshold = thresholds[i];
            VarSet(VAR_SHINY_RATE, savedOptions[i]);
            EXPECT_EQ(GetShinyRateOption(), i == 0 || i == 4 ? SHINY_RATE_256 : savedOptions[i]);
            EXPECT_EQ(GetShinyGenerationOdds(), threshold);
            EXPECT_EQ(GetTradeShinyGenerationOdds(), threshold * 12);
            CreateBoxMon(&mon, SPECIES_PIKACHU, 5, threshold - 1, OTID_STRUCT_PRESET(0));
            EXPECT(GetBoxMonData(&mon, MON_DATA_IS_SHINY));
            VarSet(VAR_SHINY_RATE, SHINY_RATE_1024);
            EXPECT(GetBoxMonData(&mon, MON_DATA_IS_SHINY));
            VarSet(VAR_SHINY_RATE, savedOptions[i]);
            CreateBoxMon(&mon, SPECIES_PIKACHU, 5, threshold, OTID_STRUCT_PRESET(0));
            EXPECT(!GetBoxMonData(&mon, MON_DATA_IS_SHINY));
            VarSet(VAR_SHINY_RATE, SHINY_RATE_256);
            EXPECT(!GetBoxMonData(&mon, MON_DATA_IS_SHINY));
            EXPECT_EQ(FlagGet(FLAG_RELEASE_SHINY_ODDS), release);
            EXPECT_EQ(GetCurrentShinyOdds(), release ? RELEASE_SHINY_ODDS : SHINY_ODDS);
        }
    }
}

TEST("Changed shiny odds do not alter existing shinies")
{
    static const u16 shinyValues[] = {0, 63, 64, 127, 128, 255, 256, 511, 512, 65535};
    struct BoxPokemon original, restored;

    for (u32 legacy = 0; legacy < 2; legacy++)
    {
        if (legacy)
            FlagClear(FLAG_RELEASE_SHINY_ODDS);
        else
            FlagSet(FLAG_RELEASE_SHINY_ODDS);
        for (u32 i = 0; i < ARRAY_COUNT(shinyValues); i++)
        {
            for (u32 modifier = 0; modifier < 2; modifier++)
            {
                VarSet(VAR_SHINY_RATE, SHINY_RATE_DEFAULT);
                CreateBoxMon(&original, SPECIES_PIKACHU, 5, shinyValues[i], OTID_STRUCT_PRESET(0));
                original.shinyModifier = modifier;
                u32 expected = (shinyValues[i] < (legacy ? SHINY_ODDS : RELEASE_SHINY_ODDS)) ^ modifier;
                for (u32 option = 0; option < SHINY_RATE_COUNT; option++)
                {
                    VarSet(VAR_SHINY_RATE, option);
                    restored = original;
                    EXPECT_EQ(GetBoxMonData(&restored, MON_DATA_IS_SHINY), expected);
                    SetBoxMonData(&restored, MON_DATA_IS_SHINY, &expected);
                    EXPECT_EQ((u32)restored.shinyModifier, modifier);
                    VarSet(VAR_SHINY_RATE, SHINY_RATE_DEFAULT);
                    EXPECT_EQ(GetBoxMonData(&restored, MON_DATA_IS_SHINY), expected);
                }
            }
        }
    }
}

TEST("Follower Mega option changes the form")
{
    u32 species;
    bool32 shiny, female;
    u32 item = ITEM_GRASSTITE;
    ZeroPlayerPartyMons();
    CreateMonWithIVs(&gPlayerParty[0], SPECIES_VENUSAUR, 50, 0, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    SetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM, &item);
    AddBagItem(ITEM_MEGA_RING, 1);
    ASSUME(gSpeciesInfo[SPECIES_VENUSAUR_MEGA].overworldData.tileTag != 0);
    VarSet(VAR_FOLLOWER_MEGA_OFF, 0);
    EXPECT(GetFollowerInfo(&species, &shiny, &female));
    EXPECT_EQ(species, SPECIES_VENUSAUR_MEGA);
    VarSet(VAR_FOLLOWER_MEGA_OFF, 1);
    EXPECT(GetFollowerInfo(&species, &shiny, &female));
    EXPECT_EQ(species, SPECIES_VENUSAUR);
    EXPECT_EQ(GetMonData(&gPlayerParty[0], MON_DATA_SPECIES), SPECIES_VENUSAUR);
    EXPECT_EQ(GetFormChangeTargetSpecies(&gPlayerParty[0], FORM_CHANGE_BATTLE_MEGA_EVOLUTION_ITEM), SPECIES_VENUSAUR_MEGA);
    VarSet(VAR_FOLLOWER_MEGA_OFF, 0);
    EXPECT(GetFollowerInfo(&species, &shiny, &female));
    EXPECT_EQ(species, SPECIES_VENUSAUR_MEGA);
}

TEST("Follower Mega option uses base form when no mega sprite exists")
{
    u32 species;
    bool32 shiny, female;
    u32 item = ITEM_GRASSTITE;
    ZeroPlayerPartyMons();
    CreateMonWithIVs(&gPlayerParty[0], SPECIES_RILLABOOM, 50, 0, OTID_STRUCT_PLAYER_ID, USE_RANDOM_IVS);
    SetMonData(&gPlayerParty[0], MON_DATA_HELD_ITEM, &item);
    AddBagItem(ITEM_MEGA_RING, 1);
    ASSUME(gSpeciesInfo[SPECIES_RILLABOOM_GMAX].overworldData.tileTag == 0);
    VarSet(VAR_FOLLOWER_MEGA_OFF, 0);
    EXPECT(GetFollowerInfo(&species, &shiny, &female));
    EXPECT_EQ(species, SPECIES_RILLABOOM);
}
