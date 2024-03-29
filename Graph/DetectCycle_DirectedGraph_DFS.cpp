#include <bits/stdc++.h>
 
using namespace std;
//Detect cycle in DIRECTED Graph-->(both connected and disconnected graphs)
//IDEA: Here we are maintaining a RecStack array to track the visited vertex is in current stack or not. For more details watch Video.
 bool DFSRec(vector<int> adj[], int src, bool visited[], bool pathvisited[]){
    visited[src]=true;
    pathvisited[src]=true;

    for(int u:adj[src]){
        if(!visited[u]){
            if(DFSRec(adj,u, visited, pathvisited)) return true;
        }
        else if(pathvisited[u]) return true;
    }
    pathvisited[src]=false;
    return false;
 }

 bool isCycle(vector<int> adj[], int src,int totalVertex){
    bool visited[totalVertex]={false};
    bool pathvisited[totalVertex]={false};

    for(int i=0; i<totalVertex; i++){
        if(!visited[i] && DFSRec(adj,i,visited,pathvisited)) return true;
    }
    return false;
 }


 
int main(int argc, char const *argv[])
{
 
  return 0;
}
