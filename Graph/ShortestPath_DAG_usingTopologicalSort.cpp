#include <bits/stdc++.h>
 
using namespace std;
void countIndegree(vector<int>adj[], int src, vector<bool>visited, vector<int>indegree){
    queue<int>q;
    q.push(src);
    visited[src]=true;

    for(int u:adj[src]){
        indegree[u]++;
        if(!visited[u]){
            visited[u]=true;
            q.push(u);
        }
    }
}
 void shortestPath(vector<int>adj[], int totalvertex, vector<vector<int>>weight, int src){
    //Assuming Indegree of src is ZERO
    vector<int>indegree(totalvertex, 0);
    vector<int>path(totalvertex, INT_MAX);
    vector<bool>visited(totalvertex, false);

    for(int i=0; i<totalvertex; i++){
        if(!visited[i]){
            countIndegree(adj, i, visited, indegree);
        }
    }
    queue<int>q;
    for(int i=0; i<totalvertex; i++){
        if(indegree[i]==0) q.push(i);
    }

    path[src]=0;
    q.push(src);
    while(!q.empty()){
        int top=q.front();
        q.pop();

        for(int u: adj[top]){
            if(path[u] > path[top]+ weight[top][u]){
                path[u]= path[top]+weight[top][u];
            }
            indegree[u]--;
            if(indegree[u] == 0) q.push(u);
        }
        
    }

 }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}