//
//  CombatGame.hpp
//  
//
//  Created by Carrie Davis on 7/31/18.
//

#ifndef CombatGame_hpp
#define CombatGame_hpp
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Character.hpp"
using namespace std;

class CombatGame{
private:
    Character* player1;
    Character* player2;
    int rounds;
    Character* selectCharacter();
    void playRound();
public:
    void combat();
    CombatGame();
};

#endif /* CombatGame_hpp */
