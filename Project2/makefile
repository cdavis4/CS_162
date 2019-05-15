#CarrieDavisProject2makefile
#Variables

CXX =	g++
CXXFLAGS = -Wall -pedantic -std=gnu++11 

Main:	main.o	ZooTycoon.o Animal.o Tiger.o Turtle.o Penguin.o newAnimal.o
	$(CXX)	$(CXXFLAGS) -o main main.o ZooTycoon.o Animal.o Tiger.o Turtle.o Penguin.o newAnimal.o


main.o:	main.cpp
	$(CXX)	$(CXXFLAGS) -c main.cpp

ZooTycoon.o:	ZooTycoon.cpp ZooTycoon.hpp
	$(CXX)	$(CXXFLAGS) -c ZooTycoon.cpp

Animal.o:	Animal.cpp Animal.hpp
	$(CXX)	$(CXXFLAGS) -c Animal.cpp

Tiger.o:	Tiger.cpp Tiger.hpp
	$(CXX)	$(CXXFLAGS) -c Tiger.cpp


Turtle.o:	Turtle.cpp Turtle.hpp
	$(CXX)	$(CXXFLAGS) -c Turtle.cpp

Penguin.o:	Penguin.cpp Penguin.hpp
	$(CXX)	$(CXXFLAGS) -c Penguin.cpp

newAnimal.o:	newAnimal.cpp newAnimal.hpp
	$(CXX)	$(CXXFLAGS) -c newAnimal.cpp
	
clean:
	rm -f main main.o ZooTycoon.o Animal.o Tiger.o Turtle.o Penguin.o newAnimal.o
