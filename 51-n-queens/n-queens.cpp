class Solution {
public:
    static bool issafe(int n,int row,int col,vector<string>& temp){
        for(int i=0;i<n;i++){
            if(temp[row][i]=='Q') return false;
        }
        for(int j=0;j<n;j++){
            if(temp[j][col]=='Q') return false;
        }

        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(temp[i][j]=='Q') return false;
        }

        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(temp[i][j]=='Q') return false;
        }

        return true;
    }
    static void helper(int n,int row,vector<string>& temp,vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(issafe(n,row,i,temp)){
                temp[row][i]='Q';
                helper(n,row+1,temp,ans);
                temp[row][i]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp(n,string(n,'.'));
        vector<vector<string>>ans;
        helper(n,0,temp,ans);
        return ans;
    }
};