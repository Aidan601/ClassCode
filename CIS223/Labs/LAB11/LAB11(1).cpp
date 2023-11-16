//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 11 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 18, 2022				    							            //
//	File Name:				LAB11(1).cpp															//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates the different amount of comparisons between sort functions.	  	//
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <ctime>
using namespace std;

const int MaxElements = 100; //Max number of elements for array

void generteSample(int sample[], int n); // Generate a set of valuse of a centain size. Produces an array that is used to initialize the sets in our experiment
void run(int sample[], int n); //run function for a specific sorting algorithm
int bubblesort(int arr[], int length); //BubbleSort
int selectionSort(int sample[], int n); //SelectionSort
int partition(int arr[], int start, int end); //Partition for QuickSort
int quickSort(int arr[], int start, int end); //QuickSort

int main()
{
	clock_t before;
	clock_t after;
	double result;
	int i;
	int n; //size
	int sample[MaxElements];

	cout << "Enter size of set: ";
	cin >> n;
	if (n >= MaxElements) {
		cout << "set size must be less than " << MaxElements << "\n";

		system("PAUSE");
		exit(1);
	}

	generteSample(sample, n);

	before = clock();

	for (i = 0; i < 100; i++) {
		run(sample, n);  //run function for a specific sorting algorithm
	}

	after = clock();

	result = static_cast<double>(after - before) / CLOCKS_PER_SEC;

	cout << before << " " << after << "\n";

	cout << result << "\n";

	system("PAUSE");
	return EXIT_SUCCESS;
}

/*
 * generateSample: Generate a set of valuse of a centain size. Produces an
 * array that is used to initialize the sets in our experiment.
	 */

void generteSample(int sample[], int n)
{
	int i;
	int r;
	i = 0;
	srand(time(0));
	while (i < n)
	{
		r = rand() % 10000;
		sample[i] = r;
		i++;
	}
}

void run(int sample[], int n)
{
	//cout << "Bubble Sort Comparisions: " << bubblesort(sample, n) << endl;
	cout << "Selection Sort Comparisions: " << selectionSort(sample, n) << endl;
	//cout << "QuickSort Comparisions: " << quickSort(sample, 0, n - 1) << endl;
}

int bubblesort(int arr[], int length) //Bubble Sort
{
	int comparisons = 0;
	// Bubble largest number toward the right
	for (int i = length - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
		{
			comparisons++; //Counts comparison
			if (arr[j] > arr[j + 1])
			{
				// Swap the numbers
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	return comparisons;
}

int selectionSort(int sample[], int n) //Selection Sort
{
	int i, x, comparisons = 0;
	for (i = 0; i < n; i++)
	{
		for (x = 0; x < i; x++)
		{
			comparisons++; //Counts comparison
			if (sample[i] > sample[x])
			{
				int temp = sample[i];
				sample[i] = sample[x];
				sample[x] = temp;
			}
		}
	}
	return comparisons;
}

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

int quickSort(int arr[], int start, int end)
{
	int comparisons = 0;
	int x;
	if (start < end)
	{
		comparisons++; //counts comparison
		x = partition(arr, start, end); //Puts into partition function
		quickSort(arr, start, x - 1); //Recursion
		quickSort(arr, x + 1, end); //Recursion
	}
	return comparisons;
}