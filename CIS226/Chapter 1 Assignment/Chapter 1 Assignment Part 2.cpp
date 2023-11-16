// Aidan Sullivan
// 2-4-2023
//Chapter 1 Assignment Pt 2 - Write a program to solve the selection problem. Let k = N/2.

#include <iostream>
using namespace std;

int main()
{
	int N;
	cout << "Enter the amount of numbers you would like to sort: " << endl;
	cin >> N;
	int k = N / 2;

	int* Array;
	Array = new int[N];

	cout << "Enter one value per row: " << endl;
	for (int i = 0; i < N; i++) //Stores initial values in array
	{
		cin >> Array[i];
	}
	
	//Bubble Sort
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			int temp;
			if (Array[i] > Array[j])
			{
				temp = Array[i];
				Array[i] = Array[j];
				Array[j] = temp;
			}
		}
	}

	//Output
	cout << "\nk = " << k << endl;
	cout << "kth largest in array: " << Array[k-1] << endl;
}