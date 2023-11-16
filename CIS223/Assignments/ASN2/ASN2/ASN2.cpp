//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Assignment 2														    //
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Feb 28, 2022											        		//
//	File Name:				ASN2.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates a custom STL string class						                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class StringSet
{
private:
	vector<char> data;

public:
	StringSet(); //Default Constructor
	StringSet(const char arr[]); //Default Constructor
	~StringSet(); //Deconstructor
	StringSet operator+ (StringSet p);
	StringSet operator* (StringSet p);
	bool operator== (StringSet p);
	friend ostream& operator << (ostream& output, StringSet& p);
	friend istream& operator >> (istream& input, StringSet& p);
};

int main()
{
	
}

StringSet::StringSet()
{
	
}

StringSet::StringSet(const char arr[])
{
	for (int i = 0; i < strlen(arr); i++)
		data.push_back(arr[i]);
}

StringSet::~StringSet()
{
}

ostream& operator << (ostream& output, StringSet& p)
{
	for (int i = 0; i < p.data.size(); i++)
		output << p.data[i];
	return output;
}

istream& operator >> (istream& input, StringSet& p) //BROKEN
{
	p.data.resize(INT_MAX);
	for (int i = 0; i < p.data.size(); i++)
	{
		input >> p.data[i];
		
		if (p.data[i] == '.')
		{
			p.data.resize(i);
			return input;
		}
	}
	return input;
}

StringSet StringSet::operator+(StringSet p)
{
	StringSet temp;
	temp.data.resize(data.size() + p.data.size());
	for (int i = 0; i < temp.data.size(); i++)
		if (i < data.size())
			temp.data[i] = data[i];
		else
			temp.data[i] = p.data[i - data.size()];
	return temp;
}

StringSet StringSet::operator* (StringSet p)
{
	StringSet temp;
	int x = 1;
	temp.data.resize(data.size() + p.data.size());
	for (int i = 1; i < temp.data.size(); i++)
	{
		if (i % 2 == 0)
			temp.data[i] = data[i-x];
		else
		{
			temp.data[i] = p.data[i-x];
			x++;
		}
	}
	return temp;
}

bool StringSet::operator== (StringSet p)
{
	for (int i = 0; i < data.size(); i++)
		if (data[i] != p.data[i])
			return false;
	return true;
}

double cosine_similarity(double* A, double* B, unsigned int Vector_Length)
{
	double dot = 0.0, denom_a = 0.0, denom_b = 0.0;
	for (unsigned int i = 0u; i < Vector_Length; ++i) {
		dot += A[i] * B[i];
		denom_a += A[i] * A[i];
		denom_b += B[i] * B[i];
	}
	return dot / (sqrt(denom_a) * sqrt(denom_b));
}