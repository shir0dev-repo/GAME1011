#pragma once

#include "gameobject.h"
#include <string>

class player : public gameObject {
public:
  player(std::string, int);

  std::string getName() const;
  std::string getHealthString() const;

  int getHealth() const;
  void setHealth(int);
  int getMaxHealth() const;
  void setMaxHealth(int);
  int getHealthPercent() const;

  void normalAttack() const override;
  virtual void specialAttack() const = 0;
  virtual int getSpecialAttackDamage() const = 0;
  void takeDamage(int);

protected:
  std::string m_name;
  int m_currentHealth;
  int m_maxHealth;

  virtual std::ostream &print(std::ostream &) const override;
  virtual bool compare(const gameObject &) const override;
};