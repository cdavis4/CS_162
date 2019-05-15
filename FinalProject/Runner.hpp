//
//  Runner.hpp
//  Created by Carrie Davis on 8/8/18.
//

#ifndef Runner_hpp
#define Runner_hpp
#include <iostream>
#include <vector>
#include <string>
#include "Fuel.hpp"
using namespace std;

class Runner{
    
  
    
private:
    // this is what the runner carries
    vector <Fuel> fuelbelt; //limiting size using interface
    string name;
    int energy; // tally points at end of game to add to score
    double time; // time that has passed for runner
    int row;  //location on the 2d array
    int column; //location on the 2d array

    
public:
    Runner();
    string getName();
    void setName(string);
    int getEnergy();
    void addEnergy(int);
    double getTime();
    void subtractTime(double);
    void subtractEnergy(int);
    int getRow();
    int getCol();
    void setRow(int);
    void setCol(int);
    void fuelUp();
    void addFuel();
   // int pickFuel();
   // void fuelOptions();
   // void addFuel();
};

#endif /* Runner_hpp */
