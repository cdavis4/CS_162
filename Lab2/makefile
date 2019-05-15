#CarrieDavisLab2makefile
#Variables

CXX =	g++
CFLAGS = -Wall -pedantic -std=gnu++11 

Main:	main.o	LetterFrequency.o
	$(CXX)	$(CFLAGS) -o main main.o LetterFrequency.o

main.o:	main.cpp
	$(CXX)	$(CFLAGS) -c main.cpp

LetterFrequency.o:	LetterFrequency.cpp LetterFrequency.hpp
	$(CXX)	$(CFLAGS) -c LetterFrequency.cpp
	
clean:
	rm -f main main.o LetterFrequency.o
