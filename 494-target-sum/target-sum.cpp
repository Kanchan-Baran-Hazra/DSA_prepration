class Solution {
public:
    static void helper(vector<int>& nums,int i, int target,int &ans,int sum){
        if(i == nums.size()){

            if(sum == target)
                ans++;

            return;
        }
        helper(nums,i+1,target,ans,sum-nums[i]);
        helper(nums,i+1,target,ans,sum+nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        helper(nums,0,target,ans,0);

        return ans;
    }
};