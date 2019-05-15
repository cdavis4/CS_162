/***********************************************
 ** Author: carrie davis
 ** Date:August 14, 2018
 ** Description: Final Project; Balance derived class
 **********************************************/
#include <iostream>
#include "Balance.hpp"
Balance::Balance()
{
    
}
/*********************************************************
 * Balance::getName method
 * gets name
 *********************************************************/
string Balance::getName()
{
    return "Balance";
}
/*********************************************************
 * Balance::complete method
 * complete obstactle
 *********************************************************/
void Balance::complete(Runner &inRunner)
{
    double timeUsed;
    if(inRunner.getEnergy() >= 50)
    {
        timeUsed = randomDouble(0.10,0.50);
    }
    if(inRunner.getEnergy() < 50)
    {
        cout << "Your low energy is impacting performance!" <<endl;
        timeUsed = randomDouble(0.50,1.00);
    }
    
    int energyUsed = randomInt(1,5);
    cout <<"*************************"<<endl;
    cout <<inRunner.getName() <<" Stats for " << getName() <<endl;
    cout <<"------------------------"<<endl;
    cout <<"Distance: 20 Meters"<<endl;
    inRunner.subtractEnergy(energyUsed);
    inRunner.subtractTime(timeUsed);
    cout <<"*************************"<<endl;
    
    completed = true;
}
