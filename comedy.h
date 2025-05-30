#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

class Comedy : public Movie {
public:
    Comedy();
};

class ComedyFactory : public MovieFactory {
public:
    ComedyFactory();
    Movie *makeMovie() const override;
};

#endif // COMEDY_H