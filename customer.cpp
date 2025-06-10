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
void Customer::printHistory() const {
    cout << "History for " << id << " " << lastName << " " << firstName << ":" << endl;
    if (history.empty()) {
        cout << "No history for " << lastName << " " << firstName << endl;
    }
    for (const auto& entry : history) {
        cout << "  " << entry << "\n";
    }
}
int Customer::getID() const{
    return id;
}
