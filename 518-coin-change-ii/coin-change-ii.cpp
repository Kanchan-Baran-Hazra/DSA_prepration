class Solution {
private:
    int helper(int i, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: if amount is 0, we found 1 valid combination
        if (amount == 0) return 1;
        
        // Base case: if we run out of coins or amount becomes negative
        if (i < 0 || amount < 0) return 0;
        
        // Return if already computed
        if (dp[i][amount] != -1) return dp[i][amount];
        
        // Option 1: Exclude the current coin
        long long waysExclude = helper(i - 1, amount, coins, dp);
        
        // Option 2: Include the current coin (since we can reuse it, stay at index i)
        long long waysInclude = helper(i, amount - coins[i], coins, dp);
        
        // Memoize and return the total ways
        return dp[i][amount] = waysExclude + waysInclude;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][amount] stores the number of ways to make 'amount' using a subset of coins up to index 'i'
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(n - 1, amount, coins, dp);
    }
};