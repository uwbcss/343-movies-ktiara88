#include "movie.h"
#include <iostream>

using namespace std;

map<string, MovieFactory *> &MovieFactory::getMap() {
  static map<string, MovieFactory *> factories;
  return factories;
}

void MovieFactory::registerType(const string &type, MovieFactory *factory) {
  getMap().emplace(type, factory);
}

Movie *MovieFactory::create(const string &type, istream &is) {
  if (!getMap().count(type)) {
    string discardedLine;
    getline(is, discardedLine);
    cout << "Invalid movie type: " << type
         << ", discarding line:" << discardedLine << endl;
    return nullptr;
  }
  return getMap().at(type)->makeMovie();
}
ostream &operator<<(ostream &os, const Movie &movie) {
  movie.print(os);
  return os;
}

bool Movie::operator==(const Movie &m) const { return this->isEqual(m); }

bool Movie::operator<(const Movie &m) const { return this->lessThan(m); }

string Movie::trim(const string &str) {
  const auto strBegin = str.find_first_not_of(" \t\r\n");
  if (strBegin == string::npos)
    return ""; // no content

  const auto strEnd = str.find_last_not_of(" \t\r\n");
  const auto strRange = strEnd - strBegin + 1;

  return str.substr(strBegin, strRange);
}
