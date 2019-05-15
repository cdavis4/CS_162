/*******************************************************
 ** Author: carrie davis
 ** Date:July 31, 2018
 ** Description: Project 3 Blue Men
 ******************************************************/
#include <iostream>
#include <random>
#include <string>
using namespace std;
#include "BlueMen.hpp"

/********************************************************
 * BlueMen::Bluemen
 * Override data members
 ********************************************************/
//Default Constructor
BlueMen::BlueMen()
{
}

/*******************************************************
 * BlueMen::attack method
 * attacks other player and inflicts damage
 *********************************************************/
int BlueMen::combatAttack()
{
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(2,attack);
    int damageRoll = dist(gen);
    cout << "Blue Men rolled " << damageRoll << " out of " << attack << " possible hit points." <<endl;
    
    return damageRoll; // subtract defenders roll and defenders armor
}
/*******************************************************
 * BlueMen::defense method
 * defense takes damage when attacked
 *  calculates inflicted damage on strength
 *********************************************************/
void BlueMen::combatDefense(int inDamage)
{
    //check to see what defense value will be based on strength
    int minSeed = Mob();
    //roll defense
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(minSeed,defense);
    int defenseRoll = dist(gen);
    int damageCalculated = inDamage - defenseRoll - armor;
    if(damageCalculated < 0) {damageCalculated =0;}
    //depends on roll then armor
    cout << "Blue Men rolled " << defenseRoll << " out of " << defense << " possible defense points." <<endl;
    cout << "Armor deflects " << armor << " hit points." <<endl;
    cout << "Total damage inflicted: " <<damageCalculated <<endl;
    
    strength -=damageCalculated;
    cout << "Strength: " << strength <<endl;
}
/*******************************************************
 * BlueMen::Mob method
 * defense lowers when strength lowers
 *  calculates what the defense die should be based on strength
 *********************************************************/
int BlueMen::Mob()
{
    int minSeed;
    if(strength >=9)
        {
            defense = 18;
            return minSeed = 3;
        }
    else if(strength <= 8 && strength >= 5)
        {
            defense = 12;
             return minSeed = 2;
        }
    else if(strength <= 4)
        {
            defense = 6;
             return minSeed = 1;
        }
}
