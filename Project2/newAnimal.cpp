/**************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Project 2; newAnimal
 ****************************************/

#include "newAnimal.hpp"
#include <iostream>
#include <string>
using namespace std;

/*************************************************
 * newAnimal::getType()
 * gets the type of animal
 **************************************************/
TYPE newAnimal::getType()
{
    return OTHER;
}
/*************************************************
 * newAnimal::setCost()
 * sets cost of animal
 **************************************************/
void newAnimal::setCost(int inCost)
{
    cost = inCost;
}
/*************************************************
 * newAnimal::getCost()
 * gets the cost of animal
 **************************************************/
int newAnimal::getCost()
{
 return cost;
}
/*************************************************
 * newAnimal::getStringOther()
 * gets the string name of animal
 **************************************************/
string newAnimal::getStringOther()
 {
     return typeString;
 }
/*************************************************
 * newAnimal::setStringOther()
 * sets the string name of animal
 **************************************************/
void newAnimal::setStringOther(string inType)
 {
     typeString = inType;
 }
/*************************************************
 * newAnimal::setBabies()
 * sets the number of babies animal can have
 **************************************************/
void newAnimal::setBabies(int inBabies)
{
    baby = inBabies;
}
/*************************************************
 * newAnimal::setFoodCost()
 * sets the daily food cost of animal
 **************************************************/
void newAnimal::setFoodCost(int inFoodCost)
{
    foodCost = inFoodCost;
}
/*************************************************
 * newAnimal::setFoodCost()
 * sets the daily food cost of animal
 **************************************************/
void newAnimal::setPayOff(int inPayOff)
{
   payOff = inPayOff;
}
