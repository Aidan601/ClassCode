#include "StringSet.h"
#include <iostream>
#include <vector>
using namespace std;

StringSet::StringSet() //Default Constructor
{
}

StringSet::~StringSet() //Destructor
{
	data.clear();
}

StringSet::StringSet(string arr[]) //Takes as an input parameter an array of strings for the initial values in the set
{
	for (int i = 0; i < sizeof(arr); i++)
		data.push_back(arr[i]);
}

void StringSet::add(string str) //Adds a string to the set
{
	data.push_back(str);
}

void StringSet::remove(string str) //Removes a string from the set
{
	for (int i = 0; i < data.size(); i++)
		if (data[i] == str)
			data.erase(data.begin() + i);
}

void StringSet::clear() //clear the entire set to empty
{
	data.clear();
}

int StringSet::search(string str) //Search for a string
{
	for (int i = 0; i < data.size(); i++)
		if (data[i] == str)
			return i;
	return -1;
}

int StringSet::size() //Returns size of strings in set
{
	return data.size();
}

void StringSet::output() //Outputs all strings in the set
{
	for (int i = 0; i < data.size(); i++)
		cout << data[i] << endl;
}

StringSet StringSet::operator+(StringSet p) //Overloads the + operator
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

StringSet operator*(StringSet& set1, StringSet& set2) //Overloads the * operator
{
	StringSet temp;
	for (int i = 0; i < set1.data.size(); i++)
		for (int x = 0; x < set2.data.size(); x++)
			if (set1.data[i] == set2.data[x])
				temp.add(set1.data[i]);
	return temp;
}

ostream& operator <<(ostream& output, StringSet& p) //Overloads the << operator
{
	for (int i = 0; i < p.data.size(); i++)
		output << p.data[i] << endl;
	return output;
}

istream& operator>>(istream& input, StringSet& p) //Overloads the >> operator
{
	string s;
	input >> s;
	p.data.push_back(s);
	return input;
}

bool StringSet::operator == (StringSet& p) //Overloads the == operator
{
	if (data.size() == p.data.size())
	{
		for (int i = 0; i < data.size(); i++)
			if (data[i] != p.data[i])
				return false;
	}
	else
		return false;
	return true;
}
