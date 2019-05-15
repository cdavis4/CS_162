/********************************************************************
 ** Author: carrie davis
 ** Date:July 1, 2018
 ** Description: Project 1 ; AntProgram function
 *********************************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

//#include "Ant.hpp"
//#include "AntBoard.hpp"
#include "AntProgram.hpp"

int main()
{
    int choice;
    
    do
    { //start menu
    cout << "1. Start Langton's Ant simulation " <<endl;
    cout << "2. Quit" << endl;
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
            AntProgram program;
            program.run();
        }
        
    }while (choice != 2);  //Loop again if user did not select to quit
 
}
