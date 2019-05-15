//
//  Climb.hpp
//  
//
//  Created by Carrie Davis on 8/14/18.
//

#ifndef Climb_hpp
#define Climb_hpp
#include "Space.hpp"
using namespace std;

class Climb: public Space
{
public:
    Climb();
    void complete(Runner&);
    string getName();
};

#endif /* Climb_hpp */
