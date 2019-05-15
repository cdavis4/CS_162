#CarrieDavisProject11makefile
#Variables

CXX =	g++
CFLAGS = -Wall -pedantic -std=gnu++11 

Main:	main.o	AntProgram.o AntBoard.o Ant.o
	$(CXX)	$(CFLAGS) -o main main.o AntProgram.o AntBoard.o Ant.o

main.o:	main.cpp
	$(CXX)	$(CFLAGS) -c main.cpp

AntProgram.o:	AntProgram.cpp AntProgram.hpp
	$(CXX)	$(CFLAGS) -c AntProgram.cpp
	
AntBoard.o:	AntBoard.cpp AntBoard.hpp
	$(CXX)	$(CFLAGS) -c AntBoard.cpp

Ant.o:	Ant.cpp Ant.hpp
	$(CXX)	$(CFLAGS) -c Ant.cpp	

clean:
	rm -f main main.o AntProgram.o AntBoard.o Ant.o
