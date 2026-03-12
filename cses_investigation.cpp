#include<bits/stdc++.h>
using namespace std;
#define pp pair<long long,long long>
int MOD=1e9+7;

int main(){
    int n,m ;
    cin >> n >> m;
    vector<vector<pp>>adj(n+1);
    
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin >>u >> v >> wt;
        adj[u].push_back({v,wt});
    }

    priority_queue<pp,vector<pp>,greater<>>pq;
    vector<long long>dist(n+1,LLONG_MAX);
    vector<int>ways(n+1,0);
    vector<long long>mini(n+1,0);
    vector<long long>maxi(n+1,0);

    pq.push({0,1});
    dist[1]=0;
    ways[1]=1;

    while(!pq.empty()){
        auto top=pq.top();
        pq.pop();
        int node=top.second;
        if(top.first > dist[node]) continue;
        
        for(auto& child:adj[node]){
            int neigh=child.first;
            int wt=child.second;

            if(dist[neigh]>dist[node]+wt){
                dist[neigh]=dist[node]+wt;
                pq.push({dist[neigh],neigh});
                ways[neigh]=ways[node];
                mini[neigh]=mini[node]+1;
                maxi[neigh]=maxi[node]+1;
            }
            else if(dist[neigh]==dist[node]+wt){
                ways[neigh]=(ways[neigh]+ways[node])%MOD;
                mini[neigh]=min(mini[neigh],mini[node]+1);
                maxi[neigh]=max(maxi[neigh],maxi[node]+1);
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     cout << dist[i] <<" "<< ways[i] << endl; 
    // }

    cout << dist[n] <<" " << ways[n] <<" "<<mini[n]<<" " << maxi[n];
}