#include "return.h"
#include "movie.h"
#include <iostream>
#include <sstream>

using namespace std;

Return::Return(Inventory &inv, unordered_map<int, Customer *> &db)
    : inventory(inv), customerDB(db) {}

void Return::readData(istream &is) {
  int customerID;
  char mediaType, movieType;

  is >> customerID >> mediaType >> movieType;

  if (mediaType != 'D') {
    cerr << "Invalid media type: " << mediaType << endl;
    return;
  }

  if (customerDB.find(customerID) == customerDB.end()) {
    cerr << "Customer ID " << customerID << " not found." << endl;
    return;
  }

  Customer *customer = (customerDB)[customerID];

  string restOfLine;
  getline(is, restOfLine);
  stringstream movieData(restOfLine);

  // Create a temporary movie object for search
  string movieTypeStr(1, movieType);
  Movie *tempMovie = MovieFactory::create(movieTypeStr, movieData);
  if (tempMovie == nullptr) {
    cerr << "Invalid movie type: " << movieType << endl;
    return;
  }

  tempMovie->readData(movieData);

  Movie *actualMovie = inventory.findMovie(tempMovie);
  if (actualMovie == nullptr) {
    cerr << "Movie not found in inventory for return." << endl;
    delete tempMovie;
    return;
  }

  if (!customer->hasBorrowed(actualMovie)) {
    cerr << "Customer " << customerID
         << " did not borrow this movie, cannot return." << endl;
    delete tempMovie;
    return;
  }

  // Success: increase stock and record return
  actualMovie->stock++;
  customer->addTransaction("Returned", actualMovie);

  delete tempMovie;
}

ReturnFactory::ReturnFactory(Inventory &inv, unordered_map<int, Customer *> &db)
    : customerDB(db), inventory(inv) {
  registerCode("R", this);
}

Command *ReturnFactory::makeCommand() const {
  return new Return(inventory, customerDB);
}

// ReturnFactory anonymous_ReturnFactory