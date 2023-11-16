// Aidan Sullivan
// 4-8-2023
//Chapter 7 Assignment

// 7.1 - Sort the sequence 3,1,4,1,5,9,2,6,5 using insertion sort
#include <iostream>
#include <vector>

template <typename Comparable>
void insertionSort(std::vector<Comparable>& a) //Insertion Sort Function
{
	for (int p = 1; p < a.size(); ++p)
	{
		Comparable tmp = std::move(a[p]);
		int j;
		for (j = p; j > 0 && tmp < a[j - 1]; --j)
			a[j] = std::move(a[j - 1]);
		a[j] = std::move(tmp);
	}
	for (int p = 1; p < a.size(); ++p)
	{
		std::cout << a[p];//Outputs sorted sequence
	}
}

int main()
{
	std::vector<int> a = { 3,1,4,1,5,9,2,6,5 }; //Creates vector of the sequence
	insertionSort(a); //Sorts vector in the insertionSort function
}

// 7.17 - Determine the running time of mergesort for sorted input, reverse-ordered input, and random input
//a. O(n*logn)
//b. O(n*logn)
//c. O(n*logn)