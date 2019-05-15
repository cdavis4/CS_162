//
//  Animal.hpp
//  
//
//  Created by Carrie Davis on 7/17/18.
//
#include <iostream>
#include <string>
#ifndef Animal_hpp
#define Animal_hpp
using namespace std;


enum TYPE{TIGER,PENGUIN,TURTLE,OTHER,NONE}; // type of animals that can be added

class Animal{
protected: // accessable to friends and dervied classes
    int age;
    int baby;
    int foodCost;
    int cost;
    int payOff;
    TYPE type;
    string typeString;
public: //member function prototypes
    Animal();//Default constructor
    virtual ~Animal(){} // Default destructor
    Animal(int,int,int,int); // constructor with parameters
    void setCost(int);
    int getAge();
    void setAge(int);
    int getCost();
    int getPayOff();
    int getBabies();
    int getFoodCost();
    virtual TYPE getType() {return NONE;}
    virtual void setStringOther(string inType) { }
    virtual void setBabies(int inputBaby){baby = inputBaby;}
    virtual void setPayOff(int inputPayOff){payOff = inputPayOff;}
    virtual void setFoodCost(int){}
    virtual string getStringOther() { return "NONE";}

};



#endif /* Animal_hpp */
