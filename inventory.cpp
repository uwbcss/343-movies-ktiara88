#include "inventory.h"
#include <iostream>

using namespace std;

InventoryFactory::InventoryFactory() {
    registerCode ("I", this);
}

Command *InventoryFactory::makeCommand() const {
    return new Inventory;
}

void Inventory::readData (istream &is) {
    // no extra info for Invetory command, so just discard string
    string s;
    getline (is, s);
    printInventory();
}

void Inventory::addMovie (const Movie *movie) {

}

void Inventory::printInventory() const {
    for (const auto &pair : moviesByType) {
        const string &movieType = pair.first;
        const vector <Movie*> &movies = pair.second;

        cout << "====== Inventory for Movie Type: " << movieType << " ======" << endl;

        for (const Movie* m : movies) {
            cout << m << endl;
        }
    }
}