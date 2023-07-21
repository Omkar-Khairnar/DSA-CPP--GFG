#include <bits/stdc++.h>
 
using namespace std;
//DJK Algo with Priority queue i.e. Min-Heap
   vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>cost(V,INT_MAX);
        cost[S]=0;
        
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
        //Min-Heap Storing {dist, node} from source node;
        pq.push({0,S});
        
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                
                if( cost[adjNode] > cost[node]+edgeWeight){
                    cost[adjNode] = cost[node]+edgeWeight;
                    pq.push({cost[adjNode], adjNode});
                }
            }
        }
        
        return cost;
    }

        //DJK algo implemented with Set.
     vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>cost(V,INT_MAX);
        cost[S]=0;
        
        //set contaning {dist, node} pair
       set<pair<int,int>>st;
        st.insert({0,S});
        
        while(!st.empty()){
            pair<int,int>top=*(st.begin());
            int dist=top.first;
            int node=top.second;
            st.erase(top);
            
            for(auto it: adj[node]){
                int edgeWeight=it[1];
                int adjNode=it[0];
                
                if( cost[adjNode] > cost[node]+edgeWeight){
                    
                    //Here we are removing previous entry of adjNode from set to prevent extra iteration. This is not possible in priority queue.
                    //But this cause O(log(n)) time ,So in case of large vertices in the set it consumes more time 
                    if(cost[adjNode] !=INT_MAX) st.erase({cost[adjNode],adjNode});
                    
                    cost[adjNode] = cost[node]+edgeWeight;
                    st.insert({cost[adjNode], adjNode});
                }
            }
        }
        
        return cost;
    }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}