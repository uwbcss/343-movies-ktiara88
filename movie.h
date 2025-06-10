#ifndef MOVIE_H
#define MOVIE_H

#include <map>
#include <string>

using namespace std;

class Movie;

class MovieFactory {
public:
    virtual Movie *makeMovie() const = 0;

    static Movie *create (const string &type, istream &is);

protected:
    static void registerType (const string &type, MovieFactory *factory);

private:
    static map <string, MovieFactory *> &getMap();
};

class Movie {
public:
    virtual void readData (istream &is) = 0;
    virtual ~Movie () = default;
    virtual void print (ostream &os) const = 0;
    friend ostream &operator << (ostream &os, const Movie &movie);
    virtual char getType() const = 0;
    bool operator==(const Movie &m) const;
    virtual bool isEqual (const Movie &other) const = 0;
    bool operator<(const Movie &m) const;
    virtual bool lessThan (const Movie &other) const = 0;
    string trim(const string &str);

    int stock;
    string director;
    string title;
    int year;
};


#endif // MOVIE_H