/*******************************************************
 ** Author: carrie davis
 ** Date:August 2, 2018
 ** Description: Project 3 Vampire
 ******************************************************/
#include <iostream>
#include <random>
#include <string>
using namespace std;

#include "Vampire.hpp"

/********************************************************
 * Vampire::Vampire
 * Override data members
 ********************************************************/
//Default Constructor
Vampire::Vampire()
{
}

/*******************************************************
 * Vampire::attack method
 * attacks other player and inflicts damage
 *********************************************************/
int Vampire::combatAttack()
{
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,attack);
    int damageRoll = dist(gen);
    cout << "Vampire rolled " << damageRoll << " out of " << attack << " possible hit points." <<endl;
    
    return damageRoll; // subtract defenders roll and defenders armor
}
/*******************************************************
 * Vampire::defense method
 * defense takes damage when attacked
 *  calculates inflicted damage on strength
 *********************************************************/
void Vampire::combatDefense(int inDamage)
{
    int actualDamage = Charm(inDamage); // 50/50 chance of being turned to 0
    //roll defense
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,defense);
    int defenseRoll = dist(gen);
    int damageCalculated = actualDamage - defenseRoll - armor;
    if(damageCalculated < 0) {damageCalculated =0;}
    //depends on roll then armor
    cout << "Vampire rolled " << defenseRoll << " out of " << defense << " possible defense points." <<endl;
    cout << "Armor deflects " << armor << " hit points." <<endl;
    cout << "Total damage inflicted: " <<damageCalculated <<endl;
    
    strength -=damageCalculated;
    cout << "Strength: " << strength <<endl;
}
/*******************************************************
 * Vampire::Charm method
 * calculates if inDamage occurs
 * 50% chance
 *********************************************************/
int Vampire::Charm(int inDamage)
{
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,2);
    int charmRoll = dist(gen);
    if(charmRoll == 1)
        { return inDamage;}
    cout <<"Vampire is turning on the Charm!" <<endl;
    cout <<"Your player can not damage him." <<endl;
    return 0; // if 2 then zero damage
    
   
}
