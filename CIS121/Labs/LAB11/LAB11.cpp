//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 11																	//
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			November 8, 2021														//
//	Project Name:			Lab 11																	//
//	File Name:				LAB11.cpp																//
//																									//
//	Purpose of Program:																				//
//		Takes input and puts it in reverse.															//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

//Function declaration


// Main Program
int main()
{

	// Variable Declarations
	char input[20], repeat = 'y';

	// Output Identification
	system("CLS");
	cout << "Lab 11 Exercise #3 by Aidan Sullivan - "
		<< "Char Reverse Order\n";

	while (repeat == 'Y' || repeat == 'y')
	{
		int count = 0, repeatcase = 0;
		cout << "\nEnter a list of Characters (. to end list):\n";
		cin >> ws;
		cin.getline(input, 21);

		//Counts the size of array
		for (int i = 0; i < 20; i++)
		{
			if (input[i] == '.')
				break;
			else
				count++;
		}

		//Outputs array backwards
		cout << "\nThe characters in reverse order are:" << endl;
		for (int i = count - 1; i >= 0; i--)
			cout << input[i];

		while (repeatcase == 0)
		{
			cout << "\n\nWould you like to process another list? (Y or N): ";
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
				repeatcase++;
				break;
			case 'n':
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

