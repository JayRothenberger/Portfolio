#Jay Rothenberger (jr2fh) binary tree makefile
CXXFLAGS= -Wall -O2
CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
OFILES = BinaryNode.o BinarySearchTree.o BSTPathTest.o

tree:$(OFILES)
	$(CXX) $(DEBUG) $(OFILES)

clean:
	-rm *.o *~ 

BinaryNode.o: BinaryNode.cpp BinaryNode.h
	$(CXX) -c BinaryNode.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
	$(CXX) -c BinarySearchTree.cpp

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
	$(CXX) -c BSTPathTest.cpp

.SUFFIXES: .o .cpp
