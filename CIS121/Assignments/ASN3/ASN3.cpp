//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Assignment 3															//
//	Problem Number:			1																		//
//	Section Number			101																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			November 2, 2021														//
//	Project Name:			ASN3																	//
//	File Name:				ASN3.cpp																//
//																									//
//	Purpose of Program:																				//
//		Put a complete description of the problem here and											//
//		don't worry about using more than one line.													//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

//Function declaration

//Collects the data
void getData(double& a, double& b, double& c)
{
	cout << "\nEnter side 1: ";
	cin >> a;
	cout << "Enter side 2: ";
	cin >> b;
	cout << "Enter side 3: ";
	cin >> c;
}

//Checks if the the sides make a real triangle
bool isValid(double a,double b,double c)
{
	if ((a + b) > c && (a + c) > b && (b + c) > a)
		return true;
	else
		return false;
}

//Calculates the area and perimeter 
void calcTriangle(double a, double b, double c, double& area, double& prim)
{
	prim = a + b + c;
	int s = (prim) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
}

void displayResult(double area, double prim)
{
	cout << "That triangle has an area of " << area << " and a perimeter of " << prim;
}

// Main Program
int main()
{
	// Variable Declarations
	double a,b,c,area,prim;
	char repeat = 'y';

	// Output Identification
	system("CLS");
	cout << "Assignment 3 Exercise #1 by Aidan Sullivan - "
		<< "Area of Triangle\n";
	while (repeat == 'Y' || repeat == 'y')
	{
		int repeatcase = 0;
		getData(a, b, c);
		if (isValid(a, b, c) == false)
			cout << "The three sides entered do not form a triangle.";
		else
		{
			calcTriangle(a, b, c, area, prim);
			displayResult(area, prim);
		}
		
		while (repeatcase == 0)
		{
			cout << "\nWould you like to run the program again (Y or N)? ";
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
				repeatcase++;
				break;
			case 'n':
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
