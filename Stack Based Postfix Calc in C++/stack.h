//Jay Rothenberger (jr2fh) 9/20/18 stack.h

#ifndef STACK_H
#define STACK_H

using namespace std;

class stack;

class stack {

 public:
  stack();
  ~stack();
  void push(int n);
  void pop();
  int top();
  bool empty();
 private:
  int *arr = new int[0];
  int size;

};

#endif
