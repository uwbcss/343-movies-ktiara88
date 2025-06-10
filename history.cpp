#include "history.h"
#include <iostream>

using namespace std;

void History::readData(istream &is) {
  int id;
  is >> id;

  auto it = customerDB.find(id);
  if (it == customerDB.end()) {
    cout << "Invalid customer ID: " << id << endl;
    return;
  }
  Customer *customer = it->second;
  customer->printHistory();
}

void History::addCustomer(Customer *c) {
  if (!c)
    return;

  int id = c->getID();
  if (customerDB.find(id) == customerDB.end()) {
    customerDB[id] = c;
  } else {
    cout << "Customer ID " << id
         << " already exists in the database. Skipping.\n";
  }
}

void History::printAllHistory() const {
  for (auto &pair : customerDB) {
    pair.second->printHistory();
  }
}

HistoryFactory::HistoryFactory() { registerCode("H", this); }

Command *HistoryFactory::makeCommand() const { return new History; }

HistoryFactory anonymous_HistoryFactory;