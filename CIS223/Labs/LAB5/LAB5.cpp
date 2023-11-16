//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 5 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Feb 28, 2022											        		//
 //	File Name:				LAB5.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates the vector's empty member function.			                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

// Function prototype
double avgVector(vector<int>);

int main()
{
	vector<int> vect;   // A vector to hold values
	int numValues;       // The number of values
	double average;      // To hold the average

	// Get the number of values to averge.
	cout << "How many values do you wish to average? ";
	cin >> numValues;

	// Get the values and store them in the vector.
	for (int count = 0; count < numValues; count++)
	{
		int x; 		//fill in the blank
		cout << "Number " << count+1 << ":" << endl;
		cin >> x;
		vect.push_back(x);
	}

	// Get the average of the values and display it.
	average = avgVector(vect);
	cout << "Average: " << average << endl;
	return 0;
}

//*************************************************************
// Definition of function avgVector.                          *
// This function accepts an int vector as its argument. If    *
// the vector contains values, the function returns the       *
// average of those values. Otherwise, an error message is    *
// displayed and the function returns 0.0.                    *
//*************************************************************

double avgVector(vector<int> vect)
{
	double total = 0;    // accumulator
	double avg = 0;       // average

	if (vect.size() == 0) // Determine if the vector is empty
	{
		cout << "ERROR: Vector contains no values";
		return 0;
	}
	else
	{
		for (unsigned int count = 0; count < vect.size(); count++)
			total += vect[count];
		avg = total / vect.size();

	}
	return avg;
}