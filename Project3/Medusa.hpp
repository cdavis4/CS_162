//
//  Medusa.hpp
//  
//
//  Created by Carrie Davis on 8/2/18.
//

#ifndef Medusa_hpp
#define Medusa_hpp
#include "Character.hpp"
using namespace std;

class Medusa: public Character
{
public:
    Medusa();
    Medusa(string name,int armor,int attack,int defense,int strength):Character(name,armor,attack,defense,strength)
    {
        name = name;
        armor = armor;
        attack = attack;
        defense = defense;
        strength = strength;
    }
    int combatAttack();
    void combatDefense(int);
};



#endif /* Medusa_hpp */
