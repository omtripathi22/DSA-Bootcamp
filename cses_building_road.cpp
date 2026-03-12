#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

void bfs(vector<list<int>> &graph, vector<bool> &vis, int row)
{
    queue<int> q;
    q.push(row);
    vis[row] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int &neigh : graph[node])
        {
            if (!vis[neigh])
            {
                q.push(neigh);
                vis[neigh] = 1;
            }
        }
    }
}

vector<vector<int>> helper(vector<vector<int>> &edge, int &m, int &n)
{
    vector<vector<int>> res;
    vector<bool> vis(m + 1, 0);
    vector<list<int>> graph(m + 1, list<int>());

    for (int i = 0; i < n; i++)
    {
        int u = edge[i][0];
        int v = edge[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    // int count=0;
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i])
        {
            if (i > 1)
            {
                res.push_back({i - 1, i});
            }
            // count++;
            bfs(graph, vis, i);
        }
    }
    // cout << count << endl;
    return res;
}

int main()
{
    int m;
    int n;
    cin >> m >> n;
    vector<vector<int>> edge(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> edge[i][0] >> edge[i][1];
    }
    vector<vector<int>> ans = helper(edge, m, n);
    int size = ans.size();
    cout << size << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}