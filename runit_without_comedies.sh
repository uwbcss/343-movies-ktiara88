rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp movie.cpp command.cpp inventory.cpp drama.cpp classics.cpp store_test.cpp
./a.out