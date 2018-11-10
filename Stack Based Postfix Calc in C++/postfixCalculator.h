//h file for the postfix calculator by Jay Rothenberger (jr2fh) 9/17/18

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include "stack.h"
#include <string>
#include <sstream>

using namespace std;

class postfixCalculator;

class postfixCalculator {
 public:
  postfixCalculator();
  ~postfixCalculator();
  void push(int n);
  int pop();
  void negate();
  void add();
  void subtract();
  void divide();
  void multiply();
  int getTopValue();
  void getInputString();
  bool isOp(string s);
//many of these methods should be private, but for the added functionality of manually stepping through the process they are left public.
 private:
  stack s;

};

#endif
