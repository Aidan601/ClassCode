//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 12																	//
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			November 8, 2021														//
//	Project Name:			Lab 12																	//
//	File Name:				LAB12.cpp																//
//																									//
//	Purpose of Program:																				//
//		Reads in a word from the keyboard and determines if the word is a palindrome.				//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

//Function declaration
bool palindrome(int count, char input[])
{
	char output[21];
	for (int i = count-1, x = 0; i >= 0, x <= count; i--, x++)
	{
		if (input[i] != '.')
			output[x] = input[i];
		else
			x--;
	}
	output[count] = '.';
	output[count + 1] = '\0';
	
	for (int i=0; i<= count; i++)
		if (input[i] != output[i])
			return false;
	return true;
}

// Main Program
int main()
{

	// Variable Declarations
	char input[21], repeat = 'y';
	// Output Identification
	system("CLS");
	cout << "Lab 12 Exercise #3 by Aidan Sullivan - "
		<< "Palindrome with Arrays\n";

	while (repeat == 'Y' || repeat == 'y')
	{
		int count = 0, repeatcase = 0;
		cout << "\nEnter a word (. to end word):\n";
		cin >> ws;
		cin.getline(input, 21);

		//Counts the size of array
		for (int i = 0; i < 21; i++)
		{
			if (input[i] == '.')
				break;
			else
			{ 
				count++;
			}
		}
		
		//Call palindrome function
		if (palindrome(count, input) == true)
			cout << "The word is a palindrome.";
		else
			cout << "The word is NOT a palindrome";

		while (repeatcase == 0)
		{
			cout << "\n\nWould you like to check another palindrome? (Y or N): ";
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

