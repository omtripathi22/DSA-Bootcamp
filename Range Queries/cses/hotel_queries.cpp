#include<bits/stdc++.h>
using namespace std;

void buildTree(vector<long long>&seg,vector<int>&rooms,int idx,int l,int r){
    if(l==r){
        seg[idx]=rooms[l];
        return;
    }
    int mid=(l+r)/2;
    buildTree(seg,rooms,2*idx+1,l,mid);
    buildTree(seg,rooms,2*idx+2,mid+1,r);
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
}

int helper(vector<long long>&seg,int idx,int l,int r,int need){
    if(l==r){
        if(seg[idx]>=need){
            seg[idx]-=need;
            return l;
        }
        else{
            return -1;
        }
    }
    
    int ans=-1;
    int mid=(l+r)/2;
    if(seg[2*idx+1]>=need){
        ans=helper(seg,2*idx+1,l,mid,need);
    }
    else if(seg[2*idx+2]>=need ){
        ans=helper(seg,2*idx+2,mid+1,r,need);
    }
    seg[idx]=max(seg[2*idx+1],seg[2*idx+2]);
    return ans;
}

int main(){
    int n,m;
    cin >> n >>m;
    vector<int>rooms(n);
    for(int i=0;i<n;i++){
        cin >> rooms[i];
    }
    vector<long long>seg(4*n);
    buildTree(seg,rooms,0,0,n-1);

    for(int i=0;i<m;i++){
        int val;
        cin >> val;
        cout << helper(seg,0,0,n-1,val)+1 << " ";
    }
}