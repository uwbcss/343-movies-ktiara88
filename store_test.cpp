/**
 * Testing ass4 movie store functions
 *
 * @author Yusuf Pisan
 * @date 19 Jan 2019
 */

#include "customer.h"
#include "history.h"
#include "inventory.h"
#include "movie.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

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
    if (line.empty())
      continue;

    stringstream ss(line);
    string type;
    getline(ss, type, ','); // get movie type (F, D, C)

    Movie *movie = MovieFactory::create(type, ss);
    if (movie != nullptr) {
      movie->readData(ss);
      inventory.addMovie(movie);
    }
  }

  infile.close();

  // Can print the loaded inventory for debugging
  inventory.printInventory();
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
    if (line.empty())
      continue;

    stringstream ss(line);

    Customer *c = new Customer();
    c->readData(ss);
    if (c != nullptr) {
      h.addCustomer(c);
    }
  }
  // can print all history for debugging
  h.printAllHistory();
  infile.close();
  cout << "End testLoadCustomers\n" << endl;
}

void testStoreFinal() {
  cout << "=====================================" << endl;
  cout << "Start testStoreFinal" << endl;

  Inventory inventory;
  unordered_map<int, Customer *> customerDB;

  // 1. Load movies
  ifstream movieFile("data4movies.txt");
  if (!movieFile) {
    cerr << "Failed to open movie file" << endl;
    return;
  }

  string movieLine;
  while (getline(movieFile, movieLine)) {
    if (movieLine.empty())
      continue;

    stringstream ss(movieLine);
    string type;
    getline(ss, type, ',');

    Movie *movie = MovieFactory::create(type, ss);
    if (movie) {
      movie->readData(ss);
      inventory.addMovie(movie);
    }
  }
  movieFile.close();

  // 2. Load customers
  ifstream customerFile("data4customers.txt");
  if (!customerFile) {
    cerr << "Failed to open customer file" << endl;
    return;
  }
  string line;
  History h;
  while (getline(customerFile, line)) {
    if (line.empty())
      continue;

    stringstream ss(line);

    Customer *c = new Customer();
    c->readData(ss);
    if (c != nullptr) {
      h.addCustomer(c);
    }
  }

  ifstream commandFile("data4commands.txt");
  if (!commandFile) {
    cerr << "Failed to open command file" << endl;
    return;
  }

  string cmdLine;
  while (getline(commandFile, cmdLine)) {
    if (cmdLine.empty())
      continue;

    stringstream ss(cmdLine);
    string cmdCode;
    ss >> cmdCode;

    Command *cmd = CommandFactory::create(cmdCode);
    if (!cmd)
      continue;
    cmd->readData(ss);
  }

  commandFile.close();

  cout << "End testStoreFinal" << endl;
  cout << "=====================================" << endl;
}

void testAll() {
  testLoadMovies();
  testLoadCustomers();

  testStoreFinal();
}
