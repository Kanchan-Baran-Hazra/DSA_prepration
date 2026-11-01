class Solution {
    long long helper(int i,int j,vector<vector<int>>& grid,int n,int m,vector<vector<int>>& dp){
        if(i>=n || j>=m) return 1e15;
        if(i==n-1 && j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        
        long long right=helper(i,j+1,grid,n,m,dp);
        long long down=helper(i+1,j,grid,n,m,dp);
        
        return dp[i][j]= grid[i][j] + min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return helper(0,0,grid,n,m,dp);
    }
};