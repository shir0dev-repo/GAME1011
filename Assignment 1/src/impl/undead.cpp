#include "../header/undead.h"

const std::string undead::speciesName = "Undead";

const std::string undead::m_taunts[5] = {
    "What doesn't kill you, will turn you into me!",
    "Not a bad swing, you would serve me well, minion.",
    "*various bone clacking noises*",
    "This is the closest I've felt to being alive since my demise!",
    "I assure you, no one has more backbone than me!"};

undead::undead(int maxHealth) : enemy(maxHealth) {}

void undead::normalAttack() const {
  // undead specific functionality
  std::cout << speciesName << " attacks normally." << std::endl;
}

void undead::takeDamage(int dmg) {
  enemy::takeDamage(dmg);
  std::cout << speciesName << " took " << dmg << " damage!" << std::endl;
}

void undead::tauntPlayer() const { std::cout << getRandomTaunt() << std::endl; }

std::string undead::getRandomTaunt() const {
  // random range equation for taunt (0 to  m_taunts length, hard-coded to 4)
  return m_taunts[rand() % 4];
}

std::ostream &undead::print(std::ostream &os) const {
  os << speciesName << ": " << getHealthString() << std::endl;

  return os;
}

bool undead::compare(const gameObject &g) const {
  if (enemy::compare(g) == false) {
    // gameObject g is not of type enemy.
    return false;
  } else if (dynamic_cast<const undead *>(&g)) {
    // do undead related comparisons
    return true;
  }

  // gameObject g is not of type undead.
  return false;
}