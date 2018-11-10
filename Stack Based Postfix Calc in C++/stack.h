//Jay Rothenberger (jr2fh) 9/20/18 stack.h
//stack suitable for storing integers
#ifndef STACK_H
#define STACK_H

using namespace std;

class stack;

class stack {

 public:
  stack();
  ~stack();
  void push(int n);
    //push n item onto the stack
  void pop();
    //pop an item off of the stack
  int top();
    //the top integer on the stack
  bool empty();
    //returns true if there are no items in the stack
 private:
  int *arr = new int[0];
  int size;

};

#endif
