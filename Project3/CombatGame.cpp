/********************************************
 ** Author: carrie davis
 ** Date:July 11, 2018
 ** Description: Lab 3; Combat Game
 *********************************************/
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <string>
#include "CombatGame.hpp"
using namespace std;


//Default Constructor
CombatGame::CombatGame()
{
    rounds = 1;
}

/********************************************
 * Game::combat
 * play rounds until player dies
 *******************************************/
void CombatGame::combat()
{
    //clear any extra from be used in next cin
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    cout << "Welcome to Fantasy Combat" <<endl;
    cout <<"****************************" <<endl;
    cout << "Player 1" <<endl;
    int round = 1;
    player1 =selectCharacter();
    
    //clear any extra from be used in next cin
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    cout << "Player 2" <<endl;
    player2 = selectCharacter();
    cout << " Now the battle starts" <<endl;

    //clear any extra from be used in next cin
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
   while((player1->getStrength() > 0 )&&(player2->getStrength() >0))
    {
    cout <<"**************************" <<endl;
    cout << "Round: " <<round <<endl;
    cout <<"**************************" <<endl;
    playRound();
     round++;
     }
    if((player1->getStrength() <= 0) && (player2->getStrength() > 0))
    {
        cout << "Player 1 " << player1->getName() << " has Lost! "<<endl;
        cout << "Player 2 wins with remaining strength of " << player2->getStrength() << " points." <<endl;
    }
    else if((player2->getStrength() <=0 )&& (player1->getStrength() > 0))
    {
        cout << "Player 2 " << player2->getName() << " has Lost! "<<endl;
        cout << "Player 1 wins with remaining strength of " << player1->getStrength() << " points." <<endl;
    }
    else if((player2->getStrength() <=0) && (player1->getStrength() <= 0))
    {
        cout << "Player 1 " << player1->getName() << " and Player 2 " << player2->getName() << " have tied! "<<endl;
    }
    delete player1;
    delete player2;
}

/********************************************
 * Game::playRound
 * determines who wins for round
 *******************************************/
void CombatGame::playRound()
{
    cout << "Player 1 " << player1->getName() << " Attacks! " <<endl;
    cout << "Attacker Strength: "<<  player1->getStrength() <<endl;
    int player2Damage = player1->combatAttack();
    cout <<"---------------------" <<endl;
    cout << "Player 2 " << player2->getName() << " Defends! " <<endl;
    player2->combatDefense(player2Damage);
    cout <<"--------------------" <<endl;
    cout << "Player 2 " << player2->getName() << " Attacks! " <<endl;
    cout << "Attacker Strength: "<< player2->getStrength() <<endl;
    int player1Damage = player2->combatAttack();
    cout <<"---------------------" <<endl;
    cout << "Player 1 " << player1->getName() << " Defends! " <<endl;
    player1->combatDefense(player1Damage);
    cout <<"---------------------" <<endl;
 
}

/********************************************
 * Game::selectCharacter
 * selects character and assigns to player
 *******************************************/
Character* CombatGame::selectCharacter()
{
    double characterChoice;
   
    cout << "Pick your Character. " <<endl;
    cout << "1. Barbarian" << endl;
    cout << "2. Blue Men" << endl;
    cout << "3. Harry Potter" << endl;
    cout << "4. Medusa" << endl;
    cout << "5. Vampire" << endl;
    cout << "Enter your fighter choice: ";
    cin >> characterChoice;
    int choice = static_cast<int>(characterChoice);
    
    while (choice != 1 && choice != 2 && choice !=3 && choice !=4 && choice !=5)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout <<"Invalid Entry" <<endl;
        cout << "1. Barbarian" << endl;
        cout << "2. Blue Men" << endl;
        cout << "3. Harry Potter" << endl;
        cout << "4. Medusa" << endl;
        cout << "5. Vampire" << endl;
        cout << "Enter your fighter choice: ";
        cin >> characterChoice;
        choice = static_cast<int>(characterChoice);
    }
    
    if (choice == 1)
    {
       
         cout << "You have selected a barbarian." << endl;
        cout << "Barbarians are big and strong. " << endl;
         cout << "They attack fiercely,but have week defense. " << endl;
        //create barbarian instance
        Character* outPtr = new Barbarian("Barbarian",0,12,12,12);// use defaults
        return outPtr;
    }
    if (choice == 2)
    {
        
        cout << "You have selected Blue Men." << endl;
        cout << "Blue Men are small, but fast and tough. " << endl;
        cout << "They are hard to hit,but have week defense when strength lowers. " << endl;
        ///create character instance
        Character* outPtr = new BlueMen("BlueMen",3,20,18,12);//base pointer to dynamic derived pointer
        return outPtr;
    }
    if (choice == 3)
    {
        
        cout << "You have selected Harry Potter." << endl;
        cout << "Harry Potter is a wizard. " << endl;
        cout << "He has the magic of Hogwarts behind him. " << endl;
        //create character instance
        Character* outPtr = new HarryPotter("Harry Potter",0,12,12,10,0);//base pointer to dynamic derived pointer
        return outPtr;
    }
    if (choice == 4)
    {
        
        cout << "You have selected Medusa." << endl;
        cout << "She has a stone cold glare and snakes in her hair. " << endl;

        //create character instance
        Character* outPtr = new Medusa("Medusa",3,12,6,8);//base pointer to dynamic derived pointer
        return outPtr;
    }
    if (choice == 5)
    {
        
        cout << "You have selected a vampire." << endl;
        cout << "Vampires are charming, but vicious and resilient. " << endl;
        cout << "They are hard to attack because of their persuasive nature. " << endl;
        //create character instance
        Character* outPtr = new Vampire("Vampire",1,12,6,18);//base pointer to dynamic derived pointer
        return outPtr;
    }
    
}
