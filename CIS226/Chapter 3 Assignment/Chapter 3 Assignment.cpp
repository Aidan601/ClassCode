// Aidan Sullivan
// 3-28-2023
// Chapter 3 Assignment - Josephus Problem

#include <iostream>

int main()
{
    int m = 1; //number of passes
    int n = 5; //number of people
    
    if (n <= 0 || m < 0) //Exits if variables have invalid values
    {
        std::cout << "ERROR: Insufficent values";
        return 0;
    }

    struct node //Node of Linked List
    {
        int data;
        node* next;
    };

    node* x; //Linked List
    node* head; //Head
    node* temp; //Temporary

    x = new node; //Creates first value of linked list
    x->data = 1;
    temp = x;
    head = x;

    for (int i = 2; i <= n; i++) //Creates remaining values
    {
        x = new node;
        x->data = i;
        temp->next = x;
        if (i == n) // If last value, point to head
            x->next = head;
        else
            temp = temp->next; //point to next node
    }
    x = head;

    std::cout << "Elimination Order: ";
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++) //Simulates Passes
        {
            temp = x; //Saves previous node
            x = x->next; //Pass
        }
        std::cout << x->data << " "; //Eliminated Node Output
        x = temp;
        x->next = x->next->next;//Deletes node in list
        x = x->next;
    }
    std::cout << "\n" << x->data << " Wins!" << std::endl; //Final Output
}

//Questions
// B. O(nm)
// C. O(n). The larger values of n, the actual speed would be slower because the larger n will be the larger the runtime is.
