//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 7																	//
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			September 30, 2021														//
//	Project Name:			Rock, Paper, Scissors Game												//
//	File Name:				LAB7(1).cpp															    //
//																									//
//	Purpose of Program:																				//
//		User inputs Rock, Paper, or Scissors and program also selects one at random					//
//		and displays the winner																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

// Function Prototypes
int getUserChoice(int PlayerChoice); //void getUserChoice ( int& ); is the alternate prototype
int getComputerChoice();
void determineWinner(int PlayerChoice, int CPUChoice);
void displayChoice(int choice);
bool loop = true;

// Main Program
int main()
{
	// Output Identification
	system("CLS");
	cout << "Lab 7 Exercise #3 by Aidan Sullivan - "
		<< "Rock, Paper, Scissors Game\n";
	while (loop == true)
	{
		int PlayerChoice = 0;
		PlayerChoice = getUserChoice(PlayerChoice);
		if (loop == false) //Breaks loop if player from chose to quit from getUserChoice
		{
			return 0;
		}
		cout << "You selected: ";
		displayChoice(PlayerChoice);
		cout << "\nThe computer selected: ";
		int CPUChoice = getComputerChoice();
		displayChoice(CPUChoice);
		determineWinner(PlayerChoice, CPUChoice);
	}

}

//Displays Menu and allows Player input
int getUserChoice(int PlayerChoice)
{
	cout << "\n\nGame Menu\n";
	cout << "---------\n";
	cout << "1) Rock\n";
	cout << "2) Paper\n";
	cout << "3) Scissors\n";
	cout << "4) Quit\n";
	cout << "\nEnter your choice (1-4): "; //If the user enters 4, the program should end.
	cin >> PlayerChoice;
	while (PlayerChoice > 4 || PlayerChoice < 1)
	{
		cout << "\nERROR: Input outside range 1-4. Try Again.";
		cout << "\nEnter your choice (1-4): ";
		cin >> PlayerChoice;
	}
	if (PlayerChoice == 4)
	{
		cout << "\nEnd Program.\n";
		loop = false;
		return 0;
	}
	return PlayerChoice;
}

//Computer choses a number 1 - 3
int getComputerChoice()
{
	int CPUChoice = rand() % 3 + 1;
	return CPUChoice;
}

//Determines the Winner
void determineWinner(int PlayerChoice, int CPUChoice)
{
	if (PlayerChoice == 1 && CPUChoice == 2)
	{
		cout << "\nComputer wins! Paper wraps Rock";
	}
	else if (PlayerChoice == 1 && CPUChoice == 3)
	{
		cout << "\nYOU win! Rock beats Scissors";
	}
	else if (PlayerChoice == 2 && CPUChoice == 1)
	{
		cout << "\nYou win! Paper wraps Rock";
	}
	else if (PlayerChoice == 2 && CPUChoice == 3)
	{
		cout << "\nComputer wins! Scissors cut Paper";
	}
	else if (PlayerChoice == 3 && CPUChoice == 1)
	{
		cout << "\nComputer wins! Rock beats Scissors";
	}
	else if (PlayerChoice == 3 && CPUChoice == 2)
	{
		cout << "\nYOU win! Scissors cut Paper";
	}
	else
	{
		cout << "\nTie. No winner.";
	}
}

//Helps display the choice from the main function
void displayChoice(int choice)
{
	switch (choice) 
	{
	case 1:
		cout << "Rock";
		break;
	case 2:
		cout << "Paper";
		break;
	case 3:
		cout << "Scissors";
		break;
	}
}
