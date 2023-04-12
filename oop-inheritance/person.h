#ifndef PERSON
#define PERSON
#include <iostream>

class Person{
    public:
        int age;
        char gender;
        std::string lname, fname, cpNumber, emailAdd;

        Person& setAge(int a);
        int getAge();

        Person& setGender(char g);
        char getGender();

        Person& setLname(std::string ln);
        std::string getLname();

        Person& setFname(std::string fn);
        std::string getFname();

        Person& setCpNum(std::string cp);
        std::string getCpNum();
        
        Person& setEmail(std::string em);
        std::string getEmail();


};


#endif