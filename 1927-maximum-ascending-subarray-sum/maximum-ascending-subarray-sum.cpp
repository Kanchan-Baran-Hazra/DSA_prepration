class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi=0;
        int prev=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>prev){
                sum+=nums[i];
                prev=nums[i];
            }else{
                sum=nums[i];
                prev=nums[i];
            }
            maxi=max(maxi,sum);
        }

        return maxi;
    }
};