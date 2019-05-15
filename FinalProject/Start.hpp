//
//  Start.hpp
//  
//
//  Created by Carrie Davis on 8/14/18.
//

#ifndef Start_hpp
#define Start_hpp
#include "Space.hpp"
using namespace std;

class Start: public Space
{
public:
    Start();
    void complete(Runner&);
    string getName();
};

#endif /* Start_hpp */
