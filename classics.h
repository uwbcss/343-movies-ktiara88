#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"

class Classics : public Movie {
public:
    string majorActor;
    int releaseDate;

    Classics() = default;

    void readData (istream &is) override;

    void print (ostream &os) const override;
};

class ClassicsFactory : public MovieFactory {
public:
    ClassicsFactory();
    Movie *makeMovie() const override;
};

#endif // CLASSICS_H