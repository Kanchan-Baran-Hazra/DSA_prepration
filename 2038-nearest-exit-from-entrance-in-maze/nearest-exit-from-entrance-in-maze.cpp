class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<bool>> mark(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        q.push({{entrance[0],entrance[1]},0});
        mark[entrance[0]][entrance[1]]=true;

        while(q.size()!=0){
            auto x=q.front();
            q.pop();

            int i=x.first.first;
            int j=x.first.second;
            int cost=x.second;

            if((i==0 || j==0 || i==n-1 || j==m-1) && (i!=entrance[0] || j!=entrance[1])) return cost;

            if(i-1>=0 && maze[i-1][j]!='+' && !mark[i-1][j]){
                q.push({{i-1,j},cost+1});
                mark[i-1][j]=true;
            }
            if(i+1<n && maze[i+1][j]!='+' && !mark[i+1][j]){
                q.push({{i+1,j},cost+1});
                mark[i+1][j]=true;
            }
            if(j-1>=0 && maze[i][j-1]!='+' && !mark[i][j-1]){
                q.push({{i,j-1},cost+1});
                mark[i][j-1]=true;
            }
            if(j+1<m && maze[i][j+1]!='+' && !mark[i][j+1]){
                q.push({{i,j+1},cost+1});
                mark[i][j+1]=true;
            }
        }

        return -1;
    }
};