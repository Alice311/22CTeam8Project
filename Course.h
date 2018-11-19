//
//  Course.h
//  22CTeam8Project
//
//  Created by SOFLY on 11/5/18.
//  Copyright © 2018 SOFLY. All rights reserved.
//  Programmer Isaac Li

#ifndef Course_h
#define Course_h
#include <string>

using namespace std;

class Course{

private:
    int crn;
    string courseName;
    string instructor;
    string days;
    string departments;
    string location;

public:
    Course(){}      //Default Constructor
    Course(int c, string cn, string ins, string day, string dep, string loc){
        crn = c;
        courseName = cn;
        instructor = ins;
        days = day;
        departments = dep;
        location = loc;

    }


    //Acccessors
    int getCrn(){return crn;}
    string getCourseName(){return courseName;}
    string getInstructor(){return instructor;}
    string getDays(){return days;}
    string getDepartment(){return departments;}
    string getLocation(){return location;}


    //Mutators
    void setCrn(int c){crn = c;}
    void setCourseName(string cn){courseName = cn;}
    void setInstructor(string ins){instructor = ins;}
    void setDays(string d){days = d;}
    void setDepartments(string dep){departments = dep;}
    void setLocation(string loc){location = loc;}




};




#endif /* Course_h */
