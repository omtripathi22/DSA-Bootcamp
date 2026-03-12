#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &dfs) {
    visited[node] = true;
    dfs.push_back(node);

    for (int i : adj[node]) {
        if (!visited[i]) {
            DFS(i, visited, adj, dfs);
        }
    }
}

void solve(vector<vector<int>> &adj, int n) {
    vector<int> dfs;
    vector<bool> visited(n + 1, false);

    DFS(1, visited, adj, dfs);

    int i = 0;
    while (i < n) {
        cout << "? " << dfs[i] << " "
             << ((i + 1 == n) ? dfs[i] : dfs[i + 1]) << endl;
        cout.flush();

        int output;
        cin >> output;

        if (output == 1) break;
        i += 2;
    }

    if (i == n - 1) {
        cout << "! " << dfs[i] << endl;
        cout.flush();
        return;
    }

    cout << "? " << dfs[i] << " " << dfs[i] << endl;
    cout.flush();

    int output;
    cin >> output;

    if (output == 1)
        cout << "! " << dfs[i] << endl;
    else
        cout << "! " << dfs[i + 1] << endl;

    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        solve(adj, n);
    }

    return 0;
}
