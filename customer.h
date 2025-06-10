#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

using namespace std;

class Customer {
public:
    Customer() = default;
    Customer(int id, const string& lastName, const string& firstName);

    void printInfo ();
    void readData (istream& is);
    void addTransaction (const string& transaction);

private:
    int id;
    string firstName;
    string lastName;
    vector <string> history;
};
#endif // CUSTOMER_H