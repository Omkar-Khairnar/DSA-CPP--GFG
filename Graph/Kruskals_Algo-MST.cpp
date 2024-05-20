#include <bits/stdc++.h>
 
using namespace std;
class DisjointSet
{
    vector<int>  parent, size;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int ultimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = ultimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ultP_u = ultimateParent(u);
        int ultP_v = ultimateParent(v);

        if (ultP_u == ultP_v)
        {
            return;
        }

        if (size[ultP_u] > size[ultP_v])
        {
            parent[ultP_v] = ultP_u;
            size[ultP_u] += size[ultP_v];
        }
        else
        {
            parent[ultP_u] = ultP_v;
            size[ultP_v] += size[ultP_u];
        }
    }
};


 int spanningTree(int V, vector<vector<int>> adj[])
    {
        // vector of {wt,{u,v}}
        vector<pair<int, pair<int,int>>>edges;
        for(int i=0; i<V; i++){
            for(auto it: adj[i]){
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        //Sorting the edges based on their weight
        sort(edges.begin(), edges.end());
        DisjointSet ds(V);
        int MSTwt=0;
        for(auto it: edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
         
            if(ds.ultimateParent(v) != ds.ultimateParent(u)){
                MSTwt+=wt;
                ds.unionBySize(u,v);
            }
        }
        return MSTwt;
        
    }
 
int main(int argc, char const *argv[])
{
 
  return 0;
}