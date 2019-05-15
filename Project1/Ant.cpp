/*********************************************************
 ** Author: carrie davis
 ** Date:July 1, 2018
 ** Description: Project 1; Ant
 ***********************************************************/
#include <iostream>
using namespace std;

#include "Ant.hpp"
//Default Constructor

Ant::Ant()
{
    setRow(-100);
    setColumn(-100);
    setOrientation('N');
}
/******************************************************
 * Ant::Ant Class
 * Initalizes the defaults for class data members
 ********************************************************/
Ant::Ant(int inRow,int inColumn, char orientation)
{
    setRow(inRow);
    setColumn(inColumn);
    setOrientation(orientation);
}
/***********************************************************
 * Ant::getRow method
 * gets row of ant location
 ***********************************************************/
int Ant::getRow()
{
    return row;
}
/***********************************************************
 * Ant::getColumn method
 * gets column of ant location
 ***********************************************************/
int Ant::getColumn()
{
    return column;
}
/***********************************************************
 * Ant::getOrientation method
 * gets orientation of ant location
 ***********************************************************/
char Ant::getOrientation()
{
    return orientation;
}
/***********************************************************
 * Ant::setOrientation method
 * sets orientation of ant location
 ***********************************************************/
void Ant::setOrientation(char inOrient)
{
    orientation = inOrient;
}
/***********************************************************
 * Ant::setRow method
 * sets row of ant location
 ***********************************************************/
void Ant::setRow(int inRow)
{
    row = inRow;
}
/***********************************************************
 * Ant::setColumn method
 * sets column of ant location
 ***********************************************************/
void Ant::setColumn(int inColumn)
{
    column = inColumn;
}
