class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sub=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            max_sub=max(max_sub,sum);
            if(sum<0) sum=0;
        }
        return max_sub;
    }
};