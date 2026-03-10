class Solution {
public:
    bool canJump(vector<int>& nums) {
        int currentPos=nums.size()-1;
        for(int i=nums.size()-2;i>=0;i--){
            if(i+nums[i]>=currentPos){
                currentPos=i;
            }
        }

        return currentPos==0;
    }
};