#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<vector<int>> &seg, vector<int> &arr, int idx, int l, int r)
{
    if (l == r)
    {
        seg[idx][0] = arr[l];
        seg[idx][1] = arr[l];
        seg[idx][2] = 1;
        return;
    }
    int mid = (l + r) / 2;
    buildTree(seg, arr, 2 * idx + 1, l, mid);
    buildTree(seg, arr, 2 * idx + 2, mid + 1, r);
    seg[idx][0] = min(seg[2 * idx + 1][0], seg[2 * idx + 2][0]);
    seg[idx][1] = max(seg[2 * idx + 1][1], seg[2 * idx + 2][1]);
    seg[idx][2] = seg[2 * idx + 1][2] + seg[2 * idx + 2][2];
}

void update(vector<vector<int>> &seg, int idx, int l, int r, int i, int val)
{
    if (l == r)
    {
        seg[idx][0] = val;
        seg[idx][1] = val;
        return;
    }

    int mid = (l + r) / 2;
    if (i <= mid)
    {
        update(seg, 2 * idx + 1, l, mid, i, val);
    }
    else
    {
        update(seg, 2 * idx + 2, mid + 1, r, i, val);
    }
    seg[idx][0] = min(seg[2 * idx + 1][0], seg[2 * idx + 2][0]);
    seg[idx][1] = max(seg[2 * idx + 1][1], seg[2 * idx + 2][1]);
}

int helper(vector<vector<int>> &seg, int idx, int l, int r, int num1, int num2){
    int mini=seg[idx][0];
    int maxi=seg[idx][1];
    if(num1<=mini && num2>=maxi){
        return seg[idx][2];
    }
    if(num1>maxi || num2<mini){
        return 0;
    }
    int mid=(l+r)/2;
    return helper(seg,2*idx+1,l,mid,num1,num2)+helper(seg,2*idx+2,mid+1,r,num1,num2);
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> seg(4 * n, vector<int>(3)); // 0->min,1->max,2->frequency
    buildTree(seg, arr, 0, 0, n - 1);
    for(int i=0;i<q;i++){
        int a,b;
        char ch;
        cin >> ch >>a >>b;
        if(ch=='!'){
            update(seg,0,0,n-1,a-1,b);
        }
        else{
            cout << helper(seg,0,0,n-1,a,b) << endl;
        }
    }
}