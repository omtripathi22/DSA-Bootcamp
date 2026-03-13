#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<vector<int>>& adj,vector<int>& team,int src){
    queue<int>q;
    q.push(src);
    team[src]=0;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto& neigh:adj[node]){
            if(team[neigh]==-1){
                team[neigh]=1-team[node];
                q.push(neigh);
            }
            else if(team[neigh]==team[node]){
                return false;
            }
        }
    }
    return true;
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

    vector<vector<int>> adj(m, vector<int>());
    for (auto &e : edges)
    {
        int u = e[0] - 1;
        int v = e[1] - 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> team(m, -1);
    for (int i = 0; i < m; i++)
    {
        if (team[i] == -1)
        {
            if (!isPossible(adj, team, i))
            {
                cout << "IMPOSSIBLE";
                return 0;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cout << team[i] + 1 << " ";
    }
    return 0;
}