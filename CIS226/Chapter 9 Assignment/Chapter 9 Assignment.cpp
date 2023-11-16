// Aidan Sullivan
// 4-25-2023
// Chapter 9 Assignment - 9.3 Topological Sort

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
	int V; //vertices
	list<int>* l; 

public:
	Graph(int V)
	{
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x, int y) 
	{
		l[x].push_back(y);
	}

	void topsort() //Kahn's Algorithim
    {
        queue<int> q;
        int counter = 0;

        vector<int> indegree(V, 0); //Empty Queue
        for (int i = 0; i < V; i++)
        {
            for (list<int>::iterator z = l[i].begin(); z != l[i].end(); z++)
                indegree[*z]++;
        }

        for (int i = 0; i < V; i++) //Set indegrees to 0
            if (indegree[i] == 0)
                q.push(i);

        vector<int> top_order;
        while (!q.empty()) //While queue is empty
        {
            int u = q.front();
            q.pop();
            top_order.push_back(u);
            for (list<int>::iterator z = l[u].begin(); z != l[u].end(); z++)
                if (--indegree[*z] == 0) //If indegree is 0
                    q.push(*z);
            counter++;
        }

        if (counter != V) //If graph contains at least one cycle
            cout << "ERROR\n";
        else
            for (int i = 0; i < top_order.size(); i++) // Prints output
                cout << top_order[i] << " ";
    }
};



int main()
{
    Graph graph(7); //Creates Graph
    graph.addEdge(0, 3);//0->3
    graph.addEdge(1, 0);//1->0
    graph.addEdge(1, 3);//1->3
    graph.addEdge(3, 2);//3->2
    graph.addEdge(3, 4);//3->4
    graph.addEdge(5, 4);//5->4
    graph.addEdge(6, 5);//6->5
    graph.addEdge(6, 3);//6->3
	graph.topsort();
	return 0;
}
