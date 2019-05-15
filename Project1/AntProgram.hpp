//  Created by Carrie Davis on 7/2/18.
//

#ifndef AntProgram_hpp
#define AntProgram_hpp
#include "Ant.hpp"
#include "AntBoard.hpp"

class AntProgram{

private:    //only accessable to the AntProgram
int placeAntChoice;
int matrixSize;
int row;
int column;
int steps;

public:   //function prototypes
//Initalizes the AntProgram
    AntProgram();
    void run();

};
#endif /* AntProgram_hpp */
