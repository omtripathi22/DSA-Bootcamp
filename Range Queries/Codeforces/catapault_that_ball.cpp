#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<int>&seg,vector<int>&arr,int idx,int l,int r){
    if(l==r){
        seg[idx]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(seg,arr,2*idx+1,l,mid);
    buildTree(seg,arr,2*idx+2,mid+1,r);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}

int helper(vector<int>&seg,int idx,int l,int r,int left,int right){
    if(left<=l && right>=r){
        return seg[idx];
    }
    if(l>right || r<left){
        return 0;
    }
    int mid=(l+r)/2;
    return max(helper(seg,2*idx+1,l,mid,left,right),helper(seg,2*idx+2,mid+1,r,left,right));
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >>q;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        vector<int>seg(4*n);
        buildTree(seg,arr,0,0,n-1);
        int cnt=0;
        for(int i=0;i<q;i++){
            int a,b;
            cin >> a >> b;
            int num=helper(seg,0,0,n-1,a,b-2);
            //cout << num << endl;
            cnt+=((arr[a-1]>=num) || (a+1==b));
        }
        cout << cnt << endl;
    }
}