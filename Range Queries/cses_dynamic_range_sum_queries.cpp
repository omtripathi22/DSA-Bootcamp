#include <bits/stdc++.h>
using namespace std;
#define ll long long

void buildTree(vector<ll> &seg, vector<ll> &arr, int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    buildTree(seg, arr, 2 * idx + 1, l, mid);
    buildTree(seg, arr, 2 * idx + 2, mid + 1, r);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

void update(vector<ll> &seg, int idx, int l, int r, int i, int val)
{
    if (l == r)
    {
        seg[idx] = val;
        return;
    }

    int mid = (l + r) / 2;
    if (mid >= i)
    {
        update(seg, 2 * idx + 1, l, mid, i, val);
    }
    else
    {
        update(seg, 2 * idx + 2, mid + 1, r, i, val);
    }
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

ll sum(vector<ll> &seg, int idx, int l, int r, int left, int right)
{
    if (l >= left && r <= right)
    {
        return seg[idx];
    }
    if (l > right || r < left)
    {
        return 0;
    }

    int mid = (l + r) / 2;
    return sum(seg, 2 * idx + 1, l, mid, left, right) + sum(seg, 2 * idx + 2, mid + 1, r, left, right);
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> seg(4 * n);
    buildTree(seg, arr, 0, 0, n - 1);
    for(int i=0;i<q;i++){
        int state,a,b;
        cin >> state >>a >>b;
        if(state-1){
            cout << sum(seg,0,0,n-1,a-1,b-1)<< endl;
        }
        else{
            update(seg,0,0,n-1,a-1,b);
        }
    }
}