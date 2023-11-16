//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-223 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 1																	//
//	Problem Number:			2																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Janurary 28, 2022														//
//	Project Name:			LAB1																	//
//	File Name:				LAB1(1).cpp																//
//																									//
//	Purpose of Program:																				//
//		Create, store, and modify customer accounts.												//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Declaration of the Customer structure
struct Customer
{
	string name;    // Name
	string address; // Address
	string city;    // City
	string state;   // State
	string zip;     // ZIP code
	string phone;   // Phone number
	string balance; // Account balance
	string lastPay; // Date of last payment
};

// Function prototypes
void getInfo(Customer& c);
void showInfo(Customer c);

int main()
{
	// Constant for the number of accounts
	const int SIZE = 20;

	// Array of Customer structures
	Customer account[SIZE];

	// Subscript of next account to enter
	int maxCust = 0;
	// User's choice from a menu
	int choice;
	int customerInfo;
	int cust;

	do
	{
		// Display a menu.
		cout << "Main Menu:" << endl;
		cout << "1. Enter new account information" << endl;
		cout << "2. Change account information" << endl;
		cout << "3. Display all account information" << endl;
		cout << "4. Exit the program" << endl;


		// Get the user's choice.
		cin >> choice;


		// Validate the choice.
		while (choice > 4 || choice < 1)
		{
			cout << "ERROR: Invalid input. Try again" << endl;
			cin >> choice;
		}


		// Perform the selected operation.
		switch (choice)
		{
			// Enter new account information.
		case 1:
			cin.get();
			//call getInfo function and pass the argument account[maxCust] 
			getInfo(account[maxCust]);

			cout << "You have entered information"    //echo the input account information
				<< " for customer number ";
			cout << maxCust << endl;

			//increase the subscript maxCust
			maxCust++;

			break;

			// Change an existing account.
		case 2:
			// Get the customer number.
			cout << "Customer number: ";
			cin >> cust;

			// Validate the customer number. If cust is not within 0 and maxCust, ask the user reenter
			while (cust > maxCust || cust < 0)
			{
				cout << "ERROR: Invalid Customer Number\n";
				cout << "Enter a valid customer number: ";
				cin >> cust;
			}

			// Show the selected account account[cust].
			showInfo(account[cust]);

			// Get the new account information.
			cin.get();
			getInfo(account[cust]);
			break;

			// Display all account information.
			showInfo(account[cust]);
		case 3:
			cin.get();
			for (int count = 0; count < maxCust; count++)
			{
				showInfo(account[count]);
				cout << "Press enter to continue...\n";
				cin.get();
			}
			break;
		}

	} while (choice != 4);

	return 0;
}

//********************************************************
// Function getInfo                                      *
// This function gets account information from the user  *
// and stores it in the parameter c, which is a Customer *
// structure reference variable.                         *
//********************************************************

void getInfo(Customer& c)
{
	// Get the customer name
	cout << "\nCustomer name: ";
	getline(cin, c.name);
	while (c.name.empty())
	{
		cout << "You must enter a name.\n";
		getline(cin, c.name);
	}

	// Get the customer's address.
	cout << "\nCustomer address: ";
	getline(cin, c.address);
	while (c.address.empty())
	{
		cout << "You must enter a address.\n";
		getline(cin, c.address);
	}

	// Get the customer's city.
	cout << "\nCity: ";
	getline(cin, c.city);
	while (c.city.empty())
	{
		cout << "You must enter a city.\n";
		getline(cin, c.city);
	}

	// Get the customer's state.
	cout << "\nState: ";
	getline(cin, c.state);
	while (c.state.empty())
	{
		cout << "You must enter a state.\n";
		getline(cin, c.state);
	}

	// Get the customer's ZIP code.
	cout << "\nZIP code: ";
	getline(cin, c.zip);
	while (c.zip.empty())
	{
		cout << "You must enter a zip code.\n";
		getline(cin, c.zip);
	}

	// Get the customer's phone number.
	cout << "\nTelephone: ";
	getline(cin, c.phone);
	while (c.phone.empty())
	{
		cout << "You must enter a Telephone number.\n";
		getline(cin, c.phone);
	}

	// Get the account balance.
	cout << "\nAccount balance: ";
	getline(cin, c.balance);
	while (c.balance.empty())
	{
		cout << "You must enter the account balance.\n";
		getline(cin, c.balance);
	}

	// Get the date of the last payment
	cout << "\nDate of last payment: ";
	getline(cin, c.lastPay);
	while (c.lastPay.empty())
	{
		cout << "You must enter the last payment.\n";
		getline(cin, c.lastPay);
	}
}

//************************************************************
// Function showInfo                                         *
// This function displays the customer's name, address,      *
// account balance, and date of last payment. The information*
// is passed into the c structure.                           *
//************************************************************

void showInfo(Customer c)
{
	cout << "Customer name: " << c.name << endl;
	cout << "Customer address: " << c.address << endl;
	cout << "City: " << c.city << endl;
	cout << "State: " << c.state << endl;
	cout << "Zip Code: " << c.zip << endl;
	cout << "Telephone: " << c.phone << endl;
	cout << "Account balance: " << c.balance << endl;
	cout << "Date of last payment: " << c.lastPay << endl;
}

