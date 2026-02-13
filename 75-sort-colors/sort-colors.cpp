class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        for(int k=0;k<=j;k++){
            if(nums[k]==1) continue;
            else if(nums[k]==0){
                swap(nums[k],nums[i]);
                i++;
            }else{
                swap(nums[j],nums[k]);
                k--;
                j--;
            }
        }
        return;
    }
};