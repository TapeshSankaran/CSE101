CXX = g++
CXXFLAGS = -Wall

OBJECTS = linkedlist.o listwrapper.o

TestCases: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o TestCases LinkedList.o TestCases.o

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CXX) -g $(CXXFLAGS) -c LinkedList.cpp
	
listwrapper.o: LinkedList.cpp LinkedList.h TestCases.cpp
	$(CXX) -g $(CXXFLAGS) -c TestCases.cpp

clean: 
	rm -f *.o
	rm TestCases