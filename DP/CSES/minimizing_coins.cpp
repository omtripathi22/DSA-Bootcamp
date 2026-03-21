#include <bits/stdc++.h>
using namespace std;

int helper(int idx, int amt, vector<int> &arr, vector<vector<int>> &dp)
{
    if (amt == 0)
    {
        return 0;
    }
    if (idx == arr.size())
    {

        return INT_MAX;
    }
    if (dp[idx][amt] != -1)
    {
        return dp[idx][amt];
    }

    int pick = INT_MAX;
    if (amt >= arr[idx])
    {
        pick = helper(idx, amt - arr[idx], arr, dp);
        pick = (pick == INT_MAX) ? INT_MAX : pick + 1;
    }
    int not_pick = helper(idx + 1, amt, arr, dp);
    return dp[idx][amt] = min(pick, not_pick);
}

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(x+1, INT_MAX));
    // int ans = helper(0, x, arr, dp);
    // cout << ((ans == INT_MAX) ? -1 : ans);

    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            int pick=INT_MAX;
            if(j>=arr[i-1]){
               pick=dp[i][j-arr[i-1]];
               pick=(pick==INT_MAX)?INT_MAX:pick+1;
            }
            int not_pick=dp[i-1][j];
            dp[i][j]=min(pick,not_pick);
        }
    }
    int ans=dp[n][x];
    cout << ((ans == INT_MAX) ? -1 : ans);
}