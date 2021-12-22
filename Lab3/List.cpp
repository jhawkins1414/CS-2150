//Jared Hawkins jmh7ax 2/17/2021

#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
#include <string>
using namespace std;

List :: List(){
  head = new ListNode();
  tail = new ListNode();
  head -> previous = NULL;
  tail -> next = NULL;
  head -> next = tail;
  tail -> previous = head;
  count = 0;
}

List :: List(const List& source){
   head = new ListNode();
  tail = new ListNode();
  head -> next = tail;
  tail -> previous = head;
  count = 0;

  ListItr iter(source.head -> next);
  while(!iter.isPastEnd()){
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

List :: ~List(){
  if(!this -> isEmpty()){
   this ->  makeEmpty();
  }
  head -> next = NULL;
  tail -> previous = NULL;
  delete head;
  delete tail;
}

List& List :: operator=(const List& source){
  if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

//methods

bool List ::  isEmpty() const{
  if(head -> next == tail && tail -> previous == head){
    return true;
  }
  return false;
}

void List :: makeEmpty(){
  if(!this -> isEmpty()){
    ListItr t = head -> next;
    for(int i = 0; i < count; i++){
      ListNode* n = t.current;
      t.moveForward();
      n-> previous = NULL;
      n-> next = NULL;
      delete n;
    }
    head -> next = tail;
    tail -> previous = head;
    count = 0;
  }
}

ListItr List :: first(){
  ListItr t = ListItr(head);
  t.moveForward();
  return t;
}

ListItr List :: last(){
  ListItr t = ListItr(tail);
  t.moveBackward();
  return t;
}

void List :: insertAfter(int x, ListItr position){
    count++;
    ListNode* l = new ListNode();
    l -> value = x;
    l -> previous = position.current;
    l -> next = position.current -> next;
    position.current -> next -> previous = l;
    position.current -> next = l;
  
}

void List :: insertBefore(int x, ListItr position) {
     count++;
    ListNode* l = new ListNode();
    l -> value = x;
    l -> next = position.current;
    l -> previous = position.current -> previous;
    position.current -> previous -> next = l;
    position.current -> previous = l;
}

void List :: insertAtTail(int x){
  ListItr t = ListItr(tail);
  insertBefore(x, t);
}

ListItr List :: find(int x){
  ListItr t = ListItr(head);
  while(!t.isPastEnd()){
    if(t.retrieve() == x){
      return t;
    }
    t.moveForward();
  }
  ListItr itr = ListItr(tail);
  return itr;
}

void List :: remove(int x){
  ListItr t = ListItr(head -> next);
  while(!t.isPastEnd()){
    if(t.retrieve() == x){
      t.current -> previous -> next = t.current -> next;
      t.current -> next -> previous = t.current -> previous;
      t.current -> next = NULL;
      t.current -> previous = NULL;
      delete t.current;
      count--;
      break;
    }
    t.moveForward();
  }
}

void List :: removeLast(){
  ListItr t = ListItr(tail -> previous);
  t.current -> previous -> next = tail;
  tail -> previous = t.current -> previous;
  t.current -> next = NULL;
  t.current -> previous = NULL;
  delete t.current;
  count--;
}

int List :: size() const{
  return count;
}

void printList(List& source, bool forward){
  if (forward){
   ListItr t = ListItr(source.first());
   string s = "";
   while(!t.isPastEnd()){
     string str = to_string(t.retrieve());
     s += str;
     s += " ";
     t.moveForward();
   }
   cout << s;
  }
  else{
    ListItr t = ListItr(source.last());
    string s = "";
    while(!t.isPastBeginning()){
      string str = to_string(t.retrieve());
      s+= str;
      s+= " ";
      t.moveBackward();
    }
    cout << s;
  }
}
