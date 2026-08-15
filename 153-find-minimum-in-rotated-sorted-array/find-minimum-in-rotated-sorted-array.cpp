class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            int mid = i + (j - i) / 2;

            if (nums[mid] > nums[j]) {
                // Minimum is on the right side
                i = mid + 1;
            }
            else {
                // Minimum is at mid or on the left side
                j = mid;
            }
        }

        return nums[i];
    }
};