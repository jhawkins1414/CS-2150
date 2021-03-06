//Jared Hawkins jmh7ax 2/17/2021

#include "List.h"
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
  head -> previous = NULL;
    tail -> next = NULL;
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
  if(!isEmpty()){
    makeEmpty();
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
  if(!isEmpty()){
    ListItr t = ListItr(head -> next);
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
    ListNode* l = new ListNode();
    l -> value = x;
    position.current -> next -> previous = l;
    l -> next = position.current -> next;
    position.current -> next = l;
    l -> previous = position.current;
    count++;
}

void List :: insertBefore(int x, ListItr position) {
    ListNode* l = new ListNode();
    l -> value = x;
    l -> next = position.current;
    l -> previous = position.current -> previous;
    position.current -> previous -> next = l;
    position.current -> previous = l;
    count++;
}

void List :: insertAtTail(int x){
   ListNode* l = new ListNode();
   l -> value = x;
   tail -> previous -> next = l;
   tail -> previous = l;
   l -> next = tail;
   count++;
}

ListItr List :: find(int x){
  ListItr t = ListItr(head);
  while(!t.isPastEnd()){
    if(t.retrieve() == x){
      return t;
    }
    t.moveForward();
  }
  return t;
}

void List :: remove(int x){
  ListItr t = ListItr(head -> next);
  while(!t.isPastEnd() && !isEmpty()){
    if(t.retrieve() == x){
      t.current -> next -> previous = t.current -> previous;
      t.current -> previous -> next = t.current -> next;
      t.current -> next = NULL;
      t.current -> previous = NULL;
      delete t.current;
      count--;
    }
    t.moveForward();
  }
}

int List :: size() const{
  return count;
}

void printList(List& source, bool forward){
  if (forward){
   ListItr t = ListItr(source.first());
   while(!t.isPastEnd()){
     cout << t.retrieve();
     cout << " ";
     t.moveForward();
   }
  }
  else{
    ListItr t = ListItr(source.last());
    string str = "";
    while(!t.isPastBeginning()){
      cout << t.retrieve();
      cout << " ";
      t.moveBackward();
    }
    cout << "\n";
  }
}
