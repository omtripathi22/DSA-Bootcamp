#include <bits/stdc++.h>
using namespace std;

vector<bool> bfs(int src, vector<vector<int>> graph, int n)
{
    queue<int> q;
    vector<bool> vis(n + 1, 0);
    q.push(src);
    vis[src] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto neigh : graph[node])
        {
            if (!vis[neigh])
            {
                q.push(neigh);
                vis[neigh] = 1;
            }
        }
    }
    return vis;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    for (auto e : edges)
    {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    vector<bool> reachable = bfs(1, adj, n);
    for (int i = 1; i <= n; i++)
    {
        if (!reachable[i])
        {
            cout << "NO" << endl
                 << 1 << " " << i;
            return 0;
        }
    }

    reachable = bfs(1, rev, n);
    for (int i = 1; i <= n; i++)
    {
        if (!reachable[i])
        {
            cout << "NO" << endl
                 << i << " " << 1;
            return 0;
        }
    }

    cout << "YES";
    return 0;
}