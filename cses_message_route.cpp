#include <bits/stdc++.h>
using namespace std;

vector<int> calculatePath(vector<int> &parent, int &dest)
{
    vector<int> res;
    int idx = dest-1;
    res.push_back(idx);
    while (parent[idx] != -1)
    {
        
        int node = parent[idx];
        res.push_back(node);
        idx = node;
    }
    reverse(res.begin(),res.end());
    return res;
}

// void print(vector<int>& parent){
//     for(int i=0;i<parent.size();i++){
//         cout << parent[i] <<" ";
//     }
//     cout << endl;
// }

vector<int> bfs(vector<vector<int>> &adj, int dest)
{
    vector<int> parent(dest, 0);
    vector<bool> vis(dest, 0);
    parent[1] = -1;
    queue<int> q;
    q.push(1);
    vis[1]=true;
    vector<int> ans;
    bool flag = false;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int node = q.front();
            q.pop();
            for (auto &neigh : adj[node])
            {
                if (!vis[neigh])
                {
                    q.push(neigh);
                    vis[neigh]=1;
                    parent[neigh] = node;
                }
                if (neigh == dest-1)
                {
                    //print(parent);
                    ans = calculatePath(parent, dest);
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> edges(n, vector<int>(2));

    for (int i = 0; i < n; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>> adj(m + 1, vector<int>());
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //cout << "hii" << endl;
    vector<int> path = bfs(adj, m + 1);

    if (path.size() == 0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        cout << path.size() << endl;
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
    }
    return 0;
}