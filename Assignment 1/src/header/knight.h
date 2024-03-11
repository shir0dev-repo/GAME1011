#pragma once

#include "player.h"

class knight : public player {
public:
  knight(std::string, int, int);
  static const std::string specialAttackName;

  int getSpecialAttackDamage() const override final;

  void normalAttack() const override final;
  void specialAttack() const override final;

private:
  int m_specialAttackDamage;

  std::ostream &print(std::ostream &) const override final;
  bool compare(const gameObject &) const override final;
};