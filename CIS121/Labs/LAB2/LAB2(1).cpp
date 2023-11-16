//  CIS121 Lab 2 Exercise #2
//  coinsStarter.cpp

#include <iostream>
using namespace std;

int main() {

	//constant variable
	const int QUARTERS = 25;
	const int DIMES = 10;
	const int NICKEL = 5;

	//Variable declaration
	int quarters, dimes, nickels, totalCents;

	// input number of quarters
	cout << " Enter number of quarters: \n";
	cin >> quarters;

	//Inputting Number of dimes
	cout << " Enter number of dimes: \n";
	cin >> dimes;

	//Input number of nickels
	cout << " Enter number of nickels: \n";
	cin >> nickels;

	//calculating total cents
	totalCents = QUARTERS*quarters + DIMES*dimes + NICKEL*nickels;

	//Displaying cents
	cout << "You have ";
	cout << totalCents;
	cout << " cents";
	return 0;

}//END PROGRAM MAIN FUNCTION