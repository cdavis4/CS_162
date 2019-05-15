/********************************************************************
 ** Author: carrie davis
 ** Date:July 17, 2018
 ** Description: Project 2 main
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "ZooTycoon.hpp"

int main()
{
    int choice;
    
    //start menu
    system("clear");
    cout << "\n Welcome to Zoo Tycoon.\n\n";
    cout << "1. Play Game" << endl;
    cout << "2. Exit Game" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    /********************************************************
     error check
     *********************************************************/

   while (choice != 1 && choice != 2)
    {
        cout <<"Invalid input. Please enter 1 to start program or 2 to quit. " <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your choice: ";
        cin >> choice;
    }
    
    if(choice == 1)
    {
        //clear cin
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        //create game instance and start play
        ZooTycoon newGame;
        newGame.play();
        exit(0);
    }
    return 0;
}
