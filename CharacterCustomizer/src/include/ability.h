#pragma once

#include <iostream>
#include <ostream>
#include <string>

class Ability {
public:
  Ability(std::string name, std::string desc);
  Ability(const Ability &other);

  const std::string GetName() const;
  const std::string GetDesc() const;

  friend std::ostream &operator<<(std::ostream &, const Ability &);
  friend bool operator==(const Ability &, const Ability &);

private:
  std::string m_name;
  std::string m_desc;
};