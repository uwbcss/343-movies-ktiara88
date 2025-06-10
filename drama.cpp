#include "drama.h"
#include <iostream>
#include <string>

using namespace std;

DramaFactory::DramaFactory() { registerType("D", this); }

Movie *DramaFactory::makeMovie() const { return new Drama(); }

void Drama::readData(istream &is) {
  string stockString, directorString, titleString, yearString;

  getline(is, stockString, ',');
  stock = stoi(stockString);

  getline(is, directorString, ',');
  director = directorString;

  getline(is, titleString, ',');
  title = titleString;

  getline(is, yearString);
  year = stoi(yearString);
}

char Drama::getType() const { return 'D'; }

void Drama::print(ostream &os) const {
  os << director << "," << title << "," << year << " (" << stock << ")";
}

bool Drama::isEqual(const Movie &other) const {
  const Drama *otherDrama = dynamic_cast<const Drama *>(&other);
  if (!otherDrama) {
    return false;
  }
  return title == otherDrama->title && year == otherDrama->year &&
         director == otherDrama->director;
}

bool Drama::lessThan(const Movie &other) const {
  const Drama &rhs = dynamic_cast<const Drama &>(other);
  if (director != rhs.director) {
    return director < rhs.director;
  }
  return title < rhs.title;
}

DramaFactory anonymous_DramaFactory;
