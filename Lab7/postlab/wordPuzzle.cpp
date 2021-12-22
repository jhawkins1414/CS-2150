//Jared Hawkins 3/21/2021

#include <iostream>
#include <string>
#include <unordered_map>
#include <fstream>
#include <math.h>
#include <vector>
#include "HashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// Forward declarations
bool readInGrid(string filename, int& rows, int& cols);
string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);

bool readInGrid(string filename, int& rows, int& cols) {
    // try to open the file
    ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }

    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
            //cout << grid[r][c];
        }
	// cout << endl;
    }
    return true;
}

string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocation.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

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

    return output;
}

int main(int argc, char *argv[]){
  HashTable table = HashTable();

  timer t;

  ifstream dicc(argv[1]);

  string info;
  while(dicc >> info){
    table.insert(info);
  }

  dicc.close();

  int rows;
  int columns;

  bool readGrid = readInGrid(argv[2], rows, columns);
  if(!readGrid){
    cout<< "Error" << endl;
  }

  int words = 0;
  string direction = "";
  string dirs[] = {"N ", "NE", "E ", "SE", "S ", "SW", "W ", "NW"};
  string previous = "";
  int previousDir = -1;

  t.start();
  
  for(int r = 0; r < rows; r++){
    for(int c = 0; c < columns; c++){
      for(int d = 0; d < 8; d++){
	for(int l = 3; l <= 20; l++){
	  string check = getWordInGrid(r, c, d, l, rows, columns);
	  if(previousDir == d && previous == check) {
	    break;
	  } else {
	    previous = check;
	    if(check.length() > 2) {
	      if(table.find(check)) {
		words++;
		direction = dirs[d];
		cout << direction + "(" + to_string(r) + ", " + to_string(c) + "):	" + check << endl;
		previousDir = d;
	      }
	    }
	  }
	}
      }
    }
  }	  

  t.stop();
  cout << to_string(words) + " words found" << endl;

  int time = t.getTime() * 1000;
  //cout << time;
  
  return 0;
}


