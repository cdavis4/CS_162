/****************************************************
 ** Author: carrie davis
 ** Date:July 7, 2018
 ** Description: Lab 3 ; Die Class
*****************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <random>

using namespace std;
#include "Die.hpp"
#include "LoadedDie.hpp"

//Default Constructor
Die::Die()
{
    this->N = 0;
}

/*****************************************************
 * Die::Die
 * sets number of sides for die and Type for die object
 *****************************************************/
 Die::Die(int inSides)
{
    this->N = inSides;
}

/*****************************************************
 * Die::getSides
 * gets number of sides for die
 *****************************************************/
int Die::getSides()
{
    return this->N;
}
/*****************************************************
 * Die::rollDie
 * rolls die and provides result
 *****************************************************/
int Die::rollDie()
{
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    int maxSeed = this->N;
    int minSeed = 1;
    
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    rollResult = dist(gen);
    cout << "Regular Die, Roll Result: ";
 
    return rollResult;
}


