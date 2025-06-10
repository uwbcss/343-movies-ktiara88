#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include <vector>
#include <map>
#include <string>

using namespace std;

class Inventory : public Command {
public:

    Inventory() = default;

    void readData (istream &is) override;

    void addMovie (Movie *movie);

    void printInventory () const;

    Movie* findMovie (const Movie *Movie) const; 

private:
    // the char will store the type, and the vector will contain the movie, which contains the infoAdd commentMore actions
    map <char, vector <Movie*>> moviesByType;
};

class InventoryFactory : public CommandFactory {
public:
    InventoryFactory();
    Command *makeCommand() const override;
};

#endif // INVENTORY_H