//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 6																	//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			September 25, 2021														//
//	Project Name:			LAB6																	//
//	File Name:				LAB6.cpp																//
//																									//
//	Purpose of Program:																				//
//		Calculates the areas of various shapes														//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

//Function declaration


// Main Program
int main()
{
	// Constant Declarations
	const double PI = 3.1415926535;	// the radius/diameter of a circle

	// Variable Declarations
	int choice = 0, repeatcase = 0;
	double radius, length, width, area, base, height;
	char repeat;

	// Output Identification
	system("CLS");
	cout << "Lab 6 Exercise #1 by Aidan Sullivan - "
		<< "Geomotry Calculator";
	while (choice != 4)
	{
		cout << "\nGeometry Calculator\n";
		cout << "1. Calculate the Area of a Rectangle\n";
		cout << "2. Calculate the Area of a Triangle\n";
		cout << "3. Calculate the Area of a Circle\n";
		cout << "4. Quit\n\n";
		cout << "Enter your choice (1-4): ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "\nEnter the length of the rectangle: ";
			cin >> length;
			while (length <= 0)
			{
				cout << "ERROR: Input is a negative number. Try again.";
				cout << "\nEnter the length of the rectangle: ";
				cin >> length;
			}
			cout << "Enter the width of the rectangle: ";
			cin >> width;
			while (width <= 0)
			{
				cout << "ERROR: Input is a negative number. Try again.";
				cout << "\nEnter the length of the rectangle: ";
				cin >> width;
			}
			area = length * width;
			cout << "The area of the rectangle is " << area;
		}
		else if (choice == 2)
		{
			cout << "\nEnter the length of the triangles base: ";
			cin >> base;
			while (base <= 0)
			{
				cout << "ERROR: Input is a negative number. Try again.";
				cout << "\nEnter the length of the rectangle: ";
				cin >> base;
			}
			cout << "Enter the height of the triangle: ";
			cin >> height;
			while (height <= 0)
			{
				cout << "ERROR: Input is a negative number. Try again.";
				cout << "\nEnter the length of the rectangle: ";
				cin >> height;
			}
			area = base * height * .5;
			cout << "The area of the triangle is " << area;
		}
		else if (choice == 3)
		{
			cout << "\nWhat is the radius of the circle: ";
			cin >> radius;
			while (radius <= 0)
			{
				cout << "ERROR: Input is a negative number. Try again.";
				cout << "\nEnter the length of the rectangle: ";
				cin >> radius;
			}
			area = PI * pow(radius, 2);
			cout << "The area of the circle is " << area;
		}
		else if (choice == 4)
		{
			cout << "\nEnd Program.\n";
			return 0;
		}
		else
		{
			cout << "ERROR: Number input outside the range of 1 - 4.";
		}
		repeatcase = 0;
		while (repeatcase == 0)
		{
			cout << "\n\nDo you wish to continue? (Y/N): ";
			cin >> repeat;
			switch (repeat)
				{
				case 'Y':
					repeatcase++;
					break;
				case 'y':
					repeatcase++;
					break;
				case 'N':
					choice = 4;
					repeatcase++;
					break;
				case 'n':
					choice = 4;
					repeatcase++;
					break;
				default:
					cout << "\nERROR: Invalid input. Try again.";
			}

		}
	}
	cout << "\nEnd Program.\n";
	return 0;
}

