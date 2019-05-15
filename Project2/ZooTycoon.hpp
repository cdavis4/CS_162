//
//  ZooTycoon.hpp
//  
//
//  Created by Carrie Davis on 7/17/18.
//

#ifndef ZooTycoon_hpp
#define ZooTycoon_hpp

#include "Animal.hpp"
#include "Animal.hpp"
#include "Turtle.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "newAnimal.hpp"

using namespace std;

class ZooTycoon
{
private:  //only accessable to ZooTycoon Class
    int bankTotal;
    //int numberOfAnimals; // size of animal array
    int tigerIndexSize;
    int turtleIndexSize;
    int penguinIndexSize;
    int newAnimalIndexSize;
    int turtleAmount;
    int tigerAmount;
    int penguinAmount;
    int newAnimalAmount;
   
  
    Turtle** turtleArray;
    Tiger** tigerArray;
    Penguin** penguinArray;
    newAnimal** newAnimalArray;
     //void setNULL(Animal**, int); //initalizes value to NULL for arrays
    //int updateDaily(Animal**, int);
    int updateTurtleDaily(Turtle**, int);
    int updateTigerDaily(Tiger**, int);
    int updatePenguinDaily(Penguin**, int);
    int updateOtherDaily(newAnimal**, int);
    void randomTiger(Tiger** ,int&, int&);
    void randomPenguin(Penguin** ,int&, int&);
    void randomTurtle(Turtle** ,int&, int&);
    void randomNewAnimal(newAnimal** ,int&, int&);
    //void randomChoice(Animal** ,int&, int&);
    void buyAnimal(TYPE);
    //Animal** addAnimal(Animal**, int&, int&);//adds animal and recreates array
    Penguin** addPenguin(Penguin**, int&, int&);
    Tiger** addTiger(Tiger**, int&, int&);
    Turtle** addTurtle(Turtle**, int&, int&);
    newAnimal** addnewAnimal(newAnimal**, int&, int&);
  
protected:
    //Animal* createAnimal(TYPE); // used to create instances of animals
    Penguin* createPenguin();
    Tiger* createTiger();
    Turtle* createTurtle();
    newAnimal* createNewAnimal();
    void startZoo();  // animal instance pointer
    void day();
    //void sickness(Animal** , int&, int&);
    void sickPenguin(Penguin** , int&, int&);
    void sickTiger(Tiger** , int&, int&);
    void sicknewAnimal(newAnimal** , int&, int&);
    void sickTurtle(Turtle** , int&, int&);
    
    void bonus();
    //void babyBorn(Animal** , int&, int&);
    void penguinBorn(Penguin** , int&, int&);
    void tigerBorn(Tiger** , int&, int&);
    void turtleBorn(Turtle** , int&, int&);
    void newAnimalBorn(newAnimal** , int&, int&);
    //string getTypeString(Animal*);
    
public: //function prototypes open to all
    void play();
    ZooTycoon();

};




#endif /* ZooTycoon_hpp */
