//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 10 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 11, 2022				    							            //
//	File Name:				LAB10.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates stacks using linked lists			    							//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <fstream>
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
	int pop(ofstream& file); //Pop
	void push(char data); //Push
	Stack(); //Default Constructor
};


int main()
{
	Stack p;
	ifstream file;
	ofstream file1;
	file.open("input.txt"); //Opens input
	if (file.is_open()) 
	{
		char letter;
		while (file) //Reads input file
		{
			letter = file.get();
			p.push(letter);
		}
	}
	else //If file failed to open
		exit(EXIT_FAILURE);
	file.close();
	file1.open("output.txt"); //Opens output
	if (!file1.is_open()) //If file failed to open
		exit(EXIT_FAILURE);
	else
		p.pop(file1); //Reverses file
	file1.close();
	cout << "Word was reversed!";
	return 0;
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
			file << temp->data; //Inputs into file
			temp = temp->next;
		}
	}
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

Stack::Stack() //Default Constructor
{
	top = NULL;
}
