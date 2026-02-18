class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size()<=1) return 0;
        vector<int>pre;
        vector<int>suf;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            pre.push_back(sum);
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            suf.push_back(sum);
        }
        reverse(suf.begin(),suf.end());

        for(int i=0;i<nums.size();i++){
            if(i==0){
                if(suf[i+1]==0) return 0;
            }else if(i==nums.size()-1){
                if(pre[i-1]==0) return nums.size()-1;
            }
            else if(pre[i-1]==suf[i+1]) return i;
        }

        return -1;
    }
};