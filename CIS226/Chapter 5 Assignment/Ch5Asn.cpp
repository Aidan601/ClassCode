// Aidan Sullivan
// 4-17-2023
// Chapter 5 Assignment -  Write a program to compute the number of collisions required in a long random sequence of insertions using linear probing, quadratic probing, and double hashing
#include <iostream>
using namespace std;

int LPcol = 0;//Linear Probing Collisions
int QPcol = 0;//Qudratic Probing Collisions
int DHcol = 0;//Double Hashing Collisions

class HashTable
{
private:
	static const int hashGroups = 10;
	int table[hashGroups] = {0,0,0,0,0,0,0,0,0,0};
public:
	void insertLP(int key); //Insert for Linear Probing
	void insertQP(int key); //Insert for Quadratic Probing
	void insertDH(int key); //Insert for Double Hashing
	void printTable(); //Outputs Hash Table
};

void HashTable::insertLP(int key) //Insert for Linear Probing
{
	int hashValue = key % hashGroups; //Calculates hash value
	while (table[hashValue] != 0) //When collision occurs
	{
		LPcol++; //Adds 1 to amount of collisions
		hashValue++; //Adds 1 to hash value
		if (hashValue >= hashGroups) //If hash value is larger than the hash table
		{
			hashValue = hashValue - hashGroups;
		}
	}
	table[hashValue] = key; //Inserts value into hash table
}

void HashTable::insertQP(int key) //Insert for Quadratic Probing
{
	int j = 0;
	int hashValue = ((key + (j*j)) % hashGroups); //Calculates hash value
	while (table[hashValue] != 0) //When collision occurs
	{
		QPcol++; //Adds 1 to amount of collisions
		j++;
		hashValue = ((key + (j * j)) % hashGroups);
		if (hashValue >= hashGroups) //If hash value is larger than the hash table
		{
			hashValue = hashValue - hashGroups;
		}
	}
	table[hashValue] = key; //Inserts value into hash table
}

void HashTable::insertDH(int key) //Insert for Double Hashing
{
	int hashValue = key % hashGroups; //Calculates hash value
	if (table[hashValue] == 0)
		table[hashValue] = key; //Inserts value into hash table
	else
	{
		int hashValue2 = 7 - (key % 7); //Second Hash Function
		while (table[hashValue] != 0) //When collision occurs
		{
			DHcol++; //Adds 1 to amount of collisions
			hashValue = hashValue + hashValue2;
			if (hashValue >= hashGroups)
			{
				hashValue = hashValue - hashGroups;
			}
		}
		table[hashValue] = key; //Inserts value into hash table
	}
}

void HashTable::printTable() //Outputs Hash Table
{
	for (int i = 0; i < hashGroups; i++)
	{
		cout << i << ": ";
		if (table[i] == 0)
			cout << "\n";
		else
			cout << table[i] << endl;
	}
	cout << "\n";
}

int main()
{
	HashTable LP;
	HashTable QP;
	HashTable DH;

	//Linear Probing
	LP.insertLP(89);
	LP.insertLP(18);
	LP.insertLP(49);
	LP.insertLP(58);
	LP.insertLP(69);

	//Quadratic Probing
	QP.insertQP(89);
	QP.insertQP(18);
	QP.insertQP(49);
	QP.insertQP(58);
	QP.insertQP(69);

	//Double Hashing
	DH.insertDH(89);
	DH.insertDH(18);
	DH.insertDH(49);
	DH.insertDH(58);
	DH.insertDH(69);

	//LP.printTable();
	//QP.printTable();
	//DH.printTable();

	//Collision Outputs
	cout << "Linear Probing: " << LPcol << " Collisions" << endl;
	cout << "Quadratic Probing: " << QPcol << " Collisions" << endl;
	cout << "Double Hashing: " << DHcol << " Collisions" << endl;

	return 0;
}


