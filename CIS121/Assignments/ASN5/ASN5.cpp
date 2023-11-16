//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Assignment 5															//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			December 14, 2021														//
//	Project Name:			ASN5																	//
//	File Name:				ASN5.cpp																//
//																									//
//	Purpose of Program:																				//
//		Calculates the monthly payment on a home mortgage											//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

class Mortgage
{
public:
    // Constructors
	Mortgage(double l, double r, double y);
	Mortgage();

    // Mutators
	void setLoan(double l);
	void setRate(double r);
	void setYear(double y);

    // Accessors
	double getPayment();
	double getLoan();
	double getRate();
	double getYear();
	double getTerm();
	double getTotal();

private:
    double loan;   // Dollar amount of the loan
    double rate;  // Annual interest rate
    double year;  // Number of years of the loan
};

// Main Program
Mortgage Input(Mortgage mort) //Reads inputs
{
	double loan, rate, year;
	cout << "Enter the loan amount($): ";
	cin >> loan;
	cout << "Enter the annual interest rate(%): ";
	cin >> rate;
	cout << "Enter the number of years: ";
	cin >> year;
	mort.setLoan(loan);
	mort.setRate(rate);
	mort.setYear(year);
	return mort;
}

void Output(Mortgage mort) //Outputs solution
{
	cout << "\nLoan: $" << mort.getLoan() << endl;
	cout << "Rate: " << mort.getRate()*100 << "%" << endl;
	cout << "Years: " << mort.getYear() << endl;
	cout << "Monthly Payment: $" << mort.getPayment() << endl;
	cout << "Total Payment: $" << mort.getTotal() << endl;
}

int main()
{

	// Variable Declarations
	double loan = 0, rate = 0, year = 0;
	Mortgage mort;

	// Output Identification
	system("CLS");
	cout << "Assignment 5 Exercise #2 by Aidan Sullivan - "
		<< "House Mortgage\n\n";
	
	mort = Input(mort);
	Output(mort);

	cout << "\nEnd Program.\n";

	return 0;
}

Mortgage::Mortgage(double l, double r, double y)
{
	loan = l;
	rate = r;
	year = y;
}

Mortgage::Mortgage()
{
	loan = 0.0;
	rate = 0.0;
	year = 0.0;
}

void Mortgage::setLoan(double l)
{
	if (l >= 0)
		loan = l;
	else
	{
		cout << "Invalid Loan\n";
		exit(EXIT_FAILURE);
	}
}

void Mortgage::setRate(double r)
{
	if (r >= 0)
		rate = r/100;
	else
	{
		cout << "Invalid Rate\n";
		exit(EXIT_FAILURE);
	}
}

void Mortgage::setYear(double y)
{
	if (y >= 0)
		year = y;
	else
	{
		cout << "Invalid Year\n";
		exit(EXIT_FAILURE);
	}
}

double Mortgage::getPayment()
{
	return (loan * (rate/12) * getTerm())/(getTerm()-1); //Payment Equation
}

double Mortgage::getLoan()
{
	return loan;
}

double Mortgage::getRate()
{
	return rate;
}

double Mortgage::getYear()
{
	return year;
}

double Mortgage::getTerm() //For getPayment
{
	return pow((1+(rate/12)),12*year);
}

double Mortgage::getTotal()
{
	return year*12*getPayment();
}