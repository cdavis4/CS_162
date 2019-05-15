//
//  Penguin.hpp
//  
//
//  Created by Carrie Davis on 7/22/18.
//

#ifndef Penguin_hpp
#define Penguin_hpp

#include "Animal.hpp"
class Penguin: public Animal{
public:
    //derived all functions from animal
    Penguin(int age,int baby,int foodCost,int payOff): Animal(age,baby,foodCost,payOff)
    {
    }
    Penguin();
    virtual ~Penguin(){}
    TYPE getType();
};
#endif /* Penguin_hpp */
