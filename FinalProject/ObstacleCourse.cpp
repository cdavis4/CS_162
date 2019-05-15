/***********************************************
 ** Author: carrie davis
 ** Date:August 8, 2018
 ** Description: Final Project; ObstacleCourse file
 ************************************************/
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <random>
#include <memory>
using namespace std;
#include "ObstacleCourse.hpp"

ObstacleCourse::ObstacleCourse()
{
   
}

/*******************************************************
 * ObstacleCourse::randomNumber method
 * generates random number
 *********************************************************/
int ObstacleCourse::randomNumber(int minSeed, int maxSeed)
{
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    int randNum = dist(gen);
    return randNum;
}
/*******************************************************
 * ObstacleCourse::print method
 * generates random number
 *********************************************************/
void ObstacleCourse::print()
{
    // Displaying the 2D vector
    for (int row = 0; row < course.size(); row++) {
        for (int column = 0; column < course[row].size(); column++)
            if((course[row][column]->getCompleted() == true )|| (course[row][column]->getName() == "Start") || (course[row][column]->getName() == "End"))
            {cout <<  "  "<< course[row][column]->getName() << " ";}
            else{ cout<<"  *   ";}
        cout << endl;
    }
    
}
/*******************************************************
* ObstacleCourse::run method
* has runner do obstacle course while they have energy
*********************************************************/
void ObstacleCourse::run()
{
    setUpCourse(); //set obstacles in course
    string runnerName;
    int startChoice;
    double choice;
    //name your runner

    cout << "Who do you pick to run this course?"<<endl;
    cout << "Enter name of your runner" <<endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    getline(cin,runnerName);
    
    Runner myRunner;
    myRunner.setName(runnerName);
    cout << "******************************"<<endl;
    cout << myRunner.getName() << " your goal is to find the quickest path to the end of this course" <<endl;
    cout << "This course will take a tremedous amount of energy." <<endl;
    cout << "Time is not on your side." <<endl;
    cout << "You have 10 minutes to get to the End." <<endl;
    cout << "You will start at 100% energy. "<<endl;
    cout << "Each obstacle uses a percentage of your energy reserves. "<<endl;
    cout << "The more energy, the quicker you will complete this course. " <<endl;
    cout << "Use your fuel belt and aid stations available throughout the course." <<endl;
    cout << "Stopping will take time but you do not want to run out of energy or you will bonk!" <<endl;
    
    do{
        cout << "Are you ready to take on this challenge?" <<endl;
        cout << "1. Yes" << endl;
        cout << "2. See Map" << endl;
        cout << "3. Exit Game" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        startChoice = static_cast<int>(choice);
    
        /********************************************************
         error check
         *********************************************************/
    
        while (startChoice != 1 && startChoice != 2 && startChoice !=3)
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout <<"Invalid Entry " <<endl;
                cout << "Are you ready to take on this challenge?" <<endl;
                cout << "1. Yes" << endl;
                cout << "2. See Map" << endl;
                cout << "3. Exit Game" << endl;
                cout << "Enter your choice: ";
                cin >> choice;
                startChoice = static_cast<int>(choice);
            }
    
        if (startChoice == 1)
            {
                myRunner.setCol(0);
                myRunner.setRow(0);
                course[myRunner.getRow()][myRunner.getCol()]->complete(myRunner);
                navigateCourse(myRunner);
            }
        if (startChoice == 2)
        {
            cout<< "------Map-------" <<endl;
            print();
        }
        if (startChoice == 3)
        {
        exit(0);
        }
    }while(startChoice == 2);
}
/****************************************************
* ObstacleCourse::addObstacle method
* add random obstactle
*********************************************************/
shared_ptr<Space> ObstacleCourse::addObstacle(int inType)
{
if (inType == 1)
    {
     shared_ptr<Space> outPtr = make_shared<Swim>();
     return outPtr;
    }
if (inType == 2)
    {
       shared_ptr<Space> outPtr = make_shared<Run>();
        return outPtr;
    }
if (inType == 3)
    {
      shared_ptr<Space> outPtr = make_shared<Balance>();
        return outPtr;
    }
if (inType == 4)
    {
        shared_ptr<Space> outPtr = make_shared<Run>();
        return outPtr;
        
    }
if (inType == 5)
    {
       shared_ptr<Space> outPtr = make_shared<Climb>();
        return outPtr;
    }
if (inType == 6)
    {
       shared_ptr<Space> outPtr = make_shared<Crawl>();
        return outPtr;
    }
    
}
/*******************************************************
 * ObstacleCourse::setupCourse method
 * setting up obstacles in course
 *********************************************************/
void ObstacleCourse::setUpCourse()
{
    int row;
    int column;
    // adding the start space and end space
    shared_ptr<Space> endPtr = make_shared<End>();
    shared_ptr<Space> startPtr = make_shared<Start>();
    
    course[9][3] = endPtr;
    course[0][0] = startPtr;
    for (row = 0; row < course.size(); row++) {
        for (column = 0; column < course[row].size(); column++)
        {
            int inSpace = randomNumber(1,6);
            if(course[row][column] == NULL)
            {
                course[row][column] = addObstacle(inSpace);
            }
        }
    }
}
/*******************************************************
 * ObstacleCourse::navigateCourse method
 * navigate obstacles in course
 *********************************************************/
void ObstacleCourse::navigateCourse(Runner& inRunner)
{
    do{
        //make sure clear from previous entry extras
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        int choice;
        double dirChoice;
        //get runner row and column location to find obstacles in diff direction
        int row =inRunner.getRow();
        int column = inRunner.getCol();
        
        cout << "\n Choose your next obstacle. \n" <<endl;
        shared_ptr<Space> north = course[row][column]->getNorth(course,row,column); //1
        shared_ptr<Space> south = course[row][column]->getSouth(course,row,column);//2
        shared_ptr<Space> east = course[row][column]->getEast(course,row,column);//3
        shared_ptr<Space> west = course[row][column]->getWest(course,row,column);//4
        cout << "5. See Map" << endl;
        cout << "6. See Stats" <<endl;
        cout << "7. Use Fuel Belt" <<endl;
        cout << "8. Visit Aid Station" <<endl;
        cout << "9. Exit Game" << endl;
        cout << "Enter your choice: ";
        cin >> dirChoice;
        choice = static_cast<int>(dirChoice);
        
        while (choice < 1 || choice > 9 || cin.fail())
        {
            cout <<"Invalid input. " <<endl;
            cout <<"1. North, 2. South, 3.East, 4.West" <<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Enter your choice: ";
            cin >> dirChoice;
            choice = static_cast<int>(dirChoice);
            cout << "\n"<<endl;
        }
        if(choice == 1)
        {
            if (north)
            {
                if(north->getCompleted() == false)
                    {
                    north->complete(inRunner);
                    inRunner.setCol(column);
                    inRunner.setRow(row - 1);
                    }
            }
        }
        if(choice == 2)
        {
            if(south)
            {
                
                if(south->getCompleted() == false)
                    {
                    south->complete(inRunner);
                    inRunner.setCol(column);
                    inRunner.setRow(row + 1);
                    }
            }
        }
        if(choice == 3)
        {
            if(east)
            {
                if(east->getCompleted() == false)
                {
                    east->complete(inRunner);
                    inRunner.setCol(column + 1);
                    inRunner.setRow(row);
                }
            }
        }
        if(choice == 4)
        {
            if(west)
            {
                if(west->getCompleted() == false)
                {
                    west->complete(inRunner);
                    inRunner.setCol(column - 1);
                    inRunner.setRow(row);
                }
            }
        }
        if(choice == 5)
        {
            cout <<"Uncompleted Obstactles show up *"<<endl;
            cout << "-----------Map Course ---------- "<<endl;
            print();
            cout <<"----------------------------------"<<endl;
        }
        if(choice == 6)
        {
       
            cout <<"\n"<<endl;
            cout <<"Stats for " << inRunner.getName() <<endl;
            cout <<"------------------------"<<endl;
            cout << "Time Available to Complete Course: " << inRunner.getTime() << " minutes" <<endl;
            cout << "Energy Available: " << inRunner.getEnergy() <<"/100" <<endl;
            cout <<"\n"<<endl;
        }
        if(choice == 7)
        {
            inRunner.fuelUp();
        }
        if(choice == 8)
        {
            inRunner.addFuel();
        }
        if(choice == 9)
        {
            exit(0);
        }
      
    }while((inRunner.getEnergy() > 0) && (course[9][3]->getCompleted() == false) && ( inRunner.getTime() > 0)) ; //play until game over by energy depleted, time up or complete
    cout << "Your Course Completed" << endl;
    cout << "------------------------" << endl;
    print();
    if(inRunner.getEnergy() <=0)
    {
        cout<< "GAME OVER!" <<endl;
        cout<< inRunner.getName() << " Ran Out of Energy!"<<endl;
    }
    if(inRunner.getTime() <=0)
    {
        cout<< "GAME OVER!" <<endl;
        cout<< inRunner.getName() << " Ran Out of Time!"<<endl;
    }
    
}


    
