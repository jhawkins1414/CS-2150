//Jared Hawkins jmh7ax 2/22/2021

#include <iostream>
#include <string>
#include "postfixCalculator.h"
#include "Stack.h"
using namespace std;

postfixCalculator :: postfixCalculator(){
  calc = Stack();
}

bool postfixCalculator :: isEmpty(){
  if(calc.empty()){
    return true;
  }
  return false;
}

void postfixCalculator :: addition(){
  int second = calc.top();
  calc.pop();
  int first = calc.top();
  calc.pop();
  int sum = first + second;
  calc.push(sum);
}

void postfixCalculator :: subtraction(){
  int second = calc.top();
  calc.pop();
  int first = calc.top();
  calc.pop();
  int difference = first - second;
  calc.push(difference);
}

void postfixCalculator :: multiplication(){
  int second = calc.top();
  calc.pop();
  int first = calc.top();
  calc.pop();
  int product = first * second;
  calc.push(product);
}

void postfixCalculator :: division(){
  int second = calc.top();
  calc.pop();
  int first = calc.top();
  calc.pop();
  int quotient = first / second;
  calc.push(quotient);
}

void postfixCalculator :: negative(){
  int num = calc.top();
  calc.pop();
  num *= -1;
  calc.push(num);
}
