#include <bits/stdc++.h>
 
using namespace std;
    void BFS(vector<int> adj[], int s, bool visited[]){
    // V->no. of vertex in graph
    // s-> source vertex
    queue<int>q;
    q.push(s);
    visited[s]=true;

    while(!q.empty()){
        int vertex=q.front();
        q.pop();
        cout<<vertex<<" ";
        for(int i: adj[vertex]){
            if(visited[i] == false){
                q.push(i);
                visited[i]=true;
            }
        }
    }
 }

 int BFS_DISCONNECTED(vector<int>adj[], int v){
    int count =0;
    bool visited[v+1];
    for(int i=0; i<v; i++){
        if(visited[i] == false){
            BFS(adj, i, visited);
            count++;
        }
    }
    return count;
 }
 
int main(int argc, char const *argv[])
{
   
  
 
  return 0;
}