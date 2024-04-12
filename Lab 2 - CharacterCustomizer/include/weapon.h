#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Ability;

class Weapon {
public:
  Weapon(std::string name, int damage);

  int GetDamageValue() const;
  const std::string GetName() const;
  const std::string GetDesc() const;

  void AddAbility(std::shared_ptr<Ability>);

  friend std::ostream &operator<<(std::ostream &, const Weapon &);
  friend bool operator==(const Weapon &, const Weapon &);

private:
  int m_damage;
  std::string m_name;

  static const unsigned int _MAX_ABILITIES = 2;
  unsigned int m_abilityCount;
  std::vector<std::weak_ptr<Ability>> m_abilities;
};