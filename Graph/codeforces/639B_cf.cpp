#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d, h;
    cin >> n >> d >> h;

    if (n <= d || d > 2 * h)
    {
        cout << -1;
        return 0;
    }

    if (h == 1 && d == 1 && n > 2)
    {
        cout << -1;
        return 0;
    }

    vector<vector<int>> adj(n + 1);
    vector<pair<int, int>> edges;
    int node = 1;
    for (int i = 0; i < h; i++)
    {
        int neigh = node + 1;
        adj[node].push_back(neigh);
        edges.push_back({node, neigh});
        node = neigh;
    }

    int curr = node;
    node = 1;
    d = d - h;
    for (int i = 0; i < d; i++)
    {
        int neigh = curr + 1;
        adj[node].push_back(neigh);
        edges.push_back({node, neigh});
        node = neigh;
        curr = neigh;
    }

    if (d == 0)
    {
        node = 2;
    }
    else
    {
        node = 1;
    }
    for (int neigh = curr + 1; neigh <= n; neigh++)
    {
        adj[node].push_back(neigh);
        edges.push_back({node, neigh});
    }

    for (int i = 0; i < edges.size(); i++)
    {
        cout << edges[i].first << " " << edges[i].second << endl;
    }
}