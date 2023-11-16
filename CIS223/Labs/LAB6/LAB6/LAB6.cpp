//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 6 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			March 11, 2022											        		//
 //	File Name:				LAB6.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates overloading operators >> and <<				                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream> 
#include<cstdlib> 
#include<fstream> 
using namespace std;
class AltMoney
{
public:
	AltMoney();
	friend istream& operator>>(istream& ins, AltMoney& m); //Overload >>
	friend AltMoney operator +(AltMoney m1, AltMoney m2);
	friend ostream& operator<<(ostream& ous, AltMoney& m); //Overload <<
private:
	int dollars;
	int cents;
};

void get_streams(ifstream& ins, ofstream& ous);
int main()
{
	ifstream ins;
	ofstream ous;
	AltMoney m1, m2, sum;
	get_streams(ins, ous);
	ins >> m1;
	ous << "The first money is:";
	ous << m1;
	ins >> m2;
	ous << "The second money is:";
	ous << m2;
	sum = m1 + m2;
	ous << "The sum is:";
	ous << sum;
	ins.close();
	ous.close();
	return 0;
}

AltMoney::AltMoney()
{
}

istream& operator>>(istream& ins, AltMoney& m)
{
	int d, c;
	ins >> d;
	ins >> c;
	if (d < 0 || c < 0)
	{
		cout << "Invalid dollars and cents, negative values\n";
		exit(1);
	}
	m.dollars = d;
	m.cents = c;
	return ins;
}

AltMoney operator +(AltMoney m1, AltMoney m2)
{
	AltMoney temp;
	int extra = 0;
	temp.cents = m1.cents + m2.cents;
	if (temp.cents >= 100) {
		temp.cents = temp.cents - 100;
		extra = 1;
	}
	temp.dollars = m1.dollars + m2.dollars + extra;
	return temp;
}

ostream& operator<<(ostream& ous, AltMoney& m)
{
	ous << "$" << m.dollars << ".";
	if (m.cents <= 9)
		ous << "0"; //to display a 0 on the left for numbers less than 10 
	ous << m.cents << endl;
	return ous;
}

void get_streams(ifstream& ins, ofstream& ous)
{
	ins.open("in_file.dat");
	if (ins.fail())
	{
		cout << "Failed to open the input file. \n";
		exit(1);
	}
	ous.open("out_file.dat");
	if (ous.fail())
	{
		cout << "Failed to open the output file. \n";
		exit(1);
	}
}
