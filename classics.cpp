#include "classics.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

ClassicsFactory::ClassicsFactory() { registerType("C", this); }

Movie *ClassicsFactory::makeMovie() const { return new Classics(); }

void Classics::readData(istream &is) {
  string stockString, directorString, titleString;

  // Read comma-separated fields
  getline(is, stockString, ',');
  stock = stoi(trim(stockString)); // use a trim function if needed

  getline(is, directorString, ',');
  director = trim(directorString);

  getline(is, titleString, ',');
  title = trim(titleString);

  // Now read the remaining part from the stream
  string majorActorFirst, majorActorLast;
  int month, year;
  is >> majorActorFirst >> majorActorLast >> month >> year;

  majorActor = majorActorFirst + " " + majorActorLast;
  releaseMonth = month;
  this->year = year;
}

char Classics::getType() const { return 'C'; }

void Classics::print(ostream &os) const {
  os << " " << year << ", " << releaseMonth << ", " << majorActor << ", "
     << director << ", " << title << " (" << stock << ")";
}

bool Classics::isEqual(const Movie &other) const {
  const Classics *otherClassics = dynamic_cast<const Classics *>(&other);
  if (!otherClassics) {
    return false;
  }
  return title == otherClassics->title && year == otherClassics->year &&
         releaseMonth == otherClassics->releaseMonth &&
         majorActor == otherClassics->majorActor &&
         director == otherClassics->director;
}

bool Classics::lessThan(const Movie &other) const {
  const Classics &rhs = dynamic_cast<const Classics &>(other);
  if (year != rhs.year) {
    return year < rhs.year;
  }
  if (releaseMonth != rhs.releaseMonth) {
    return releaseMonth < rhs.releaseMonth;
  }
  return majorActor < rhs.majorActor;
}

ClassicsFactory anonymous_ClassicsFactory;