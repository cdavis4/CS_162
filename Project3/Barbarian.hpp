//
//  Barbarian.hpp
//  
//
//  Created by Carrie Davis on 7/31/18.
//

#ifndef Barbarian_hpp
#define Barbarian_hpp
#include "Character.hpp"
using namespace std;

class Barbarian: public Character
{
public:
    Barbarian();
  Barbarian(string name,int armor,int attack,int defense,int strength):Character(name,armor,attack,defense,strength)
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


#endif /* Barbarian_hpp */
