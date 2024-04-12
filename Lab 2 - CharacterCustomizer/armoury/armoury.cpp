#include "../include/armoury.h"
#include "../include/ability.h"
#include "../include/armour_set.h"
#include "../include/weapon.h"
#include <cassert>
#include <iostream>
#include <memory>

Armoury::Armoury() {
  PopulateAbilities();
  PopulateWeapons();
  PopulateArmourSets();
}
std::shared_ptr<Weapon> Armoury::GetWeapon(int index) const {
  assert(index >= 0 && index < 3 && m_weapons[index]);

  return m_weapons.at(index);
}

std::shared_ptr<Ability> Armoury::GetAbility(int index) const {
  assert(index >= 0 && index < 4 && m_abilities[index]);

  return m_abilities.at(index);
}

std::shared_ptr<ArmourSet> Armoury::GetArmourSet(int index) const {
  assert(index >= 0 && index < 3 && m_armourSets[index]);

  return m_armourSets.at(index);
}

const void Armoury::PrintWeapons() const {
  if (!m_weapons.empty()) {
    for (unsigned int i = 0; i < m_weapons.size(); i++) {
      if (m_weapons[i])
        std::cout << *m_weapons[i] << std::endl;
    }
  }
}

const void Armoury::PrintArmourSets() const {
  if (!m_armourSets.empty()) {
    for (unsigned int i = 0; i < m_armourSets.size(); i++) {
      std::cout << *m_armourSets[i] << std::endl;
    }
  }
}

void Armoury::PopulateAbilities() {
  m_abilities.push_back(std::make_shared<Ability>(
      "Double Strike", "Attacks again, dealing bonus damage!"));
  m_abilities.push_back(std::make_shared<Ability>(
      "Enflame", "Ignites target, dealing bonus damage!"));
  m_abilities.push_back(std::make_shared<Ability>(
      "Focus", "Focus on target, dealing bonus damage!"));
  m_abilities.push_back(std::make_shared<Ability>(
      "Summon Spectre", "Summons a spectre for dealing bonus damage!"));
}
void Armoury::PopulateWeapons() {
  m_weapons.push_back(std::make_shared<Weapon>("Flaming Greatsword", 5));
  m_weapons[0]->AddAbility(m_abilities.at(0));
  m_weapons[0]->AddAbility(m_abilities.at(1));

  m_weapons.push_back(std::make_shared<Weapon>("Conjurer's Staff", 4));
  m_weapons[1]->AddAbility(m_abilities.at(2));
  m_weapons[1]->AddAbility(m_abilities.at(3));

  m_weapons.push_back(std::make_shared<Weapon>("Marksman's Longbow", 8));
  m_weapons[2]->AddAbility(m_abilities.at(2));
  m_weapons[2]->AddAbility(m_abilities.at(0));
}
void Armoury::PopulateArmourSets() {
  m_armourSets.push_back(std::make_shared<ArmourSet>(
      "Leather Armour", "Armour crafted from an unlucky cattle.", 9));
  m_armourSets.push_back(std::make_shared<ArmourSet>(
      "Chainmail Armour", "Like wearing a fence, but noisier!", 12));
  m_armourSets.push_back(std::make_shared<ArmourSet>(
      "Steel Platemail", "Despite the name, you can't eat off it!", 16));
}