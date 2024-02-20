#pragma once

#include <iostream>
#include <string>

enum class Species : unsigned char {
  UNDEFINED = 0,
  Human = 1,
  Orc = 2,
  Elf = 3,
  DarkElf = 4,
  Gnome = 5,
  Dragonborn = 6,
  LENGTH
};

inline static constexpr const char *SpeciesPrintAll() {
  return "1 - Human \n"
         "2 - Orc \n"
         "3 - Elf \n"
         "4 - DarkElf \n"
         "5 - Gnome \n"
         "6 - Dragonborn \n";
}

inline static const std::string SpeciesAsString(const Species *value) {
  switch (*value) {
  case Species::Human:
    return "Human";
  case Species::Orc:
    return "Orc";
  case Species::Elf:
    return "Elf";
  case Species::DarkElf:
    return "Dark Elf";
  case Species::Gnome:
    return "Gnome";
  case Species::Dragonborn:
    return "Dragonborn";
  default:
    return "UNDEFINED";
  }
}