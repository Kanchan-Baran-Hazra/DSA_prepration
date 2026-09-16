#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>>& grid,vector<vector<bool>>& mark,int i,int j,int &count,int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1 || mark[i][j]==true) return;

    mark[i][j]=true;

    helper(grid,mark,i+1,j,count,n,m);
    helper(grid,mark,i-1,j,count,n,m);
    helper(grid,mark,i,j+1,count,n,m);
    helper(grid,mark,i,j-1,count,n,m);
    return;
}

int no_of_island(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>> mark(n,vector<bool>(m,false));
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!mark[i][j] && grid[i][j]==1){
                helper(grid,mark,i,j,count,n,m);
                count++;
            }
        }
    }

    return count;
}

int main(){
    vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1}};
    cout<<"No of Island are:"<<" ";
    cout<<no_of_island(grid)<<endl;
    return 0;
}