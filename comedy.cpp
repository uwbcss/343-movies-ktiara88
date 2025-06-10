
#include "comedy.h"
#include <iostream>
#include <string>

using namespace std;

ComedyFactory::ComedyFactory() { registerType("F", this); }

Movie *ComedyFactory::makeMovie() const { return new Comedy(); }

void Comedy::readData(istream &is) {
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

char Comedy::getType() const { return 'F'; }

void Comedy::print(ostream &os) const {
  os << title << ", " << year << "," << director << " (" << stock << ")";
}

bool Comedy::isEqual(const Movie &other) const {
  const Comedy *otherComedy = dynamic_cast<const Comedy *>(&other);
  if (!otherComedy) {
    return false;
  }
  return title == otherComedy->title && year == otherComedy->year &&
         director == otherComedy->director;
}

bool Comedy::lessThan(const Movie &other) const {
  const Comedy &rhs = dynamic_cast<const Comedy &>(other);
  if (title != rhs.title) {
    return title < rhs.title;
  }
  return year < rhs.year;
}

ComedyFactory anonymous_ComedyFactory;