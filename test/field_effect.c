#include "global.h"
#include "field_effect.h"
#include "field_weather.h"
#include "sprite.h"
#include "test/test.h"

TEST("Field effect cleanup keeps the weather palette after the last shadow disappears")
{
    u32 paletteNum;

    ResetSpriteData();
    FreeAllSpritePalettes();
    paletteNum = AllocSpritePalette(PALTAG_WEATHER);
    EXPECT(paletteNum < 16);

    FieldEffectFreePaletteIfUnused(paletteNum);

    EXPECT_EQ(IndexOfSpritePaletteTag(PALTAG_WEATHER), paletteNum);
    EXPECT(AllocSpritePalette(1234) != paletteNum);
    FreeAllSpritePalettes();
}

TEST("Field effect cleanup still frees unused effect palettes")
{
    u32 paletteNum;

    ResetSpriteData();
    FreeAllSpritePalettes();
    paletteNum = AllocSpritePalette(1234);
    EXPECT(paletteNum < 16);

    FieldEffectFreePaletteIfUnused(paletteNum);

    EXPECT_EQ(IndexOfSpritePaletteTag(1234), 0xFF);
    FreeAllSpritePalettes();
}
