class Solution {
    int helper(vector<vector<int>>& grid,int i1,int j1,int i2,int j2,int n,vector<vector<vector<vector<int>>>>& dp){
        if(i1>=n || j1>=n || i2>=n || j2>=n) return -1e8;
        if(i1==n-1 && j1==n-1 && i2==n-1 && j2==n-1) return grid[n-1][n-1];
        if(grid[i1][j1]==-1 || grid[i2][j2]==-1) return -1e8;

        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];
        int addi=0;
        if(i1==i2 && j1==j2) addi+=grid[i1][j1];
        else addi+=(grid[i1][j1]+grid[i2][j2]);

        int rig=helper(grid,i1,j1+1,i2,j2+1,n,dp)+addi;
        int dow=helper(grid,i1+1,j1,i2+1,j2,n,dp)+addi;
        int rig_dow=helper(grid,i1,j1+1,i2+1,j2,n,dp)+addi;
        int dow_rig=helper(grid,i1+1,j1,i2,j2+1,n,dp)+addi;

        return dp[i1][j1][i2][j2]= max(rig,max(dow,max(rig_dow,dow_rig)));
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))));
        if(grid[n-1][n-1]==-1) return 0;
        int x= helper(grid,0,0,0,0,n,dp);
        if(x<0) return 0;
        return x;
    }
};