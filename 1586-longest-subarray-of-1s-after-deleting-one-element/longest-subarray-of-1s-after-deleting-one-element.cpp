class Solution {
    int helper(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        // int i=0;
        int j=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) k--;
            while(j<=i && k<0){
                if(nums[j]==0) k++;
                j++;
            }
            maxi=max(maxi,i-j);
        }
        return maxi;
    }
public:
    int longestSubarray(vector<int>& nums) {
        return helper(nums,1);
    }
};