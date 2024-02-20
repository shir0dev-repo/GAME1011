#include "../include/validator.h"
#include "../include/armour_set.h"
#include "../include/armoury.h"
#include "../include/character.h"
#include "../include/species.h"
#include "../include/weapon.h"
#include <cstdlib>
#include <iostream>

namespace validator {

void HandleCommand(Armoury &armoury,
                   std::vector<std::unique_ptr<Character>> *characters) {
  std::string input;
}
void ListCommands() {
  system("CLS");
  std::cout << "-help : displays all commands" << std::endl
            << "-character create : creates a new character (max 3)"
            << std::endl
            << "-character compare : compares 2 characters together"
            << std::endl
            << "-display : displays a selected character" << std::endl
            << "-display all : displays all created characters" << std::endl
            << "-exit : exits the program" << std::endl;
}

int ValidateIntegerInput(int minInclusive, int maxExclusive,
                         std::string errmsg) {
  int value;

  while ((std::cin >> value && value >= minInclusive && value < maxExclusive) ==
         false) {
    std::cout << errmsg;
    CinClear();
  }

  CinClear();
  return value;
}

bool ValidateBooleanInput() {
  std::string input;
  while (true) {
    std::cin >> input;
    if (input.length() > 4)
      std::cout << "Could not parse, please try again." << std::endl;

    unsigned char ch = std::tolower(input[0]);
    if (ch == 'y') {
      CinClear();
      return true;
    } else if (ch == 'n') {
      CinClear();
      return false;
    } else {
      std::cout << "Could not parse, please try again." << std::endl;
      input = "";
      CinClear();
    }
  }
}

std::string ValidateStringInput() {
  std::string input;

  while (!(std::getline(std::cin, input) && input.length() > 1)) {
    std::cout << "Invalid input, try again: ";
    CinClear();
  }

  return input;
}

void CreateCharacter(
    Armoury *armoury,
    std::vector<std::unique_ptr<Character>> *currentCharacters) {
  if (currentCharacters->size() >= Character::MAX_CHARACTER_COUNT) {
    std::cout << "Maximum characters reached! Cannot create more than 3.";
    return;
  }

  std::string cName;
  std::string cBackstory;

  std::cout << "What is your character's name?: ";
  cName = ValidateStringInput();
  system("CLS");

  std::cout << SpeciesPrintAll() << "What species is " << cName << "?: ";
  const int sIndex = ValidateIntegerInput(1, (int)Species::LENGTH);
  const Species &cSpecies = static_cast<Species>(sIndex);
  system("CLS");
  std::cout << cName << "'s species is now " << SpeciesAsString(&cSpecies)
            << '.' << std::endl;

  std::cout << "Give your character an epic backstory: ";
  cBackstory = ValidateStringInput();
  system("CLS");
  std::cout << '"' << cBackstory << "?\" " << cName << " sounds awesome!"
            << std::endl;

  std::cout << "Let's give " << cName << " some health: ";
  int cHealth = ValidateIntegerInput(5, 21, "C'mon, be reasonable (5 - 20): ");
  system("CLS");
  std::cout << cName << " now has " << cHealth << " health." << std::endl;

  armoury->PrintWeapons();
  std::cout << "Select a starting weapon: ";

  const int wIndex = ValidateIntegerInput(1, 4);
  auto cWeapon = armoury->GetWeapon(wIndex - 1);
  system("CLS");

  std::cout << cWeapon->GetName() << " is a great choice!" << std::endl;

  armoury->PrintArmourSets();
  std::cout << "Select an armour set: ";
  const int aIndex = ValidateIntegerInput(1, 4);
  auto cArmour = armoury->GetArmourSet(aIndex - 1);
  system("CLS");
  std::cout << cArmour->GetName() << "? Nice!" << std::endl << std::endl;

  auto character = std::make_unique<Character>(cName, cBackstory, cSpecies,
                                               cHealth, cArmour, cWeapon);
  std::cout << *character << std::endl;
  std::cout << "Here's an overview of " << character->GetName() << '.'
            << std::endl;

  std::cout << "Is " << character->GetName()
            << " everything you ever wanted? (Y/N)" << std::endl;
  if (ValidateBooleanInput()) {
    system("CLS");
    std::cout << "Sweet! " << character->GetName()
              << " was added to your list of characters!" << std::endl;
    currentCharacters->push_back(std::move(character));
  } else {
    system("CLS");
    std::cout << "Alright, let's try again!" << std::endl;
    return CreateCharacter(armoury, currentCharacters);
  }
}

void CompareCharacters(
    const std::vector<std::unique_ptr<Character>> &characters) {
  for (unsigned int i = 0; i < characters.size(); i++) {
    std::cout << i + 1 << " - " << characters[i]->GetName() << std::endl;
  }

  std::cout << "Please select the first character: ";
  int input = ValidateIntegerInput(1, characters.size() + 1);
  const auto c = characters[input - 1].get();

  std::cout << c->GetName() << " selected" << std::endl;
  std::cout << "Please select the second character: ";
  int firstCharacterIndex = input;
  while ((input = ValidateIntegerInput(
              1, characters.size() + 1,
              "Please select the second character: ")) == firstCharacterIndex) {
    std::cout << "These are the same characters!";
  }
  const auto &c2 = *characters[input - 1].get();
  system("CLS");
  c->PrintComparison(c2);
}

void PrintCharacter(const std::vector<std::unique_ptr<Character>> &characters,
                    bool printAll) {
  if (printAll) {
    for (unsigned int i = 0; i < characters.size(); i++) {
      std::cout << i + 1 << " - " << *characters[i] << std::endl;
    }
    return;
  } else {
    const int arrSize = characters.size();
    for (unsigned int i = 0; i < characters.size(); i++) {
      std::cout << i + 1 << " - " << characters[i]->GetName() << std::endl;
    }
    std::cout << "Which character would you like to display?" << std::endl
              << "You have " << arrSize << " characters: ";
    int input = ValidateIntegerInput(1, arrSize + 1);

    std::cout << *characters[input - 1] << std::endl;
  }
}
} // namespace validator
