#include "movie.h"
#include <iostream>

using namespace std;

map <string, MovieFactory *> &MovieFactory::getMap() {
    static map <string, MovieFactory *> factories;
    return factories;
}

void MovieFactory::registerType (const string &type, MovieFactory *factory) {
    getMap().emplace(type,factory);
}

Movie *MovieFactory::create (const string &type) {
    if (!getMap().count(type)) {
        cout << "Don't know how to create " << type << "movie" << endl;
        return nullptr;
    }
    return getMap().at(type)->makeMovie();
}