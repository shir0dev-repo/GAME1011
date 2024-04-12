#include "../include/weapon.h"
#include "../include/ability.h"
#include <memory>
#include <ostream>


Weapon::Weapon(std::string name, int damage) {
  m_name = name;
  m_damage = damage;
  m_abilityCount = 0;
}

int Weapon::GetDamageValue() const { return m_damage; }
const std::string Weapon::GetName()const { return m_name; }

void Weapon::AddAbility(std::shared_ptr<Ability> ability) {
  if (m_abilityCount < _MAX_ABILITIES) {
    m_abilities.push_back(ability);
    m_abilityCount++;
  }
  else
    return;
}

std::ostream &operator<<(std::ostream &os, const Weapon &w) {
  
  os << w.m_name << ": " << w.m_damage << " DMG" << std::endl;
  int printIndex = 1; 
  for (auto &ability : w.m_abilities) {
    if (auto sharedAbility = ability.lock()) {
      std::cout << "    Ability " << printIndex << " - " << *sharedAbility;
      printIndex++;
    }
  }

  return os;
}

bool operator==(const Weapon &lhs, const Weapon &rhs) {
  return lhs.m_name == rhs.m_name && lhs.m_damage == rhs.m_damage;
}