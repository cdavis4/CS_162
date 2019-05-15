/********************************************************************
 ** Author: carrie davis
 ** Date:July 1, 2018
 ** Description: Project 1 ; AntProgram function
 *********************************************************************/
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
using namespace std;


//#include "AntBoard.hpp"
#include "AntProgram.hpp"
//Default Constructor
AntProgram::AntProgram()
{
    placeAntChoice = 0;
    matrixSize = 0;
    row = 0;
    column = 0;
    steps = 0;
    

}
/********************************************************************
 * AntProgram::run method
 * runs program
 *********************************************************************/
void AntProgram::run()
    {
    //Langton's Ant simulation menu
    cout << "Welcome to Langton's Ant Simulation menu.\n" <<endl;
    cout << "First step is to create a square matrix. " <<endl;
    cout <<  "Pick a size between 2 and 20. " <<endl;
    cout <<  "Enter the size of your matrix: ";
        
    double inputMatrixSize; // to catch any values that are not int
    cin >> inputMatrixSize;
    matrixSize = static_cast<int>(inputMatrixSize);
        
    /********************************************************
    error check
    *********************************************************/
    while ((matrixSize < 2 || matrixSize > 20) || ((matrixSize % 1) != 0))
        {
        cout <<"Invalid input. Please enter a number between 2 and 100." <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Enter your choice: ";
            cin >> matrixSize;
        }
            
    //ant location menu
    cout <<"\n Second step is to place your ant on board\n " <<endl;
    cout << "1. Randomly place ant on board." <<endl;
    cout << "2. Choose where to place your ant on board.\n " <<endl;
    cout << "Enter your choice: ";
    cin >> placeAntChoice;
            
    /********************************************************
    error check
    *********************************************************/
    while (placeAntChoice < 1 || placeAntChoice > 2)
        {
        cout <<"Invalid input. Please enter either 1 to randomize or 2 to pick placement." <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your choice: ";
        cin >> placeAntChoice;
        }
            
    if (placeAntChoice == 1)
        {
        //seed value initalization and randomization
        int maxSeed = matrixSize - 1;
        int minSeed = 1;
                
        row = (rand() % (maxSeed - minSeed + 1) ) + minSeed;
        column =  (rand() % (maxSeed - minSeed + 1) ) + minSeed;
                
        cout << "Row selected for you is: " << row <<endl;
        cout <<  "Column selected for you is:  " << column <<endl;
        }
            
    if(placeAntChoice == 2)
        {
            cout << "Enter the row number between 1 and " << matrixSize<< ": " <<endl;
            cin >> row;
            cout << "Enter the column number between 1 and " << matrixSize << ": "<<endl;
            cin >> column;
                    
            /********************************************************
            error check
            *********************************************************/
            while ((row < 1 || row > matrixSize) || (column < 1 || column > matrixSize))
                {
                cout <<"Invalid input." <<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    cout << "Enter the row number between 1 and " << matrixSize << ": " <<endl;
                    cin >> row;
                    cout << "Enter the column number between 1 and " <<matrixSize << ": " <<endl;
                    cin >> column;
                }
            }
        
        Ant newAnt(row-1,column-1,'N');
        AntBoard newBoard(matrixSize);
        newBoard.placeAnt(&newAnt);
        
        cout << "Starting Setup for Simulation " <<endl;
        cout << "Matrix Size: " << matrixSize <<endl;
        cout << "Row: " << newAnt.getRow() <<endl;
        cout <<  "Column:  " << newAnt.getColumn() <<endl;
        cout <<  "Orientation:  " << newAnt.getOrientation() <<endl;
    
        
        //step menu
        cout <<" \n Third step is to pick number of steps or squares your ant will move.\n " <<endl;
        cout << "Enter your choice from 1 to 100: ";
        cin >> steps;
        /********************************************************
         error check
         *********************************************************/
        while (steps < 1 || steps > 100)
        {
            cout <<"Invalid Input." <<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Enter a number between 1 and 100. " <<endl;
            cin >> steps;
        }
        cout <<  " \n Langston's Ant Simulation \n";
        newBoard.print(&newAnt);
        int step = 1; // loops with counter to implement steps on board
        while(step <= steps)
        {   //move the ant the around board
            newBoard.moveAnt(&newAnt);
            cout <<  "Step: " << step << endl;
            newBoard.print(&newAnt);
            step ++;
        }
        newBoard.deleteBoard();
        
}
