//
//  LoadedDie.hpp
//  
//
//  Created by Carrie Davis on 7/11/18.
//

#ifndef LoadedDie_hpp
#define LoadedDie_hpp

#include "Die.hpp"
class LoadedDie : public Die
{
    
public:
 

 LoadedDie(int N): Die(N)
   {
       
   }
     int rollDie();
    
};


#endif /* LoadedDie_hpp */
