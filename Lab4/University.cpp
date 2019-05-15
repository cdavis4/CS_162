/********************************************
 ** Author: carrie davis
 ** Date:July 22, 2018
 ** Description: Lab 4; Info System
 *********************************************///
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <string>
#include <limits>

using namespace std;

#include "University.hpp"

//Default Constructor
University::University()
{
    this->name = "Oregon State University";
    //distinguish between GPA or Rating whether fac or student
    //name, age
   
}

/********************************************
 * University::printBuildings
 * print buildings
 *******************************************/
void University::printBuildings()
{
    vector<Building> buildings;
    Building building1("Women's Building", 85441,"160 SW 26TH STREET");
    Building building2("Withycombe Hall", 81136,"2921 SW CAMPUS WAY");
    Building building3("Gilfillan Auditorium", 56478,"2601 SW ORCHARD AVE");
    Building building4("Wiegand Hall", 57610,"3051 SW CAMPUS WAY");
    Building building5("Merryfield Hall", 57610,"3051 SW CAMPUS WAY");
    
    buildings.push_back(building1);
    buildings.push_back(building2);
    buildings.push_back(building3);
    buildings.push_back(building4);
    buildings.push_back(building5);
    
   string printOut;
    
    //name, size and address of building pg 948
    cout << "\n Building : Address : Size (square feet) \n " <<endl;
    for(int building = 0; building < 5; building++)
    {
        cout <<buildings[building].getName() << " : ";
        cout <<buildings[building].getAddress()<< " : " ;
        cout <<buildings[building].getSize()<<endl;
    }
    
    
    
}
/********************************************
 * University::printPeople
 * print people
 *******************************************/
void University::printPeople()
{
    vector<shared_ptr<Student>> people
    {   make_shared<Student>("Carol Brown", 22, 4.0),
        make_shared<Student>("Sarah Wright", 25, 3.0),
        make_shared<Student>("Paul Willams", 32, 3.4),
        make_shared<Student>("Will Mel", 20, 2.8),
        make_shared<Student>("Joe Yu", 21, 3.8),
        make_shared<Instructor>("Ryan Cantor", 38, 5.0),
        make_shared<Instructor>("Jill Yu", 21, 4.8),
        make_shared<Instructor>("Beck Scott", 43, 3.8)
    };
    
    cout << "\n Person : Age : Score : Work Status" <<endl;
    for(int person = 0; person < people.size(); person++)
    {
        cout <<people[person]->getName() << " : ";
        cout <<people[person]->getAge()<< " : " ;
        cout <<people[person]->getScore()<< " : " ;
        cout <<people[person]->do_work()<<endl;
    }
}
/********************************************
 * University::printPerson
 * print people
 *******************************************/
void University::printPersonList()
{
    vector<shared_ptr<Student>> people
    {   make_shared<Student>("Carol Brown", 22, 4.0),
        make_shared<Student>("Sarah Wright", 25, 3.0),
        make_shared<Student>("Paul Willams", 32, 3.4),
        make_shared<Student>("Will Mel", 20, 2.8),
        make_shared<Student>("Joe Yu", 21, 3.8),
        make_shared<Instructor>("Ryan Cantor", 38, 5.0),
        make_shared<Instructor>("Jill Yu", 21, 4.8),
        make_shared<Instructor>("Beck Scott", 43, 3.8)
    };
    
    cout << "\n People at University" <<endl;
    for(int person = 0; person < people.size(); person++)
    {
        cout << person + 1 <<". ";
        cout <<people[person]->getName() << endl;
    }
    int choice;
    cout << "Who would you like to work with? " <<endl;
    cout << "Enter your choice: ";
    cin >> choice;
    
    //input validation
        while ((choice < 1 || choice > 8) || ((choice % 1) != 0))
        {
            cout <<"Invalid input " <<endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cout << "Who would you like to work with? " <<endl;
            cout << "Enter your choice: ";
            cin >> choice;
        }
    cout << "\n" <<endl;
    cout << "You picked " << people[choice - 1]->getName() << ". " <<endl;
    
}
/********************************************
 * University::printPeople
 * print people
 *******************************************/
string University::getName()
{
    
    return name;
}
