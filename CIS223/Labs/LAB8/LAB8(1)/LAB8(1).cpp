//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 8 																    //
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Mar 28, 2022											        		//
 //	File Name:				LAB8(1).cpp, ID.h, ID.cpp, Loan.h, Loan.cpp 							//
//																									//
//	Purpose of Program:																				//
//		To seperate program into 5 different files								                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////
// This program is a driver written to demonstrate how we can use a 
// class inside another one. 
#include <iostream> 
using namespace std;
#include "ID.h"
#include "Loan.h"


int main()
{
	Loan loan1(ID(111, 22, 4444), 2300, 5.5, 48); // initialize to values given
	Loan loan2;
	cout << "Display loan1 \n";
	loan1.display();
	loan2.set(); // set the values 
	cout << "Display loan2 \n";
	loan2.display();
	return 0;
}