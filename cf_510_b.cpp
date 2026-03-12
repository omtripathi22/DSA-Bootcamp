#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, int>

bool bfs(vector<string> adj, vector<vector<bool>> vis, int row, int col, int &n, int &m)
{
    vector<vector<pp>> parent(n, vector<pp>(m));
    queue<pp> q;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    q.push({row, col});
    parent[row][col] = {-1, -1};
    vis[row][col] = 1;
    char ch = adj[row][col];

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int i = p.first;
        int j = p.second;
        for (int d = 0; d < 4; d++)
        {
            int newRow = i + dir[d][0];
            int newCol = j + dir[d][1];
            if (newRow < 0 || newCol < 0 || newRow >= n || newCol >= m)
            {
                continue;
            }

            if (adj[newRow][newCol] == ch)
            {
                auto par=parent[i][j];
                int pRow=par.first;
                int pCol=par.second;
                if (!vis[newRow][newCol]){
                    q.push({newRow,newCol});
                    parent[newRow][newCol]={i,j};
                    vis[newRow][newCol]=1;
                }
                else if(vis[newRow][newCol] && (pRow!=newRow || pCol!=newCol)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> adj(n);
    for (int i = 0; i < n; i++)
    {
        cin >> adj[i];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (bfs(adj, vis, i, j, n, m))
            {
                cout << "Yes";
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        cout << "No";
    }
}