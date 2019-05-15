//
//  newAnimal.hpp
//  
//
//  Created by Carrie Davis on 7/22/18.
//

#ifndef newAnimal_hpp
#define newAnimal_hpp

#include "Animal.hpp"

class newAnimal: public Animal{
    
public:
    //derived all functions from animal
    newAnimal(int age,int baby,int foodCost,int payOff): Animal(age,baby,foodCost,payOff)
    {
    }
    newAnimal();
    virtual ~newAnimal(){}
    void setCost(int);
    int getCost();
    TYPE getType();
    string getStringOther();
    void setStringOther(string);
    void setBabies(int);
    void setFoodCost(int);
    void setPayOff(int);
};


#endif /* newAnimal_hpp */
