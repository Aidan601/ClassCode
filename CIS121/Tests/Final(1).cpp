//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Final																	//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			December 15, 2021														//
//	Project Name:			Final																	//
//	File Name:				Final.cpp																//
//																									//
//	Purpose of Program:																				//
//		Generates random number and asks user to guess what it is									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

// Main Program
int main()
{
	// Variable Declarations
	bool loop = true;
	int guess, number, count = 0;

	// Output Identification
	system("CLS");
	cout << "Final Problem #2 by Aidan Sullivan - "
		<< "Number Guesser\n\n";

	srand(time(0));
	number = 1 + rand() % 100;
	while (loop == true)
	{
		cout << "Enter a number (1-100): ";
		cin >> guess;
		if (guess > number)
			cout << "Too high, try again." << endl;
		else
			if (guess < number)
				cout << "Too low, try again." << endl;
			else
				loop = false;
		count++;
	}
	cout << "Correct! The number was " << number << "!" << endl;
	if (count == 1)
		cout << "It took 1 guess";
	else
		cout << "It took " << count << " guesses";

	cout << "\nEnd Program.\n";

	return 0;
}

