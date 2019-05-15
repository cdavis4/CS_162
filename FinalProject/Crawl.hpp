//
//  Crawl.hpp
//  
//
//  Created by Carrie Davis on 8/14/18.
//

#ifndef Crawl_hpp
#define Crawl_hpp
#include "Space.hpp"
using namespace std;

class Crawl: public Space
{
public:
    Crawl();
    void complete(Runner&);
    string getName();
};
#endif /* Crawl_hpp */
