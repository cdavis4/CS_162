//
//  Building.hpp
//  
//
//  Created by Carrie Davis on 7/23/18.
//

#ifndef Building_hpp
#define Building_hpp

using namespace std;
class Building
{
protected:
    string name;
    int size;  //square feet
    string address;
    
public:
    Building();
    Building(string, int, string);  //name, size, address
    int getSize();
    void setSize(int);
    void setAddress(string);
    void setName(string);
    string getName();
    string getAddress();
};

#endif /* Building_hpp */
