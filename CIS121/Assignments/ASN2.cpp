//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Assignment 2															//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			September 26, 2021														//
//	Project Name:			ASN2																	//
//	File Name:				ASN2.cpp															    //
//																									//
//	Purpose of Program:				                                                                //
//  Calculates the day of week when given the date												    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

// Main Program
int main()
{
	// Variable Declarations
	int month, day, year, calc, monthkey = 0, yearkey = 0, repeatcase = 0;
	bool leapyear = false, loop = true;
	char repeat;

	// Output Identification
	system("CLS");
	cout << "Assignment 2 Exercise #2 by Aidan Sullivan - " << "Find the Day of the Week\n";
	while (loop == true)
	{
		cout << "\nEnter the day (1 - 31): ";
		cin >> day; // Day of Month
		cout << "Enter the month (1 - 12): ";
		cin >> month; // Month of Year
		cout << "Enter the year (1752 - 2399): ";
		cin >> year; // Year

		//Calculates the Century Key
		if (year < 2000 && year > 1899 || year < 2400 && year > 2299)
			yearkey = 0;
		else if (year < 1900 && year > 1799 || year < 2300 && year > 2199)
			yearkey = 2;
		else if (year < 1800 && year > 1699 || year < 2200 && year > 2099)
			yearkey = 4;
		else if (year < 2100 && year > 1999)
			yearkey = 6;

		//Calculates the Leap Year
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
			leapyear = true;
		else
			leapyear = false;

		//Calculates the Month Key
		if (month == 1 && leapyear == true || month == 4 || month == 7)
			monthkey = 0;
		else if (month == 1 || month == 10)
			monthkey = 1;
		else if (month == 5)
			monthkey = 2;
		else if (month == 2 && leapyear == true || month == 8)
			monthkey = 3;
		else if (month == 2 || month == 3 || month == 11)
			monthkey = 4;
		else if (month == 6)
			monthkey = 5;
		else if (month == 9 || month == 12)
			monthkey = 6;
		else
		{
			cout << "ERROR: Invalid number input(s)";
			return 0;
		}

		//Inputs variables into the Algorithm
		calc = ((year % 100) + ((year % 100) / 4) + monthkey + day + yearkey) % 7;

		//Converts key into day of the week
		if (calc == 0)
			cout << "\nThat day is Saturday.";
		if (calc == 1)
			cout << "\nThat day is Sunday.";
		if (calc == 2)
			cout << "\nThat day is Monday.";
		if (calc == 3)
			cout << "\nThat day is Tuesday.";
		if (calc == 4)
			cout << "\nThat day is Wednesday.";
		if (calc == 5)
			cout << "\nThat day is Thursday.";
		if (calc == 6)
			cout << "\nThat day is Friday.";

		//Loop
		repeatcase = 0;
		while (repeatcase == 0)
		{
			cout << "\n\nDo you want to continue? (y/n): ";
			cin >> repeat;
			switch (repeat)
			{
			case 'Y':
				repeatcase++;
				break;
			case 'y':
				repeatcase++;
				break;
			case 'N':
				loop = false;
				repeatcase++;
				break;
			case 'n':
				loop = false;
				repeatcase++;
				break;
			default:
				cout << "\nERROR: Invalid input. Try again.";
			}

		}
	
	}
	cout << "\nEnd Program.\n";
	return 0;
}
