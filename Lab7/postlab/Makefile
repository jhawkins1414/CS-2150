#Jared Hawkins jmh7ax 3/22/2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g
OBJECTS=HashTable.o wordPuzzle.o timer.o 

WordPuzzle: HashTable.o wordPuzzle.o timer.o
	$(CXX) $(DEBUG) $(OBJECTS)

HashTable.o: HashTable.cpp HashTable.h

wordPuzzle.o: wordPuzzle.cpp

timer.o: timer.cpp timer.h counter.cpp

.PHONY: clean
clean:
	-rm -f *.o *.~ WordPuzzle
