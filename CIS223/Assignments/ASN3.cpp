//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-223 Spring 2022													//
//																									//
//	Type of Assignment:		Assignment 3															//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			April 28, 2022   														//
//	Project Name:			ASN3																	//
//	File Name:				ASN3.cpp																//
//																									//
//	Purpose of Program:																				//
//		Tracks who is logged into each computer and simulates login using linked list               //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

struct Node
{
    int data;//Location
    int ID; //User ID
    Node* link;
};
typedef Node* nodePtr;
nodePtr head;

bool search(Node* head, int ID); //Searches for ID and returns true or false
void push(int data, int ID); //Pushes data and ID into linked list
void searchoutput(Node* head, int ID); //Searches and outputs ID location
void remove(int ID); //Removes element from the linked list
void Display(Node* head, int data); //Displays all the computer stations

//Prints ID Number or Empty for each array
void Display(Node* head, int data) //Displays all the computer stations
{
    bool t = false;
    int w;
    Node* current = head; // Initialize current
    while (current != NULL)
    {
        if (current->data == data)
        {
            t = true;
            w = current->ID;
        }
        current = current->link;
    }
    if (t)
        cout << w;
    else
        cout << "empty";
}

bool search(Node* head, int data) //Searches for data and returns true or false
{
    Node* current = head; // Initialize current
    if (data > 20)
    {
        while (current != NULL)
        {
            if (current->ID == data)
                return true;
            current = current->link;
        }
        return false;
    }
    else
    {
        while (current != NULL)
        {
            if (current->data == data)
                return true;
            current = current->link;
        }
        return false;
    }
}

void push(int data, int ID) //Pushes data and ID into linked list
{
    nodePtr temp = new Node();
    if (!temp)
    {
        cout << "ERROR";
        exit(1);
    }
    else
    {
        temp->data = data;
        temp->ID = ID;
    }
    temp->link = head;
    head = temp;
}

void searchoutput(Node* head, int ID) //Searches and outputs ID location
{
    Node* current = head; // Initialize current
    int lab = 0, y = 0;
    bool t = false;
    while (current != NULL)
    {
        if (current->ID == ID)
        {
            t = true;
            y = current->data;
            cout << ID << " is located at Lab ";
            if (y < 6)
                lab = 1;
            else if (y < 12)
            {
                lab = 2;
                y = y - 5;
            }
            else if (y < 16)
            {
                lab = 3;
                y = y - 11;
            }
            else
            {
                lab = 4;
                y = y - 15;
            }
            cout << lab << " Station Number " << y << endl; //Prints ID and location
        }
        current = current->link;
    }
    if (!t)
        cout << ID << " is not signed into a computer." << endl; //Prints that the ID was not found
}

void remove(int ID) //Removes element from the linked list
{
    bool t = false;
    for (int i = 0; i < 4; i++)
    {
        nodePtr temp = head;
        while (temp != NULL)
        {
            if (temp->ID == ID)
            {
                temp->ID = NULL;
                temp->data = NULL;
                t = true;
                break;
            }
            temp = temp->link;
        }
        if (t)
        {
            break;
        }
    }
    if (t == true)
    {
        cout << ID << " has been logged off" << endl;;
    }
    else
        cout << ID << " is already logged out." << endl;
}

int main()
{
    int choice = 0;
    int ID, lab, number;
    int total = 0;

    nodePtr tmp;
    tmp = head;

    //Loops while not quitting
    while (choice != 4)
    {
        int loop = 0; //Resets loops
        cout << "Main Menu\n";
        cout << "1. Login" << endl;
        cout << "2. Logout" << endl;
        cout << "3. Search" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;

        while (choice > 4 || choice < 1) //Checks if choices is valid
        {
            cout << "Invalid Input. Try again." << endl;
            cin >> choice;
        }

        //Choice 1: Login
        if (choice == 1)
        {
            cout << "Enter the ID number of the user" << endl;
            cin >> ID;
            while (ID > 99999 || ID < 10000) //Checks if ID is valid
            {
                cout << "ERROR: Invalid ID input. Try again." << endl;
                cin >> ID;
            }

            // Sees if ID is already logged in            
            if (search(head,ID) == true) //If already logged in
            {
                cout << "ID is already logged into a computer" << endl;
                loop++;
            }
           
            if (loop == 1)
            {
                loop--;
                continue;
            }

            cout << "Enter the lab number" << endl;
            cin >> lab;
            while (lab > 4 || lab < 1) //Checks if lab number is valid
            {
                cout << "ERROR: Invalid lab number. Try again." << endl;
                cin >> lab;
            }
            cout << "Enter the computer station number" << endl;
            cin >> number;
            if (lab == 1) //Checks if computer station number is valid in Lab 1
            {
                while (number > 5 || number < 1)
                {
                    cout << "ERROR: Invalid computer station number. Try again." << endl;
                    cin >> number;
                }
                total = number;
            }
            if (lab == 2) //Checks if computer station number is valid in Lab 2
            {
                while (number > 6 || number < 1)
                {
                    cout << "ERROR: Invalid computer station number. Try again." << endl;
                    cin >> number;
                }
                total = number + 5;
            }
            if (lab == 3) //Checks if computer station number is valid in Lab 3
            {
                while (number > 4 || number < 1)
                {
                    cout << "ERROR: Invalid computer station number. Try again." << endl;
                    cin >> number;
                }
                total = number + 11;
            }
            if (lab == 4) //Checks if computer station number is valid in Lab 4
            {
                while (number > 3 || number < 1)
                {
                    cout << "ERROR: Invalid computer station number. Try again." << endl;
                    cin >> number;
                }
                total = number + 15;
            }
           
            if (search(head,total) == false) //Checks to see if empty 
                push(total, ID); //Assigns ID to station
            else
                cout << "ERROR: Another ID is already signed into this station" << endl;
        }

        //Chioce 2: Logout
        if (choice == 2)
        {
            cout << "Enter the User ID" << endl;
            cin >> ID;
            while (ID > 99999 || ID < 10000) //While ID is not 5 digits long
            {
                cout << "ERROR: Invalid ID input. Try again." << endl;
                cin >> ID;
            }
            remove(ID); 
        }

        //Choice 3: Search
        if (choice == 3)
        {
            cout << "Enter the User ID" << endl;
            cin >> ID;
            searchoutput(head, ID);
        }

        //Choice 4: Quit
        if (choice == 4)
            break;

        //Prints Labs after each loop
        cout << "\nLAB" << endl;
        cout << "Lab Number\tComputer Stations Numbers" << endl;
        cout << "1\t\t1: ";  Display(head, 1); cout << " 2: ";  Display(head, 2); cout << " 3: "; Display(head, 3); cout << " 4: "; Display(head, 4); cout << " 5: ";  Display(head, 5); cout << endl;
        cout << "2\t\t1: ";  Display(head, 6); cout << " 2: ";  Display(head, 7); cout << " 3: "; Display(head, 8); cout << " 4: "; Display(head, 9); cout << " 5: ";  Display(head, 10); cout << " 6: ";  Display(head, 11); cout << endl;
        cout << "3\t\t1: ";  Display(head, 12); cout << " 2: ";  Display(head, 13); cout << " 3: ";  Display(head, 14); cout << " 4: ";  Display(head, 15);  cout << endl;
        cout << "4\t\t1: ";  Display(head, 16); cout << " 2: ";  Display(head, 17); cout << " 3: ";  Display(head, 18); cout << endl; cout << endl;
    }
    return 0;
}