//
//  BlueMen.hpp
//  
//
//  Created by Carrie Davis on 8/2/18.
//

#ifndef BlueMen_hpp
#define BlueMen_hpp
#include "Character.hpp"
using namespace std;

class BlueMen: public Character
{
private:
    int Mob(); //returns minseed changes
public:
    BlueMen();
    BlueMen(string name,int armor,int attack,int defense,int strength):Character(name,armor,attack,defense,strength)
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

#endif /* BlueMen_hpp */
