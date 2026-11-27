class Solution {
    int helper(vector<int>& prices,int i,int taken,vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][taken]!=-1) return dp[i][taken];
        int no_take=INT_MAX;
        int taken1 = max(taken, 2 * i + 2);
        if(i<taken){
            no_take= helper(prices,i+1,taken,dp);
        }

        return dp[i][taken]= min(no_take, prices[i]+helper(prices,i+1,taken1,dp));
    }
public:
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2*n+1,-1));
        return helper(prices,0,0,dp);
    }
};