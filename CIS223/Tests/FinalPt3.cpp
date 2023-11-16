//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Final   															    //
//	Problem Number:			5																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			May 17, 2022											        		//
//	File Name:				Final(2).cpp															//
//																									//
//	Purpose of Program:																				//
//		Function takes integer input and returns the square root if its a perfect square			//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <math.h>
using namespace std;

int SquareRoot(int input); //Square Root function

int main()
{
	int input;
	cout << "Input a number to square root: ";
	cin >> input;
	cout << SquareRoot(input);
}

int SquareRoot(int input)
{
	try
	{
		if (input == (sqrt(input) * sqrt(input))) //If input is a perfect square
			return sqrt(input); //Returns sqaure root of input
		else throw input; //If input is not a perfect square
	}
	catch (int x) //Catches input from throw
	{
		cout << "The square root of " << x << " is not a perfect square";
		exit(1);
	}
}
