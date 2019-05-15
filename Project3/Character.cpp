/***********************************************
 ** Author: carrie davis
 ** Date:July 31, 2018
 ** Description: Project 3; base fighter class
 **********************************************/
#include <iostream>
#include "Character.hpp"
#include <string>
using namespace std;

//Default Constructor
Character::Character()
{
    this->name = "";
    this->armor = -99;
    this->attack = -99;
    this->defense = -99;
    this->strength = -99;
}
/********************************************************
 * Character::Character Class
 * Initalizes the defaults for class data members
 ********************************************************/
Character::Character(string inName, int inArmor, int inAttack, int inDefense, int inStrength)
{
    name = inName;
    armor = inArmor;
    attack = inAttack;
    defense = inDefense;
    strength = inStrength;
}

/*********************************************************
 * Character::getName method
 * gets character name
 *********************************************************/
string Character::getName()
{
    return this->name;
}
/*******************************************************
 * Character::setName method
 * sets character name
 *********************************************************/
void Character::setName(string inName)
{
    name = inName;
}
/*********************************************************
 * Character::getArmor method
 * gets character armor
 *********************************************************/
int Character::getStrength()
{
    return this->strength;
}

/*********************************************************
 * Character::getArmor method
 * gets character armor
 *********************************************************/
int Character::getArmor()
{
    return this->armor;
}
/*******************************************************
 * Character::setArmor method
 * sets character armor
 *********************************************************/
void Character::setArmor(int inArmor)
{
    armor = inArmor;
}




