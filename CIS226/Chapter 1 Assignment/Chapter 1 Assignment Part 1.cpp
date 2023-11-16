//Chapter 1 Assignment Pt 1
//Aidan Sullivan
//For the matrix class, add a resize member function and zero-parameter constructor

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
using namespace std;

template <typename Object>
class matrix
{
public:
	//Zero-parameter constructor
	matrix() : array(1)
	{
		for (auto& thisRow : array)
			thisRow.resize(1);
	}
	
	matrix(int rows, int cols) : array(rows)
	{
		for (auto& thisRow : array)
			thisRow.resize(cols);
	}

	matrix(vector<vector<Object>> v) : array{v}
	{ 

	}

	matrix(vector<vector<Object>>&& v) : array{ std::move(v) }
	{
	
	}

	const vector<Object>& operator[](int row) const
	{
		return array[row];
	}

	vector<Object>& operator[](int row)
	{
		return array[row];
	}

	int numrows() const
	{
		return array.size();
	}

	int numcols() const
	{
		return numrows() ? array[0].size() : 0;
	}

	//Resize Member Function
	void resize(int rows, int cols) //New row and columns
	{
		array.resize(rows);
		for (auto& thisRow : array)
			thisRow.resize(cols);
	}
private:
	vector<vector<Object>> array;
};

#endif