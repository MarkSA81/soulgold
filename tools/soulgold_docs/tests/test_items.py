import unittest
from collections import defaultdict

from tools.soulgold_docs.constants import ADDITIONAL_IMPORTANT_ITEMS, EV_FEATHER_ITEMS, TYPE_RESIST_BERRY_ITEMS
from tools.soulgold_docs.parsers.items import (
    IMPORTANT_ITEM_LOCATION_OVERRIDES,
    add_bug_contest_reward_locations,
    add_fishing_feather_locations,
    format_item_location,
)


class ImportantItemExceptionTests(unittest.TestCase):
    def test_includes_special_use_items(self):
        self.assertTrue(
            {
                "ITEM_ABILITY_CAPSULE",
                "ITEM_ABILITY_PATCH",
                "ITEM_GRACIDEA",
                "ITEM_WITHERED_HERB",
                "ITEM_GRIMY_HERB",
                "ITEM_BRITTLE_HERB",
                "ITEM_GOOPY_HERB",
                "ITEM_DULL_HERB",
                "ITEM_SOGGY_HERB",
                "ITEM_OLD_ROD",
                "ITEM_GOOD_ROD",
                "ITEM_SUPER_ROD",
                "ITEM_DOWSING_MACHINE",
                "ITEM_VS_SEEKER",
                "ITEM_COIN_CASE",
                "ITEM_BECKONING_BELL",
                "ITEM_TIMER_BALL",
                "ITEM_DUSK_BALL",
                "ITEM_QUICK_BALL",
                "ITEM_EXP_SHARE",
                "ITEM_OVAL_CHARM",
                "ITEM_SQUIRTBOTTLE",
                "ITEM_SHIN_GENOME",
                "ITEM_ZEROMIN",
                "ITEM_BLACK_MIRROR",
                "ITEM_REVERSE_CANDY",
                "ITEM_GS_BALL",
                *EV_FEATHER_ITEMS,
            }.issubset(ADDITIONAL_IMPORTANT_ITEMS)
        )

    def test_exp_share_and_oval_charm_use_story_source_overrides(self):
        self.assertEqual(
            IMPORTANT_ITEM_LOCATION_OVERRIDES["ITEM_EXP_SHARE"],
            [{"map": "Obtained from Rival before arriving in Violet City", "source": ""}],
        )
        self.assertEqual(
            IMPORTANT_ITEM_LOCATION_OVERRIDES["ITEM_OVAL_CHARM"],
            [{"map": "Obtained after finishing rival's postgame legendary story", "source": ""}],
        )

    def test_ev_feathers_include_fishing_as_a_source(self):
        locations = defaultdict(list)

        add_fishing_feather_locations(locations, set(EV_FEATHER_ITEMS))

        for item in EV_FEATHER_ITEMS:
            with self.subTest(item=item):
                self.assertIn(
                    {"map": "Fishing", "source": "Any rod"},
                    locations[item],
                )

    def test_special_key_items_use_player_facing_source_overrides(self):
        self.assertEqual(
            IMPORTANT_ITEM_LOCATION_OVERRIDES["ITEM_SQUIRTBOTTLE"],
            [{"map": "Goldenrod Flower Shop", "source": "After beating Whitney"}],
        )
        self.assertEqual(
            IMPORTANT_ITEM_LOCATION_OVERRIDES["ITEM_SHIN_GENOME"],
            [
                {"map": "Route 40", "source": "15-trophy achievement reward"},
                {"map": "Rocket Arcade", "source": "Postgame"},
                {"map": "Battle Cafe", "source": "Postgame"},
            ],
        )
        self.assertEqual(
            IMPORTANT_ITEM_LOCATION_OVERRIDES["ITEM_GS_BALL"],
            [{"map": "Ruins of Alph Secret Room", "source": "After completing all 8 puzzles"}],
        )

    def test_mahogany_shop_mentions_its_story_requirement(self):
        self.assertEqual(
            format_item_location(
                {"id": "MAP_MAHOGANY_TOWN_SHOP", "name": "MahoganyTown_Shop"},
                "MahoganyTown_Shop",
                "Mart",
            ),
            ("Mahogany Town Shop", "After Rocket Hideout event"),
        )

    def test_type_resist_berry_group_excludes_chilan(self):
        self.assertEqual(len(TYPE_RESIST_BERRY_ITEMS), 17)
        self.assertIn("ITEM_OCCA_BERRY", TYPE_RESIST_BERRY_ITEMS)
        self.assertIn("ITEM_PASSHO_BERRY", TYPE_RESIST_BERRY_ITEMS)
        self.assertNotIn("ITEM_CHILAN_BERRY", TYPE_RESIST_BERRY_ITEMS)

    def test_gracidea_has_story_location_override(self):
        self.assertEqual(
            IMPORTANT_ITEM_LOCATION_OVERRIDES["ITEM_GRACIDEA"],
            [
                {
                    "map": "Goldenrod Flower Shop after showing Shaymin",
                    "source": "",
                }
            ],
        )


class BugContestItemLocationTests(unittest.TestCase):
    def test_adds_the_correct_place_choice_to_each_reward_stone(self):
        first_place = {
            "ITEM_MOON_STONE",
            "ITEM_SUN_STONE",
            "ITEM_LEAF_STONE",
            "ITEM_DAWN_STONE",
            "ITEM_SHINY_STONE",
            "ITEM_DUSK_STONE",
            "ITEM_ICE_STONE",
        }
        second_place = {
            "ITEM_FIRE_STONE",
            "ITEM_THUNDER_STONE",
            "ITEM_WATER_STONE",
        }
        locations = defaultdict(list)

        add_bug_contest_reward_locations(locations, first_place | second_place)

        for item in first_place:
            self.assertIn(
                {"map": "Bug Catching Contest", "source": "1st place choice"},
                locations[item],
            )
        for item in second_place:
            self.assertIn(
                {"map": "Bug Catching Contest", "source": "2nd place choice"},
                locations[item],
            )


if __name__ == "__main__":
    unittest.main()
