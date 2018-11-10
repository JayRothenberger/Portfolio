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
int stack::top(){

  return arr[0];

}
bool stack::empty(){

  if(sizeof(arr) == 0)
    return true;
  else
    return false;

}
