class Solution {
public:
    static bool isposs(vector<int>& nums, int target, int mid) {
        int sum = 0;

        // First window
        for(int i = 0; i < mid; i++) {
            sum += nums[i];
        }

        if(sum >= target)
            return true;

        // Remaining windows
        int i = 0;
        int j = mid;

        while(j < nums.size()) {
            sum += nums[j];
            sum -= nums[i];

            if(sum >= target)
                return true;

            i++;
            j++;
        }

        return false;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i = 1;
        int j = n;
        int ans = 0;

        while(i <= j) {
            int mid = i + (j - i) / 2;

            if(isposs(nums, target, mid)) {
                // A subarray of length mid works.
                // Try smaller length.
                ans = mid;
                j = mid - 1;
            }
            else {
                // No subarray of length mid works.
                // Need larger length.
                i = mid + 1;
            }
        }

        return ans;
    }
};