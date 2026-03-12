#include <bits/stdc++.h>
using namespace std;

void Dfs(int node, vector<bool> &vis, vector<vector<int>> &rev, int cnt, vector<int> &res)
{
    vis[node] = 1;
    for (auto &neigh : rev[node])
    {
        if (!vis[neigh])
        {
            Dfs(neigh, vis, rev, cnt, res);
        }
    }
    res[node] = cnt;
}

void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;
    for (auto &neigh : adj[node])
    {
        if (!vis[neigh])
        {
            dfs(neigh, vis, adj, st);
        }
    }
    st.push(node);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    vector<bool> vis(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    vis.assign(n + 1, 0);
    int cnt = 0;
    vector<int> res(n + 1, 0);

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if(!vis[top]){
            cnt++;
            Dfs(top, vis, rev, cnt, res);
        }
    }

    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << res[i] << " ";
    }
    return 0;
}