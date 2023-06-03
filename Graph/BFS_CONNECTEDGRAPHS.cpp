#include <bits/stdc++.h>
 
using namespace std;
 //FIRST VERSION-> THIS IS FOR CONNECTED GRAPHS;
 void BFS(vector<int> adj[], int v, int s){
    // V->no. of vertex in graph
    // s-> source vertex
    bool visited[v+1];
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


int main(int argc, char const *argv[])
{
 
  return 0;
}