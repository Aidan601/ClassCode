#include<iostream> 
#include<cstdlib> 
#include<fstream> 
using namespace std;

class Set {
public:
	//default constructor
	Set();
	//add element to set
	void addElement(int element);
	//remove element from set
	void removeElement(int element);
	//check for membership
	bool isMember(int element);
	//set union, modifies curremtn set
	void Union(Set s);
	//set difference modifiers current set
	void difference(Set s);
	//size of set
	int size();
	//get element i
	int getElement(int i);
private:
	//binary search for element, returns index
	bool search(int element, int& index);
	//set members
	int elements[maxElements];
	//next empty position in elements
	int next;
};

int main()
{
    
	
	set1.generateSample(set1, size);
	set1.printSet();
	set1.removeElement(15);
	cout << "\n\n";
	set1.printSet();
	set1.addElement(15);
	cout << "\n\n";
	set1.printSet();
	set2.generateSample(set2, size);
	cout << "\n\n";
	for (int i = 0; i < set2.size(); i++)
		cout << set2.getElement(i) << " ";
	if (set1 == set2)
		cout << "\nset1 and set2 are equal\n";
	else
		cout << "\nset1 and set2 are not equal\n";
	if (set1 != set2)
		cout << "\nset1 and set2 are not equivalent\n";
	else
		cout << "set1 and set2 are identical sets";
	set1 = set1 + 25;
	cout << "\n\n";
	set1.printSet();
	set2 = set2 - 60;
	cout << "\n\n";
	set2.printSet();
	set2 = set2 + 1005;
	cout << "\n\n";
	set2.printSet();
}

Set::Set()
{

}

void Set::addElement(int element)
{

}

void Set::removeElement(int element)
{

}

bool Set::isMember(int element)
{
	return false;
}

void Set::Union(Set s)
{

}

void Set::difference(Set s)
{

}

int Set::size()
{
	return 0;
}

int Set::getElement(int i)
{
	return 0;
}

bool Set::search(int element, int& index)
{
	return false;
}
