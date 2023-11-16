//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 11 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 18, 2022				    							            //
//	File Name:				LAB11.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates the Quicksort algorithm with recursion.	  					    //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

void quickSort(int[], int, int);
int partition(int[], int, int);
void swap(int& value1, int& value2);
int main()
{
    int array[10]{};

    cout << "Enter 10 Numbers in any order: " << endl;
    for (int i = 0; i < 10; i++)
        cin >> array[i]; //Inputs numbers into array
    cout << "Your inputs: ";
    for (int i = 0; i < 10; i++)
        cout << array[i] << " "; //Outputs numbers from array
    cout << "\n";
    quickSort(array, 0, 9); //Puts array into quickSort function
    cout << "In order: ";
    for (int i = 0; i < 10; i++)
        cout << array[i] << " "; //Outputs numbers of array in order
    return 0;
}

//************************************************
// quickSort uses the QuickSort algorithm to     *
// sort arr from arr[start] through arr[end].    *
//************************************************
void quickSort(int arr[], int start, int end)
{
    int x;
    if (start < end)
    {
        x = partition(arr, start, end); //Puts into partition function
        quickSort(arr, start, x - 1); //Recursion
        quickSort(arr, x + 1, end); //Recursion
    }
}

//***********************************************************
// partition rearranges the entries in the array arr from   *
// start to end so all values greater than or equal to the  *
// pivot are on the right of the pivot and all values less  *
// than are on the left of the pivot.                       *
//***********************************************************
int partition(int arr[], int start, int end)
{
    int value = arr[start];
    int position = start;
    for (int pos = start + 1; pos <= end; pos++)
    {
        if (arr[pos] < value)
        {
            swap(arr[position + 1], arr[pos]);
            swap(arr[position], arr[position + 1]);
            position++;
        }
    }
    return position;
}

//***********************************************************
// swap simply exchanges the contens of		   	            * 
// values1 and value2					                    *
//***********************************************************
void swap(int& value1, int& value2)
{
    int value3 = value1;
    value1 = value2;
    value2 = value3;
}
