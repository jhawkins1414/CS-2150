// Jared Hawkins jmh7ax 3/2/2021

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int bitCount(int num){
  if(num == 0){
    return 0;
  }
  else if(num == 1){
    return 1;
  }
  else if(num % 2 == 0){
    return bitCount(num / 2);
  }
  else{
    return bitCount(num / 2) + 1;
  }
}

string convert(string numConvert, int startBase, int endBase){
  if(numConvert  == "0"){
    return 0;
  }

  int baseTen = 0;
  int position = numConvert.length() - 1;

  for(int i = 0; i < numConvert.length(); i++){
      char c = numConvert[i];
      int number = c - '0';
      if(number > 9){
	number -= 7;
      }
      int converted = number * pow(startBase, position);
      baseTen += converted;
      position--;
  }

  string f = "";
  
  while(baseTen > 0){
    int remainder = baseTen % endBase;
    baseTen /= endBase;

    if(remainder > 9){
      int ascii = remainder + '0' + 7;
      char ch = (char)ascii;
      f += ch;
    }
    else{
      f += to_string(remainder);
    }
  }

  char temp;
  for(int k = 0; k < f.length() / 2; k++){
    temp = f[k];
    f[k] = f[f.length() - k - 1];
    f[f.length() - k - 1] = temp;
  }
  return f;
 }

int main(int argc, char **argv){
  
  int bcNum = atoi(argv[1]);
  string numConvert = argv[2];
  int startBase = atoi(argv[3]);
  int endBase = atoi(argv[4]);
  
  cout << to_string(bcNum) + " has " + to_string(bitCount(bcNum)) + " bit(s)" << endl;

  string converted = convert(numConvert, startBase, endBase);

  cout << numConvert + " (base " + to_string(startBase) + ") = " + converted + " (base " + to_string(endBase) + ")" << endl;
  
  return 0;
}
