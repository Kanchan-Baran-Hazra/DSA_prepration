class Solution {
public:
    bool solve(vector<int>& nums, int mask, int currSum, int target, int k, vector<int>& memo) {
        if (k == 1)
            return true;

        if (currSum == target)
            return solve(nums, mask, 0, target, k - 1, memo);

        if (memo[mask] != -1)
            return memo[mask];

        for (int i = 0; i < (int)nums.size(); i++) {
            if (mask & (1 << i))
                continue;
            if (currSum + nums[i] > target)
                continue;

            if (solve(nums, mask | (1 << i), currSum + nums[i], target, k, memo)) {
                return memo[mask] = 1;
            }
        }

        return memo[mask] = 0;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (int x : nums) sum += x;
        if (sum % k != 0) return false;

        int target = sum / k;
        int n = (int)nums.size();
        vector<int> memo(1 << n, -1);

        return solve(nums, 0, 0, target, k, memo);
    }
};