#include "student.h"
#include <iostream>


Student& Student::setStudentNum(std::string sn){
    _studentNum = sn;
    return *this;
}

std::string Student::getStudentNum(){
    return _studentNum;
}

Student& Student::setCollege(std::string cl){
    college = cl;
    return *this;
}

std::string Student::getCollege(){
    return college;
}

Student& Student::setCourse(std::string co){
    course = co;
    return *this;
}

std::string Student::getCourse(){
    return course;
}

Student& Student::setDept(std::string dp){
    dept = dp;
    return *this;
}

std::string Student::getDept(){
    return dept;
}