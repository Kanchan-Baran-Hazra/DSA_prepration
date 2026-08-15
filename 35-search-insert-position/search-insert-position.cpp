#include <bits/stdc++.h>
class Solution {
public:
    static int get_lower_bound(vector<int>& nums,int target){
        int i=0;
        int j=nums.size()-1;

        while(i<=j){
            int mid=i+(j-i)/2;

            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) j=mid-1;
            else i=mid+1;
        }

        return i;
    }
    int searchInsert(vector<int>& nums, int target) {
        int x= get_lower_bound(nums,target);
        return x;
    }
};