//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 9 																    //
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 6, 2022				    							        		//
//	File Name:				LAB9(1).cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates the function search.              			                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream> 
#include <cstddef> 
#include <string> 
using namespace std;

struct Node
{
    string item;
    int count;
    Node* link;
};

typedef Node* NodePtr;
NodePtr search(NodePtr head, string an_item);
void head_insert(NodePtr& head, string an_item, int a_number);
void show_list(NodePtr& head);

int main()
{
    string input;
    NodePtr head = NULL;
    head_insert(head, "Tea", 2);
    head_insert(head, "Jam", 3);
    head_insert(head, "Rolls", 10);
    show_list(head);

    cout << "Search for word (case sensitive): ";
    cin >> input;
    NodePtr result = search(head, input);
    if (result == NULL)
        cout << input << " was not found." << endl;
    else
        cout << input << " was found!" << endl;
    return 0;
}


NodePtr search(NodePtr head, string target) 
{
    NodePtr head1 = head; //Make the pointer variable here point to the head node (that is, the first node) of the linked list. 
    while (head1->item != target && head1->link != NULL)
        head1 = head1->link;
    if (head1->item == target)
        return head1;
    else
        return NULL;
}


void head_insert(NodePtr& head, string an_item, int a_number)
{
    NodePtr temp_ptr;
    temp_ptr = new Node;
    temp_ptr->item = an_item;
    temp_ptr->count = a_number;
    temp_ptr->link = head;
    head = temp_ptr;
}

void show_list(NodePtr& head) //Displays the list
{
    NodePtr head1 = head;
    while (head1 != NULL)
    {
        cout << head1->item << " " << head1->count << endl;
        head1 = head1->link;
    }
}
