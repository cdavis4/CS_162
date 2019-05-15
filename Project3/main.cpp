/********************************************************************
 ** Author: carrie davis
 ** Date:July 31, 2018
 ** Description: Project 3; main runs Fantasy Combat Game
 *********************************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

#include "CombatGame.hpp"

int main()
{
    int choice;
    
    do
    { //start menu
        cout << "1. Start Fantasy Combat " <<endl;
        cout << "2. Exit Program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        /********************************************************
         error check
         *********************************************************/
        
        while (choice < 1 || choice > 2)
        {
            cout <<"Invalid input. Please enter 1 to start program or 2 to quit. " <<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Enter your choice: ";
            cin >> choice;
        }
        
        if(choice == 1)
        {
            //run program
            CombatGame program;
            program.combat();
            cout << "GAME OVER" <<endl;
        }
        
    }while (choice != 2);  //Loop again if user did not select to quit
    
}
