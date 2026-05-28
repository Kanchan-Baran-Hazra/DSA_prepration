class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()==1) return true;
        int count=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
               count++;
            }
        }
        if(count>1) return false;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                if(nums[0]>=nums[nums.size()-1]) return true;
                return false;
            }
        }
        return true;
    }
};