#include "inventory.h"
#include <iostream>

using namespace std;

InventoryFactory::InventoryFactory() {
    registerCode ("I", this);
}

Command *InventoryFactory::makeCommand() const {
    return new Inventory;
}

void Inventory::addMovie (const Movie *movie) {
    
}

void Inventory::readData (istream &is) {
    /// read data
}
