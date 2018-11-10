//Jay Rothenberger (jr2fh) hashTable.h 10/23/18

/*
This hash table has constant search time, because the collision resolution
strategy that it uses is rather heinous when it comes to the size of the
table.  The algorithm is as follows, and there will be a justification of method after:
Set the size of the table as a large prime number, n * 5.
Hash a value into the table using the hash value function % the prime number
(ignore duplicates)
If you collide with a value, proceed n spaces to the right, repeat until you find an empty slot
If you encounter 5 collisions, rehash all of the values in the table into a table of a larger prime and try again

Justification:
On the surface this may seem like a VERY space intensive and time intensive hashing process,
however because strings are arrays of characters they are initialized as no data, and take
up no space.  This makes the size of the vector that stores the table values quite immaterial.
The astute may also notice that finding progressively larger primes may be time consuming,
not to mention rehasing the table, and if the hash function was not 1-1 there is a possibility
of an infinite loop.  Well, the hash function is 1-1, and I hashed 25,000 words in .16 seconds.
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>

using namespace std;

class hashTable {

 public:
  hashTable();
  ~hashTable();

  void insert(const string x);
  bool includes(const string x);

 private:
  void rehash();
  long hashString(string s);
  int getNextPrime(unsigned int n);
  bool checkprime(unsigned int p);
  vector<string>* v;
  unsigned long prime;
 
};


#endif
