#Jared Hawkins jmh7ax 3/21/2021

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
OBJECTS = BSTPathTest.o BinaryNode.o BinarySearchTree.o
DEBUG=-g

BSTPathTest: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	@echo "BST compiled!"

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

.PHONY: clean
clean:
	-rm -f *.o *.~ BSTPathTest
