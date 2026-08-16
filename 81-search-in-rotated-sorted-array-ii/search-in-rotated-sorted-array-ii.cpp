class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            while(i<j && nums[i]==nums[i+1]) i++;
            while(i<j && nums[j]==nums[j-1]) j--;
            int mid=i+(j-i)/2;

            if(nums[mid]==target) return true;
            else if(nums[mid]>=nums[i]){
                if(nums[mid]>target && nums[i]<=target) j=mid-1;
                else i=mid+1;
            }else{
                if(nums[mid]<target && nums[j]>=target) i=mid+1;
                else j=mid-1;
            }
        }
        return false;
    }
};