#pragma once

#include "enemy.h"
#include <string>

class undead : public enemy /*number one*/ {
public:
  undead(int);
  static const std::string speciesName;

  void normalAttack() const override final;
  void tauntPlayer() const override final;
  std::string getRandomTaunt() const override final;
  void takeDamage(int) override final;

private:
  static const std::string m_taunts[5];

  std::ostream &print(std::ostream &) const override final;
  bool compare(const gameObject &) const override final;
};