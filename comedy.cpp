
#include "comedy.h"
#include <iostream>

using namespace std;

ComedyFactory::ComedyFactory() {
    registerType ("F", this);
}

Movie *ComedyFactory::makeMovie() const {
    return new Comedy();
}

void Comedy::readData (istream &is) {
    string stockString, directorString, titleString, yearString;
    
    getline(is, stockString, ',');
    stock = stoi (stockString);

    getline (is, directorString, ',');
    director = directorString;

    getline (is, titleString, ',');
    title = titleString;

    getline (is, yearString);
    year = stoi(yearString);
}

void Comedy::print (ostream &os) const {
    os << title << ", " << year << ", " << director << " (" << stock << ")";
}

ComedyFactory anonymous_ComedyFactory;