//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Final																	//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			December 16, 2021														//
//	Project Name:			Final(2)																//
//	File Name:				Final(2).cpp															//
//																									//
//	Purpose of Program:																				//
//  Takes three arguments of an array, array size and a number smallest and returns the average and //
//  the smallest number.																			//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

//Function declaration
double average(const int array[], int size, int& smallest);

// Main Program
int main()
{
	// Variable Declarations
	int small = INT_MAX;
	int arr[] = { 10,9,2,3,4 };
	int SIZE = 5;

	// Output Identification
	system("CLS");
	cout << "Final Problem #1 by Aidan Sullivan - "
		<< "Array\n\n";
	
	cout << "Average: " << average(arr, SIZE, small) << endl;
	cout << "Smallest Number: " << small;

	cout << "\n\nEnd Program.\n";

	return 0;
}

double average(const int array[], int size, int& smallest)
{
	int average = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] < smallest)
			smallest = array[i];
		average = array[i] + average;
	}
	return average;
}
