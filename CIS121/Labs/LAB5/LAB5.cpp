//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 5																	//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			September 20, 2021														//
//	Project Name:			LAB5																    //
//	File Name:				LAB5.cpp															    //
//																									//
//	Purpose of Program:																				//
//		The program will ask you to list 10 numbers and it will output the total amount of			//
//		positive and negative numbers, the sums of each, and the largest and smallest numbers.		//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

// Main Program
int main()
{
	// Variable Declarations
	double average, sum = 0, sumn = 0, sump = 0;
	int positve = 0, negative = 0, ask = 0, num;
	int low = INT_MAX, high = INT_MIN;

	// Output Identification
	system("CLS");
	cout << "Lab 5 Exercise #1 by Aidan Sullivan - "
		<< "The Sum, the Largest and the Smallest\n\n";
	
	cout << "Please enter 10 numbers:\n\n";
	while (ask < 10)
	{
		cout << "Enter a number: ";
		cin >> num;
		if (num > 0)
		{
			positve++;
			sump = num + sump;
			sum = num + sum;
		}
		else if (num < 0)
		{
			negative++;
			sumn = num + sumn;
			sum = num + sum;
		}
		if (num < low)
		{
			low = num;
		}
		if (num > high)
		{
			high = num;
		}
		ask++;
	}
	average = sum / 10;
	cout << "\nThere were a total of " << positve << " positive numbers entered\n";
	cout << "There were a total of " << negative << " negative numbers entered\n\n";
	cout << "The sum of all the negative numbers is: " << sumn;
	cout << "\nThe sum of all the positive numbers is: " << sump;
	cout << "\nThe sum of all numbers is: " << sum;
	cout << "\n\nThe average of all the numbers is: " << average;
	cout << "\nThe largest number is " << high;
	cout << "\nThe lowest number is " << low;
	cout << "\n\nEnd Program.\n";
	return 0;
}

