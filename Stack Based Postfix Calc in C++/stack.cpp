//Jay Rothenberger (jr2fh) 9/20/18 stack.cpp

#include "stack.h"
#include <iostream>

using namespace std;

stack::stack(){

  arr = new int[0];
  size = 0;

}
stack::~stack(){

  delete [] arr;

}
//just constructors
void stack::push(int n){
  
  int *arr1 = new int[sizeof(arr) + 1];

  for(int i = 1; i < sizeof(arr); i++)
    arr1[i] = arr[i-1];

  arr1[0] = n;

  delete [] arr;

  arr = new int[sizeof(arr1)];

  for(int i = 0; i < sizeof(arr); i++)
    arr[i] = arr1[i];

  delete [] arr1;

  size++;

}
/*
what I did here was implement a vector that only grows by one each time
you may be saying "wow, this is really inefficient"
you are right.  It really is, but you're getting a two for one, because
this is not only a stack implementation, it is also a vector implementation.

The item you push is at index 0
*/
void stack::pop(){

  int *arr1 = new int[sizeof(arr)-1];

  for(int i = 0; i < sizeof(arr); i++)
    arr1[i] = arr[i+1];

  delete [] arr;

  arr = new int[sizeof(arr1)];

  for(int i = 0; i < sizeof(arr); i++)
    arr[i] = arr1[i];

  delete [] arr1;

  size--;

}
//this is the same.  Shift all indexes left, vector shrinks.
int stack::top(){

  return arr[0];

}
//just a peek method
bool stack::empty(){

  if(sizeof(arr) == 0)
    return true;
  else
    return false;

}
//true if the stack is empty
