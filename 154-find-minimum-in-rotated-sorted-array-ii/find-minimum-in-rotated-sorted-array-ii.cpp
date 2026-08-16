class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int i=0;
        int n=nums.size();
        int j=n-1;
        while(i<=j){
            while(i<j && nums[i]==nums[i+1]) i++;
            while(i<j && nums[j]==nums[j-1]) j--;
            int mid=i+(j-i)/2;

            if(nums[mid]>=nums[i]){
                ans=min(ans,nums[i]);
                i=mid+1;
            }else j=mid;
        }
        return ans;
    }
};