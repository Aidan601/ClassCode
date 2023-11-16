#include <iostream>
#include <vector>
using namespace std;

class StringSet
{
private:
	vector<string> data;
public:
	StringSet(); //Default Constructor
	~StringSet(); //Destructor
	StringSet(string arr[]); //Takes as an input parameter an array of strings for the initial values in the set
	void add(string s); //Adds a string to the set
	void remove(string s); //Removes a string from the set
	void clear(); //clear the entire set to empty
	int search(string s); //Search for a string
	int size(); //Returns size of strings in set
	void output(); //Outputs all strings in the set
	StringSet operator+ (StringSet p); //Overloads the + operator
	friend StringSet operator*(StringSet& set1, StringSet& set2); //Overloads the * operator
	friend ostream& operator <<(ostream& output, StringSet& p); //Overloads the << operator
	friend istream& operator >>(istream& input, StringSet& p); //Overloads the >> operator
	bool operator == (StringSet& p); //Overloads the == operator
};