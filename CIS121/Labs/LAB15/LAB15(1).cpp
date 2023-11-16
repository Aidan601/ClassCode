//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 15																	//
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			December 12, 2021														//
//	Project Name:			LAB15(2)																//
//	File Name:				LAB15(2).cpp															//
//																									//
//	Purpose of Program:																				//
//		Checks if password input meets the correct criteria											//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

// Main Program
int main()
{
	// Variable Declarations
	string password;
	bool upper = false, lower = false, number = false;


	// Output Identification
	system("CLS");
	cout << "Lab 3 Exercise #3 by Aidan Sullivan - "
		<< "Password\n\n";

	while (upper == false || lower == false || number == false)
	{
		upper = false, lower = false, number = false;
		cout << "Enter a password: ";
		cin >> password;
		for (int i = 0; i < password.size(); i++)
		{
			//Checks if uppercase
			if (isupper(password.at(i))) // Checks if uppercase
				upper = true;
			if (islower(password.at(i))) // Checks if lowercase
				lower = true;
			if (isdigit(password.at(i))) // Checks if number
				number = true;
		}
		
		if (upper == false || lower == false || number == false)
		{
			cout << "The password must have:" << endl;
			cout << "\tat least one upper" << endl;
			cout << "\tat least one lower" << endl;
			cout << "\tat least one number" << endl;
			cout << "The password is not valid.\n" << endl;
		}
	}
	cout << "The password is valid.";

	cout << "\n\nEnd Program.\n";

	return 0;
}

