class Solution {
    int helper(int i,int j,vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int profit=0;
        if(j){
            profit=max(-prices[i]+helper(i+1,0,prices,dp),helper(i+1,1,prices,dp));
        }else{
            profit=max(prices[i]+helper(i+2,1,prices,dp),helper(i+1,0,prices,dp));
        }
        return dp[i][j]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};