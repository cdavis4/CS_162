/**************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Project 2; LoadedDie
 ****************************************/

#ifndef Turtle_hpp
#define Turtle_hpp

#include "Animal.hpp"
class Turtle: public Animal{
public:
    //derived all functions from animal
    Turtle(int age,int baby,int foodCost,int payOff): Animal(age,baby,foodCost,payOff)
    {
    }
    Turtle();
    virtual ~Turtle() {}
    TYPE getType();
};
#endif /* Turtle_hpp */
