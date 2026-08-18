class Solution {
public:
    static bool isvalid(vector<string>& temp,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(temp[row][i]=='Q') return false;
        }

        for(int i=0;i<n;i++){
            if(temp[i][col]=='Q') return false;
        }

        int i=row-1;
        int j=col-1;
        while(i>=0 && j>=0){
            if(temp[i][j]=='Q') return false;
            i--;
            j--;
        }

        i=row-1;
        j=col+1;
        while(i>=0 && j<n){
            if(temp[i][j]=='Q') return false;
            i--;
            j++;
        }

        return true;
    }
    static void helper(int n, vector<vector<string>>& ans,vector<string>& temp,int row){
        if(row==n){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<n;i++){
            if(isvalid(temp,row,i,n)){
                temp[row][i]='Q';
                helper(n,ans,temp,row+1);
                temp[row][i]='.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>temp(n,string(n,'.'));
        helper(n,ans,temp,0);

        return (int)ans.size();
    }
};