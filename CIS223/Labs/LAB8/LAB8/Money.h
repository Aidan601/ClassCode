//Class for amounts of money in U.S. currency.

#ifndef MONEY_H
#define MONEY_H

class Money
{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);

    friend Money operator -(const Money& amount1, const Money& amount2);

    friend Money operator -(const Money& amount);

    friend bool operator ==(const Money& amount1, const Money& amount2);


    Money(long dollars, int cents);

    Money(long dollars);

    Money();

    double getValue() const;

    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in -$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type Money.
    //Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream,
    //then outs has already been connected to a file.

    friend Money operator <(const Money& amount1, const Money& amount2);

    friend Money operator <=(const Money& amount1, const Money& amount2);

    friend Money operator >(const Money& amount1, const Money& amount2);

    friend Money operator >=(const Money& amount1, const Money& amount2);
private:
    long allCents;
};

int digitToInt(char c);

#endif // !MONEY_H