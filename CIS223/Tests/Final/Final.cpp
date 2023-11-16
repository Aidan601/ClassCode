//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Final   															    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			May 17, 2022											        		//
//	File Name:				Final.cpp																//
//																									//
//	Purpose of Program:																				//
//		Reverses a text file into another file									                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

class Stack
{
private:
	typedef struct node
	{
		char data;
		node* next;
	}*nodePtr;

	nodePtr top;

public:
	Stack(); //Default Constructor
	void push(char data); //Push
	int pop(ofstream& file); //Pop
};


int main()
{
	Stack p;
	ifstream input;
	ofstream output;
	string in = "input.txt";
	string out = "output.txt";
	input.open(in);
	try
	{
		if (!input.is_open())
			throw in; //Failed to open input.txt
		else
		{
			char letter;
			while (input)
			{
				letter = input.get();
				p.push(letter);
			}
		}
		input.close();
		output.open(out);
		if (output.is_open())
			p.pop(output);
		else
			throw out; //Failed to open output.txt
		output.close();
	}
	catch (string x)
	{
		cout << x << " failed to open.";
		exit(1);
	}
	cout << "Word has been reversed";
	return 0;
}

Stack::Stack() //Default Constructor
{
	top = NULL;
}

void Stack::push(char data) //Push
{
	nodePtr temp = new node();
	if (!temp)
	{
		cout << "ERROR";
		exit(1);
	}
	else
		temp->data = data;
	temp->next = top;
	top = temp;
}

int Stack::pop(ofstream& file) //Pop
{
	nodePtr temp;
	if (top == NULL)
	{
		cout << "ERROR";
		exit(1);
	}
	else
	{
		temp = top;
		temp = temp->next;
		while (temp != NULL)
		{
			file << temp->data;
			temp = temp->next;
		}
	}
}
