#include <bits/stdc++.h>
 
using namespace std;


  vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>path(N, INT_MAX);
        vector<int>vis(N, 0);
        path[src]=0;
        vector<int>adj[N];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        queue<pair<int,int>>q;
        q.push({src,0});
        vis[src]=1;

        while(!q.empty()){
            int node=q.front().first;
            int dist=q.front().second;
            q.pop();

            for(int u: adj[node]){
                if(path[u] > path[node]+1)  path[u]=path[node]+1;
                if(!vis[u]){
                    vis[u]=true;
                    q.push({u,path[u]});
                }
            }
        }
        return path;
        

    }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}