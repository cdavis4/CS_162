//
//  HarryPotter.hpp
//  
//
//  Created by Carrie Davis on 8/2/18.
//

#ifndef HarryPotter_hpp
#define HarryPotter_hpp

#include "Character.hpp"

using namespace std;

class HarryPotter: public Character
{
    private :
    void Hogwarts(); // harry potter can come back to life
public:
    int xtraLife;
    HarryPotter();
    HarryPotter(string name,int armor,int attack,int defense,int strength, int inLife):Character(name,armor,attack,defense,strength)
    {
        xtraLife = inLife;
    }
    int combatAttack();
    void combatDefense(int);
};
#endif /* HarryPotter_hpp */
