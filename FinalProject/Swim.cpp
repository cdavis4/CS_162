/***********************************************
 ** Author: carrie davis
 ** Date:August 14, 2018
 ** Description: Final Project; Swim derived class
 **********************************************/
#include <iostream>
#include "Swim.hpp"
Swim::Swim()
{
   
}
/*********************************************************
 * Space::getName method
 * gets Space name
 *********************************************************/
string Swim::getName()
{
    return "Swim";
}
/*********************************************************
 * Swim::complete method
 * complete obstactle
 *********************************************************/
void Swim::complete(Runner &inRunner)
{
    double timeUsed;
    if(inRunner.getEnergy() >= 50)
        {
        timeUsed = randomDouble(0.30,1.00);
        }
    if(inRunner.getEnergy() < 50)
        {
            cout << "Your low energy is impacting performance!" <<endl;
            timeUsed = randomDouble(1.00,2.00);
        }

    int energyUsed = randomInt(5,20);
    cout <<"*************************"<<endl;
    cout <<inRunner.getName() <<" Stats for " << getName() <<endl;
    cout <<"------------------------"<<endl;
    cout <<"Distance: 50 Meters"<<endl;
    inRunner.subtractEnergy(energyUsed);
    inRunner.subtractTime(timeUsed);
     cout <<"*************************"<<endl;
    
    completed = true;
}
