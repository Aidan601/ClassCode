//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Assignment 2															//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 5, 2022		    									        		//
//	File Name:				Step1.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program tests all the member functions and overloaded operators for class StirngSet    //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include "StringSet.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	StringSet test1;
	StringSet test2;
	string search;

	//Tests >> operator
	cout << "Input 3 words for test file 1" << endl;
	cin >> test1; cin >> test1; cin >> test1;
	cout << "\nInput 3 words for test file 2" << endl;
	cin >> test2; cin >> test2; cin >> test2;

	//Tests remove function
	test1.remove("goodbye");
	//Tests add function
	test2.add("hello");

	//Tests output function
	cout << "\nTest File 1:" << endl; 
	test1.output();
	//Tests << operator
	cout << "\nTest File 2:" << endl << test2;

	//Tests == operator
	if (test1 == test2)
		cout << "\nThe files are the same" << endl;
	else
		cout << "\nThe files are not the same" << endl;

	//Tests + operator
	StringSet sum = test1 + test2;
	cout << "\nThe combination of the test files are:" << endl << sum;

	//Tests * operator
	StringSet product = test1 * test2;
	cout << "\nThe instercting valuse are:" << endl << product;

	//Tests search function
	cout << "\nSearh File 1: ";
	cin >> search;
	if (test1.search(search) != -1)
		cout << search << " was found at " << test1.search(search) << endl;
	else
		cout << search << " was not found" << endl;

	//Tests size function
	cout << "\nSize of File 1: " << test1.size() << endl;
	cout << "Size of File 2: " << test2.size() << endl;

	//Tests clear function
	test1.clear();
	test2.clear();
	cout << test1;
	cout << test2;

	return 0;
}