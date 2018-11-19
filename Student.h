//
//  Student.h
//  22CTeam8Project
//
//  Created by SOFLY on 11/8/18.
//  Copyright © 2018 SOFLY. All rights reserved.
//  Programmer Isaac Li

#ifndef Student_h
#define Student_h
#include "Course.h"
#include <cstring>

using namespace std;

const int MAX_COURSE = 8;

class Student{
private:
    string studentID;
    string name;
    string major;
    string address;
    Course *courses;
    int year;



public:
    Student(){}
    Student(string s, string n, string m, string a, int y){
        studentID = s;
        name = n;
        major = m;
        address = a;
        year = y;
        courses = new Course[MAX_COURSE];
    }

    /*Accessors*/
    string getStudentID(){return studentID;} const
    string getName(){return name;} const
    string getMajor(){return major;} const
    string getAddress(){return address;} const
    Course* getCourses(){return courses;}
    Course getCourse(string cs){
        for(int i = 0; i < MAX_COURSE; i++)
            if(courses[i].getCourseName() == cs)
                return courses[i];
        Course emptyCourse;
        return emptyCourse;
    }
    int getYear(){return year;}


    /*Mutators*/
    void setStudentID(string id){studentID = id;}
    void setName(string n){name = n;}
    void setMajor(string m){major = m;}
    void setAddress(string a){address = a;}
    void setYear(int y){year = y;}
    bool addCourse(Course c){
        Course* temp = courses;
        for(int i = 0; i < MAX_COURSE; i++){
            if(!temp){
                *temp = c;
                return true;
            }
            temp++;
        }
        return false;
    }
    bool deleteCourse(string cs){
        Course* temp = courses;
        for(int i = 0; i < MAX_COURSE; i++){
            if(temp->getCourseName() == cs){
                delete temp;
                temp = new Course;
                return true;
            }
            temp++;
        }
        return false;
    }

    friend ostream& operator<< (ostream& os, const Student& stu);

};

ostream& operator<< (ostream& os, const Student& stu){
    os << stu.studentID;
    return os;
}


#endif /* Student_h */

