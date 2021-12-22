//Jared Hawkins jmh7ax 2/22/2021

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include "Stack.h"
using namespace std;

class postfixCalculator{
public:
  postfixCalculator();

  Stack calc;

  bool isEmpty();

  void addition();

  void subtraction();

  void multiplication();

  void division();

  void negative();
};

#endif
