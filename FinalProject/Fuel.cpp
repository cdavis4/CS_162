/*******************************************************
 ** Author: carrie davis
 ** Date:August 8, 2018
 ** Description: FinalProject Fuel Class
 ******************************************************/
#include <iostream>
using namespace std;
#include "Fuel.hpp"
//constructor for energy fuels
Fuel::Fuel(string inName, int inEnergy, double inTime)
{
    name = inName;
    energyProvided = inEnergy;
    timeTaken = inTime;
}
/***************************************
 * Fuel::getName method
 * gets fuel name
 ***************************************/
string Fuel::getName()
{
    return name;
}
/****************************************
 * Fuel::getEnergy method
 * gets fuel energy
 ***************************************/
int Fuel::getEnergyProvided()
{
    return energyProvided;
}
/*******************************************
 * Fuel::getTimeTaken method
 * gets time it takes to have this snack
 *****************************************/
double Fuel::getTimeTaken()
{
    return timeTaken;
}
