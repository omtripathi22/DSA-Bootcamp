#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, int>

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pp>> adj(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }

    priority_queue<pair<long long, pp>, vector<pair<long long, pp>>, greater<>> pq;
    vector<vector<long long>> dist(n + 1, vector<long long>(2, LLONG_MAX));
    vector<vector<bool>> final(n + 1,vector<bool>(2,0));
    pq.push({0, {1, 0}});
    dist[1][0] = 0;

    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int node = p.second.first;
        bool state = p.second.second;

        if (final[node][state])
        {
            continue;
        }
        final[node][state] = 1;

        for (auto &child : adj[node])
        {
            int cost = child.second;
            int neigh = child.first;
            long long new_cost = 0;
            if (state == 1)
            {
                new_cost =dist[node][state]+ cost;
                if (dist[neigh][state] > new_cost)
                {
                    dist[neigh][state] = new_cost;
                    pq.push({new_cost, {neigh, state}});
                }
            }
            else{
                new_cost =dist[node][state]+ cost;
                if (dist[neigh][state] > new_cost)
                {
                    dist[neigh][state] = new_cost;
                    pq.push({new_cost, {neigh, state}});
                }

                new_cost =dist[node][state]+ cost/2;
                if (dist[neigh][1] > new_cost)
                {
                    dist[neigh][1] = new_cost;
                    pq.push({new_cost, {neigh, 1}});
                }
            }
        }
    }

    cout << dist[n][1];
}

// test case
//  10 12
//  1 2 4
//  5 7 1
//  4 6 4
//  7 9 3
//  9 10 1
//  7 8 5
//  1 3 1
//  6 7 4
//  4 5 1
//  3 4 2
//  8 10 5
//  2 4 3