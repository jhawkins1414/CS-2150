// Jared Hawkins jmh7ax 2/23/2021

#include <iostream>
#include "Stack.h"
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
using namespace std;

Stack :: Stack(){
  l = List();
}

void Stack :: push(int x){
  l.insertAtTail(x);
}

void Stack :: pop(){
  l.removeLast();
}

int Stack :: top() {
  return l.last().retrieve();
}

bool Stack :: empty(){
  if(l.isEmpty()){
    return true;
  }
  return false;
}
