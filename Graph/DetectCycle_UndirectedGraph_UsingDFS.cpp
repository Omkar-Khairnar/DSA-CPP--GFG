#include <bits/stdc++.h>
 
using namespace std;
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
 
  return 0;
}