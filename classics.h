#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"

class Classics : public Movie {
public:
    int majorActorReleaseDate;

    Classics() = default;

    void readData (istream &is) override;
};

class ClassicsFactory : public MovieFactory {
public:
    ClassicsFactory();
    Movie *makeMovie() const override;
};

#endif // CLASSICS_H