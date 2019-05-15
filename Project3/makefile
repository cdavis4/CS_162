#Project3makefile
#Variables

CXX =	g++
CFLAGS = -Wall -pedantic -std=gnu++11 

Main:	main.o	Character.o  Barbarian.o BlueMen.o Vampire.o HarryPotter.o Medusa.o CombatGame.o 
	$(CXX)	$(CFLAGS) -o main main.o Character.o  Barbarian.o BlueMen.o HarryPotter.o Vampire.o Medusa.o CombatGame.o 

main.o:	main.cpp
	$(CXX)	$(CFLAGS) -c main.cpp

Character.o:	Character.cpp Character.hpp
	$(CXX)	$(CFLAGS) -c Character.cpp	

CombatGame.o:	CombatGame.cpp CombatGame.hpp
	$(CXX)	$(CFLAGS) -c CombatGame.cpp
	
Barbarian.o:	Barbarian.cpp Barbarian.hpp
	$(CXX)	$(CFLAGS) -c Barbarian.cpp

BlueMen.o:	BlueMen.cpp BlueMen.hpp
	$(CXX)	$(CFLAGS) -c BlueMen.cpp

Vampire.o:	Vampire.cpp Vampire.hpp
	$(CXX)	$(CFLAGS) -c Vampire.cpp

HarryPotter.o:	HarryPotter.cpp HarryPotter.hpp
	$(CXX)	$(CFLAGS) -c HarryPotter.cpp


Medusa.o:	Medusa.cpp Medusa.hpp
	$(CXX)	$(CFLAGS) -c Medusa.cpp

clean:
	rm -f main main.o Character.o CombatGame.o Barbarian.o BlueMen.o HarryPotter.o Vampire.0 Medusa.o
