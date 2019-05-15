//
//  Swim.hpp

//  Created by Carrie Davis on 8/14/18.
//

#ifndef Swim_hpp
#define Swim_hpp

#include "Space.hpp"
using namespace std;

class Swim: public Space
{
public:
    Swim();
    void complete(Runner&);
    string getName();
};

#endif /* Swim_hpp */
