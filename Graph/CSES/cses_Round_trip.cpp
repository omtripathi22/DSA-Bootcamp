#include<bits/stdc++.h>
using namespace std;

void calculatePath(vector<int>&parent,vector<int>&path,int src,int dest){
     
    while(src!=dest){
        path.push_back(src);
        src=parent[src];
    }
    path.push_back(src);
}

bool dfs(int src,vector<vector<int>>&adj,vector<int>&parent,vector<bool>vis,vector<int>&path){
    vis[src]=1;

    for(auto& neigh:adj[src]){
        if(!vis[neigh]){
            vis[neigh]=1;
            parent[neigh]=src;
            if(dfs(neigh,adj,parent,vis,path)){
                return true;
            }
        }
        else if(parent[src]!=neigh){
            path.push_back(neigh);
            calculatePath(parent,path,src,neigh);
            return true;
        }
    }
    return false;
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>>edges(n,vector<int>(2));
    for(int i=0;i<n;i++){
        cin >> edges[i][0] >> edges[i][1];
    }

    vector<vector<int>>adj(m+1,vector<int>());
    for(auto& e:edges){
        int u=e[0];
        int v=e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>parent(m+1,-1);
    vector<bool>vis(m+1,0);
    vector<int>path;
    bool flag=false;
    for(int i=1;i<=m;i++){
        if(parent[i]==-1){
           if(dfs(i,adj,parent,vis,path)){
            flag=true;
              break;
           }
        }
    }
    
    if(flag){
        cout << path.size() << endl;
        for(int i=0;i<path.size();i++){
            cout << path[i] <<" ";
        }
    }
    else{
        cout << "IMPOSSIBLE" ;
    }
    return 0;
}