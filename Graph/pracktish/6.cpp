// No of islands
#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& grid,vector<vector<bool>>& mark,int i,int j,int n,int m){

    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1 || mark[i][j]) return;

    mark[i][j]=true;

    helper(grid,mark,i+1,j,n,m);
    helper(grid,mark,i-1,j,n,m);
    helper(grid,mark,i,j+1,n,m);
    helper(grid,mark,i,j-1,n,m);
}

int no_Island(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>> mark(n,vector<bool>(m,false));
    int count=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1 && !mark[i][j]){
                count++;
                helper(grid,mark,i,j,n,m);
            }
        }
    }

    return count;
}


int main(){
    // cout<<"hello";
    vector<vector<int>> grid(4,vector<int>(5,0));

    grid[0][0]=1;
    grid[0][1]=1;
    grid[1][0]=1;
    grid[1][1]=1;
    grid[2][2]=1;
    grid[3][3]=1;
    grid[3][4]=1;
    grid[0][4]=1;
    grid[1][4]=1;

    cout<<no_Island(grid);
    return 0;
}