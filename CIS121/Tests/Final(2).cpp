//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Fall 2021													//
//																									//
//	Type of Assignment:		Final																	//
//	Problem Number:			5																		//
//	Author:					Aidan Sullivan															//
//	Date Assigned:			December 15, 2021														//
//	Project Name:			Final(1)															    //
//	File Name:				Final(1).cpp															//
//																									//
//	Purpose of Program:																				//
//		Calculates payroll of employees given hours and pay     									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

//Class declaration
class PayRoll
{
public:
    PayRoll(int h,int p);
    PayRoll();

    void setHours(int h);
    void setPay(int p);
    void Output();

    int getHours();
    int getPay();
    int TotalPay();

private:
    int hours;
    int pay;
};

int main()
{
    // Output Identification
    system("CLS");
    cout << "Final Problem #5 by Aidan Sullivan - "
        << "Payroll\n\n";

    PayRoll payroll;
    int pay, hour;
    cout << "Enter the hours worked and pay rate for the employee:" << endl;
    cout << "Pay rate: ";
    cin >> pay;
    cout << "Hours worked: ";
    cin >> hour;
    payroll.setPay(pay);
    payroll.setHours(hour);
    payroll.Output();

    return 0;
}

PayRoll::PayRoll(int h, int p)
{
    hours = h;
    pay = p;
}

PayRoll::PayRoll()
{
    hours = 0;
    pay = 0;
}

void PayRoll::setHours(int h)
{
    hours = h;
}

void PayRoll::setPay(int p)
{
    pay = p;
}

void PayRoll::Output()
{
    cout << "Total pay: $" << TotalPay() << ".00";
}

int PayRoll::TotalPay()
{
    return hours*pay;
}

int PayRoll::getHours()
{
    return hours;
}

int PayRoll::getPay()
{
    return pay;
}
