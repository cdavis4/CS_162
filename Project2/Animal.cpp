/***********************************************
 ** Author: carrie davis
 ** Date:July 17, 2018
 ** Description: Project 2 ; Animal Class
 ************************************************/
#include <iostream>
#include <iomanip>
using namespace std;
#include "Animal.hpp"

//Default Constructor
Animal::Animal()
{
    this->age = 1;
    this->baby = 0;
    this->foodCost = 10;
    this->cost = 0;
    this->payOff = 0;
}

/***********************************************
 * Animal::Animal
 * sets up data members for Animal
 **********************************************/
Animal::Animal(int inAge,int inBaby,int inFoodCost,int inPayOff)
{
    this->age = inAge;
    this->baby = inBaby;
    this->foodCost = inFoodCost;
    this->payOff = inPayOff;
}

/*****************************************************
 * Animal::setCost
 * set inital cost for animal
 *****************************************************/
void Animal::setCost(int inCost)
{
    cost = inCost;
}
/*****************************************************
 * Animal::setAge
 * set inital cost for animal
 *****************************************************/
void Animal::setAge(int inAge)
{
    age = inAge;
}

/*****************************************************
 * Animal::getAge
 * gets age for animal
 *****************************************************/
int Animal::getAge()
{
    return this->age;
}

/*****************************************************
 * Animal::getCost
 * gets inital cost for animal
 *****************************************************/
int Animal::getCost()
{
    return this->cost;
}

/*****************************************************
 * Animal::getPayOff
 * gets payoff for each day for animal
 *****************************************************/
int Animal::getPayOff()
{
    return this->payOff;
}
/*****************************************************
 * Animal::getBabies
 * gets baby total for each animal
 *****************************************************/
int Animal::getBabies()
{
    return this->baby;
}
/*****************************************************
 * Animal::getBabies
 * gets daily food cost for each animal
 *****************************************************/
int Animal::getFoodCost()
{
    return this->foodCost;
}
