//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 14																	//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			December 5, 2021														//
//	Project Name:			LAB14																	//
//	File Name:				LAB14(1).cpp															//
//																									//
//	Purpose of Program:																				//
//		Stores and displays employee data                       									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

//Constant Declaration
const int MAX_EMPOLYEE = 5;

//Class declaration
class Employee
{
public:
    // Constructors
    Employee(string n, int id, string dep, string pos);
    Employee(string n, int id);
    Employee();

    // Mutators
    void setName(string n);
    void setId(int id);
    void setDepartment(string dep);
    void setPosition(string pos);

    // Accessors
    string getName() const;
    int getId();
    string getDepartment();
    string getPosition();

private:
    string name;        // Employee's name
    int idNumber;       // ID number
    string department;  // Department name
    string position;    // Employee's position
};

void displayInfo(Employee e)
{
    cout << e.getName() << "\t" << e.getId() << "\t\t" << e.getDepartment();
    if (e.getDepartment() == "IT")
        cout << "\t\t";
    else
        cout << "\t";
    cout << e.getPosition() << endl;
}

int main()
{
    // Create an Employee object to test constructor #1.
    Employee susan("Susan Meyers", 47899, "Accounting", "Vice President");


    // Create an Employee object to test constructor #2.
    Employee mark("Mark Jones", 39119);
    mark.setDepartment("IT");
    mark.setPosition("Programmer");


// Create an Employee object to test constructor #3.
    Employee joy;
    joy.setName("Joy Rogers");
    joy.setId(81774);
    joy.setDepartment("Manufacturing");
    joy.setPosition("Engineer");

    // Display each employee's data.
    cout << "Name\t\tID Number\tDepartment\tPosition" << endl;
    displayInfo(susan);
    displayInfo(mark);
    displayInfo(joy);

    return 0;
}

// Constructor #1
/* add function description here

*/
Employee::Employee(string n, int id, string dep, string pos)
{
    name = n;
    idNumber = id;
    department = dep;
    position = pos;
}

// Constructor #2
/* add function description here

*/
Employee::Employee(string n, int id)
{
    name = n;
    idNumber = id;
    department = "";
    position = "";
}

// Constructor #3, default constructor
/* add function description here

*/
Employee::Employee()
{
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

// Mutators
void Employee::setName(string n)
{
    name = n;
}

void Employee::setId(int id)
{
    idNumber = id;
}

void Employee::setDepartment(string dep)
{
    department = dep;
}

void Employee::setPosition(string pos)
{
    position = pos;
}

// Accessors
string Employee::getName() const
{
    return name;
}

int Employee::getId()
{
    return idNumber;
}

string Employee::getDepartment()
{
    return department;
}

string Employee::getPosition()
{
    return position;
}
