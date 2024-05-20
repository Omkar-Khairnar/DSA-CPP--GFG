#include <bits/stdc++.h>
 
using namespace std;
 
 int minKey(vector<int>key, vector<bool>mSet, int V){
    int min=INT_MAX,min_index;

    for(int i=0; i<V; i++){
        if(mSet[i]==false && key[i] < min){
            min=key[i], min_index=i;
        }
    }
        return min_index;
 }
 

 int MST_Weight(vector<int>graph[], int V){
    vector<int>key(V,INT_MAX);
    key[0]=0;
    vector<bool>mSet(V,false);
    int res=0;

    for(int count=0; count <V; count++){

        int u=minKey(key,mSet,V);
        res=res+key[u];
        mSet[u]=true;

        for(int i=0; i<V; i++){
            if(mSet[i]==false && graph[u][i] !=0){
                key[i]=min(key[i], graph[u][i]);
            }
        }
    }
    return res;
 }



 //Another approach using Priority Queue
  int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int>vis(V,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        //pq({edgeWeight, node})
        pq.push({0,0});
        int sum=0;  
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int node=it.second;
            //If its already visited then continuing to next iteration
            if(vis[node]==1) continue;
            //marking visited node after removing from queue
            vis[node]=1;
            //Here we are adding min. spanning edge 
            sum+=wt;
            
            for(auto vec :adj[node]){
                if(!vis[vec[0]]){
                    pq.push({vec[1], vec[0]});
                }
            }
        }
        return sum;
    }
int main(int argc, char const *argv[])
{
 
  return 0;
}