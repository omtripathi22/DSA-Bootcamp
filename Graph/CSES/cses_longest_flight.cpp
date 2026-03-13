#include <bits/stdc++.h>
using namespace std;

// void dfs(int node, int dest, vector<int> &ans, vector<int> &temp, vector<vector<int>> &adj)
// {
//     temp.push_back(node);
//     if (node == dest)
//     {
//         if (temp.size() > ans.size())
//         {
//             ans = temp;
//         }
//         return;
//     }

//     for (auto &neigh : adj[node])
//     {
//         dfs(neigh,dest,ans,temp,adj);
//         temp.pop_back();
//     }
// }

void constructPath(int node, vector<int> &par, vector<int> &ans)
{
    if (node == 1)
    {
        ans.push_back(node);
        return;
    }
    constructPath(par[node],par,ans);
    ans.push_back(node);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    vector<int> ans;
    // vector<int> temp;
    // dfs(1, n, ans, temp, adj );

    vector<int> par(n + 1, -1);
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto &neigh : adj[node])
        {
            indegree[neigh]--;
            if (indegree[neigh] == 0)
            {
                q.push(neigh);
                par[neigh] = node;
            }
        }
    }

    constructPath(n, par, ans);
    if (par[n] == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}