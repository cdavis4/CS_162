//
//  Student.hpp
//  
//
//  Created by Carrie Davis on 7/23/18.
//

#ifndef Student_hpp
#define Student_hpp

#include "Person.hpp"

class Student: public Person
{
protected:
    float grade = 0.0;
public:
    Student();
    Student(string name, int age,float inputGrade): Person(name, age)
    {
        grade = inputGrade;
        
    }
    string do_work();
    float getScore();
    void setScore(float);

};

#endif /* Student_hpp */
