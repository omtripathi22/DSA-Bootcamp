#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> adj(n + 1, vector<long long>(n + 1, LLONG_MAX));
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = min(adj[u][v], (long long)wt);
        adj[v][u] = min(adj[v][u], (long long)wt);
    }

    for (int i = 0; i <= n; i++)
    {
        adj[i][i] = 0;
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adj[i][k] == LLONG_MAX || adj[k][j] == LLONG_MAX)
                {
                    continue;
                }

                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        if (adj[u][v] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << adj[u][v] << endl;
        }
    }
}