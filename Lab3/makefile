#CarrieDavisLab3makefile
#Variables

CXX =	g++
CFLAGS = -Wall -pedantic -std=gnu++11 

Main:	main.o	Game.o LoadedDie.o Die.o
	$(CXX)	$(CFLAGS) -o main main.o Game.o LoadedDie.o Die.o

main.o:	main.cpp
	$(CXX)	$(CFLAGS) -c main.cpp

Game.o:	Game.cpp Game.hpp
	$(CXX)	$(CFLAGS) -c Game.cpp

LoadedDie.o:	LoadedDie.cpp LoadedDie.hpp
	$(CXX)	$(CFLAGS) -c LoadedDie.cpp

Die.o:	Die.cpp Die.hpp
	$(CXX)	$(CFLAGS) -c Die.cpp
	
clean:
	rm -f main main.o Game.o LoadedDie.o Die.o
