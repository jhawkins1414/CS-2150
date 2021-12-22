// Jared Hawkins jmh7ax 3/22/2021

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <vector>

using namespace std;

class HashTable{
 public:
  HashTable();

  void insert(string key);

  bool find(string key);

 private:
  vector<list<string> > ht;

  int size;

  int hashIt(string key);
  
};
#endif
