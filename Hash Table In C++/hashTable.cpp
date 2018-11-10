//Jay Rothenberger (jr2fh) hashTable.cpp 10/23/18

#include <string>
#include <vector>
#include <math.h>
#include <cstring>
#include <string.h>

#include "hashTable.h"

using namespace std;

hashTable::hashTable(){

  v = new vector<string>();
  prime = 5501;
  v->resize(prime*5);

}
hashTable::~hashTable(){

  delete v;

}
//constructors
void hashTable::insert(const string s){
    //This function inserts a string into the hash table
  long i = hashString(s);
  if(i < 0){
    return;
  }
    //checks to see if there is an empty slot at the current hash value
  
  if(strncmp((*v)[i].c_str(), "", 1) == 0 || (*v)[i] == s || (*v)[prime] == s){
    (*v)[i] = s;
  }else if(strncmp((*v)[prime + i].c_str(), "", 1) == 0 || (*v)[i + prime] == s){
    (*v)[prime + i] = s;
  }else if(strncmp((*v)[2*prime + i].c_str(), "", 1) == 0 || (*v)[i + 2*prime] == s){
    (*v)[2*prime + i] = s;
  }else if(strncmp((*v)[3*prime + i].c_str(), "", 1) == 0 || (*v)[i + 3*prime] == s){
    (*v)[3*prime + i] = s; 
  }else if(strncmp((*v)[4*prime + i].c_str(), "", 1) == 0 || (*v)[i + 4*prime] == s){
    (*v)[4*prime + i] = s;
  }
  else{
    //otherwise rehash the values into a larger table
    rehash();
    insert(s);
  }
   
    
}
bool hashTable::includes(const string s){
  //this function returns true if the hash table contains the string s, and false otherwise

  int i = hashString(s);
  

  if((*v)[i] == s){
    
    return true;
  }
  else if((*v)[prime + i] == s){

    return true;
  }
  else if((*v)[2*prime + i] == s){

    return true;
  }else if((*v)[3*prime + i] == s){

    return true;
  }else if((*v)[4*prime + i] == s){

    return true;
  }
  else
    return false;
}
void hashTable::rehash(){
    //this function creates a larger table and rehashes all of the values in the current table into it
  prime = getNextPrime(2*prime);

  unsigned long size = 5*prime;

  vector<string>* newV = new vector<string>;
  newV->resize(size);
  int i;
  for(i = 0; i < v->size(); i++){
    long reindex = hashString((*v)[i]);
    if(reindex < 0){}
    else{
      if(strncmp((*newV)[reindex].c_str(), "", 1) == 0 || (*newV)[reindex] == (*v)[i]){
	(*newV)[reindex] = (*v)[i];
      }else if(strncmp((*newV)[prime+reindex].c_str(), "", 1) == 0){
	(*newV)[prime+reindex] = (*v)[i];
      }else if(strncmp((*newV)[2*prime+reindex].c_str(), "", 1) == 0){
	(*newV)[2*prime+reindex] = (*v)[i];
      }else if(strncmp((*newV)[3*prime+reindex].c_str(), "", 1) == 0){
	(*newV)[3*prime+reindex] = (*v)[i];
      }else if(strncmp((*newV)[4*prime+reindex].c_str(), "", 1) == 0){
	(*newV)[4*prime+reindex] = (*v)[i];
      }
      else{
	delete newV;
	rehash();
	return;
      }
    }
  }
  v = newV;
  return;
}

long hashTable::hashString(string s){
    //here is the hash function for the string s.  It should be 1-1 for strings whose hash value is less than the largest long.
    
  long l = 0;

  if(strncmp(s.c_str(), "", 1) == 0)
    return -1;
  
  for(int i = 0; i < s.size(); i++){
	l = l*31 + s[i];
  }

  long hash = (l)%prime;

  return hash;

}
int hashTable::getNextPrime(unsigned int n){
    //Finds the next prime after an unsigned integer

    while ( !checkprime(++n) );
    return n; // all your primes are belong to us

}
bool hashTable::checkprime(unsigned int p){

    if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;

}

