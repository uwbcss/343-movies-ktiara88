#ifndef INVENTORY_H
#define INVENTORY_H

#include "command.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Inventory : public Command {
public:

    Inventory() = default;

    void readData (istream &is) override;

    void addMovie (const Movie *movie);

    void printInventory () const;


private:
    // the string will store the movie with the stock for easy stock access
    unordered_map<Movie*, int, hash <Movie*>, MoviePtrEqual> movies;

};

class InventoryFactory : public CommandFactory {
public:
    InventoryFactory();
    Command *makeCommand() const override;
};

#endif // INVENTORY_H