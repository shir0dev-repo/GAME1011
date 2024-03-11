#include <cassert>
#include <ctime>
#include <iostream>
#include <limits>
#include <string>

#include "header/knight.h"
#include "header/orc.h"
#include "header/undead.h"
#include "header/wizard.h"

int main() {
  // init random
  srand(std::time(NULL));

  // init actors
  player *plr;
  enemy *enemy;

  // greet player
  std::cout << "Welcome to the NotSoAccurate Battle Simulator! " << std::endl;

  // get class choice
  std::cout << "Would you like to play as a wizard (1) or knight(2)?"
            << std::endl;

  // get valid class input
  std::string classChoice;
  while ((std::cin >> classChoice)) {
    // player chose wizard
    if (classChoice == "wizard" || classChoice == "1") {
      std::cout << "You picked wizard! Great choice!" << std::endl;

      // get player name
      std::cout << "Give your character a name: " << std::endl;
      std::string name;
      std::cin >> name;

      // create new wizard
      plr = new wizard(name, 15, 10);
      break;

    }
    // player chose knight
    else if (classChoice == "knight" || classChoice == "2") {

      std::cout << "You picked knight! Great choice!" << std::endl;
      std::cout << "Give your character a name: " << std::endl;
      std::string name;
      std::cin >> name;

      // create new player
      plr = new knight(name, 25, 12);
      break;
    }
    // invalid choice
    else {
      // handle invalid input
      std::cout << "Please select a valid class!" << std::endl;

      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      classChoice.clear();
    }
  }

  // make sure plr is not a nullptr.
  assert(plr != nullptr);

  // display character stats
  std::cout << "Here's all you need to know about your character!" << std::endl;
  std::cout << *plr << std::endl;

  // get yes/no prompt (aware it does not matter which input, i just found it
  // funny :D)
  std::string yn;
  do {
    std::cout << "Are you ready to witness the most exciting, gut-wrenching, "
                 "nail-biting fight of your life!? (Y/N)"
              << std::endl;

    std::cin >> yn;
    if (std::tolower(yn[0]) == 'n') {
      std::cout << "Good thing this wont be that." << std::endl;
      break;
    } else if (std::tolower(yn[0]) == 'y') {
      std::cout << "Too bad, how about this instead?" << std::endl;
      break;
    }
  } while (true);

  // create random enemy
  if (rand() % 2 == 0) {
    enemy = new undead(40);
  } else {
    enemy = new orc(45);
  }

  std::cout << "Enemy stats: " << std::endl << *enemy << std::endl;

  // battle start
  std::cout << "BEGIN!" << std::endl;

  enemy->tauntPlayer();
  plr->normalAttack();
  enemy->takeDamage(6);
  enemy->tauntPlayer();
  plr->specialAttack();
  enemy->takeDamage(plr->getSpecialAttackDamage());

  enemy->normalAttack();
  plr->takeDamage(5);
  enemy->normalAttack();
  plr->takeDamage(5);

  plr->specialAttack();
  enemy->takeDamage(plr->getSpecialAttackDamage());

  enemy->tauntPlayer();

  plr->specialAttack();
  enemy->takeDamage(plr->getSpecialAttackDamage());

  std::cout << std::endl
            << "The battle is over! " << plr->getName() << " is victorious!"
            << std::endl;

  // clean-up player and enemy
  delete plr;
  delete enemy;

  std::cin;

  return 0;
}