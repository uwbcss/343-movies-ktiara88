#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"
#include <string>

class Comedy : public Movie {
public:

    Comedy() = default;

    void readData (istream &is) override;

    char getType() const override;

    void print (ostream &os) const override;

    bool isEqual (const Movie &other) const override;

    bool lessThan (const Movie &other) const override;
};

class ComedyFactory : public MovieFactory {
public:
    ComedyFactory();
    Movie *makeMovie() const override;
};

#endif // COMEDY_H