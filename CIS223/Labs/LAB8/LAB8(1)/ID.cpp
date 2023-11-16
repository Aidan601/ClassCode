#include <iostream> 
using namespace std;
#include "ID.h"
ID::ID()
{
	// use default values 
}
ID::ID(int l, int m, int r)
{
	left = l;
	middle = m;
	right = r;
}
void ID::display()
{
	cout << right << "-" << middle << "-" << right << endl;
}