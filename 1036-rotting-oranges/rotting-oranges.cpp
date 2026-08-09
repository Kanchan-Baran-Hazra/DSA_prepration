class Solution {
public:
    static int bfs(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>> &q,int n,int m,vector<vector<bool>>& mark){
        int ans=0;
        while(q.size()!=0){
            pair<pair<int,int>,int> p=q.front();
            q.pop();
            int i=p.first.first;
            int j=p.first.second;
            grid[i][j]=2;

            if(i-1>=0 && mark[i-1][j]!=true && grid[i-1][j]==1){
                q.push({{i-1,j},p.second+1});
                mark[i-1][j]=true;
            }
            if(i+1<n && mark[i+1][j]!=true && grid[i+1][j]==1){
                q.push({{i+1,j},p.second+1});
                mark[i+1][j]=true;
            }
            if(j-1>=0 && mark[i][j-1]!=true && grid[i][j-1]==1){
                q.push({{i,j-1},p.second+1});
                mark[i][j-1]=true;
            }
            if(j+1<m && mark[i][j+1]!=true && grid[i][j+1]==1){
                q.push({{i,j+1},p.second+1});
                mark[i][j+1]=true;
            }
            ans=max(ans,p.second);
        }

        return ans;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

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
        int ans=bfs(grid,q,n,m,mark);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
    }
};