This is a hash table for strings that I implemented in C++ from scratch.  Attached
to the hash table is file called wordPuzzle.cpp that completes a word
search on one of the grid files.  I wrote the algorithm that searches
through the word grid for the words in the dictionary, and I am particularly
proud of its efficiency.

Below is a breif description of each file, and it's function:

Makefile: for make, if you have it installed "make hash" is the default
command, and it will compile the word search program.

hashTable.h: a fully functional hash table with constant search time. For
the interested a further description of it is available in a comment at
the top of the file

hashTable.cpp: The implementation of the hashTable

timer.h: A timer I did not write that I use to calculate the runtime of
wordPuzzle.

wordPuzzle.cpp: a sample program that demonstrates the hash table's functionality

XxY.grid.txt: a data structure containing a grid of letters, word search puzzles

words.txt/words2.txt: dictionaries for wordPuzzle.

a.out: the executable for the word search, should you like to try it.

