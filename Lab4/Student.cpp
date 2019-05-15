/********************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Lab 4; Student
 *********************************************/
#include <iostream>
#include <iomanip>
using namespace std;

#include "Student.hpp"
#include "Person.hpp"



/*******************************************
 * Student::do_work method
 * do_work method work message
 *********************************************/
string Student::do_work() 
{
    /* cout << name <<“ did X hours of ” << getWorkType(); Where PERSON_NAME is the person’s name, and X is the randomly generated number.
     */
    return Person::getName() + " did " + Person::do_work() + " hours of homework. ";
    
}

/*******************************************
 * Student::setScore method
 * sets score in grades
 *********************************************/
void Student::setScore(float inScore)
{
    this->grade = inScore;
}
/*******************************************
 * Student::getScore method
 * get score in grades
 *********************************************/
float Student::getScore()
{
    cout << "GPA:";
    return grade;
}
