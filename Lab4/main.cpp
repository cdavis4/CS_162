/********************************************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Lab 4 main
 *********************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;
#include "Student.hpp"
#include "Instructor.hpp"
#include "Building.hpp"
#include "University.hpp"

int main()
{
    int choice;
    //Information System program loop
    University oregonState;
    do{
    cout << "\n University Information System \n " <<endl;
    cout << "1. Print information about all the buildings" << endl;
    cout << "2. Print information on everybody at university" << endl;
    cout << "3. Choose a person to do work." << endl;
    cout << "4. Exit the program" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    /********************************************************
     input validation
     *********************************************************/
    
        while ((choice < 1 || choice > 4) || ((choice % 1) != 0))
        {
        cout <<"Invalid input " <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "1. Print information about all the buildings" << endl;
        cout << "2. Print information on everybody at university" << endl;
        cout << "3. Choose a person to do work." << endl;
        cout << "4. Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        }
    
    //choices
        if(choice == 1)
            {
                cout << "\n" <<endl;
            cout << oregonState.getName() << " People " << endl;
            oregonState.printBuildings();
        
            }
        if(choice == 2)
            {
                  cout << "\n" <<endl;
                cout << oregonState.getName() << "Buildings" <<endl;
                oregonState.printPeople();
            }
        if(choice == 3)
            {
                cout << "\n" <<endl;
                cout << oregonState.getName() << " People List" <<endl;
                cout << "Enter the number of the person you would like to work with." <<endl;
                oregonState.printPersonList();
            }
     //clears cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }while(choice !=4);  // exits with 4
    return 0;
}
