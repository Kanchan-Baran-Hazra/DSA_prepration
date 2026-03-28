class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int num;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                count++;
                num=nums[i];
            }else{
                if(nums[i]==num) count++;
                else count--;
            }
        }

        return num;
    }
};