#include<bits/stdc++.h>
using namespace std;
#define pp pair<long long,long long>

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pp>>adj(n+1);
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >>v >> wt;
        adj[u].push_back({v,wt});
    }

    vector<long long>dist(n+1,LLONG_MAX);
    vector<bool>final(n+1,0);
    priority_queue<pp,vector<pp>,greater<>>pq;
    pq.push({0,1});
    dist[1]=0;

    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        int node=top.second;
        if(final[node]){
            continue;
        }
        final[node]=1;

        for(auto& child:adj[node]){
            int neigh=child.first;
            long long wt=child.second;

            if(dist[neigh]>dist[node]+wt){
                dist[neigh]=dist[node]+wt;
                pq.push({dist[neigh],neigh});
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << dist[i] <<" ";
    }
    return 0;
}