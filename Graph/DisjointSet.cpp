#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)  
    {
        rank.resize(n + 1, 0);
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

    void unionByRank(int u, int v)
    {
        int ultP_u = ultimateParent(u);
        int ultP_v = ultimateParent(v);

        if (ultP_u == ultP_v)
        {
            return;
        }

        if (rank[ultP_u] > rank[ultP_v])
        {
            parent[ultP_v] = ultP_u;
        }
        else if (rank[ultP_u] < rank[ultP_v])
        {
            parent[ultP_u] = ultP_v;
        }
        else
        {
            parent[ultP_u] = ultP_v;
            rank[ultP_v]++;
        }
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


int main(int argc, char const *argv[])
{
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // Check if 3 and 7 cconnected to same graph or not
    if (ds.ultimateParent(3) == ds.ultimateParent(7))
    {
        cout << "Same" << endl;
    }
    else
        cout << "Not Same" << endl;

    ds.unionByRank(3, 7);
    if (ds.ultimateParent(3) == ds.ultimateParent(7))
    {
        cout << "Same" << endl;
    }
    else
        cout << "Not Same" << endl;

    return 0;
}