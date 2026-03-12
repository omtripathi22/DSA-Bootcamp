#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>>& grid,vector<vector<bool>>&vis,int row,int col){
    vector<vector<int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
    vis[row][col]=1;
    
    for(int d=0;d<4;d++){
        int newRow=row+dir[d][0];
        int newCol=col+dir[d][1];

        if(newRow<0 || newCol<0 || newRow>=grid.size() || newCol>=grid[0].size()){
            continue;
        }

        if(grid[newRow][newCol]=='.' && !vis[newRow][newCol]){
            dfs(grid,vis,newRow,newCol);
        }
    }
}

int main(){
    int m,n;
    cin >> m >> n;

    vector<vector<char>> grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j] ;
        }
    }

    vector<vector<bool>>vis(m,vector<bool>(n,0));
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && grid[i][j]=='.'){
               count++;
               dfs(grid,vis,i,j);
            }
        }
    }

    cout << count ;
}