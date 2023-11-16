// Aidan Sullivan
// 2-17-2023
//Chapter 2 Assignment

#include <iostream>
#include <chrono>

int Program(int program, int n)
{
	int sum = 0;
	
	//Get Start Time
	auto start = std::chrono::steady_clock::now();

	if (program == 1)
	{
		for (int i = 0; i < n; i++)
			sum++;
	}
	if (program == 2)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				sum++;
	}
	if (program == 3)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n * n; j++)
				sum++;
	}
	if (program == 4)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				sum++;
	}
	if (program == 5)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i * i; j++)
				for (int k = 0; k < j; k++)
					sum++;
	}
	if (program == 6)
	{
		for (int i = 1; i < n; i++)
			for (int j = 1; j < i * i; j++)
				if (j % i == 0)
					for (int k = 0; k < j; k++)
						sum++;
	}
	//Get End Time and Find the Difference
	auto end = std::chrono::steady_clock::now();
	double elapsed_time_ns = double(std::chrono::duration_cast <std::chrono::nanoseconds> (end - start).count());
	return elapsed_time_ns;
}

int main()
{
	//Get input of times
	std::cout << Program(1, 10) << std::endl;
	std::cout << Program(1, 100) << std::endl;
	std::cout << Program(1, 1000) << std::endl;
	std::cout << Program(1, 10000) << std::endl;
}