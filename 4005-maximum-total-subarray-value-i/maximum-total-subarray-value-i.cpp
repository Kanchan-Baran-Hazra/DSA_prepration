class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = nums[0];
        long long mini = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            maxi = max(maxi, (long long)nums[i]);
            mini = min(mini, (long long)nums[i]);
        }

        return (maxi - mini) * k;
    }
};