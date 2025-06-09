#include "movie.h"
#include <iostream>

using namespace std;

map <string, MovieFactory *> &MovieFactory::getMap() {
    static map <string, MovieFactory *> factories;
    return factories;
}

void MovieFactory::registerType (const string &type, MovieFactory *factory) {
    getMap().emplace(type, factory);
}

Movie *MovieFactory::create (const string &type) {
    if (!getMap().count(type)) {
        cout << "Invalid code: " << type << endl;
        return nullptr;
    }
    return getMap().at(type)->makeMovie();
}
ostream &operator << (ostream &os, const Movie &movie) {
    movie.print (os);
    return os;
}

bool Movie::operator==(const Movie &m) const {
    return this->isEqual (m);
}

size_t hash<Movie*>::operator()(const Movie* m) const {
    char type = m->getType();
    switch (type) {
        case 'F': return 0; // comedy
        case 'D': return 1; // drama
        case 'C': return 2; // classics
        default: return 3; // invalid type
    }
}

bool MoviePtrEqual::operator()(const Movie* lhs, const Movie* rhs) const {
        return *lhs == *rhs;
}
