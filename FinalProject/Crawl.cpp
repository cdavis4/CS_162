/***********************************************
 ** Author: carrie davis
 ** Date:August 14, 2018
 ** Description: Final Project; Crawl derived class
 **********************************************/
#include <iostream>
#include "Crawl.hpp"
Crawl::Crawl()
{
    
}
/*********************************************************
 * Crawl::getName method
 * gets name
 *********************************************************/
string Crawl::getName()
{
    return "Balance";
}
/*********************************************************
 * Crawl::complete method
 * complete obstactle
 *********************************************************/
void Crawl::complete(Runner &inRunner)
{
    double timeUsed;
    if(inRunner.getEnergy() >= 50)
    {
        timeUsed = randomDouble(0.40,1.50);
    }
    if(inRunner.getEnergy() < 50)
    {
          cout << "Your low energy is impacting performance!" <<endl;
        timeUsed = randomDouble(1.00,2.00);
    }
    
    int energyUsed = randomInt(1,20);
    cout <<"*************************"<<endl;
    cout <<inRunner.getName() <<" Stats for " << getName() <<endl;
    cout <<"------------------------"<<endl;
    cout <<"Distance: 100 Meters"<<endl;
    inRunner.subtractEnergy(energyUsed);
    inRunner.subtractTime(timeUsed);
    cout <<"*************************"<<endl;
    
    completed = true;
}
