//
//  End.hpp
//  
//
//  Created by Carrie Davis on 8/14/18.
//

#ifndef End_hpp
#define End_hpp

#include "Space.hpp"
using namespace std;

class End: public Space
{
public:
    End();
    void complete(Runner&);
    string getName();
};

#endif /* End_hpp */
