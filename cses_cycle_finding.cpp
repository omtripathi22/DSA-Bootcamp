#include <bits/stdc++.h>
using namespace std;

vector<int> helper(int node, vector<int> &parent)
{
    vector<int> temp;
    int par = node;
    temp.push_back(node);
    int neigh = parent[node];
    while (par != neigh)
    {
        temp.push_back(neigh);
        node = neigh;
        neigh = parent[node];
    }
    temp.push_back(par);
    reverse(temp.begin(),temp.end());
    return temp;
}

vector<int> hasCycle(int node, int par, vector<int> &parent, int n)
{
    for (int i = 0; i < n; i++)
    {
        //cout << node << " ";
        node = par;
        par = parent[node];
    }
    //cout << endl;
    return helper(node, parent);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(3));

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<long long> dist(n + 1, 0);
    vector<int> parent(n + 1);
    for (int i = 1; i < n; i++)
    {
        for (auto e : edges)
        {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            if (dist[v] > dist[u] + wt)
            {
                parent[v] = u;
                dist[v] = dist[u] + wt;
            }
        }
    }

    // for (int i = 0; i < n + 1; i++)
    // {
    //     cout << parent[i] << " ";
    // }
    // cout << endl;
    bool flag = false;
    vector<int> cycle;
    for (auto e : edges)
    {
        int u = e[0];
        int v = e[1];
        int wt = e[2];
        if (dist[v] > dist[u] + wt)
        {
            flag = true;
            parent[v]=u;
            cycle = hasCycle(v, u, parent, n);
            break;
        }
    }

    if (flag)
    {
        cout << "YES";
        cout << endl;
        for (int i = 0; i < cycle.size(); i++)
        {
            cout << cycle[i] << " ";
        }
    }
    else
    {
        cout << "NO";
    }
}