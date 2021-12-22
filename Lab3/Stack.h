// Jared Hawkins jmh7ax 2/23/2021

#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

class Stack {
 public:
  Stack();

  List l;

  void push(int x);

  void pop();

  int top();

  bool empty();

  friend class postfixCalculator;
};
#endif

  
