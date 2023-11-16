//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Midterm																	//
//	Problem Number:			4																		//
//	Author:					Aidan Sullivan															//
//																									//
//	Purpose of Program:																				//
//		To find the student with the highest score and the average score							//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
using namespace std;

// Main Program
int main()
{
	int students, count = 0;
	double score, highscore = 0, averagecalc = 0, average;
	string name, highname;

	cout << "Enter the Number of Students: ";
	cin >> students;
	while (students != 0)
	{
		cout << "What is the students name?: ";
		cin >> name;
		cout << "What is was their score?: ";
		cin >> score;
		if (highscore < score)
		{
			highname = name;
			highscore = score;
		}
		averagecalc = averagecalc + score;
		students--;
		count++;
	}
	average = averagecalc / count;
	cout << "\n" << highname << " had the highest score with " << highscore << endl;
	cout << average << " was the average score";
	cout << "\n\nEnd Program.\n";
	return 0;
}