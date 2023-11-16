//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Spring 2021													//
//																									//
//	Type of Assignment:		Lab 9																	//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Janurary 16, 2021														//
//	Project Name:			Circle																	//
//	File Name:				circleCalc.cpp															//
//																									//
//	Purpose of Program:																				//
//		Put a complete description of the problem here and											//
//		don't worry about using more than one line.													//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include<fstream> // This enables you to do file I/O
#include<iostream> // For cin and cout
#include<cstdlib> // To use exit(1) that terminates the program
#include <string>
using namespace std;

//Function declaration


// Main Program
int main()
{
	int a,b,c,d,e,f,g,h, sum = 0;
	// Output Identification
	system("CLS");
	cout << "Lab 9 Exercise #1 by Aidan Sullivan - "
		<< "Integers\n";

	ifstream input;
	input.open("input.txt");
	
	if (input.fail()) 
	{
		cerr << "Error Opening File" << endl;
		exit(1);
	}
	
	input >> a >> b >> c >> d >> e >> f >> g >> h;
	input.close();

	ofstream output;
	output.open("output.txt");

	output << " x	x^2	Current Sum\n===	===	===========";
	sum = sum + a;
	output << "\n " << a << "	" << pow(a, 2) << "	    " << sum;
	sum = sum + b;
	output << "\n " << b << "	" << pow(b, 2) << "	    " << sum;
	sum = sum + c;
	output << "\n " << c << "	" << pow(c, 2) << "	    " << sum;
	sum = sum + d;
	output << "\n " << d << "	" << pow(d, 2) << "	    " << sum;
	sum = sum + e;
	output << "\n " << e << "	" << pow(e, 2) << "	    " << sum;
	sum = sum + f;
	output << "\n " << f << "	" << pow(f, 2) << "	    " << sum;
	sum = sum + g;
	output << "\n " << g << "	" << pow(g, 2) << "	    " << sum;
	sum = sum + h;
	output << "\n " << h << "	" << pow(h, 2) << "	    " << sum << endl;
	output << "The average of these 8 numbers is: " << sum / 8 << endl;
	output << "The sum of these 8 numbers is: " << sum << endl;
	output.close();
	
	cout << "\nProgram Complete.\n";

	return 0;
}

