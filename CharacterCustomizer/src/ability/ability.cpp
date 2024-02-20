#include <ostream>

#include "../include/ability.h"

Ability::Ability(std::string name, std::string desc) {
  m_name = name;
  m_desc = desc;
}

const std::string Ability::GetName() const { return m_name; }
const std::string Ability::GetDesc() const { return m_name; }

std::ostream &operator<<(std::ostream &os, const Ability &a) {
  os << a.m_name << ": " << a.m_desc << std::endl;

  return os;
}

bool operator==(const Ability &lhs, const Ability &rhs) {
  return lhs.m_name == rhs.m_name && lhs.m_desc == rhs.m_desc;
}