//
//  ObstacleCourse.hpp
//  
//
//  Created by Carrie Davis on 8/8/18.
//

#ifndef ObstacleCourse_hpp
#define ObstacleCourse_hpp
#include <vector>
#include <memory>
#include "Space.hpp"
#include "Runner.hpp"
#include "Swim.hpp"
#include "Climb.hpp"
#include "Run.hpp"
#include "Balance.hpp"
#include "Crawl.hpp"
#include "End.hpp"
#include "Start.hpp"

class ObstacleCourse{
public:
    vector<vector<shared_ptr<Space>>> course{
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL},
        {NULL,NULL,NULL,NULL} };
    void run();
    void setUpCourse();
    void navigateCourse(Runner&);
    ObstacleCourse();
    shared_ptr<Space> addObstacle(int);
    int randomNumber(int,int);
    void print();
    //void bonk();  //no energy left to finish race
    //int aidStation(); //get water and add energy gel,orange slice or gummies
};
#endif /* ObstacleCourse_hpp */
