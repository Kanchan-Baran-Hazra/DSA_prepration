class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int minjump=0;
        int covarage=0;
        int lastjump=0;
        for(int i=0;i<nums.size();i++){
            covarage=max(covarage,i+nums[i]);

            if(lastjump==i){
                lastjump=covarage;
                minjump++;
                if(covarage>=nums.size()-1) return minjump;
            }
        }

        return minjump;
    }
};