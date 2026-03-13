#include <bits/stdc++.h>
using namespace std;
#define pp pair<long long, long long>

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edges(m, vector<int>(3));
    vector<vector<pp>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    for (auto e : edges)
    {
        int u = e[0];
        int v = e[1];
        int wt = e[2];
        adj[u].push_back({v, wt});
    }

    priority_queue<pp, vector<pp>, greater<>> pq;
    vector<long long> dist;
    vector<int>count(n+1,0);
    pq.push({0, 1});

    while (!pq.empty() && dist.size() < k)
    {
        auto p = pq.top();
        pq.pop();
        int node = p.second;
        long long cost = p.first;

        if(count[node]>=k){
            continue;
        }
        count[node]++;

        if (node == n)
        {
            //cout << " hii";
            dist.push_back(cost);
        }

        for (auto &it : adj[node])
        {
            int neigh = it.first;
            long long curr_cost = it.second;
            pq.push({cost + curr_cost, neigh});
        }
    }

    for(int i=0;i<k;i++){
        cout << dist[i] <<" ";
    }
    return 0;
}