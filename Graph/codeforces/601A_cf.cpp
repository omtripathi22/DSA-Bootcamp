#include<bits/stdc++.h>
using namespace std;
#define pp pair<int,int>

int main(){
    int n, m;
    cin >> n >>m;
    vector<vector<int>>adj(n+1,vector<int>(n+1,0));
    
    //1->railway
    //0->road
    for(int i=0;i<m;i++){
        int u ,v;
        cin >>u >>v;
        adj[u][v]=1;
        adj[v][u]=1;
        
    }

    vector<int>railway(n+1,-1);
    vector<int>road(n+1,-1);
    queue<pp>q;
    q.push({1,0});
    //cout << endl;

    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int node=front.first;
        int cost=front.second;
        //cout << node <<" "<< cost << endl;
        if(railway[node]!=-1){
            continue;
        }
        railway[node]=cost;

        for(int i=1;i<=n;i++){
            if(adj[node][i] && railway[i]==-1){
                q.push({i,cost+1});
            }
        }
    }
    //cout << endl;

    q.push({1,0});
    while(!q.empty()){
        auto front=q.front();
        q.pop();
        int node=front.first;
        int cost=front.second;
        //cout << node <<" "<< cost << endl;
        if(road[node]!=-1 ){
            continue;
        }
        road[node]=cost;

        for(int i=1;i<=n;i++){
            if(!adj[node][i] && road[i]==-1){
                q.push({i,cost+1});
            }
        }
    }

    if(road[n]==-1 || railway[n]==-1){
        cout << -1;
        return 0;
    }

    int dist=max(road[n],railway[n]);
    cout << dist;
    return 0;
}