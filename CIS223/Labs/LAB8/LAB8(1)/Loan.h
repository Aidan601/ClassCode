#ifndef LOAN_H
#define LOAN_H

class Loan // Loan is called structure tag 
{
public:
	Loan();
	Loan(ID id, float amount, float rate, int term);
	void set();
	float payment();
	void display();
private:
	ID id; //assume an unique integer between 1111-9999
	float amount; // $ amount of the loan 
	float rate; // annual interest rate 
	int term; // number of months, length of the loan 
};

#endif