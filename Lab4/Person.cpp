/*******************************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Lab 4; Person
 ******************************************************/
#include <iostream>
#include <string>
#include <random>
using namespace std;

#include "Person.hpp"
//Default Constructor
Person::Person()
{
    this->name = "";
    this->age = 0;
}
/********************************************************
 * Person::Person Class
 * Initalizes the defaults for class data members
 ********************************************************/
Person::Person(string inName, int inAge)
{
    setName(inName);
    setAge(inAge);
}
/*********************************************************
 * Person::getName method
 * gets person name
*********************************************************/
string Person::getName()
{
    return this->name;
}

/*******************************************************
 * Person::setName method
 * sets person name
*********************************************************/
void Person::setName(string inName)
{
     name = inName;
}
/*******************************************************
 * Person::setAge method
 * sets person name
 *********************************************************/
void Person::setAge(int inAge)
{
    age = inAge;
}

/********************************************************************
 * Person::getAge method
 * gets person age
 *********************************************************************/
int Person::getAge()
{
    return age;
}
/********************************************************************
 * Person::do_work method
 * gets person age
 *********************************************************************/
string Person::do_work()
{
    string workHours;
    int hours;
    //randomize hours for person
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    int maxSeed = 40;
    int minSeed = 1;
    
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    hours = dist(gen);
    workHours = to_string(hours);
    
    return workHours;
    
}
