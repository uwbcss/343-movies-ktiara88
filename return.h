#ifndef RETURN_H
#define RETURN_H

#include "command.h"
#include "movie.h"
#include "customer.h"
#include "inventory.h"
#include <unordered_map>
#include <string>

class Return : public Command {
public:
    Return(Inventory& inv, unordered_map<int, Customer*>& db);

    void readData(std::istream& is) override;

private:
    Inventory& inventory;
    unordered_map<int, Customer*>& customerDB;
};

class ReturnFactory : public CommandFactory {
public:
    ReturnFactory(Inventory& inv, unordered_map<int, Customer*>& db);
    Command* makeCommand() const override;

private:
    unordered_map<int, Customer*>& customerDB;
    Inventory& inventory;
};


#endif // RETURN_H