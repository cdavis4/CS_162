/***********************************************
 ** Author: carrie davis
 ** Date:August 14, 2018
 ** Description: Final Project; Run derived class
 **********************************************/
#include <iostream>
#include "Run.hpp"
Run::Run()
{
    
}
/*********************************************************
 * Run::getName method
 * gets name
 *********************************************************/
string Run::getName()
{
    return "Run";
}
/*********************************************************
 * Run::complete method
 * complete obstactle
 *********************************************************/
void Run::complete(Runner &inRunner)
{
    double timeUsed;
    if(inRunner.getEnergy() >= 50)
    {
        timeUsed = randomDouble(0.45,2.00);
    }
    if(inRunner.getEnergy() < 50)
    {
        cout << "Your low energy is impacting performance!" <<endl;
        timeUsed = randomDouble(1.00,3.00);
    }
    
    int energyUsed = randomInt(5,25);
    cout <<"*************************"<<endl;
    cout <<inRunner.getName() <<" Stats for " << getName() <<endl;
    cout <<"------------------------"<<endl;
    cout <<"Distance: 400 Meters"<<endl;
    inRunner.subtractEnergy(energyUsed);
    inRunner.subtractTime(timeUsed);
    cout <<"*************************"<<endl;
    
    completed = true;
}
