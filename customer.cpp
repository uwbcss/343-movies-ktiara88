#include "customer.h"
#include <iostream>

Customer::Customer(int id, const string& lastName, const string& firstName) {
    this->id = id;
    this->lastName = lastName;
    this->firstName = firstName;
}

void Customer::printInfo () {
    cout << id << " " << lastName << " " << firstName;
}
void Customer::readData (istream& is) {
    is >> id >> lastName >> firstName;
}
void Customer::addTransaction (const string& transaction) {
    history.push_back(transaction);
}
