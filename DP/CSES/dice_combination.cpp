#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;

int helper(int sum,vector<int>&dp){
    if(sum<0){
        return 0;
    }
    if(sum==0){
        return 1;
    }
    
    if(dp[sum]!=-1){
        return dp[sum];
    }
    long long ans=0;
    for(int i=1;i<=6;i++){
        ans+=helper(sum-i,dp);
        ans%=MOD;
    }
    return dp[sum]=ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>dp(n+1,-1);
    cout << helper(n,dp);
    return 0;
}