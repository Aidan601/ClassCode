//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Lab 14																	//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			December 5, 2021														//
//	Project Name:			LAB14																	//
//	File Name:				LAB14.cpp																//
//																									//
//	Purpose of Program:																				//
//		Outputs Area and Circumference of a circle given a radius									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

//Constant Declaration
const double pi = 3.1415926535;	//global constant

class Circle
{
private:
	double radius;
public:
	//Default Constructor
	Circle();
	
	//Constructor that accepts a value for radius
	Circle(double r);

	//Mutators
	void setRadius(double);
	
	//accessors
	double getRadius() const;
	double getArea() const;
	double getCircumference() const;
};

// Main Program
int main()
{
	//Declare variables
	double mradius;

	//Declare objects of class Circle
	Circle circle;

	//Output Identification
	cout << "Input the radius of the circle: " << endl;

	//Get the inputs from the user
	cin >> mradius;

	//Store radius into the Circle object
	circle.setRadius(mradius);


	//Store the second radius into a new object using the default constructor
	Circle radius = mradius;



	//Display circle's information
	cout << "The circle's area is " << circle.getArea() << endl;
	cout << "The circle's circumference is " << circle.getCircumference() << endl;

	cout << "End Program\n";

	return 0;
}

//Default Constructor
Circle::Circle()
{
	radius = 0.0;
}

//Constructor for the circle that accepts a value for the radius
Circle::Circle(double r)
{
	//Checks to see if the input is negative
	radius = r;

	//If it isn't positive, exit the program
	

}

//Sets or changes the radius for the circle
void Circle::setRadius(double r)
{
	if (r >= 0)
		radius = r;
	else
	{
		cout << "Invalid radius\n";
		exit(EXIT_FAILURE);
	}
}

//Returns the radius of the circle object
double Circle::getRadius() const
{
	return radius;
}

//Returns the area of the circle object
double Circle::getArea() const
{
	return radius * radius * pi;
}

//Returns the Circumference of the circle object
double Circle::getCircumference() const
{
	return radius * 2 * pi;
}