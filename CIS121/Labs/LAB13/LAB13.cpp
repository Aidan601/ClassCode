//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 13																	//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			November 15, 2021														//
//	Project Name:			LAB13																	//
//	File Name:				LAB13.cpp																//
//																									//
//	Purpose of Program:																				//
//		Seperates sentances without space   														//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Main Program
int main()
{
	// Variable Declarations
	string input;

	// Output Identification
	system("CLS");
	cout << "Lab 13 Exercise #2 by Aidan Sullivan - "
		<< "Word Separator\n\n";

	cout << "Input a sentance without spaces (First letter of each word must be uppercase):" << endl;
	cin >> input;
	
	for (int i = 1; i < input.size(); i++)
	{
		//Checks if uppercase
		if (isupper(input.at(i)))
		{
			input.at(i) = tolower(input.at(i)); //Converts Uppercase to lowercase
			input.insert(i, " "); //Inserts a space between the words;
		}
	}
	cout << input;
	cout << "\n\nEnd Program.\n";

	return 0;
}

