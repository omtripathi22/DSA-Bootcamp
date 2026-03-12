#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >>m;
    vector<vector<int>>adj(n+1);
    vector<int>indegree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >>v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int>res;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto& neigh:adj[node]){
            indegree[neigh]--;
            if(indegree[neigh]==0){
                q.push(neigh);
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(indegree[i]>0){
            cout <<"IMPOSSIBLE";
            return 0;
        }
    }

    for(int i=0;i<res.size();i++){
        cout << res[i] <<" ";
    }
}