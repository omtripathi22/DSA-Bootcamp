#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<vector<int>> &adj, vector<int> &col)
{
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &neigh : adj[node])
        {
            if (col[neigh] == col[node])
            {
                return false;
            }
            if (col[neigh] == -1)
            {
                col[neigh] = 1 - col[node];
                q.push(neigh);
            }
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool flag = false;
        vector<int> col(n + 1, -1);
        for (int i = 1; i <= n; i++)
        {
            if (col[i] != -1)
            {
                continue;
            }
            col[i] = 0;
            if (!bfs(i, adj, col))
            {
                flag = 1;
                break;
            }
        }
        
        if (flag)
        {
            cout << "Scenario #" << i<<":" << endl;
            cout << "Suspicious bugs found!" << endl;
        }
        else
        {
            cout << "Scenario #" << i<<":" << endl;
            cout << "No suspicious bugs found!" << endl;
        }
        i++;
    }
}