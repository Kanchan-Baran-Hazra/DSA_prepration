class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat[0].size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(mat[i][j]==0 && mat[j][i]==1) j--;
            else if(mat[i][j]==1 && mat[j][i]==0) i++;
            else{
                i++;
                j--;
            }
        }
        if(i>j) return -1;
        for(int k=0;k<n;k++){
            if(k==i) continue;
            if(mat[i][k]!=0 || mat[k][i]!=1) return -1;
        }
        return i;
    }
};