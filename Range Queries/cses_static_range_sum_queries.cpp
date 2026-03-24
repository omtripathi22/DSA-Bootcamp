#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n,q;
    cin >> n >>q;
    vector<ll>arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    vector<ll>prefix(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+arr[i];
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        cout << prefix[r]-prefix[l-1] << endl;
    }
}