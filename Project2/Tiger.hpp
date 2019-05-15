//
//  Tiger.hpp
//  
//
//  Created by Carrie Davis on 7/22/18.
//

#ifndef Tiger_hpp
#define Tiger_hpp

#include "Animal.hpp"

class Tiger: public Animal{
    
    
public:
    //derived all functions from animal
    Tiger(int age,int baby,int foodCost,int payOff): Animal(age,baby,foodCost,payOff)
    {
    }
    Tiger();
    //virtual ~Tiger(){}
    TYPE getType();
};

#endif /* Tiger_hpp */
