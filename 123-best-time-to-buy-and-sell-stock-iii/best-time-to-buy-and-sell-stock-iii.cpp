class Solution {
    int helper(int i, int j, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        // If we have completed 2 transactions, profit is 0
        if (k == 2) return 0;
        // If we reach the end of the prices array
        if (i == prices.size()) return 0;
        
        // Return memoized result if available
        if (dp[i][j][k] != -1) return dp[i][j][k];
        
        int profit = 0;
        if (j) {
            // Currently holding a stock: we can either sell it or skip
            profit = max(-prices[i] + helper(i + 1, 0, k, prices, dp), 
                         helper(i + 1, 1, k, prices, dp));
        } else {
            // Not holding a stock: we can either buy one (which increments transaction count k) or skip
            profit = max(prices[i] + helper(i + 1, 1, k + 1, prices, dp), 
                         helper(i + 1, 0, k, prices, dp));
        }
        
        return dp[i][j][k] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 3D DP table: [prices.size()][holding: 2][transactions: 3] initialized to -1
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // Start at day 0, not holding stock (j = 1 means we can buy, or adjust your flag convention), 0 transactions completed
        return helper(0, 1, 0, prices, dp);
    }
};