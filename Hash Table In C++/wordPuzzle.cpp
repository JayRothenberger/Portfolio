//Jay Rothenberger wordPuzzle.cpp 10/23/18
//time for 3x3.grid.txt: 0.000091 seconds
//time for 4x7.grid.txt: 0.000275 seconds
//time for 50x50.grid.txt: 0.075209 seconds
//time for 300x300.grid.txt: 3.33932 seconds
//time for 250x250.grid.txt: 2.32571 seconds
//big theta for this program is n, or linear time with respect to the number of letters in the grid
/*
Technically I think it is also reliant on the number of words returned, because it has to print them
which takes some time.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "hashTable.h"
#include "timer.h"

using namespace std;

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

int main(int argc, char* argv[]){
  timer t;
  int kprev = -1;
  t.start();
  // cout << "dictionary: " << argv[1] << endl;
  ifstream fin(argv[1]);
  string line;
  hashTable h;
  hashTable subs;

  while(getline(fin, line)){
    for(int c = 3; c < line.size(); c++){
      subs.insert(line.substr(0, c));
    }
    h.insert(line);
    //cout << "inserted" << endl;
  }
  fin.close();
  //start grid computation
  int rows, cols;

  bool result = readInGrid(argv[2], rows, cols);
  //cout << "reading success!" <<endl;
  if(!result){

    cout << "error, unlucky m8" << endl;
    exit(1);

  }

  //quad for-loop time

  int row, col;
  int numwor = 0;
  string prevword;
  vector<string> victor;

  for(int i = 0; i < rows; i++){
    //for each row
    for(int j = 0; j < cols; j++){
      //for each column in each row
      for(int k = 0; k < 8; k++){
	//for each direction from each point
	for(int l = 3; l < 22; l++){
	  string word = getWordInGrid(i,j,k,l,rows,cols);
	  if(h.includes(word) && (row != i || col != j || word != prevword || k != kprev)){
	    prevword = word;
	    kprev = k;
	    numwor++;
	    row = i;
	    col = j;
	    string dir;
	    switch (k) { // assumes grid[0][0] is in the upper-left
            case 0:
                dir = "N ";
                break; // north
            case 1:
	      dir = "NE";
                break; // north-east
            case 2:
	      dir = "E ";
                break; // east
            case 3:
	      dir = "SE";
                break; // south-east
            case 4:
	      dir = "S ";
                break; // south
            case 5:
	      dir = "SW";
                break; // south-west
            case 6:
	      dir = "W ";
                break; // west
            case 7:
	      dir = "NW";
                break; // north-west
	    }
	    cout << dir << "(" << i << ", " << j << "):    " << word << endl;
	  }
	  if(!subs.includes(word))
	    break;
	}
      }
    }
  }
  t.stop();
  cout << numwor << " words found" << endl;
  cout << "Found all words in " <<  t.getTime() << " seconds" << endl;
  //cout << (int)ceil(t.getTime()*10000) << endl;
  return 0;
  /*
  fin.open(arvg[2]);
  
  while(fin.peek() != '\n'){
    cols++;
  }
  while(fin >> val){
    items++;
    rows = items/cols;
  }
  fin.close();


  while this is cool, it is superflous
  */
  //cols = argv[2][2];
}

bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
        //cout << endl;
    }
    // return success!
    return true;
}

char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}
