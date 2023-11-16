//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 14      														    //
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			May 9, 2022		    		    							            //
//	File Name:				LAB14(1).cpp															//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates exceptions and templates					   						//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <fstream>
using namespace std;

class Stack
{
private:
	typedef struct node
	{
		int data;
		node* prev;
	}*nodePtr;

	nodePtr top;

public:
	int pop(); //Pop
	void push(int data); //Push
	Stack(); //Default Constructor
};

class EmptyStackException
{};


int main()
{
	//Pushes three times and pops four to get error
	Stack p;
	p.push(3);
	p.push(2);
	p.push(1);
	p.pop(); //1
	p.pop(); //2
	p.pop(); //3
	p.pop(); //ERROR
}

int Stack::pop() //Pop
{
	nodePtr temp;
	try 
	{
		if (top == NULL)
			throw EmptyStackException(); //Throws to catch
		else
		{
			temp = top;
			cout << temp->data << endl;
			top = top->prev;
			temp->prev = NULL;
		}
	}
	catch (EmptyStackException)
	{
		cout << "ERROR: Stack is empty";
		exit(1);
	}
}

void Stack::push(int data) //Push
{
	nodePtr temp = new node();
	temp->data = data;
	if (top == NULL)
	{
		top = temp;
		top->prev = NULL;
	}
	else
	{
		temp->prev = top;
		top = temp;
	}
}

Stack::Stack() //Default Constructor
{
	top = NULL;
}
