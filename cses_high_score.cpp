#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));
    vector<vector<int>> rev(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        rev[edges[i][1]].push_back(edges[i][0]);
    }

    vector<long long> dist(n + 1, -1e18);
    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if (dist[u] != -1e18 && dist[v] < dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    vector<int> bad(n + 1, 0);
    for (auto &e : edges)
    {
        int u = e[0];
        int v = e[1];
        int wt = e[2];

        if (dist[u] != -1e18 && dist[v] < dist[u] + wt)
        {
            bad[v] = 1;
        }
    }

    queue<int> q;
    vector<int> canReach(n + 1, 0);
    q.push(n);
    canReach[n] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int p : rev[node])
        {
            if (!canReach[p])
            {
                canReach[p] = 1;
                q.push(p);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (bad[i] && canReach[i])
        {
            cout << -1;
            return 0;
        }
    }

    cout << dist[n];
}