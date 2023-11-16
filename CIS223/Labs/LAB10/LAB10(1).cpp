//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 10 																    //
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 11, 2022				    							            //
//	File Name:				LAB10(1).cpp															//
//																									//
//	Purpose of Program:																				//
//		Calculates problems using the Reverse Polish Notation		    							//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
using namespace std;

class Stack
{
private:
	typedef struct node
	{
		int data;
		node* next;
	}*nodePtr;

	nodePtr top;

public:
	int pop(); //Pop
	void push(int data); //Push
	Stack(); //Default Constructor
};


int main()
{
	Stack rpn;
	char input = '0';
	int number;
	while (input != 'q')
	{
		cin >> input;
		
		if (isdigit(input)) //If a number is input, push it on the stack.
		{
			number = input - 48; //Converts char into int
			rpn.push(number);
		}

		if (input == '+') //If “+” is input then pop the last two operands off the stack, add them, and push the result on the stack.
		{
			rpn.push(rpn.pop() + rpn.pop());
		}
		
		if (input == '-') //If “-” is input, then pop value1, pop value2, then push value2-value1 on the stack.
		{
			rpn.push(rpn.pop() - rpn.pop());
		}

		if (input == '*') //If “*” is input, then pop the last two operands off the stack, multiply them, and push the result on the stack.
		{
			rpn.push(rpn.pop() * rpn.pop());
		}

		if (input == '/') //If “/” is input, then pop value1, pop value2, then push value2/value1on the stack.
		{
			int value1 = rpn.pop();
			int value2 = rpn.pop();
			rpn.push(value2 / value1);
		}

		if (input == 'q') //If “q” is input, then stop inputting values, print out the top of the stack, and exit the program.
		{
			cout << "\nThe top of the stack is: " << rpn.pop();
		}

	}
	return 0;
}

int Stack::pop() //Pop
{
	nodePtr temp;
	if (top == NULL) //Output an appropriate error message if there are not two operands on the stack when given an operator
	{
		cout << "ERROR: NEED TWO OPERANDS ON THE STACK";
		exit(1);
	}
	else
	{
		temp = top;
		top = top->next;
		return temp->data;
	}
}

void Stack::push(int data) //Push
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
