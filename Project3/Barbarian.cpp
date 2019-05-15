/*******************************************************
 ** Author: carrie davis
 ** Date:July 31, 2018
 ** Description: Project 3 Barbarian
 ******************************************************/
#include <iostream>
#include <random>
#include <string>
using namespace std;
#include "Barbarian.hpp"

/********************************************************
 * Barbarian::
 * Override data members
 ********************************************************/
//Default Constructor
Barbarian::Barbarian()
{
}

/*******************************************************
 * Character::attack method
 * attacks other player and inflicts damage
 *********************************************************/
int Barbarian::combatAttack()
{
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(2,attack);
    int damageRoll = dist(gen);
    cout << "Barbarian rolled " << damageRoll << " out of " << attack << " possible hit points." <<endl;
    
    return damageRoll; // subtract defenders roll and defenders armor
}
/*******************************************************
 * Character::defense method
 * defense takes damage when attacked
 *  calculates inflicted damage on strength
 *********************************************************/
void Barbarian::combatDefense(int inDamage)
{
    //roll defense
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(2,defense);
    int defenseRoll = dist(gen);
    int damageCalculated = inDamage - defenseRoll - armor;
    if(damageCalculated < 0) {damageCalculated =0;}
    //depends on roll then armor
    cout << "Barbarian rolled " << defenseRoll << " out of " << defense << " possible defense points." <<endl;
    cout << "Armor deflects " << armor << " hit points." <<endl;
    cout << "Total damage inflicted: " <<damageCalculated <<endl;
    strength -=damageCalculated;
     cout << "Strength: " << strength <<endl;
}
