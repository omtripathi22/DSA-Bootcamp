#include<bits/stdc++.h>
using namespace std;

int helper(int idx,int cost,vector<int>&price,vector<int>&pages,vector<vector<int>>&dp){
    if(idx==price.size()){
        return 0;
    }
    if(dp[idx][cost]!=-1){
        return dp[idx][cost];
    }

    int pick=0;
    if(price[idx]<=cost){
        pick=helper(idx+1,cost-price[idx],price,pages,dp)+pages[idx];
    }
    int not_pick=helper(idx+1,cost,price,pages,dp);

    return dp[idx][cost]=max(pick,not_pick);
}

int main(){
    int n,x;
    cin >> n >>x;
    vector<int>price(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin >> price[i];
    }
    for(int i=0;i<n;i++){
        cin >> pages[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    //cout << helper(0,x,price,pages,dp);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            int pick=0;
            if(j>=price[i-1]){
                pick=dp[i-1][j-price[i-1]]+pages[i-1];
            }
            int not_pick=dp[i-1][j];
            dp[i][j]=max(pick,not_pick);
        }
    }
    cout << dp[n][x];
}