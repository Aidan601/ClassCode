//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:	Lab 11	  	 																//
//	Problem Number:	2		 																		//
//	Author:	Aidan Sullivan																			//
//	Due Date: November 8, 2021 			 															//
//	File Name:	lotteryStarter.cpp																	//
//																									//
//	Purpose of Program:																				//
//	Allows user to input 5 numbers and program generates 5 of its own.								//
//	Then it compares the two numbers displays how many match.										//		
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Global constants
const int SIZE = 5;
const int MAX_RANGE = 10;  //0 through 9

// Function prototypes
void generateNumbers(int lottery[], int size);
void getUser(int user[], int size);
int findMatches(int lottery[], int user[], int size);
void displayValues(int lottery[], int user[], int size);


int main()
{
	//Declare variables
	int lottery[SIZE]; // Lottery numbers array  
	int user[SIZE];	 // User array
	int numOfMatches; // Number of matches

	//Output Identification
	system("CLS");
	cout << "Lab #11 Exercise #2 by Aidan Sullivan - "
		<< "Lottery Application\n\n";

	// Generate the random lottery numbers.
	generateNumbers(lottery, SIZE);

	// Get the user's numbers.
	getUser(user, SIZE);

	// Display the lottery and the user picked numbers.
	displayValues(lottery, user, SIZE);

	// Get the number of matching numbers.
	// Call findMatches function and returns the number of matching number
	int matches = findMatches(lottery, user, SIZE);

	// Display the number of matching numbers.
	if (matches == 1)
		cout << "\nYou have 1 matching number" << endl;
	else
		cout << "\nYou have " << matches << " matching numbers" << endl;

	// Determine whether the user won the grand prize.
	if (matches == 5)  //if the number of matching is 5 then congrats.
		cout << "Congratulations! You won the grand prize!";

		return 0;
}

// *******************************************************
// The generateNumbers function generates random numbers *
// and stores them in the lottery array.                 *
// *******************************************************
void generateNumbers(int lottery[], int size)
{
	// Seed the random number generator.
	srand(time(0));

	// Generate the random numbers between 0 to 9.
	for (int i = 0; i < size; i++)  // i = 0, 1, 2, 3, 4
	{
		//Store the random number in lottery[i]
		lottery[i] = rand()%MAX_RANGE;
	}
}

// *******************************************************
// The getUser function gets the user's lottery picks.   *
// *******************************************************
void getUser(int user[], int size)
{
	int x;
	//Prompt the user to enter 5 numbers between 0 ~ 9
	cout << "Input 5 numbers (0 - 9):" << endl;

	// Get the user's picks.
	for (int i = 0; i < size; i++)  // i = 0, 1, 2, 3, 4
	{
		cin >> x;
		user[i] = x;
	}
}

//*******************************************************
//The findMatches function finds the number of the      *
//user's values that match the lottery numbers. The     *
//number of matches is returned.                        *
//*******************************************************
int findMatches(int lottery[], int user[], int size)
{
	// Declare a counter for holding the  number of matching and set to zero
	int matches = 0; // Counter for matching numbers. Start with 0

	// Search for matches.
	for (int i = 0; i < size; i++)
	{
		if (lottery[i] == user[i])
			matches++;
	}

	// Return the number of matching numbers.
	return matches;

}

// *******************************************************
// The displayValues function displays the values in the *
// lottery array and the user array.                     *
// *******************************************************
void displayValues(int lottery[], int user[], int size)
{
	// Display the lottery numbers.
	cout << "Lottery numbers:\n";
	for (int i = 0; i < SIZE; i++)
		cout << lottery[i];

	// Display the user's numbers.
	cout << "\nYour numbers:\n";
	for (int i = 0; i < SIZE; i++)
		cout << user[i];
}

