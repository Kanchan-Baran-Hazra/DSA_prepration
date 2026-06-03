class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int count=1;
        int i=1;
        int j=1;
        while(j<nums.size()){
            while(j < nums.size() && nums[j]==nums[j-1]) j++;
            if(j == nums.size()) break;
            nums[i]=nums[j];
            count++;
            j++;
            i++;
        }

        return count;
    }
};