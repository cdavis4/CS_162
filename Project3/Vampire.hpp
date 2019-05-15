//
//  Vampire.hpp
//  
//
//  Created by Carrie Davis on 8/2/18.
//

#ifndef Vampire_hpp
#define Vampire_hpp
#include "Character.hpp"
using namespace std;

class Vampire: public Character
{
public:
    Vampire();
    Vampire(string name,int armor,int attack,int defense,int strength):Character(name,armor,attack,defense,strength)
    {
        name = name;
        armor = armor;
        attack = attack;
        defense = defense;
        strength = strength;
    }
    int combatAttack();
    void combatDefense(int);
    int Charm(int);
    
};
#endif /* Vampire_hpp */
