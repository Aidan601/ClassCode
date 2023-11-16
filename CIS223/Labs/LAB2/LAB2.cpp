//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-223 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 2																	//
//	Problem Number:			1																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			February 1, 2022														//
//	Project Name:			LAB2																	//
//	File Name:				LAB2.cpp																//
//																									//
//	Purpose of Program:																				//
//		Manages the deposits and withdrawls of two bank accounts.									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SavingsAccount
{
private:
	int dollars, cents, account, xd, xc;
public:
	//Default Constructor
	SavingsAccount();

	//Constructor
	SavingsAccount(int d, int c);

	//Mutators
	void setDollars(int d);
	void setCents(int c);

	//Accesors
	int getDollars();
	int getCents();
	int getAccount();

	void OpenAccount(); //Creates Account
	void Deposit(); //Deposit Balance
	void Withdrawal(); //Withdrawal Balance
	void CheckBalance(); //Cent Normalization
};


int main()
{
	int choice = 0, account = 0;
	SavingsAccount bank1, bank2;
	
	// Output Identification
	system("CLS");
	cout << "Lab 2 Exercise #1 by Aidan Sullivan - "
		<< "Savings Account\n\n";

	cout << "Lets create your bank account! (Account 1)" << endl;
	bank1.OpenAccount();
	while (choice != 4) 
	{
		cout << "\nMain Menu:" << endl;
		cout << "1. Make a Deposit" << endl;
		cout << "2. Make a Withdrawl" << endl;
		cout << "3. Show Current Balance" << endl;
		cout << "4. Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:

			if (bank1.getAccount() == 1)
				bank1.Deposit();
			else
				bank2.Deposit();
			break;
		case 2:
			if (bank1.getAccount() == 1)
				bank1.Withdrawal();
			else
				bank2.Withdrawal();
			break;
		case 3:
			cout << "Account 1: $" << bank1.getDollars() << ".";
			if (bank1.getCents() < 10)
				cout << "0";
			cout << bank1.getCents() << endl;
			cout << "Account 2: $" << bank2.getDollars() << ".";
			if (bank2.getCents() < 10)
				cout << "0";
			cout << bank2.getCents();
			break;
		default: 
			break;
		}
		bank1.CheckBalance();
		bank2.CheckBalance();
	}
}

SavingsAccount::SavingsAccount()
{
	dollars = 0;
	cents = 0;
}

SavingsAccount::SavingsAccount(int d, int c)
{
	dollars = d;
	cents = c;
}

void SavingsAccount::setDollars(int d)
{
	dollars = d;
}

void SavingsAccount::setCents(int c)
{
	cents = c;
}

int SavingsAccount::getDollars()
{
	return dollars;
}

int SavingsAccount::getCents()
{
	return cents;
}

int SavingsAccount::getAccount()
{
	cout << "Which account would you like to use? (1 - 2)" << endl;
	cin >> account;
	return account;
}

void SavingsAccount::OpenAccount()
{
	cout << "How much dollars would you like to deposit?: ";
	cin >> dollars;
	cout << "How much cents would you like to deposit?: ";
	cin >> cents;
	setDollars(dollars);
	setCents(cents);
}

void SavingsAccount::Deposit()
{
	cout << "How much dollars would you like to deposit?: ";
	cin >> xd;
	cout << "How much cents would you like to deposit?: ";
	cin >> xc;
	setDollars(getDollars() + xd);
	setCents(getCents() + xc);
}

void SavingsAccount::Withdrawal()
{
	cout << "How much dollars would you like to withdrawal?: ";
	cin >> xd;
	cout << "How much cents would you like to withdrawal?: ";
	cin >> xc;
	setDollars(getDollars() - xd);
	setCents(getCents() - xc);
}

void SavingsAccount::CheckBalance()
{
	while (getCents() >= 100)
	{
		setDollars(getDollars() + 1);
		setCents(getCents() - 100);
	}
	while (getCents() < 0)
	{
		setDollars(getDollars() - 1);
		setCents(getCents() + 100);
	}

}
