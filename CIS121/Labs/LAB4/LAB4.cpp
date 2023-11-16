//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 4																	//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			September 15, 2021														//
//	Project Name:			LAB4																	//
//	File Name:				LAB4.cpp																//
//																									//
//	Purpose of Program:																				//
//		Prints out a weekly paycheck stub for an hourly worker										//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	double gross,sst,fit,sit,net; //Gross Pay, Social Security Tax. Federal Income Tax, State Income Tax, Net Pay
	int hours,depend; //Hours Worked, Number of Dependents
	system("CLS");
	cout << "Lab 4 Exercise #2 by Aidan Sullivan - " << "Pay Stub\n\n";
	cout << "Enter the number of hours worked this week:";
	cin >> hours;
	cout << "Enter the number of dependents:";
	cin >> depend;
	if (hours > 40)
	{
		gross = (hours - 40) * 25.17 + 671.20; //Calculate Gross Pay with Overtime
	}
	else
	{
		gross = hours * 16.78; //Calculate Normal Gross Pay
	}
	sst = gross * 0.06; //Calculate Social Security Tax
	fit = gross * 0.14; //Calculate Federal Income Tax
	sit = gross * 0.05; //Calculate State Income Tax
	cout << "\nYour gross pay is:          " << setprecision(2) << fixed << gross; //Outputs and Corrected decimal numbers
	cout << "\n\nDeductions\n";
	cout << "  Social Security Tax:       " << sst;
	cout << "\n  Federal Income Tax:        " << fit;
	cout << "\n  State Income Tax:          " << sit;
	cout << "\n  Union Dues:                10.00";
	if (depend >= 3) //Health Insurance if there are 3 or more dependents
	{
		cout << "\n  Health Insurance:          35.00";
		net = gross - sst - fit - sit - 45;
	}
	else // Less than 3 dependents
	{
		net = gross - sst - fit - sit - 10;
	}
	cout << "\n\nYour net pay is:            " << net;
	cout << "\n\nEnd Program.\n";
	return 0;
}
