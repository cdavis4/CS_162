#CarrieDavisLab4makefile
#Variables

CXX =	g++
CXXFLAGS = -Wall -pedantic -std=c++0x

Main:	main.o	University.o Student.o Instructor.o Person.o Building.o
	$(CXX)	$(CXXFLAGS) -o main main.o University.o Student.o Instructor.o Person.o Building.o

main.o:	main.cpp
	$(CXX)	$(CXXFLAGS) -c main.cpp

University.o:	University.cpp University.hpp
	$(CXX)	$(CXXFLAGS) -c University.cpp

Instructor.o:	Instructor.cpp Instructor.hpp
	$(CXX)	$(CXXFLAGS) -c Instructor.cpp

Student.o:	Student.cpp Student.hpp
	$(CXX)	$(CXXFLAGS) -c Student.cpp

Person.o:	Person.cpp Person.hpp
	$(CXX)	$(CXXFLAGS) -c Person.cpp

Building.o:	Building.cpp Building.hpp
	$(CXX)	$(CXXFLAGS) -c Building.cpp


clean:
	rm -f main main.o University.o Student.o Instructor.o Person.o Building.o