//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 5 																    //
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Feb 28, 2022											        		//
 //	File Name:				LAB5(1).cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates the vector member functions.					                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> values;

	// Store values in the vector.
	values.push_back(1);
	values.push_back(2);
	values.push_back(3);

	cout << "The size of values is " << values.size() << endl;

	// Remove a value from the vector.
	cout << "Popping a value from the vector...\n";
	values.pop_back();
		cout << "The size of values is now " << values.size() << endl;

	// Now remove another value from the vector.
	cout << "Popping a value from the vector...\n";
	values.pop_back();
		cout << "The size of values is now " << values.size() << endl;

	// Remove the last value from the vector.
	cout << "Popping a value from the vector...\n";
	values.pop_back();
		cout << "The size of values is now " << values.size() << endl;

	// Store values in the vector.
	values.push_back(1);
	cout << "I will call the clear member function...\n";
	values.clear();
	cout << "Now, the values vector has "
		<< values.size() << " elements.\n";

	return 0;
}