#include "person.h"
#include <iostream>

Person& Person::setAge(int a){
    age = a;
    return *this;
}

int Person::getAge(){
    return age;
}

Person& Person::setGender(char g){
    gender = g;
    return *this;
}

char Person::getGender(){
    return gender;
}

Person& Person::setLname(std::string ln){
    lname = ln;
    return *this;
}

std::string Person::getLname(){
    return lname;
}

Person& Person::setFname(std::string fn){
    fname = fn;
    return *this;
}

std::string Person::getFname(){
    return fname;
}

Person& Person::setCpNum(std::string cp){
    cpNumber = cp;
    return *this;
}

std::string Person::getCpNum(){
    return cpNumber;
}

Person& Person::setEmail(std::string em){
    emailAdd = em;
    return *this;
}

std::string Person::getEmail(){
    return emailAdd;
}
