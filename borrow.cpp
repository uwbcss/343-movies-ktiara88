#include "borrow.h"
#include "movie.h"
#include <iostream>
#include <sstream>

using namespace std;

Borrow::Borrow(unordered_map<int, Customer *> &customers, Inventory &inv)
    : customerDB(customers), inventory(inv) {}

void Borrow::readData(istream &is) {
  int customerID;
  char mediaType, movieType;

  is >> customerID >> mediaType >> movieType;

  if (mediaType != 'D') {
    cout << "Invalid media type '" << mediaType << "' for customer "
         << customerID << endl;
    return;
  }

  if (customerDB.find(customerID) == customerDB.end()) {
    cout << "Unknown customer ID: " << customerID << endl;
    return;
  }

  string restOfLine;
  getline(is, restOfLine); // Read the rest of the movie line
  stringstream movieData;
  movieData << movieType << "," << restOfLine;

  // Create a temporary movie object
  Movie *tempMovie = MovieFactory::create(string(1, movieType), is);
  if (!tempMovie) {
    cout << "Invalid movie type '" << movieType << "'." << endl;
    return;
  }

  tempMovie->readData(movieData);

  // Find the actual movie in inventory
  Movie *actualMovie = inventory.findMovie(tempMovie);
  delete tempMovie;

  if (!actualMovie) {
    cout << "Movie is not in our inventory." << endl;
    return;
  }

  if (actualMovie->stock <= 0) {
    cout << "The movie '" << actualMovie->title
         << "' is out of stock. Cannot borrow." << endl;
    return;
  }

  // Decrease stock
  actualMovie->stock--;

  // Record transaction for the customer
  Customer *customer = customerDB[customerID];
  customer->borrowMovie(actualMovie);
  customer->addTransaction("Borrowed", actualMovie);
}

BorrowFactory::BorrowFactory(unordered_map<int, Customer *> &customers,
                             Inventory &inv)
    : customerDB(customers), inventory(inv) {
  registerCode("B", this);
}

Command *BorrowFactory::makeCommand() const {
  return new Borrow(customerDB, inventory);
}

// BorrowFactory anonymous_BorrowFactory;