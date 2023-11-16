//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 12 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 23, 2022				    							            //
//	File Name:				LAB12.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates inheritance and derived classes			   						//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
using namespace std;

class Employee //Base Class
{
protected:
	string name;
	int number;
	string date;
public:
	Employee(); //Default Constructor
	~Employee(); //Destructor
	Employee(string n,int m,string d); //Constructor
};

class ProductionWorker : public Employee //Derived Class
{
protected:
	int shift;
	double pay;
public:
	ProductionWorker(); //Default Constructor
	ProductionWorker(int s, double p); //Constructor
	ProductionWorker(string n, int m, string d, int s, double p); //Constructor
	void ProductionWorkerOutput(); //Outputs data for step 1
};

class TeamLeader : public ProductionWorker //Step 2 Derived Class
{
private:
	double bonus;
	int hours;
	
public:
	TeamLeader(); //Default Constructor
	TeamLeader(double b, int h); //Constructor
	TeamLeader(string n, int m, string d, int s, double p, double b, int h); //Constructor
	void TeamLeaderOutput(); //Outputs data for step 2
};


int main()
{
	//Step 1
	ProductionWorker John("John Jones",12345, "9/9/2014", 2, 16);
	John.ProductionWorkerOutput();

	cout << "\n"; //Divider

	//Step 2
	TeamLeader James("James Jones", 54321, "8/12/2012", 1, 18, 50, 40);
	James.TeamLeaderOutput();
}

ProductionWorker::ProductionWorker() //Default Constructor
{
	shift = 1;
	pay = 0;
}

ProductionWorker::ProductionWorker(int s, double p) //Constructor
{
	shift = s;
	pay = p;
}

ProductionWorker::ProductionWorker(string n, int m, string d, int s, double p) //Constructor
{
	name = n;
	number = m;
	date = d;
	shift = s;
	pay = p;
}

void ProductionWorker::ProductionWorkerOutput() //Outputs data for step 1
{
	cout << "Name: " << name << endl;
	cout << "Employee Number: " << number << endl;
	cout << "Hire date: " << date << endl;
	cout << "Shift: ";
	if (shift == 1)
		cout << "Day" << endl;
	else
		cout << "Night" << endl;
	cout << "Shift number: " << shift << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Pay rate: $" << pay << endl;
}

Employee::Employee() //Default Constructor
{
	name = "John Doe";
	number = 00000;
	date = "1/1/1970";
}

Employee::~Employee() //Destructor
{
	system("pause");
}

Employee::Employee(string n, int m, string d) //Constructor
{
	name = n;
	number = m;
	date = d;
}

//Step 2
TeamLeader::TeamLeader() //Default Constructor
{
	bonus = 0;
	hours = 0;
}

TeamLeader::TeamLeader(double b, int h) //Constructor
{
	bonus = b;
	hours = h;
}

TeamLeader::TeamLeader(string n, int m, string d, int s, double p, double b, int h) //Constructor
{
	name = n;
	number = m;
	date = d;
	shift = s;
	pay = p;
	bonus = b;
	hours = h;
}

void TeamLeader::TeamLeaderOutput() //Outputs data for step 2
{
	cout << "Name: " << name << endl;
	cout << "Employee Number: " << number << endl;
	cout << "Hire date: " << date << endl;
	cout << "Shift: ";
	if (shift == 1)
		cout << "Day" << endl;
	else
		cout << "Night" << endl;
	cout << "Shift number: " << shift << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Pay rate: $" << pay << endl;
	cout << "Monthly Bonus: $" << bonus << endl;
	cout << "Training Hours: " << hours << endl;
}