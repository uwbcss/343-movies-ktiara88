#include "inventory.h"
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

InventoryFactory::InventoryFactory() { registerCode("I", this); }

Command *InventoryFactory::makeCommand() const { return new Inventory; }

void Inventory::readData(istream &is) {
  // no extra info for Inventory command, so just discard string
  string s;
  getline(is, s);
  printInventory();
}

void Inventory::addMovie(Movie *movie) {
  if (movie == nullptr)
    return;
  char type = movie->getType();
  moviesByType[type].push_back(movie);
}

void Inventory::printInventory() const {
  auto printCategory = [](const vector<Movie *> &movies, const string &name) {
    cout << "------ " << name << " ------" << endl;
    vector<Movie *> sorted = movies;
    sort(sorted.begin(), sorted.end(),
         [](Movie *a, Movie *b) { return *a < *b; });
    for (const auto &m : sorted) {
      cout << *m << endl;
    }
  };

  cout << "====== Inventory ======" << endl;

  if (moviesByType.count('F')) {
    printCategory(moviesByType.at('F'), "Comedies");
  }

  if (moviesByType.count('D')) {
    printCategory(moviesByType.at('D'), "Dramas");
  }

  if (moviesByType.count('C')) {
    printCategory(moviesByType.at('C'), "Classics");
  }
}

Movie *Inventory::findMovie(const Movie *movie) const {
  if (!movie)
    return nullptr;

  char type = movie->getType();

  // Check if the type exists in the inventory
  auto it = moviesByType.find(type);
  if (it == moviesByType.end())
    return nullptr;

  // Search the vector for a matching movie using isEqual
  const vector<Movie *> &movieList = it->second;
  for (Movie *m : movieList) {
    if (m->isEqual(*movie)) {
      return m;
    }
  }

  // No match found
  return nullptr;
}

InventoryFactory anonymous_InventoryFactory;