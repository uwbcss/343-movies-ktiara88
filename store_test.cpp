/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <cassert>
#include "movie.h"
#include "inventory.h"
#include "customer.h"
#include "history.h"

using namespace std;

void testLoadMovies() {
  cout << "Start testLoadMovies" << endl;

  Inventory inventory;

  ifstream infile("data4movies.txt");
  if (!infile.is_open()) {
      cerr << "Failed to open file" << endl;
      return;
  }

  string line;
  while (getline(infile, line)) {
      if (line.empty()) continue;

      stringstream ss(line);
      string type;
      getline(ss, type, ','); // get movie type (F, D, C)

      Movie* movie = MovieFactory::create(type, ss);
      if (movie != nullptr) {
          movie->readData(ss);
          inventory.addMovie(movie);
      }
      
  }

  infile.close();

  // Can print the loaded inventory for debugging
  // inventory.printInventory();
  cout << "End testLoadMovies\n" << endl;

}

void testLoadCustomers() {
  cout << "Start testLoadCustomers" << endl;
  ifstream infile("data4customers.txt");
  if (!infile) {
      cerr << "Failed to open customer file: " << endl;
      return;
  }

  string line;
  History h;
  while (getline(infile, line)) {
    if (line.empty()) continue;

    stringstream ss(line);

    Customer* c = new Customer();
    c->readData (ss);
    if (c != nullptr) {
        h.addCustomer (c);
    } 
  }
  // can print all history for debugging
  // h.printAllHistory();
  infile.close();
  cout << "End testLoadCustomers\n" << endl;
}

void testStore1() {
  cout << "Start testStore1" << endl;
  // Should do something more, but lets just read files
  // since each implementation will
  string cfile = "testcommands-1.txt";
  stringstream out;
  ifstream fs(cfile);
  assert(fs.is_open());
  char commandType;
  string discard;
  while (fs >> commandType) {
    out << commandType;
    getline(fs, discard);
  }
  fs.close();
  string result = "IHHBRIBBIH";
  assert(out.str() == result);
  


  cout << "End testStore1\n" << endl;
  
}

void testStore2() {
  cout << "Start testStore2" << endl;
  cout << "End testStore2\n" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;
  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testLoadMovies();
  testLoadCustomers();
  testStore1();
  testStore2();
  testStoreFinal();
}
