/**************************************
 ** Author: carrie davis
 ** Date:July 12, 2018
 ** Description: Lab 3; LoadedDie
 ****************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <random>

using namespace std;
#include "LoadedDie.hpp"



/*************************************************
 * Die::rollDie
 * rolls die and provides result
 **************************************************/
int LoadedDie::rollDie()
{
    double biased;
    
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    int maxSeed = this->N;
    int minSeed = 1;
    
    do{
        uniform_int_distribution<int> dist(minSeed,maxSeed);
        rollResult = dist(gen);
        //rollResult = rand() % maxSeed + 1;
        // checking if closed to max seed
        biased = (rollResult / static_cast<double>(maxSeed));
    }while(biased <= 0.66);
    
    cout << "Loaded Die, Roll Result: ";

    return rollResult;
    
}
