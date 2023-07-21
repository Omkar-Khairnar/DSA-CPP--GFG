#include <bits/stdc++.h>
 
using namespace std;
 void countDegree(vector<int>adj[], int src,bool visited[], int indegree[]){
    queue<int>q;
    visited[src]=true;
    q.push(src);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            indegree[v]++;
            if(!visited[v]){ q.push(v);
            visited[v]=true;}
        }
    }
 }

 //This Kahn's Algo works only for DIRECTED ACYCLIC GRAPH(DAG)
 void topologicalOrder(vector<int>adj[], int src, int totalVertex){
    int indegree[totalVertex]={0};
    bool visited[totalVertex]={false};

    for(int i=0; i<totalVertex; i++){
        if(!visited[i]){
            countDegree(adj,src, visited, indegree);
        }
    }

    //Now indegree[] has indegress of all vertex

    queue<int>q;
    //Inserting vertex with indegrees 0.
    for(int i=0; i<totalVertex; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u]){
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }
 }

int main(int argc, char const *argv[])
{
 
  return 0;
}