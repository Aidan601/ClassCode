#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

#include "Money.h" //Money ADT

//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
    char oneChar, decimalPoint,
        digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> oneChar;
    if (oneChar == '-')
    {
        negative = true;
        ins >> oneChar; //read '$'
    }
    else
        negative = false;
    //if input is legal, then oneChar == '$'

    ins >> dollars >> decimalPoint >> digit1 >> digit2;

    if (oneChar != '$' || decimalPoint != '.'
        || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digitToInt(digit1) * 10 + digitToInt(digit2);

    amount.allCents = dollars * 100 + cents;
    if (negative)
        amount.allCents = -amount.allCents;


    return ins;
}

//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positiveCents, dollars, cents;
    positiveCents = labs(amount.allCents);
    dollars = positiveCents / 100;
    cents = positiveCents % 100;

    if (amount.allCents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;

    return outs;
}

//The definitions of the member functions and other overloaded operators go here.
//See Display 11.3, 11.4, 11.5, and 11.6 for the definitions.

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) //If one is negative and one is positive


    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    allCents = dollars * 100 + cents;
}

Money::Money(long dollars) : allCents(dollars * 100)
{
    //Body intentionally blank.
}

Money::Money() : allCents(0)
{
    //Body intentionally blank.
}

double Money::getValue() const
{
    return (allCents * 0.01);
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.allCents = amount1.allCents + amount2.allCents;
    return temp;
}

Money operator-(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.allCents = amount1.allCents - amount2.allCents;
    return temp;
}


Money operator -(const Money& amount)
{
    Money temp;
    temp.allCents = -amount.allCents;
    return temp;
}

bool operator==(const Money& amount1, const Money& amount2)
{
    return (amount1.allCents == amount2.allCents);
}

Money operator<(const Money& amount1, const Money& amount2) //Overloads < 
{
    if (amount1.allCents < amount2.allCents)
        return true;
    else
        return false;
}

Money operator<=(const Money& amount1, const Money& amount2) //Overloads <= 
{
    if (amount1.allCents <= amount2.allCents)
        return true;
    else
        return false;
}

Money operator>(const Money& amount1, const Money& amount2) //Overloads > 
{
    if (amount1.allCents > amount2.allCents)
        return true;
    else
        return false;
}

Money operator>=(const Money& amount1, const Money& amount2) //Overloads >=
{
    if (amount1.allCents >= amount2.allCents)
        return true;
    else
        return false;
}

int digitToInt(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}