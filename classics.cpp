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
     string stockString, directorString, titleString, majorActorFirstNameString, 
            majorActorLastNameString, releaseDataString;

    getline(is, stockString, ',');
    stock = stoi (stockString);

    getline (is, directorString, ',');
    director = directorString;

    getline (is, titleString, ',');
    title = titleString;

    getline (is, majorActorFirstNameString, ' ');
    getline (is, majorActorLastNameString, ' ');

    majorActor = majorActorFirstNameString + majorActorLastNameString;

    getline (is, releaseDataString);
    releaseDate = stoi(releaseDataString);

}

char Classics::getType() const {
    return 'C';
}

void Classics::print (ostream &os) const {
    os << releaseDate << ", " << majorActor << ", " << director << ", " << title << " (" << stock << ")" << endl;
}

bool Classics::isEqual (const Movie &other) const {
    const Classics* otherClassics = dynamic_cast<const Classics*>(&other);
    if (!otherClassics) {
        return false;
    }
    return title == otherClassics->title && 
        releaseDate == otherClassics->releaseDate && 
        majorActor == otherClassics->majorActor &&
        director == otherClassics->director;
}

ClassicsFactory anonymous_ClassicsFactory; 