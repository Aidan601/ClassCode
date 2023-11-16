//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Midterm																    //
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Mar 30, 2022											        		//
//	File Name:				MidTerm.cpp																//
//																									//
//	Purpose of Program:																				//
//		Display roots of data fields a, b, and c								                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

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
	QuadraticEquation(double av, double bv, double cv);

	//Mutators
	void setA(double av);
	void setB(double bv);
	void setC(double cv);

	//Accesors
	double getA();
	double getB();
	double getC();

	double getDiscriminant();
	double getRoot1();
	double getRoot2();
};

int main()
{
	double a,b,c;
	QuadraticEquation q;
	cout << "Enter a:" << endl;
	cin >> a;
	cout << "Enter b:" << endl;
	cin >> b;
	cout << "Enter c:" << endl;
	cin >> c;
	q.setA(a);
	q.setB(b);
	q.setC(c);
	if (q.getDiscriminant() > 0)
		cout << "The roots are " << q.getRoot1() << " and " << q.getRoot2();
	else
		if (q.getDiscriminant() == 0)
			cout << "The root is " << q.getRoot1();
		else cout << "The equation has no roots";
}

QuadraticEquation::QuadraticEquation()
{
	a = 0;
	b = 0;
	c = 0;
}

QuadraticEquation::QuadraticEquation(double av, double bv, double cv)
{
	a = av;
	b = bv;
	c = cv;
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
	return (b * b) - (4 * a * c);
}

double QuadraticEquation::getRoot1()
{
	return (-b + sqrt(getDiscriminant())) / (2 * a);
}

double QuadraticEquation::getRoot2()
{
	return (-b - sqrt(getDiscriminant())) / (2 * a);
}

