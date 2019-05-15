/********************************************************************
 ** Author: carrie davis
 ** Date:July 2, 2018
 ** Description: Project 1; AntBoard
 *********************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

//#include "Ant.hpp"
#include "AntBoard.hpp"
//Default Constructor initalizing the arrays and data members.
AntBoard::AntBoard()
{
    boardSize = 0;
}
/********************************************************************
 * AntBoard::AntBoard class
 * Initalizes the defaults for class data members
 *********************************************************************/
//Dynamically allocate an array large enough to hold values
AntBoard::AntBoard(int inSize)
{
    boardPtr = new bool*[inSize];
    for(int row=0; row < inSize; row++)
    {  boardPtr[row] = new bool[inSize];}
    boardSize = inSize;
    createBoard();
}
/********************************************************************
 * AntBoard::createBoard method
 * create board
 *********************************************************************/
//Dynamically allocate an array large enough to hold values
void AntBoard::createBoard()
{

    for (int row = 0; row < boardSize; row++){
        for (int column = 0; column < boardSize; column++)
        {boardPtr[row][column] = 0;}}
}
/********************************************************************
 * AntBoard::createBoard method
 * delete board
 *********************************************************************/
//Dynamically allocate an array large enough to hold values
void AntBoard::deleteBoard()
{
    //free memory
    for (int row = 0; row < boardSize; row++)
    {
        delete [] boardPtr[row];  // frees the columns of the matrix
    }
    delete [] boardPtr;
    boardPtr = nullptr;
}

/********************************************************************
 * AntBoard::placeAnt method
 * move ant on board
 *********************************************************************/
void AntBoard::placeAnt(Ant *inAnt)
{
     //pointer to an object to access methods
    antRow = (*inAnt).getRow();
    antColumn = (*inAnt).getColumn();
    boardPtr[antRow][antColumn] = 1;
}

/********************************************************************
 * AntBoard::moveAnt method
 * move ant on board
 *********************************************************************/
void AntBoard::moveAnt(Ant *inAnt)
{
    antOrient  = (*inAnt).getOrientation();
    antRow = (*inAnt).getRow();
    antColumn = (*inAnt).getColumn();
    
    if( antOrient == 'N')
    {
           
        int row = antRow - 1;
        int column = antColumn;
        
       if((row >= 0) && (boardPtr[row][column] == 0))
            {
                boardPtr[row][column] = 1;
                (*inAnt).setRow(row);
                (*inAnt).setColumn(column);
                (*inAnt).setOrientation('E');
            }
        else if((row >= 0)  && (boardPtr[row][column] == 1))
            {
            boardPtr[row][column] = 0;
            (*inAnt).setRow(row);
            (*inAnt).setColumn(column);
            (*inAnt).setOrientation('W');
            }
        
        else
            {
                cout << "Stopped and turned ant around to avoid going out of bounds." <<endl;
                (*inAnt).setOrientation('S');
            }
        }

    if( antOrient == 'E')
    {
        int row = antRow;
        int column = antColumn + 1;
        
        if((column < boardSize) && (boardPtr[row][column] == 0))
            {
            boardPtr[row][column] = 1;
            (*inAnt).setRow(row);
            (*inAnt).setColumn(column);
            (*inAnt).setOrientation('S');
            }
        else if((column < boardSize) && (boardPtr[row][column] == 1))
            {
            boardPtr[row][column] = 0;
            (*inAnt).setRow(row);
            (*inAnt).setColumn(column);
            (*inAnt).setOrientation('N');
            }
        else
            {
             cout << "Stopped and turned ant around to avoid going out of bounds." <<endl;
            (*inAnt).setOrientation('W');
            }
    }

    if( antOrient == 'W')
    {
        int row = antRow;
        int column = antColumn - 1;
        
        if((column >= 0) && (boardPtr[row][column] == 0))
            {
            boardPtr[row][column] = 1;
            (*inAnt).setRow(row);
            (*inAnt).setColumn(column);
            (*inAnt).setOrientation('N');
            }
        else if((column >= 0) && (boardPtr[row][column] == 1))
            {
            boardPtr[row][column] = 0;
            (*inAnt).setRow(row);
            (*inAnt).setColumn(column);
            (*inAnt).setOrientation('S');
            }
        else
            {
            cout << "Stopped and turned ant around to avoid going out of bounds." <<endl;
            (*inAnt).setOrientation('E');
            }
    }

    if( antOrient == 'S')
    {
        int row = antRow + 1;
        int column = antColumn;
        
        if((row < boardSize) && (boardPtr[row][column] == 0))
            {
            boardPtr[row][column] = 1;
            (*inAnt).setRow(row);
            (*inAnt).setColumn(column);
            (*inAnt).setOrientation('W');
            }
        else if((row < boardSize) && (boardPtr[row][column] == 1))
            {
            boardPtr[row][column] = 0;
            (*inAnt).setRow(row);
            (*inAnt).setColumn(column);
            (*inAnt).setOrientation('E');
            }
        else
        {
            cout << "Stopped and turned ant around to avoid going out of bounds." <<endl;
            (*inAnt).setOrientation('N');
        }
    }
  
}
/********************************************************************
 * AntBoard::print
 * prints board
 *********************************************************************/
void AntBoard::print(Ant *inAnt)
{
    // prints existing board
    antRow = (*inAnt).getRow();
    antColumn = (*inAnt).getColumn();
    
    for (int row = 0; row < boardSize; row++)
    {
        for(int column = 0; column < boardSize; column++)
        {
            if(column == antColumn && row == antRow)
                {
                cout<< setw(3) << "*"  <<"  ";
                }
            else if(boardPtr[row][column] == 0)
                {
                cout<< setw(3) << " " <<"  ";
                }
         
            else if(boardPtr[row][column] == 1)
                {
                cout<< setw(3) << "#" << "  ";
                }
        }
        cout << endl;
    }
}
