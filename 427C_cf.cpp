#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;

void Dfs(int node, vector<vector<int>> &rev, vector<bool> &vis, int &val, vector<int> &res)
{
    vis[node] = 1;
    for (auto &neigh : rev[node])
    {
        if (!vis[neigh])
        {
            Dfs(neigh, rev, vis, val, res);
        }
    }
    res[node] = val;
}

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto &neigh : adj[node])
    {
        if (!vis[neigh])
        {
            dfs(neigh, adj, vis, st);
        }
    }
    st.push(node);
}

int main()
{
    int n;
    cin >> n;
    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
    }

    int m;
    cin >> m;
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
            dfs(i, adj, vis, st);
        }
    }

    //cout << "hii";
    vis.assign(n + 1, 0);
    vector<int> res(n + 1);
    int val = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            Dfs(top, rev, vis, val, res);
            val++;
        }
    }

    vector<int> mini(val, INT_MAX);
    vector<int> ways(val, 0);
    for (int i = 1; i <= n; i++)
    {
        int idx = res[i];
        //cout << idx <<endl;
        if (mini[idx] > cost[i])
        {
            mini[idx] = cost[i];
            ways[idx] = 1;
        }
        else if (mini[idx] == cost[i])
        {
            ways[idx]++;
        }
    }

    //cout << val <<endl;
    long long cnt = 1;
    long long min_cost = 0;
    for (int i = 0; i < val; i++)
    {
        cnt = (cnt * ways[i]) % MOD;
        min_cost += mini[i];
    }

    cout << min_cost << " " << cnt;
}