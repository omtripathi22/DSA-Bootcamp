#include<bits/stdc++.h>
using namespace std;

vector<int> getDigit(int n){
    vector<int>temp;
    while(n>0){
        int d=n%10;
        n=n/10;
        if(d!=0){
temp.push_back(d);
        }
        
    }
    return temp;
}

int helper(int num,vector<int>&dp){
    if(num==0){
        //cout << step;
        return 0;
    }
    
    if(dp[num]!=-1){
        return dp[num];
    }
    vector<int>digit=getDigit(num);
    int ans=INT_MAX;
    for(int i=0;i<digit.size();i++){
        if(num>=digit[i]){
            ans=min(ans,1+helper(num-digit[i],dp));
        }
    }
    return dp[num]=ans;
}

int main(){
    int n;
    cin >>n;
    vector<int>dp(n+1,-1);
    cout << helper(n,dp);
}