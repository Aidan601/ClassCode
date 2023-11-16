//Aidan Sullivan
//05-17-2023
//Chapter 8 Assignment 8.3
#include <iostream>
#include <list>
#include <queue>
using namespace std;

class DisjSet {
	int* rank, * parent, *size, n;

public:
	DisjSet(int n)
	{
		rank = new int[n];
		size = new int[n];
		parent = new int[n];
		this->n = n;
		for (int i = 0; i < n; i++) 
		{
			parent[i] = i;
			rank[i] = 0;
			size[i] = 1;
		}
	}

	//Find Without Path Compression
	int find(int x)
	{
		if (parent[x] != x)
			x = parent[x];
		return x;
	}

	//Find with Path Compression
	int findPC(int x)
	{
		if (parent[x] != x)
			x = parent[x];
		return parent[x] = x;
	}

	//Prints output of Disjoint set
	void print()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i << " -> " << parent[i] << endl;
		}
	}

	//Union performed arbitrarily
	void ArbitraryUnion(int x, int y)
	{
		parent[y] = x;
	}

	//Union performed by size
	void UnionBySize(int x, int y)
	{
		//Find x and y
		int s = find(x);
		int r = find(y);
		//Find x and y with path compression
		//int s = findPC(x);
		//int r = findPC(y);;

		// If they are already in same set
		if (r == s)
			return;
		else if (size[r] > rank[s]) 
		{
			parent[s] = r;
			size[r] += size[s];
		}
		else
		{
			parent[r] = s;
			size[s] += size[r];
		}
	}

	//Union performed by height(rank)
	void UnionByRank(int x, int y)
	{
		//Find x and y
		int s = find(x);
		int r = find(y);
		//Find x and y with path compression
		//int s = findPC(x);
		//int r = findPC(y);
	
		// If they are already in same set
		if (r == s)
			return;
		else if (rank[r] > rank[s]) {
			parent[s] = r;
		}
		else if (rank[r] < rank[s]) {
			parent[r] = s;
		}
		else 
		{
			parent[r] = s;
			rank[s] = rank[s]++;
		}
	}
};

// Driver Code
int main()
{
	// Function Call
	DisjSet obj(17);
	obj.UnionByRank(1, 2);
	obj.UnionByRank(3, 4);
	obj.UnionByRank(3, 5);
	obj.UnionByRank(1, 7);
	obj.UnionByRank(3, 6);
	obj.UnionByRank(8, 9);
	obj.UnionByRank(1, 8);
	obj.UnionByRank(3, 10);
	obj.UnionByRank(3, 11);
	obj.UnionByRank(3, 12);
	obj.UnionByRank(3, 13);
	obj.UnionByRank(14, 15);
	obj.UnionByRank(16, 0);
	obj.UnionByRank(14, 16);
	obj.UnionByRank(1, 3);
	obj.UnionByRank(1, 14);

	obj.print();

	return 0;
}
