class Solution {
public:
    int first(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int ans = -1;

        while(i <= j) {
            int mid = i + (j - i) / 2;

            if(nums[mid] == target) {
                ans = mid;
                j = mid - 1;       // search left
            }
            else if(nums[mid] > target) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        return ans;
    }

    int last(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int ans = -1;

        while(i <= j) {
            int mid = i + (j - i) / 2;

            if(nums[mid] == target) {
                ans = mid;
                i = mid + 1;       // search right
            }
            else if(nums[mid] > target) {
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums, target), last(nums, target)};
    }
};