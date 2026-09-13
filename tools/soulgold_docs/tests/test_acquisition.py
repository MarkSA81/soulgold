from __future__ import annotations

import unittest

from tools.soulgold_docs.models import SpeciesRow
from tools.soulgold_docs.parsers.acquisition import BreedingRules, attach_acquisition_paths, parse_breeding_rules


RULES = BreedingRules(False, True, "SPECIES_SCATTERBUG_FANCY", {})


def mon(name, *, source=False, groups=None, categories=None, dex=1, species_id=1):
    return SpeciesRow(
        id=species_id, constant=f"SPECIES_{name}", name=name, nat_dex=dex,
        display_dex=dex, dex_visible=True, types=[], stats={}, ev_yield={},
        egg_groups=groups if groups is not None else ["EGG_GROUP_MONSTER"],
        categories=categories or [], abilities=[], regular_abilities=[],
        hidden_abilities=[], innates=[], level_up_symbol=None, teachable_symbol=None,
        egg_move_symbol=None, front_pic_symbol=None, shiny_palette_symbol=None,
        locations=[{"name": "Route 44", "map": "MAP_ROUTE44", "time": "",
                    "method": "Land Mons", "minLevel": 36, "maxLevel": 40, "rate": 5}] if source else [],
    )


def evolves(source, target, label="Level 30"):
    source.evolutions.append({
        "target": target.constant, "method": "EVO_LEVEL", "param": "30",
        "conditions": [], "label": label, "itemName": "",
    })


def ditto():
    return mon("DITTO", source=True, groups=["EGG_GROUP_DITTO"])


class AcquisitionTests(unittest.TestCase):
    def test_elekid_breeding_lists_both_obtainable_parents(self):
        baby = mon("ELEKID", groups=["EGG_GROUP_NO_EGGS_DISCOVERED"])
        buzz = mon("ELECTABUZZ", source=True, species_id=125)
        vire = mon("ELECTIVIRE", source=True, species_id=466)
        evolves(baby, buzz)
        evolves(buzz, vire)
        attach_acquisition_paths([baby, buzz, vire, ditto()], {}, RULES)
        self.assertEqual([p["source"] for p in baby.acquisition_paths], [buzz.constant, vire.constant])
        self.assertTrue(all(p["steps"][0]["kind"] == "breed" for p in baby.acquisition_paths))
        self.assertEqual(baby.acquisition_paths[0]["locations"], buzz.locations)
        self.assertEqual(buzz.acquisition_paths, [])

    def test_multistage_evolution_preserves_requirements_and_starting_location(self):
        base, middle, final = mon("BASE", source=True), mon("MIDDLE"), mon("FINAL")
        evolves(base, middle, "Level 16")
        evolves(middle, final, "Level 36")
        attach_acquisition_paths([base, middle, final], {}, RULES)
        path = final.acquisition_paths[0]
        self.assertEqual(path["source"], base.constant)
        self.assertEqual([s["evolution"]["label"] for s in path["steps"]], ["Level 16", "Level 36"])

    def test_breeding_final_produces_base_then_evolves_to_middle(self):
        base, middle, final = mon("BASE"), mon("MIDDLE"), mon("FINAL", source=True)
        evolves(base, middle)
        evolves(middle, final)
        attach_acquisition_paths([base, middle, final, ditto()], {}, RULES)
        self.assertEqual([s["kind"] for s in middle.acquisition_paths[0]["steps"]], ["breed", "evolve"])
        self.assertEqual(middle.acquisition_paths[0]["steps"][0]["target"], base.constant)

    def test_unavailable_family_does_not_bootstrap_itself(self):
        base, final = mon("BASE"), mon("FINAL")
        evolves(base, final)
        attach_acquisition_paths([base, final, ditto()], {}, RULES)
        self.assertEqual(base.acquisition_paths, [])
        self.assertEqual(final.acquisition_paths, [])

    def test_unbreedable_or_mega_parent_is_not_suggested(self):
        for groups, categories in [(["EGG_GROUP_NO_EGGS_DISCOVERED"], []), (["EGG_GROUP_MONSTER"], ["mega"])]:
            with self.subTest(groups=groups, categories=categories):
                base = mon("BASE")
                parent = mon("PARENT", source=True, groups=groups, categories=categories)
                evolves(base, parent)
                attach_acquisition_paths([base, parent, ditto()], {}, RULES)
                self.assertEqual(base.acquisition_paths, [])

    def test_pairing_requires_obtainable_ditto(self):
        base, final = mon("BASE"), mon("FINAL", source=True)
        evolves(base, final)
        attach_acquisition_paths([base, final], {}, RULES)
        self.assertEqual(base.acquisition_paths, [])

    def test_regional_parent_can_preserve_or_drop_regional_form(self):
        base = mon("VULPIX", species_id=37, dex=37)
        regional = mon("VULPIX_ALOLA", species_id=1000, dex=37, categories=["regional"])
        parent = mon("NINETALES_ALOLA", species_id=1001, dex=38, categories=["regional"], source=True)
        evolves(regional, parent)
        attach_acquisition_paths([base, regional, parent, ditto()], {}, RULES)
        self.assertIn("hold an Everstone", regional.acquisition_paths[0]["steps"][0]["requirement"])
        self.assertIn("without an Everstone", base.acquisition_paths[0]["steps"][0]["requirement"])

    def test_incense_matches_configuration(self):
        baby, parent = mon("MUNCHLAX"), mon("SNORLAX", source=True)
        evolves(baby, parent)
        rules = BreedingRules(True, True, RULES.scatterbug,
                             {baby.constant: (parent.constant, "ITEM_FULL_INCENSE")})
        attach_acquisition_paths([baby, parent, ditto()], {}, rules)
        self.assertIn("Full Incense", baby.acquisition_paths[0]["steps"][0]["requirement"])
        attach_acquisition_paths([baby, parent, ditto()], {}, RULES)
        self.assertEqual(baby.acquisition_paths[0]["steps"][0]["requirement"], "")

    def test_special_offspring_manaphy_and_authentic_forms(self):
        for parent_name, target_name in [("MANAPHY", "PHIONE"), ("SINISTEA_ANTIQUE", "SINISTEA_PHONY"), ("POLTCHAGEIST_ARTISAN", "POLTCHAGEIST_COUNTERFEIT")]:
            with self.subTest(parent=parent_name):
                parent, target = mon(parent_name, source=True), mon(target_name)
                attach_acquisition_paths([parent, target, ditto()], {}, RULES)
                self.assertEqual(target.acquisition_paths[0]["source"], parent.constant)

    def test_mixed_gender_eggs_and_configured_scatterbug_form(self):
        female, male = mon("NIDORAN_F", source=True), mon("NIDORAN_M")
        attach_acquisition_paths([female, male, ditto()], {}, RULES)
        self.assertIn("either species", male.acquisition_paths[0]["steps"][0]["requirement"])
        fancy, other = mon("SCATTERBUG_FANCY"), mon("SCATTERBUG_POLAR", source=True)
        attach_acquisition_paths([fancy, other, ditto()], {}, RULES)
        self.assertEqual(fancy.acquisition_paths[0]["source"], other.constant)

    def test_evolution_cycles_terminate_and_paths_never_repeat_species(self):
        first, second, third = mon("FIRST", source=True), mon("SECOND"), mon("THIRD")
        evolves(first, second)
        evolves(second, third)
        evolves(third, second)
        attach_acquisition_paths([first, second, third, ditto()], {}, RULES)
        for row in [second, third]:
            self.assertTrue(row.acquisition_paths)
            for path in row.acquisition_paths:
                visited = [path["source"], *(s["target"] for s in path["steps"])]
                self.assertEqual(len(visited), len(set(visited)))

    def test_current_game_breeding_config_is_parsed(self):
        rules = parse_breeding_rules()
        self.assertFalse(rules.incense_required)
        self.assertEqual(rules.scatterbug, "SPECIES_SCATTERBUG_FANCY")
        self.assertEqual(rules.incense_babies["SPECIES_MUNCHLAX"], ("SPECIES_SNORLAX", "ITEM_FULL_INCENSE"))


if __name__ == "__main__":
    unittest.main()
