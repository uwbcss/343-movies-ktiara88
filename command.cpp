#include "command.h"
#include <iostream>

using namespace std;

map<string, CommandFactory *> &CommandFactory::getMap() {
  static map<string, CommandFactory *> factories;
  return factories;
}

void CommandFactory::registerCode(const string &code, CommandFactory *factory) {
  getMap().emplace(code, factory);
}

Command *CommandFactory::create(const string &code) {
  if (!getMap().count(code)) {
    cout << "Invalid code: " << code << endl;
    return nullptr;
  }
  return getMap().at(code)->makeCommand();
}
