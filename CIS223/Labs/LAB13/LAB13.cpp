//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 13 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 26, 2022				    							            //
//	File Name:				LAB13.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates polymorphism and virtual functions		   						//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

class Ship //Base Class
{
protected:
	string name;
	string year;
public:
	Ship(); //Default Constructor
	Ship(string n, string y); //Constructor

	//Mutators
	void setName(string n);
	void setYear(string y);

	//Accesors
	string getName();
	string getYear();

	//Print Function
	virtual void Print();
};

class CruiseShip : public Ship //Derived Class
{
private:
	int max;
public:
	CruiseShip(); //Default Constructor
	CruiseShip(string n, string y, int m); //Constructor

	//Mutators
	void setMax(int m);

	//Accesors
	int getMax();

	//Print Function
	virtual void Print();
};

class CargoShip : public Ship //Derived Class
{
private:
	int capacity;
public:
	CargoShip(); //Default Constructor
	CargoShip(string n, string y, int c); //Constructor

	//Mutators
	void setCapacity(int c);

	//Accesors
	int getCapacity();

	//Print Function
	virtual void Print();
};


int main()
{
	Ship* array[3]; //Array of ship pointers
	array[0] = new Ship("Lolipop", "1960"); //Ship Object
	array[1] = new CruiseShip("Disney Magic", "1998", 2400); //CruiseShip Object
	array[2] = new CargoShip("Black Pearl", "1800", 50000); //CargoShip Object
	for (int i = 0; i < 3; i++)
		array[i]->Print();
}

Ship::Ship()
{
	name = "";
	year = "";
}

Ship::Ship(string n, string y)
{
	name = n;
	year = y;
}

void Ship::setName(string n)
{
	name = n;
}

void Ship::setYear(string y)
{
	year = y;
}

string Ship::getName()
{
	return name;
}

string Ship::getYear()
{
	return year;
}

void Ship::Print()
{
	cout << "Name: " << name << endl;
	cout << "Year built: " << year << endl;
	cout << "----------------------------" << endl;
}

CruiseShip::CruiseShip()
{
	max = 0;
}

CruiseShip::CruiseShip(string n, string y, int m)
{
	name = n;
	year = y;
	max = m;
}

void CruiseShip::setMax(int m)
{
	max = m;
}

int CruiseShip::getMax()
{
	return max;
}

void CruiseShip::Print()
{
	cout << "Name: " << name << endl;
	cout << "Maximum passengers: " << max << endl;
	cout << "----------------------------" << endl;
}

CargoShip::CargoShip()
{
	name = "";
	capacity = 0;
}

CargoShip::CargoShip(string n, string y, int c)
{
	name = n;
	year = y;
	capacity = c;
}

void CargoShip::setCapacity(int c)
{
	capacity = c;
}

int CargoShip::getCapacity()
{
	return capacity;
}

void CargoShip::Print()
{
	cout << "Name: " << name << endl;
	cout << "Cargo capacity: " << capacity << " tons" << endl;
	cout << "----------------------------" << endl;
}
