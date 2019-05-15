/*******************************************************
 ** Author: carrie davis
 ** Date:July 31, 2018
 ** Description: Project 3 Character Abstract Base Class
 ******************************************************/
#ifndef Character_hpp
#define Character_hpp
using namespace std;

class Character{
    
public: // accessable to friends and derived classes
    int strength; // subtract damage, when gone dies
    string name; //depends on the type of character
    int attack;
    int defense;
    int armor;
    void setName(string);
    void setArmor(int);

    Character();
    Character(string,int,int,int,int); //name, armor, attack, defense and strength
    virtual ~Character(){};
    int getArmor();
    string getName();
    int getStrength();
    virtual int combatAttack()=0;//sets up standard on how character should attack
    virtual void combatDefense(int)=0; //sets standard on defense
 

};


#endif /* base_hpp */
