#ifndef HISTORY_H
#define HISTORY_H

#include "command.h"
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "classics.h"
#include "customer.h"
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class History: public Command {
public:
    History() = default;

    void readData (istream &is) override;

    void addCustomer (Customer* c);

    void printAllHistory () const;

private:
    // id and customer
    unordered_map <int, Customer*> customerDB;
};

class HistoryFactory : public CommandFactory {
public:
    HistoryFactory();
    Command *makeCommand() const override;
};


#endif // HISTORY_H