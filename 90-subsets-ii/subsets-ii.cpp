class Solution {
public:
    void helper(vector<int>nums,vector<vector<int>> &ans,vector<int> &sub,int i){
        if(i>=nums.size()){
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        helper(nums,ans,sub,i+1);
        sub.pop_back();
        while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;
        helper(nums,ans,sub,i+1);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>sub;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        helper(nums,ans,sub,0);
        return ans;
    }
};