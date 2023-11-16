//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 8 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Mar 28, 2022											        		//
 //	File Name:				LAB8.cpp, Money.h, Money.cpp										    //
//																									//
//	Purpose of Program:																				//
//		This program demonstrates separate compilation              			                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//DISPLAY 11.8 Overloading << and >>
//Program to demonstrate the class Money.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;
#include "Money.h" //Money ADT

//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digitToInt('3') returns 3.

int main()
{
    Money amount;
    ifstream inStream;
    ofstream outStream;

    inStream.open("infile.dat");
    if (inStream.fail())
    {
        cout << "Input file opening failed.\n";
        exit(1);
    }

    outStream.open("outfile.dat");
    if (outStream.fail())
    {
        cout << "Output file opening failed.\n";
        exit(1);
    }


    inStream >> amount;
    outStream << amount
        << " copied from the file infile.dat.\n";
    cout << amount
        << " copied from the file infile.dat.\n";

    inStream.close();
    outStream.close();

    return 0;
}