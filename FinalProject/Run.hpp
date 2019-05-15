//
//  Run.hpp
//  
//
//  Created by Carrie Davis on 8/14/18.
//

#ifndef Run_hpp
#define Run_hpp
#include "Space.hpp"
using namespace std;

class Run: public Space
{
public:
    Run();
    void complete(Runner&);
    string getName();
};

#endif /* Run_hpp */
