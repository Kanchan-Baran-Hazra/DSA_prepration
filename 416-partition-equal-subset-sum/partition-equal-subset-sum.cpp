class Solution {
public:
    bool helper(vector<int> &nums,int sum,int n,vector<vector<int>> &t){
        if(sum==0) return 1;
        if(n<0 && sum!=0) return 0;
        if(t[n][sum]!=-1) return t[n][sum];
        if(nums[n]<=sum){
            return t[n][sum]=helper(nums,sum-nums[n],n-1,t) || helper(nums,sum,n-1,t);
        }else{
            return t[n][sum]=helper(nums,sum,n-1,t);
        }
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        vector<vector<int>>t(nums.size(),vector<int>(sum,-1));
        return helper(nums,sum/2,nums.size()-1,t);
    }
};