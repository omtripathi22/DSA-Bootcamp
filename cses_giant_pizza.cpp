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
            if(col[neigh]==col[node]){
                return false;
            }
            else if(col[neigh]==-1){
                col[neigh]=1-col[node];
                q.push(neigh);
            }
        }
    }
    return true;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        string s1, s2;
        int u ,v;
        cin >> s1 >>u >> s2>>v;
        if (s1[0] == s2[0])
        {
            continue;
        }

        cout << u <<" "<< v <<endl ;
        // int u = stoi(s1.substr(2, s1.size()-2));
        // int v = stoi(s2.substr(2, s2.size()-2));
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

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
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    vector<char>ans(n+1);
    for(int i=1;i<=n;i++){
        if(col[i]==0){
            ans[i]='+';
        }
        else{
            ans[i]='-';
        }
    }

    for(int i=1;i<=n;i++){
        cout << ans[i] <<" ";
    }
}