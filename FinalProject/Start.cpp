/***********************************************
 ** Author: carrie davis
 ** Date:August 14, 2018
 ** Description: Final Project; Start derived class
 **********************************************/
#include <iostream>
#include "Start.hpp"
Start::Start()
{
    
}
/*********************************************************
 * Start::getName method
 * gets name
 *********************************************************/
string Start::getName()
{
    return "Start";
}
/*********************************************************
 * Start::complete method
 * complete obstactle
 *********************************************************/
void Start::complete(Runner &inRunner)
{
    cout <<"*************************"<<endl;
    cout <<"Start of Course " <<endl;
    cout <<"------------------------"<<endl;
    cout << "Time To Complete Course: " << inRunner.getTime() << " minutes" <<endl;
    cout << "Energy: " << inRunner.getEnergy() <<"%" <<endl;
    cout <<"*************************"<<endl;
    completed = true;
}
