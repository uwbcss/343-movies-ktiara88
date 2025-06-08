#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"
#include "movie.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class Inventory : public Command {
public:

    Inventory() = default;

    void readData (istream &is) override;

    void addMovie (const Movie *movie);

    void printInventory () const;


private:
    // the string will store the type, and the vector will contain the movie, which contains the info
    map <string, vector <Movie*>> moviesByType;

};

class InventoryFactory : public CommandFactory {
public:
    InventoryFactory();
    Command *makeCommand() const override;
};

#endif // INVENTORY_H