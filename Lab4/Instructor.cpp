//
//  Instructor.cpp
//  
//
//  Created by Carrie Davis on 7/23/18.
#include <string>
#include <iostream>
using namespace std;
#include "Instructor.hpp"

/*******************************************
 * Student::getScore method
 * get score in grades
 *********************************************/
float Instructor::getScore()
{
    cout << "Rating:";
    return rating;
}


/*******************************************
 * Instructor::do_work method
 * do_work method work message
 *********************************************/
string Instructor::do_work()
{
    /* cout << name <<“ did X hours of ” << getWorkType(); Where PERSON_NAME is the person’s name, and X is the randomly generated number.
     */
    return Person::getName() + " graded papers for " + Person::do_work() + " hours. ";
    
}
