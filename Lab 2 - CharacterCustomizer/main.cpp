#include "include/armoury.h"
#include "include/character.h"
#include "include/validator.h"
#include <iostream>

/*
FULLPRINT:

CharacterName - DONE
    CharacterBackstory - DONE
    CharacterWeaponName: WeaponDamage DMG - DONE
        WeaponAbilityA - DONE
            AbilityDescription - DONE
        WeaponAbilityB - DONE
            AbilityDescription - DONE
    CharacterArmourName: ArmourValue AP - DONE
        Armour Description - DONE
*/


int main() {
  Armoury armoury;
  std::vector<std::unique_ptr<Character>> characters;

  std::cout << "Hello player! Please create a character to begin!" << std::endl;
  validator::CreateCharacter(&armoury, &characters);

  for (;;) {
    std::cout << "What would you like to do? (type -help for commands): ";
    std::string input;
    std::getline(std::cin, input);

    if (input == "-exit") {
      break;
    } else if (input == "-help") {
      validator::ListCommands();
      continue;
    } else if (input == "-character create") {
      validator::CreateCharacter(&armoury, &characters);
    } else if (input == "-character compare") {
      validator::CompareCharacters(characters);
    } else if (input == "-display") {
      validator::PrintCharacter(characters, false);
    } else if (input == "-display all") {
      validator::PrintCharacter(characters, true);
    } else if (input == "-clear") {
      system("CLS");

    } else {
    }
  }

  return 0;
}
