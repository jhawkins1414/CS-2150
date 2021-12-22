// Jared Hawkins jmh7ax 3/22/2021

#include "HashTable.h"
#include <string>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

HashTable :: HashTable(){
  ht = vector<list<string> >(7971);
  size = ht.size();
}

int HashTable :: hashIt(string key){
  int num = 0;
  for(int i = 0; i < key.length(); i++){
    num+= (int)key[i];
  }
  return num % size;
}

void HashTable :: insert(string key){
  ht[hashIt(key)].push_back(key);
}

bool HashTable :: find(string key){
  list<string> :: iterator i;
  for(i = ht[hashIt(key)].begin(); i != ht[hashIt(key)].end(); i++){
    if((*i).compare(key) == 0){
      return true;
    }
  }
  return false;
}
