//
//  Instructor.hpp
//  
//
//  Created by Carrie Davis on 7/23/18.
//

#ifndef Instructor_hpp
#define Instructor_hpp

#include "Person.hpp"
#include "Student.hpp"


class Instructor: public Student
{
protected:
     float rating = grade;
public:
    Instructor();
    Instructor(string name, int age,
               float grade):Student(name, age, grade)
  {
      
     // setName(inName);
     // setAge(inAge);
    //  setScore(rating);
      
  }

   float getScore();
    string do_work();
    
};
#endif /* Instructor_hpp */
