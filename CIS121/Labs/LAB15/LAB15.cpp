//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Spring 2021													//
//																									//
//	Type of Assignment:		Lab 15																	//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			December 12, 2021														//
//	Project Name:			LAB15(1)																//
//	File Name:				LAB15(1).cpp															//
//																									//
//	Purpose of Program:																				//
//		Finds root(s) using the quadratic formula													//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

class QuadraticEquation
{
private:
	double a,b,c;
public:
	//Default Constructor
	QuadraticEquation();

	//Constructor
	QuadraticEquation(double a, double b, double c);

	//Mutators
	void setA(double a);
	void setB(double b);
	void setC(double c);

	//Accessors
	double getA();
	double getB();
	double getC();
	double getDiscriminant();
	double getRoot1();
	double getRoot2();
};

// Main Program
int main()
{

	// Variable Declarations
	double a, b, c;

	//Declare Object
	QuadraticEquation quad;

	// Output Identification
	system("CLS");
	cout << "Lab 15 Exercise #2 by Aidan Sullivan - "
		<< "Quadratic Class\n\n";

	cout << "Please enter value for a, b and c: ";
	cin >> a >> b >> c;

	quad.setA(a);
	quad.setB(b);
	quad.setC(c);

	cout << "The coefficients for a, b and c are: " << a << " " << b << " " << c << endl;

	if (quad.getDiscriminant() > 0)
		cout << "The two roots are " << quad.getRoot1() << " and " << quad.getRoot2();
	else
		if (quad.getDiscriminant() == 0)
			cout << "The root is " << quad.getRoot1();
		else
			cout << "The equation has no roots";


	cout << "\n\nEnd Program.\n";

	return 0;
}

QuadraticEquation::QuadraticEquation()
{
	a = 0;
	b = 0;
	c = 0;
}

QuadraticEquation::QuadraticEquation(double va, double vb, double vc)
{
	a = va;
	b = vb;
	c = vc;
}

void QuadraticEquation::setA(double va)
{
	a = va;
}

void QuadraticEquation::setB(double vb)
{
	b = vb;
}

void QuadraticEquation::setC(double vc)
{
	c = vc;
}

double QuadraticEquation::getA()
{
	return a;
}

double QuadraticEquation::getB()
{
	return b;
}

double QuadraticEquation::getC()
{
	return c;
}

double QuadraticEquation::getDiscriminant()
{
	return (b*b) - (4 * a * c);
}

double QuadraticEquation::getRoot1()
{
	return (-b + sqrt(getDiscriminant())) / (2*a);
}

double QuadraticEquation::getRoot2()
{
	return (-b - sqrt(getDiscriminant())) / (2 * a);
}
