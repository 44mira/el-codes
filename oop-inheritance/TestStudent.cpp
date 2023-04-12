#include <iostream>
#include "person.h"
#include "person.cpp"
#include "student.h"
#include "student.cpp"

using namespace std;

int main(void){

    Student stdnt = Student();

    cout << "This program is a demonstration of the Student class." << endl;

    cout << "Programmed by: Legolas Tyrael B. Lada" << endl;

    string inp;
    cout << "Student First name: ";
    cin >> inp;
    stdnt.setFname(inp);
    cout << endl;

    cout << "Student Last name: ";
    cin >> inp;
    stdnt.setLname(inp);
    cout << endl;

    cout << "Student Email: ";
    cin >> inp;
    stdnt.setEmail(inp);
    cout << endl;

    cout << "Student Cellphone Number: ";
    cin >> inp;
    stdnt.setCpNum(inp);
    cout << endl;

    char inp2;
    cout << "Student Gender: ";
    cin >> inp2;
    stdnt.setGender(inp2);
    cout << endl;

    cout << "Student Number: ";
    cin >> inp;
    stdnt.setStudentNum(inp);
    cout << endl;

    cout << "Course: ";
    getline(cin, inp);      // takes first space
    getline(cin, inp);
    stdnt.setCourse(inp);
    cout << endl;

    cout << "Department: ";
    getline(cin, inp);
    stdnt.setDept(inp);
    cout << endl;

    cout << "College: ";
    getline(cin, inp);
    stdnt.setCollege(inp);
    cout << endl;

    cout << "\nHi, " << stdnt.getLname() << " " << stdnt.getFname() << "!"
            " Welcome to UP Mindanao and congratulations!\nWe are pleased to inform you that"
            " you are admitted in the " << stdnt.getCourse() << " program\nunder the"
            " Department of " << stdnt.getDept() << ", " << stdnt.getCollege() << "."
            "\nYour Student number is " << stdnt.getStudentNum() << ".\nCP No. : " << stdnt.getCpNum() << "\n"
            "Email: " << stdnt.getEmail();


    return 0;
}