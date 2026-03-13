#include <bits/stdc++.h>
using namespace std;

void calculatePath(vector<int> &parent, vector<int> &res, int src, int dest)
{

    while (src != dest)
    {
        //cout << src <<" ";
        res.push_back(src);
        src = parent[src];
    }
    res.push_back(src);
    reverse(res.begin(),res.end());
}

bool dfs(int node, vector<vector<int>> &adj, vector<int> &parent, vector<bool> &vis, vector<bool> &path, vector<int> &res)
{
    vis[node] = 1;
    path[node] = 1;
    for (auto &neigh : adj[node])
    {
        if (!vis[neigh])
        {
            parent[neigh] = node;
            if (dfs(neigh, adj, parent, vis, path, res))
            {
                path[neigh]=0;
                return true;
            }
        }
        else if (path[neigh])
        {
            res.push_back(neigh);
            calculatePath(parent, res, node, neigh);
            path[neigh]=0;
            return true;
        }
    }
    path[node] = 0;
    return false;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adj(m + 1, vector<int>());
    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
    }

    vector<int> parent(m + 1, -1);
    vector<bool> vis(m + 1, 0);
    vector<bool> path(m + 1, 0);
    vector<int> res;
    bool flag = false;
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, adj, parent, vis, path, res))
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
    {
        cout << res.size() << endl;
        for (int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}