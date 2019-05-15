/***********************************************
 ** Author: carrie davis
 ** Date:July 17, 2018
 ** Description: Project 2 ; ZooTycoon Class
 ************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <random>
#include <limits>
#include <unistd.h>
#include <algorithm>
#include <tgmath.h>
using namespace std;

#include "ZooTycoon.hpp"


/*****************************************************
 * ZooTycoon::ZooTycoon
 * constructs animal array and data members
 *****************************************************/
ZooTycoon::ZooTycoon()
{
    bankTotal = 100000;
    //numberOfAnimals = 0;
    tigerAmount = 0;
    turtleAmount = 0;
    penguinAmount = 0;
    newAnimalAmount = 0;
    tigerIndexSize = 10;
    turtleIndexSize = 10;
    penguinIndexSize = 10;
    newAnimalIndexSize = 10;
    
}

/*****************************************************
 * ZooTycoon::play
 * controls game play
 *****************************************************/
void ZooTycoon::play()
{
    //start Zoo by adding animals
    startZoo();
    double startChoice;  //start game play
    cout << "\n Your zoo is set up. \n" <<endl;
    cout << "Let's open the doors to the public for our first day!" <<endl;
    cout << "1. Start 1st Day" << endl;
    cout << "2. Exit Game" << endl;
    cout << "Enter your choice: ";
    cin >> startChoice;
    startChoice = static_cast<int>(startChoice);
    
    while (startChoice < 1 || startChoice > 2)
    {
        cout <<"Invalid input. Please enter 1 to start 1st day or 2 to quit. " <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your choice: ";
        cin >> startChoice;
    }
    if (startChoice == 2)
        {
           
            //free memory**/
            //free memory**/
 
            delete [] turtleArray;
            delete [] tigerArray;
            delete [] penguinArray;
            delete [] newAnimalArray;
            newAnimalArray = nullptr;
            penguinArray = nullptr;
            tigerArray = nullptr;
            turtleArray = nullptr;
            exit(0);
        }
        
    if (startChoice == 1)
    {
        int choice;
        int animalChoice;
        int days =1;
        int animalTypeChoice;
        do{
            cout << "\n Day " << days << " Report" <<endl;
            day();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << " You just survived a day of running a zoo!" << endl;
            cout << "\n You have $" << bankTotal << " in the bank. " <<endl;
            cout << "Would you like to purchase another animal? " <<endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "Enter your choice: ";
            cin >> animalChoice;
            
            /********************************************************
             error check
             *********************************************************/
            
            while (animalChoice < 1 || animalChoice > 2)
            {
                cout <<"Invalid input. Please enter 1 to buy animal or 2 to quit. " <<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "Enter your choice: ";
                cin >> animalChoice;
            }
            if(animalChoice == 1)
            {
                cout << "Would you like to purchase? " <<endl;
                cout << "1. Penguin" << endl;
                cout << "2. Tiger" << endl;
                cout << "3. Turtle" << endl;
                cout << "4. Other" << endl;
                cout << "Enter your choice: ";
                cin >> animalTypeChoice;
                
                //error check
                while (animalTypeChoice < 1 || animalTypeChoice > 4)
                {
                    cout <<"Invalid input. " <<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    cout << "Would you like to purchase? " <<endl;
                    cout << "1. Penguin" << endl;
                    cout << "2. Tiger" << endl;
                    cout << "3. Turtle" << endl;
                    cout << "4. Other" << endl;
                    cout << "Enter your choice: ";
                    cin >> animalTypeChoice;
                }
                
                if(animalTypeChoice == 1)
                    {buyAnimal(PENGUIN);}
                
                else if(animalTypeChoice == 2)
                        {buyAnimal(TIGER);}
                
                else if(animalTypeChoice == 3)
                    {buyAnimal(TURTLE);}
                
                else if(animalTypeChoice == 4)
                    {buyAnimal(OTHER);}
            }
            
            //clear cin
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            
            cout << "Do you want to play another day? " <<endl;
            days++;
            cout << "1. Play Another Day" << endl;
            cout << "2. Exit Game" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            choice = static_cast<int>(choice);
    
            /********************************************************
             error check
             *********************************************************/
    
            while (choice < 1 || choice > 2)
            {
                cout <<"Invalid input. Please enter 1 to start program or 2 to quit. " <<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "Enter your choice: ";
                cin >> choice;
            }
        }while((choice == 1) && (bankTotal > 0)); // play another week again if choice is 1.
    }
    
}
/*****************************************************
 * ZooTycoon::day
 * controls a day events
 *****************************************************/
void ZooTycoon::day()
{
    int otherProfit = 0;
    int penguinProfit = 0;
    int tigerProfit = 0;
    int turtleProfit = 0;
    
    // age update, payoff and feed costs of animals
    turtleProfit = updateTurtleDaily(turtleArray,turtleAmount);
    tigerProfit = updateTigerDaily(tigerArray,tigerAmount);
    penguinProfit = updatePenguinDaily(penguinArray, penguinAmount);
    otherProfit = updateOtherDaily(newAnimalArray, newAnimalAmount);
    
    cout << "" <<endl;
    cout << "\n Total Daily Profit: $" << turtleProfit + penguinProfit + tigerProfit + otherProfit <<endl;
    cout << "" <<endl;
    
    //calls random sickness, bonus, etc
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    
    
    int maxSeed = 4;
    int minSeed = 1;
    
    // choose other animal if doesn't exist
    if (newAnimalAmount == 0) {maxSeed = 3;}
    if(tigerAmount == 0){minSeed=2;}
    if(turtleAmount == 0) {maxSeed = 2;}
    
    
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    int randomValue = dist(gen);
    if(penguinIndexSize == 0)
    {
        default_random_engine generator;
        discrete_distribution<int> list {1,3};
        randomValue = list(generator);
    }
    
    switch (randomValue)
    {
        case 1: randomTiger(tigerArray,tigerAmount, tigerIndexSize);
            break;
            
        case 2:  randomPenguin(penguinArray,penguinAmount,penguinIndexSize);
            break;
            
        case 3: randomTurtle(turtleArray,turtleAmount, turtleIndexSize);
            break;
        case 4:
            randomNewAnimal(newAnimalArray,newAnimalAmount, newAnimalIndexSize);
            break;
    }
}


/*****************************************************
 * ZooTycoon::startZoo
 * initalizes the zoo
 *****************************************************/
void ZooTycoon::startZoo()
{
    // menu
    
    cout << "\n To have a zoo you need some animals.\n\n";
    cout << "Your bank has $ " <<bankTotal << " for you to spend." <<endl;
    cout <<  "Let's start with 3 of the most popular animals."<<endl;
    cout << "\n Tigers, penguins and turtles! \n";
    cout << "You may purchase 1 or 2 of each to start out. " <<endl;
    cout << "How many Tigers would you like to buy?"<<endl;
    cout << "Enter your choice: ";
    cin >> tigerAmount;
  
    /********************************************************
     error check
     *********************************************************/
    
    while (tigerAmount < 1 || tigerAmount > 2)
    {
        cout <<"Invalid input. Please enter 1 or 2. " <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your choice: ";
        cin >> tigerAmount;
    }
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout << "How many Penguins would you like to buy?"<<endl;
    cout << "Enter your choice: ";
    cin >> penguinAmount;
 
    
    /********************************************************
     error check
     *********************************************************/
    
    while (penguinAmount < 1 || penguinAmount > 2)
    {
        cout <<"Invalid input. Please enter 1 or 2. " <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your choice: ";
        cin >> penguinAmount;
      
    }
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    cout << "How many Turtles would you like to buy?"<<endl;
    cout << "Enter your choice: ";
    cin >> turtleAmount;
    
    
    /********************************************************
     error check
     *********************************************************/
    
    while (turtleAmount < 1 || turtleAmount > 2)
    {
        cout <<"Invalid input. Please enter 1 or 2 . " <<endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        cout << "Enter your choice: ";
        cin >> turtleAmount;
      
    }
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    
    tigerArray = new Tiger*[tigerIndexSize];
    turtleArray = new Turtle*[turtleIndexSize];
    penguinArray = new Penguin*[penguinIndexSize];
    newAnimalArray = new newAnimal*[newAnimalIndexSize];
    
    //need to set to null to initalize or get garbage values
    //setNULL(turtleArray,turtleIndexSize);
    //setNULL(tigerArray, tigerIndexSize);
    //setNULL(penguinArray,penguinIndexSize);
    //setNULL(newAnimalArray,newAnimalIndexSize);
   
    for (int tiger = 0; tiger < tigerAmount; tiger++)
    {
        bankTotal -= 10000;
        tigerArray[tiger] = createTiger();
        cout << "Tiger Cost: $10000. " <<endl;
        cout << "Bank balance: $" << bankTotal <<endl;
    }
    for (int penguin = 0; penguin < penguinAmount; penguin++)
    {
        bankTotal -= 1000;
        penguinArray[penguin] = createPenguin();
        cout << "Penguin Cost: $1000. " <<endl;
        cout << "Bank balance: $" << bankTotal <<endl;
    }
    for (int turtle = 0; turtle < turtleAmount; turtle++)
    {
        bankTotal -= 100;
        turtleArray[turtle] = createTurtle();
        cout << "Turtle Cost: $100. " <<endl;
        cout << "Bank balance: $" << bankTotal <<endl;
    }
}

/*****************************************************
 * ZooTycoon::buyAnimal
 * buys new animal
 *****************************************************/
void ZooTycoon::buyAnimal(TYPE inType)
{
    if(inType == TIGER)
    {
        tigerArray = addTiger(tigerArray,tigerAmount,tigerIndexSize);
        Tiger* tigerAnimal = createTiger();
        tigerArray[tigerAmount-1] = tigerAnimal;
        tigerAnimal->setAge(3);
        
        bankTotal -= 10000;
        cout << "Tiger Cost: $10000. " <<endl;
        cout << "Bank balance: $" << bankTotal <<endl;
    }
    else if(inType == TURTLE)
    {
        turtleArray = addTurtle(turtleArray,turtleAmount,turtleIndexSize);
        Turtle* turtleAnimal = createTurtle();
        turtleArray[turtleAmount-1] = turtleAnimal;
        turtleAnimal->setAge(3);
        bankTotal -= 100;
        cout << "Turtle Cost: $100. " <<endl;
        cout << "Bank balance: $" << bankTotal <<endl;
    }
    else if(inType == PENGUIN)
    {
        penguinArray = addPenguin(penguinArray,penguinAmount,penguinIndexSize);
        Penguin* penguinAnimal = createPenguin();
        penguinArray[penguinAmount-1] = penguinAnimal;
        penguinAnimal->setAge(3);
        bankTotal -= 1000;
        cout << "Penguin Cost: $1000. " <<endl;
        cout << "Bank balance: $" << bankTotal <<endl;
    }
    else if(inType == OTHER)
    {
        string animalName;
        int costInput;
        int foodCostInput;
        int payOffInput;
        int babyInput;
        int choice;
       
        do{
            cout << "What type of Animal would you like to purchase?"<<endl;
            cout << "Enter name of animal. Bear for example" <<endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            getline(cin,animalName);
            cout << "Are you sure you want to purchase a " << animalName <<"?"<<endl;
        
            cout << "1. Yes" << endl;
            cout << "2. Enter Different Animal" << endl;
            cout << "3. Exit Animal Purchase" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
        
            /********************************************************
             error check
             *********************************************************/
        
            while (choice != 1 && choice != 2 && choice !=3)
            {
                cout <<"Invalid Entry " <<endl;
                cout << "1. Yes" << endl;
                cout << "2. Enter Different Animal" << endl;
                cout << "3. Exit Animal Purchase" << endl;
                cout << "Enter your choice: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "Enter your choice: ";
                cin >> choice;
            }
        }while(choice==2); // repeat so correct animal type can be entered
        
        if(choice == 1)
            
        {
            newAnimalArray = addnewAnimal(newAnimalArray,newAnimalAmount,newAnimalIndexSize);
            newAnimal* NewAnimal = createNewAnimal();
            newAnimalArray[newAnimalAmount-1] = NewAnimal;
            NewAnimal->setStringOther(animalName);
        
            //clear out input stream if error
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
            cout << "Set Cost for " << animalName<<" in US Dollars. " <<endl;
            cout << "Enter Cost: ";
            cin >> costInput;
            
            //error check
            while (costInput < 1 || costInput > bankTotal)
            {
                cout <<"Please enter a number between 1 and your Bank Total. " << endl;
                cout << "Your Bank Total: " << bankTotal <<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "Enter your choice: ";
                cin >> costInput;
            }
        
            NewAnimal->setCost(costInput);
            NewAnimal->setAge(3);
        
            bankTotal -= costInput;
        
            cout << inType <<" Cost: $" <<NewAnimal->getCost() <<endl;
            cout << "Bank balance: $" << bankTotal <<endl;
        
            //clear out input stream if error
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
            cout << "Set number of babies it can have. " <<endl;
            cout << "Enter Baby(s): ";
            cin >> babyInput;
        
        
            //If Error
        
            while (babyInput < 1 || babyInput > 101)
            {
                cout <<"Please enter a number between 1 - 100 . " <<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "Enter your choice: ";
                cin >> babyInput;
            }
            NewAnimal->setBabies(babyInput);
        
            //clear out input stream if error
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
            cout << "Set daily food cost in US dollars: " <<endl;
            cout << "Enter Food Cost: ";
            cin >> foodCostInput;
        
        
            //If Error
        
            while (foodCostInput < 1 || foodCostInput > 1001)
            {
                cout <<"Please enter a number between 1 - 1000 . " <<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "Enter your choice: ";
                cin >> foodCostInput;
            }
        
            NewAnimal->setFoodCost(foodCostInput);
        
            //clear out input stream if error
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        
            cout << "Set daily pay off in US dollars. " <<endl;
            cout << "Enter Pay Off: ";
            cin >> payOffInput;
        
            //If Error
        
            while (payOffInput < 1 || payOffInput > 5000)
            {
                cout <<"Please enter a number between 1 - 5000 . " <<endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                cout << "Enter your choice: ";
                cin >> payOffInput;
            }
            NewAnimal->setPayOff(payOffInput);
        }
    }
}

/*****************************************************
 * ZooTycoon::createTiger
 * adds tiger to zoo
 *****************************************************/
Tiger* ZooTycoon::createTiger()
{
    //updates array to add new animal
    //used example from here to forumulate https://www.cs.fsu.edu/~myers/c++/notes/dma.html
    Tiger* createdAnimal;
    
    createdAnimal = new Tiger(1,1,50,2000);
  
    return createdAnimal;
}
/*****************************************************
 * ZooTycoon::createPenguin
 * adds penguin to zoo
 *****************************************************/
Penguin* ZooTycoon::createPenguin()
{
    //updates array to add new animal
    //used example from here to forumulate https://www.cs.fsu.edu/~myers/c++/notes/dma.html
    Penguin* createdAnimal;
    
    createdAnimal = new Penguin(1,5,10,100);
   
    return createdAnimal;
}

/*****************************************************
 * ZooTycoon::createTurtle
 * adds turtle to zoo
 *****************************************************/
Turtle* ZooTycoon::createTurtle()
{
    //updates array to add new animal
    //used example from here to forumulate https://www.cs.fsu.edu/~myers/c++/notes/dma.html
    Turtle* createdAnimal;
    createdAnimal = new Turtle(1,10,5,5);
    
    return createdAnimal;
}

/*****************************************************
 * ZooTycoon::createNewAnimal
 * adds animal to zoo
 *****************************************************/
newAnimal* ZooTycoon::createNewAnimal()
{
    //updates array to add new animal
    //used example from here to forumulate https://www.cs.fsu.edu/~myers/c++/notes/dma.html
    newAnimal* createdAnimal;
    createdAnimal = new newAnimal(1,0,0,0);
 
    return createdAnimal;
}

/*****************************************************
 * ZooTycoon::randomNewAnimal
 * randomizes the animal choice once array is picked
 *****************************************************/
void ZooTycoon::randomNewAnimal(newAnimal** animalArray, int &numberOfAnimals, int &inIndexSize)
{
    //calls random sickness, bonus, etc
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    int maxSeed = 3;
    int minSeed = 1;
    int parentAge=0;
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    int randomValue = dist(gen);
    switch (randomValue)
    {
        case 1: cout << "Oh no sick animal. " <<endl;
            sicknewAnimal(animalArray,numberOfAnimals,inIndexSize);
            break;
            
        case 2:cout << "What a great, relaxing day at the zoo!" <<endl;
            break;
            
            
        case 3: for(int animal = 0; animal < numberOfAnimals; animal++)
        {
            if (animalArray[animal]->getAge() >= 3)
            {parentAge++;}
        }
            if(parentAge > 0)
            {newAnimalBorn(animalArray,numberOfAnimals,inIndexSize);}
            break;
            
    }
}

/*****************************************************
 * ZooTycoon::randomPenguin
 * randomizes the animal choice once array is picked
 *****************************************************/
void ZooTycoon::randomPenguin(Penguin** animalArray, int &numberOfAnimals, int &inIndexSize)
{
    //calls random sickness, bonus, etc
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    int maxSeed = 3;
    int minSeed = 1;
    int parentAge=0;
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    int randomValue = dist(gen);
    switch (randomValue)
    {
        case 1: cout << "Oh no sick animal. " <<endl;
            sickPenguin(animalArray,numberOfAnimals,inIndexSize);
            break;
            
        case 2:cout << "What a great, relaxing day at the zoo!" <<endl;
            break;
            
            
        case 3: for(int animal = 0; animal < numberOfAnimals; animal++)
        {
            if (animalArray[animal]->getAge() >= 3)
            {parentAge++;}
        }
            if(parentAge > 0)
            {penguinBorn(animalArray,numberOfAnimals,inIndexSize);}
            break;
            
    }
}
/*****************************************************
 * ZooTycoon::randomTurtle
 * randomizes the animal choice once array is picked
 *****************************************************/
void ZooTycoon::randomTurtle(Turtle** animalArray, int &numberOfAnimals, int &inIndexSize)
{
    //calls random sickness, bonus, etc
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    int maxSeed = 3;
    int minSeed = 1;
    int parentAge=0;
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    int randomValue = dist(gen);
    switch (randomValue)
    {
        case 1: cout << "Oh no sick animal. " <<endl;
            sickTurtle(animalArray,numberOfAnimals,inIndexSize);
            break;
            
        case 2:cout << "What a great, relaxing day at the zoo!" <<endl;
            break;
           
            
        case 3: for(int animal = 0; animal < numberOfAnimals; animal++)
                {
                if (animalArray[animal]->getAge() >= 3)
                    {parentAge++;}
                }
                if(parentAge > 0)
                {turtleBorn(animalArray,numberOfAnimals,inIndexSize);}
            break;
            
    }
}
/*****************************************************
 * ZooTycoon::randomTiger
 * randomizes the animal choice
 *****************************************************/
void ZooTycoon::randomTiger(Tiger** animalArray, int &numberOfAnimals, int &inIndexSize)
{
    //calls random sickness, bonus, etc
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    int maxSeed = 4;
    int minSeed = 1;
    int parentAge=0;
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    int randomValue = dist(gen);
    switch (randomValue)
    {
        case 1: cout << "Oh no sick animal. " <<endl;
            sickTiger(animalArray,numberOfAnimals,inIndexSize);
            break;
            
        case 2:bonus();

            break;
            
        case 3: for(int animal = 0; animal < numberOfAnimals; animal++)
        {   if (animalArray[animal]->getAge() >= 3)
        {parentAge++;}
        }
            if(parentAge > 0)
            {tigerBorn(animalArray,numberOfAnimals,inIndexSize);}
            break;
            
        case 4: cout << "What a great, relaxing day at the zoo!" <<endl;
            break;
    }
}


/*****************************************************
 * ZooTycoon::updateOtherDaily
 * updates daily events
 *****************************************************/
int ZooTycoon::updateOtherDaily(newAnimal** animalArray, int numberOfAnimals)
{
    int totalFoodCost = 0;
    int totalProfit = 0;
    string animalType;
    for(int animal = 0 ; animal < numberOfAnimals; animal ++ )
        
    {
        if(animalArray[animal]!=NULL)
        {
            int previousAge = animalArray[animal]->getAge();
            animalArray[animal]->setAge(previousAge + 1);
            int dayPayoff = animalArray[animal]->getPayOff();
            bankTotal += dayPayoff;
            totalProfit +=dayPayoff;
            int dayFoodCost = animalArray[animal]->getFoodCost();
            bankTotal -= dayFoodCost;
            totalProfit -= dayFoodCost;
            
            totalFoodCost +=dayFoodCost;
        }
        
    }
    
    
    if (numberOfAnimals > 0)
        
    {
        cout <<"-------------------"<<endl;
        cout <<numberOfAnimals <<" Other(s):"  << endl;
        cout << "Daily Cost: $" << totalFoodCost <<endl;
        cout << "Profit: $" << totalProfit << endl;
    }
    return totalProfit;
}
/*****************************************************
 * ZooTycoon::updatePenguinDaily
 * updates daily events
 *****************************************************/
int ZooTycoon::updatePenguinDaily(Penguin** animalArray, int numberOfAnimals)
{
    int totalFoodCost = 0;
    int totalProfit = 0;
    string animalType;
    for(int animal = 0 ; animal < numberOfAnimals; animal ++ )
        
    {
        if(animalArray[animal]!=NULL)
        {
            int previousAge = animalArray[animal]->getAge();
            animalArray[animal]->setAge(previousAge + 1);
            int dayPayoff = animalArray[animal]->getPayOff();
            bankTotal += dayPayoff;
            totalProfit +=dayPayoff;
            int dayFoodCost = animalArray[animal]->getFoodCost();
            bankTotal -= dayFoodCost;
            totalProfit -= dayFoodCost;
            
            totalFoodCost +=dayFoodCost;
        }
        
    }
    
    
    if (numberOfAnimals > 0)
        
    {
        cout <<"-------------------"<<endl;
        cout <<numberOfAnimals <<" Penguin(s):"  << endl;
        cout << "Daily Cost: $" << totalFoodCost <<endl;
        cout << "Profit: $" << totalProfit << endl;
    }
    return totalProfit;
}
/*****************************************************
 * ZooTycoon::updateTurtleDaily
 * updates daily events
 *****************************************************/
int ZooTycoon::updateTurtleDaily(Turtle** animalArray, int numberOfAnimals)
{
    int totalFoodCost = 0;
    int totalProfit = 0;
    string animalType;
    for(int animal = 0 ; animal < numberOfAnimals; animal ++ )
        
    {
        if(animalArray[animal]!=NULL)
        {
            int previousAge = animalArray[animal]->getAge();
            animalArray[animal]->setAge(previousAge + 1);
            int dayPayoff = animalArray[animal]->getPayOff();
            bankTotal += dayPayoff;
            totalProfit +=dayPayoff;
            int dayFoodCost = animalArray[animal]->getFoodCost();
            bankTotal -= dayFoodCost;
            totalProfit -= dayFoodCost;
            
            totalFoodCost +=dayFoodCost;
        }
        
    }
    
    
    if (numberOfAnimals > 0)
        
    {
        cout <<"-------------------"<<endl;
        cout <<numberOfAnimals <<" Turtles(s):"  << endl;
        cout << "Daily Cost: $" << totalFoodCost <<endl;
        cout << "Profit: $" << totalProfit << endl;
    }
    return totalProfit;
}
/*****************************************************
 * ZooTycoon::updateTigerDaily
 * updates daily events
 *****************************************************/
int ZooTycoon::updateTigerDaily(Tiger** animalArray, int numberOfAnimals)
{
    int totalFoodCost = 0;
    int totalProfit = 0;
    string animalType;
    for(int animal = 0 ; animal < numberOfAnimals; animal ++ )
        
    {
        if(animalArray[animal]!=NULL)
        {
            int previousAge = animalArray[animal]->getAge();
            animalArray[animal]->setAge(previousAge + 1);
            int dayPayoff = animalArray[animal]->getPayOff();
            bankTotal += dayPayoff;
            totalProfit +=dayPayoff;
            int dayFoodCost = animalArray[animal]->getFoodCost();
            bankTotal -= dayFoodCost;
            totalProfit -= dayFoodCost;
            
            totalFoodCost +=dayFoodCost;
        }
        
    }
    
    
    if (numberOfAnimals > 0)
        
    {
        cout <<"-------------------"<<endl;
        cout <<numberOfAnimals <<" Tiger(s):"  << endl;
        cout << "Daily Cost: $" << totalFoodCost <<endl;
        cout << "Profit: $" << totalProfit << endl;
    }
    return totalProfit;
}


/*****************************************************
 * ZooTycoon::sickness
 * controls a day events
 *****************************************************/
void ZooTycoon::sickPenguin(Penguin** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    if (numberOfAnimals >0)
    {numberOfAnimals = numberOfAnimals - 1;
        cout << "A penguin has just died. " <<endl;
        animalArray[numberOfAnimals] = NULL;
    }
    else{ cout << "There are no penguins left to die" <<endl;}
}

/*****************************************************
 * ZooTycoon::sickNewAnimal
 * penguin removed
 *****************************************************/
void ZooTycoon::sicknewAnimal(newAnimal** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    if (numberOfAnimals >0)
    {numberOfAnimals = numberOfAnimals - 1;
        cout << "A " << animalArray[numberOfAnimals]->getStringOther() << " has just died. " <<endl;
        animalArray[numberOfAnimals] = NULL;
    }
    else{ cout << "There are no animals left to die" <<endl;}
}

/*****************************************************
 * ZooTycoon::sickTiger
 * tiger removed
 *****************************************************/
void ZooTycoon::sickTiger(Tiger** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    if (numberOfAnimals >0)
    {numberOfAnimals = numberOfAnimals - 1;
        cout << "A tiger has just died. " <<endl;
        animalArray[numberOfAnimals] = NULL;
    }
    else{ cout << "There are no tigers left to die" <<endl;}
}

/*****************************************************
 * ZooTycoon::sickTurtle
 * turtle removed
 *****************************************************/
void ZooTycoon::sickTurtle(Turtle** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    if (numberOfAnimals >0)
    {numberOfAnimals = numberOfAnimals - 1;
        cout << "A turtle has just died. " <<endl;
        animalArray[numberOfAnimals] = NULL;
    }
    else{ cout << "There are no turtles left to die" <<endl;}
}


/*****************************************************
 * ZooTycoon::bonus
 * Tiger bonus occurs
 *****************************************************/
void ZooTycoon::bonus()
{
    int bonusMoney;
    random_device rd; //seed
    mt19937 gen(rd()); // standard mersenne_twister engine
    //seed value initalization and randomization
    int maxSeed = 500;
    int minSeed = 250;
    
    uniform_int_distribution<int> dist(minSeed,maxSeed);
    bonusMoney = dist(gen);
    
    bankTotal += bonusMoney;
    //Generate a random bonus for the day, 250-500 dollars for each tiger in the zoo
   // Add the bonus payoff for each tiger to the total payoff of the day as a reward
    cout << "This is National Tiger Day! Tigers generate money today!"<<endl;
    cout << "You made: $" << bonusMoney << endl;
}

/*****************************************************
 * ZooTycoon::tigerBorn
 * baby is born
 *****************************************************/
void ZooTycoon::tigerBorn(Tiger** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    
    string animalName;
    int numberOfBabies = animalArray[0]->getBabies();
    
    
    for(int baby=0; baby < numberOfBabies; baby++)
    {
        
            tigerArray = addTiger(tigerArray,tigerAmount,tigerIndexSize);
            Tiger* babyAnimal = createTiger();
            tigerArray[tigerAmount-1] = babyAnimal;
            babyAnimal->setAge(0);
      
        cout << "\n A Tiger gave birth to a baby!"<<endl;
    }
}
/*****************************************************
 * ZooTycoon::turtleBorn
 * baby is born
 *****************************************************/
void ZooTycoon::turtleBorn(Turtle** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    
    string animalName;
    int numberOfBabies = animalArray[0]->getBabies();
    
    
    for(int baby=0; baby < numberOfBabies; baby++)
    {
            turtleArray = addTurtle(turtleArray,turtleAmount,turtleIndexSize);
            Turtle* babyAnimal = createTurtle();
            turtleArray[turtleAmount-1] = babyAnimal;
            babyAnimal->setAge(0);
      
        cout << "\n A Turle gave birth to a baby!"<<endl;
    }
}

/*****************************************************
 * ZooTycoon::penguinBorn
 * baby is born
 *****************************************************/
void ZooTycoon::penguinBorn(Penguin** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    
    string animalName;
    int numberOfBabies = animalArray[0]->getBabies();
    
    for(int baby=0; baby < numberOfBabies; baby++)
    {
        
       
            penguinArray = addPenguin(penguinArray,penguinAmount,penguinIndexSize);
            Penguin* babyAnimal = createPenguin();
            penguinArray[penguinAmount-1] = babyAnimal;
            babyAnimal->setAge(0);
      
        cout << "\n A penguin gave birth to a baby!"<<endl;
    }
}
/*****************************************************
 * ZooTycoon::newAnimalBorn
 * baby is born
 *****************************************************/
void ZooTycoon::newAnimalBorn(newAnimal** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    
    string animalName;
    int numberOfBabies = animalArray[0]->getBabies();
    
    
    for(int baby=0; baby < numberOfBabies; baby++)
    {
        
            newAnimalArray = addnewAnimal(newAnimalArray,newAnimalAmount,newAnimalIndexSize);
            newAnimal* babyAnimal = createNewAnimal();
            newAnimalArray[newAnimalAmount-1] = babyAnimal;
            babyAnimal->setAge(0);
            int cost = newAnimalArray[0]->getCost();
            int foodCost = newAnimalArray[0]->getFoodCost();
            int payOff = newAnimalArray[0]->getPayOff();
            string name = newAnimalArray[0]->getStringOther();
            babyAnimal->setCost(cost);
            babyAnimal->setBabies(numberOfBabies);
            babyAnimal->setPayOff(payOff);
            babyAnimal->setFoodCost(foodCost);
            babyAnimal->setStringOther(name);
            cout << "\n A " << name << " gave birth to a baby!"<<endl;
  
        cout << "\n A " << animalArray[0]->getStringOther() << " gave birth to a baby!"<<endl;
    }
}
/*****************************************************
 * ZooTycoon::addTurtle
 * add animal to array resizing array
 *****************************************************/
Turtle** ZooTycoon::addTurtle(Turtle** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    if(numberOfAnimals >= inputIndexSize)
    {
        inputIndexSize = inputIndexSize + 10;
        
        Turtle** temp = new Turtle*[inputIndexSize];
        //setNULL(temp,inputIndexSize);
        int  tempSubscript = 0;
        for (int animal = 0; animal < numberOfAnimals; animal++)
        {
            if(animalArray[animal]!=NULL)
            {
                temp[tempSubscript] = animalArray[animal];
                tempSubscript++;
            }
        }
        delete [] animalArray;
        animalArray = NULL;
        animalArray = temp;
        delete [] temp;
        temp = NULL;
    }
    numberOfAnimals = numberOfAnimals + 1;
    return animalArray;
}
/*****************************************************
 * ZooTycoon::addPenguin
 * add animal to array resizing array
 *****************************************************/
Penguin** ZooTycoon::addPenguin(Penguin** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    if(numberOfAnimals >= inputIndexSize)
    {
        inputIndexSize = inputIndexSize + 10;
        
        Penguin** temp = new Penguin*[inputIndexSize];
        //setNULL(temp,inputIndexSize);
        int  tempSubscript = 0;
        for (int animal = 0; animal < numberOfAnimals; animal++)
        {
            if(animalArray[animal]!=NULL)
            {
                temp[tempSubscript] = animalArray[animal];
                tempSubscript++;
            }
        }
        delete [] animalArray;
        animalArray = NULL;
        animalArray = temp;
        delete [] temp;
        temp = NULL;
        
    }
    numberOfAnimals = numberOfAnimals + 1;
    return animalArray;
}
/*****************************************************
 * ZooTycoon::addTiger
 * add animal to array resizing array
 *****************************************************/
Tiger** ZooTycoon::addTiger(Tiger** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    if(numberOfAnimals >= inputIndexSize)
    {
        inputIndexSize = inputIndexSize + 10;
        
        Tiger** temp = new Tiger*[inputIndexSize];
        //setNULL(temp,inputIndexSize);
        int  tempSubscript = 0;
        for (int animal = 0; animal < numberOfAnimals; animal++)
        {
            if(animalArray[animal]!=NULL)
            {
                temp[tempSubscript] = animalArray[animal];
                tempSubscript++;
            }
        }
        delete [] animalArray;
        animalArray = NULL;
        animalArray = temp;
        delete [] temp;
        temp = NULL;
     
    }
    numberOfAnimals = numberOfAnimals + 1;
    return animalArray;
}
/*****************************************************
 * ZooTycoon::addnewAninal
 * add animal to array resizing array
 *****************************************************/
newAnimal** ZooTycoon::addnewAnimal(newAnimal** animalArray, int &numberOfAnimals, int &inputIndexSize)
{
    if(numberOfAnimals >= inputIndexSize)
    {
        inputIndexSize = inputIndexSize + 10;
        
        newAnimal** temp = new newAnimal*[inputIndexSize];
        //setNULL(temp,inputIndexSize);
        int  tempSubscript = 0;
        for (int animal = 0; animal < numberOfAnimals; animal++)
        {
            if(animalArray[animal]!=NULL)
            {
                temp[tempSubscript] = animalArray[animal];
                tempSubscript++;
            }
        }
        delete [] animalArray;
        animalArray = NULL;
        animalArray = temp;
        delete [] temp;
        temp = NULL;
        
    }
    numberOfAnimals = numberOfAnimals + 1;
    return animalArray;
}

