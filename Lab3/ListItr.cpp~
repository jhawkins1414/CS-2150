//Jared Hawkins jmh7ax 2/17/2021

#include "ListItr.h"
using namespace std;

//constructors
ListItr :: ListItr(){
}

ListItr :: ListItr(ListNode* theNode){
  current = theNode;
}

//methods
bool ListItr :: isPastEnd() const{
  if(current -> next == NULL){
    return true;
  }
  return false;
}

bool ListItr :: isPastBeginning() const{
  if(current -> previous == NULL){
    return true;
  }
  return false;
}

void ListItr :: moveForward(){
  if(current -> next != NULL){
    current = current -> next;
  }
}

void ListItr :: moveBackward(){
  if(current -> previous != NULL){
    current = current -> previous;
  }
}

int ListItr :: retrieve() const{
  return current -> value;
}
