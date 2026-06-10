class Solution {
public:
    static bool helper(vector<int>& nums,int i,int sum,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(sum<0 || i>=nums.size()) return false;

        if(dp[i][sum]!=-1) return dp[i][sum];

        return dp[i][sum]=helper(nums,i+1,sum-nums[i],dp) || helper(nums,i+1,sum,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        return helper(nums,0,sum/2,dp);
    }
};