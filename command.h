#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <map>

using namespace std;

class Command;

class CommandFactory {
public:
    virtual Command *makeCommand() const = 0;

    static Command *create (const string &code);

protected:
    static void registerCode (const string &code, CommandFactory *factory);

private:
    static map <string, CommandFactory *> &getMap();
};

class Command {
public:
    virtual void readData (istream &is) = 0;
    virtual ~Command () = default;
    
};


#endif // COMMAND_H