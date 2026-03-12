#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m ,k;
    cin >>n >> m >> k;
    vector<vector<int>>edges(m,vector<int>(3));

    for(int i=0;i<m;i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector<int>storages(k);
    for(int i=0;i<k;i++){
        cin >> storages[i];
    }
    
    unordered_set<int>found;
    for(int i=0;i<k;i++){
        found.insert(storages[i]);
    }

    vector<vector<pair<int,int>>>graph(n+1,vector<pair<int,int>>());
    
    int ans=INT_MAX;
    for(auto& edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];

        graph[u].push_back({v,w});
        graph[v].push_back({u,w});

        if(found.count(u) && found.count(v)){
           continue;
        }

        if(found.count(u) || found.count(v)){
           ans=min(ans,w);
        }
    }

    if(k==0 || ans==INT_MAX){
        cout << -1 ;
    }
    else{
        cout << ans;
    }
}