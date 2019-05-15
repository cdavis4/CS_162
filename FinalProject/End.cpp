
/***********************************************
 ** Author: carrie davis
 ** Date:August 14, 2018
 ** Description: Final Project; End derived class
 **********************************************/
#include <iostream>
#include "End.hpp"
End::End()
{
   
}
/*********************************************************
 * End::getName method
 * gets name
 *********************************************************/
string End::getName()
{
    return "End";
}
/*********************************************************
 * End::complete method
 * complete obstactle
 *********************************************************/
void End::complete(Runner &inRunner)
{
    cout <<"*************************"<<endl;
    cout <<inRunner.getName() <<" Finished the Course !" <<endl;
    cout <<"------------------------"<<endl;
    cout << "Total Time To Complete: " << 10 - inRunner.getTime() <<endl;
    cout << "Energy Left: " << inRunner.getEnergy() <<endl;
    cout <<"*************************"<<endl;
    completed = true;
}
