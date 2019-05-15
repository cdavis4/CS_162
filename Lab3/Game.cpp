/********************************************
 ** Author: carrie davis
 ** Date:July 11, 2018
 ** Description: Lab 3; War Game
*********************************************/
#include <iostream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <string>

using namespace std;
#include "Game.hpp"

//Default Constructor
Game::Game()
{
    rounds = -1;
}


/********************************************
 * Game::playRounds
 * determines who wins for round
 *******************************************/
void Game::playRounds(Die * inputPtrArray[], int inputRounds)
{
    int player1Score = 0;
    int player2Score = 0;
    
    for (int round = 0; round < inputRounds; round++)
    {
        cout << "Round " << round + 1<< ": " <<endl;
        
        //Player 1 info and results
        cout << "Player 1: " <<endl ;
        int sides1 = inputPtrArray[0]->getSides();
        cout << sides1 << " Sides. ";
        int rollResult1 = inputPtrArray[0]->rollDie();
       
        cout << rollResult1 <<endl;
     
        //Player 2 info and results
        cout << "Player 2: " <<endl;
        int sides2 = inputPtrArray[1]->getSides();
        cout << sides2 << " Sides. ";
        int rollResult2 = inputPtrArray[1]->rollDie();
      
        cout << rollResult2 <<endl;
    
        //Update Score based on round results
        if(rollResult1 == rollResult2)
        {cout << "Tie and no one scores" <<endl;}
        else if (rollResult1 > rollResult2)
        { player1Score += 1;
            cout << "Player 1 scores a point!" <<endl;
        }
        else if (rollResult1 < rollResult2)
        { player2Score += 1;
            cout << "Player 2 scores a point!" <<endl;
        }
        
        cout << "Current Total Player 1: " <<player1Score <<endl;
        cout << "Current Total Player 2: " <<player2Score <<endl;
    }
    //Final tally
    if(player1Score > player2Score)
    {cout << "Player 1 wins with " << player1Score <<endl;}
    else if(player1Score < player2Score)
    {cout << "Player 2 wins with " << player2Score <<endl;}
    else if (player2Score == player1Score)
    { cout << "It's a tie! " <<endl; }
}

/********************************************
 * Game::createDie
 * creates player instance for die
 *******************************************/
Die* Game::createDie()
{
    int type;
    double inputType;
  

    cout <<  "Do you want a regular dice or a loaded dice? \n "<<endl;
    cout << "The loaded dice will improve your chances of rolling a higher number.\n" <<endl;
    cout << "1: For Regular Die. "<<endl;
    cout << "2: For Loaded Die. " <<endl;
    cout << "Enter choice: ";
    cin >> inputType;
    type = static_cast<int>(inputType);
   
    
    /****************************************
     error check
     ***************************************/
    while (type < 1|| type > 2)
    {
        cout <<"Invalid input. Enter 1 for regular or 2 for loaded." <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
         cout << "Enter choice: ";
        cin >> inputType;
        type = static_cast<int>(inputType);
    }
 
    cout <<  "How many sides? Pick between 4 - 120. "<<endl;
    cout <<  "Enter your choice: ";
    double inputN;
    cin >> inputN;
    N = static_cast<int>(inputN);
   
    
    while (N < 4 || N > 120)
    {
        cout <<"Invalid input. Please enter a number 4 - 120." <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your choice: ";
        cin >> inputN;
        N = static_cast<int>(inputN);
    }
    
    //define Dice as regular die
    if(type == 1)
        {
        newDie = new Die(N);
        }
    else if(type == 2)
        {
        newDie = new LoadedDie(N);
            
        }
    return newDie;
}
/********************************************
 * Game::play
 * play game menu
 *******************************************/
void Game::play()
{
    // menu
    cout << "Welcome to the War Game menu.\n" <<endl;
    cout << "Select how many rounds you want to play.\n Must be between 1 - 25." <<endl;
    cout <<  "Enter number of rounds: ";
    double inputRounds;
    cin >> inputRounds;
    rounds = static_cast<int>(inputRounds);
    
    /****************************************
     error check
     ***************************************/
    while (rounds < 1 || rounds > 25)
    {
        cout <<"Invalid input. Please enter a number between 1 and 25." <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter number of rounds: ";
        cin >> inputRounds;
        rounds = static_cast<int>(inputRounds);
    }
  
    Die *dice[2]; // initalize the dice
    
    int players = 2;    //Create players dice.
    cout << "Now let's define the players dice." <<endl;
    for (int player = 0; player < players; player++)
    {
        cout << "For player " << player + 1 << endl;
        dice[player] = createDie();
    }
    
    cout << "Finally Let's Play War" <<endl;
    playRounds(dice,rounds);

    //free memory**/
  
    for (int player = 0; player < players; player++)
    {
       dice[player]=nullptr;  // frees the columns of the matrix
    }
}
