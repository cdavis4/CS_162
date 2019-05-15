//
//  AntBoard.hpp
//  
//
//  Created by Carrie Davis on 7/1/18.
//

#ifndef AntBoard_hpp
#define AntBoard_hpp
#include <iostream>
#include "Ant.hpp"
using namespace std;

class AntBoard
{
  
private:
    bool **boardPtr; // Dynamically allocated 2D array
    int antRow,antColumn, boardSize;  //ant  array
    char antOrient; // ant orientation
    
public:
    AntBoard(); // Default constructor
    AntBoard(int); //Default constructor with parameters
    void placeAnt(Ant*);
    void moveAnt(Ant*);
    void createBoard();
    void deleteBoard();
    void print(Ant*);
};

#endif /* AntBoard_hpp */
