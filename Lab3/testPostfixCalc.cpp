// Jared Hawkins jmh7ax 2/22/2021

#include <iostream>
#include <string>
#include "postfixCalculator.h"
#include "Stack.h"
using namespace std;

int main(){
  string token;
  postfixCalculator pfc;
  string e = "The Calculator is Empty. Please Try Again.";

  while(cin >> token){
    if(token == "+"){
      pfc.addition();
    }
    else if(token == "-"){
      pfc.subtraction();
    }
    else if(token == "*"){
      pfc.multiplication();
    }
    else if(token == "/"){
      pfc.division();
    }
    else if(token == "~"){
      pfc.negative();
    }
     else{
	pfc.calc.push(stoi(token));
      }
  }
    cout << pfc.calc.top() << endl;
    return 0;
}
