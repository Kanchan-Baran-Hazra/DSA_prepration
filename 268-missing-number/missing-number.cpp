class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        for(int x:nums)
        ans^=x;
        for(int i=0;i<=nums.size();i++){
            ans=ans^i;
        }
        return ans;
    }
};