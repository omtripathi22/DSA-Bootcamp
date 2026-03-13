#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pp>>adj(n+1);
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }

    priority_queue<pp,vector<pp>,greater<>>pq;
    vector<int>vis(n+1,0);
    pq.push({0,1});
    long long ans=0;

    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();

        int cost=top.first;
        int node=top.second;

        if(vis[node]){
            continue;
        }
        vis[node]=1;
        ans+=cost;

        for(auto& child:adj[node]){
            int neigh=child.first;
            int wt=child.second;

            if(!vis[neigh]){
                pq.push({wt,neigh});
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cout <<"IMPOSSIBLE";
            return 0;
        }
    }
    cout << ans;
}