class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int i;
        int j;
        int k=0;
        for(k=0;k<mat.size();k++){
            i=0;
            j=mat[k].size()-1;
            // if(mat[k][i]>x) return false;
            if(mat[k][i]<=x && mat[k][j]>=x){
                break;
            }
        }
        if(k>=mat.size()) return false;
        // cout<<k<<i<<j<<endl;
        
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mat[k][mid]==x) return true;
            else if(mat[k][mid]>x) j=mid-1;
            else i=mid+1;
        }
        
        return false;
    }
};