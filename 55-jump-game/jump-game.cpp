class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int need=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]+i>=need) need=i;
        }
        if(need>0) return false;
        return true;
    }
};