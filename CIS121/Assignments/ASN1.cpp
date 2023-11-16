//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Assignment 1															//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			September 6, 2021														//
//	Project Name:			ASN1																	//
//	File Name:				ASN1.cpp															    //
//																									//
//	Purpose of Program:																				//
//		The purpose of the program is to calculate the amount of boxes and packages needed			//
//		to get the correct number of engines with the price											//
//////////////////////////////////////////////////////////////////////////////////////////////////////
//
#include <iostream>
using namespace std;
int main()
{
    system("CLS");
    cout << "Assignment #1 by Aidan Sullivan - Calculate Engine Purchase "
        << "Example Program\n\n";
    int engines, pack;
    double boxcost, packcost, total;
    cout << "Enter the number of engines needed:";
    cin >> engines; //The total amount of engines 
    if (engines <= 0)
    {
        cout << "\n\nEnd Program.\n";
        return 0;
    }
    const int box = engines / 24; //The number of boxes to purchase
    pack = engines / 3 - 8 * box; // The number of packages to purchase
    if (box*24+pack*3 != engines) //Adds extra package if any remainf are less than 3
    {
        pack++;
    }
    cout << "Enter the cost of a box of 24 engines:";
    cin >> boxcost;                                     //Inputs cost of each box
    cout << "Enter the cost of a package of 3 engines:";
    cin >> packcost;                                    //Inputs cost of each package
    total = box * boxcost + pack * packcost;            // Calculates total price
    if (box == 0 && pack == 1) //Grammar for one package
    {
        cout << "You will need to purchase 1 package of engines\n";
        cout << "at a total of $" << packcost << ".";
    }
    else if (box == 0 && pack >= 1) //Grammar for more than one package
    {
        cout << "You will need to purchase " << pack << " packages of engines\n";
        cout << "at a total of $" << total << ".";
    }
    else if (box == 1 && pack == 0) //Grammar for one box
    {
        cout << "You will need to purchase 1 box of engines\n";
        cout << "at a total of $" << total << ".";
    }
    else if (box == 1 && pack == 1) //Grammar for one box and one package
    {
        cout << "You will need to purchase 1 box and 1 package of engines\n";
        cout << "at a total of $" << total << ".";
    }
    else if (box == 1 && pack >= 1) //Grammar for one box and more than on package
    {
        cout << "You will need to purchase 1 box and " << pack << " packages of engines\n";
        cout << "at a total of $" << total << ".";
    }
    else if (box >= 1 && pack == 0) //Grammar for more than one box
    {
        cout << "You will need to purchase " << box << " boxes of engines\n";
        cout << "at a total of $" << total << ".";
    }
    else if (box >= 1 && pack == 1) //Grammar for more than one box and one package
    {
        cout << "You will need to purchase " << box << " boxes and 1 package of engines\n";
        cout << "at a total of $" << total << ".";
    }
    else if (box >= 1 && pack >= 1) //Grammar for more than one box and more than one package
    {
        cout << "You will need to purchase " << box << " boxes and " << pack << " packages of engines\n";
        cout << "at a total of $" << total << ".";
    }
    cout << "\n\nEnd Program.\n";
    return 0;
}