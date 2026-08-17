class Solution {
public:
    static bool isposs(vector<vector<char>>& board,int row,int col,int num){
        for(int i=0;i<9;i++){
            if(board[row][i]==num) return false;
        }

        for(int j=0;j<9;j++){
            if(board[j][col]==num) return false;
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==num) return false;
            }
        }

        return true;
    }
    static bool helper(vector<vector<char>>& board,int row,int col){
        if(row==9) return true;

        int nrow=row;
        int ncol=col+1;
        if(ncol==9){
            nrow+=1;
            ncol=0;
        }

        if(board[row][col]!='.') {
            return helper(board,nrow,ncol);
        }

        for(char i='1';i<='9';i++){
            if(isposs(board,row,col,i)){
                board[row][col]=i;
                if(helper(board,nrow,ncol)) return true;
                board[row][col]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool x=helper(board,0,0);
        return;
    }
};