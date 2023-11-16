//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab	4 																    //
//	Problem Number			4																		//
//	Author:					Aidan Sullivan 									 		    			//
//	File Name:				LAB4(3).cpp																//
//																									//
//	Purpose of Program:																				//
//		Creates an array of a user inputted size with random integers in each element.			    //
//		Outputs both arrays and checks if the pointer worked.									  	//
//																									//
//  Algorithm:																						//
//    1. Ask the user to enter the size of the array they want 								        //
//    2. Pass that value to the random function														//
//    3. Fill in each element with a random integer from 1-100										//
//    4. Return a pointer points to the array that was just created									//
//    5. Assign the returned pointer from the function to the new array								//
//    6. Output each value of the new arrayb														//
//    7. Free the memory allocated for the new array back to the freestore							//
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Section
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Prototype
int* getRandomNumbers(int num);
void displayArray(int* arr, int size);

//Main Program
int main()
{
	//Variable Declaration
	int* array;							//The variable to receive the pointer from the randomArray function
	int size;					//The user inputted size of the random array

	//Output Identification
	system("CLS");
	cout << "Lab #4 by Aidan Sullivan - "
		<< "Experiment 4 Programming Exercise\n\n";

	//Asks the user for the size of the array
	cout << "Enter the size of the array: ";
	cin >> size;

	//Input validation loop. Checks to see if the user input is negative
	if (size < 0)
	{
		cout << "Invalid Input. Array can't be negative. Try again.";
		cout << "Enter the size of the array";
		cin >> size;
	}

	//Call the random function to get a random array of 10 numbers
	array = getRandomNumbers(size);
	//Display the passed array and check if it matches with the original
	displayArray(array, size);


	//Free the memory allocated for the new array
	delete array;
}

//Function description
//.....
int* getRandomNumbers(int num)
{
	//Create a pointer variable 
	int* point;


	//Allocate memory to the dynamic array
	point = new int[num];


	//seeds the random function
	srand(time(0));


	//assigns a random number for each element of the array
	for (int x = 0; x < num; x++)
	{
		point[x] = 1+(rand() % 100);
	}

	//Outputs the randomly generated array for testing purposes
	cout << "The random array is: ";
	for (int x = 0; x < num; x++)
	{
		cout << point[x] << " ";
	}
	cout << endl;
	//Returns the pointer points to the array back to the calling function
	return point;
}

void displayArray(int* arr, int size)
{
	//Output the dynamic allocated array 
	cout << "The random array is: ";
	for (int x = 0; x < size; x++)
	{
		cout << arr[x] << " ";
	}
	cout << endl;
}