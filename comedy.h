#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
    int year;

    Comedy() = default;

    void readData (istream &is) override;

    char getType() const override;

    void print (ostream &os) const override;

    bool isEqual (const Movie &other) const override;
};

class ComedyFactory : public MovieFactory {
public:
    ComedyFactory();
    Movie *makeMovie() const override;
};

#endif // COMEDY_H