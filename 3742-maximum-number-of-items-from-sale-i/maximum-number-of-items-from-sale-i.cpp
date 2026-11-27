class Solution {
    int helper(int i,vector<vector<int>>& items,int budget,int n,vector<int>& free,int mn,vector<vector<int>>& dp){
        if(i>=n) return budget/mn;
        if(dp[i][budget]!=-1) return dp[i][budget];
        int take=0;
        if(items[i][1]<=budget) take=free[i]+helper(i+1,items,budget-items[i][1],n,free,mn,dp)+1;
        int no_take=helper(i+1,items,budget,n,free,mn,dp);
        return dp[i][budget]= max(take,no_take);
    }
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> free(n,0);
        int mn=INT_MAX;
        vector<vector<int>> dp(n,vector<int>(budget+1,-1));
        for(int i=0;i<n;i++){
            mn=min(mn,items[i][1]);
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%items[i][0]==0) free[i]++;
            }
        }

        return helper(0,items,budget,n,free,mn,dp);
    }
};