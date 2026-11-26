class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int ans=0;
        int total=0;
        int sum=0;
        for(auto x:nums) total+=x;
        for(int i=0;i<nums.size()-1;i++){
            sum+=nums[i];
            int right=total-sum;
            if(abs(right-sum)%2==0) ans++;
        }
        return ans;
    }
};