#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"

class Classics : public Movie {
public:
    string majorActor;
    int releaseDate;

    Classics() = default;

    void readData (istream &is) override;

    char getType() const override;

    void print (ostream &os) const override;

    bool isEqual (const Movie &other) const override;
};

class ClassicsFactory : public MovieFactory {
public:
    ClassicsFactory();
    Movie *makeMovie() const override;
};

#endif // CLASSICS_H