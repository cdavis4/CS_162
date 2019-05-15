/********************************************************************
 ** Author: carrie davis
 ** Date:July 7, 2018
 ** Description: Lab 2 main
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;
#include "LetterFrequency.hpp"

int main()
{
    string fileName;
    int count;
    
    //Get input file name from user
    cout << "Please enter your filename." << endl;
    cin >> fileName;
    
    //Open input file if exists
    ifstream inputFile;
    inputFile.open(fileName.c_str());
    
    //error checking
    while(!inputFile && count!=6)
        {
            count++;
            cout << "Could not open file. Please try again." <<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Enter File Name: ";
            cin >> fileName;
            inputFile.open(fileName.c_str());
            if(count == 6)
            {
                cout << "Too many failed inputs.";
                cout << "Quiting program." <<endl;
            }
        }
   
    //Dynamic array to hold letter count for inputFile
    int* myArray = new int[27];

    LetterFrequency newCounter;
    newCounter.count_letters(inputFile, myArray);
    
    //clear memory
    delete []myArray;
    
    //close input file and write total to output file
    inputFile.close();
    
    return 0;
}
