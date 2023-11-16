//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Midterm																    //
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Mar 30, 2022											        		//
//	File Name:				MidTerm.cpp																//
//																									//
//	Purpose of Program:																				//
//		Finds area of circle (not finished)										                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

const double pi = 3.14159265358979323846;

class Circle
{
public:
	Circle();
	Circle(double r);
	double getArea();
	double getRadius();
	void setRadius(double r);
	friend ostream& operator << (ostream& output, Circle& c);
private:
	double radius;
};

int main()
{

}

Circle::Circle()
{
	radius = 0;
}

Circle::Circle(double r)
{
	radius = r;
}

double Circle::getArea()
{
	return pi * radius * radius;
}

double Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(double r)
{
	radius = r;
}

ostream& operator<<(ostream& output, Circle& c)
{
	output << "Radius: " << c.getRadius() << endl;
	output << "Area: " << c.getArea();
	return output;
}
