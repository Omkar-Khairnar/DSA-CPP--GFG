#include <bits/stdc++.h>

using namespace std;
int timer = 1;
void dfs(vector<int> adj[], int node, int parent, vector<int> &vis, int tin[], int low[], vector<vector<int>> &bridges)
{
    vis[node] = 1;
    tin[node] = timer;
    low[node] = timer;
    timer++;

    for (int adjNode : adj[node])
    {
        if (adjNode == parent)
            continue;
        if (vis[adjNode] == 0)
        {
            dfs(adj, adjNode, node, vis, tin, low, bridges);
            low[node] = min(low[node], low[adjNode]);

            // checking its critical bridge or not
            if (low[adjNode] > tin[node])
            {
                bridges.push_back({adjNode, node});
            }
        }
        else
        {
            low[node] = min(low[node], low[adjNode]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    vector<vector<int>> bridges;
    int tin[n];
    int low[n];
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(adj, i, -1, vis, tin, low, bridges);
        }
    }
    return bridges;
}

int main(int argc, char const *argv[])
{

    return 0;
}