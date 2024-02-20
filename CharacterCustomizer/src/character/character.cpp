#include <iostream>
#include <memory>
#include <ostream>
#include <string>

#include "../include/armour_set.h"
#include "../include/character.h"
#include "../include/species.h"
#include "../include/weapon.h"

Character::Character(std::string name, std::string desc, Species species,
                     int maxHealth, std::shared_ptr<ArmourSet> armPtr,
                     std::shared_ptr<Weapon> wpnPtr) {

  m_name = name;
  m_desc = desc;
  m_species = species;
  m_maxHealthValue = maxHealth;
  m_currentHealthValue = m_maxHealthValue;
  m_currentArmourSet = armPtr;
  m_currentWeapon = wpnPtr;
}

std::string Character::GetName() const { return m_name; }

std::string Character::GetBackstory() const { return m_desc; }

std::string Character::GetSpeciesName() const {
  return SpeciesAsString(&m_species);
}

Species Character::GetSpecies() const { return m_species; }

float Character::GetCurrentHealthPercent() const {
  return (m_currentHealthValue / (float)m_maxHealthValue) * 100;
}

int Character::GetMaxHealth() const { return m_maxHealthValue; }

int Character::GetCurrentHealth() const { return m_currentHealthValue; }

int Character::GetArmourValue() const {
  if (auto sharedArmour = m_currentArmourSet.lock())
    return sharedArmour->GetArmourValue();
  else
    return 0;
}

int Character::CalculateDamageTaken(int damage) const {
  int val = damage - (int)(GetArmourValue() / 2);
  return val;
}

void Character::TakeDamage(int damage) {
  int damageTaken = CalculateDamageTaken(damage);

  if (damageTaken > 0) {
    m_currentHealthValue -= damageTaken;

    if (m_currentHealthValue <= 0)
      Die();
  }
}

void Character::Die() { std::cout << "goodbye cruel world"; }

void Character::PrintComparison(const Character &other) {
  auto mArmour = m_currentArmourSet.lock();
  auto mWeapon = m_currentWeapon.lock();

  auto otherArm = other.m_currentArmourSet.lock();
  auto otherWpn = other.m_currentWeapon.lock();

  std::cout << m_name << ": " << GetCurrentHealthPercent() << "% HP VS "
            << other.m_name << ": " << GetCurrentHealthPercent() << "% HP"
            << std::endl;
  std::cout << mWeapon->GetName() << ": " << mWeapon->GetDamageValue()
            << " DMG :: " << otherWpn->GetName() << ": "
            << otherWpn->GetDamageValue() << " DMG" << std::endl;
  std::cout << mArmour->GetName() << ": " << mArmour->GetArmourValue()
            << " AP :: " << otherArm->GetName() << ": "
            << otherArm->GetArmourValue() << " AP" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Character &c) {
  auto sharedWpnPtr = c.m_currentWeapon.lock();
  auto sharedArmPtr = c.m_currentArmourSet.lock();

  os << "Name - " << c.m_name << ": " << (int)c.m_currentHealthValue << '/'
     << (int)c.m_maxHealthValue << " HP" << std::endl
     << "Species - " << SpeciesAsString(&c.m_species) << std::endl
     << "Backstory - " << c.m_desc << std::endl
     << "Weapon - " << *sharedWpnPtr << "Armour - " << *sharedArmPtr;
  return os;
}