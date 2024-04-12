#include <ostream>
#include "../include/armour_set.h"

ArmourSet::ArmourSet(std::string name, std::string description, int value) {
  m_name = name;
  m_desc = description;
  m_armourValue = value;
}

int ArmourSet::GetArmourValue() const { return m_armourValue; }
const std::string ArmourSet::GetName() const { return m_name; }
const std::string ArmourSet::GetDesc() const { return m_name; }

std::ostream &operator<<(std::ostream &os, const ArmourSet &a) {
  os << a.m_name << ": " << a.m_armourValue << " AP" << std::endl;
  os << "    " << a.m_desc;

  return os;
}

bool operator==(const ArmourSet &lhs, const ArmourSet &rhs) {
  return lhs.m_name == rhs.m_name && lhs.m_armourValue == rhs.m_armourValue;
}