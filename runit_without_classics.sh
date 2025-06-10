#!/bin/bash

# shortcut to compile and run the program

rm -f a.out
g++ -g -std=c++11 -Wall -Wextra -Wno-sign-compare main.cpp movie.cpp command.cpp inventory.cpp drama.cpp comedy.cpp store_test.cpp customer.cpp borrow.cpp history.cpp return.cpp
./a.out