//Jay Rothenberger
//reads the desired number of steps in the collatz conjecture and finds the smallest number with greater than or equal to that number of steps to one.
#include <iostream>
#include "timer.h"
using namespace std;
 
extern "C" unsigned int threeplusone(unsigned int n);
 
int main(){
 
  unsigned int steps;
  cin >> steps;
  unsigned int y = 0;
  unsigned int max = 0;
 
  while(max < steps){
    y++;
    max = threeplusone(y);
    cout << y << endl;
   
  }
  cout << threeplusone(y) << " y: " << y << endl;
}