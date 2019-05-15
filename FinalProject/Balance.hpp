//
//  Balance.hpp
//  
//
//  Created by Carrie Davis on 8/14/18.
//

#ifndef Balance_hpp
#define Balance_hpp
#include "Space.hpp"
using namespace std;

class Balance: public Space
{
public:
    Balance();
    void complete(Runner&);
    string getName();
};

#endif /* Balance_hpp */
