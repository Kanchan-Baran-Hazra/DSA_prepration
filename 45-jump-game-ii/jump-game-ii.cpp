class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        int can_reach=nums[0];
        int jump=1;
        int c_max_jump=can_reach;
        int i=0;

        while(i<nums.size() && i<=can_reach){
            can_reach=max(can_reach,nums[i]+i);

            if(c_max_jump==i && i < n - 1){
                jump++;
                c_max_jump=can_reach;
            }


            i++;
        }

        return jump;
    }
};