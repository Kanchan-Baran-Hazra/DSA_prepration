class Solution {
public:
static void helper(vector<int>& nums, int target,int idx,vector<int> &sub,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(sub);
            return;
        }
        for(int i=idx;i<nums.size();i++){
            if(nums[i]>target) break;
            if(i>idx && nums[i]==nums[i-1]) continue;

            sub.push_back(nums[i]);
            helper(nums,target-nums[i],i+1,sub,ans);
            sub.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>sub;
        sort(nums.begin(),nums.end());
        helper(nums,target,0,sub,ans);

        return ans;
    }
};