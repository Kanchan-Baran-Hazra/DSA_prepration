#include <bits/stdc++.h>
using namespace std;


void helper(int i,int j,int org,int change,vector<vector<int>>& grid){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!=org) return;

    grid[i][j]=change;

    helper(i-1,j,org,change,grid);
    helper(i+1,j,org,change,grid);
    helper(i,j+1,org,change,grid);
    helper(i,j-1,org,change,grid);
}


int main(){
    // cout<<"hello";
    vector<vector<int>> grid ={{1,1,1},{1,1,0},{1,0,0}};

    // printing
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    int i=1;
    int j=1;
    int org=grid[i][j];
    int change=2;
    helper(i,j,org,change,grid);

    // printing
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}