#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> edges(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adj(m + 1);
    vector<int> indegree(m + 1, 0);
    queue<int> q;
    for (auto e : edges)
    {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        indegree[v]++;
    }

    for (int i = 1; i <= m; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<long long> dist(m + 1, 0);
    int MOD = 1e9 + 7;
    dist[1]++;
    //cout << endl;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto neigh : adj[node])
        {
            indegree[neigh]--;
            dist[neigh] = (dist[neigh] + dist[node]) % MOD;
            //cout << neigh << " " << dist[neigh] << endl;
            if (indegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }
    
    cout << dist[m];
}