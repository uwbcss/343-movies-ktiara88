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
    friend hash <Movie>; 
public:
    virtual void readData (istream &is) = 0;
    virtual ~Movie () = default;
    virtual void print (ostream &os) const = 0;
    friend ostream &operator << (ostream &os, const Movie &movie);
    bool operator==(const Movie &m) const;

    int stock;
    string director;
    string title;
};

template <> struct hash <Movie> {
    size_t operator()(const Movie &m) const {
        // add operations for the has function
    }
}
#endif // MOVIE_H