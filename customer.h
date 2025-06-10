#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "movie.h"
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Movie; 

class Customer {
public:
    Customer() = default;
    Customer(int id, const string& lastName, const string& firstName);

    void printInfo ();
    void readData (istream& is);
    void addTransaction (const string& action, const Movie* movie);
    bool hasBorrowed (const Movie* movie) const;
    void borrowMovie(const Movie* movie);
    void returnMovie(const Movie* movie);
    void printHistory() const;
    int getID() const;

private:
    int id;
    string firstName;
    string lastName;
    vector <string> history;
    unordered_set <const Movie*> currentlyBorrowed;

};
#endif // CUSTOMER_H