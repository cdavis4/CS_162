/***********************************************
 ** Author: carrie davis
 ** Date:August 7, 2018
 ** Description: Final Project; Space base class
 **********************************************/
#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <stdexcept>
#include "Space.hpp"
//Default Constructor
Space::Space()
{
    north = NULL;
    south = NULL;
    east = NULL;
    west = NULL;
    completed = false;
}
/*********************************************************
 * Space::getcompleted method
 * gets completed value
 *********************************************************/
bool Space::getCompleted()
{
    return completed;
}

/*********************************************************
 * Space::getName method
 * gets name
 *********************************************************/
string Space::getName()
{
    return "Space";
}
/*********************************************************
 * Space::getNorth method
 * gets north space
 *********************************************************/
shared_ptr<Space>  Space::getNorth(vector<vector<shared_ptr<Space>>> inVector, int inRow, int inCol)
{
    try {
        north = inVector.at(inRow - 1).at(inCol);
        if(north->getCompleted() == false)
        {
            cout << "1. North: " << north->getName() <<endl;
            return north;
        }
        if(north->getCompleted() == true)
        {
            cout << "1. North:" << north->getName() <<" (Already Completed)" <<endl;
            return north;
        }
    } catch (const out_of_range& oor) {
        cout << "1. North: Not Available" <<endl;
        return NULL;
        
    }
 
}
/*********************************************************
 * Space::getSouth method
 * gets south space
 *********************************************************/
shared_ptr<Space> Space::getSouth(vector<vector<shared_ptr<Space>>> inVector, int inRow, int inCol)
{
    try {
        south = inVector.at(inRow + 1).at(inCol);
        if(south->getCompleted() == false)
        {
            cout << "2. South: " << south->getName() <<endl;
            return south;
        }
        if(south->getCompleted() == true)
        {
            cout << "2. South:" << south->getName() <<" (Already Completed)" <<endl;
            return south;
        }
    } catch (const out_of_range& oor) {
        cout << "2. South: Not Available" <<endl;
        return NULL;
        
    }
}
/*********************************************************
 * Space::getEast method
 * gets east space
 *********************************************************/
shared_ptr<Space> Space::getEast(vector<vector<shared_ptr<Space>>> inVector, int inRow, int inCol)
{
    try {
        east = inVector.at(inRow).at(inCol + 1);
        if(east->getCompleted() == false)
            {
            cout << "3. East: " << east->getName() <<endl;
            return east;
            }
        if(east->getCompleted() == true)
            {
            cout << "3. East:" << east->getName() <<" (Already Completed)" <<endl;
                return east;
            }
    } catch (const out_of_range& oor) {
        cout << "3. East: Not Available" <<endl;
        return NULL;
        
    }
}
/*********************************************************
 * Space::getWest method
 * gets west space
 *********************************************************/
shared_ptr<Space> Space::getWest(vector<vector<shared_ptr<Space>>> inVector, int inRow, int inCol)
{
    try {
        west = inVector.at(inRow).at(inCol - 1);
        if(west->getCompleted() == false)
        {
            cout << "4. West: " << west->getName() <<endl;
            return west;
        }
        if(west->getCompleted() == true)
        {
            cout << "4. West:" << west->getName() <<" (Already Completed)" <<endl;
            return west;
        }
    } catch (const out_of_range& oor) {
        cout << "4. West: Not Available" <<endl;
        return NULL;
    }
}
/*******************************************************
 * Space::randomDouble method
 * generates random double number
 *********************************************************/
double Space::randomDouble(double minSeed, double maxSeed)
{
    random_device rd; //seed
    mt19937 gen(rd()); // a core engine class
    uniform_real_distribution<double> dist(minSeed,maxSeed);
    double randNum = dist(gen);
    return randNum;
}
/*******************************************************
 * Space::randomNumber method
 * generates random number
 *********************************************************/
int Space::randomInt(int minSeed, int maxSeed)
{
    random_device rd; //seed
    mt19937 gen(rd()); // a core engine class
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    int randNum = dist(gen);
    return randNum;
}

