//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Final   															    //
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			May 17, 2022											        		//
//	File Name:				Final(1).cpp															//
//																									//
//	Purpose of Program:																				//
//		Reads file containing scores and outputs the total and average							    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	double total = 0, average = 0, count = 0;
	ifstream text;
	text.open("text.txt"); //Opens text
	if (text.is_open())
	{
		double score;
		while (!text.eof()) //Reads text file
		{
			text>>score;
			total = total + score; //Accumulates the total score
			count++; //Adds number of scores
		}
	}
	else //If file failed to open
		exit(EXIT_FAILURE);
	text.close();
	average = total / count; //Calculates average
	cout << "Total Score: " << total << endl;
	cout << "Average: " << average << endl;
	return 0;
}
