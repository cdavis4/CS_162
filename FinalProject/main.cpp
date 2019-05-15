/***********************************************
 ** Author: carrie davis
 ** Date:August 14, 2018
 ** Description: Lab5 ; Final Project main file
 ************************************************/
#include <iostream>
#include <limits>
#include <string>
using namespace std;
#include "ObstacleCourse.hpp"


int main()
{
    double choice;
    int choiceInput;
    do{
        cout << "\n Try to beat the" <<endl;
        cout << "Obstacle Course of Doom.  \n " <<endl;
        cout << "This course is designed to test your physical abilities in " <<endl;
        cout << "climbing, running, crawling and balance." <<endl;
        cout << "1. Let's Start" << endl;
        cout << "2. Exit the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        choiceInput = static_cast<int>(choice);
        
        while (choiceInput != 1 && choiceInput != 2)
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "\n Invalid selection." <<endl;
            cout << "1. Let's Start" << endl;
            cout << "2. Exit the program" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            choiceInput = static_cast<int>(choice);
        }
        if (choiceInput == 1)
        {
            ObstacleCourse course;
            course.run();
        }
        if (choiceInput == 2)
        {
            exit(0);
        }
    }while(choiceInput != 2);
    return 0;
}
