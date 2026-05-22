class Solution {
public:
    static bool helper(vector<int>& arr, int i, int currSum, int target,
                       vector<vector<int>>& dp) {
        
        if (currSum == target) return true;
        
        if (i >= arr.size() || currSum > target) return false;

        if (dp[i][currSum] != -1)
            return dp[i][currSum];

        // take
        bool take = helper(arr, i + 1, currSum + arr[i], target, dp);

        // not take
        bool notTake = helper(arr, i + 1, currSum, target, dp);

        return dp[i][currSum] = take || notTake;
    }

    bool equalPartition(vector<int>& arr) {
        int sum = 0;

        for (int x : arr)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(arr.size(),
                               vector<int>(target + 1, -1));

        return helper(arr, 0, 0, target, dp);
    }
};