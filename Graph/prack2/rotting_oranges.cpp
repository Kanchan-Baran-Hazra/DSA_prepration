#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& grid,vector<vector<bool>>& mark,queue<pair<int,pair<int,int>>>& q,int n,int m){
    int maxi=0;
    while(q.size()!=0){
        pair<int ,pair<int ,int>> x=q.front();
        q.pop();
        int time=x.first;
        int i=x.second.first;
        int j=x.second.second;

        maxi=max(maxi,time);
        
        if(i-1>=0 && grid[i-1][j]==1 && !mark[i-1][j]){
            q.push({time+1,{i-1,j}});
            mark[i-1][j]=true;
        }

        if(i+1<n && grid[i+1][j]==1 && !mark[i+1][j]){
            q.push({time+1,{i+1,j}});
            mark[i+1][j]=true;
        }

        if(j-1>=0 && grid[i][j-1]==1 && !mark[i][j-1]){
            q.push({time+1,{i,j-1}});
            mark[i][j-1]=true;
        }

        if(j+1<m && grid[i][j+1]==1 && !mark[i][j+1]){
            q.push({time+1,{i,j+1}});
            mark[i][j+1]=true;
        }
    }

    return maxi;
}

int time_required(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,pair<int,int>>> q;
    vector<vector<bool>> mark(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({0,{i,j}});
                mark[i][j]=true;
            }
        }
    }
    return helper(grid,mark,q,n,m);
}

int main(){
    // cout<<"hello"<<endl;
    vector<vector<int>> grid={{2,1,1},{1,1,0},{2,1,1}};
    cout<<time_required(grid);
    return 0;
}