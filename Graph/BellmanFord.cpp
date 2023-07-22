#include <bits/stdc++.h>
 
using namespace std;

 vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int>dist(V, 1e8);
        dist[S]=0;
        for(int i=0; i<V-1; i++){
            int ct=0;
           for(auto it:edges){
               if(dist[it[0]] + it[2] < dist[it[1]]){
                   dist[it[1]]=dist[it[0]] + it[2];
                   ct++;
               }
           }
           if(ct==0){
               return dist;
               break;
           }
        }
        
        //Checking for Nth iteration, if any changes occur in this iteration then this means negative cycle in graph
        for(auto it : edges){
            if(dist[it[0]] + it[2] < dist[it[1]]){
                  return {-1};
               }
        }
       
        
        return dist;
    } 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}