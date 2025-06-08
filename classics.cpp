#include "classics.h"
#include <iostream> 

using namespace std;

ClassicsFactory:: ClassicsFactory() {
    registerType ("C", this);
}

Movie *ClassicsFactory::makeMovie() const {
    return new Classics();
}

void Classics::readData (istream &is) {
     string stockString, directorString, titleString, majorReleaseString;

     getline(is, stockString, ',');
    stock = stoi (stockString);

    getline (is, directorString, ',');
    director = directorString;

    getline (is, titleString, ',');
    title = titleString;

    getline (is, majorReleaseString);
    majorActorReleaseDate = stoi(majorReleaseString);
}