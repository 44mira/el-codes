#include <iostream>
#include "person.h"
#include "person.cpp"
#include "employee.h"
#include "employee.cpp"

using namespace std;

int main(void){

    Employee empl = Employee();

    cout << "This program is a demonstration of the Employee class." << endl;

    cout << "Programmed by: Legolas Tyrael B. Lada" << endl;

    string inp;
    cout << "Employee First name: ";
    cin >> inp;
    empl.setFname(inp);
    cout << endl;

    cout << "Employee Last name: ";
    cin >> inp;
    empl.setLname(inp);
    cout << endl;
    
    cout << "Employee Email: ";
    cin >> inp;
    empl.setEmail(inp);
    cout << endl;

    cout << "Employee Cellphone Number: ";
    cin >> inp;
    empl.setCpNum(inp);
    cout << endl;

    char inp2;
    cout << "Employee Gender: ";
    cin >> inp2;
    empl.setGender(inp2);
    cout << endl;

    cout << "Employee Number: ";
    cin >> inp;
    empl.setEmpNum(inp);
    cout << endl;

    cout << "Position: ";
    getline(cin, inp);      // takes first space
    getline(cin, inp);
    empl.setPos(inp);
    cout << endl;

    cout << "Office: ";
    getline(cin, inp);
    empl.setOffice(inp);
    cout << endl;

    int sal;
    cout << "Salary: ";
    cin >> sal;
    empl.setSalary(sal);
    cout << endl;

    cout << "\nHi, " << empl.getLname() << " " << empl.getFname() << "!"
            " Welcome to UP Mindanao and congratulations!\nWe are pleased to inform you that"
            " you are employed in the " << empl.getOffice() << " office with the"
            " position of " << empl.getPos() << ".\nYour starting salary is: P" << empl.getSalary() << "."
            "\nYour Employee number is " << empl.getEmpNum() << ".\nCP No. : " << empl.getCpNum() << "\n"
            "Email : " << empl.getEmail();


    return 0;
}