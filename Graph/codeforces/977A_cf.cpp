#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    while(k>0 && n>0){
        int digit=n%10;
        if(digit!=0){
            n-=1;
        }
        else{
            n/=10;
        }
        k--;
    }

    cout << n;
}