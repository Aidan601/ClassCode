//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 																    //
//	Problem Number:			2																	    //
//	Section Number			N/A																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			September 30, 2021														//
//	Project Name:			LAB7								    							    //
//	File Name:				LAB7.cpp																//
//																									//
//	Purpose of Program:																				//
//		Output a menu of 4 choices, have the user choose one of the choices and find the area	    //
//		of the respective shape using values inputted from the user. The choices should be			//
//		rectangle, triangle, circle, and a choice to exit the program.								//
//																									//
//  Algorithm:																						//
//    1. Display the menu with the 4 choices                                                        //
//    2. Ask the user to input their choice															//
//        If 1: select rectange:																	//
//            Ask the user to input width and length												//
//            Check the width and length are positive												//
//            Calculate the area.   area = length* width									    	//
//        If 2: select triangle:																	//
//            Ask the user to input base and height													//
//            Make sure the input values are positive												//
//            Calculate the area.   area = base * height * 0.5								    	//
//        If 3: select rectange:																	//
//            Ask the user to input radius															//
//            Check the radius are positive															//
//            Calculate the area (pi * radius^2) 													//
//        If 4: exit the program													   				//
//    3. Display the result																			//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

// Function declaration
void showMenu();
double rectangle(double len, double wid);
double triangle(double base, double height);
double circle(double r);

//Global Constant 
const double PI = 3.14159;		//global constant 

// Main Program
int main()
{
	//Variable Declaration
	int choice;			//To hold the user's choice
	double width,		//To hold the width of a rectangle
		length,			//To hold length of a rectangle
		area,			//To hold area of a given shape
		base,			//To hold base of a triangle
		height,			//To hold the height of a triangle
		radius;			//To hold the radius of a circle

	// Output Identification
		system("CLS");
	cout << "Lab #7 by Aidan Sullivan - "
		<< "Geometry Calculator\n";

	// Display the menu and get a choice.
	showMenu();								 //Call function showMenu to display the menu
	cout << "Please enter your selection (1-4): ";
	cin >> choice;								//  read the user's choice 

	// Respond to the user's menu selection.
	// Calculate the area
	switch (choice)
	{
		//If the user enters 1, it is a rectangle
	case  1:
		//Read the length and the width from the user: 
		cout << "\nEnter the length of the rectangle: ";
		cin >> length;
		cout << "Enter the width of the rectangle: ";
		cin >> width;

	   //Input validataion
		while (length <= 0 || width <= 0)
		{
			cout << "ERROR: Input includes a negative number. Try again.";
			cout << "\nEnter the length of the rectangle: ";
			cin >> length;
			cout << "Enter the width of the rectangle: ";
			cin >> width;
		}

		//Compute the area and display the result
		area = rectangle(length, width);
		cout << "The area of the rectangle is " << area;
		break;

		//If the user enters 2, calculate a triangle
	case 2:
		//Read the base and the height of a triangle 
		cout << "\nEnter the length of the triangles base: ";
		cin >> base;
		cout << "Enter the height of the triangle: ";
		cin >> height;

		//Checks the entered value is negative number
		while (base <= 0 || height <= 0)
		{
			cout << "ERROR: Input includes a negative number. Try again.";
			cout << "\nEnter the length of the triangles base: ";
			cin >> base;
			cout << "Enter the height of the triangle: ";
			cin >> height;
		}

		//Compute the area and display the result
		area = triangle(base, height);
		cout << "The area of the triangle is " << area;
		break;

	//If the user enters 3, it is a circle
	case 3:
		cout << "\nWhat is the radius of the circle: ";
		cin >> radius;
		while (radius <= 0)
		{
			cout << "ERROR: Input is a negative number. Try again.";
			cout << "\nWhat is the radius of the circle: ";
			cin >> radius;
		}
		area = circle(radius);
		cout << "The area of the circle is " << area;
		break;

		//If the user enters 4, quit the program
	case 4:
		cout << "\nEnd Program.\n";
		break;

	default:
		cout << "ERROR: Number input outside the range of 1 - 4.";
		break;
	}

	cout << "\nThe end of program.\n";
	return 0;
}

//The function will print out the menu and return no value 
void showMenu()
{
	cout << "\nGeometry Calculator\n";
	cout << "1. Calculate the Area of a Rectangle\n";
	cout << "2. Calculate the Area of a Triangle\n";
	cout << "3. Calculate the Area of a Circle\n";
	cout << "4. Quit\n\n";
}

//This function accepts two double arguments, the length and the width 
//of the ractangle. It returns the area of the ractangle. 
double rectangle(double len, double wid)
{
	return len * wid;
}

//This function accepts two double arguments, the base and the height 
//of a triangle. It returns the area of the triangle. 
double triangle(double base, double height)
{
	return base * height * .5;
}

//This function accepts one double argument, the radius of a circle. 
// It returns the area of the cirlce.
double circle(double r)
{
	return PI * pow(r, 2);
}