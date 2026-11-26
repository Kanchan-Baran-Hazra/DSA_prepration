class Solution {
    bool helper(vector<int>& nums, long long target,int i){
        if(target==1) return true;
        if(i>=nums.size()) return false;

        bool no_take=helper(nums,target,i+1);
        int take=false;
        if(nums[i]<=target && target%nums[i]==0) take=helper(nums,target/nums[i],i+1);

        return take || no_take;
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        if (target <= 0) return false;

        __int128 totalProd = 1;
        for (int x : nums) {
            totalProd *= x;
        }

        __int128 neededProd = (__int128)target * target;
        if (totalProd != neededProd) return false;

        return helper(nums, target, 0);
    }
};