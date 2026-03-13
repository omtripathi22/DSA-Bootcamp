#include <bits/stdc++.h>
using namespace std;

void dfs(int node, string &ans, vector<vector<int>> &adj, vector<bool> &have)
{
    ans += (node + 'a');
    for (auto &neigh : adj[node])
    {
        if (have[neigh])
        {
            have[neigh] = 0;
            dfs(neigh, ans, adj, have);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<string> edg(n);
    for (int i = 0; i < n; i++)
    {
        cin >> edg[i];
    }

    vector<vector<int>> adj(26);
    vector<bool> have(26, 0);
    vector<int> indegree(26, 0);

    for (auto s : edg)
    {
        int u = s[0] - 'a';
        have[u] = 1;
        for (int i = 1; i < s.size(); i++)
        {
            int v = s[i] - 'a';
            adj[u].push_back(v);
            indegree[v]++;
            have[v] = 1;

            u = v;
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (!have[i])
        {
            continue;
        }
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    string ans = "";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        if (have[node])
        {
            have[node] = 0;
            dfs(node, ans, adj, have);
        }
    }

    cout << ans;
}

// atoumrydhfgwekjilbpsvqncx