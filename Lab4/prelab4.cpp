//Jared Hawkins jmh7ax 2/24/2021

#include <iostream>
#include <string>
#include <climits>
using namespace std;

void sizeOfTest(){
  cout << "Size of int: " + to_string(sizeof(int)) << endl;
  cout << "Size of unsigned int: " + to_string(sizeof(unsigned int)) << endl;
  cout << "Size of float: " + to_string(sizeof(float)) << endl;
  cout << "Size of double: " + to_string(sizeof(double)) << endl;
  cout << "Size of char: " + to_string(sizeof(char)) << endl;
  cout << "Size of bool: " + to_string(sizeof(bool)) << endl;
  cout << "Size of int*: " + to_string(sizeof(int*)) << endl;
  cout << "Size of char*: " + to_string(sizeof(char*)) << endl;
  cout << "Size of double*: " + to_string(sizeof(double*)) << endl;
}

void overflow(){
  unsigned int  max = UINT_MAX;
  cout << to_string(max) + " + 1 = " + to_string(max + 1) << endl;
}

void outputBinary(unsigned int x){
  unsigned int max = UINT_MAX;
  if (x > max) {
    cout << "Number too Big" << endl;
  }
  else {
    int r[32];
    for(int i = 31; i >=0; i--){
      int remainder = x%2;
      x = x/2;
      r[i] = remainder;
    }
    for(int i = 0; i < 32; i++){
      if(i%4 == 0 && i !=0){
	cout << " ";
      }
      cout << r[i];
    }
    cout << "\n";
  }
      
}

int main(){
  unsigned int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);
  return 0;
}
