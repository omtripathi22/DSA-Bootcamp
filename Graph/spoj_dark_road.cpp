#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, int>

int main()
{
    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
        {
            break;
        }
        vector<vector<pp>> adj(n);
        int total = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, wt;
            cin >> u >> v >> wt;
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
            total += wt;
        }

        priority_queue<pp, vector<pp>, greater<>> pq;
        vector<bool> vis(n, 0);
        int ans = 0;
        pq.push({0, 0});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            int cost = top.first;

            if (vis[node])
            {
                continue;
            }
            vis[node] = 1;
            ans += cost;

            for (auto &child : adj[node])
            {
                int neigh = child.first;
                int wt = child.second;

                if (!vis[neigh])
                {
                    pq.push({wt, neigh});
                }
            }
        }

        cout << total - ans << endl;
    }
}