#include "../header/player.h"

player::player(std::string name, int maxHealth) {
  m_name = name;
  m_maxHealth = maxHealth;
  m_currentHealth = m_maxHealth;
}

std::string player::getName() const { return m_name; }

std::string player::getHealthString() const {
  return std::to_string(m_currentHealth)
      .append("/")
      .append(std::to_string(m_maxHealth))
      .append(" HP ")
      .append("(")
      .append(std::to_string(getHealthPercent()))
      .append("%)");
}

int player::getHealth() const { return m_currentHealth; }
void player::setHealth(int value) {
  m_currentHealth = value;
  if (m_currentHealth < 0)
    m_currentHealth = 0;
}

int player::getMaxHealth() const { return m_maxHealth; }
void player::setMaxHealth(int value) {
  m_maxHealth = value;
  if (m_currentHealth < m_maxHealth)
    m_currentHealth = m_maxHealth;
}

int player::getHealthPercent() const {
  return (m_currentHealth / m_maxHealth) * 100;
}

void player::normalAttack() const {
  // base player attack functionality
  std::cout << m_name << " is attacking..." << std::endl;
}

void player::takeDamage(int dmg) {
  std::cout << m_name << " took " << dmg << " damage!" << std::endl;
  m_currentHealth -= dmg;
  if (m_currentHealth < 0)
    m_currentHealth = 0;
}

std::ostream &player::print(std::ostream &os) const {
  os << m_name << ": " << getHealthString() << std::endl;

  return os;
}

bool player::compare(const gameObject &g) const {
  if (const player *plrPtr = dynamic_cast<const player *>(&g)) {
    return plrPtr->m_name == m_name &&
           plrPtr->getHealthPercent() == getHealthPercent();
  }

  // gameObject g is not of type player.
  return false;
}