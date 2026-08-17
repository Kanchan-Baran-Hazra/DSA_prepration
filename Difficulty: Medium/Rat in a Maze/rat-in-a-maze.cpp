class Solution {
  public:
    static void helper(vector<vector<int>>& maze,int row,int col,string &sub,vector<string>& ans,int n,int m,vector<vector<bool>>& visited){
        if(row<0 || col<0 || row>=n || col>=n) return;
        
        if(visited[row][col]) return;
        
        if(maze[row][col]==0) return;
        
        if(row==n-1 && col==m-1){
            ans.push_back(sub);
            return;
        }
        
        
        visited[row][col]=true;
        
        sub.push_back('L');
        helper(maze,row,col-1,sub,ans,n,m,visited);
        sub.pop_back();
        
        sub.push_back('R');
        helper(maze,row,col+1,sub,ans,n,m,visited);
        sub.pop_back();
        
        sub.push_back('U');
        helper(maze,row-1,col,sub,ans,n,m,visited);
        sub.pop_back();
        
        sub.push_back('D');
        helper(maze,row+1,col,sub,ans,n,m,visited);
        sub.pop_back();
        
        // Backtrack
        visited[row][col] = false;
        
        return;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        int n=maze.size();
        int m=maze[0].size();
        string sub="";
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        if(maze[0][0]==0 || maze[n-1][m-1]==0) return ans;
        
        helper(maze,0,0,sub,ans,n,m,visited);
        sort(ans.begin(),ans.end());
        return ans;
    }
};