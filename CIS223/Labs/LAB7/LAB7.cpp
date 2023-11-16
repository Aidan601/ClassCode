//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 7 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			March 12, 2022											        		//
 //	File Name:				LAB7.cpp																//
//																									//
//	Purpose of Program:																				//
//		Uses pointer array to find higest, lowest, and average number of an array	                //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class NumberArray
{
public:
	// The constructor  accepts an integer argument and dynamically allocate memory
	NumberArray(int s);

	// Destructor
	~NumberArray();

	// Mutator
	void setCell(int p, double n);

	// Accessor
	int getCell(int p);

	double average(); //Gets average
	double highest(); //Gets highest number
	double lowest(); //Gets lowest number

private:
	double* arrayPointer;
	int size;

};

int main()
{
	int size, number;
	cout << "How many numbers would you want to store? ";
	cin >> size;
	NumberArray arr(size);
	cout << "Enter the " << size << " numbers:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "\tNumber " << i+1 << ": ";
		cin >> number;
		arr.setCell(i, number); //Stores part of Array
	}
	cout << "\n";
	cout << "Here are the values you entered:" << endl;
	for (int i = 0; i < size; i++)
		cout << "\tNumber " << i + 1 << ": " << arr.getCell(i) << endl; //Lists Array
	cout << "\n";
	cout << "The highest of those values is " << arr.highest() << endl;
	cout << "The lowest of those values is " << arr.lowest() << endl;
	cout << "The average of those values is " << arr.average() << endl;
}

NumberArray::NumberArray(int s)
{
	size = s;
	arrayPointer = new double[s];
}

NumberArray::~NumberArray()
{
	delete[] arrayPointer;
}

void NumberArray::setCell(int p, double n)
{
	*(arrayPointer + p) = n;
}

int NumberArray::getCell(int p)
{
	return *(arrayPointer + p);
}

double NumberArray::average()
{
	double average = 0;
	for (int i = 0; i < size; i++)
		average = average + *(arrayPointer + i);
	average = average / size;
	return average;
}

double NumberArray::highest()
{
	double highest = -INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (highest < *(arrayPointer + i))
			highest = *(arrayPointer + i);
	}
	return highest;
}

double NumberArray::lowest()
{
	double lowest = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (lowest > *(arrayPointer + i))
			lowest = *(arrayPointer + i);
	}
	return lowest;
}
