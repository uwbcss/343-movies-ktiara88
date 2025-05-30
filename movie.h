#ifndef MOVIE_H
#define MOVIE_H

#include <map>
#include <string>

using namespace std;

class Movie;

class MovieFactory {
public:
    virtual Movie *makeMovie() const = 0;

    static Movie *create (const string &type);

protected:
    static void registerType (const string &type, MovieFactory *factory);

private:
    static map <string, MovieFactory *> &getMap();
};

class Movie {
public:
    // add movie functions
    virtual void readData (istream &is) = 0;
    virtual ~Movie () = default;
    int stock;
    string director;
    string title;
};

#endif // MOVIE_H