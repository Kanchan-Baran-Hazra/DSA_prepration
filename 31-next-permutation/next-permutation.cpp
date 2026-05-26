class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int i = nums.size() - 2;

        // find first decreasing element
        while(i >= 0 && nums[i] >= nums[i+1]) {
            i--;
        }

        // already largest permutation
        if(i < 0) {
            sort(nums.begin(), nums.end());
            return;
        }

        int big = i + 1;

        // find just larger element
        for(int j = i + 1; j < nums.size(); j++) {
            if(nums[j] > nums[i] && nums[j] <= nums[big]) {
                big = j;
            }
        }

        swap(nums[i], nums[big]);

        sort(nums.begin() + i + 1, nums.end());
    }
};