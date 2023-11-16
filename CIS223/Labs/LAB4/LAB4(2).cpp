//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 4 																    //
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Feb 22, 2022												        	//
 //	File Name:				LAB4(2).cpp																//
//////////////////////////////////////////////////////////////////////////////////////////////////////
// This program demonstrates the use of dynamic arrays 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float* monthSales;		// a pointer used to point to an array holding monthly sales 
	float total = 0; // total of all sales
	float average; // average of monthly sales
	int numOfSales; // number of sales to be processed
	int count; // loop counter 

	cout << fixed << showpoint << setprecision(2);
	cout << "How many monthly sales will be processed? ";
	cin >> numOfSales;
	// Fill in the code to allocate memory for the array pointed to by monthSales.
	monthSales = new float[numOfSales];

	if (monthSales == NULL) // Determine if memory has been allocated  
	{
		cout << "Error allocating memory!\n";
		return 1;
	}

	cout << "Enter the sales below\n";
	for (count = 0; count < numOfSales; count++)
	{
		cout << "Sales for Month number "
			<< count+1 // Fill in code to show the number of the month 
			<< ": ";
		// Fill in code to bring sales into an element of the array
		cin >> monthSales[count];
	}

	for (count = 0; count < numOfSales; count++)
	{
		total = total + monthSales[count];
	}
	average = total / count;
		cout << "Average Monthly sale is $" << average << endl;
	// Fill in the code to deallocate memory assigned to the array. 
		delete[] monthSales;
	return 0;
}