#include "employee.h"
#include <iostream>

Employee& Employee::setEmpNum(std::string en){
    _empNum = en;
    return *this;
}

std::string Employee::getEmpNum(){
    return _empNum;
}

Employee& Employee::setOffice(std::string of){
    office = of;
    return *this;
}

std::string Employee::getOffice(){
    return office;
}

Employee& Employee::setPos(std::string po){
    pos = po;
    return *this;
}

std::string Employee::getPos(){
    return pos;
}

Employee& Employee::setSalary(int sl){
    salary = sl;
    return *this;
}

int Employee::getSalary(){
    return salary;
}