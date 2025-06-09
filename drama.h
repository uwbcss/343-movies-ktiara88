#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"

class Drama : public Movie {
public:
    int year;

    Drama() = default;
    
    void readData (istream &is) override;

    void print (ostream &os) const override;
};

class DramaFactory : public MovieFactory {
public:
    DramaFactory();
    Movie *makeMovie() const override;
};

#endif // DRAMA_H