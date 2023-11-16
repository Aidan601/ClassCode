//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-212 Spring 2022													//
//																									//
//	Type of Assignment:		Lab 5 																    //
//	Problem Number:			3																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			Feb 28, 2022											        		//
 //	File Name:				LAB5(2).cpp																//
//																									//
//	Purpose of Program:																				//
//		This program adds money of two different people							                    //
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream> 
#include<cstdlib> 
using namespace std;
class AltMoney
{
public:
	AltMoney();
	AltMoney(int d, int c);
	void read_money();
	void display_money();
	friend AltMoney add(AltMoney m1, AltMoney m2);
	friend AltMoney subtract(AltMoney m1, AltMoney m2);
private:
	int dollars;
	int cents;
};

int main()
{
	int d, c;
	AltMoney m1, m2, sum, sub;
	sum = AltMoney(0, 0);
	m1.read_money();
	cout << "The first money is:";
	m1.display_money();
	m2.read_money();
	cout << "The second money is:";
	m2.display_money();
	sum = add(m1, m2);
	cout << "The sum is:";
	sum.display_money();
	sub = subtract(m1, m2);
	cout << "The differece is:";
	sub.display_money();
	return 0;
}
AltMoney::AltMoney()
{
}
AltMoney::AltMoney(int d, int c)
{
	dollars = d;
	cents = c;
}
void AltMoney::display_money()
{
	cout << "$" << dollars << ".";
	if (cents <= 9)
		cout << "0"; //to display a 0 in the left for numbers less than 10 
	cout << cents << endl;
}
AltMoney add(AltMoney m1, AltMoney m2)
{
	AltMoney sum;
	int extra = 0;
	sum.cents = m1.cents + m2.cents;
	if (sum.cents >= 100) {
		sum.cents = sum.cents - 100;
		extra = 1;
	}
	sum.dollars = m1.dollars + m2.dollars + extra;
	return sum;
}
AltMoney subtract(AltMoney m1, AltMoney m2) //Subtracting function
{
	AltMoney sub;
	int extra = 0;
	sub.cents = m1.cents - m2.cents;
	if (sub.cents <= 0) {
		sub.cents = sub.cents + 100;
		extra = 1;
	}
	sub.dollars = m1.dollars - m2.dollars - extra;
	return sub;
}
void AltMoney::read_money()
{
	cout << "Enter dollar \n";
	cin >> dollars;
	cout << "Enter cents \n";
	cin >> cents;
	if (dollars < 0 || cents < 0)
	{
		cout << "Invalid dollars and cents, negative values\n";
		exit(1);
	}
}