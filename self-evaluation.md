# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: -0

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: TODO(student)
Return: TODO(student)


Q: -1 for each compilation warning, min -3: ENTER_NUMBER

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: ENTER_NUMBER

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: ENTER_NUMBER

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: ENTER_NUMBER

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: ENTER_NUMBER

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): ENTER_NUMBER

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: command.cpp: Command *CommandFactory::create (const string &code)

invalid movie type: movie.cpp: Movie *MovieFactory::create (const string &type, istream &is)

invalid customer ID: history.cpp: void History::readData(istream& is)
 
invalid movie: TODO(student)

factory classes: command.h/command.cpp and movie.h/movie.cpp

hashtable: inventory.h where map <char, vector <Movie*>> stores moviesByType, placing the keys (char), in individual buckets for O(1) retrieval

container used for comedy movies: inventory.h: map <char, vector <Movie*>> moviesByType;

function for sorting comedy movies: inventory.cpp: void Inventory::printInventory() (use a sort function with underlying operator< overload)

function where comedy movies are sorted: inventory.cpp void: Inventory::printInventory() sorted when the function is called

functions called when retrieving a comedy movie based on title and year: TODO(student)

functions called for retrieving and printing customer history: history.cpp: void History::readData(istream& is), and customer.cpp: void Customer::printHistory() const

container used for customer history: history.h: unordered_map <int, Customer*> customerDB;

functions called when borrowing a movie: TODO(student)

explain borrowing a movie that does not exist: TODO(student)

explain borrowing a movie that has 0 stock: TODO(student)

explain returning a movie that customer has not checked out: TODO(student)

any static_cast or dynamic_cast used: dynamic_cast used in comedy.cpp, drama.cpp, and classics.cpp in isEqual and lessThan functions

## Bonus +5

Are there multiple files, of the form runit-without-XXX, where the same set of files will compile and run excluding some of the commands or genres? YES



Q: Total points: ADD_ALL_POINTS (max 25 (+ 5 Bonus))