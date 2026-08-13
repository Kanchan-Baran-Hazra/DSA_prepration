class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count=0;
        int n=nums.size();
        int i=0;
        int j=0;
        while(j<n){
            if(nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }else{
                j++;
                count++;
            }
        }
        return n-count;
    }
};