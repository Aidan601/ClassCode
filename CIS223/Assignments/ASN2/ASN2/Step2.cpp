//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Assignment 2															//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 5, 2022		    									        		//
//	File Name:				Step2.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program compares an input of StringSet to 2 documents using binary cosine coefficent   //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include "StringSet.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

string OnlyLetters(string str); //Removes anything that isn't a letter

int main()
{
	StringSet doc1, doc2, query;
	ifstream inStream;
	string str;
	double coefficient1, coefficient2;

	//Doc 1
	inStream.open("doc1.txt"); //Opens doc1
	if (inStream.fail()) //If doc1 is not found
	{
		cout << "Doc1 file opening failed." << endl;
		exit(1);
	}
	while (!inStream.eof())
	{
		inStream >> str;
		transform(str.begin(), str.end(), str.begin(), tolower); //Converts string into all lowercase
		doc1.add(OnlyLetters(str)); //Adds string into StringSet doc1
	}
	inStream.close();//Closes doc1

	//Doc 2
	inStream.open("doc2.txt"); //Opens doc2
	if (inStream.fail()) //If doc2 is not found
	{
		cout << "Doc2 file opening failed." << endl;
		exit(1);
	}
	while (!inStream.eof())
	{
		inStream >> str;
		transform(str.begin(), str.end(), str.begin(), tolower); //Converts string into all lowercase
		doc2.add(OnlyLetters(str)); //Adds string into StringSet doc2
	}
	inStream.close(); //Closes doc2

	//Query
	cout << "Input query one word at a time (Enter nothing to stop): " << endl;
	do //While input is not blank
	{
		getline(cin, str); //Input string
		transform(str.begin(), str.end(), str.begin(), tolower); //Converts string into all lowercase
		if (str != string("")) //if not blank
			query.add(OnlyLetters(str)); //Adds string to StringSet query
	} while (str != string(""));

	coefficient1 = (doc1 * query).size() / (sqrt(doc1.size()) * sqrt(query.size())); //Calculate the binary cosine coefficient for doc1
	coefficient2 = (doc2 * query).size() / (sqrt(doc2.size()) * sqrt(query.size())); //Calculate the binary cosine coefficient for doc2
	cout << "The binary cosine coefficient of document 1 is " << coefficient1 << endl;
	cout << "The binary cosine coefficient of document 2 is " << coefficient2 << endl;
	return 0;
}

string OnlyLetters(string str) //Removes anything that isn't a letter
{
	for (int i = 0; i < str.size(); i++) 
	{
		if (!isalpha(str[i])) // If its not a letter
		{
			str.erase(i, 1); //Erase
			i--;
		}
	}
	return str;
}