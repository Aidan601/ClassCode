//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 4 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Feb 22, 2022												        	//
 //	File Name:				LAB4.cpp																//
//////////////////////////////////////////////////////////////////////////////////////////////////////
// This program demonstrates the use of pointer variables
// It finds the area of a rectangle given length and width
// It prints the length and width in ascending order

#include <iostream> 
using namespace std;
int main()
{
	int length; // holds length
	int width; // holds width
	int area; // holds area 
	int* lengthPtr; // int pointer which will be set to point to length
	int* widthPtr; // int pointer which will be set to point to width 

	cout << "Please input the length of the rectangle" << endl;
	cin >> length;
	cout << "Please input the width of the rectangle" << endl;
	cin >> width;

	// Fill in code to make lengthPtr point to length (hold its address)
	lengthPtr = &length;


	// Fill in code to make widthPtr point to width (hold its address) 
	widthPtr = &width;

	// Fill in code to find the area by using only the pointer variables
	area = *lengthPtr * *widthPtr;


	cout << "The area is " << area << endl;
		
	// 	Fill in the condition length > width by using only the pointer variables
	if (*lengthPtr > *widthPtr)

		cout << "The length is greater than the width" << endl;


	// Fill in the condition of width > length by using only the pointer variables
	else if (*lengthPtr < *widthPtr)
		cout << "The width is greater than the length" << endl;
	else
		cout << "The width and length are the same" << endl;
		return 0;
}

