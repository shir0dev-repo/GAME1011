#include "../header/wizard.h"

const std::string wizard::specialAttackName = "Flaming Vortex";

wizard::wizard(std::string name, int maxHealth, int specialAtkDmg) : player(name, maxHealth) {
  m_specialAttackDamage = specialAtkDmg;
}

int wizard::getSpecialAttackDamage() const { return m_specialAttackDamage; }

void wizard::normalAttack() const {
  // attack enemy functionality
  player::normalAttack();
  std::cout << "...as a Wizard!" << std::endl;
}

void wizard::specialAttack() const {
  // special attack functionality
  std::cout << m_name << " casts " << specialAttackName << '!' << std::endl
            << "Is it getting hot in here, or is it just " << m_name << '?' << std::endl;
}

std::ostream &wizard::print(std::ostream &os) const {
  player::print(os);
  os << "Class: Wizard" << std::endl;
  os << "  " << specialAttackName << ": " << m_specialAttackDamage << " DMG" << std::endl;

  return os;
}

bool wizard::compare(const gameObject &g) const {
  if (player::compare(g) == false) {
    // gameObject g is not of type player.
    return false;
  } else if (dynamic_cast<const wizard *>(&g)) {
    //do wizard related comparisons
    return true;
  }
  // gameObject g is not of type wizard.
  return false;
}