/*******************************************************
 ** Author: carrie davis
 ** Date:August 2, 2018
 ** Description: Project 3 Medusa
 ******************************************************/
#include <iostream>
#include <random>
#include <string>
using namespace std;

#include "Medusa.hpp"
/********************************************************
 * Medusa::Medusa
 * Override data members
 ********************************************************/
//Default Constructor
Medusa::Medusa()
{
}
/*******************************************************
 * Medusa::attack method
 * attacks other player and inflicts damage
 *********************************************************/
int Medusa::combatAttack()
{
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(2,attack);
    int damageRoll = dist(gen);
    if(damageRoll == 12) //GLARE of Medusa
        {
            cout << "Attacker rolled " << damageRoll << "." <<endl;
            cout << "Medusa GLARE activated!" <<endl;
            damageRoll = 50;
        }
    cout << "Medusa rolled " << damageRoll << " out of " << attack << " possible hit points." <<endl;

    return damageRoll; // subtract defenders roll and defenders armor
}
/*******************************************************
 * Medusa::defense method
 * defense takes damage when attacked
 *  calculates inflicted damage on strength
 *********************************************************/
void Medusa::combatDefense(int inDamage)
{
    //roll defense
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1,defense);
    int defenseRoll = dist(gen);
    int damageCalculated = inDamage - defenseRoll - armor;
    if(damageCalculated < 0) {damageCalculated =0;}
    //depends on roll then armor
    cout << "Medusa rolled " << defenseRoll << " out of " << defense << " possible defense points." <<endl;
    cout << "Armor deflects " << armor << " hit points." <<endl;
    cout << "Total damage inflicted: " <<damageCalculated <<endl;
    
    strength -=damageCalculated;
    cout << "Strength: " << strength <<endl;
}

