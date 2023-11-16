#include "StringSet.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	StringSet doc1, doc2, query;
	ifstream in_stream;
	string str;

	//Doc 1
	in_stream.open("doc1.txt");
	if (in_stream.fail())
	{
		cout << "Input file opening failed." << endl;
		exit(-1);
	}
	while (!in_stream.eof())
	{
		in_stream >> str;
		doc1.add(str);
	}
	in_stream.close();

	//Doc 2
	in_stream.open("doc2.txt");
	if (in_stream.fail())
	{
		cout << "Input file opening failed." << endl;
		exit(-1);
	}
	while (!in_stream.eof())
	{
		in_stream >> str;
		doc2.add(str);
	}
	in_stream.close();

	//Query
	cout << "Enter set of keywords for the query." << endl;
	cout << "Enter keywords, one per line. Enter a blank line when finished." << endl;
	do
	{
		getline(cin, str);
		if (str != string(""))
			query.add(str);
	} while (str != string(""));

	StringSet intersect1 = doc1 * query;
	StringSet intersect2 = doc2 * query;

	double sim1 = intersect1.size() / (sqrt(doc1.size()) * sqrt(query.size()));
	double sim2 = intersect2.size() / (sqrt(doc2.size()) * sqrt(query.size()));
	cout << "The similarity to document 1 is " << sim1 << endl;
	cout << "The similarity to document 2 is " << sim2 << endl;
	return 0;
}