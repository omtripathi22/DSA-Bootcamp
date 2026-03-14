#include<bits/stdc++.h>
using namespace std;
int MOD=1e9+7;

int helper(int idx,int curr,int& n,int& limit,vector<int>&arr,vector<vector<int>>&dp){
    if(curr<0 || curr>limit){
        return 0;
    }
    if(idx>0 && curr==0){
        return 0;
    }
    if(idx==n){
        return 1;
    }
    
    if(idx>0 && arr[idx]!=0  && abs(arr[idx]-curr)>1){
        return 0;
    }
    
    if(dp[idx][curr]!=-1){
        return dp[idx][curr];
    }
    long long cnt=0;
    if(arr[idx]==0){
        if(idx==0){
            for(int i=1;i<=limit;i++){
                cnt=(cnt+helper(idx+1,i,n,limit,arr,dp))%MOD;
            }
        }
        else{
            cnt=(cnt+helper(idx+1,curr-1,n,limit,arr,dp)+helper(idx+1,curr,n,limit,arr,dp)+helper(idx+1,curr+1,n,limit,arr,dp))%MOD;
        }
    }
    else{
        cnt=(cnt+helper(idx+1,arr[idx],n,limit,arr,dp))%MOD;
    }

    return dp[idx][curr]=cnt;
}

int count(int& n,int& limit,vector<int>&arr){
    vector<vector<int>>dp(n,vector<int>(limit+1,-1));
    return helper(0,0,n,limit,arr,dp);
}

int main(){
    int n,m;
    cin >> n >>m;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int val=count(n,m,arr);
    cout << val ;
    return 0;
}