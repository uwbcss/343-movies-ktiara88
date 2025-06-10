#include "customer.h"
#include "movie.h"
#include <iostream>
#include <sstream>

Customer::Customer(int id, const string &lastName, const string &firstName) {
  this->id = id;
  this->lastName = lastName;
  this->firstName = firstName;
}

void Customer::printInfo() {
  cout << id << " " << lastName << " " << firstName;
}
void Customer::readData(istream &is) { is >> id >> lastName >> firstName; }
void Customer::addTransaction(const string &action, const Movie *movie) {
  stringstream ss;
  ss << action << ": " << *movie;
  history.push_back(ss.str());
}

bool Customer::hasBorrowed(const Movie *movie) const {
  return currentlyBorrowed.count(movie);
}

void Customer::borrowMovie(const Movie *movie) {
  currentlyBorrowed.insert(movie);
  addTransaction("Borrowed", movie);
}

void Customer::returnMovie(const Movie *movie) {
  currentlyBorrowed.erase(movie);
  addTransaction("Returned", movie);
}

void Customer::printHistory() const {
  cout << "History for " << id << " " << lastName << " " << firstName << ":"
       << endl;
  if (history.empty()) {
    cout << "No history for " << lastName << " " << firstName << endl;
  }
  for (const auto &entry : history) {
    cout << "  " << entry << "\n";
  }
}

int Customer::getID() const { return id; }
