#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> adj(n);
    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            q.push(i);
        }
        else
        {
            adj[arr[i] - 1].push_back(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            int node=q.front();
            q.pop();
            for(auto neigh:adj[node]){
                q.push(neigh);
            }
        }
        cnt++;
    }

    cout << cnt;
}