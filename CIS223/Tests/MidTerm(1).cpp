//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Midterm																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Mar 30, 2022											        		//
//	File Name:				MidTerm.cpp																//
//																									//
//	Purpose of Program:																				//
//		Write code that uses the iterator to display all the values stored in the vector			//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> numbers {2,4,6,8,10};
	vector<int>::iterator iter;
	
	//Write code that uses the iterator to display all the values stored in the vector.
	for (iter = numbers.begin(); iter < numbers.end(); iter++)
		cout << *iter << " ";
}