#include "drama.h"
#include <iostream>

using namespace std;

DramaFactory::DramaFactory() {
    registerType ("D", this);
}

Movie *DramaFactory::makeMovie() const {
    return new Drama();
}

void Drama::readData (istream &is) {
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

void Drama::print (ostream &os) const {
    os << director << ", " << title << ", " << year << " (" << stock << ")" << endl;
}

DramaFactory anonymous_DramaFactory;
