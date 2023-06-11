#include <bits/stdc++.h>
 
using namespace std;
 
 void DFS(vector<int>adj[], vector<bool>visited, stack<int>st, int src ){
    visited[src]=true;

    for(int u: adj[src]){
        if(!visited[u]){
            DFS(adj, visited,st,u);
        }
    }
    st.push(src);
 }

 void TopologicalSort(vector<int>adj[], int totalVertex){
    vector<bool>visited(totalVertex, false);
    stack<int>st;
    for(int i=0; i<totalVertex; i++){
        if(!visited[i]){
            DFS(adj, visited,st,i);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
 }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}