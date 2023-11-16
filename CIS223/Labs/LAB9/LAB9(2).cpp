//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 9 																    //
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 6, 2022				    							        		//
//	File Name:				LAB9(2).cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates linked lists and member functions.      							//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <cstddef> 
#include <string> 
using namespace std;

class LinkedList 
{
private:
	typedef struct node 
	{
		int data;
		node* next;
	}* nodePtr;
	
	nodePtr head;
	nodePtr curr;
	nodePtr temp;
	nodePtr next;



public:
	void add(double x); //Adds node containing x
	void remove(double x); //Removes node containing x
	void print(); //Prints list
	void reverse(); //Reverses order of list
	void search(double x); //Searches if x is in list
	bool isMember(double x); //Searches if x is in list
	LinkedList(); //Default Constructor
	~LinkedList(); //Deconstructor
};

int main() //Menus for functions
{
	LinkedList list;
	int choice = 0;
	double input;
	while (choice != 6)
	{
		cout << "\nMain Menu:" << endl;
		cout << "1. Add to List" << endl;
		cout << "2. Remove from list" << endl;
		cout << "3. Print list" << endl;
		cout << "4. Reverse list" << endl;
		cout << "5. Search for data in list" << endl;
		cout << "6. Quit" << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "\nInput number: ";
			cin >> input;
			list.add(input);
		}
		if (choice == 2)
		{
			cout << "\nInput number: ";
			cin >> input;
			list.remove(input);
		}
		if (choice == 3)
			list.print();
		if (choice == 4)
			list.reverse();
		if (choice == 5)
		{
			cout << "\nInput number: ";
			cin >> input;
			list.search(input);
		}
		if (choice == 6)
			break;
	}
	return 0;
}

void LinkedList::add(double x) //Adds node containing x
{
	nodePtr n = new node;
	n->data = x;
	n->next = head;
	head = n;
}

void LinkedList::remove(double x) //Removes node containing x
{
	nodePtr xPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != x)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout << x << " does not exist in the list." << endl;
		delete xPtr;
	}
	else
	{
		xPtr = curr;
		curr = curr->next;
		temp->next = curr;
		delete xPtr;
		cout << x << " sucessfully deleted." << endl;
	}
}

void LinkedList::print() //Prints list
{
	cout << "\n";
	curr = head;
	while (curr != NULL)
	{
		cout << curr->data << endl;
		curr = curr->next;
	}
}

void LinkedList::reverse() //Reverses order of list
{
	curr = head;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = temp;
		temp = curr;
		curr = next;
	}
	head = temp;
	cout << "List has been reveresed" << endl;
}

void LinkedList::search(double x) //Searches if x is in list
{
	nodePtr xPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != x)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		cout << x << " was not found." << endl;
	else
		cout << x << " was found!" << endl;
}

bool LinkedList::isMember(double x) //Searches if x is in list
{
	nodePtr xPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != x)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		return false;
	else
		return true;
}

LinkedList::LinkedList() //Default Constructor
{
	head = NULL;
	curr = NULL;
	temp = NULL;
	next = NULL;
}

LinkedList::~LinkedList() //Deconstructor
{

}
