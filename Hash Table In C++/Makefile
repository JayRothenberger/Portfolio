 #Jay Rothenberger (jr2fh) hashTable makefile
CXXFLAGS= -Wall -O2
CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g
OFILES = hashTable.o timer.o wordPuzzle.o

hash:$(OFILES)
	$(CXX) $(DEBUG) $(OFILES)

clean:
	-rm *.o a.out *~

hashTable.o: hashTable.cpp hashTable.h
	$(CXX) -c hashTable.cpp
	
timer.o: timer.cpp timer.h
	$(CXX) -c timer.cpp
	
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
	$(CXX) -c wordPuzzle.cpp


.SUFFIXES: .o .cpp
