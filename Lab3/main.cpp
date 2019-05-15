/********************************************************************
 ** Author: carrie davis
 ** Date:July 11, 2018
 ** Description: Lab 3 main
 *********************************************************************/
//First, create a menu that first asks the user to select from the following 2 choices:
/**
Play game
Exit game **/
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "Game.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

int main()
{
    int choice;
    
    //start menu
    cout << "1. Play game" << endl;
    cout << "2. Exit Game" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    /********************************************************
     error check
     *********************************************************/
    
    while ((choice < 1 || choice > 2) || ((choice % 1) != 0))
    {
        cout <<"Invalid input. Please enter 1 to start program or 2 to quit. " <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your choice: ";
        cin >> choice;
    }
    
    if(choice == 1)
    {
       
        Game newGame;
        newGame.play();
    }
    return 0;
}
