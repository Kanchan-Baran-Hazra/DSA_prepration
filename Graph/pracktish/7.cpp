// wrotton orrange
#include <bits/stdc++.h>
using namespace std;



int timeToRot(vector<vector<int>>& grid,int n,int m){
    queue<pair<pair<int,int>,int>>q;
    vector<vector<bool>> mark(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                mark[i][j]=true;
            }
        }
    }
    int maxi=0;

    while(q.size()!=0){
        auto x=q.front();
        q.pop();
        int i=x.first.first;
        int j=x.first.second;
        int lev=x.second;
        maxi=max(maxi,lev);

        if(i-1>=0 && !mark[i-1][j] && grid[i-1][j]!=0){
            q.push({{i-1,j},lev+1});
            mark[i-1][j]=true;
        }
        if(j-1>=0 && !mark[i][j-1] && grid[i][j-1]!=0){
            q.push({{i,j-1},lev+1});
            mark[i][j-1]=true;
        }
        if(i+1<n && !mark[i+1][j] && grid[i+1][j]!=0){
            q.push({{i+1,j},lev+1});
            mark[i+1][j]=true;
        }
        if(j+1<m && !mark[i][j+1] && grid[i][j+1]!=0){
            q.push({{i,j+1},lev+1});
            mark[i][j+1]=true;
        }
    }


    return maxi;
}


int main(){
    // cout<<"hello";
    vector<vector<int>> grid(3,vector<int>(3,0));

    grid[0][0]=2;
    grid[0][1]=1;
    grid[0][2]=1;
    grid[1][0]=1;
    grid[1][1]=1;
    grid[2][1]=1;
    grid[2][2]=1;
    grid[2][0]=2;

    int n=grid.size();
    int m=grid[0].size();

    cout<<timeToRot(grid,n,m);


    return 0;
}