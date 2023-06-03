#include <bits/stdc++.h>
 
using namespace std;
 void DFSRec(vector<int>adj[], int s, bool visited[]){
    visited[s]=true;
    cout<<s<<" ";
    for(int u: adj[s]){
        if(visited[u] == false){
            DFSRec(adj, u, visited);
        }
    }
 }

 void DFS(vector<int>adj[], int v){
    bool visited[v+1];
    for(int i=0; i<v; i++){
        if(visited[i] == false)
                DFSRec(adj, i, visited);
    }
        
 }

 
 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}