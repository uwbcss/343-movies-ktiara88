#ifndef BORROW_H
#define BORROW_H

#include "command.h"
#include "customer.h"
#include "movie.h"
#include "inventory.h"
#include <unordered_map>
#include <string>

class Borrow : public Command {
public: 
    Borrow () = default;

    Borrow (unordered_map<int, Customer*>& customers, Inventory& inventory);

    void readData (istream &is) override;

private: 
    unordered_map<int, Customer*>& customerDB;
    Inventory& inventory;
};

class BorrowFactory : public CommandFactory {
public:
    BorrowFactory(unordered_map<int, Customer*>& customers, Inventory& inventory);
    Command* makeCommand() const override;

private:
    unordered_map<int, Customer*>& customerDB;
    Inventory& inventory;
};


#endif // BORROW_H