#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printList(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int x : adj[i])
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    int V = 4;
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    printList(adj, V);

    return 0;
}