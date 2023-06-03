#include <bits/stdc++.h>
 
using namespace std;
 
 vector<int> ShortestPathFromSource(vector<int>adj[], int src, int totalVertex){
    vector<int> dist(totalVertex, INT_MAX);
    bool visited[totalVertex]={false};

    queue<int> q;
    q.push(src);
    dist[src]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(int i: adj[curr]){
            if(visited[i]  == false){
                dist[i]=dist[curr]+1;
                visited[i]=true;
                q.push(i);  
            }
        }
    }

    return dist;

 }


 
int main(int argc, char const *argv[])
{
 
  return 0;
}