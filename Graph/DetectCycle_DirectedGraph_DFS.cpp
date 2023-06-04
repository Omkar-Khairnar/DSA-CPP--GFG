#include <bits/stdc++.h>
 
using namespace std;
//Detect cycle in DIRECTED Graph-->(both connected and disconnected graphs)
//IDEA: Here we are maintaining a RecStack array to track the visited vertex is in current stack or not. For more details watch Video.
 bool DFSRec(vector<int> adj[], int src, bool visited[], bool recStack[]){
    visited[src]=true;
    recStack[src]=true;

    for(int u:adj[src]){
        if(!visited[u]){
            if(DFSRec(adj,u, visited, recStack)) return true;
        }
        else if(recStack[u]) return true;
    }
    recStack[src]=false;
    return false;
 }

 bool isCycle(vector<int> adj[], int src,int totalVertex){
    bool visited[totalVertex]={false};
    bool recStack[totalVertex]={false};

    for(int i=0; i<totalVertex; i++){
        if(!visited[i] && DFSRec(adj,i,visited,recStack)) return true;
    }
    return false;
 }


 
int main(int argc, char const *argv[])
{
 
  return 0;
}