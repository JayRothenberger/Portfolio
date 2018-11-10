//test file for postfixCalculator by Jay Rothenberger (jr2fh) 9/17/18

#include "stack.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "postfixCalculator.h"


int main() {

    postfixCalculator p;

    p.getInputString();
    
    cout << "Result is: " << p.getTopValue() << endl;

    return 0;
}


