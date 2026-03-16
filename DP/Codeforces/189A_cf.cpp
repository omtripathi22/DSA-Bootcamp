#include <bits/stdc++.h>
using namespace std;

int helper(int len, int a, int b, int c, vector<int> &dp)
{
    if (len == 0)
    {
        return 0;
    }
    if (dp[len] != -1)
    {
        return dp[len];
    }
    int pickA=INT_MIN;
    int pickB=INT_MIN;
    int pickC=INT_MIN;
    if (len >= a)
    {
        pickA = helper(len - a, a, b, c, dp);
        //cout << pickA <<" ";
    }
    if (len >= b)
    {
        pickB = helper(len - b, a, b, c, dp);
        //cout << pickB <<" " ;
    }
    if (len >= c)
    {
        pickC = helper(len - c, a, b, c, dp);
        //cout << pickC <<" ";
    }
   // cout<<pickA <<" "<<pickB <<" "<< pickC << endl;
    int mini=max({pickA,pickB,pickC});
    return dp[len]=(mini==INT_MIN)?INT_MIN:mini+1;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> dp(n + 1, -1);
    cout << helper(n, a, b, c, dp);
}