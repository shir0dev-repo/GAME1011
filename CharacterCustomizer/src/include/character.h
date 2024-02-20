#pragma once

#include <memory>
#include <ostream>
#include <string>
#include <vector>

enum class Species : unsigned char;
struct NameDesc;
class ArmourSet;
class Weapon;

class Character {
public:
  static const int MAX_CHARACTER_COUNT = 3;
  Character(std::string, std::string, Species, int,
            std::shared_ptr<ArmourSet>, std::shared_ptr<Weapon>);

  std::string GetName() const;
  std::string GetBackstory() const;
  std::string GetSpeciesName() const;

  Species GetSpecies() const;

  float GetCurrentHealthPercent() const;
  int GetMaxHealth() const;
  int GetCurrentHealth() const;
  int GetArmourValue() const;
  int CalculateDamageTaken(int damage) const;

  void TakeDamage(int damage);

  void PrintComparison(const Character &other);
  bool operator==(const Character &other);
  friend std::ostream &operator<<(std::ostream &os, const Character &c);

private:
  std::string m_name;
  std::string m_desc;
  std::weak_ptr<Weapon> m_currentWeapon;
  std::weak_ptr<ArmourSet> m_currentArmourSet;
  Species m_species;
  unsigned char m_maxHealthValue;
  unsigned char m_currentHealthValue;

  void Die();
};