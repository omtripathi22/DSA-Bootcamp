#include<bits/stdc++.h>
using namespace std;

int main(){
    int num,tar;
    cin >> num >> tar;
    queue<int>q;
    q.push(num);
    int step=0;
    unordered_set<int>vis;

    while(!q.empty()){
        int size=q.size();
        bool found=0;
        while(size--){
            int val=q.front();
            q.pop();
            if(vis.count(val)){
                continue;
            }
            vis.insert(val);
            if(val==tar){
                found=1;
                break;
            }

            if(val>0 ){
               q.push(val-1);
            }
            if(val<tar){
                q.push(2*val);
            }
        }
        if(found){
            break;
        }
        step++;
    }
    cout << step;
}