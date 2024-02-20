#include "../header/orc.h"

const std::string orc::speciesName = "Orc";

const std::string orc::m_taunts[5] = {
"Me meet trolls smarter! You hit head as baby?",
"Want tough fight! You fight like tiny orc baby!",
"Is that battle cry? Or baby cry?",
"Me find sleeping harder. Fight more good!",
"I find the lack of angular velocity within the trajectory of your swing deeply alarming." };

orc::orc(int maxHealth) : enemy(maxHealth) {}

void orc::normalAttack() const {
  // orc specific functionality
  std::cout << speciesName << " attacks normally." << std::endl;
}

void orc::tauntPlayer() const { std::cout << getRandomTaunt(); }

std::string orc::getRandomTaunt() const {
  // random range equation for taunt (0 to  m_taunts length, hard-coded to 4)
  return m_taunts[rand() % 4];
}

std::ostream &orc::print(std::ostream &os) const {
  os << speciesName << ": " << getHealthString() << std::endl;

  return os;
}

bool orc::compare(const gameObject &g) const {
  if (enemy::compare(g) == false) {
    // gameObject g is not of type enemy.
    return false;
  } else if (dynamic_cast<const orc *>(&g)) {
    // do orc related comparisons
    return true;
  }

  // gameObject g is not of type orc.
  return false;
}