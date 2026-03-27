#include <bits/stdc++.h>
using namespace std;
#define ll long long
int MOD = 1e9 + 7;

int helper(vector<int> &arr, int idx, int tar, vector<ll> &dp)
{
    if (tar == 0)
    {
        return 1;
    }
    if (tar < 0)
    {
        return 0;
    }
    if (dp[tar] != -1)
    {
        return dp[tar];
    }

    ll cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        cnt += helper(arr, idx + 1, tar - arr[i], dp);
    }
    return dp[tar] = cnt%MOD;
}

int main()
{
    int n, tar;
    cin >> n >> tar;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll>dp(tar + 1, -1);
    cout << helper(arr, 0, tar, dp);
}