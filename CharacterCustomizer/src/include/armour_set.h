#pragma once

#include <ostream>
#include <string>

class ArmourSet {
public:
  ArmourSet(std::string name, std::string description, int value);

  int GetArmourValue() const;
  const std::string GetName() const;
  const std::string GetDesc() const;

  friend std::ostream &operator<<(std::ostream &, const ArmourSet &);
  friend bool operator==(const ArmourSet &, const ArmourSet &);

private:
  int m_armourValue;
  std::string m_name;
  std::string m_desc;
};