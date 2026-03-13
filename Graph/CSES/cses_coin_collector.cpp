#include <bits/stdc++.h>
using namespace std;

long long helper(int node,vector<vector<int>> &graph, vector<bool> &vis,vector<long long>&dp,vector<long long>&cost){
    vis[node]=1;
    long long num=0;
    for(auto& neigh:graph[node]){
        if(!vis[neigh]){
           num=max(num,helper(neigh,graph,vis,dp,cost));
        }
        else{
            num=max(num,dp[neigh]);
        }
    }

    return dp[node]=num+cost[node];
}

void Dfs(int node, vector<vector<int>> &rev, vector<bool> &vis,int& cnt,vector<int>&res){
    vis[node] = 1;
    for (auto &neigh : rev[node])
    {
        if (!vis[neigh])
        {
            Dfs(neigh,rev,vis,cnt,res);
        }
    }
    res[node]=cnt;
}

void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto &neigh : adj[node])
    {
        if (!vis[neigh])
        {
            dfs(neigh, adj, vis, st);
        }
    }
    st.push(node);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> coins(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> coins[i];
    }

    vector<vector<int>> adj(n + 1);
    vector<vector<int>> rev(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    vector<bool> vis(n + 1, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vis.assign(n+1,0);
    vector<int>res(n+1);
    int cnt=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        if(!vis[top]){
            Dfs(top,rev,vis,cnt,res);
            cnt++;
        }
    }

    vector<long long>cost(cnt,0);
    vector<vector<int>>graph(cnt);
    set<pair<int,int>>s;
    vector<int>indegree(cnt,0);
    for(int i=1;i<=n;i++){
        int idx=res[i];
        cost[idx]+=coins[i];
        for(auto& neigh:adj[i]){
            int new_idx=res[neigh];
            if(idx!=new_idx && !s.count({idx,new_idx})){
                graph[idx].push_back(new_idx);
                s.insert({idx,new_idx});
                indegree[new_idx]++;
            }
        }
    }

    vector<long long>dp(cnt,-1);
    long long maxi=0;
    vis.assign(cnt,0);
    for(int i=0;i<cnt;i++){
        if(indegree[i]==0){
            maxi=max(maxi,helper(i,graph,vis,dp,cost));
        }
    }

    cout << maxi;
}