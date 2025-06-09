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
    // no extra info for Inventory command, so just discard string
    string s;
    getline (is, s);
    printInventory();
}

void Inventory::addMovie (const Movie* movie) {
    // auto it = movies.find(movie);
    // if (it != movies.end()) {
    //     it->second += movie->stock; // Combine stock for duplicates
    // } else {
    //     movies[movie] = movie->stock;
    // }
}

void Inventory::printInventory() const {
    vector <Movie*> comedies;
    vector <Movie*> dramas;
    vector <Movie*> classics;

    for (const auto& pair: movies) {
        Movie* m = pair.first;
        char type = m->getType();
        switch (type) {
            case 'F': comedies.push_back (m); break;
            case 'D': dramas.push_back (m); break;
            case 'C': classics.push_back (m); break;
            default: break;
        }
    }

}