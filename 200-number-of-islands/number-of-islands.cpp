class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>> &mark,vector<vector<char>>& grid,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || mark[i][j]==1 || grid[i][j]=='0'){
            return false;
        }
        mark[i][j]=1;
        bool x=dfs(i+1,j,mark,grid,n,m);
        bool y=dfs(i-1,j,mark,grid,n,m);
        bool z=dfs(i,j+1,mark,grid,n,m);
        bool p=dfs(i,j-1,mark,grid,n,m);
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> mark(n,vector<int>(m,0));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool temp=dfs(i,j,mark,grid,n,m);
                if(temp) ans++;
            }
        }

        return ans;
    }
};