//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-223 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 2																	//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			February 1, 2022														//
//	Project Name:			LAB2																	//
//	File Name:				LAB2(1).cpp																//
//																									//
//	Purpose of Program:																				//
//		Calculate the total pay of employees given the pay rate and hours							//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class PayRoll
{
private:
	double pay, hours;
public:
	//Default Constructor
	PayRoll();

	//Constructor
	PayRoll(double p, double h);

	//Mutators
	void setPay(double p);
	void setHours(double h);

	//Accesors
	double getPay();
	double getHours();
	double getTotalPay();

	void Input(int i);
};

int main()
{
	// Variable Declarations
	double pay = 0, hours = 0;

	//Declare Object

	// Output Identification
	system("CLS");
	cout << "Lab 2 Exercise #2 by Aidan Sullivan - "
		<< "Payroll\n\n";

	PayRoll employee[7];
	cout << "Enter the hours worked and pay rate for 7 employees:" << endl;
	for (int i = 0; i < 7; i++)
	{
		employee[i].Input(i);
	}
	cout << "Total Pay:" << endl;
	cout << setprecision(2) << fixed;
	cout << "\tEmployee #1: " << employee[0].getTotalPay() << endl;
	cout << "\tEmployee #2: " << employee[1].getTotalPay() << endl;
	cout << "\tEmployee #3: " << employee[2].getTotalPay() << endl;
	cout << "\tEmployee #4: " << employee[3].getTotalPay() << endl;
	cout << "\tEmployee #5: " << employee[4].getTotalPay() << endl;
	cout << "\tEmployee #6: " << employee[5].getTotalPay() << endl;
	cout << "\tEmployee #7: " << employee[6].getTotalPay() << endl;
}

PayRoll::PayRoll()
{
	hours = 0;
	pay = 0;
}

PayRoll::PayRoll(double p, double h)
{
	pay = p;
	hours = h;
}

void PayRoll::setPay(double p)
{
	pay = p;
}

void PayRoll::setHours(double h)
{
	hours = h;
}

double PayRoll::getPay()
{
	return pay;
}

double PayRoll::getHours()
{
	return hours;
}

double PayRoll::getTotalPay()
{
	return pay * hours;
}

void PayRoll::Input(int i)
{
	cout << "\nEmployee #" << i + 1 << " pay rate: ";
	cin >> pay;
	cout << "Employee #" << i + 1 << " hours worked: ";
	cin >> hours;
	while (hours > 60)
	{
		cout << "Invalid Input. Hours must be less then 60. Try Again." << endl;
		cout << "Employee #" << i + 1 << " hours worked: ";
		cin >> hours;
	}
	setPay(pay);
	setHours(hours);
}
