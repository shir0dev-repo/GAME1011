#include "header/wizard.h"
#include "header/knight.h"
#include "header/orc.h"
#include "header/undead.h"
#include <ostream>

int main() {

  wizard wiz("jerry", 25, 10);
  knight kn("tom", 50, 12);

  orc oc(25);
  undead ud(15);

  std::cout << wiz << kn << oc << ud << std::endl;
  std::string str;
  std::cin >> str;

  return 0;
}