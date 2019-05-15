//
//  Die.hpp
//  
//
//  Created by Carrie Davis on 7/11/18.
//

#ifndef Die_hpp
#define Die_hpp


class Die{
private: //only accessable to the Die class
protected: //only accessable to class and children
    int rollResult; // random integer bt 1 and N as result of one roll
    int N;  // number of sides on the individual die
public:
    //initalize class
    Die();
    Die(int);
    int getSides();
    virtual int rollDie();
    
};

#endif /* Die_hpp */
