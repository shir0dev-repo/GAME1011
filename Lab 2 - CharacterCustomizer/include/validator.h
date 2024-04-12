#pragma once

#include <iostream>
#include <istream>
#include <string>
#include <vector>

class Character;
class Armoury;

namespace validator {

static bool shouldExit = false;

inline void CinClear() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int ValidateIntegerInput(
    int minValue, int maxValue,
    std::string errmsg = "Please enter a valid integer!: ");
bool ValidateBooleanInput();
std::string ValidateStringInput();

// commands
void ListCommands();
void HandleCommand(Armoury &, std::vector<std::unique_ptr<Character>> *);
bool ValidateCommand(std::string input);

void CreateCharacter(
    Armoury *armoury,
    std::vector<std::unique_ptr<Character>> *currentCharacterCount);

void CompareCharacters(const std::vector<std::unique_ptr<Character>> &);

void PrintCharacter(const std::vector<std::unique_ptr<Character>> &, bool);
} // namespace validator