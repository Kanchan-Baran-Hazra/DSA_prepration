class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 1;
        int ans=0;
        int i=2;
        int j=2;
        int count=0;
        while(j<n){
            if(nums[j]==nums[i-2]){
                j++;
                count++;
            }else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
        return i;
    }
};