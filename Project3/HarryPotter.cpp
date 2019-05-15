/*******************************************************
 ** Author: carrie davis
 ** Date:August 2, 2018
 ** Description: Project 3 Harry Potter
 ******************************************************/
#include <iostream>
#include <random>
#include <string>
using namespace std;

#include "HarryPotter.hpp"
/********************************************************
 * HarryPotter::HarryPotter
 * Override data members
 ********************************************************/
//Default Constructor
HarryPotter::HarryPotter()
{
    xtraLife = 0;
}

/*******************************************************
 * HarryPotter::attack method
 * attacks other player and inflicts damage
 *********************************************************/
int HarryPotter::combatAttack()
{
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(2,attack);
    int damageRoll = dist(gen);
    cout << "Harry Potter rolled " << damageRoll << " out of " << attack << " possible hit points." <<endl;
    
    return damageRoll; // subtract defenders roll and defenders armor
}
/*******************************************************
 * HarryPotter::defense method
 * defense takes damage when attacked
 *  calculates inflicted damage on strength
 *********************************************************/
void HarryPotter::combatDefense(int inDamage)
{
    //roll defense
    random_device rd; //seed
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(2,defense);
    int defenseRoll = dist(gen);
    int damageCalculated = inDamage - defenseRoll - armor;
    if(damageCalculated < 0) {damageCalculated =0;}
    //depends on roll then armor
    cout << "Harry Potter rolled " << defenseRoll << " out of " << defense << " possible defense points." <<endl;
    cout << "Armor deflects " << armor << " hit points." <<endl;
    cout << "Total damage inflicted: " <<damageCalculated <<endl;
    
    strength -=damageCalculated;
    if (strength <= 0)
        {Hogwarts();}
    
    cout << "Strength: " << strength <<endl;
}
/*******************************************************
 * HarryPotter::Hogwarts method
 * brings back from dead but only once
 *********************************************************/
void HarryPotter::Hogwarts()
{
    
    if (xtraLife == 0)
        {
        strength = 10;
        cout <<"Extra life of Hogwarts activated."<<endl;
        cout << "He's alive! "  <<endl;
        xtraLife = 1;
        }
    
}
