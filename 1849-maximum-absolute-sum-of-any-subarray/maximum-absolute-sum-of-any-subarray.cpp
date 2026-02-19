class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int max_sub=INT_MIN;
        int max_sum=0;
        int min_sub=INT_MAX;
        int min_sum=0;

        for(int i=0;i<nums.size();i++){
            max_sum+=nums[i];
            max_sub=max(max_sub,max_sum);
            if(max_sum<0) max_sum=0;

            min_sum+=nums[i];
            min_sub=min(min_sub,min_sum);
            if(min_sum>0) min_sum=0;
        }
        return max(abs(max_sub),abs(min_sub));
    }
};