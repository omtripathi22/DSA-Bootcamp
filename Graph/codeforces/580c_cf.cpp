#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> cats(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cats[i];
    }

    vector<vector<int>>edges(n-1,vector<int>(2));
    vector<vector<int>>adj(n+1);
    for(int i=0;i<n-1;i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    for(auto e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    queue<pair<int,int>>q;
    vector<bool>vis(n,0);
    if(cats[0]==1){
        q.push({1,1});
    }
    else{
        q.push({1,0});
    }

    vis[0]=1;
    int count=0;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int node=p.first;
        int cat=p.second;
        if(cat>m){
            continue;
        }
        bool leaf=true;
        for(auto& neigh:adj[node]){
            if(vis[neigh-1]){
                continue;
            }
            leaf=false;
            vis[neigh-1]=1;
            if(cats[neigh-1]==1 ){
                if(cat+1>m){
                    continue;
                }
                q.push({neigh,cat+1});
            }
            else{
                q.push({neigh,0});
            }
        }
        if(leaf){
            count++;
        }
    }

    cout << count;
}