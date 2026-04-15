class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int buc1=0;
        int buc2=0;
        for(int i=0;i<nums.size();i++){
            buc1=(buc1^nums[i]) & (~buc2);
            buc2=(buc2^nums[i]) & (~buc1);
        }

        return buc1;
    }
};