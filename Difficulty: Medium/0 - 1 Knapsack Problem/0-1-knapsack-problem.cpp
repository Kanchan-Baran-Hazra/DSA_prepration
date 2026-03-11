class Solution {
  public:
    int helper(int W, vector<int> &val, vector<int> &wt,int n,vector<vector<int>> &t){
        if(n<0 || W==0) return 0;
        if(t[W][n]!=-1) return t[W][n];
        if(wt[n]>W){
            return t[W][n]=helper(W,val,wt,n-1,t);
        }else{
            return t[W][n]=max(val[n]+helper(W-wt[n],val,wt,n-1,t),helper(W,val,wt,n-1,t));
        }
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size()-1;
        vector<vector<int>>t(W+1,vector<int>(n+1,-1));
        return helper(W,val,wt,n,t);
    }
};