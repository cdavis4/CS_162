#FinalProjectmakefile
#Variables

CXX =	g++
CFLAGS = -Wall -pedantic -std=gnu++11 

Main:	main.o Runner.o	Fuel.o	Space.o Swim.o Climb.o Run.o Balance.o Crawl.o End.o Start.o ObstacleCourse.o 
	$(CXX)	$(CXXFLAGS) -o main main.o Runner.o Fuel.o Space.o Swim.o Climb.o Run.o Balance.o Crawl.o End.o Start.o ObstacleCourse.o 

main.o:	main.cpp
	$(CXX)	$(CFLAGS) -c main.cpp

Runner.o:	Runner.cpp Runner.hpp
	$(CXX)	$(CFLAGS) -c Runner.cpp 

Fuel.o:	Fuel.cpp Fuel.hpp
	$(CXX)	$(CFLAGS) -c Fuel.cpp 

Space.o:	Space.cpp Space.hpp
	$(CXX)	$(CFLAGS) -c Space.cpp 

Swim.o:	Swim.cpp Swim.hpp
	$(CXX)	$(CFLAGS) -c Swim.cpp 

Climb.o:	Climb.cpp Climb.hpp
	$(CXX)	$(CFLAGS) -c Climb.cpp 

Run.o:	Run.cpp Run.hpp
	$(CXX)	$(CFLAGS) -c Run.cpp 


Balance.o:	Balance.cpp Balance.hpp
	$(CXX)	$(CFLAGS) -c Balance.cpp 

Crawl.o:	Crawl.cpp Crawl.hpp
	$(CXX)	$(CFLAGS) -c Crawl.cpp 

End.o:	End.cpp End.hpp
	$(CXX)	$(CFLAGS) -c End.cpp 

Start.o:	Start.cpp Start.hpp
	$(CXX)	$(CFLAGS) -c Start.cpp 

ObstacleCourse.o:	ObstacleCourse.cpp ObstacleCourse.hpp
	$(CXX)	$(CFLAGS) -c ObstacleCourse.cpp 

clean:
	rm -f main main.o Runner.o Fuel.o Space.o Swim.o Climb.o Run.o Balance.o Crawl.o End.o Start.o ObstacleCourse.o 