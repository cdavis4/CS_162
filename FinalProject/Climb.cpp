/***********************************************
 ** Author: carrie davis
 ** Date:August 14, 2018
 ** Description: Final Project; Climb derived class
 **********************************************/
#include <iostream>
#include "Climb.hpp"
Climb::Climb()
{
    
}
/*********************************************************
 * Climb::getName method
 * gets  name
 *********************************************************/
string Climb::getName()
{
    return "Climb";
}
/*********************************************************
 * Climb::complete method
 * complete obstactle
 *********************************************************/
void Climb::complete(Runner &inRunner)
{
    double timeUsed;
    if(inRunner.getEnergy() >= 50)
        {
        timeUsed = randomDouble(0.50,1.50);
        }
    if(inRunner.getEnergy() < 50)
        {
        timeUsed = randomDouble(1.00,2.00);
        }

    int energyUsed = randomInt(10,20);
    cout <<"*************************"<<endl;
    cout <<inRunner.getName() <<" Stats for " << getName() <<endl;
    cout <<"------------------------"<<endl;
    cout <<"Distance: 50 Meters"<<endl;
    inRunner.subtractEnergy(energyUsed);
    inRunner.subtractTime(timeUsed);
    cout <<"*************************"<<endl;
    
    completed = true;
}
