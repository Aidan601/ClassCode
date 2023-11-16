//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 14      														    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			May 9, 2022		    		    							            //
//	File Name:				LAB14.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates exceptions and templates					   						//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class CheckedArray //Base Class
{
protected:
	int arr[];
public:
	CheckedArray(); //Default Constructor
	int& operator[](int x); //Overloads []
};

class ArrayOutOfRangeError
{};

int CheckIndex(int num, int i) throw (ArrayOutOfRangeError);

int main()
{
	CheckedArray a; //Object of class CheckedArray
	int number;
	int i = 10; //i is an illegal index
	cout << "Input number for array: ";
	cin >> number;
	try
	{
		a[CheckIndex(number, i)] = number;
	}
	catch (ArrayOutOfRangeError) //if illegal index
	{
		cout << "ERROR: a[" << i << "] is an illegal index";
		exit(0);
	}
	cout << "a[" << a[number] << "] is a valid index"; //if legal index
}

CheckedArray::CheckedArray()
{
}

int CheckIndex(int num, int i) throw (ArrayOutOfRangeError)
{
	if (num == i) //if illegal index
		throw ArrayOutOfRangeError(); //throws to catch
	return num;
}

int& CheckedArray::operator[](int x)
{
	return arr[x];
}
