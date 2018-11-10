//cpp file for the postfix calculator by Jay Rothenberger (jr2fh) 9/17/18

#include "stack.h"
#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#include "postfixCalculator.h"

postfixCalculator::postfixCalculator(){

  stack s;

}
postfixCalculator::~postfixCalculator(){

  //There is no data stored here, this is not a memory leak to leave stubbed

}
void postfixCalculator::push(int n){

  s.push(n);
  
}
int postfixCalculator::pop(){

  int n = s.top();
  s.pop();

  if(s.empty())
    exit(-1);

  return n;

}
void postfixCalculator::negate(){

  int n = s.top();
  s.pop();
  s.push(0-n);

}
void postfixCalculator::add(){
  int n0 = s.top();
  s.pop();
  int n1 = s.top();
  s.pop();
  s.push(n0+n1);

}
void postfixCalculator::subtract(){

  int n0 = s.top();
  s.pop();
  int n1 = s.top();
  s.pop();
  s.push(n1 - n0);

}
void postfixCalculator::divide(){

  int n0 = s.top();
  s.pop();
  int n1 = s.top();
  s.pop();
  s.push(n1 / n0);

}
void postfixCalculator::multiply(){

   int n0 = s.top();
  s.pop();
  int n1 = s.top();
  s.pop();
  s.push(n1 * n0);
  
}
int postfixCalculator::getTopValue(){

  int n = s.top();
  s.pop();
  return n;

}
void postfixCalculator::getInputString(){
  cout << "enter input string" << endl;
  string in;
  getline(cin, in);

  if(in.length() == 0)
    in = "0";

  string *arr = new string[in.length()];

  int n = 0;

  for(int i = 0; i < in.length(); i++){

    if(in[i] == 32 && arr[n] != "")
      n++;
    else
      arr[n] += in.substr(i,1);
    
  }

  //by this point we have separated the input into an array of words
  /*for each element we need to push it onto the stack,
    and if it is only op, perform of*/

  for(int i = 0; i < in.length(); i++){

    if(!isOp(arr[i]) && arr[i] != ""){

      stringstream strStr(arr[i]);

      int y = 0;

      strStr >> y;

      push(y);

    }else{

      int num = arr[i][0];

      if( num == 43)
	add();

      if( num == 45)
	subtract();

      if(num  == 47)
        divide();

      if(num == 42)
	multiply();

      if(num  == 126)
        negate();

    }
    }
  
  delete [] arr;
}
  bool postfixCalculator::isOp(string s){

    if(s.length() == 1){

      if(s == "+")
	return true;

      if(s == "-")
	return true;

      if(s == "/")
	return true;

      if(s == "*")
	return true;

      if(s == "~")
	return true;

      return false;


    }
      else{
	return false;
      }
    }

  
