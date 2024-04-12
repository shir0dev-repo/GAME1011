#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "ability.h"
#include "weapon.h"
#include "armour_set.h"

class Armoury {
public:
  Armoury();

  std::shared_ptr<Ability> GetAbility(int index) const;
  std::shared_ptr<Weapon> GetWeapon(int index) const;
  std::shared_ptr<ArmourSet> GetArmourSet(int index) const;

  const void PrintWeapons() const;
  const void PrintArmourSets() const;

private:
  std::vector<std::shared_ptr<Ability>> m_abilities;
  std::vector<std::shared_ptr<Weapon>> m_weapons;
  std::vector<std::shared_ptr<ArmourSet>> m_armourSets;

  void PopulateWeapons();
  void PopulateArmourSets();
  void PopulateAbilities();
};