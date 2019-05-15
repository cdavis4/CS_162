//
//  Game.hpp
//  
//
//  Created by Carrie Davis on 7/11/18.
//

#ifndef Game_hpp
#define Game_hpp
#include "Die.hpp"
#include "LoadedDie.hpp"

enum TYPE{REGULAR, LOADED}; // type of the die that determines how it rolls

class Game{
    
private: //only accessable to the Game class
   
    int rounds;
    int inputType;
    void playRounds(Die*[], int); // used in play
   
    TYPE type; //die type
       int N;  // number of sides on the individual die
protected: //only accessable to Game class and children
  
    Die* createDie();//used in play to create instances of die to use
    
public: // function prototypes
      Die* newDie;
    Die* dice1,dice2;
    //initalize class
    Game();
    void play();

};

#endif /* Game_hpp */
