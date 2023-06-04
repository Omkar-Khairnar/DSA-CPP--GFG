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

// Detect cycle in UNDIRECTED GRAPHS -->(both connected and disconnected graphs)
  bool DFSRec(vector<int>adj[], int src, bool visited[], int parent){
    visited[src]=true;
    for(int u: adj[src]){
      if(!visited[u]){
        if(DFSRec(adj,u,visited,src)) return true;
      }
      else if(u != parent){
        return true;
      }
    }
    return false;
  }
 bool isCycle(vector<int>adj[], int src, int totalVertex){
    bool visited[totalVertex+1]={false};
    for(int i=0; i<totalVertex; i++){
      if(visited[i]==false){
       if(DFSRec(adj, src, visited, -1)) return true;
      }
    }
    return false;
 }
int main(int argc, char const *argv[])
{
 int V = 4;
    vector<int> adj[4];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    // addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    // printList(adj, V);

    cout<<isCycle(adj,V,0);
  return 0;
}