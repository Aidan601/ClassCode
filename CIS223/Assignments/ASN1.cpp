//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-223 Spring 2022													//
//																									//
//	Type of Assignment:		Assignment 1															//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			April 20, 2022   														//
//	Project Name:			ASN1																	//
//	File Name:				ASN1.cpp																//
//																									//
//	Purpose of Program:																				//
//		Tracks who is logged into each computer and simulates login                   				//
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

//Prints ID Number or Empty for each array
void Display(int vect)
{
    if (vect == 0)
        cout << "empty";
    else
        cout << vect;
}

int main()
{
    int choice = 0;
    int ID, lab, number;
    vector<vector<int>> vect;
    
    //Resizes vector and sets each element to zero
    vect.resize(4, vector<int>(6, 0));
   
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
            for (int i = 0; i < 4; i++)
            {
                for (int x = 0; x < 6; x++)
                {
                    if (vect[i][x] == ID) //If already logged in
                    {
                        cout << "ID is already logged into a computer" << endl;
                        loop++;
                    }
                }
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
            }
            if (lab == 2) //Checks if computer station number is valid in Lab 2
            {
                while (number > 6 || number < 1)
                {
                    cout << "ERROR: Invalid computer station number. Try again." << endl;
                    cin >> number;
                }
            }
            if (lab == 3) //Checks if computer station number is valid in Lab 3
            {
                while (number > 4 || number < 1)
                {
                    cout << "ERROR: Invalid computer station number. Try again." << endl;
                    cin >> number;
                }
            }
            if (lab == 4) //Checks if computer station number is valid in Lab 4
            {
                while (number > 3 || number < 1)
                {
                    cout << "ERROR: Invalid computer station number. Try again." << endl;
                    cin >> number;
                }
            }
            if (vect[lab - 1][number - 1] == 0) //Checks to see if empty 
                vect[lab - 1][number - 1] = ID; //Assigns ID to station
            else
                cout << "ERROR: Another ID is already signed into this station" << endl;
        }
        
        //Chioce 2: Logout
        if (choice == 2)
        {
            cout << "Which user would you like to logout" << endl;
            cin >> ID;
            while (ID > 99999 || ID < 10000) //While ID is not 5 digits long
            {
                cout << "ERROR: Invalid ID input. Try again." << endl;
                cin >> ID;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int x = 0; x < 6; x++)
                {
                    loop++;
                    if (vect[i][x] == ID)
                    {
                        vect[i][x] = 0; //Emptys array
                        break;
                    }
                    if (loop == 24) //If already logged out
                        cout << ID << " is already logged out." << endl;
                }
            }
        }
        
        //Choice 3: Search
        if (choice == 3)
        {
            cout << "Enter the User ID" << endl;
            cin >> ID;
            while (ID > 99999 || ID < 10000) //While ID is not 5 digits long
            {
                cout << "ERROR: Invalid ID input. Try again." << endl;
                cin >> ID;
            }
            for (int i = 0; i < 4; i++)
            {
                for (int x = 0; x < 6; x++)
                {
                    loop++;
                    if (vect[i][x] == ID)
                    {
                        cout << ID << " is located at Lab " << i + 1 << " Station Number " << x + 1 << endl; //Prints ID and location
                        break;
                    }
                    else if (loop == vect.size())
                        cout << ID << " is not signed into a computer." << endl; //Prints that the ID was not found
                }
            }
        }
        
        //Choice 4: Quit
        if (choice == 4)
            break;
        
        //Prints Labs after each loop
        cout << "\nLAB" << endl;
        cout << "Lab Number\tComputer Stations Numbers" << endl;
        cout << "1\t\t1: ";  Display(vect[0][0]); cout << " 2: ";  Display(vect[0][1]); cout << " 3: ";  Display(vect[0][2]); cout << " 4: ";  Display(vect[0][3]); cout << " 5: ";  Display(vect[0][4]); cout << endl;
        cout << "2\t\t1: ";  Display(vect[1][0]); cout << " 2: ";  Display(vect[1][1]); cout << " 3: ";  Display(vect[1][2]); cout << " 4: ";  Display(vect[1][3]); cout << " 5: ";  Display(vect[1][4]); cout << " 6: ";  Display(vect[1][5]); cout << endl;
        cout << "3\t\t1: ";  Display(vect[2][0]); cout << " 2: ";  Display(vect[2][1]); cout << " 3: ";  Display(vect[2][2]); cout << " 4: ";  Display(vect[2][3]); cout << endl;
        cout << "4\t\t1: ";  Display(vect[3][0]); cout << " 2: ";  Display(vect[3][1]); cout << " 3: ";  Display(vect[3][2]); cout << endl; cout << endl;
    }
    return 0;
}