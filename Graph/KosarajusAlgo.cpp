#include <bits/stdc++.h>
 
using namespace std;
//Function to find number of strongly connected components in the graph.
	void dfs(vector<vector<int>>& adj, stack<int>&st, vector<int>&vis, int src){
	    vis[src]=1;
	    
	    for(int u: adj[src]){
	        if(!vis[u]){
	            dfs(adj, st, vis, u);
	        }
	    }
	    
	    st.push(src);
	}
	
	void dfs2(vector<int>adj[], vector<int>&vis, int src){
	    vis[src]=1;
	    
	    for(int u: adj[src]){
	        if(!vis[u]){
	            dfs2(adj,vis, u);
	        }
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
       vector<int>vis(V,0);
       stack<int>st;
       
       for(int i=0; i<V; i++){
           if(!vis[i]){
               dfs(adj, st, vis,i);
           }
       }
       
       vector<int>revAdj[V];
       
       for(int i=0; i<adj.size(); i++){
           //To reuse the vis array, assigning values zero
           vis[i]=0;
           for(auto j:adj[i]){
               revAdj[j].push_back(i);
           }
       }
       
       int sccCount=0;
       while(!st.empty()){
           int node=st.top();
           st.pop();
           
           if(!vis[node]){
               sccCount++;
               dfs2(revAdj, vis, node);
           }
       }
       
       
       return sccCount;
    } 
 
int main(int argc, char const *argv[])
{
 
  return 0;
}