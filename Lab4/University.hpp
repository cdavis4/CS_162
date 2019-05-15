//
//  University.hpp
//  
//
//  Created by Carrie Davis on 7/23/18.
//

#ifndef University_hpp
#define University_hpp
#include <vector>
#include <memory>
#include "Building.hpp"
#include "Person.hpp"
#include "Student.hpp"
#include "Instructor.hpp"

class University{
private:
    
string name; // must be constant
//int buildings; //# of Building objects
//int people; //vectors contains m number of Person objects
//int n; //# of building objects
//int m; //# of people objects

    
protected:
  
    //need to distinguish between instructors and students.
public:
    University();
    University(string);  //name, size, address
    void printBuildings(); //name, address, building size
    void printPeople(); // name, age, GPA or Rating
    string getName();
    void printPersonList();
};
#endif /* University_hpp */
