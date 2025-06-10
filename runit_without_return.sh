rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp movie.cpp command.cpp inventory.cpp classics.cpp comedy.cpp drama.cpp store_test.cpp customer.cpp borrow.cpp history.cpp
./a.out