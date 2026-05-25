class Solution {
public:
    static void helper(vector<int>& nums, int target,int i,vector<int> &sub,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(sub);
            return;
        }
        if(i>=nums.size() || target<0){
            return;
        }
        sub.push_back(nums[i]);
        target-=nums[i];
        // helper(nums,target,i+1,sub,ans);
        helper(nums,target,i,sub,ans);
        sub.pop_back();
        target+=nums[i];
        helper(nums,target,i+1,sub,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>sub;
        helper(nums,target,0,sub,ans);

        return ans;
    }
};