#include "../header/knight.h"

const std::string knight::specialAttackName = "Fury Strike";

knight::knight(std::string name, int maxHealth, int spcAtkDmg) : player(name, maxHealth) {
  m_specialAttackDamage = spcAtkDmg;
}

int knight::getSpecialAttackDamage() const { return m_specialAttackDamage; }

void knight::normalAttack() const {
  // attack enemy functionality
  player::normalAttack();
  std::cout << "...as a Knight!" << std::endl;
}

void knight::specialAttack() const {
  // special attack functionality
  std::cout << m_name << " casts " << specialAttackName << '!' << std::endl
            << m_name << " has never been so enraged!" << std::endl;
}

std::ostream &knight::print(std::ostream &os) const {
  player::print(os);
  os << "Class: Knight" << std::endl;
  os << "  " << specialAttackName << ": " << m_specialAttackDamage << " DMG" << std::endl;

  return os;
}

bool knight::compare(const gameObject &g) const {
  if (player::compare(g) == false) {
    // gameObject g is not of type player.
    return false;
  } else if (dynamic_cast<const knight *>(&g)) {
    //do knight related comparisons
    return true;
  }
  // gameObject g is not of type knight.
  return false;
}