#include "../header/enemy.h"

enemy::enemy(int maxHealth) {
  m_maxHealth = maxHealth;
  m_currentHealth = m_maxHealth;
}

std::string enemy::getHealthString() const {
  return std::to_string(m_currentHealth)
      .append("/")
      .append(std::to_string(m_maxHealth))
      .append(" HP ")
      .append("(")
      .append(std::to_string(getHealthPercent()))
      .append("%)");
}

int enemy::getHealth() const { return m_currentHealth; }

void enemy::setHealth(int value) {
  m_currentHealth = value;
  if (m_currentHealth < 0)
    m_currentHealth = 0;
}

int enemy::getMaxHealth() const { return m_maxHealth; }

void enemy::setMaxHealth(int value) {
  m_maxHealth = value;
  if (m_currentHealth > m_maxHealth)
    m_currentHealth = m_maxHealth;
}

int enemy::getHealthPercent() const {
  return (m_currentHealth / m_maxHealth) * 100;
}

void enemy::normalAttack() const {
  // attack player functionality
  std::cout << "Enemy is attacking normally.";
}

void enemy::takeDamage(int dmg) {
  m_currentHealth -= dmg;
  if (m_currentHealth < 0) {
    m_currentHealth = 0;
  }
}

std::ostream &enemy::print(std::ostream &os) const {
  os << "Enemy: "
     << ": " << getHealthString() << std::endl;

  return os;
}

bool enemy::compare(const gameObject &g) const {
  if (const enemy *nmePtr = dynamic_cast<const enemy *>(&g)) {
    return nmePtr->getHealthPercent() == getHealthPercent();
  }

  // gameObject g is not of type enemy.
  return false;
}