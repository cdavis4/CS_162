/*******************************************************
 ** Author: carrie davis
 ** Date:August 8, 2018
 ** Description: FinalProject  Runner Class
 ******************************************************/
#include <iostream>
#include <string>
#include <stack>
#include <memory>
#include <limits>
#include <ios>
#include <iomanip>

#include "Runner.hpp"
using namespace std;

//Default Constructor
Runner::Runner()
{
    this->name = "";
    this->energy = 100; // starts at 100%
    this->time = 15.00;
    this->row = 3; //starting row
    this->column = 0; //starting column
}

/*********************************************************
 * Runner::getName method
 * gets runner name
 *********************************************************/
string Runner::getName()
{
    return this->name;
}
/*******************************************************
 * Runner::setName method
 * sets character name
 *********************************************************/
void Runner::setName(string inName)
{
    name = inName;
}
/*********************************************************
 * Runner::getPoints method
 * gets runner's points
 *********************************************************/
int Runner::getEnergy()
{
    return this->energy;
}
/*******************************************************
 * Runner::addPoints method
 *adds to runner's points
 *********************************************************/
void Runner::addEnergy(int inEnergy)
{
    int addedPts = inEnergy;
    cout << "Energy Added: " << addedPts <<endl;
    energy += addedPts;
}
/*********************************************************
 * Runner::getTime method
 * gets runner time
 *********************************************************/
double Runner::getTime()
{
    return this->time;
}
/*******************************************************
 * Runner::subtractTime method
 * subtracts used time from time total
 *********************************************************/
void Runner::subtractTime(double inTime)
{
    double timeUsed = inTime;
    cout << "Time Taken: "  << fixed << setprecision(2) <<timeUsed << " minutes" <<endl;
    time -= timeUsed;
}
/*******************************************************
 * Runner::subtractTime method
 * subtracts used time from time total
 *********************************************************/
void Runner::subtractEnergy(int inEnergy)
{
    int energyUsed = inEnergy;
    cout << "Energy Used: " << energyUsed << "%" <<endl;
    energy -= energyUsed;
}
/*********************************************************
 * Runner::getRow method
 * gets runner's row location
 *********************************************************/
int Runner::getRow()
{
    return this->row;
}
/*******************************************************
 * Runner::setRow method
 *set's runner's row location
 *********************************************************/
void Runner::setRow(int inRow)
{
    row = inRow;
}
/*********************************************************
 * Runner::getColumn method
 * gets runner's row location
 *********************************************************/
int Runner::getCol()
{
    return this->column;
}
/*******************************************************
 * Runner::setColumn method
 *set's runner's row location
 *********************************************************/
void Runner::setCol(int inColumn)
{
    column = inColumn;
}
/*******************************************************
 * Runner::addFuel method
 *adds snack to belt
 *********************************************************/
void Runner::addFuel()
{
    double choice;
    int energyChoice;
    if (fuelbelt.size() >= 3)
    {
        cout<< "Your fuelbelt is full!" <<endl;
    }
    else if(fuelbelt.size() < 3)
    {
        cout << "Welcome to the Aid Station" <<endl;
        cout <<"Pick Energy Sources for your Fuel Belt" <<endl;
        cout <<"1. Gummies " <<endl;
        cout <<"2. Water Bottle" <<endl;
        cout<< "3. Energy Gel" <<endl;
        cout <<"4. Leave Aid Station" <<endl;
        cout << "Enter your choice: ";
        cin >>choice;
        energyChoice = static_cast<int>(choice);
    
        //error catch
    while (choice < 1 || choice > 4 || cin.fail())
        {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout <<"Invalid input. " <<endl;
        cout <<"1. Gummies " <<endl;
        cout <<"2. Water Bottle" <<endl;
        cout <<"3. Energy Gel" <<endl;
        cout<< "4. Leave Aid Station" <<endl;
        cout << "Enter your choice: ";
        cin >>choice;
        energyChoice = static_cast<int>(choice);
        }
        //
        if(energyChoice == 1)
        {
            cout <<"Good choice as Gunnies provide quick energy in a short period of time."<<endl;
            Fuel gummies("Gummies",20,0.10);
            fuelbelt.push_back(gummies);
            cout << "You picked: Gummies" <<endl;
            cout << "Energy Available: 20%"<<endl;
        }
        if(energyChoice == 2)
        {
            cout <<"Water is an essental choice."<<endl;
            Fuel water("Water",10,0.20);
            fuelbelt.push_back(water);
            cout << "You picked: Water" <<endl;
            cout << "Energy Available: 10%"<<endl;
        }
        if(energyChoice == 3)
        {
            cout <<"Energy Gel is a gooey."<<endl;
            Fuel gel("Gel",25,0.15);
            fuelbelt.push_back(gel);
            cout << "You picked: Gel" <<endl;
            cout << "Energy Available: 25%"<<endl;
        }
    }
}
/*******************************************************
 * Runner::fuelUp method
 *adds to time depending on fuel
 *********************************************************/
void Runner::fuelUp()
{
   if(!fuelbelt.empty())
   {
    //clear out cin
    cin.clear();
    cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
    double choice;
    int energyChoice;
    //output first item if not empty
    cout << "1: ";
    cout << fuelbelt[0].getName() <<endl;
     //check and output second item
    cout << "2: ";
    if(fuelbelt.size() >= 2)
        {
        cout << fuelbelt[1].getName() <<endl;
        }
     else{ cout <<"Empty" <<endl;}
    //check and output third item
    cout << "3: ";
    if(fuelbelt.size() == 3)
        {
        cout << fuelbelt[2].getName() <<endl;
        }
    else{ cout <<"Empty" <<endl;}
    
    cout << "4. Select Nothing" <<endl;
    cin >> choice;
    energyChoice = static_cast<int>(choice) - 1;
    //error check
        while (choice < 0 || choice > fuelbelt.size())
            {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
            cout <<"Invalid Entry " <<endl;
            cout <<"Enter integer value representing choice: ";
            cin >>choice;
            energyChoice = static_cast<int>(choice) - 1;
            }
    if(energyChoice != 4)
        {
        string name = fuelbelt[energyChoice].getName();
        cout << "You picked: "<<fuelbelt[energyChoice].getName() <<endl;
        cout << "Energy added: "<< fuelbelt[energyChoice].getEnergyProvided() << endl;
        energy += fuelbelt[energyChoice].getEnergyProvided();
        time -= fuelbelt[energyChoice].getTimeTaken();
        fuelbelt.erase(fuelbelt.begin()+energyChoice);//remove element
        }
   }
        else {cout << "You are out of snacks! " <<endl;}
}


