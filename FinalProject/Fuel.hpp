//
//  Fuel.hpp
//  
//
//  Created by Carrie Davis on 8/8/18.
//

#ifndef Fuel_hpp
#define Fuel_hpp

#include <iostream>
using namespace std;

class Fuel{
private:
    string name;
    int energyProvided;
    double timeTaken;
public:
    string getName();
    int getEnergyProvided();
    double getTimeTaken();
    Fuel(string,int, double);
};

#endif /* Fuel_hpp */
