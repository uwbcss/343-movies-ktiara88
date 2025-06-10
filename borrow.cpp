#include "borrow.h"
#include "movie.h"
#include <iostream>
#include <sstream>

using namespace std;

Borrow::Borrow (unordered_map <int, Customer*>& customers, Inventory& inv)
    : customerDB (customers), inventory (inv) {}

void Borrow::readData (istream& is) {
    int customerID;
    char mediaType, movieType;

    is >> customerID >> mediaType >> movieType;

    if (mediaType != 'D') {
        cout << "Invalid media type '" << mediaType << "' for customer " << customerID << endl;
        return;
    }
    if (customerDB.find(customerID) == customerDB.end()) {
        cout << "Unknown customer ID: " << customerID << endl;
        return;
    }
    stringstream movieData;
    string restOfLine;
    getline(is, restOfLine); // get the rest of the movie info
    movieData << movieType << "," << restOfLine;

    Movie* tempMovie = MovieFactory::create(string(1, movieType), is);
    if (!tempMovie) {
        cout << "Invalid movie type '" << movieType << "'." << endl;
        return;
    }

    tempMovie->readData(movieData);

    Movie* actualMovie = inventory.findMovie(tempMovie);
    delete tempMovie;

    if (!actualMovie) {
        cout << "Movie is not in our inventory." << endl;
        return;
    }

    if (actualMovie->stock <= 0) {
        cout << "The movie '" << actualMovie->title << "' is out of stock. Cannot borrow." << endl;
        return;
    }

    actualMovie->stock--; // borrow, so decrease stock
    customerDB[customerID]->addTransaction("Borrowed: " + actualMovie->title);
}

BorrowFactory::BorrowFactory(unordered_map<int, Customer*>& customers, Inventory& inv)
    : customerDB(customers), inventory(inv) {
    registerCode("B", this);
}

Command* BorrowFactory::makeCommand() const {
    return new Borrow(customerDB, inventory);
}