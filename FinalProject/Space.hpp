//
//  Space.hpp
//  Created by Carrie Davis on 8/7/18.
//

#ifndef Space_hpp
#define Space_hpp
#include <vector>
#include <memory>
#include "Runner.hpp"

class Space
{
public:
    // point to objects that will be set to null if not crossed by runner
    shared_ptr<Space> north; //these can be random spaces in vector
    shared_ptr<Space> south;
    shared_ptr<Space> east;
    shared_ptr<Space> west;
    shared_ptr<Space> getNorth(vector<vector<shared_ptr<Space>>>, int, int);
    shared_ptr<Space> getSouth(vector<vector<shared_ptr<Space>>>, int, int);
    shared_ptr<Space> getEast(vector<vector<shared_ptr<Space>>>, int, int);
    shared_ptr<Space> getWest(vector<vector<shared_ptr<Space>>>, int, int);
    bool completed;
    bool getCompleted();
    virtual string getName();
    double randomDouble(double,double);
    int randomInt(int, int);
    virtual void complete(Runner&)=0;
    Space();
    
protected:
   
};
#endif /* Space_hpp */
