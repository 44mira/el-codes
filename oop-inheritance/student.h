#ifndef STUDENT
#define STUDENT

#include "person.h"
#include <iostream>

class Student : public Person{
    private:
        std::string _studentNum;

    public: 
        std::string course, dept, college;
        
        Student& setStudentNum(std::string sn);
        std::string getStudentNum();

        Student& setCourse(std::string co);
        std::string getCourse();

        Student& setDept(std::string dp);
        std::string getDept();

        Student& setCollege(std::string cl);
        std::string getCollege();

};

#endif
