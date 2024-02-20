#pragma once

#include "player.h"

class wizard : public player {
public:
  wizard(std::string, int, int);
  static const std::string specialAttackName;

  int getSpecialAttackDamage() const;

  void normalAttack() const override final;
  void specialAttack() const override final;

private:
  int m_specialAttackDamage;

  std::ostream &print(std::ostream &) const override final;
  bool compare(const gameObject &) const override final;
};