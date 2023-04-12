#ifndef EMPLOYEE
#define EMPLOYEE

#include "person.h"
#include <iostream>

class Employee: public Person{
    private:
        std::string _empNum;
    public:
        std::string pos, office;
        int salary;

        Employee& setEmpNum(std::string en);
        std::string getEmpNum();
        
        Employee& setPos(std::string po);
        std::string getPos();

        Employee& setOffice(std::string of);
        std::string getOffice();

        Employee& setSalary(int sl);
        int getSalary();

};


#endif