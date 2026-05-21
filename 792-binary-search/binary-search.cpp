class Solution {
public:
    static int helper(vector<int>& nums, int target,int i,int j){
        if(i>j) return -1;
        int mid=i+(j-i)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) return helper(nums,target,mid+1,j);
        else return helper(nums,target,i,mid-1);
    }
    int search(vector<int>& nums, int target) {
        return helper(nums,target,0,nums.size()-1);
    }
};