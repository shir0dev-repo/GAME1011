#pragma once

#include "gameobject.h"
#include <string>


class enemy : public gameObject {
public:
  enemy(int maxHealth);

  std::string getHealthString() const;
  int getHealth() const;
  void setHealth(int);
  int getMaxHealth() const;
  void setMaxHealth(int);
  int getHealthPercent() const;

  virtual void normalAttack() const override;
  virtual void tauntPlayer() const = 0;
  virtual std::string getRandomTaunt() const = 0;
  virtual void takeDamage(int);

protected:
  int m_currentHealth;
  int m_maxHealth;
  virtual std::ostream &print(std::ostream &) const override;
  virtual bool compare(const gameObject &) const override;
};