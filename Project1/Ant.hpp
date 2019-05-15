//
//  Ant.hpp
//  
//
//  Created by Carrie Davis on 7/1/18.
//

#ifndef Ant_hpp
#define Ant_hpp

class Ant
{
private://only accessable in the class
    int row;
    int column;
    char orientation;
public: //member function prototypes
    Ant();//Default constructor
    //constructor with parameters
    Ant(int, int, char);
    int getRow();
    int getColumn();
    char getOrientation();
    void setOrientation(char);
    void setRow(int);
    void setColumn(int);
};

#endif /* Ant_hpp */
