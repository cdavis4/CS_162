/*******************************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Lab 4; Building
 ******************************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Building.hpp"
//Default Constructor
Building::Building()
{
    this->name = "";
    this->size = 0;
    this->address = "";
}
/********************************************************
 * Building::Building Class
 * Initalizes the defaults for class data members
 ********************************************************/
Building::Building(string inName, int inSize, string inAddress)
{
    setName(inName);
    setSize(inSize);
    setAddress(inAddress);
}
/*********************************************************
 * Building::getName method
 * gets building name
 *********************************************************/
string Building::getName()
{
    return this->name;
}

/*******************************************************
 * Building::setName method
 * sets building name
 *********************************************************/
void Building::setName(string inName)
{
    name = inName;
}
/*******************************************************
 * Building::setSize method
 * sets building size
 *********************************************************/
void Building::setSize(int inSize)
{
    size = inSize;
}

/********************************************************************
 * Building::getSize method
 * gets building size
 *********************************************************************/
int Building::getSize()
{
    return this->size;
}
/********************************************************************
 * Building::getAddress
 * gets address
 *********************************************************************/
string Building::getAddress()
{
    return this->address;
    
}
/*******************************************************
 * Building::setAddress method
 * sets building address
 *********************************************************/
void Building::setAddress(string inAddress)
{
    address = inAddress;
}
