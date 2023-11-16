//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Spring 2021													//
//																									//
//	Type of Assignment:		Assignment 4															//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			November 23, 2021														//
//	Project Name:			ASN4																	//
//	File Name:				ASN4.cpp																//
//																									//
//	Purpose of Program:																				//
//		Allows two players to play tic-tac-toe														//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

// Main Program
int main()
{
	// Variable Declarations
	char ttt[3][3] = { '*','*','*','*','*','*','*','*','*' }; 
	char player = 'O';
	int row, column, turn = 0;
	bool win = false;

	// Output Identification
	system("CLS");
	cout << "Assignment 4 Exercise #2 by Aidan Sullivan - "
		<< "Tic-Tac-Toe Game\n";

	while (win == false)
	{
		int valid = false;
		
		// Prints Chart
		cout << "\n      Columns" << endl;
		cout << "       1 2 3" << endl;
		cout << "Row 1: " << ttt[0][0] << " " << ttt[0][1] << " " << ttt[0][2] << endl;
		cout << "Row 2: " << ttt[1][0] << " " << ttt[1][1] << " " << ttt[1][2] << endl;
		cout << "Row 3: " << ttt[2][0] << " " << ttt[2][1] << " " << ttt[2][2] << endl;

		// Switches Players 
		if (player == 'O')
			player = 'X';
		else
			player = 'O';

		while (valid == false)
		{
			// Player inputs row and column
			cout << "\nPlayer " << player << "'s turn." << endl;
			cout << "Enter a row and column to place an " << player << '.' << endl;
			cout << "Row: ";
			cin >> row;
			cout << "Column: ";
			cin >> column;

			// Checks if input is valid
			if (3 >= row >= 1 && 3 >= column >= 1 && ttt[row - 1][column - 1] == '*')
			{
				ttt[row - 1][column - 1] = player;
				valid = true;
			}
			else
				cout << "Invalid Input. Try Again." << endl;

		}
		
		// Checks if there is a winner
		for (int i = 0; i < 2; i++) 
		{
			if (ttt[i][0] == player && ttt[i][1] == player && ttt[i][2] == player || ttt[0][i] == player && ttt[1][i] == player && ttt[2][i] == player
				|| ttt[0][0] == player && ttt[1][1] == player && ttt[2][2] == player || ttt[0][2] == player && ttt[1][1] == player && ttt[2][0] == player)
			{
				win = true;
				break;
			}
		}
		turn++;
		
		// Creates tie
		if (turn == 9)
			win = true;

	}

	// Displays winner
	cout << "\n      Columns" << endl;
	cout << "       1 2 3" << endl;
	cout << "Row 1: " << ttt[0][0] << " " << ttt[0][1] << " " << ttt[0][2] << endl;
	cout << "Row 2: " << ttt[1][0] << " " << ttt[1][1] << " " << ttt[1][2] << endl;
	cout << "Row 3: " << ttt[2][0] << " " << ttt[2][1] << " " << ttt[2][2] << endl;
	if (turn == 9) // If Tie
		cout << "No winner. Tie.";
	else
		cout << "Player " << player << " Wins!";

	cout << "\n\nEnd Program.\n";

	return 0;
}