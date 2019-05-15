//
//  Person.hpp
//  
//
//  Created by Carrie Davis on 7/23/18.
//

#ifndef Person_hpp
#define Person_hpp
using namespace std;
class Person
{
protected:
    
    string name;
    int age;
 
public:
    Person();
    Person(string, int);
    int getAge();
    void setAge(int);
    void setName(string);
    string getName();
    virtual string do_work();
    virtual float getScore(){}
};

#endif /* Person_hpp */
