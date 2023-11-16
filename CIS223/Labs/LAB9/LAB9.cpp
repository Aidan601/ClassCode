//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 9 																    //
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Apr 6, 2022		    									        		//
//	File Name:				LAB9.cpp																//
//																									//
//	Purpose of Program:																				//
//		This program demonstrates enumerated data types.            			                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;
enum coin_type { nickel, dime, quarter };
int main()
{
    coin_type coin;
    int holdings[3] = { 3, 6, 2 };
    int total = 0;
    for (coin = nickel; coin <= quarter; coin = static_cast<coin_type>(coin + 1))
    {
        switch (coin)
        {
        case nickel:   total = total + (5 * holdings[coin]);  break;
        case dime:     total = total + (10 * holdings[coin]); break;
        case quarter:  total = total + (25 * holdings[coin]); break;
        }
    }
    cout << "Total holdings are " << total << " cents.\n";
    return 0;
}
//The identifers help easily label what each variable of coin represents. 
